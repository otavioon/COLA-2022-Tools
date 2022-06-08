#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef int scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_6__   TYPE_3__ ;
typedef  struct TYPE_5__   TYPE_2__ ;
typedef  struct TYPE_4__   TYPE_1__ ;

/* Type definitions */
struct TYPE_4__ {int /*<<< orphan*/  iSocketDescriptor; int /*<<< orphan*/  iNumberOfBytes; } ;
typedef  TYPE_1__ tBsdReadReturnParams ;
struct TYPE_5__ {scalar_t__ iStatus; } ;
typedef  TYPE_2__ tBsdGetSockOptReturnParams ;
typedef  int /*<<< orphan*/  sockaddr ;
typedef  scalar_t__ UINT8 ;
typedef  int UINT32 ;
typedef  int UINT16 ;
struct TYPE_6__ {scalar_t__ usEventOrDataReceived; scalar_t__ usNumberOfFreeBuffers; int usSlBufferLength; int usRxEventOpcode; scalar_t__ usRxDataPending; scalar_t__* pucReceivedData; } ;
typedef  scalar_t__ CHAR ;

/* Variables and functions */
 int /*<<< orphan*/  ACCEPT_ADDRESS__OFFSET ; 
 int /*<<< orphan*/  ACCEPT_RETURN_STATUS_OFFSET ; 
 int /*<<< orphan*/  ACCEPT_SD_OFFSET ; 
 int /*<<< orphan*/  BSD_RECV_FROM_FROMLEN_OFFSET ; 
 int BSD_RECV_FROM_FROM_OFFSET ; 
 int /*<<< orphan*/  ERROR_SOCKET_INACTIVE ; 
 int /*<<< orphan*/  GET_HOST_BY_NAME_ADDR_OFFSET ; 
 int /*<<< orphan*/  GET_HOST_BY_NAME_RETVAL_OFFSET ; 
 int GET_MSS_VAL_RETVAL_OFFSET ; 
 int GET_SCAN_RESULTS_FRAME_TIME_OFFSET ; 
 int GET_SCAN_RESULTS_ISVALID_TO_SSIDLEN_OFFSET ; 
 int /*<<< orphan*/  GET_SCAN_RESULTS_SCANRESULT_STATUS_OFFSET ; 
 int GET_SCAN_RESULTS_SSID_MAC_LENGTH ; 
 int /*<<< orphan*/  GET_SCAN_RESULTS_TABlE_COUNT_OFFSET ; 
#define  HCI_CMND_EVENT_MASK 171 
#define  HCI_CMND_GETSOCKOPT 170 
#define  HCI_CMND_LISTEN 169 
#define  HCI_CMND_NVMEM_WRITE_PATCH 168 
#define  HCI_CMND_READ_BUFFER_SIZE 167 
#define  HCI_CMND_SETSOCKOPT 166 
#define  HCI_CMND_SIMPLE_LINK_START 165 
#define  HCI_CMND_WLAN_CONFIGURE_PATCH 164 
#define  HCI_CMND_WLAN_CONNECT 163 
#define  HCI_CMND_WLAN_IOCTL_DEL_PROFILE 162 
#define  HCI_CMND_WLAN_IOCTL_GET_SCAN_RESULTS 161 
#define  HCI_CMND_WLAN_IOCTL_SET_CONNECTION_POLICY 160 
#define  HCI_CMND_WLAN_IOCTL_SET_SCANPARAM 159 
#define  HCI_CMND_WLAN_IOCTL_SIMPLE_CONFIG_SET_PREFIX 158 
#define  HCI_CMND_WLAN_IOCTL_SIMPLE_CONFIG_START 157 
#define  HCI_CMND_WLAN_IOCTL_SIMPLE_CONFIG_STOP 156 
#define  HCI_CMND_WLAN_IOCTL_STATUSGET 155 
 int HCI_DATA_HEADER_SIZE ; 
 int /*<<< orphan*/  HCI_DATA_LENGTH_OFFSET ; 
 int HCI_EVENT_HEADER_SIZE ; 
 int HCI_EVENT_OPCODE_OFFSET ; 
 int /*<<< orphan*/  HCI_EVENT_STATUS_OFFSET ; 
#define  HCI_EVNT_ACCEPT 154 
#define  HCI_EVNT_BIND 153 
#define  HCI_EVNT_BSD_GETHOSTBYNAME 152 
#define  HCI_EVNT_CLOSE_SOCKET 151 
#define  HCI_EVNT_CONNECT 150 
#define  HCI_EVNT_GETMSSVALUE 149 
#define  HCI_EVNT_MDNS_ADVERTISE 148 
#define  HCI_EVNT_NVMEM_CREATE_ENTRY 147 
#define  HCI_EVNT_NVMEM_READ 146 
#define  HCI_EVNT_NVMEM_WRITE 145 
 int HCI_EVNT_PATCHES_REQ ; 
#define  HCI_EVNT_READ_SP_VERSION 144 
#define  HCI_EVNT_RECV 143 
#define  HCI_EVNT_RECVFROM 142 
#define  HCI_EVNT_SELECT 141 
#define  HCI_EVNT_SEND 140 
#define  HCI_EVNT_SENDTO 139 
#define  HCI_EVNT_SOCKET 138 
#define  HCI_EVNT_WLAN_DISCONNECT 137 
#define  HCI_EVNT_WLAN_IOCTL_ADD_PROFILE 136 
#define  HCI_NETAPP_ARP_FLUSH 135 
#define  HCI_NETAPP_DHCP 134 
#define  HCI_NETAPP_IPCONFIG 133 
#define  HCI_NETAPP_PING_REPORT 132 
#define  HCI_NETAPP_PING_SEND 131 
#define  HCI_NETAPP_PING_STOP 130 
#define  HCI_NETAPP_SET_DEBUG_LEVEL 129 
#define  HCI_NETAPP_SET_TIMERS 128 
 int /*<<< orphan*/  HCI_PACKET_ARGSIZE_OFFSET ; 
 int HCI_PACKET_LENGTH_OFFSET ; 
 scalar_t__ HCI_TYPE_EVNT ; 
 int /*<<< orphan*/  NETAPP_IPCONFIG_IP_LENGTH ; 
 int /*<<< orphan*/  NETAPP_IPCONFIG_MAC_LENGTH ; 
 int /*<<< orphan*/  NETAPP_IPCONFIG_SSID_LENGTH ; 
 int /*<<< orphan*/  SELECT_EXFD_OFFSET ; 
 int /*<<< orphan*/  SELECT_READFD_OFFSET ; 
 int /*<<< orphan*/  SELECT_STATUS_OFFSET ; 
 int /*<<< orphan*/  SELECT_WRITEFD_OFFSET ; 
 int /*<<< orphan*/  SL_RECEIVE_NUM_BYTES_OFFSET ; 
 int /*<<< orphan*/  SL_RECEIVE_SD_OFFSET ; 
 int /*<<< orphan*/  SL_RECEIVE__FLAGS__OFFSET ; 
 int /*<<< orphan*/  SOCKET_STATUS_INACTIVE ; 
 int /*<<< orphan*/  STREAM_TO_STREAM (scalar_t__*,scalar_t__*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  STREAM_TO_UINT16 (scalar_t__*,int,int) ; 
 int /*<<< orphan*/  STREAM_TO_UINT32 (scalar_t__*,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  STREAM_TO_UINT8 (scalar_t__*,int /*<<< orphan*/ ,scalar_t__) ; 
 int /*<<< orphan*/  SpiResumeSpi () ; 
 int /*<<< orphan*/  UINT32_TO_STREAM (scalar_t__*,int) ; 
 scalar_t__ hci_unsol_event_handler (scalar_t__*) ; 
 int /*<<< orphan*/  hci_unsol_handle_patch_request (scalar_t__*) ; 
 int /*<<< orphan*/  memcpy (scalar_t__*,scalar_t__*,int) ; 
 int /*<<< orphan*/  set_socket_active_status (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 TYPE_3__ tSLInformation ; 

UINT8 * hci_event_handler(void *pRetParams, UINT8 *from, UINT8 *fromlen)
{
	UINT8 *pucReceivedData, ucArgsize;
	UINT16 usLength;
	UINT8 *pucReceivedParams;
	UINT16 usReceivedEventOpcode = 0;
	UINT32 retValue32;
	UINT8 * RecvParams;
	UINT8 *RetParams;


	while (1)
	{
		if (tSLInformation.usEventOrDataReceived != 0)
		{				
			pucReceivedData = (tSLInformation.pucReceivedData);

			if (*pucReceivedData == HCI_TYPE_EVNT)
			{
				// Event Received
				STREAM_TO_UINT16((CHAR *)pucReceivedData, HCI_EVENT_OPCODE_OFFSET,
					usReceivedEventOpcode);
				pucReceivedParams = pucReceivedData + HCI_EVENT_HEADER_SIZE;		
				RecvParams = pucReceivedParams;
				RetParams = pRetParams;

				// In case unsolicited event received - here the handling finished
				if (hci_unsol_event_handler((CHAR *)pucReceivedData) == 0)
				{
					STREAM_TO_UINT8(pucReceivedData, HCI_DATA_LENGTH_OFFSET, usLength);

					switch(usReceivedEventOpcode)
					{		
					case HCI_CMND_READ_BUFFER_SIZE:
						{
							STREAM_TO_UINT8((CHAR *)pucReceivedParams, 0, 
								tSLInformation.usNumberOfFreeBuffers);
							STREAM_TO_UINT16((CHAR *)pucReceivedParams, 1, 
								tSLInformation.usSlBufferLength);
						}
						break;

					case HCI_CMND_WLAN_CONFIGURE_PATCH:
					case HCI_NETAPP_DHCP:
					case HCI_NETAPP_PING_SEND:
					case HCI_NETAPP_PING_STOP:
					case HCI_NETAPP_ARP_FLUSH:
					case HCI_NETAPP_SET_DEBUG_LEVEL:
					case HCI_NETAPP_SET_TIMERS:
					case HCI_EVNT_NVMEM_READ:
					case HCI_EVNT_NVMEM_CREATE_ENTRY:
					case HCI_CMND_NVMEM_WRITE_PATCH:
					case HCI_NETAPP_PING_REPORT:
					case HCI_EVNT_MDNS_ADVERTISE:

						STREAM_TO_UINT8(pucReceivedData, HCI_EVENT_STATUS_OFFSET
							,*(UINT8 *)pRetParams);
						break;

					case HCI_CMND_SETSOCKOPT:
					case HCI_CMND_WLAN_CONNECT:
					case HCI_CMND_WLAN_IOCTL_STATUSGET:
					case HCI_EVNT_WLAN_IOCTL_ADD_PROFILE:
					case HCI_CMND_WLAN_IOCTL_DEL_PROFILE:
					case HCI_CMND_WLAN_IOCTL_SET_CONNECTION_POLICY:
					case HCI_CMND_WLAN_IOCTL_SET_SCANPARAM:
					case HCI_CMND_WLAN_IOCTL_SIMPLE_CONFIG_START:
					case HCI_CMND_WLAN_IOCTL_SIMPLE_CONFIG_STOP:
					case HCI_CMND_WLAN_IOCTL_SIMPLE_CONFIG_SET_PREFIX:
					case HCI_CMND_EVENT_MASK:
					case HCI_EVNT_WLAN_DISCONNECT:
					case HCI_EVNT_SOCKET:
					case HCI_EVNT_BIND:
					case HCI_CMND_LISTEN:
					case HCI_EVNT_CLOSE_SOCKET:
					case HCI_EVNT_CONNECT:
					case HCI_EVNT_NVMEM_WRITE:

						STREAM_TO_UINT32((CHAR *)pucReceivedParams,0
							,*(UINT32 *)pRetParams);
						break;

					case HCI_EVNT_READ_SP_VERSION:

						STREAM_TO_UINT8(pucReceivedData, HCI_EVENT_STATUS_OFFSET
							,*(UINT8 *)pRetParams);
						pRetParams = ((CHAR *)pRetParams) + 1;
						STREAM_TO_UINT32((CHAR *)pucReceivedParams, 0, retValue32);
						UINT32_TO_STREAM((UINT8 *)pRetParams, retValue32);				
						break;

					case HCI_EVNT_BSD_GETHOSTBYNAME:

						STREAM_TO_UINT32((CHAR *)pucReceivedParams
							,GET_HOST_BY_NAME_RETVAL_OFFSET,*(UINT32 *)pRetParams);
						pRetParams = ((CHAR *)pRetParams) + 4;
						STREAM_TO_UINT32((CHAR *)pucReceivedParams
							,GET_HOST_BY_NAME_ADDR_OFFSET,*(UINT32 *)pRetParams);					
						break;

					case HCI_EVNT_GETMSSVALUE:

						STREAM_TO_UINT16((CHAR *)pucReceivedParams
							,GET_MSS_VAL_RETVAL_OFFSET,*(UINT16 *)pRetParams);					

						break;

					case HCI_EVNT_ACCEPT:
						{
							STREAM_TO_UINT32((CHAR *)pucReceivedParams,ACCEPT_SD_OFFSET
								,*(UINT32 *)pRetParams);
							pRetParams = ((CHAR *)pRetParams) + 4;
							STREAM_TO_UINT32((CHAR *)pucReceivedParams
								,ACCEPT_RETURN_STATUS_OFFSET,*(UINT32 *)pRetParams);
							pRetParams = ((CHAR *)pRetParams) + 4; 

							//This argument returns in network order
							memcpy((UINT8 *)pRetParams, 
								pucReceivedParams + ACCEPT_ADDRESS__OFFSET, sizeof(sockaddr));	
							break;
						}

					case HCI_EVNT_RECV:
					case HCI_EVNT_RECVFROM:
						{
							STREAM_TO_UINT32((CHAR *)pucReceivedParams,SL_RECEIVE_SD_OFFSET ,*(UINT32 *)pRetParams);
							pRetParams = ((CHAR *)pRetParams) + 4;
							STREAM_TO_UINT32((CHAR *)pucReceivedParams,SL_RECEIVE_NUM_BYTES_OFFSET,*(UINT32 *)pRetParams);
							pRetParams = ((CHAR *)pRetParams) + 4;
							STREAM_TO_UINT32((CHAR *)pucReceivedParams,SL_RECEIVE__FLAGS__OFFSET,*(UINT32 *)pRetParams);

							if(((tBsdReadReturnParams *)pRetParams)->iNumberOfBytes == ERROR_SOCKET_INACTIVE)
							{
								set_socket_active_status(((tBsdReadReturnParams *)pRetParams)->iSocketDescriptor,SOCKET_STATUS_INACTIVE);
							}
							break;
						}

					case HCI_EVNT_SEND:
					case HCI_EVNT_SENDTO:
						{
							STREAM_TO_UINT32((CHAR *)pucReceivedParams,SL_RECEIVE_SD_OFFSET ,*(UINT32 *)pRetParams);
							pRetParams = ((CHAR *)pRetParams) + 4;
							STREAM_TO_UINT32((CHAR *)pucReceivedParams,SL_RECEIVE_NUM_BYTES_OFFSET,*(UINT32 *)pRetParams);
							pRetParams = ((CHAR *)pRetParams) + 4;

							break;
						}

					case HCI_EVNT_SELECT:
						{ 
							STREAM_TO_UINT32((CHAR *)pucReceivedParams,SELECT_STATUS_OFFSET,*(UINT32 *)pRetParams);
							pRetParams = ((CHAR *)pRetParams) + 4;
							STREAM_TO_UINT32((CHAR *)pucReceivedParams,SELECT_READFD_OFFSET,*(UINT32 *)pRetParams);
							pRetParams = ((CHAR *)pRetParams) + 4;
							STREAM_TO_UINT32((CHAR *)pucReceivedParams,SELECT_WRITEFD_OFFSET,*(UINT32 *)pRetParams);
							pRetParams = ((CHAR *)pRetParams) + 4;
							STREAM_TO_UINT32((CHAR *)pucReceivedParams,SELECT_EXFD_OFFSET,*(UINT32 *)pRetParams);			
							break;
						}

					case HCI_CMND_GETSOCKOPT:

						STREAM_TO_UINT8(pucReceivedData, HCI_EVENT_STATUS_OFFSET,((tBsdGetSockOptReturnParams *)pRetParams)->iStatus);
						//This argument returns in network order
						memcpy((UINT8 *)pRetParams, pucReceivedParams, 4);
						break;

					case HCI_CMND_WLAN_IOCTL_GET_SCAN_RESULTS:

						STREAM_TO_UINT32((CHAR *)pucReceivedParams,GET_SCAN_RESULTS_TABlE_COUNT_OFFSET,*(UINT32 *)pRetParams);
						pRetParams = ((CHAR *)pRetParams) + 4;   					
						STREAM_TO_UINT32((CHAR *)pucReceivedParams,GET_SCAN_RESULTS_SCANRESULT_STATUS_OFFSET,*(UINT32 *)pRetParams);
						pRetParams = ((CHAR *)pRetParams) + 4;                                                        					
						STREAM_TO_UINT16((CHAR *)pucReceivedParams,GET_SCAN_RESULTS_ISVALID_TO_SSIDLEN_OFFSET,*(UINT32 *)pRetParams);
						pRetParams = ((CHAR *)pRetParams) + 2;   					
						STREAM_TO_UINT16((CHAR *)pucReceivedParams,GET_SCAN_RESULTS_FRAME_TIME_OFFSET,*(UINT32 *)pRetParams);
						pRetParams = ((CHAR *)pRetParams) + 2;  
						memcpy((UINT8 *)pRetParams, (CHAR *)(pucReceivedParams + GET_SCAN_RESULTS_FRAME_TIME_OFFSET + 2), GET_SCAN_RESULTS_SSID_MAC_LENGTH);	
						break;

					case HCI_CMND_SIMPLE_LINK_START:
						break;

					case HCI_NETAPP_IPCONFIG:

						//Read IP address
						STREAM_TO_STREAM(RecvParams,RetParams,NETAPP_IPCONFIG_IP_LENGTH);
						RecvParams += 4;

						//Read subnet
						STREAM_TO_STREAM(RecvParams,RetParams,NETAPP_IPCONFIG_IP_LENGTH);
						RecvParams += 4;

						//Read default GW
						STREAM_TO_STREAM(RecvParams,RetParams,NETAPP_IPCONFIG_IP_LENGTH);
						RecvParams += 4;

						//Read DHCP server                                          	
						STREAM_TO_STREAM(RecvParams,RetParams,NETAPP_IPCONFIG_IP_LENGTH);
						RecvParams += 4;

						//Read DNS server                                           
						STREAM_TO_STREAM(RecvParams,RetParams,NETAPP_IPCONFIG_IP_LENGTH);
						RecvParams += 4;

						//Read Mac address                            	
						STREAM_TO_STREAM(RecvParams,RetParams,NETAPP_IPCONFIG_MAC_LENGTH);
						RecvParams += 6;

						//Read SSID
						STREAM_TO_STREAM(RecvParams,RetParams,NETAPP_IPCONFIG_SSID_LENGTH);

					}
				}

				if (usReceivedEventOpcode == tSLInformation.usRxEventOpcode)
				{
					tSLInformation.usRxEventOpcode = 0;
				}
			}
			else
			{				
				pucReceivedParams = pucReceivedData;
				STREAM_TO_UINT8((CHAR *)pucReceivedData, HCI_PACKET_ARGSIZE_OFFSET, ucArgsize);

				STREAM_TO_UINT16((CHAR *)pucReceivedData, HCI_PACKET_LENGTH_OFFSET, usLength);

				// Data received: note that the only case where from and from length 
				// are not null is in recv from, so fill the args accordingly
				if (from)
				{
					STREAM_TO_UINT32((CHAR *)(pucReceivedData + HCI_DATA_HEADER_SIZE), BSD_RECV_FROM_FROMLEN_OFFSET, *(UINT32 *)fromlen);
					memcpy(from, (pucReceivedData + HCI_DATA_HEADER_SIZE + BSD_RECV_FROM_FROM_OFFSET) ,*fromlen);
				}

				memcpy(pRetParams, pucReceivedParams + HCI_DATA_HEADER_SIZE + ucArgsize,
					usLength - ucArgsize);

				tSLInformation.usRxDataPending = 0;
			}

			tSLInformation.usEventOrDataReceived = 0;

			SpiResumeSpi();

			// Since we are going to TX - we need to handle this event after the 
			// ResumeSPi since we need interrupts
			if ((*pucReceivedData == HCI_TYPE_EVNT) &&
				(usReceivedEventOpcode == HCI_EVNT_PATCHES_REQ))
			{
				hci_unsol_handle_patch_request((CHAR *)pucReceivedData);
			}

			if ((tSLInformation.usRxEventOpcode == 0) && (tSLInformation.usRxDataPending == 0))
			{
				return NULL;
			}	
		}
	}

}