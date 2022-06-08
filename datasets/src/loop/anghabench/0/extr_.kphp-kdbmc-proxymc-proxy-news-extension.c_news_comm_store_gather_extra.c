#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef int scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */

/* Type definitions */
struct news_gather_extra {int request_tag; int mask; int grouping; int date; int st_time; int end_time; int max_res; int user_mode; int user_id; } ;

/* Variables and functions */
 int /*<<< orphan*/  MAX_QUERY ; 
 int PHP_MAX_RES ; 
 int /*<<< orphan*/  Q ; 
 int QL ; 
 int QLsave ; 
 int /*<<< orphan*/  Qsave ; 
 int /*<<< orphan*/  fprintf (int /*<<< orphan*/ ,char*,int) ; 
 int lrand48 () ; 
 int /*<<< orphan*/  memcpy (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int) ; 
 int np_parse_list_str (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int,char const*,int) ; 
 int /*<<< orphan*/  set_rlen () ; 
 int sscanf (char const*,char*,int*,...) ; 
 int /*<<< orphan*/  stderr ; 
 int strtol (char const*,char**,int) ; 
 int uidsave ; 
 scalar_t__ verbosity ; 
 struct news_gather_extra* zzmalloc (int) ; 

void *news_comm_store_gather_extra (const char *key, int key_len) {
  int list_tag;
  int grouping = 0, date = 0, st_time = 0, end_time = 0, x = 0, raw = 0, max_res = -1, user_mode = 0, user_id = 0, mask = 0xffffffff;
  char *ptr;

  if (*key == '%') {
    raw = 1;
  }

  if ((sscanf (key+raw, "raw_comm_updates[%d,%d]:%n", &st_time, &end_time, &x) >= 2 || sscanf (key+raw, "raw_comm_updates%n%d", &x, &list_tag) >= 1) && x > 0) {
    x += raw;
  } else if (sscanf (key+raw, "comm_updates%d,%d_%d>%d#%d:%n", &date, &end_time, &grouping, &st_time, &max_res, &x) >= 5) {
    x += raw;
  } else if (sscanf (key+raw, "comm_updates%d,%d_%d>%d:%n", &date, &end_time, &grouping, &st_time, &x) >= 4) {
    x += raw;
  } else if (sscanf (key+raw, "comm_updates%d,%d_%d#%d:%n", &date, &end_time, &grouping, &max_res, &x) >= 4) {
    x += raw;
    st_time = date;
  } else if (sscanf (key+raw, "comm_updates%d,%d_%d:%n", &date, &end_time, &grouping, &x) >= 3) {
    x += raw;
    st_time = date;
  } else if ((sscanf (key+raw, "raw_user_comm_updates[%d,%d]:%n", &st_time, &end_time, &x) >= 2 || sscanf (key+raw, "raw_user_comm_updates%n%d", &x, &list_tag) >= 1) && x > 0) {
    x += raw;                   
    user_mode = 1;
  } else if (sscanf (key+raw, "user_comm_updates%d,%d_%d>%d#%d:%n", &date, &end_time, &grouping, &st_time, &max_res, &x) >= 5) {
    x += raw;
    user_mode = 1;
  } else if (sscanf (key+raw, "user_comm_updates%d,%d_%d>%d:%n", &date, &end_time, &grouping, &st_time, &x) >= 4) {
    x += raw;
    user_mode = 1;
  } else if (sscanf (key+raw, "user_comm_updates%d,%d_%d#%d:%n", &date, &end_time, &grouping, &max_res, &x) >= 4) {
    x += raw;
    st_time = date;
    user_mode = 1;
  } else if (sscanf (key+raw, "user_comm_updates%d,%d_%d:%n", &date, &end_time, &grouping, &x) >= 3) {
    x += raw;
    st_time = date;
    user_mode = 1;
  } else if (sscanf (key+raw, "raw_user_comm_bookmarks%n", &x) >= 0) {
    x += raw;
    user_mode = 2;
  }

  //fprintf (stderr, "raw = %d, x = %d, user_mode = %d\n", raw, x, user_mode);
  if (x <= 1) {
    return 0;
  }

  if (!user_mode) {
    ptr = 0;
    list_tag = strtol (key + x, &ptr, 10);

    if (list_tag < 0 && ptr == key + key_len && list_tag == uidsave && QLsave) {
      QL = QLsave;
      memcpy (Q, Qsave, QL * 12);
    } else {
      QL = np_parse_list_str (Q, MAX_QUERY, 3, key + x, key_len - x);
      list_tag = lrand48() | (-1 << 30);
    }

    if (QL <= 0) {
      return 0;
    }

    if (list_tag >= 0) {
      return 0;
    }

    set_rlen ();
  } else {
    ptr = 0;
    user_id = strtol (key + x, &ptr, 10);
    if (verbosity) {
      fprintf (stderr, "news_comm_store_gather_extra: user_id = %d\n", user_id);
    }
    if (ptr < key + key_len && *ptr == ',') {
      ptr ++;
      mask = strtol (ptr, &ptr, 10);
    }
    if (ptr != key + key_len || user_id <= 0) {
      return 0;
    }
  }


  if (end_time <= 0) {
    end_time = 0x7fffffff;
  }

  struct news_gather_extra* extra = zzmalloc (sizeof (struct news_gather_extra));
  extra->request_tag = list_tag;
  extra->mask = mask;
  extra->grouping = grouping;
  extra->date = date;
  extra->st_time = st_time;
  extra->end_time = end_time;
  extra->max_res = (max_res < PHP_MAX_RES && max_res > 0) ? max_res : PHP_MAX_RES;
  extra->user_mode = user_mode;
  extra->user_id = user_id;
  return extra;
}