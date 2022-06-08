#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef int scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_10__   TYPE_5__ ;
typedef  struct TYPE_9__   TYPE_4__ ;
typedef  struct TYPE_8__   TYPE_3__ ;
typedef  struct TYPE_7__   TYPE_2__ ;
typedef  struct TYPE_6__   TYPE_1__ ;

/* Type definitions */
struct ath10k_tlv_dump_data {int /*<<< orphan*/ * tlv_data; void* tlv_len; void* type; } ;
struct TYPE_9__ {int /*<<< orphan*/  tv_nsec; int /*<<< orphan*/  tv_sec; } ;
struct ath10k_fw_crash_data {int ramdump_buf_len; int /*<<< orphan*/ * ramdump_buf; int /*<<< orphan*/ * ce_crash_data; int /*<<< orphan*/  registers; TYPE_4__ timestamp; int /*<<< orphan*/  guid; } ;
struct ath10k_dump_file_data {void* tv_nsec; void* tv_sec; int /*<<< orphan*/  kernel_ver; scalar_t__ kernel_ver_code; int /*<<< orphan*/  fw_ver; void* num_rf_chains; void* vht_cap_info; void* ht_cap_info; void* hw_max_tx_power; void* hw_min_tx_power; void* phy_capability; void* fw_version_build; void* fw_version_release; void* fw_version_minor; void* fw_version_major; void* target_version; void* bus_type; void* chip_id; int /*<<< orphan*/  guid; void* version; void* len; int /*<<< orphan*/  df_magic; } ;
struct ath10k_ce_crash_hdr {int /*<<< orphan*/ * entries; int /*<<< orphan*/  reserved; void* ce_count; } ;
struct TYPE_6__ {struct ath10k_fw_crash_data* fw_crash_data; } ;
struct ath10k {int chip_id; int target_version; int fw_version_major; int fw_version_minor; int fw_version_release; int fw_version_build; int phy_capability; int hw_min_tx_power; int hw_max_tx_power; int ht_cap_info; int vht_cap_info; int num_rf_chains; int /*<<< orphan*/  data_lock; TYPE_3__* hw; TYPE_1__ coredump; } ;
struct TYPE_10__ {char* release; } ;
struct TYPE_8__ {TYPE_2__* wiphy; } ;
struct TYPE_7__ {char* fw_version; } ;

/* Variables and functions */
 int ATH10K_FW_CRASH_DUMP_CE_DATA ; 
 int ATH10K_FW_CRASH_DUMP_RAM_DATA ; 
 int ATH10K_FW_CRASH_DUMP_REGISTERS ; 
 int ATH10K_FW_CRASH_DUMP_VERSION ; 
 int CE_COUNT ; 
 int /*<<< orphan*/  ath10k_coredump_mask ; 
 void* cpu_to_le32 (int) ; 
 void* cpu_to_le64 (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  guid_copy (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 TYPE_5__* init_utsname () ; 
 int /*<<< orphan*/  memcpy (int /*<<< orphan*/ *,int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/  memset (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  spin_lock_bh (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  spin_unlock_bh (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  strlcpy (int /*<<< orphan*/ ,char*,int) ; 
 scalar_t__ test_bit (int,int /*<<< orphan*/ *) ; 
 unsigned char* vzalloc (size_t) ; 

__attribute__((used)) static struct ath10k_dump_file_data *ath10k_coredump_build(struct ath10k *ar)
{
	struct ath10k_fw_crash_data *crash_data = ar->coredump.fw_crash_data;
	struct ath10k_ce_crash_hdr *ce_hdr;
	struct ath10k_dump_file_data *dump_data;
	struct ath10k_tlv_dump_data *dump_tlv;
	size_t hdr_len = sizeof(*dump_data);
	size_t len, sofar = 0;
	unsigned char *buf;

	len = hdr_len;

	if (test_bit(ATH10K_FW_CRASH_DUMP_REGISTERS, &ath10k_coredump_mask))
		len += sizeof(*dump_tlv) + sizeof(crash_data->registers);

	if (test_bit(ATH10K_FW_CRASH_DUMP_CE_DATA, &ath10k_coredump_mask))
		len += sizeof(*dump_tlv) + sizeof(*ce_hdr) +
			CE_COUNT * sizeof(ce_hdr->entries[0]);

	if (test_bit(ATH10K_FW_CRASH_DUMP_RAM_DATA, &ath10k_coredump_mask))
		len += sizeof(*dump_tlv) + crash_data->ramdump_buf_len;

	sofar += hdr_len;

	/* This is going to get big when we start dumping FW RAM and such,
	 * so go ahead and use vmalloc.
	 */
	buf = vzalloc(len);
	if (!buf)
		return NULL;

	spin_lock_bh(&ar->data_lock);

	dump_data = (struct ath10k_dump_file_data *)(buf);
	strlcpy(dump_data->df_magic, "ATH10K-FW-DUMP",
		sizeof(dump_data->df_magic));
	dump_data->len = cpu_to_le32(len);

	dump_data->version = cpu_to_le32(ATH10K_FW_CRASH_DUMP_VERSION);

	guid_copy(&dump_data->guid, &crash_data->guid);
	dump_data->chip_id = cpu_to_le32(ar->chip_id);
	dump_data->bus_type = cpu_to_le32(0);
	dump_data->target_version = cpu_to_le32(ar->target_version);
	dump_data->fw_version_major = cpu_to_le32(ar->fw_version_major);
	dump_data->fw_version_minor = cpu_to_le32(ar->fw_version_minor);
	dump_data->fw_version_release = cpu_to_le32(ar->fw_version_release);
	dump_data->fw_version_build = cpu_to_le32(ar->fw_version_build);
	dump_data->phy_capability = cpu_to_le32(ar->phy_capability);
	dump_data->hw_min_tx_power = cpu_to_le32(ar->hw_min_tx_power);
	dump_data->hw_max_tx_power = cpu_to_le32(ar->hw_max_tx_power);
	dump_data->ht_cap_info = cpu_to_le32(ar->ht_cap_info);
	dump_data->vht_cap_info = cpu_to_le32(ar->vht_cap_info);
	dump_data->num_rf_chains = cpu_to_le32(ar->num_rf_chains);

	strlcpy(dump_data->fw_ver, ar->hw->wiphy->fw_version,
		sizeof(dump_data->fw_ver));

	dump_data->kernel_ver_code = 0;
	strlcpy(dump_data->kernel_ver, init_utsname()->release,
		sizeof(dump_data->kernel_ver));

	dump_data->tv_sec = cpu_to_le64(crash_data->timestamp.tv_sec);
	dump_data->tv_nsec = cpu_to_le64(crash_data->timestamp.tv_nsec);

	if (test_bit(ATH10K_FW_CRASH_DUMP_REGISTERS, &ath10k_coredump_mask)) {
		dump_tlv = (struct ath10k_tlv_dump_data *)(buf + sofar);
		dump_tlv->type = cpu_to_le32(ATH10K_FW_CRASH_DUMP_REGISTERS);
		dump_tlv->tlv_len = cpu_to_le32(sizeof(crash_data->registers));
		memcpy(dump_tlv->tlv_data, &crash_data->registers,
		       sizeof(crash_data->registers));
		sofar += sizeof(*dump_tlv) + sizeof(crash_data->registers);
	}

	if (test_bit(ATH10K_FW_CRASH_DUMP_CE_DATA, &ath10k_coredump_mask)) {
		dump_tlv = (struct ath10k_tlv_dump_data *)(buf + sofar);
		dump_tlv->type = cpu_to_le32(ATH10K_FW_CRASH_DUMP_CE_DATA);
		dump_tlv->tlv_len = cpu_to_le32(sizeof(*ce_hdr) +
						CE_COUNT * sizeof(ce_hdr->entries[0]));
		ce_hdr = (struct ath10k_ce_crash_hdr *)(dump_tlv->tlv_data);
		ce_hdr->ce_count = cpu_to_le32(CE_COUNT);
		memset(ce_hdr->reserved, 0, sizeof(ce_hdr->reserved));
		memcpy(ce_hdr->entries, crash_data->ce_crash_data,
		       CE_COUNT * sizeof(ce_hdr->entries[0]));
		sofar += sizeof(*dump_tlv) + sizeof(*ce_hdr) +
			CE_COUNT * sizeof(ce_hdr->entries[0]);
	}

	/* Gather ram dump */
	if (test_bit(ATH10K_FW_CRASH_DUMP_RAM_DATA, &ath10k_coredump_mask)) {
		dump_tlv = (struct ath10k_tlv_dump_data *)(buf + sofar);
		dump_tlv->type = cpu_to_le32(ATH10K_FW_CRASH_DUMP_RAM_DATA);
		dump_tlv->tlv_len = cpu_to_le32(crash_data->ramdump_buf_len);
		memcpy(dump_tlv->tlv_data, crash_data->ramdump_buf,
		       crash_data->ramdump_buf_len);
		sofar += sizeof(*dump_tlv) + crash_data->ramdump_buf_len;
	}

	spin_unlock_bh(&ar->data_lock);

	return dump_data;
}