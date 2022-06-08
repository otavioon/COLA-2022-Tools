#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_2__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  uint8_t ;
typedef  int u_int ;
struct scb_platform_data {int dummy; } ;
struct scb_data {int numscbs; int scbs_left; int sgs_left; int sense_left; int /*<<< orphan*/  sense_dmat; int /*<<< orphan*/  sense_maps; int /*<<< orphan*/  sg_dmat; int /*<<< orphan*/  sg_maps; int /*<<< orphan*/  hscb_dmat; int /*<<< orphan*/  hscb_maps; } ;
struct scb {TYPE_1__* col_scb; struct hardware_scb* hscb; int /*<<< orphan*/  flags; struct ahd_softc* ahd_softc; void* sg_list_busaddr; void* sense_busaddr; int /*<<< orphan*/ * sense_data; int /*<<< orphan*/ * sg_list; struct scb* sense_map; struct scb* sg_map; struct scb* hscb_map; struct scb_platform_data* platform_data; void* physaddr; int /*<<< orphan*/ * vaddr; int /*<<< orphan*/  dmamap; } ;
struct map_node {TYPE_1__* col_scb; struct hardware_scb* hscb; int /*<<< orphan*/  flags; struct ahd_softc* ahd_softc; void* sg_list_busaddr; void* sense_busaddr; int /*<<< orphan*/ * sense_data; int /*<<< orphan*/ * sg_list; struct map_node* sense_map; struct map_node* sg_map; struct map_node* hscb_map; struct scb_platform_data* platform_data; void* physaddr; int /*<<< orphan*/ * vaddr; int /*<<< orphan*/  dmamap; } ;
struct hardware_scb {int /*<<< orphan*/  tag; int /*<<< orphan*/  hscb_busaddr; } ;
struct ahd_softc {int flags; struct scb_data scb_data; } ;
struct ahd_dma_seg {int dummy; } ;
struct ahd_dma64_seg {int dummy; } ;
typedef  void* dma_addr_t ;
struct TYPE_2__ {struct scb* col_scb; } ;

/* Variables and functions */
 int AHD_64BIT_ADDRESSING ; 
 int AHD_SCB_MAX_ALLOC ; 
 int AHD_SENSE_BUFSIZE ; 
 int AHD_SHOW_MEMORY ; 
 int /*<<< orphan*/  BUS_DMA_NOWAIT ; 
 int /*<<< orphan*/  GFP_ATOMIC ; 
 int PAGE_SIZE ; 
 int /*<<< orphan*/  SCB_FLAG_NONE ; 
 struct scb* SLIST_FIRST (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  SLIST_INSERT_HEAD (int /*<<< orphan*/ *,struct scb*,int /*<<< orphan*/ ) ; 
 int ahd_debug ; 
 int /*<<< orphan*/  ahd_dmamap_cb ; 
 int /*<<< orphan*/  ahd_dmamap_load (struct ahd_softc*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ *,int,int /*<<< orphan*/ ,void**,int /*<<< orphan*/ ) ; 
 scalar_t__ ahd_dmamem_alloc (struct ahd_softc*,int /*<<< orphan*/ ,void**,int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 TYPE_1__* ahd_find_scb_by_tag (struct ahd_softc*,int) ; 
 int /*<<< orphan*/  ahd_free_scb (struct ahd_softc*,struct scb*) ; 
 int /*<<< orphan*/  ahd_htole16 (int) ; 
 int /*<<< orphan*/  ahd_htole32 (void*) ; 
 int ahd_sglist_allocsize (struct ahd_softc*) ; 
 int ahd_sglist_size (struct ahd_softc*) ; 
 int /*<<< orphan*/  kfree (struct scb*) ; 
 void* kmalloc (int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  links ; 
 int /*<<< orphan*/  memset (struct hardware_scb*,int /*<<< orphan*/ ,int) ; 
 int min (int,int) ; 
 int /*<<< orphan*/  printk (char*) ; 

__attribute__((used)) static void
ahd_alloc_scbs(struct ahd_softc *ahd)
{
	struct scb_data *scb_data;
	struct scb	*next_scb;
	struct hardware_scb *hscb;
	struct map_node *hscb_map;
	struct map_node *sg_map;
	struct map_node *sense_map;
	uint8_t		*segs;
	uint8_t		*sense_data;
	dma_addr_t	 hscb_busaddr;
	dma_addr_t	 sg_busaddr;
	dma_addr_t	 sense_busaddr;
	int		 newcount;
	int		 i;

	scb_data = &ahd->scb_data;
	if (scb_data->numscbs >= AHD_SCB_MAX_ALLOC)
		/* Can't allocate any more */
		return;

	if (scb_data->scbs_left != 0) {
		int offset;

		offset = (PAGE_SIZE / sizeof(*hscb)) - scb_data->scbs_left;
		hscb_map = SLIST_FIRST(&scb_data->hscb_maps);
		hscb = &((struct hardware_scb *)hscb_map->vaddr)[offset];
		hscb_busaddr = hscb_map->physaddr + (offset * sizeof(*hscb));
	} else {
		hscb_map = kmalloc(sizeof(*hscb_map), GFP_ATOMIC);

		if (hscb_map == NULL)
			return;

		/* Allocate the next batch of hardware SCBs */
		if (ahd_dmamem_alloc(ahd, scb_data->hscb_dmat,
				     (void **)&hscb_map->vaddr,
				     BUS_DMA_NOWAIT, &hscb_map->dmamap) != 0) {
			kfree(hscb_map);
			return;
		}

		SLIST_INSERT_HEAD(&scb_data->hscb_maps, hscb_map, links);

		ahd_dmamap_load(ahd, scb_data->hscb_dmat, hscb_map->dmamap,
				hscb_map->vaddr, PAGE_SIZE, ahd_dmamap_cb,
				&hscb_map->physaddr, /*flags*/0);

		hscb = (struct hardware_scb *)hscb_map->vaddr;
		hscb_busaddr = hscb_map->physaddr;
		scb_data->scbs_left = PAGE_SIZE / sizeof(*hscb);
	}

	if (scb_data->sgs_left != 0) {
		int offset;

		offset = ((ahd_sglist_allocsize(ahd) / ahd_sglist_size(ahd))
		       - scb_data->sgs_left) * ahd_sglist_size(ahd);
		sg_map = SLIST_FIRST(&scb_data->sg_maps);
		segs = sg_map->vaddr + offset;
		sg_busaddr = sg_map->physaddr + offset;
	} else {
		sg_map = kmalloc(sizeof(*sg_map), GFP_ATOMIC);

		if (sg_map == NULL)
			return;

		/* Allocate the next batch of S/G lists */
		if (ahd_dmamem_alloc(ahd, scb_data->sg_dmat,
				     (void **)&sg_map->vaddr,
				     BUS_DMA_NOWAIT, &sg_map->dmamap) != 0) {
			kfree(sg_map);
			return;
		}

		SLIST_INSERT_HEAD(&scb_data->sg_maps, sg_map, links);

		ahd_dmamap_load(ahd, scb_data->sg_dmat, sg_map->dmamap,
				sg_map->vaddr, ahd_sglist_allocsize(ahd),
				ahd_dmamap_cb, &sg_map->physaddr, /*flags*/0);

		segs = sg_map->vaddr;
		sg_busaddr = sg_map->physaddr;
		scb_data->sgs_left =
		    ahd_sglist_allocsize(ahd) / ahd_sglist_size(ahd);
#ifdef AHD_DEBUG
		if (ahd_debug & AHD_SHOW_MEMORY)
			printk("Mapped SG data\n");
#endif
	}

	if (scb_data->sense_left != 0) {
		int offset;

		offset = PAGE_SIZE - (AHD_SENSE_BUFSIZE * scb_data->sense_left);
		sense_map = SLIST_FIRST(&scb_data->sense_maps);
		sense_data = sense_map->vaddr + offset;
		sense_busaddr = sense_map->physaddr + offset;
	} else {
		sense_map = kmalloc(sizeof(*sense_map), GFP_ATOMIC);

		if (sense_map == NULL)
			return;

		/* Allocate the next batch of sense buffers */
		if (ahd_dmamem_alloc(ahd, scb_data->sense_dmat,
				     (void **)&sense_map->vaddr,
				     BUS_DMA_NOWAIT, &sense_map->dmamap) != 0) {
			kfree(sense_map);
			return;
		}

		SLIST_INSERT_HEAD(&scb_data->sense_maps, sense_map, links);

		ahd_dmamap_load(ahd, scb_data->sense_dmat, sense_map->dmamap,
				sense_map->vaddr, PAGE_SIZE, ahd_dmamap_cb,
				&sense_map->physaddr, /*flags*/0);

		sense_data = sense_map->vaddr;
		sense_busaddr = sense_map->physaddr;
		scb_data->sense_left = PAGE_SIZE / AHD_SENSE_BUFSIZE;
#ifdef AHD_DEBUG
		if (ahd_debug & AHD_SHOW_MEMORY)
			printk("Mapped sense data\n");
#endif
	}

	newcount = min(scb_data->sense_left, scb_data->scbs_left);
	newcount = min(newcount, scb_data->sgs_left);
	newcount = min(newcount, (AHD_SCB_MAX_ALLOC - scb_data->numscbs));
	for (i = 0; i < newcount; i++) {
		struct scb_platform_data *pdata;
		u_int col_tag;

		next_scb = kmalloc(sizeof(*next_scb), GFP_ATOMIC);
		if (next_scb == NULL)
			break;

		pdata = kmalloc(sizeof(*pdata), GFP_ATOMIC);
		if (pdata == NULL) {
			kfree(next_scb);
			break;
		}
		next_scb->platform_data = pdata;
		next_scb->hscb_map = hscb_map;
		next_scb->sg_map = sg_map;
		next_scb->sense_map = sense_map;
		next_scb->sg_list = segs;
		next_scb->sense_data = sense_data;
		next_scb->sense_busaddr = sense_busaddr;
		memset(hscb, 0, sizeof(*hscb));
		next_scb->hscb = hscb;
		hscb->hscb_busaddr = ahd_htole32(hscb_busaddr);

		/*
		 * The sequencer always starts with the second entry.
		 * The first entry is embedded in the scb.
		 */
		next_scb->sg_list_busaddr = sg_busaddr;
		if ((ahd->flags & AHD_64BIT_ADDRESSING) != 0)
			next_scb->sg_list_busaddr
			    += sizeof(struct ahd_dma64_seg);
		else
			next_scb->sg_list_busaddr += sizeof(struct ahd_dma_seg);
		next_scb->ahd_softc = ahd;
		next_scb->flags = SCB_FLAG_NONE;
		next_scb->hscb->tag = ahd_htole16(scb_data->numscbs);
		col_tag = scb_data->numscbs ^ 0x100;
		next_scb->col_scb = ahd_find_scb_by_tag(ahd, col_tag);
		if (next_scb->col_scb != NULL)
			next_scb->col_scb->col_scb = next_scb;
		ahd_free_scb(ahd, next_scb);
		hscb++;
		hscb_busaddr += sizeof(*hscb);
		segs += ahd_sglist_size(ahd);
		sg_busaddr += ahd_sglist_size(ahd);
		sense_data += AHD_SENSE_BUFSIZE;
		sense_busaddr += AHD_SENSE_BUFSIZE;
		scb_data->numscbs++;
		scb_data->sense_left--;
		scb_data->scbs_left--;
		scb_data->sgs_left--;
	}
}