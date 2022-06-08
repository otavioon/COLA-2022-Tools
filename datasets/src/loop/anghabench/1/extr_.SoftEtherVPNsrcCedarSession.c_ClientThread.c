#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef int scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_22__   TYPE_7__ ;
typedef  struct TYPE_21__   TYPE_6__ ;
typedef  struct TYPE_20__   TYPE_5__ ;
typedef  struct TYPE_19__   TYPE_4__ ;
typedef  struct TYPE_18__   TYPE_3__ ;
typedef  struct TYPE_17__   TYPE_2__ ;
typedef  struct TYPE_16__   TYPE_1__ ;
typedef  struct TYPE_15__   TYPE_14__ ;

/* Type definitions */
typedef  int UINT ;
struct TYPE_22__ {int /*<<< orphan*/  CurrentActiveLinks; TYPE_14__* Client; } ;
struct TYPE_21__ {void* LastError; } ;
struct TYPE_20__ {int LinkModeClient; int RetryFlag; int CurrentRetryCount; int Halt; int RetryInterval; int ConnectSucceed; TYPE_3__* Account; void* ClientStatus; scalar_t__ ForceStopFlag; int /*<<< orphan*/  HaltEvent; TYPE_1__* ClientOption; void* Err; TYPE_7__* Cedar; TYPE_2__* Link; scalar_t__ UserCanceled; scalar_t__ NextConnectionTime; int /*<<< orphan*/  ServerIP_CacheForNextConnect; int /*<<< orphan*/  Win32HideNicInfoWindow; int /*<<< orphan*/  Win32HideConnectWindow; TYPE_4__* Thread; int /*<<< orphan*/  ref; } ;
struct TYPE_19__ {int /*<<< orphan*/  ref; } ;
struct TYPE_18__ {int /*<<< orphan*/ * ClientSession; } ;
struct TYPE_17__ {int /*<<< orphan*/  Hub; scalar_t__ Halting; scalar_t__* StopAllLinkFlag; } ;
struct TYPE_16__ {int NumRetry; int /*<<< orphan*/  AccountName; int /*<<< orphan*/  HideNicInfoWindow; int /*<<< orphan*/  HideStatusWindow; } ;
struct TYPE_15__ {int DontSavePassword; } ;
typedef  TYPE_4__ THREAD ;
typedef  TYPE_5__ SESSION ;
typedef  TYPE_6__ LINK ;
typedef  int /*<<< orphan*/  IP ;
typedef  TYPE_7__ CEDAR ;

/* Variables and functions */
 int /*<<< orphan*/  AddRef (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  CLIENT_NOTIFY_ACCOUNT_CHANGED ; 
 void* CLIENT_STATUS_CONNECTING ; 
 void* CLIENT_STATUS_IDLE ; 
 void* CLIENT_STATUS_RETRY ; 
 int /*<<< orphan*/  CLog (TYPE_14__*,char*,int /*<<< orphan*/ ,int,...) ; 
 int /*<<< orphan*/  CiDecrementNumActiveSessions () ; 
 int /*<<< orphan*/  CiIncrementNumActiveSessions () ; 
 int Count (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  Debug (char*,...) ; 
 void* ERR_DEVICE_DRIVER_ERROR ; 
 void* ERR_HUB_IS_BUSY ; 
 void* ERR_HUB_STOPPING ; 
 void* ERR_LICENSE_ERROR ; 
 void* ERR_TOO_MANY_USER_SESSION ; 
 void* ERR_USER_CANCEL ; 
 int /*<<< orphan*/  GetUniErrorStr (void*) ; 
 int /*<<< orphan*/  HLog (int /*<<< orphan*/ ,char*,int /*<<< orphan*/ ,int,...) ; 
 int MAX (int,int) ; 
 int MIN (int,int) ; 
 int /*<<< orphan*/  NoticeThreadInit (TYPE_4__*) ; 
 int /*<<< orphan*/  Notify (TYPE_5__*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  PrintSessionTotalDataSize (TYPE_5__*) ; 
 int RETRY_INTERVAL_SPECIAL ; 
 int Rand32 () ; 
 int /*<<< orphan*/  ReleaseSession (TYPE_5__*) ; 
 int /*<<< orphan*/  SessionConnect (TYPE_5__*) ; 
 int /*<<< orphan*/  Wait (int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  Zero (int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/  _E (void*) ; 

void ClientThread(THREAD *t, void *param)
{
	SESSION *s;
	bool use_password_dlg;
	bool no_save_password = false;
	bool is_vpngate_connection = false;
	CEDAR *cedar;
	bool num_active_sessions_incremented = false;
	// Validate arguments
	if (t == NULL || param == NULL)
	{
		return;
	}

	Debug("ClientThread 0x%x Started.\n", t);

	s = (SESSION *)param;
	AddRef(s->ref);
	s->Thread = t;
	AddRef(t->ref);

	if (s->LinkModeClient == false)
	{
		CiIncrementNumActiveSessions();
		num_active_sessions_incremented = true;
	}

	NoticeThreadInit(t);

	cedar = s->Cedar;

	s->ClientStatus = CLIENT_STATUS_CONNECTING;
	s->RetryFlag = true;
	s->CurrentRetryCount = 0;

	Notify(s, CLIENT_NOTIFY_ACCOUNT_CHANGED);

	if (s->Cedar->Client != NULL)
	{
		no_save_password = s->Cedar->Client->DontSavePassword;
	}

	s->Win32HideConnectWindow = s->ClientOption->HideStatusWindow;
	s->Win32HideNicInfoWindow = s->ClientOption->HideNicInfoWindow;


	while (true)
	{
		Zero(&s->ServerIP_CacheForNextConnect, sizeof(IP));

		if (s->Link != NULL && ((*s->Link->StopAllLinkFlag) || s->Link->Halting))
		{
			s->Err = ERR_USER_CANCEL;
			break;
		}

		CLog(s->Cedar->Client, "LC_CONNECT_1", s->ClientOption->AccountName, s->CurrentRetryCount + 1);
		if (s->LinkModeClient && s->Link != NULL)
		{
			HLog(s->Link->Hub, "LH_CONNECT_1", s->ClientOption->AccountName, s->CurrentRetryCount + 1);
		}

		Debug("Trying to Connect to Server... (%u / %u)\n", s->CurrentRetryCount + 0,
			s->ClientOption->NumRetry);

		// Initialize
//		s->TotalRecvSize = s->TotalRecvSizeReal = 
//			s->TotalSendSize = s->TotalSendSizeReal = 0;
		s->NextConnectionTime = 0;

		// Connect
		s->ClientStatus = CLIENT_STATUS_CONNECTING;
		s->Halt = false;
		SessionConnect(s);
		if (s->UserCanceled)
		{
			s->Err = ERR_USER_CANCEL;
		}
		Debug("Disconnected. Err = %u : %S\n", s->Err, _E(s->Err));

		PrintSessionTotalDataSize(s);

		CLog(s->Cedar->Client, "LC_CONNECT_ERROR", s->ClientOption->AccountName,
			GetUniErrorStr(s->Err), s->Err);

#ifdef OS_UNIX
		if (s->NicDownOnDisconnect != NULL && *s->NicDownOnDisconnect)
		{
			UnixVLanSetState(s->ClientOption->DeviceName, false);
		}
#endif

		if (s->LinkModeClient && s->Link != NULL)
		{
			HLog(s->Link->Hub, "LH_CONNECT_ERROR", s->ClientOption->AccountName,
				GetUniErrorStr(s->Err), s->Err);
		}

		s->ClientStatus = CLIENT_STATUS_RETRY;

		if (s->Link != NULL)
		{
			((LINK *)s->Link)->LastError = s->Err;
		}

		if (s->Halt && (s->RetryFlag == false) || s->ForceStopFlag)
		{
			// Must be aborted
			if (s->Err == ERR_DEVICE_DRIVER_ERROR)
			{
#ifdef	OS_WIN32
				wchar_t tmp[MAX_SIZE];
				if (s->Account != NULL && s->Cedar->Client != NULL)
				{
					UniFormat(tmp, sizeof(tmp), _UU("ERRDLG_DEVICE_ERROR"), s->ClientOption->DeviceName,
						s->Err, _E(s->Err));
					MsgBox(NULL, 0x10000 | 0x40000 | 0x200000 | 0x30, tmp);
				}
#endif	// OS_WIN32
			}
			break;
		}
		// Determine whether to display the password re-entry dialog
		use_password_dlg = false;

		if (s->Account != NULL && s->Cedar->Client != NULL)
		{
#ifdef	OS_WIN32
			if (s->ClientAuth->AuthType == CLIENT_AUTHTYPE_PASSWORD || s->ClientAuth->AuthType == CLIENT_AUTHTYPE_PLAIN_PASSWORD)
			{
				if (s->Err == ERR_AUTH_FAILED || s->Err == ERR_PROXY_AUTH_FAILED)
				{
					use_password_dlg = true;
				}
			}
#endif	// OS_WIN32
		}

		// Failed to connect or the connection is disconnected
		// Wait for retry interval
		if (use_password_dlg == false)
		{
			UINT retry_interval = s->RetryInterval;

			if (s->LinkModeClient)
			{
				UINT current_num_links = Count(s->Cedar->CurrentActiveLinks);
				UINT max_retry_interval = MAX(1000 * current_num_links, retry_interval);

				retry_interval += retry_interval * MIN(s->CurrentRetryCount, 1000);
				retry_interval = MIN(retry_interval, max_retry_interval);

				// On the cascade client, adjust the retry_interval. (+/- 20%)
				if (retry_interval >= 1000 && retry_interval <= (60 * 60 * 1000))
				{
					retry_interval = (retry_interval * 8 / 10) + (Rand32() % (retry_interval * 4 / 10));
				}
			}

			if (s->Err == ERR_HUB_IS_BUSY || s->Err == ERR_LICENSE_ERROR ||
				s->Err == ERR_HUB_STOPPING || s->Err == ERR_TOO_MANY_USER_SESSION)
			{
				retry_interval = RETRY_INTERVAL_SPECIAL;
			}

			if (s->CurrentRetryCount >= s->ClientOption->NumRetry)
			{
				// Retry count excess

#ifndef	OS_WIN32

				break;

#else	// OS_WIN32

				if (s->Win32HideConnectWindow == false &&
					s->Cedar->Client != NULL && s->Account != NULL)
				{
					// Show a reconnection dialog
					UI_CONNECTERROR_DLG p;
					Zero(&p, sizeof(p));
					UniStrCpy(p.AccountName, sizeof(p.AccountName), s->ClientOption->AccountName);
					StrCpy(p.ServerName, sizeof(p.ServerName), s->ClientOption->Hostname);
					p.Err = s->Err;
					p.CurrentRetryCount = s->CurrentRetryCount + 1;
					s->Halt = false;
					p.RetryLimit = 0;
					p.RetryIntervalSec = 0;
					p.CancelEvent = s->HaltEvent;
					p.HideWindow = s->Win32HideConnectWindow;
					if (CncConnectErrorDlg(s, &p) == false)
					{
						// Abort
						break;
					}
					else
					{
						s->Win32HideConnectWindow = p.HideWindow;
						goto SKIP;
					}
				}
				else
				{
					break;
				}

#endif
			}

#ifndef	OS_WIN32

			// Simple wait
			Wait(s->HaltEvent, retry_interval);

#else	// OS_WIN32

			if (s->Win32HideConnectWindow == false &&
				s->Cedar->Client != NULL && s->Account != NULL)
			{
				// Show a reconnection dialog
				UI_CONNECTERROR_DLG p;
				Zero(&p, sizeof(p));
				UniStrCpy(p.AccountName, sizeof(p.AccountName), s->ClientOption->AccountName);
				StrCpy(p.ServerName, sizeof(p.ServerName), s->ClientOption->Hostname);
				p.Err = s->Err;
				p.CurrentRetryCount = s->CurrentRetryCount + 1;
				p.RetryLimit = s->ClientOption->NumRetry;
				p.RetryIntervalSec = retry_interval;
				p.CancelEvent = s->HaltEvent;
				s->Halt = false;
				p.HideWindow = s->Win32HideConnectWindow;
				if (CncConnectErrorDlg(s, &p) == false)
				{
					// Abort
					break;
				}
				s->Win32HideConnectWindow = p.HideWindow;
			}
			else
			{
				// Simple wait
				Wait(s->HaltEvent, s->RetryInterval);
			}

#endif	// OS_WIN32
		}
		else
		{
#ifdef	OS_WIN32
			// Wait for re-entry the password
			UI_PASSWORD_DLG p;
			Zero(&p, sizeof(p));
			if (s->Client_NoSavePassword == false)
			{
				p.ShowNoSavePassword = true;
			}
			p.NoSavePassword = no_save_password;
			p.CancelEvent = s->HaltEvent;
			if (s->Err == ERR_PROXY_AUTH_FAILED)
			{
				p.ProxyServer = true;
			}

			if (p.ProxyServer)
			{
				StrCpy(p.Username, sizeof(p.Username), s->ClientOption->ProxyUsername);
				StrCpy(p.Password, sizeof(p.Password), s->ClientOption->ProxyPassword);
				StrCpy(p.ServerName, sizeof(p.ServerName), s->ClientOption->ProxyName);
			}
			else
			{
				bool empty = false;

				StrCpy(p.Username, sizeof(p.Username), s->ClientAuth->Username);
				if (s->ClientAuth->AuthType == AUTHTYPE_RADIUS)
				{
					if (StrLen(s->ClientAuth->PlainPassword) == 0)
					{
						empty = true;
					}
				}
				else if (s->ClientAuth->AuthType == AUTHTYPE_PASSWORD)
				{
					if (IsZero(s->ClientAuth->HashedPassword, sizeof(s->ClientAuth->HashedPassword)))
					{
						empty = true;
					}
				}

				StrCpy(p.Password, sizeof(p.Password), empty ? "" : HIDDEN_PASSWORD);
				StrCpy(p.ServerName, sizeof(p.ServerName), s->ClientOption->Hostname);
			}

			p.RetryIntervalSec = s->RetryInterval / 1000;
			p.Type = s->ClientAuth->AuthType;

			// Display the password re-entry dialog
			if (CncPasswordDlg(s, &p) == false)
			{
				// Abort the connection
				break;
			}
			else
			{
				// Overwrite the user name
				if (p.ProxyServer)
				{
					// User name of the proxy
					StrCpy(s->ClientOption->ProxyUsername, sizeof(s->ClientOption->ProxyUsername), p.Username);
				}
				else
				{
					// The user name for connecting to the server
					StrCpy(s->ClientAuth->Username, sizeof(s->ClientAuth->Username), p.Username);
					s->ClientAuth->AuthType = p.Type;
				}

				if (StrCmp(p.Password, HIDDEN_PASSWORD) != 0)
				{
					// Password is re-entered
					if (p.ProxyServer)
					{
						// Password for the proxy server
						StrCpy(s->ClientOption->ProxyPassword, sizeof(s->ClientOption->ProxyPassword), p.Password);
					}
					else
					{
						if (s->ClientAuth->AuthType == CLIENT_AUTHTYPE_PLAIN_PASSWORD)
						{
							// Plaintext password authentication
							StrCpy(s->ClientAuth->PlainPassword, sizeof(s->ClientAuth->PlainPassword), p.Password);
						}
						else
						{
							// Encrypted password authentication
							HashPassword(s->ClientAuth->HashedPassword, s->ClientAuth->Username, p.Password);
						}
					}
				}

				no_save_password = p.NoSavePassword;

				if (s->Account != NULL && s->Cedar->Client != NULL)
				{
					s->Cedar->Client->DontSavePassword = no_save_password;
					if (p.NoSavePassword == false)
					{
						// Update the account database of the client
						if (p.ProxyServer == false)
						{
							// Update the Server connection information
							ACCOUNT *a = s->Account;
							Lock(a->lock);
							{
								CiFreeClientAuth(a->ClientAuth);
								a->ClientAuth = CopyClientAuth(s->ClientAuth);
							}
							Unlock(a->lock);
							CiSaveConfigurationFile(s->Cedar->Client);
						}
						else
						{
							// Update the proxy connection information
							ACCOUNT *a = s->Account;
							Lock(a->lock);
							{
								Copy(a->ClientOption, s->ClientOption, sizeof(CLIENT_OPTION));
							}
							Unlock(a->lock);
							CiSaveConfigurationFile(s->Cedar->Client);
						}
					}
				}
			}
#endif	// OS_WIN32
		}

SKIP:
		// Increase the number of retries
		if (s->ConnectSucceed == false)
		{
			s->CurrentRetryCount++;
		}

		if (s->ForceStopFlag)
		{
			break;
		}
	}

	Debug("Session Halt.\n");

	s->ClientStatus = CLIENT_STATUS_IDLE;

	// Regard as that the session is ended here
	if (s->Account != NULL)
	{
		s->Account->ClientSession = NULL;
		ReleaseSession(s);
	}

	Notify(s, CLIENT_NOTIFY_ACCOUNT_CHANGED);


	ReleaseSession(s);

	if (num_active_sessions_incremented)
	{
		CiDecrementNumActiveSessions();
	}
}