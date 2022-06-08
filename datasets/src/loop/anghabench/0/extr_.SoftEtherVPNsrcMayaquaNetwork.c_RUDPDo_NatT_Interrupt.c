#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef int scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_10__   TYPE_3__ ;
typedef  struct TYPE_9__   TYPE_2__ ;
typedef  struct TYPE_8__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  private_ip_str ;
typedef  int /*<<< orphan*/  machine_name ;
typedef  int /*<<< orphan*/  machine_key ;
typedef  int /*<<< orphan*/  hash ;
typedef  int /*<<< orphan*/  ddns_fqdn ;
typedef  int UINT64 ;
typedef  scalar_t__ UINT ;
typedef  char UCHAR ;
struct TYPE_10__ {char* Buf; int Size; } ;
struct TYPE_9__ {scalar_t__ NatT_GetTokenNextTick; scalar_t__ Now; int NatT_Token_Ok; scalar_t__ NatT_NextNatStatusCheckTick; scalar_t__ LastDDnsFqdnHash; scalar_t__ NatT_RegisterNextTick; char* NatT_Token; char* SvcName; int NatT_Register_Ok; int /*<<< orphan*/  Interrupt; int /*<<< orphan*/  NatT_RegisterFailNum; int /*<<< orphan*/  NatT_IP_Safe; TYPE_1__* UdpSock; int /*<<< orphan*/  My_Private_IP_Safe; int /*<<< orphan*/  NatT_SessionKey; int /*<<< orphan*/  NatT_TranId; int /*<<< orphan*/  NatT_GetTokenFailNum; scalar_t__ ServerMode; } ;
struct TYPE_8__ {int /*<<< orphan*/  LocalPort; } ;
typedef  TYPE_2__ RUDP_STACK ;
typedef  int /*<<< orphan*/  PACK ;
typedef  TYPE_3__ BUF ;

/* Variables and functions */
 int /*<<< orphan*/  AddInterrupt (int /*<<< orphan*/ ,scalar_t__) ; 
 int /*<<< orphan*/  BinToStr (char*,int,char*,int) ; 
 int /*<<< orphan*/  Debug (char*) ; 
 int /*<<< orphan*/  FreeBuf (TYPE_3__*) ; 
 int /*<<< orphan*/  FreePack (int /*<<< orphan*/ *) ; 
 int GenRandInterval (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  GetCurrentDDnsFqdn (char*,int) ; 
 scalar_t__ GetCurrentDDnsFqdnHash () ; 
 int /*<<< orphan*/  GetCurrentMachineIpProcessHash (char*) ; 
 int /*<<< orphan*/  GetMachineName (char*,int) ; 
 int /*<<< orphan*/  IPToStr (char*,int,int /*<<< orphan*/ *) ; 
 int IsZeroIp (int /*<<< orphan*/ *) ; 
 int MAX_SIZE ; 
 int MIN (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/ * NewPack () ; 
 int /*<<< orphan*/  PackAddBool (int /*<<< orphan*/ *,char*,scalar_t__) ; 
 int /*<<< orphan*/  PackAddInt (int /*<<< orphan*/ *,char*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  PackAddInt64 (int /*<<< orphan*/ *,char*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  PackAddStr (int /*<<< orphan*/ *,char*,char*) ; 
 TYPE_3__* PackToBuf (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  RUDPSendPacket (TYPE_2__*,int /*<<< orphan*/ *,int /*<<< orphan*/ ,char*,int,int /*<<< orphan*/ ) ; 
 int SHA1_SIZE ; 
 int /*<<< orphan*/  UDP_NAT_TRAVERSAL_VERSION ; 
 int UDP_NAT_T_GET_TOKEN_INTERVAL_1 ; 
 int /*<<< orphan*/  UDP_NAT_T_GET_TOKEN_INTERVAL_FAIL_MAX ; 
 int /*<<< orphan*/  UDP_NAT_T_NAT_STATUS_CHECK_INTERVAL_MAX ; 
 int /*<<< orphan*/  UDP_NAT_T_NAT_STATUS_CHECK_INTERVAL_MIN ; 
 int /*<<< orphan*/  UDP_NAT_T_PORT ; 
 int /*<<< orphan*/  UDP_NAT_T_REGISTER_INTERVAL_FAIL_MAX ; 
 int UDP_NAT_T_REGISTER_INTERVAL_INITIAL ; 
 int /*<<< orphan*/  Zero (char*,int) ; 
 scalar_t__ g_natt_low_priority ; 
 int g_no_rudp_register ; 

void RUDPDo_NatT_Interrupt(RUDP_STACK *r)
{
	// Validate arguments
	if (r == NULL)
	{
		return;
	}

	if (r->ServerMode)
	{

		if (g_no_rudp_register == false && IsZeroIp(&r->NatT_IP_Safe) == false)
		{
			if (r->NatT_GetTokenNextTick == 0 || r->Now >= r->NatT_GetTokenNextTick)
			{
				// Try to get a token from the NAT-T server periodically
				PACK *p = NewPack();
				BUF *b;

				PackAddStr(p, "opcode", "get_token");
				PackAddInt64(p, "tran_id", r->NatT_TranId);
				PackAddInt(p, "nat_traversal_version", UDP_NAT_TRAVERSAL_VERSION);

				b = PackToBuf(p);
				FreePack(p);

				RUDPSendPacket(r, &r->NatT_IP_Safe, UDP_NAT_T_PORT, b->Buf, b->Size, 0);

				FreeBuf(b);

				// Determine the next acquisition time
				r->NatT_GetTokenFailNum++;
				r->NatT_GetTokenNextTick = r->Now + (UINT64)(UDP_NAT_T_GET_TOKEN_INTERVAL_1 * (UINT64)MIN(r->NatT_GetTokenFailNum, UDP_NAT_T_GET_TOKEN_INTERVAL_FAIL_MAX));
				AddInterrupt(r->Interrupt, r->NatT_GetTokenNextTick);
				r->NatT_Token_Ok = false;
			}
		}

		{
			if (IsZeroIp(&r->NatT_IP_Safe) == false)
			{
				// Normal servers: Send request packets to the NAT-T server
				if (r->NatT_NextNatStatusCheckTick == 0 || r->Now >= r->NatT_NextNatStatusCheckTick)
				{
					UCHAR a = 'A';
					UINT ddns_hash;
					// Check of the NAT state
					RUDPSendPacket(r, &r->NatT_IP_Safe, UDP_NAT_T_PORT, &a, 1, 0);

					// Execution time of the next
					r->NatT_NextNatStatusCheckTick = r->Now + (UINT64)GenRandInterval(UDP_NAT_T_NAT_STATUS_CHECK_INTERVAL_MIN, UDP_NAT_T_NAT_STATUS_CHECK_INTERVAL_MAX);
					AddInterrupt(r->Interrupt, r->NatT_NextNatStatusCheckTick);

					// Check whether the DDNS host name changing have not occurred
					ddns_hash = GetCurrentDDnsFqdnHash();

					if (r->LastDDnsFqdnHash != ddns_hash)
					{
						r->LastDDnsFqdnHash = ddns_hash;
						// Do the Register immediately if there is a change in the DDNS host name
						r->NatT_RegisterNextTick = 0;
					}
				}
			}
		}

		if (r->NatT_Token_Ok && g_no_rudp_register == false && IsZeroIp(&r->NatT_IP_Safe) == false)
		{
			if (r->NatT_RegisterNextTick == 0 || r->Now >= r->NatT_RegisterNextTick)
			{
				// Try to register itself periodically for NAT-T server
				PACK *p = NewPack();
				BUF *b;
				char private_ip_str[MAX_SIZE];
				char machine_key[MAX_SIZE];
				char machine_name[MAX_SIZE];
				UCHAR hash[SHA1_SIZE];
				char ddns_fqdn[MAX_SIZE];

				Debug("NAT-T Registering...\n");

				GetCurrentDDnsFqdn(ddns_fqdn, sizeof(ddns_fqdn));

				PackAddStr(p, "opcode", "nat_t_register");
				PackAddInt64(p, "tran_id", r->NatT_TranId);
				PackAddStr(p, "token", r->NatT_Token);
				PackAddStr(p, "svc_name", r->SvcName);
				PackAddStr(p, "product_str", "SoftEther OSS");
				PackAddInt64(p, "session_key", r->NatT_SessionKey);
				PackAddInt(p, "nat_traversal_version", UDP_NAT_TRAVERSAL_VERSION);


				if (g_natt_low_priority)
				{
					PackAddBool(p, "low_priority", g_natt_low_priority);
				}

				Zero(private_ip_str, sizeof(private_ip_str));
				if (IsZeroIp(&r->My_Private_IP_Safe) == false)
				{
					IPToStr(private_ip_str, sizeof(private_ip_str), &r->My_Private_IP_Safe);
					PackAddStr(p, "private_ip", private_ip_str);
				}

				PackAddInt(p, "private_port", r->UdpSock->LocalPort);

				Zero(hash, sizeof(hash));
				GetCurrentMachineIpProcessHash(hash);
				BinToStr(machine_key, sizeof(machine_key), hash, sizeof(hash));
				PackAddStr(p, "machine_key", machine_key);

				Zero(machine_name, sizeof(machine_name));
				GetMachineName(machine_name, sizeof(machine_name));
				PackAddStr(p, "host_name", machine_name);
				PackAddStr(p, "ddns_fqdn", ddns_fqdn);

				b = PackToBuf(p);
				FreePack(p);

				RUDPSendPacket(r, &r->NatT_IP_Safe, UDP_NAT_T_PORT, b->Buf, b->Size, 0);
				//RUDPSendPacket(r, &r->NatT_IP_Safe, UDP_NAT_T_PORT, "a", 1);

				FreeBuf(b);

				// Determine the next acquisition time
				r->NatT_RegisterFailNum++;
				r->NatT_RegisterNextTick = r->Now + (UINT64)UDP_NAT_T_REGISTER_INTERVAL_INITIAL * (UINT64)MIN(r->NatT_RegisterFailNum, UDP_NAT_T_REGISTER_INTERVAL_FAIL_MAX);
				AddInterrupt(r->Interrupt, r->NatT_RegisterNextTick);
				r->NatT_Register_Ok = false;
			}
		}
	}
}