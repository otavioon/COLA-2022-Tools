#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef int scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */

/* Type definitions */
typedef  int uint64_t ;
typedef  int uint32_t ;
typedef  int u_int ;
struct xsave_limits {unsigned int xcr0_allowed; unsigned int xsave_max_size; int /*<<< orphan*/  xsave_enabled; } ;
struct vm {int dummy; } ;
typedef  enum x2apic_state { ____Placeholder_x2apic_state } x2apic_state ;

/* Variables and functions */
 int /*<<< orphan*/  AMDID2_IBS ; 
 int /*<<< orphan*/  AMDID2_NODE_ID ; 
 int /*<<< orphan*/  AMDID2_OSVW ; 
 int /*<<< orphan*/  AMDID2_PCXC ; 
 int /*<<< orphan*/  AMDID2_PNXC ; 
 int /*<<< orphan*/  AMDID2_PTSCEL2I ; 
 int AMDID2_SVM ; 
 int AMDID2_TOPOLOGY ; 
 int /*<<< orphan*/  AMDID_RDTSCP ; 
 unsigned int AMDPM_TSC_INVARIANT ; 
 int CPUID2_EST ; 
 int /*<<< orphan*/  CPUID2_HV ; 
 int /*<<< orphan*/  CPUID2_MON ; 
 int /*<<< orphan*/  CPUID2_OSXSAVE ; 
 int /*<<< orphan*/  CPUID2_PDCM ; 
 int /*<<< orphan*/  CPUID2_SMX ; 
 int CPUID2_TM2 ; 
 int /*<<< orphan*/  CPUID2_TSCDLT ; 
 int CPUID2_VMX ; 
 int /*<<< orphan*/  CPUID2_X2APIC ; 
 int /*<<< orphan*/  CPUID2_XSAVE ; 
#define  CPUID_0000_0000 145 
#define  CPUID_0000_0001 144 
 unsigned int CPUID_0000_0001_APICID_SHIFT ; 
#define  CPUID_0000_0002 143 
#define  CPUID_0000_0003 142 
#define  CPUID_0000_0004 141 
#define  CPUID_0000_0006 140 
#define  CPUID_0000_0007 139 
#define  CPUID_0000_000A 138 
#define  CPUID_0000_000B 137 
#define  CPUID_0000_000D 136 
#define  CPUID_8000_0000 135 
#define  CPUID_8000_0001 134 
#define  CPUID_8000_0002 133 
#define  CPUID_8000_0003 132 
#define  CPUID_8000_0004 131 
#define  CPUID_8000_0006 130 
#define  CPUID_8000_0007 129 
#define  CPUID_8000_0008 128 
 int CPUID_ACPI ; 
 int /*<<< orphan*/  CPUID_DS ; 
 unsigned int CPUID_EXTSTATE_XSAVEOPT ; 
 int /*<<< orphan*/  CPUID_HTT ; 
 int /*<<< orphan*/  CPUID_HTT_CORES ; 
 int /*<<< orphan*/  CPUID_LOCAL_APIC_ID ; 
 int CPUID_MCA ; 
 int CPUID_MCE ; 
 int CPUID_MTRR ; 
 unsigned int CPUID_STDEXT_AVX2 ; 
 unsigned int CPUID_STDEXT_AVX512CD ; 
 unsigned int CPUID_STDEXT_AVX512ER ; 
 unsigned int CPUID_STDEXT_AVX512F ; 
 unsigned int CPUID_STDEXT_AVX512PF ; 
 unsigned int CPUID_STDEXT_BMI1 ; 
 unsigned int CPUID_STDEXT_BMI2 ; 
 unsigned int CPUID_STDEXT_ERMS ; 
 unsigned int CPUID_STDEXT_FSGSBASE ; 
 unsigned int CPUID_STDEXT_HLE ; 
 unsigned int CPUID_STDEXT_RTM ; 
 int CPUID_TM ; 
 int CPUID_TYPE_CORE ; 
 int CPUID_TYPE_SMT ; 
 int CPUID_VM_HIGH ; 
 unsigned int CPUTPM1_ARAT ; 
 int CR4_XSAVE ; 
 int /*<<< orphan*/  VCPU_CTR2 (struct vm*,int,char*,int,int) ; 
 int /*<<< orphan*/  VM_REG_GUEST_CR4 ; 
 int /*<<< orphan*/  X2APIC_DISABLED ; 
 int /*<<< orphan*/  atomic_add_long (int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/  bcopy (int /*<<< orphan*/ ,unsigned int*,int) ; 
 int /*<<< orphan*/  bhyve_id ; 
 int /*<<< orphan*/  bhyve_xcpuids ; 
 unsigned int cores_per_package ; 
 int /*<<< orphan*/  cpuid_count (int,int,unsigned int*) ; 
 int /*<<< orphan*/  cpuid_leaf_b ; 
 int /*<<< orphan*/  do_cpuid (int,unsigned int*) ; 
 int log2 (unsigned int) ; 
 unsigned int threads_per_core ; 
 int vm_get_register (struct vm*,int,int /*<<< orphan*/ ,int*) ; 
 int vm_get_x2apic_state (struct vm*,int,int*) ; 
 struct xsave_limits* vmm_get_xsave_limits () ; 
 int /*<<< orphan*/  xhyve_abort (char*,int) ; 

int
x86_emulate_cpuid(struct vm *vm, int vcpu_id,
		  uint32_t *eax, uint32_t *ebx, uint32_t *ecx, uint32_t *edx)
{
	const struct xsave_limits *limits;
	uint64_t cr4;
	int error, level, width, x2apic_id;
	unsigned int func, regs[4], logical_cpus;
	u_int cpu_feature, amd_feature, amd_feature2, cpu_high, cpu_exthigh;
	u_int tsc_is_invariant, smp_tsc;
	enum x2apic_state x2apic_state;

	VCPU_CTR2(vm, vcpu_id, "cpuid %#x,%#x", *eax, *ecx);

	tsc_is_invariant = 1;
	smp_tsc = 1;
	do_cpuid(0, regs);
	cpu_high = regs[0];
	do_cpuid(1, regs);
	cpu_feature = regs[3];
	do_cpuid(0x80000000, regs);
	cpu_exthigh = regs[0];
	do_cpuid(0x80000001, regs);
	amd_feature = regs[3] & ~(cpu_feature & 0x0183f3ff);
	amd_feature2 = regs[2];

	/*
	 * Requests for invalid CPUID levels should map to the highest
	 * available level instead.
	 */
	if (cpu_exthigh != 0 && *eax >= 0x80000000) {
		if (*eax > cpu_exthigh)
			*eax = cpu_exthigh;
	} else if (*eax >= 0x40000000) {
		if (*eax > CPUID_VM_HIGH)
			*eax = CPUID_VM_HIGH;
	} else if (*eax > cpu_high) {
		*eax = cpu_high;
	}

	func = *eax;

	/*
	 * In general the approach used for CPU topology is to
	 * advertise a flat topology where all CPUs are packages with
	 * no multi-core or SMT.
	 */
	switch (func) {
		/*
		 * Pass these through to the guest
		 */
		case CPUID_0000_0000:
		case CPUID_0000_0002:
		case CPUID_0000_0003:
		case CPUID_8000_0000:
		case CPUID_8000_0002:
		case CPUID_8000_0003:
		case CPUID_8000_0004:
		case CPUID_8000_0006:
			cpuid_count(*eax, *ecx, regs);
			break;
		case CPUID_8000_0008:
			cpuid_count(*eax, *ecx, regs);
			break;
		case CPUID_8000_0001:
			cpuid_count(*eax, *ecx, regs);

			/*
			 * Hide SVM and Topology Extension features from guest.
			 */
			regs[2] &= ~((unsigned) (AMDID2_SVM | AMDID2_TOPOLOGY));

			/*
			 * Don't advertise extended performance counter MSRs
			 * to the guest.
			 */
			regs[2] &= ~((unsigned) AMDID2_PCXC);
			regs[2] &= ~((unsigned) AMDID2_PNXC);
			regs[2] &= ~((unsigned) AMDID2_PTSCEL2I);

			/*
			 * Don't advertise Instruction Based Sampling feature.
			 */
			regs[2] &= ~((unsigned) AMDID2_IBS);

			/* NodeID MSR not available */
			regs[2] &= ~((unsigned) AMDID2_NODE_ID);

			/* Don't advertise the OS visible workaround feature */
			regs[2] &= ~((unsigned) AMDID2_OSVW);

			/*
			 * Hide rdtscp/ia32_tsc_aux until we know how
			 * to deal with them.
			 */
			regs[3] &= ~((unsigned) AMDID_RDTSCP);
			break;

		case CPUID_8000_0007:
			/*
			 * AMD uses this leaf to advertise the processor's
			 * power monitoring and RAS capabilities. These
			 * features are hardware-specific and exposing
			 * them to a guest doesn't make a lot of sense.
			 *
			 * Intel uses this leaf only to advertise the
			 * "Invariant TSC" feature with all other bits
			 * being reserved (set to zero).
			 */
			regs[0] = 0;
			regs[1] = 0;
			regs[2] = 0;
			regs[3] = 0;

			/*
			 * "Invariant TSC" can be advertised to the guest if:
			 * - host TSC frequency is invariant
			 * - host TSCs are synchronized across physical cpus
			 *
			 * XXX This still falls short because the vcpu
			 * can observe the TSC moving backwards as it
			 * migrates across physical cpus. But at least
			 * it should discourage the guest from using the
			 * TSC to keep track of time.
			 */
			if (tsc_is_invariant && smp_tsc)
				regs[3] |= AMDPM_TSC_INVARIANT;
			break;

		case CPUID_0000_0001:
			do_cpuid(1, regs);

			error = vm_get_x2apic_state(vm, vcpu_id, &x2apic_state);
			if (error) {
				xhyve_abort("x86_emulate_cpuid: error %d "
					"fetching x2apic state\n", error);
			}

			/*
			 * Override the APIC ID only in ebx
			 */
			regs[1] &= ~((unsigned) CPUID_LOCAL_APIC_ID);
			regs[1] |= (((unsigned) vcpu_id) << CPUID_0000_0001_APICID_SHIFT);

			/*
			 * Don't expose VMX, SpeedStep, TME or SMX capability.
			 * Advertise x2APIC capability and Hypervisor guest.
			 */
			regs[2] &= ~((unsigned) (CPUID2_VMX | CPUID2_EST | CPUID2_TM2));
			regs[2] &= ~((unsigned) CPUID2_SMX);

			regs[2] |= (unsigned) CPUID2_HV;

			if (x2apic_state != ((unsigned) X2APIC_DISABLED))
				regs[2] |= ((unsigned) CPUID2_X2APIC);
			else
				regs[2] &= ~((unsigned) CPUID2_X2APIC);

			/*
			 * Only advertise CPUID2_XSAVE in the guest if
			 * the host is using XSAVE.
			 */
			if (!(regs[2] & ((unsigned) CPUID2_OSXSAVE)))
				regs[2] &= ~((unsigned) CPUID2_XSAVE);

			/*
			 * If CPUID2_XSAVE is being advertised and the
			 * guest has set CR4_XSAVE, set
			 * CPUID2_OSXSAVE.
			 */
			regs[2] &= ~((unsigned) CPUID2_OSXSAVE);
			if (regs[2] & ((unsigned) CPUID2_XSAVE)) {
				error = vm_get_register(vm, vcpu_id, VM_REG_GUEST_CR4, &cr4);
				if (error)
					xhyve_abort("x86_emulate_cpuid: error %d "
					      "fetching %%cr4\n", error);
				if (cr4 & CR4_XSAVE)
					regs[2] |= ((unsigned) CPUID2_OSXSAVE);
			}

			/*
			 * Hide monitor/mwait until we know how to deal with
			 * these instructions.
			 */
			regs[2] &= ~((unsigned) CPUID2_MON);

                        /*
			 * Hide the performance and debug features.
			 */
			regs[2] &= ~((unsigned) CPUID2_PDCM);

			/*
			 * No TSC deadline support in the APIC yet
			 */
			regs[2] &= ~((unsigned) CPUID2_TSCDLT);

			/*
			 * Hide thermal monitoring
			 */
			regs[3] &= ~((unsigned) (CPUID_ACPI | CPUID_TM));

			/*
			 * Hide the debug store capability.
			 */
			regs[3] &= ~((unsigned) CPUID_DS);

			/*
			 * Advertise the Machine Check and MTRR capability.
			 *
			 * Some guest OSes (e.g. Windows) will not boot if
			 * these features are absent.
			 */
			regs[3] |= (unsigned) (CPUID_MCA | CPUID_MCE | CPUID_MTRR);

			logical_cpus = threads_per_core * cores_per_package;
			regs[1] &= ~((unsigned) CPUID_HTT_CORES);
			regs[1] |= (logical_cpus & 0xff) << 16;
			regs[3] |= (unsigned) CPUID_HTT;
			break;

		case CPUID_0000_0004:
			cpuid_count(*eax, *ecx, regs);

			if (regs[0] || regs[1] || regs[2] || regs[3]) {
				regs[0] &= 0x3ff;
				regs[0] |= (cores_per_package - 1) << 26;
				/*
				 * Cache topology:
				 * - L1 and L2 are shared only by the logical
				 *   processors in a single core.
				 * - L3 and above are shared by all logical
				 *   processors in the package.
				 */
				logical_cpus = threads_per_core;
				level = (regs[0] >> 5) & 0x7;
				if (level >= 3)
					logical_cpus *= cores_per_package;
				regs[0] |= (logical_cpus - 1) << 14;
			}
			break;

		case CPUID_0000_0007:
			regs[0] = 0;
			regs[1] = 0;
			regs[2] = 0;
			regs[3] = 0;

			/* leaf 0 */
			if (*ecx == 0) {
				cpuid_count(*eax, *ecx, regs);

				/* Only leaf 0 is supported */
				regs[0] = 0;

				/*
				 * Expose known-safe features.
				 */
				regs[1] &= (CPUID_STDEXT_FSGSBASE |
				    CPUID_STDEXT_BMI1 | CPUID_STDEXT_HLE |
				    CPUID_STDEXT_AVX2 | CPUID_STDEXT_BMI2 |
				    CPUID_STDEXT_ERMS | CPUID_STDEXT_RTM |
				    CPUID_STDEXT_AVX512F |
				    CPUID_STDEXT_AVX512PF |
				    CPUID_STDEXT_AVX512ER |
				    CPUID_STDEXT_AVX512CD);
				regs[2] = 0;
				regs[3] = 0;
				/* FIXME */
				// regs[1] |= CPUID_STDEXT_INVPCID;
			}
			break;

		case CPUID_0000_0006:
			regs[0] = CPUTPM1_ARAT;
			regs[1] = 0;
			regs[2] = 0;
			regs[3] = 0;
			break;

		case CPUID_0000_000A:
			/*
			 * Handle the access, but report 0 for
			 * all options
			 */
			regs[0] = 0;
			regs[1] = 0;
			regs[2] = 0;
			regs[3] = 0;
			break;

		case CPUID_0000_000B:
			/*
			 * Processor topology enumeration
			 */
			logical_cpus = 0;
			width = 0;
			level = 0;
			x2apic_id = 0;

			if (*ecx == 0) {
				logical_cpus = threads_per_core;
				width = log2(logical_cpus);
				level = CPUID_TYPE_SMT;
				x2apic_id = vcpu_id;
			}

			if (*ecx == 1) {
				logical_cpus = threads_per_core *
				    cores_per_package;
				width = log2(logical_cpus);
				level = CPUID_TYPE_CORE;
				x2apic_id = vcpu_id;
			}

			if (!cpuid_leaf_b || *ecx >= 2) {
				width = 0;
				logical_cpus = 0;
				level = 0;
				x2apic_id = 0;
			}

			regs[0] = width & 0x1f;
			regs[1] = logical_cpus & 0xffff;
			regs[2] = (((unsigned) level) << 8) | (*ecx & 0xff);
			regs[3] = (unsigned) x2apic_id;
			break;

		case CPUID_0000_000D:
			limits = vmm_get_xsave_limits();
			if (!limits->xsave_enabled) {
				regs[0] = 0;
				regs[1] = 0;
				regs[2] = 0;
				regs[3] = 0;
				break;
			}

			cpuid_count(*eax, *ecx, regs);
			switch (*ecx) {
			case 0:
				/*
				 * Only permit the guest to use bits
				 * that are active in the host in
				 * %xcr0.  Also, claim that the
				 * maximum save area size is
				 * equivalent to the host's current
				 * save area size.  Since this runs
				 * "inside" of vmrun(), it runs with
				 * the guest's xcr0, so the current
				 * save area size is correct as-is.
				 */
				regs[0] &= limits->xcr0_allowed;
				regs[2] = limits->xsave_max_size;
				regs[3] &= (limits->xcr0_allowed >> 32);
				break;
			case 1:
				/* Only permit XSAVEOPT. */
				regs[0] &= CPUID_EXTSTATE_XSAVEOPT;
				regs[1] = 0;
				regs[2] = 0;
				regs[3] = 0;
				break;
			default:
				/*
				 * If the leaf is for a permitted feature,
				 * pass through as-is, otherwise return
				 * all zeroes.
				 */
				if (!(limits->xcr0_allowed & (1ul << *ecx))) {
					regs[0] = 0;
					regs[1] = 0;
					regs[2] = 0;
					regs[3] = 0;
				}
				break;
			}
			break;

		case 0x40000000:
			regs[0] = CPUID_VM_HIGH;
			bcopy(bhyve_id, &regs[1], 4);
			bcopy(bhyve_id + 4, &regs[2], 4);
			bcopy(bhyve_id + 8, &regs[3], 4);
			break;

		default:
			/*
			 * The leaf value has already been clamped so
			 * simply pass this through, keeping count of
			 * how many unhandled leaf values have been seen.
			 */
			atomic_add_long(&bhyve_xcpuids, 1);
			cpuid_count(*eax, *ecx, regs);
			break;
	}

	*eax = regs[0];
	*ebx = regs[1];
	*ecx = regs[2];
	*edx = regs[3];

	return (1);
}