#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */

/* Type definitions */
struct hdaa_widget {scalar_t__ enable; int nconns; scalar_t__ type; scalar_t__ nid; scalar_t__ ossdev; int selconn; scalar_t__* conns; scalar_t__* connsenable; } ;
struct hdaa_pcm_devinfo {struct hdaa_devinfo* devinfo; } ;
struct hdaa_devinfo {int startnode; int endnode; } ;
struct hdaa_audio_ctl {int dummy; } ;
typedef  scalar_t__ nid_t ;

/* Variables and functions */
 int /*<<< orphan*/  HDAA_CTL_IN ; 
 int /*<<< orphan*/  HDAA_CTL_OUT ; 
 scalar_t__ HDA_PARAM_AUDIO_WIDGET_CAP_TYPE_AUDIO_INPUT ; 
 scalar_t__ HDA_PARAM_AUDIO_WIDGET_CAP_TYPE_AUDIO_MIXER ; 
 scalar_t__ HDA_PARAM_AUDIO_WIDGET_CAP_TYPE_PIN_COMPLEX ; 
 int HDA_PARSE_MAXDEPTH ; 
 struct hdaa_audio_ctl* hdaa_audio_ctl_amp_get (struct hdaa_devinfo*,scalar_t__,int /*<<< orphan*/ ,int,int) ; 
 int /*<<< orphan*/  hdaa_audio_ctl_dev_set (struct hdaa_audio_ctl*,int,int,int*,int*) ; 
 struct hdaa_widget* hdaa_widget_get (struct hdaa_devinfo*,int) ; 

__attribute__((used)) static void
hdaa_audio_ctl_source_volume(struct hdaa_pcm_devinfo *pdevinfo,
    int ossdev, nid_t nid, int index, int mute, int left, int right, int depth)
{
	struct hdaa_devinfo *devinfo = pdevinfo->devinfo;
	struct hdaa_widget *w, *wc;
	struct hdaa_audio_ctl *ctl;
	int i, j, conns = 0;

	if (depth > HDA_PARSE_MAXDEPTH)
		return;

	w = hdaa_widget_get(devinfo, nid);
	if (w == NULL || w->enable == 0)
		return;

	/* Count number of active inputs. */
	if (depth > 0) {
		for (j = 0; j < w->nconns; j++) {
			if (!w->connsenable[j])
				continue;
			conns++;
		}
	}

	/* If this is not a first step - use input mixer.
	   Pins have common input ctl so care must be taken. */
	if (depth > 0 && (conns == 1 ||
	    w->type != HDA_PARAM_AUDIO_WIDGET_CAP_TYPE_PIN_COMPLEX)) {
		ctl = hdaa_audio_ctl_amp_get(devinfo, w->nid, HDAA_CTL_IN,
		    index, 1);
		if (ctl)
			hdaa_audio_ctl_dev_set(ctl, ossdev, mute, &left, &right);
	}

	/* If widget has own ossdev - not traverse it.
	   It will be traversed on its own. */
	if (w->ossdev >= 0 && depth > 0)
		return;

	/* We must not traverse pin */
	if ((w->type == HDA_PARAM_AUDIO_WIDGET_CAP_TYPE_AUDIO_INPUT ||
	    w->type == HDA_PARAM_AUDIO_WIDGET_CAP_TYPE_PIN_COMPLEX) &&
	    depth > 0)
		return;

	/*
	 * If signals mixed, we can't assign controls farther.
	 * Ignore this on depth zero. Caller must knows why.
	 */
	if (conns > 1 &&
	    (w->type == HDA_PARAM_AUDIO_WIDGET_CAP_TYPE_AUDIO_MIXER ||
	     w->selconn != index))
		return;

	ctl = hdaa_audio_ctl_amp_get(devinfo, w->nid, HDAA_CTL_OUT, -1, 1);
	if (ctl)
		hdaa_audio_ctl_dev_set(ctl, ossdev, mute, &left, &right);

	for (i = devinfo->startnode; i < devinfo->endnode; i++) {
		wc = hdaa_widget_get(devinfo, i);
		if (wc == NULL || wc->enable == 0)
			continue;
		for (j = 0; j < wc->nconns; j++) {
			if (wc->connsenable[j] && wc->conns[j] == nid) {
				hdaa_audio_ctl_source_volume(pdevinfo, ossdev,
				    wc->nid, j, mute, left, right, depth + 1);
			}
		}
	}
	return;
}