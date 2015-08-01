/******************************************************************************
 *
 * Copyright( c ) 2009-2014  Realtek Corporation.
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of version 2 of the GNU General Public License as
 * published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for
 * more details.
 *
 * The full GNU General Public License is included in this distribution in the
 * file called LICENSE.
 *
 * Contact Information:
 * wlanfae <wlanfae@realtek.com>
 * Realtek Corporation, No. 2, Innovation Road II, Hsinchu Science Park,
 * Hsinchu 300, Taiwan.
 *
 *
 * Bug Fixes and enhancements for Linux Kernels >= 3.2
 * by Benjamin Porter <BenjaminPorter86@gmail.com>
 *
 * Project homepage: https://github.com/FreedomBen/rtl8188ce-linux-driver
 *
 *
 * Larry Finger <Larry.Finger@lwfinger.net>
 *
 *****************************************************************************/

#ifndef __RTL8723BE_PWRSEQ_H__
#define __RTL8723BE_PWRSEQ_H__

/*	Check document WM-20130425-JackieLau-RTL8723B_Power_Architecture v05.vsd
 *	There are 6 HW Power States:
 *	0: POFF--Power Off
 *	1: PDN--Power Down
 *	2: CARDEMU--Card Emulation
 *	3: ACT--Active Mode
 *	4: LPS--Low Power State
 *	5: SUS--Suspend
 *
 *	The transition from different states are defined below
 *	TRANS_CARDEMU_TO_ACT
 *	TRANS_ACT_TO_CARDEMU
 *	TRANS_CARDEMU_TO_SUS
 *	TRANS_SUS_TO_CARDEMU
 *	TRANS_CARDEMU_TO_PDN
 *	TRANS_ACT_TO_LPS
 *	TRANS_LPS_TO_ACT
 *
 *	TRANS_END
 */
#define	RTL8723B_TRANS_CARDEMU_TO_ACT_STEPS	23
#define	RTL8723B_TRANS_ACT_TO_CARDEMU_STEPS	15
#define	RTL8723B_TRANS_CARDEMU_TO_SUS_STEPS	15
#define	RTL8723B_TRANS_SUS_TO_CARDEMU_STEPS	15
#define	RTL8723B_TRANS_CARDEMU_TO_PDN_STEPS	15
#define	RTL8723B_TRANS_PDN_TO_CARDEMU_STEPS	15
#define	RTL8723B_TRANS_ACT_TO_LPS_STEPS		15
#define	RTL8723B_TRANS_LPS_TO_ACT_STEPS		15
#define	RTL8723B_TRANS_END_STEPS		1

#define RTL8723B_TRANS_CARDEMU_TO_ACT					\
	{0x0020, PWR_CUT_ALL_MSK, PWR_FAB_ALL_MSK,			\
	 PWR_INTF_USB_MSK | PWR_INTF_SDIO_MSK,				\
	 PWR_BASEADDR_MAC, PWR_CMD_WRITE, BIT( 0 ), BIT( 0 )},		\
	{0x0067, PWR_CUT_ALL_MSK, PWR_FAB_ALL_MSK,			\
	 PWR_INTF_USB_MSK | PWR_INTF_SDIO_MSK,				\
	 PWR_BASEADDR_MAC, PWR_CMD_WRITE, BIT( 4 ), 0},			\
	{0x0001, PWR_CUT_ALL_MSK, PWR_FAB_ALL_MSK,			\
	 PWR_INTF_USB_MSK | PWR_INTF_SDIO_MSK,				\
	 PWR_BASEADDR_MAC, PWR_CMD_DELAY, 1, PWRSEQ_DELAY_MS},		\
	{0x0000, PWR_CUT_ALL_MSK, PWR_FAB_ALL_MSK,			\
	 PWR_INTF_USB_MSK | PWR_INTF_SDIO_MSK,				\
	 PWR_BASEADDR_MAC, PWR_CMD_WRITE, BIT( 5 ), 0},			\
	{0x0005, PWR_CUT_ALL_MSK, PWR_FAB_ALL_MSK, PWR_INTF_ALL_MSK,	\
	 PWR_BASEADDR_MAC, PWR_CMD_WRITE, ( BIT( 4 )|BIT( 3 )|BIT( 2 ) ), 0},	\
	{0x0075, PWR_CUT_ALL_MSK, PWR_FAB_ALL_MSK, PWR_INTF_PCI_MSK,	\
	 PWR_BASEADDR_MAC, PWR_CMD_WRITE, BIT( 0 ) , 0},			\
	{0x0006, PWR_CUT_ALL_MSK, PWR_FAB_ALL_MSK, PWR_INTF_ALL_MSK,	\
	 PWR_BASEADDR_MAC, PWR_CMD_POLLING, BIT( 1 ), BIT( 1 )},		\
	{0x0075, PWR_CUT_ALL_MSK, PWR_FAB_ALL_MSK, PWR_INTF_PCI_MSK,	\
	 PWR_BASEADDR_MAC, PWR_CMD_WRITE, BIT( 0 ) , BIT( 0 )},		\
	{0x0006, PWR_CUT_ALL_MSK, PWR_FAB_ALL_MSK, PWR_INTF_ALL_MSK,	\
	 PWR_BASEADDR_MAC, PWR_CMD_WRITE, BIT( 0 ), BIT( 0 )},		\
	{0x0005, PWR_CUT_ALL_MSK, PWR_FAB_ALL_MSK, PWR_INTF_ALL_MSK,	\
	 PWR_BASEADDR_MAC, PWR_CMD_WRITE, BIT( 7 ), 0},			\
	{0x0005, PWR_CUT_ALL_MSK, PWR_FAB_ALL_MSK, PWR_INTF_ALL_MSK,	\
	 PWR_BASEADDR_MAC, PWR_CMD_WRITE, ( BIT( 4 )|BIT( 3 ) ), 0},		\
	{0x0005, PWR_CUT_ALL_MSK, PWR_FAB_ALL_MSK, PWR_INTF_ALL_MSK,	\
	 PWR_BASEADDR_MAC, PWR_CMD_WRITE, BIT( 0 ), BIT( 0 )},		\
	{0x0005, PWR_CUT_ALL_MSK, PWR_FAB_ALL_MSK, PWR_INTF_ALL_MSK,	\
	 PWR_BASEADDR_MAC, PWR_CMD_POLLING, BIT( 0 ), 0},			\
	{0x0010, PWR_CUT_ALL_MSK, PWR_FAB_ALL_MSK, PWR_INTF_ALL_MSK,	\
	 PWR_BASEADDR_MAC, PWR_CMD_WRITE, BIT( 6 ), BIT( 6 )},		\
	{0x0049, PWR_CUT_ALL_MSK, PWR_FAB_ALL_MSK, PWR_INTF_ALL_MSK,	\
	 PWR_BASEADDR_MAC, PWR_CMD_WRITE, BIT( 1 ), BIT( 1 )},		\
	{0x0063, PWR_CUT_ALL_MSK, PWR_FAB_ALL_MSK, PWR_INTF_ALL_MSK,	\
	 PWR_BASEADDR_MAC, PWR_CMD_WRITE, BIT( 1 ), BIT( 1 )},		\
	{0x0062, PWR_CUT_ALL_MSK, PWR_FAB_ALL_MSK, PWR_INTF_ALL_MSK,	\
	 PWR_BASEADDR_MAC, PWR_CMD_WRITE, BIT( 1 ), 0},			\
	{0x0058, PWR_CUT_ALL_MSK, PWR_FAB_ALL_MSK, PWR_INTF_ALL_MSK,	\
	 PWR_BASEADDR_MAC, PWR_CMD_WRITE, BIT( 0 ), BIT( 0 )},		\
	{0x005A, PWR_CUT_ALL_MSK, PWR_FAB_ALL_MSK, PWR_INTF_ALL_MSK,	\
	 PWR_BASEADDR_MAC, PWR_CMD_WRITE, BIT( 1 ), BIT( 1 )},		\
	{0x0068, PWR_CUT_TESTCHIP_MSK, PWR_FAB_ALL_MSK, PWR_INTF_ALL_MSK,\
	 PWR_BASEADDR_MAC, PWR_CMD_WRITE, BIT( 3 ), BIT( 3 )},		\
	{0x0069, PWR_CUT_ALL_MSK, PWR_FAB_ALL_MSK, PWR_INTF_ALL_MSK,	\
	 PWR_BASEADDR_MAC, PWR_CMD_WRITE, BIT( 6 ), BIT( 6 )},

#define RTL8723B_TRANS_ACT_TO_CARDEMU					\
	{0x001F, PWR_CUT_ALL_MSK, PWR_FAB_ALL_MSK, PWR_INTF_ALL_MSK,	\
	 PWR_BASEADDR_MAC, PWR_CMD_WRITE, 0xFF, 0},			\
	{0x004F, PWR_CUT_ALL_MSK, PWR_FAB_ALL_MSK, PWR_INTF_ALL_MSK,	\
	 PWR_BASEADDR_MAC, PWR_CMD_WRITE, BIT( 0 ), 0},			\
	{0x0049, PWR_CUT_ALL_MSK, PWR_FAB_ALL_MSK, PWR_INTF_ALL_MSK,	\
	 PWR_BASEADDR_MAC, PWR_CMD_WRITE, BIT( 1 ), 0},			\
	{0x0005, PWR_CUT_ALL_MSK, PWR_FAB_ALL_MSK, PWR_INTF_ALL_MSK,	\
	 PWR_BASEADDR_MAC, PWR_CMD_WRITE, BIT( 1 ), BIT( 1 )},		\
	{0x0005, PWR_CUT_ALL_MSK, PWR_FAB_ALL_MSK, PWR_INTF_ALL_MSK,	\
	 PWR_BASEADDR_MAC, PWR_CMD_POLLING, BIT( 1 ), 0},			\
	{0x0010, PWR_CUT_ALL_MSK, PWR_FAB_ALL_MSK, PWR_INTF_ALL_MSK,	\
	 PWR_BASEADDR_MAC, PWR_CMD_WRITE, BIT( 6 ), 0},			\
	{0x0000, PWR_CUT_ALL_MSK, PWR_FAB_ALL_MSK,			\
	 PWR_INTF_USB_MSK | PWR_INTF_SDIO_MSK, PWR_BASEADDR_MAC,	\
	 PWR_CMD_WRITE, BIT( 5 ), BIT( 5 )},				\
	{0x0020, PWR_CUT_ALL_MSK, PWR_FAB_ALL_MSK,			\
	 PWR_INTF_USB_MSK | PWR_INTF_SDIO_MSK, PWR_BASEADDR_MAC,	\
	 PWR_CMD_WRITE, BIT( 0 ), 0},

#define RTL8723B_TRANS_CARDEMU_TO_SUS					\
	{0x0005, PWR_CUT_ALL_MSK, PWR_FAB_ALL_MSK, PWR_INTF_PCI_MSK,	\
	 PWR_BASEADDR_MAC, PWR_CMD_WRITE, BIT( 4 ) | BIT( 3 ), ( BIT( 4 ) | BIT( 3 ) )}, \
	{0x0005, PWR_CUT_ALL_MSK, PWR_FAB_ALL_MSK,			\
	 PWR_INTF_USB_MSK | PWR_INTF_SDIO_MSK, PWR_BASEADDR_MAC,	\
	 PWR_CMD_WRITE, BIT( 3 ) | BIT( 4 ), BIT( 3 )},			\
	{0x0023, PWR_CUT_ALL_MSK, PWR_FAB_ALL_MSK, PWR_INTF_SDIO_MSK,	\
	 PWR_BASEADDR_MAC, PWR_CMD_WRITE, BIT( 4 ), BIT( 4 )},		\
	{0x0007, PWR_CUT_ALL_MSK, PWR_FAB_ALL_MSK, PWR_INTF_SDIO_MSK,	\
	 PWR_BASEADDR_MAC, PWR_CMD_WRITE, 0xFF, 0x20},			\
	{0x0005, PWR_CUT_ALL_MSK, PWR_FAB_ALL_MSK, PWR_INTF_PCI_MSK,	\
	 PWR_BASEADDR_MAC, PWR_CMD_WRITE, BIT( 3 ) | BIT( 4 ), BIT( 3 ) | BIT( 4 )},\
	{0x0086, PWR_CUT_ALL_MSK, PWR_FAB_ALL_MSK, PWR_INTF_SDIO_MSK,	\
	 PWR_BASEADDR_SDIO, PWR_CMD_WRITE, BIT( 0 ), BIT( 0 )},		\
	{0x0086, PWR_CUT_ALL_MSK, PWR_FAB_ALL_MSK, PWR_INTF_SDIO_MSK,	\
	 PWR_BASEADDR_SDIO, PWR_CMD_POLLING, BIT( 1 ), 0},

#define RTL8723B_TRANS_SUS_TO_CARDEMU					\
	{0x0005, PWR_CUT_ALL_MSK, PWR_FAB_ALL_MSK, PWR_INTF_ALL_MSK,	\
	 PWR_BASEADDR_MAC, PWR_CMD_WRITE, BIT( 3 ) | BIT( 7 ), 0},		\
	{0x0086, PWR_CUT_ALL_MSK, PWR_FAB_ALL_MSK, PWR_INTF_SDIO_MSK,	\
	 PWR_BASEADDR_SDIO, PWR_CMD_WRITE, BIT( 0 ), 0},			\
	{0x0086, PWR_CUT_ALL_MSK, PWR_FAB_ALL_MSK, PWR_INTF_SDIO_MSK,	\
	 PWR_BASEADDR_SDIO, PWR_CMD_POLLING, BIT( 1 ), BIT( 1 )},		\
	{0x0023, PWR_CUT_ALL_MSK, PWR_FAB_ALL_MSK, PWR_INTF_SDIO_MSK,	\
	 PWR_BASEADDR_MAC, PWR_CMD_WRITE, BIT( 4 ), 0},			\
	{0x0005, PWR_CUT_ALL_MSK, PWR_FAB_ALL_MSK, PWR_INTF_ALL_MSK,	\
	 PWR_BASEADDR_MAC, PWR_CMD_WRITE, BIT( 3 )|BIT( 4 ), 0},

#define RTL8723B_TRANS_CARDEMU_TO_CARDDIS				\
	{0x0007, PWR_CUT_ALL_MSK, PWR_FAB_ALL_MSK, PWR_INTF_SDIO_MSK,	\
	 PWR_BASEADDR_MAC, PWR_CMD_WRITE, 0xFF, 0x20},			\
	{0x0005, PWR_CUT_ALL_MSK, PWR_FAB_ALL_MSK,			\
	 PWR_INTF_USB_MSK | PWR_INTF_SDIO_MSK,				\
	 PWR_BASEADDR_MAC, PWR_CMD_WRITE, BIT( 3 )|BIT( 4 ), BIT( 3 )},	\
	{0x0005, PWR_CUT_ALL_MSK, PWR_FAB_ALL_MSK, PWR_INTF_PCI_MSK,	\
	 PWR_BASEADDR_MAC, PWR_CMD_WRITE, BIT( 2 ), BIT( 2 )},		\
	{0x004A, PWR_CUT_ALL_MSK, PWR_FAB_ALL_MSK, PWR_INTF_USB_MSK,	\
	 PWR_BASEADDR_MAC, PWR_CMD_WRITE, BIT( 0 ), 1},			\
	{0x0023, PWR_CUT_ALL_MSK, PWR_FAB_ALL_MSK, PWR_INTF_SDIO_MSK,	\
	 PWR_BASEADDR_MAC, PWR_CMD_WRITE, BIT( 4 ), BIT( 4 )},		\
	{0x0086, PWR_CUT_ALL_MSK, PWR_FAB_ALL_MSK, PWR_INTF_SDIO_MSK,	\
	 PWR_BASEADDR_SDIO, PWR_CMD_WRITE, BIT( 0 ), BIT( 0 )},		\
	{0x0086, PWR_CUT_ALL_MSK, PWR_FAB_ALL_MSK, PWR_INTF_SDIO_MSK,	\
	 PWR_BASEADDR_SDIO, PWR_CMD_POLLING, BIT( 1 ), 0},

#define RTL8723B_TRANS_CARDDIS_TO_CARDEMU				\
	{0x0005, PWR_CUT_ALL_MSK, PWR_FAB_ALL_MSK, PWR_INTF_ALL_MSK,	\
	 PWR_BASEADDR_MAC, PWR_CMD_WRITE, BIT( 3 ) | BIT( 7 ), 0},		\
	{0x0086, PWR_CUT_ALL_MSK, PWR_FAB_ALL_MSK, PWR_INTF_SDIO_MSK,	\
	 PWR_BASEADDR_SDIO, PWR_CMD_WRITE, BIT( 0 ), 0},			\
	{0x0086, PWR_CUT_ALL_MSK, PWR_FAB_ALL_MSK, PWR_INTF_SDIO_MSK,	\
	 PWR_BASEADDR_SDIO, PWR_CMD_POLLING, BIT( 1 ), BIT( 1 )},		\
	{0x004A, PWR_CUT_ALL_MSK, PWR_FAB_ALL_MSK, PWR_INTF_USB_MSK,	\
	 PWR_BASEADDR_MAC, PWR_CMD_WRITE, BIT( 0 ), 0},			\
	{0x0005, PWR_CUT_ALL_MSK, PWR_FAB_ALL_MSK, PWR_INTF_ALL_MSK,	\
	 PWR_BASEADDR_MAC, PWR_CMD_WRITE, BIT( 3 )|BIT( 4 ), 0},		\
	{0x0023, PWR_CUT_ALL_MSK, PWR_FAB_ALL_MSK, PWR_INTF_SDIO_MSK,	\
	 PWR_BASEADDR_MAC, PWR_CMD_WRITE, BIT( 4 ), 0},			\
	{0x0301, PWR_CUT_ALL_MSK, PWR_FAB_ALL_MSK, PWR_INTF_PCI_MSK,	\
	 PWR_BASEADDR_MAC, PWR_CMD_WRITE, 0xFF, 0},

#define RTL8723B_TRANS_CARDEMU_TO_PDN					\
	{0x0023, PWR_CUT_ALL_MSK, PWR_FAB_ALL_MSK, PWR_INTF_SDIO_MSK,	\
	 PWR_BASEADDR_MAC, PWR_CMD_WRITE, BIT( 4 ), BIT( 4 )},		\
	{0x0007, PWR_CUT_ALL_MSK, PWR_FAB_ALL_MSK,			\
	 PWR_INTF_SDIO_MSK | PWR_INTF_USB_MSK, PWR_BASEADDR_MAC,	\
	 PWR_CMD_WRITE, 0xFF, 0x20},					\
	{0x0006, PWR_CUT_ALL_MSK, PWR_FAB_ALL_MSK, PWR_INTF_ALL_MSK,	\
	 PWR_BASEADDR_MAC, PWR_CMD_WRITE, BIT( 0 ), 0},			\
	{0x0005, PWR_CUT_ALL_MSK, PWR_FAB_ALL_MSK, PWR_INTF_ALL_MSK,	\
	 PWR_BASEADDR_MAC, PWR_CMD_WRITE, BIT( 7 ), BIT( 7 )},

#define RTL8723B_TRANS_PDN_TO_CARDEMU					\
	{0x0005, PWR_CUT_ALL_MSK, PWR_FAB_ALL_MSK, PWR_INTF_ALL_MSK,	\
	 PWR_BASEADDR_MAC, PWR_CMD_WRITE, BIT( 7 ), 0},

#define RTL8723B_TRANS_ACT_TO_LPS					\
	{0x0301, PWR_CUT_ALL_MSK, PWR_FAB_ALL_MSK, PWR_INTF_PCI_MSK,	\
	 PWR_BASEADDR_MAC, PWR_CMD_WRITE, 0xFF, 0xFF},			\
	{0x0522, PWR_CUT_ALL_MSK, PWR_FAB_ALL_MSK, PWR_INTF_ALL_MSK,	\
	 PWR_BASEADDR_MAC, PWR_CMD_WRITE, 0xFF, 0xFF},			\
	{0x05F8, PWR_CUT_ALL_MSK, PWR_FAB_ALL_MSK, PWR_INTF_ALL_MSK,	\
	 PWR_BASEADDR_MAC, PWR_CMD_POLLING, 0xFF, 0},			\
	{0x05F9, PWR_CUT_ALL_MSK, PWR_FAB_ALL_MSK, PWR_INTF_ALL_MSK,	\
	 PWR_BASEADDR_MAC, PWR_CMD_POLLING, 0xFF, 0},			\
	{0x05FA, PWR_CUT_ALL_MSK, PWR_FAB_ALL_MSK, PWR_INTF_ALL_MSK,	\
	 PWR_BASEADDR_MAC, PWR_CMD_POLLING, 0xFF, 0},			\
	{0x05FB, PWR_CUT_ALL_MSK, PWR_FAB_ALL_MSK, PWR_INTF_ALL_MSK,	\
	 PWR_BASEADDR_MAC, PWR_CMD_POLLING, 0xFF, 0},			\
	{0x0002, PWR_CUT_ALL_MSK, PWR_FAB_ALL_MSK, PWR_INTF_ALL_MSK,	\
	 PWR_BASEADDR_MAC, PWR_CMD_WRITE, BIT( 0 ), 0},			\
	{0x0002, PWR_CUT_ALL_MSK, PWR_FAB_ALL_MSK, PWR_INTF_ALL_MSK,	\
	 PWR_BASEADDR_MAC, PWR_CMD_DELAY, 0, PWRSEQ_DELAY_US},		\
	{0x0002, PWR_CUT_ALL_MSK, PWR_FAB_ALL_MSK, PWR_INTF_ALL_MSK,	\
	 PWR_BASEADDR_MAC, PWR_CMD_WRITE, BIT( 1 ), 0},			\
	{0x0100, PWR_CUT_ALL_MSK, PWR_FAB_ALL_MSK, PWR_INTF_ALL_MSK,	\
	 PWR_BASEADDR_MAC, PWR_CMD_WRITE, 0xFF, 0x03},			\
	{0x0101, PWR_CUT_ALL_MSK, PWR_FAB_ALL_MSK, PWR_INTF_ALL_MSK,	\
	 PWR_BASEADDR_MAC, PWR_CMD_WRITE, BIT( 1 ), 0},			\
	{0x0093, PWR_CUT_ALL_MSK, PWR_FAB_ALL_MSK, PWR_INTF_SDIO_MSK,	\
	 PWR_BASEADDR_MAC, PWR_CMD_WRITE, 0xFF, 0x00},			\
	{0x0553, PWR_CUT_ALL_MSK, PWR_FAB_ALL_MSK, PWR_INTF_ALL_MSK,	\
	 PWR_BASEADDR_MAC, PWR_CMD_WRITE, BIT( 5 ), BIT( 5 )},

#define RTL8723B_TRANS_LPS_TO_ACT					\
	{0x0080, PWR_CUT_ALL_MSK, PWR_FAB_ALL_MSK, PWR_INTF_SDIO_MSK,	\
	 PWR_BASEADDR_SDIO, PWR_CMD_WRITE, 0xFF, 0x84},		\
	{0xFE58, PWR_CUT_ALL_MSK, PWR_FAB_ALL_MSK, PWR_INTF_USB_MSK,	\
	 PWR_BASEADDR_MAC, PWR_CMD_WRITE, 0xFF, 0x84},			\
	{0x0361, PWR_CUT_ALL_MSK, PWR_FAB_ALL_MSK, PWR_INTF_PCI_MSK,	\
	 PWR_BASEADDR_MAC, PWR_CMD_WRITE, 0xFF, 0x84},			\
	{0x0002, PWR_CUT_ALL_MSK, PWR_FAB_ALL_MSK, PWR_INTF_ALL_MSK,	\
	 PWR_BASEADDR_MAC, PWR_CMD_DELAY, 0, PWRSEQ_DELAY_MS},		\
	{0x0008, PWR_CUT_ALL_MSK, PWR_FAB_ALL_MSK, PWR_INTF_ALL_MSK,	\
	 PWR_BASEADDR_MAC, PWR_CMD_WRITE, BIT( 4 ), 0},			\
	{0x0109, PWR_CUT_ALL_MSK, PWR_FAB_ALL_MSK, PWR_INTF_ALL_MSK,	\
	 PWR_BASEADDR_MAC, PWR_CMD_POLLING, BIT( 7 ), 0},		\
	{0x0029, PWR_CUT_ALL_MSK, PWR_FAB_ALL_MSK, PWR_INTF_ALL_MSK,	\
	 PWR_BASEADDR_MAC, PWR_CMD_WRITE, BIT( 6 )|BIT( 7 ), 0},		\
	{0x0101, PWR_CUT_ALL_MSK, PWR_FAB_ALL_MSK, PWR_INTF_ALL_MSK,	\
	 PWR_BASEADDR_MAC, PWR_CMD_WRITE, BIT( 1 ), BIT( 1 )},		\
	{0x0100, PWR_CUT_ALL_MSK, PWR_FAB_ALL_MSK, PWR_INTF_ALL_MSK,	\
	 PWR_BASEADDR_MAC, PWR_CMD_WRITE, 0xFF, 0xFF},			\
	{0x0002, PWR_CUT_ALL_MSK, PWR_FAB_ALL_MSK, PWR_INTF_ALL_MSK,	\
	 PWR_BASEADDR_MAC, PWR_CMD_WRITE, BIT( 1 ) | BIT( 0 ), BIT( 1 ) | BIT( 0 )}, \
	{0x0522, PWR_CUT_ALL_MSK, PWR_FAB_ALL_MSK, PWR_INTF_ALL_MSK,	\
	 PWR_BASEADDR_MAC, PWR_CMD_WRITE, 0xFF, 0},

#define RTL8723B_TRANS_END						\
	{0xFFFF, PWR_CUT_ALL_MSK, PWR_FAB_ALL_MSK, PWR_INTF_ALL_MSK, 0,	\
	 PWR_CMD_END, 0, 0},

extern struct wlan_pwr_cfg rtl8723B_power_on_flow
				[RTL8723B_TRANS_CARDEMU_TO_ACT_STEPS +
				 RTL8723B_TRANS_END_STEPS];
extern struct wlan_pwr_cfg rtl8723B_radio_off_flow
				[RTL8723B_TRANS_ACT_TO_CARDEMU_STEPS +
				 RTL8723B_TRANS_END_STEPS];
extern struct wlan_pwr_cfg rtl8723B_card_disable_flow
				[RTL8723B_TRANS_ACT_TO_CARDEMU_STEPS +
				 RTL8723B_TRANS_CARDEMU_TO_PDN_STEPS +
				 RTL8723B_TRANS_END_STEPS];
extern struct wlan_pwr_cfg rtl8723B_card_enable_flow
				[RTL8723B_TRANS_ACT_TO_CARDEMU_STEPS +
				 RTL8723B_TRANS_CARDEMU_TO_PDN_STEPS +
				 RTL8723B_TRANS_END_STEPS];
extern struct wlan_pwr_cfg rtl8723B_suspend_flow
				[RTL8723B_TRANS_ACT_TO_CARDEMU_STEPS +
				 RTL8723B_TRANS_CARDEMU_TO_SUS_STEPS +
				 RTL8723B_TRANS_END_STEPS];
extern struct wlan_pwr_cfg rtl8723B_resume_flow
				[RTL8723B_TRANS_ACT_TO_CARDEMU_STEPS +
				 RTL8723B_TRANS_CARDEMU_TO_SUS_STEPS +
				 RTL8723B_TRANS_END_STEPS];
extern struct wlan_pwr_cfg rtl8723B_hwpdn_flow
				[RTL8723B_TRANS_ACT_TO_CARDEMU_STEPS +
				 RTL8723B_TRANS_CARDEMU_TO_PDN_STEPS +
				 RTL8723B_TRANS_END_STEPS];
extern struct wlan_pwr_cfg rtl8723B_enter_lps_flow
				[RTL8723B_TRANS_ACT_TO_LPS_STEPS +
				 RTL8723B_TRANS_END_STEPS];
extern struct wlan_pwr_cfg rtl8723B_leave_lps_flow
				[RTL8723B_TRANS_LPS_TO_ACT_STEPS +
				 RTL8723B_TRANS_END_STEPS];

/* RTL8723 Power Configuration CMDs for PCIe interface */
#define RTL8723_NIC_PWR_ON_FLOW		rtl8723B_power_on_flow
#define RTL8723_NIC_RF_OFF_FLOW		rtl8723B_radio_off_flow
#define RTL8723_NIC_DISABLE_FLOW	rtl8723B_card_disable_flow
#define RTL8723_NIC_ENABLE_FLOW		rtl8723B_card_enable_flow
#define RTL8723_NIC_SUSPEND_FLOW	rtl8723B_suspend_flow
#define RTL8723_NIC_RESUME_FLOW		rtl8723B_resume_flow
#define RTL8723_NIC_PDN_FLOW		rtl8723B_hwpdn_flow
#define RTL8723_NIC_LPS_ENTER_FLOW	rtl8723B_enter_lps_flow
#define RTL8723_NIC_LPS_LEAVE_FLOW	rtl8723B_leave_lps_flow

#endif
