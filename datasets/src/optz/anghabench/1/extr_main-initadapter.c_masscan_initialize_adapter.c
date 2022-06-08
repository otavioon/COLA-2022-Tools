#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_8__   TYPE_4__ ;
typedef  struct TYPE_7__   TYPE_3__ ;
typedef  struct TYPE_6__   TYPE_2__ ;
typedef  struct TYPE_5__   TYPE_1__ ;

/* Type definitions */
struct TYPE_7__ {int /*<<< orphan*/  packet_trace; } ;
struct Masscan {TYPE_4__* nic; int /*<<< orphan*/  is_offline; scalar_t__ bpf_filter; TYPE_3__ nmap; int /*<<< orphan*/  is_sendq; int /*<<< orphan*/  is_pfring; } ;
typedef  int /*<<< orphan*/  ifname2 ;
struct TYPE_5__ {unsigned int first; unsigned int last; int range; } ;
struct TYPE_6__ {TYPE_1__ ip; } ;
struct TYPE_8__ {char* ifname; char* my_mac; scalar_t__ my_mac_count; char* router_mac; unsigned int router_ip; int /*<<< orphan*/  adapter; int /*<<< orphan*/  vlan_id; int /*<<< orphan*/  is_vlan; TYPE_2__ src; } ;

/* Variables and functions */
 int /*<<< orphan*/  LOG (int,char*,...) ; 
 int /*<<< orphan*/  arp_resolve_sync (int /*<<< orphan*/ ,unsigned int,unsigned char*,unsigned int,unsigned char*) ; 
 int /*<<< orphan*/  fprintf (int /*<<< orphan*/ ,char*,...) ; 
 scalar_t__ memcmp (unsigned char*,char*,int) ; 
 int /*<<< orphan*/  memcpy (unsigned char*,char*,int) ; 
 unsigned int rawsock_get_adapter_ip (char*) ; 
 int /*<<< orphan*/  rawsock_get_adapter_mac (char*,unsigned char*) ; 
 int rawsock_get_default_gateway (char*,unsigned int*) ; 
 int rawsock_get_default_interface (char*,int) ; 
 int /*<<< orphan*/  rawsock_ignore_transmits (int /*<<< orphan*/ ,unsigned char*,char*) ; 
 int /*<<< orphan*/  rawsock_init_adapter (char*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,void*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  stderr ; 

int
masscan_initialize_adapter(
    struct Masscan *masscan,
    unsigned index,
    unsigned char *adapter_mac,
    unsigned char *router_mac
    )
{
    char *ifname;
    char ifname2[256];
    unsigned adapter_ip = 0;
    
    if (masscan == NULL)
        return -1;

    LOG(1, "if: initializing adapter interface\n");

    /*
     * ADAPTER/NETWORK-INTERFACE
     *
     * If no network interface was configured, we need to go hunt down
     * the best Interface to use. We do this by choosing the first
     * interface with a "default route" (aka. "gateway") defined
     */
    if (masscan->nic[index].ifname[0])
        ifname = masscan->nic[index].ifname;
    else {
        /* no adapter specified, so find a default one */
        int err;
        ifname2[0] = '\0';
        err = rawsock_get_default_interface(ifname2, sizeof(ifname2));
        if (err || ifname2[0] == '\0') {
            fprintf(stderr, "FAIL: could not determine default interface\n");
            fprintf(stderr, "FAIL:... try \"--interface ethX\"\n");
            return -1;
        }
        ifname = ifname2;
    }
    LOG(2, "if: interface=%s\n", ifname);

    /*
     * IP ADDRESS
     *
     * We need to figure out that IP address to send packets from. This
     * is done by querying the adapter (or configured by user). If the
     * adapter doesn't have one, then the user must configure one.
     */
    adapter_ip = masscan->nic[index].src.ip.first;
    if (adapter_ip == 0) {
        adapter_ip = rawsock_get_adapter_ip(ifname);
        masscan->nic[index].src.ip.first = adapter_ip;
        masscan->nic[index].src.ip.last = adapter_ip;
        masscan->nic[index].src.ip.range = 1;
    }
    if (adapter_ip == 0) {
        fprintf(stderr, "FAIL: failed to detect IP of interface \"%s\"\n",
                        ifname);
        fprintf(stderr, " [hint] did you spell the name correctly?\n");
        fprintf(stderr, " [hint] if it has no IP address, manually set with "
                        "\"--adapter-ip 192.168.100.5\"\n");
        return -1;
    }
    LOG(2, "if:%s: adapter-ip=%u.%u.%u.%u\n",
        ifname,
        (adapter_ip>>24)&0xFF,
        (adapter_ip>>16)&0xFF,
        (adapter_ip>> 8)&0xFF,
        (adapter_ip>> 0)&0xFF
        );

    /*
     * MAC ADDRESS
     *
     * This is the address we send packets from. It actually doesn't really
     * matter what this address is, but to be a "responsible" citizen we
     * try to use the hardware address in the network card.
     */
    memcpy(adapter_mac, masscan->nic[index].my_mac, 6);
    if (masscan->nic[index].my_mac_count == 0) {
        if (memcmp(adapter_mac, "\0\0\0\0\0\0", 6) == 0) {
            rawsock_get_adapter_mac(ifname, adapter_mac);
        }
        if (memcmp(adapter_mac, "\0\0\0\0\0\0", 6) == 0) {
            fprintf(stderr, "FAIL: failed to detect MAC address of interface:"
                    " \"%s\"\n", ifname);
            fprintf(stderr, " [hint] try something like "
                    "\"--adapter-mac 00-11-22-33-44-55\"\n");
            return -1;
        }
    }
    LOG(2, "if:%s: adapter-mac=%02x-%02x-%02x-%02x-%02x-%02x\n",
        ifname,
        adapter_mac[0],
        adapter_mac[1],
        adapter_mac[2],
        adapter_mac[3],
        adapter_mac[4],
        adapter_mac[5]
        );


    /*
     * START ADAPTER
     *
     * Once we've figured out which adapter to use, we now need to
     * turn it on.
     */
    masscan->nic[index].adapter = rawsock_init_adapter(
                                            ifname,
                                            masscan->is_pfring,
                                            masscan->is_sendq,
                                            masscan->nmap.packet_trace,
                                            masscan->is_offline,
                                            (void*)masscan->bpf_filter,
                                            masscan->nic[index].is_vlan,
                                            masscan->nic[index].vlan_id);
    if (masscan->nic[index].adapter == 0) {
        LOG(1, "if:%s:init: failed\n", ifname);
        return -1;
    }
    rawsock_ignore_transmits(masscan->nic[index].adapter, adapter_mac, ifname);
    


    /*
     * ROUTER MAC ADDRESS
     *
     * NOTE: this is one of the least understood aspects of the code. We must
     * send packets to the local router, which means the MAC address (not
     * IP address) of the router.
     *
     * Note: in order to ARP the router, we need to first enable the libpcap
     * code above.
     */
    memcpy(router_mac, masscan->nic[index].router_mac, 6);
    if (masscan->is_offline) {
        memcpy(router_mac, "\x66\x55\x44\x33\x22\x11", 6);
    } else if (memcmp(router_mac, "\0\0\0\0\0\0", 6) == 0) {
        unsigned router_ipv4 = masscan->nic[index].router_ip;
        int err = 0;


        LOG(1, "if:%s: looking for default gateway\n", ifname);
        if (router_ipv4 == 0)
            err = rawsock_get_default_gateway(ifname, &router_ipv4);
        if (err == 0) {
            LOG(2, "if:%s: router-ip=%u.%u.%u.%u\n",
                ifname,
                (router_ipv4>>24)&0xFF,
                (router_ipv4>>16)&0xFF,
                (router_ipv4>> 8)&0xFF,
                (router_ipv4>> 0)&0xFF
                );

            LOG(1, "if:%s:arp: resolving IPv4 address\n", ifname);
            arp_resolve_sync(
                    masscan->nic[index].adapter,
                    adapter_ip,
                    adapter_mac,
                    router_ipv4,
                    router_mac);

        }
    }
    LOG(2, "if:%s: router-mac=%02x-%02x-%02x-%02x-%02x-%02x\n",
        ifname,
        router_mac[0],
        router_mac[1],
        router_mac[2],
        router_mac[3],
        router_mac[4],
        router_mac[5]
        );
    if (memcmp(router_mac, "\0\0\0\0\0\0", 6) == 0) {
        LOG(0, "FAIL: failed to detect router for interface: \"%s\"\n", ifname);
        LOG(0, " [hint] try something like \"--router-mac 66-55-44-33-22-11\" to specify router\n");
        LOG(0, " [hint] try something like \"--interface eth0\" to change interface\n");
        return -1;
    }


    LOG(1, "if:%s: initialization done.\n", ifname);
    return 0;
}