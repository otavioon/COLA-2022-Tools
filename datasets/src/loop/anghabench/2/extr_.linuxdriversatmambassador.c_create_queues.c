#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef int scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_28__   TYPE_6__ ;
typedef  struct TYPE_27__   TYPE_5__ ;
typedef  struct TYPE_26__   TYPE_4__ ;
typedef  struct TYPE_25__   TYPE_3__ ;
typedef  struct TYPE_24__   TYPE_2__ ;
typedef  struct TYPE_23__   TYPE_1__ ;
typedef  struct TYPE_22__   TYPE_14__ ;
typedef  struct TYPE_21__   TYPE_12__ ;
typedef  struct TYPE_20__   TYPE_11__ ;

/* Type definitions */
struct TYPE_25__ {TYPE_6__* limit; TYPE_6__* ptr; TYPE_6__* start; } ;
struct TYPE_24__ {TYPE_6__* limit; TYPE_6__* ptr; TYPE_6__* start; } ;
struct TYPE_20__ {unsigned int maximum; TYPE_3__ out; TYPE_2__ in; scalar_t__ filled; scalar_t__ high; scalar_t__ pending; } ;
struct TYPE_23__ {TYPE_6__* limit; TYPE_6__* out; TYPE_6__* in; TYPE_6__* start; } ;
struct TYPE_22__ {unsigned int maximum; TYPE_1__ ptrs; scalar_t__ high; scalar_t__ pending; } ;
struct TYPE_28__ {TYPE_12__* rxq; TYPE_11__ txq; TYPE_14__ cq; } ;
typedef  TYPE_6__ tx_out ;
typedef  TYPE_6__ tx_in ;
typedef  TYPE_6__ rx_out ;
typedef  TYPE_6__ rx_in ;
typedef  TYPE_6__ command ;
typedef  TYPE_11__ amb_txq ;
struct TYPE_27__ {TYPE_6__* limit; TYPE_6__* ptr; TYPE_6__* start; } ;
struct TYPE_26__ {TYPE_6__* limit; TYPE_6__* ptr; TYPE_6__* start; } ;
struct TYPE_21__ {unsigned int buffer_size; unsigned int low; unsigned int maximum; TYPE_5__ out; TYPE_4__ in; scalar_t__ emptied; scalar_t__ pending; scalar_t__ buffers_wanted; } ;
typedef  TYPE_12__ amb_rxq ;
typedef  TYPE_6__ amb_dev ;
typedef  TYPE_14__ amb_cq ;

/* Variables and functions */
 int /*<<< orphan*/  DBG_CMD ; 
 int /*<<< orphan*/  DBG_FLOW ; 
 int /*<<< orphan*/  DBG_INIT ; 
 int /*<<< orphan*/  DBG_RX ; 
 int /*<<< orphan*/  DBG_TX ; 
 int ENOMEM ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int /*<<< orphan*/  KERN_ERR ; 
 unsigned char NUM_RX_POOLS ; 
 int /*<<< orphan*/  PRINTD (int /*<<< orphan*/ ,char*,TYPE_6__*,...) ; 
 int /*<<< orphan*/  PRINTK (int /*<<< orphan*/ ,char*,...) ; 
 scalar_t__ check_area (TYPE_6__*,size_t) ; 
 int /*<<< orphan*/  kfree (TYPE_6__*) ; 
 TYPE_6__* kmalloc (size_t,int /*<<< orphan*/ ) ; 

__attribute__((used)) static int create_queues(amb_dev *dev, unsigned int cmds, unsigned int txs,
			 unsigned int *rxs, unsigned int *rx_buffer_sizes)
{
  unsigned char pool;
  size_t total = 0;
  void * memory;
  void * limit;
  
  PRINTD (DBG_FLOW, "create_queues %p", dev);
  
  total += cmds * sizeof(command);
  
  total += txs * (sizeof(tx_in) + sizeof(tx_out));
  
  for (pool = 0; pool < NUM_RX_POOLS; ++pool)
    total += rxs[pool] * (sizeof(rx_in) + sizeof(rx_out));
  
  memory = kmalloc (total, GFP_KERNEL);
  if (!memory) {
    PRINTK (KERN_ERR, "could not allocate queues");
    return -ENOMEM;
  }
  if (check_area (memory, total)) {
    PRINTK (KERN_ERR, "queues allocated in nasty area");
    kfree (memory);
    return -ENOMEM;
  }
  
  limit = memory + total;
  PRINTD (DBG_INIT, "queues from %p to %p", memory, limit);
  
  PRINTD (DBG_CMD, "command queue at %p", memory);
  
  {
    command * cmd = memory;
    amb_cq * cq = &dev->cq;
    
    cq->pending = 0;
    cq->high = 0;
    cq->maximum = cmds - 1;
    
    cq->ptrs.start = cmd;
    cq->ptrs.in = cmd;
    cq->ptrs.out = cmd;
    cq->ptrs.limit = cmd + cmds;
    
    memory = cq->ptrs.limit;
  }
  
  PRINTD (DBG_TX, "TX queue pair at %p", memory);
  
  {
    tx_in * in = memory;
    tx_out * out;
    amb_txq * txq = &dev->txq;
    
    txq->pending = 0;
    txq->high = 0;
    txq->filled = 0;
    txq->maximum = txs - 1;
    
    txq->in.start = in;
    txq->in.ptr = in;
    txq->in.limit = in + txs;
    
    memory = txq->in.limit;
    out = memory;
    
    txq->out.start = out;
    txq->out.ptr = out;
    txq->out.limit = out + txs;
    
    memory = txq->out.limit;
  }
  
  PRINTD (DBG_RX, "RX queue pairs at %p", memory);
  
  for (pool = 0; pool < NUM_RX_POOLS; ++pool) {
    rx_in * in = memory;
    rx_out * out;
    amb_rxq * rxq = &dev->rxq[pool];
    
    rxq->buffer_size = rx_buffer_sizes[pool];
    rxq->buffers_wanted = 0;
    
    rxq->pending = 0;
    rxq->low = rxs[pool] - 1;
    rxq->emptied = 0;
    rxq->maximum = rxs[pool] - 1;
    
    rxq->in.start = in;
    rxq->in.ptr = in;
    rxq->in.limit = in + rxs[pool];
    
    memory = rxq->in.limit;
    out = memory;
    
    rxq->out.start = out;
    rxq->out.ptr = out;
    rxq->out.limit = out + rxs[pool];
    
    memory = rxq->out.limit;
  }
  
  if (memory == limit) {
    return 0;
  } else {
    PRINTK (KERN_ERR, "bad queue alloc %p != %p (tell maintainer)", memory, limit);
    kfree (limit - total);
    return -ENOMEM;
  }
  
}