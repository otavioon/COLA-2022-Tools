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
struct tep_handle {int dummy; } ;
struct tep_format_field {char* name; int flags; struct tep_format_field* next; } ;
struct TYPE_2__ {struct tep_format_field* fields; } ;
struct tep_event {char* system; char* name; TYPE_1__ format; } ;
typedef  int /*<<< orphan*/  FILE ;

/* Variables and functions */
 int PATH_MAX ; 
 int /*<<< orphan*/  TEP_EVENT_SORT_ID ; 
 int TEP_FIELD_IS_ARRAY ; 
 int TEP_FIELD_IS_FLAG ; 
 int TEP_FIELD_IS_SIGNED ; 
 int TEP_FIELD_IS_STRING ; 
 int TEP_FIELD_IS_SYMBOLIC ; 
 int /*<<< orphan*/  fclose (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/ * fopen (char*,char*) ; 
 int /*<<< orphan*/  fprintf (int /*<<< orphan*/ *,char*,...) ; 
 int /*<<< orphan*/  sprintf (char*,char*,char const*) ; 
 int /*<<< orphan*/ * stderr ; 
 int tep_get_events_count (struct tep_handle*) ; 
 struct tep_event** tep_list_events (struct tep_handle*,int /*<<< orphan*/ ) ; 

__attribute__((used)) static int python_generate_script(struct tep_handle *pevent, const char *outfile)
{
	int i, not_first, count, nr_events;
	struct tep_event **all_events;
	struct tep_event *event = NULL;
	struct tep_format_field *f;
	char fname[PATH_MAX];
	FILE *ofp;

	sprintf(fname, "%s.py", outfile);
	ofp = fopen(fname, "w");
	if (ofp == NULL) {
		fprintf(stderr, "couldn't open %s\n", fname);
		return -1;
	}
	fprintf(ofp, "# perf script event handlers, "
		"generated by perf script -g python\n");

	fprintf(ofp, "# Licensed under the terms of the GNU GPL"
		" License version 2\n\n");

	fprintf(ofp, "# The common_* event handler fields are the most useful "
		"fields common to\n");

	fprintf(ofp, "# all events.  They don't necessarily correspond to "
		"the 'common_*' fields\n");

	fprintf(ofp, "# in the format files.  Those fields not available as "
		"handler params can\n");

	fprintf(ofp, "# be retrieved using Python functions of the form "
		"common_*(context).\n");

	fprintf(ofp, "# See the perf-script-python Documentation for the list "
		"of available functions.\n\n");

	fprintf(ofp, "from __future__ import print_function\n\n");
	fprintf(ofp, "import os\n");
	fprintf(ofp, "import sys\n\n");

	fprintf(ofp, "sys.path.append(os.environ['PERF_EXEC_PATH'] + \\\n");
	fprintf(ofp, "\t'/scripts/python/Perf-Trace-Util/lib/Perf/Trace')\n");
	fprintf(ofp, "\nfrom perf_trace_context import *\n");
	fprintf(ofp, "from Core import *\n\n\n");

	fprintf(ofp, "def trace_begin():\n");
	fprintf(ofp, "\tprint(\"in trace_begin\")\n\n");

	fprintf(ofp, "def trace_end():\n");
	fprintf(ofp, "\tprint(\"in trace_end\")\n\n");

	nr_events = tep_get_events_count(pevent);
	all_events = tep_list_events(pevent, TEP_EVENT_SORT_ID);

	for (i = 0; all_events && i < nr_events; i++) {
		event = all_events[i];
		fprintf(ofp, "def %s__%s(", event->system, event->name);
		fprintf(ofp, "event_name, ");
		fprintf(ofp, "context, ");
		fprintf(ofp, "common_cpu,\n");
		fprintf(ofp, "\tcommon_secs, ");
		fprintf(ofp, "common_nsecs, ");
		fprintf(ofp, "common_pid, ");
		fprintf(ofp, "common_comm,\n\t");
		fprintf(ofp, "common_callchain, ");

		not_first = 0;
		count = 0;

		for (f = event->format.fields; f; f = f->next) {
			if (not_first++)
				fprintf(ofp, ", ");
			if (++count % 5 == 0)
				fprintf(ofp, "\n\t");

			fprintf(ofp, "%s", f->name);
		}
		if (not_first++)
			fprintf(ofp, ", ");
		if (++count % 5 == 0)
			fprintf(ofp, "\n\t\t");
		fprintf(ofp, "perf_sample_dict");

		fprintf(ofp, "):\n");

		fprintf(ofp, "\t\tprint_header(event_name, common_cpu, "
			"common_secs, common_nsecs,\n\t\t\t"
			"common_pid, common_comm)\n\n");

		fprintf(ofp, "\t\tprint(\"");

		not_first = 0;
		count = 0;

		for (f = event->format.fields; f; f = f->next) {
			if (not_first++)
				fprintf(ofp, ", ");
			if (count && count % 3 == 0) {
				fprintf(ofp, "\" \\\n\t\t\"");
			}
			count++;

			fprintf(ofp, "%s=", f->name);
			if (f->flags & TEP_FIELD_IS_STRING ||
			    f->flags & TEP_FIELD_IS_FLAG ||
			    f->flags & TEP_FIELD_IS_ARRAY ||
			    f->flags & TEP_FIELD_IS_SYMBOLIC)
				fprintf(ofp, "%%s");
			else if (f->flags & TEP_FIELD_IS_SIGNED)
				fprintf(ofp, "%%d");
			else
				fprintf(ofp, "%%u");
		}

		fprintf(ofp, "\" %% \\\n\t\t(");

		not_first = 0;
		count = 0;

		for (f = event->format.fields; f; f = f->next) {
			if (not_first++)
				fprintf(ofp, ", ");

			if (++count % 5 == 0)
				fprintf(ofp, "\n\t\t");

			if (f->flags & TEP_FIELD_IS_FLAG) {
				if ((count - 1) % 5 != 0) {
					fprintf(ofp, "\n\t\t");
					count = 4;
				}
				fprintf(ofp, "flag_str(\"");
				fprintf(ofp, "%s__%s\", ", event->system,
					event->name);
				fprintf(ofp, "\"%s\", %s)", f->name,
					f->name);
			} else if (f->flags & TEP_FIELD_IS_SYMBOLIC) {
				if ((count - 1) % 5 != 0) {
					fprintf(ofp, "\n\t\t");
					count = 4;
				}
				fprintf(ofp, "symbol_str(\"");
				fprintf(ofp, "%s__%s\", ", event->system,
					event->name);
				fprintf(ofp, "\"%s\", %s)", f->name,
					f->name);
			} else
				fprintf(ofp, "%s", f->name);
		}

		fprintf(ofp, "))\n\n");

		fprintf(ofp, "\t\tprint('Sample: {'+"
			"get_dict_as_string(perf_sample_dict['sample'], ', ')+'}')\n\n");

		fprintf(ofp, "\t\tfor node in common_callchain:");
		fprintf(ofp, "\n\t\t\tif 'sym' in node:");
		fprintf(ofp, "\n\t\t\t\tprint(\"\\t[%%x] %%s\" %% (node['ip'], node['sym']['name']))");
		fprintf(ofp, "\n\t\t\telse:");
		fprintf(ofp, "\n\t\t\t\tprint(\"\t[%%x]\" %% (node['ip']))\n\n");
		fprintf(ofp, "\t\tprint()\n\n");

	}

	fprintf(ofp, "def trace_unhandled(event_name, context, "
		"event_fields_dict, perf_sample_dict):\n");

	fprintf(ofp, "\t\tprint(get_dict_as_string(event_fields_dict))\n");
	fprintf(ofp, "\t\tprint('Sample: {'+"
		"get_dict_as_string(perf_sample_dict['sample'], ', ')+'}')\n\n");

	fprintf(ofp, "def print_header("
		"event_name, cpu, secs, nsecs, pid, comm):\n"
		"\tprint(\"%%-20s %%5u %%05u.%%09u %%8u %%-20s \" %% \\\n\t"
		"(event_name, cpu, secs, nsecs, pid, comm), end=\"\")\n\n");

	fprintf(ofp, "def get_dict_as_string(a_dict, delimiter=' '):\n"
		"\treturn delimiter.join"
		"(['%%s=%%s'%%(k,str(v))for k,v in sorted(a_dict.items())])\n");

	fclose(ofp);

	fprintf(stderr, "generated Python script: %s\n", fname);

	return 0;
}