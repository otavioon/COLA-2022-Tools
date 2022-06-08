#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef int scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */

/* Type definitions */
struct tm {unsigned int tm_wday; unsigned int tm_mon; int tm_year; long long tm_mday; int tm_yday; long long tm_hour; long long tm_min; long long __tm_gmtoff; long long tm_sec; int /*<<< orphan*/  tm_isdst; } ;
typedef  unsigned int nl_item ;
typedef  int /*<<< orphan*/  locale_t ;

/* Variables and functions */
 unsigned int ABDAY_1 ; 
 unsigned int ABMON_1 ; 
 unsigned int AM_STR ; 
 unsigned int DAY_1 ; 
 unsigned int D_FMT ; 
 unsigned int D_T_FMT ; 
 unsigned int MON_1 ; 
 unsigned int PM_STR ; 
 unsigned int T_FMT ; 
 unsigned int T_FMT_AMPM ; 
 char* __nl_langinfo_l (unsigned int,int /*<<< orphan*/ ) ; 
 size_t __strftime_l (char*,int,char const*,struct tm const*,int /*<<< orphan*/ ) ; 
 long long __tm_to_secs (struct tm const*) ; 
 char* __tm_to_tzname (struct tm const*) ; 
 int abs (int) ; 
 size_t snprintf (char*,int,char*,int,...) ; 
 size_t strlen (char const*) ; 
 int week_num (struct tm const*) ; 

const char *__strftime_fmt_1(char (*s)[100], size_t *l, int f, const struct tm *tm, locale_t loc)
{
	nl_item item;
	long long val;
	const char *fmt = "-";
	int width = 2;

	switch (f) {
	case 'a':
		if (tm->tm_wday > 6U) goto string;
		item = ABDAY_1 + tm->tm_wday;
		goto nl_strcat;
	case 'A':
		if (tm->tm_wday > 6U) goto string;
		item = DAY_1 + tm->tm_wday;
		goto nl_strcat;
	case 'h':
	case 'b':
		if (tm->tm_mon > 11U) goto string;
		item = ABMON_1 + tm->tm_mon;
		goto nl_strcat;
	case 'B':
		if (tm->tm_mon > 11U) goto string;
		item = MON_1 + tm->tm_mon;
		goto nl_strcat;
	case 'c':
		item = D_T_FMT;
		goto nl_strftime;
	case 'C':
		val = (1900LL+tm->tm_year) / 100;
		goto number;
	case 'd':
		val = tm->tm_mday;
		goto number;
	case 'D':
		fmt = "%m/%d/%y";
		goto recu_strftime;
	case 'e':
		*l = snprintf(*s, sizeof *s, "%2d", tm->tm_mday);
		return *s;
	case 'F':
		fmt = "%Y-%m-%d";
		goto recu_strftime;
	case 'g':
	case 'G':
		val = tm->tm_year + 1900LL;
		if (tm->tm_yday < 3 && week_num(tm) != 1) val--;
		else if (tm->tm_yday > 360 && week_num(tm) == 1) val++;
		if (f=='g') val %= 100;
		else width = 4;
		goto number;
	case 'H':
		val = tm->tm_hour;
		goto number;
	case 'I':
		val = tm->tm_hour;
		if (!val) val = 12;
		else if (val > 12) val -= 12;
		goto number;
	case 'j':
		val = tm->tm_yday+1;
		width = 3;
		goto number;
	case 'm':
		val = tm->tm_mon+1;
		goto number;
	case 'M':
		val = tm->tm_min;
		goto number;
	case 'n':
		*l = 1;
		return "\n";
	case 'p':
		item = tm->tm_hour >= 12 ? PM_STR : AM_STR;
		goto nl_strcat;
	case 'r':
		item = T_FMT_AMPM;
		goto nl_strftime;
	case 'R':
		fmt = "%H:%M";
		goto recu_strftime;
	case 's':
		val = __tm_to_secs(tm) - tm->__tm_gmtoff;
		width = 1;
		goto number;
	case 'S':
		val = tm->tm_sec;
		goto number;
	case 't':
		*l = 1;
		return "\t";
	case 'T':
		fmt = "%H:%M:%S";
		goto recu_strftime;
	case 'u':
		val = tm->tm_wday ? tm->tm_wday : 7;
		width = 1;
		goto number;
	case 'U':
		val = (tm->tm_yday + 7U - tm->tm_wday) / 7;
		goto number;
	case 'W':
		val = (tm->tm_yday + 7U - (tm->tm_wday+6U)%7) / 7;
		goto number;
	case 'V':
		val = week_num(tm);
		goto number;
	case 'w':
		val = tm->tm_wday;
		width = 1;
		goto number;
	case 'x':
		item = D_FMT;
		goto nl_strftime;
	case 'X':
		item = T_FMT;
		goto nl_strftime;
	case 'y':
		val = tm->tm_year % 100;
		goto number;
	case 'Y':
		val = tm->tm_year + 1900LL;
		if (val >= 10000) {
			*l = snprintf(*s, sizeof *s, "+%lld", val);
			return *s;
		}
		width = 4;
		goto number;
	case 'z':
		if (tm->tm_isdst < 0) {
			*l = 0;
			return "";
		}
		*l = snprintf(*s, sizeof *s, "%+.2d%.2d",
			(tm->__tm_gmtoff)/3600,
			abs(tm->__tm_gmtoff%3600)/60);
		return *s;
	case 'Z':
		if (tm->tm_isdst < 0) {
			*l = 0;
			return "";
		}
		fmt = __tm_to_tzname(tm);
		goto string;
	case '%':
		*l = 1;
		return "%";
	default:
		return 0;
	}
number:
	*l = snprintf(*s, sizeof *s, "%0*lld", width, val);
	return *s;
nl_strcat:
	fmt = __nl_langinfo_l(item, loc);
string:
	*l = strlen(fmt);
	return fmt;
nl_strftime:
	fmt = __nl_langinfo_l(item, loc);
recu_strftime:
	*l = __strftime_l(*s, sizeof *s, fmt, tm, loc);
	if (!*l) return 0;
	return *s;
}