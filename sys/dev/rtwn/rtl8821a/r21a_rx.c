/*-
 * Copyright (c) 2016 Andriy Voskoboinyk <avos@FreeBSD.org>
 *
 * Permission to use, copy, modify, and distribute this software for any
 * purpose with or without fee is hereby granted, provided that the above
 * copyright notice and this permission notice appear in all copies.
 *
 * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
 * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
 * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
 * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN
 * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF
 * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
 */

#include <sys/cdefs.h>
__FBSDID("$FreeBSD$");

#include "opt_wlan.h"

#include <sys/param.h>
#include <sys/lock.h>
#include <sys/mutex.h>
#include <sys/mbuf.h>
#include <sys/kernel.h>
#include <sys/socket.h>
#include <sys/systm.h>
#include <sys/malloc.h>
#include <sys/queue.h>
#include <sys/taskqueue.h>
#include <sys/bus.h>
#include <sys/endian.h>
#include <sys/linker.h>

#include <net/if.h>
#include <net/ethernet.h>
#include <net/if_media.h>

#include <net80211/ieee80211_var.h>
#include <net80211/ieee80211_radiotap.h>

#include <dev/rtwn/if_rtwnvar.h>

#include <dev/rtwn/rtl8812a/r12a_rx_desc.h>

#include <dev/rtwn/rtl8821a/r21a.h>


int8_t
r21a_get_rssi_cck(struct rtwn_softc *sc, void *physt)
{
	struct r12a_rx_phystat *stat = (struct r12a_rx_phystat *)physt;
	int8_t lna_idx, rssi;

	lna_idx = (stat->cfosho[0] & 0xe0) >> 5;
	rssi = -6 - 2*(stat->cfosho[0] & 0x1f);	/* Pout - (2 * VGA_idx) */

	switch (lna_idx) {
	case 5:
		rssi -= 32;
		break;
	case 4:
		rssi -= 24;
		break;
	case 2:
		rssi -= 11;
		break;
	case 1:
		rssi += 5;
		break;
	case 0:
		rssi += 21;
		break;
	}

	return (rssi);
}

