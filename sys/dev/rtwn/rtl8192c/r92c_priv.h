/*-
 * Copyright (c) 2010 Damien Bergamini <damien.bergamini@free.fr>
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
 *
 * $OpenBSD: if_urtwnreg.h,v 1.3 2010/11/16 18:02:59 damien Exp $
 * $FreeBSD$
 */

#ifndef R92C_PRIV_H
#define R92C_PRIV_H

#include <dev/rtwn/rtl8192c/r92c_rom_defs.h>

/*
 * Parsed Tx power (diff) values.
 */
static struct rtwn_r92c_txpwr {
	uint8_t		cck_tx_pwr[R92C_MAX_CHAINS][R92C_GROUP_2G];
	uint8_t		ht40_1s_tx_pwr[R92C_MAX_CHAINS][R92C_GROUP_2G];
	int8_t		ht40_2s_tx_pwr_diff[R92C_MAX_CHAINS][R92C_GROUP_2G];
	int8_t		ht20_tx_pwr_diff[R92C_MAX_CHAINS][R92C_GROUP_2G];
	int8_t		ofdm_tx_pwr_diff[R92C_MAX_CHAINS][R92C_GROUP_2G];
	int8_t		ht40_max_pwr[R92C_MAX_CHAINS][R92C_GROUP_2G];
	int8_t		ht20_max_pwr[R92C_MAX_CHAINS][R92C_GROUP_2G];
} r92c_txpwr;


/*
 * Baseband initialization values.
 */
/*
 * RTL8192CU and RTL8192CE-VAU.
 */
static const uint16_t rtl8192ce_bb_regs[] = {
	0x024, 0x028, 0x800, 0x804, 0x808, 0x80c, 0x810, 0x814, 0x818,
	0x81c, 0x820, 0x824, 0x828, 0x82c, 0x830, 0x834, 0x838, 0x83c,
	0x840, 0x844, 0x848, 0x84c, 0x850, 0x854, 0x858, 0x85c, 0x860,
	0x864, 0x868, 0x86c, 0x870, 0x874, 0x878, 0x87c, 0x880, 0x884,
	0x888, 0x88c, 0x890, 0x894, 0x898, 0x89c, 0x900, 0x904, 0x908,
	0x90c, 0xa00, 0xa04, 0xa08, 0xa0c, 0xa10, 0xa14, 0xa18, 0xa1c,
	0xa20, 0xa24, 0xa28, 0xa2c, 0xa70, 0xa74, 0xc00, 0xc04, 0xc08,
	0xc0c, 0xc10, 0xc14, 0xc18, 0xc1c, 0xc20, 0xc24, 0xc28, 0xc2c,
	0xc30, 0xc34, 0xc38, 0xc3c, 0xc40, 0xc44, 0xc48, 0xc4c, 0xc50,
	0xc54, 0xc58, 0xc5c, 0xc60, 0xc64, 0xc68, 0xc6c, 0xc70, 0xc74,
	0xc78, 0xc7c, 0xc80, 0xc84, 0xc88, 0xc8c, 0xc90, 0xc94, 0xc98,
	0xc9c, 0xca0, 0xca4, 0xca8, 0xcac, 0xcb0, 0xcb4, 0xcb8, 0xcbc,
	0xcc0, 0xcc4, 0xcc8, 0xccc, 0xcd0, 0xcd4, 0xcd8, 0xcdc, 0xce0,
	0xce4, 0xce8, 0xcec, 0xd00, 0xd04, 0xd08, 0xd0c, 0xd10, 0xd14,
	0xd18, 0xd2c, 0xd30, 0xd34, 0xd38, 0xd3c, 0xd40, 0xd44, 0xd48,
	0xd4c, 0xd50, 0xd54, 0xd58, 0xd5c, 0xd60, 0xd64, 0xd68, 0xd6c,
	0xd70, 0xd74, 0xd78, 0xe00, 0xe04, 0xe08, 0xe10, 0xe14, 0xe18,
	0xe1c, 0xe28, 0xe30, 0xe34, 0xe38, 0xe3c, 0xe40, 0xe44, 0xe48,
	0xe4c, 0xe50, 0xe54, 0xe58, 0xe5c, 0xe60, 0xe68, 0xe6c, 0xe70,
	0xe74, 0xe78, 0xe7c, 0xe80, 0xe84, 0xe88, 0xe8c, 0xed0, 0xed4,
	0xed8, 0xedc, 0xee0, 0xeec, 0xf14, 0xf4c, 0xf00
};

static const uint32_t rtl8192ce_agc_vals[] = {
	0x7b000001, 0x7b010001, 0x7b020001, 0x7b030001, 0x7b040001,
	0x7b050001, 0x7a060001, 0x79070001, 0x78080001, 0x77090001,
	0x760a0001, 0x750b0001, 0x740c0001, 0x730d0001, 0x720e0001,
	0x710f0001, 0x70100001, 0x6f110001, 0x6e120001, 0x6d130001,
	0x6c140001, 0x6b150001, 0x6a160001, 0x69170001, 0x68180001,
	0x67190001, 0x661a0001, 0x651b0001, 0x641c0001, 0x631d0001,
	0x621e0001, 0x611f0001, 0x60200001, 0x49210001, 0x48220001,
	0x47230001, 0x46240001, 0x45250001, 0x44260001, 0x43270001,
	0x42280001, 0x41290001, 0x402a0001, 0x262b0001, 0x252c0001,
	0x242d0001, 0x232e0001, 0x222f0001, 0x21300001, 0x20310001,
	0x06320001, 0x05330001, 0x04340001, 0x03350001, 0x02360001,
	0x01370001, 0x00380001, 0x00390001, 0x003a0001, 0x003b0001,
	0x003c0001, 0x003d0001, 0x003e0001, 0x003f0001, 0x7b400001,
	0x7b410001, 0x7b420001, 0x7b430001, 0x7b440001, 0x7b450001,
	0x7a460001, 0x79470001, 0x78480001, 0x77490001, 0x764a0001,
	0x754b0001, 0x744c0001, 0x734d0001, 0x724e0001, 0x714f0001,
	0x70500001, 0x6f510001, 0x6e520001, 0x6d530001, 0x6c540001,
	0x6b550001, 0x6a560001, 0x69570001, 0x68580001, 0x67590001,
	0x665a0001, 0x655b0001, 0x645c0001, 0x635d0001, 0x625e0001,
	0x615f0001, 0x60600001, 0x49610001, 0x48620001, 0x47630001,
	0x46640001, 0x45650001, 0x44660001, 0x43670001, 0x42680001,
	0x41690001, 0x406a0001, 0x266b0001, 0x256c0001, 0x246d0001,
	0x236e0001, 0x226f0001, 0x21700001, 0x20710001, 0x06720001,
	0x05730001, 0x04740001, 0x03750001, 0x02760001, 0x01770001,
	0x00780001, 0x00790001, 0x007a0001, 0x007b0001, 0x007c0001,
	0x007d0001, 0x007e0001, 0x007f0001, 0x3800001e, 0x3801001e,
	0x3802001e, 0x3803001e, 0x3804001e, 0x3805001e, 0x3806001e,
	0x3807001e, 0x3808001e, 0x3c09001e, 0x3e0a001e, 0x400b001e,
	0x440c001e, 0x480d001e, 0x4c0e001e, 0x500f001e, 0x5210001e,
	0x5611001e, 0x5a12001e, 0x5e13001e, 0x6014001e, 0x6015001e,
	0x6016001e, 0x6217001e, 0x6218001e, 0x6219001e, 0x621a001e,
	0x621b001e, 0x621c001e, 0x621d001e, 0x621e001e, 0x621f001e
};

static const struct rtwn_agc_prog rtl8192ce_agc[] = {
	{
		nitems(rtl8192ce_agc_vals),
		rtl8192ce_agc_vals,
		{ 0 },
		NULL
	}
};


/*
 * RTL8188CE-VAU.
 */
static const uint32_t rtl8188ce_bb_vals[] = {
	0x0011800d, 0x00ffdb83, 0x80040000, 0x00000001, 0x0000fc00,
	0x0000000a, 0x10005388, 0x020c3d10, 0x02200385, 0x00000000,
	0x01000100, 0x00390004, 0x00000000, 0x00000000, 0x00000000,
	0x00000000, 0x00000000, 0x00000000, 0x00010000, 0x00000000,
	0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x569a569a,
	0x001b25a4, 0x66e60230, 0x061f0130, 0x00000000, 0x32323200,
	0x07000700, 0x22004000, 0x00000808, 0x00000000, 0xc0083070,
	0x000004d5, 0x00000000, 0xccc000c0, 0x00000800, 0xfffffffe,
	0x40302010, 0x00706050, 0x00000000, 0x00000023, 0x00000000,
	0x81121111, 0x00d047c8, 0x80ff000c, 0x8c838300, 0x2e68120f,
	0x9500bb78, 0x11144028, 0x00881117, 0x89140f00, 0x1a1b0000,
	0x090e1317, 0x00000204, 0x00d30000, 0x101fbf00, 0x00000007,
	0x48071d40, 0x03a05611, 0x000000e4, 0x6c6c6c6c, 0x08800000,
	0x40000100, 0x08800000, 0x40000100, 0x00000000, 0x00000000,
	0x00000000, 0x00000000, 0x69e9ac44, 0x469652cf, 0x49795994,
	0x0a97971c, 0x1f7c403f, 0x000100b7, 0xec020107, 0x007f037f,
	0x6954341e, 0x43bc0094, 0x6954341e, 0x433c0094, 0x00000000,
	0x5116848b, 0x47c00bff, 0x00000036, 0x2c7f000d, 0x018610db,
	0x0000001f, 0x00b91612, 0x40000100, 0x20f60000, 0x40000100,
	0x20200000, 0x00121820, 0x00000000, 0x00121820, 0x00007f7f,
	0x00000000, 0x00000080, 0x00000000, 0x00000000, 0x00000000,
	0x00000000, 0x00000000, 0x28000000, 0x00000000, 0x00000000,
	0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x64b22427,
	0x00766932, 0x00222222, 0x00000000, 0x37644302, 0x2f97d40c,
	0x00080740, 0x00020401, 0x0000907f, 0x20010201, 0xa0633333,
	0x3333bc43, 0x7a8f5b6b, 0xcc979975, 0x00000000, 0x80608000,
	0x00000000, 0x00027293, 0x00000000, 0x00000000, 0x00000000,
	0x00000000, 0x6437140a, 0x00000000, 0x00000000, 0x30032064,
	0x4653de68, 0x04518a3c, 0x00002101, 0x2a201c16, 0x1812362e,
	0x322c2220, 0x000e3c24, 0x2a2a2a2a, 0x2a2a2a2a, 0x03902a2a,
	0x2a2a2a2a, 0x2a2a2a2a, 0x2a2a2a2a, 0x2a2a2a2a, 0x00000000,
	0x1000dc1f, 0x10008c1f, 0x02140102, 0x681604c2, 0x01007c00,
	0x01004800, 0xfb000000, 0x000028d1, 0x1000dc1f, 0x10008c1f,
	0x02140102, 0x28160d05, 0x00000008, 0x001b25a4, 0x631b25a0,
	0x631b25a0, 0x081b25a0, 0x081b25a0, 0x081b25a0, 0x081b25a0,
	0x631b25a0, 0x081b25a0, 0x631b25a0, 0x631b25a0, 0x631b25a0,
	0x631b25a0, 0x001b25a0, 0x001b25a0, 0x6b1b25a0, 0x00000003,
	0x00000000, 0x00000300
};

static const struct rtwn_bb_prog rtl8188ce_bb[] = {
	{
		nitems(rtl8192ce_bb_regs),
		rtl8192ce_bb_regs,
		rtl8188ce_bb_vals,
		{ 0 },
		NULL
	}
};

static const uint32_t rtl8188ce_agc_vals[] = {
	0x7b000001, 0x7b010001, 0x7b020001, 0x7b030001, 0x7b040001,
	0x7b050001, 0x7a060001, 0x79070001, 0x78080001, 0x77090001,
	0x760a0001, 0x750b0001, 0x740c0001, 0x730d0001, 0x720e0001,
	0x710f0001, 0x70100001, 0x6f110001, 0x6e120001, 0x6d130001,
	0x6c140001, 0x6b150001, 0x6a160001, 0x69170001, 0x68180001,
	0x67190001, 0x661a0001, 0x651b0001, 0x641c0001, 0x631d0001,
	0x621e0001, 0x611f0001, 0x60200001, 0x49210001, 0x48220001,
	0x47230001, 0x46240001, 0x45250001, 0x44260001, 0x43270001,
	0x42280001, 0x41290001, 0x402a0001, 0x262b0001, 0x252c0001,
	0x242d0001, 0x232e0001, 0x222f0001, 0x21300001, 0x20310001,
	0x06320001, 0x05330001, 0x04340001, 0x03350001, 0x02360001,
	0x01370001, 0x00380001, 0x00390001, 0x003a0001, 0x003b0001,
	0x003c0001, 0x003d0001, 0x003e0001, 0x003f0001, 0x7b400001,
	0x7b410001, 0x7b420001, 0x7b430001, 0x7b440001, 0x7b450001,
	0x7a460001, 0x79470001, 0x78480001, 0x77490001, 0x764a0001,
	0x754b0001, 0x744c0001, 0x734d0001, 0x724e0001, 0x714f0001,
	0x70500001, 0x6f510001, 0x6e520001, 0x6d530001, 0x6c540001,
	0x6b550001, 0x6a560001, 0x69570001, 0x68580001, 0x67590001,
	0x665a0001, 0x655b0001, 0x645c0001, 0x635d0001, 0x625e0001,
	0x615f0001, 0x60600001, 0x49610001, 0x48620001, 0x47630001,
	0x46640001, 0x45650001, 0x44660001, 0x43670001, 0x42680001,
	0x41690001, 0x406a0001, 0x266b0001, 0x256c0001, 0x246d0001,
	0x236e0001, 0x226f0001, 0x21700001, 0x20710001, 0x06720001,
	0x05730001, 0x04740001, 0x03750001, 0x02760001, 0x01770001,
	0x00780001, 0x00790001, 0x007a0001, 0x007b0001, 0x007c0001,
	0x007d0001, 0x007e0001, 0x007f0001, 0x3800001e, 0x3801001e,
	0x3802001e, 0x3803001e, 0x3804001e, 0x3805001e, 0x3806001e,
	0x3807001e, 0x3808001e, 0x3c09001e, 0x3e0a001e, 0x400b001e,
	0x440c001e, 0x480d001e, 0x4c0e001e, 0x500f001e, 0x5210001e,
	0x5611001e, 0x5a12001e, 0x5e13001e, 0x6014001e, 0x6015001e,
	0x6016001e, 0x6217001e, 0x6218001e, 0x6219001e, 0x621a001e,
	0x621b001e, 0x621c001e, 0x621d001e, 0x621e001e, 0x621f001e
};

static const struct rtwn_agc_prog rtl8188ce_agc[] = {
	{
		nitems(rtl8188ce_agc_vals),
		rtl8188ce_agc_vals,
		{ 0 },
		NULL
	}
};


/*
 * RF initialization values.
 */
/*
 * RTL8192CU and RTL8192CE-VAU.
 */
static const uint8_t rtl8192ce_rf1_regs[] = {
	0x00, 0x01, 0x02, 0x03, 0x04, 0x09, 0x0a, 0x0b, 0x0c, 0x0d, 0x0e,
	0x0f, 0x19, 0x1a, 0x1b, 0x1c, 0x1d, 0x1e, 0x1f, 0x20, 0x21, 0x22,
	0x23, 0x24, 0x25, 0x26, 0x27, 0x28, 0x29, 0x2a, 0x2b, 0x2a, 0x2b,
	0x2a, 0x2b, 0x2b, 0x2c, 0x2a, 0x2b, 0x2b, 0x2c, 0x2a, 0x2b, 0x2b,
	0x2c, 0x2a, 0x2b, 0x2b, 0x2c, 0x2a, 0x2b, 0x2b, 0x2c, 0x2a, 0x2b,
	0x2b, 0x2c, 0x2a, 0x2b, 0x2b, 0x2c, 0x2a, 0x2b, 0x2b, 0x2c, 0x2a,
	0x2b, 0x2b, 0x2c, 0x2a, 0x2b, 0x2b, 0x2c, 0x2a, 0x2b, 0x2b, 0x2c,
	0x2a, 0x2b, 0x2b, 0x2c, 0x2a, 0x2b, 0x2b, 0x2c, 0x2a, 0x2b, 0x2b,
	0x2c, 0x2a, 0x10, 0x11, 0x10, 0x11, 0x10, 0x11, 0x10, 0x11, 0x10,
	0x11, 0x10, 0x11, 0x10, 0x11, 0x12, 0x12, 0x12, 0x12, 0x13, 0x13,
	0x13, 0x13, 0x13, 0x13, 0x13, 0x13, 0x13, 0x13, 0x13, 0x14, 0x14,
	0x14, 0x14, 0x15, 0x15, 0x15, 0x15, 0x16, 0x16, 0x16, 0x16, 0x00,
	0x18, 0xfe, 0xfe, 0x1f, 0xfe, 0xfe, 0x1e, 0x1f, 0x00
};

static const uint32_t rtl8192ce_rf1_vals[] = {
	0x30159, 0x31284, 0x98000, 0x18c63, 0x210e7, 0x2044f, 0x1adb1,
	0x54867, 0x8992e, 0x0e52c, 0x39ce7, 0x00451, 0x00000, 0x10255,
	0x60a00, 0xfc378, 0xa1250, 0x4445f, 0x80001, 0x0b614, 0x6c000,
	0x00000, 0x01558, 0x00060, 0x00483, 0x4f000, 0xec7d9, 0x577c0,
	0x04783, 0x00001, 0x21334, 0x00000, 0x00054, 0x00001, 0x00808,
	0x53333, 0x0000c, 0x00002, 0x00808, 0x5b333, 0x0000d, 0x00003,
	0x00808, 0x63333, 0x0000d, 0x00004, 0x00808, 0x6b333, 0x0000d,
	0x00005, 0x00808, 0x73333, 0x0000d, 0x00006, 0x00709, 0x5b333,
	0x0000d, 0x00007, 0x00709, 0x63333, 0x0000d, 0x00008, 0x0060a,
	0x4b333, 0x0000d, 0x00009, 0x0060a, 0x53333, 0x0000d, 0x0000a,
	0x0060a, 0x5b333, 0x0000d, 0x0000b, 0x0060a, 0x63333, 0x0000d,
	0x0000c, 0x0060a, 0x6b333, 0x0000d, 0x0000d, 0x0060a, 0x73333,
	0x0000d, 0x0000e, 0x0050b, 0x66666, 0x0001a, 0xe0000, 0x4000f,
	0xe31fc, 0x6000f, 0xff9f8, 0x2000f, 0x203f9, 0x3000f, 0xff500,
	0x00000, 0x00000, 0x8000f, 0x3f100, 0x9000f, 0x23100, 0x32000,
	0x71000, 0xb0000, 0xfc000, 0x287af, 0x244b7, 0x204ab, 0x1c49f,
	0x18493, 0x14297, 0x10295, 0x0c298, 0x0819c, 0x040a8, 0x0001c,
	0x1944c, 0x59444, 0x9944c, 0xd9444, 0x0f424, 0x4f424, 0x8f424,
	0xcf424, 0xe0330, 0xa0330, 0x60330, 0x20330, 0x10159, 0x0f401,
	0x0c350, 0x0c350, 0x80003, 0x0c350, 0x0c350, 0x44457, 0x80000,
	0x30159
};

static const uint8_t rtl8192ce_rf2_regs[] = {
	0x00, 0x01, 0x02, 0x03, 0x04, 0x09, 0x0a, 0x0b, 0x0c, 0x0d, 0x0e,
	0x0f, 0x12, 0x12, 0x12, 0x12, 0x13, 0x13, 0x13, 0x13, 0x13, 0x13,
	0x13, 0x13, 0x13, 0x13, 0x13, 0x14, 0x14, 0x14, 0x14, 0x15, 0x15,
	0x15, 0x15, 0x16, 0x16, 0x16, 0x16
};

static const uint32_t rtl8192ce_rf2_vals[] = {
	0x30159, 0x31284, 0x98000, 0x18c63, 0x210e7, 0x2044f, 0x1adb1,
	0x54867, 0x8992e, 0x0e52c, 0x39ce7, 0x00451, 0x32000, 0x71000,
	0xb0000, 0xfc000, 0x287af, 0x244b7, 0x204ab, 0x1c49f, 0x18493,
	0x14297, 0x10295, 0x0c298, 0x0819c, 0x040a8, 0x0001c, 0x1944c,
	0x59444, 0x9944c, 0xd9444, 0x0f424, 0x4f424, 0x8f424, 0xcf424,
	0xe0330, 0xa0330, 0x60330, 0x20330
};

static const struct rtwn_rf_prog rtl8192ce_rf[] = {
	/* RF chain 1 */
	{
		nitems(rtl8192ce_rf1_regs),
		rtl8192ce_rf1_regs,
		rtl8192ce_rf1_vals,
		{ 0 },
		NULL
	},
	{ 0, NULL, NULL, { 0 }, NULL },
	/* RF chain 2 */
	{
		nitems(rtl8192ce_rf2_regs),
		rtl8192ce_rf2_regs,
		rtl8192ce_rf2_vals,
		{ 0 },
		NULL
	},
	{ 0, NULL, NULL, { 0 }, NULL }
};


/*
 * RTL8188CE-VAU.
 */
static const uint32_t rtl8188ce_rf_vals[] = {
	0x30159, 0x31284, 0x98000, 0x18c63, 0x210e7, 0x2044f, 0x1adb1,
	0x54867, 0x8992e, 0x0e52c, 0x39ce7, 0x00451, 0x00000, 0x10255,
	0x60a00, 0xfc378, 0xa1250, 0x4445f, 0x80001, 0x0b614, 0x6c000,
	0x00000, 0x01558, 0x00060, 0x00483, 0x4f200, 0xec7d9, 0x577c0,
	0x04783, 0x00001, 0x21334, 0x00000, 0x00054, 0x00001, 0x00808,
	0x53333, 0x0000c, 0x00002, 0x00808, 0x5b333, 0x0000d, 0x00003,
	0x00808, 0x63333, 0x0000d, 0x00004, 0x00808, 0x6b333, 0x0000d,
	0x00005, 0x00808, 0x73333, 0x0000d, 0x00006, 0x00709, 0x5b333,
	0x0000d, 0x00007, 0x00709, 0x63333, 0x0000d, 0x00008, 0x0060a,
	0x4b333, 0x0000d, 0x00009, 0x0060a, 0x53333, 0x0000d, 0x0000a,
	0x0060a, 0x5b333, 0x0000d, 0x0000b, 0x0060a, 0x63333, 0x0000d,
	0x0000c, 0x0060a, 0x6b333, 0x0000d, 0x0000d, 0x0060a, 0x73333,
	0x0000d, 0x0000e, 0x0050b, 0x66666, 0x0001a, 0xe0000, 0x4000f,
	0xe31fc, 0x6000f, 0xff9f8, 0x2000f, 0x203f9, 0x3000f, 0xff500,
	0x00000, 0x00000, 0x8000f, 0x3f100, 0x9000f, 0x23100, 0x32000,
	0x71000, 0xb0000, 0xfc000, 0x287b3, 0x244b7, 0x204ab, 0x1c49f,
	0x18493, 0x1429b, 0x10299, 0x0c29c, 0x081a0, 0x040ac, 0x00020,
	0x1944c, 0x59444, 0x9944c, 0xd9444, 0x0f424, 0x4f424, 0x8f424,
	0xcf424, 0xe0330, 0xa0330, 0x60330, 0x20330, 0x10159, 0x0f401,
	0x0c350, 0x0c350, 0x80003, 0x0c350, 0x0c350, 0x44457, 0x80000,
	0x30159
};

static const struct rtwn_rf_prog rtl8188ce_rf[] = {
	{
		nitems(rtl8192ce_rf1_regs),
		rtl8192ce_rf1_regs,
		rtl8188ce_rf_vals,
		{ 0 },
		NULL
	},
	{ 0, NULL, NULL, { 0 }, NULL }
};


/*
 * RTL8188CU.
 */
static const uint32_t rtl8188cu_rf_vals[] = {
	0x30159, 0x31284, 0x98000, 0x18c63, 0x210e7, 0x2044f, 0x1adb1,
	0x54867, 0x8992e, 0x0e52c, 0x39ce7, 0x00451, 0x00000, 0x10255,
	0x60a00, 0xfc378, 0xa1250, 0x4445f, 0x80001, 0x0b614, 0x6c000,
	0x00000, 0x01558, 0x00060, 0x00483, 0x4f000, 0xec7d9, 0x577c0,
	0x04783, 0x00001, 0x21334, 0x00000, 0x00054, 0x00001, 0x00808,
	0x53333, 0x0000c, 0x00002, 0x00808, 0x5b333, 0x0000d, 0x00003,
	0x00808, 0x63333, 0x0000d, 0x00004, 0x00808, 0x6b333, 0x0000d,
	0x00005, 0x00808, 0x73333, 0x0000d, 0x00006, 0x00709, 0x5b333,
	0x0000d, 0x00007, 0x00709, 0x63333, 0x0000d, 0x00008, 0x0060a,
	0x4b333, 0x0000d, 0x00009, 0x0060a, 0x53333, 0x0000d, 0x0000a,
	0x0060a, 0x5b333, 0x0000d, 0x0000b, 0x0060a, 0x63333, 0x0000d,
	0x0000c, 0x0060a, 0x6b333, 0x0000d, 0x0000d, 0x0060a, 0x73333,
	0x0000d, 0x0000e, 0x0050b, 0x66666, 0x0001a, 0xe0000, 0x4000f,
	0xe31fc, 0x6000f, 0xff9f8, 0x2000f, 0x203f9, 0x3000f, 0xff500,
	0x00000, 0x00000, 0x8000f, 0x3f100, 0x9000f, 0x23100, 0x32000,
	0x71000, 0xb0000, 0xfc000, 0x287b3, 0x244b7, 0x204ab, 0x1c49f,
	0x18493, 0x1429b, 0x10299, 0x0c29c, 0x081a0, 0x040ac, 0x00020,
	0x1944c, 0x59444, 0x9944c, 0xd9444, 0x0f405, 0x4f405, 0x8f405,
	0xcf405, 0xe0330, 0xa0330, 0x60330, 0x20330, 0x10159, 0x0f401,
	0x0c350, 0x0c350, 0x80003, 0x0c350, 0x0c350, 0x44457, 0x80000,
	0x30159
};

static const struct rtwn_rf_prog rtl8188cu_rf[] = {
	{
		nitems(rtl8192ce_rf1_regs),
		rtl8192ce_rf1_regs,
		rtl8188cu_rf_vals,
		{ 0 },
		NULL
	},
	{ 0, NULL, NULL, { 0 }, NULL }
};


/*
 * RTL8188RU.
 */
static const uint32_t rtl8188ru_rf_vals[] = {
	0x30159, 0x31284, 0x98000, 0x18c63, 0x210e7, 0x2044f, 0x1adb0,
	0x54867, 0x8992e, 0x0e529, 0x39ce7, 0x00451, 0x00000, 0x00255,
	0x60a00, 0xfc378, 0xa1250, 0x4445f, 0x80001, 0x0b614, 0x6c000,
	0x0083c, 0x01558, 0x00060, 0x00483, 0x4f000, 0xec7d9, 0x977c0,
	0x04783, 0x00001, 0x21334, 0x00000, 0x00054, 0x00001, 0x00808,
	0x53333, 0x0000c, 0x00002, 0x00808, 0x5b333, 0x0000d, 0x00003,
	0x00808, 0x63333, 0x0000d, 0x00004, 0x00808, 0x6b333, 0x0000d,
	0x00005, 0x00808, 0x73333, 0x0000d, 0x00006, 0x00709, 0x5b333,
	0x0000d, 0x00007, 0x00709, 0x63333, 0x0000d, 0x00008, 0x0060a,
	0x4b333, 0x0000d, 0x00009, 0x0060a, 0x53333, 0x0000d, 0x0000a,
	0x0060a, 0x5b333, 0x0000d, 0x0000b, 0x0060a, 0x63333, 0x0000d,
	0x0000c, 0x0060a, 0x6b333, 0x0000d, 0x0000d, 0x0060a, 0x73333,
	0x0000d, 0x0000e, 0x0050b, 0x66666, 0x0001a, 0xe0000, 0x4000f,
	0xe31fc, 0x6000f, 0xff9f8, 0x2000f, 0x203f9, 0x3000f, 0xff500,
	0x00000, 0x00000, 0x8000f, 0x3f100, 0x9000f, 0x23100, 0xd8000,
	0x90000, 0x51000, 0x12000, 0x28fb4, 0x24fa8, 0x207a4, 0x1c798,
	0x183a4, 0x14398, 0x101a4, 0x0c198, 0x080a4, 0x04098, 0x00014,
	0x1944c, 0x59444, 0x9944c, 0xd9444, 0x0f405, 0x4f405, 0x8f405,
	0xcf405, 0xe0330, 0xa0330, 0x60330, 0x20330, 0x10159, 0x0f401,
	0x0c350, 0x0c350, 0x80003, 0x0c350, 0x0c350, 0x44457, 0x80000,
	0x30159
};

static const struct rtwn_rf_prog rtl8188ru_rf[] = {
	{
		nitems(rtl8192ce_rf1_regs),
		rtl8192ce_rf1_regs,
		rtl8188ru_rf_vals,
		{ 0 },
		NULL
	},
	{ 0, NULL, NULL, { 0 }, NULL }
};


struct rtwn_r92c_txagc {
	uint8_t	pwr[R92C_GROUP_2G][28];	/* RTWN_RIDX_MCS(15) + 1 */
};

/*
 * Per RF chain/group/rate Tx gain values.
 */
static const struct rtwn_r92c_txagc rtl8192cu_txagc[] = {
	{ {	/* Chain 0. */
	{	/* Group 0. */
	0x00, 0x00, 0x00, 0x00,				/* CCK1~11. */
	0x0c, 0x0c, 0x0c, 0x0a, 0x08, 0x06, 0x04, 0x02,	/* OFDM6~54. */
	0x0e, 0x0d, 0x0c, 0x0a, 0x08, 0x06, 0x04, 0x02,	/* MCS0~7. */
	0x0e, 0x0d, 0x0c, 0x0a, 0x08, 0x06, 0x04, 0x02	/* MCS8~15. */
	},
	{	/* Group 1. */
	0x00, 0x00, 0x00, 0x00,				/* CCK1~11. */
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,	/* OFDM6~54. */
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,	/* MCS0~7. */
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00	/* MCS8~15. */
	},
	{	/* Group 2. */
	0x00, 0x00, 0x00, 0x00,				/* CCK1~11. */
	0x04, 0x04, 0x04, 0x04, 0x04, 0x02, 0x02, 0x00,	/* OFDM6~54. */
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,	/* MCS0~7. */
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00	/* MCS8~15. */
	}
	} },
	{ {	/* Chain 1. */
	{	/* Group 0. */
	0x00, 0x00, 0x00, 0x00,				/* CCK1~11. */
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,	/* OFDM6~54. */
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,	/* MCS0~7. */
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00	/* MCS8~15. */
	},
	{	/* Group 1. */
	0x00, 0x00, 0x00, 0x00,				/* CCK1~11. */
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,	/* OFDM6~54. */
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,	/* MCS0~7. */
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00	/* MCS8~15. */
	},
	{	/* Group 2. */
	0x00, 0x00, 0x00, 0x00,				/* CCK1~11. */
	0x04, 0x04, 0x04, 0x04, 0x04, 0x02, 0x02, 0x00,	/* OFDM6~54. */
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,	/* MCS0~7. */
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00	/* MCS8~15. */
	}
	} }
};

static const struct rtwn_r92c_txagc rtl8188ru_txagc[] = {
	{ {	/* Chain 0. */
	{	/* Group 0. */
	0x00, 0x00, 0x00, 0x00,				/* CCK1~11. */
	0x08, 0x08, 0x08, 0x06, 0x06, 0x04, 0x04, 0x00,	/* OFDM6~54. */
	0x08, 0x06, 0x06, 0x04, 0x04, 0x02, 0x02, 0x00,	/* MCS0~7. */
	0x08, 0x06, 0x06, 0x04, 0x04, 0x02, 0x02, 0x00	/* MCS8~15. */
	},
	{	/* Group 1. */
	0x00, 0x00, 0x00, 0x00,				/* CCK1~11. */
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,	/* OFDM6~54. */
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,	/* MCS0~7. */
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00	/* MCS8~15. */
	},
	{	/* Group 2. */
	0x00, 0x00, 0x00, 0x00,				/* CCK1~11. */
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,	/* OFDM6~54. */
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,	/* MCS0~7. */
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00	/* MCS8~15. */
	}
	} }
};

#endif	/* R92C_PRIV_H */
