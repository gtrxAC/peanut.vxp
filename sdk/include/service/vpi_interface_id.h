/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2008
*
*  BY OPENING THIS FILE, BUYER HEREBY UNEQUIVOCALLY ACKNOWLEDGES AND AGREES
*  THAT THE SOFTWARE/FIRMWARE AND ITS DOCUMENTATIONS ("MEDIATEK SOFTWARE")
*  RECEIVED FROM MEDIATEK AND/OR ITS REPRESENTATIVES ARE PROVIDED TO BUYER ON
*  AN "AS-IS" BASIS ONLY. MEDIATEK EXPRESSLY DISCLAIMS ANY AND ALL WARRANTIES,
*  EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
*  MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE OR NONINFRINGEMENT.
*  NEITHER DOES MEDIATEK PROVIDE ANY WARRANTY WHATSOEVER WITH RESPECT TO THE
*  SOFTWARE OF ANY THIRD PARTY WHICH MAY BE USED BY, INCORPORATED IN, OR
*  SUPPLIED WITH THE MEDIATEK SOFTWARE, AND BUYER AGREES TO LOOK ONLY TO SUCH
*  THIRD PARTY FOR ANY WARRANTY CLAIM RELATING THERETO. MEDIATEK SHALL ALSO
*  NOT BE RESPONSIBLE FOR ANY MEDIATEK SOFTWARE RELEASES MADE TO BUYER'S
*  SPECIFICATION OR TO CONFORM TO A PARTICULAR STANDARD OR OPEN FORUM.
*
*  BUYER'S SOLE AND EXCLUSIVE REMEDY AND MEDIATEK'S ENTIRE AND CUMULATIVE
*  LIABILITY WITH RESPECT TO THE MEDIATEK SOFTWARE RELEASED HEREUNDER WILL BE,
*  AT MEDIATEK'S OPTION, TO REVISE OR REPLACE THE MEDIATEK SOFTWARE AT ISSUE,
*  OR REFUND ANY SOFTWARE LICENSE FEES OR SERVICE CHARGE PAID BY BUYER TO
*  MEDIATEK FOR SUCH MEDIATEK SOFTWARE AT ISSUE. 
*
*  THE TRANSACTION CONTEMPLATED HEREUNDER SHALL BE CONSTRUED IN ACCORDANCE
*  WITH THE LAWS OF THE STATE OF CALIFORNIA, USA, EXCLUDING ITS CONFLICT OF
*  LAWS PRINCIPLES. ANY DISPUTES, CONTROVERSIES OR CLAIMS ARISING THEREOF AND
*  RELATED THERETO SHALL BE SETTLED BY ARBITRATION IN SAN FRANCISCO, CA, UNDER
*  THE RULES OF THE INTERNATIONAL CHAMBER OF COMMERCE (ICC).
*
*****************************************************************************/

/*******************************************************************************
 * Filename:
 * ---------
 *  vpi_interface_id.h
 *
 * Project:
 * --------
 *  Venus Plug-in Core
 *
 * Description:
 * ------------
 *  
 *
 * Author:
 * -------
 *  Jun Liu (mtk80064)
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 * $Log$
 *
 * 07 13 2012 wei.fu
 * [MAUI_03180984] DLUI check-in
 * Document check in.
 *
 * 06 18 2012 wei.fu
 * [MAUI_03180984] DLUI check-in
 * Revise datatype.
 *
 * 05 30 2012 jun.liu
 * [MAUI_03053506] Plug-in check in
 * Check in owner draw enhancement for VPI
 * 1. Add VfxOwnerDrawWrapper, VfxOwnerDrawControl, VpiOwnerDrawControl
 * 2. Add VRT frame partial dirty
 *
 * 05 16 2012 jun.liu
 * [MAUI_03185603] Check in New animation image
 * .
 *
 * 04 20 2012 wei.fu
 * [MAUI_03053506] Plug-in check in
 * .
 *
 * 03 13 2012 stella.yang
 * [MAUI_03146398] [DLUI] VPI Check in
 * .
 *
 * 03 05 2012 siddhartha.saxena
 * [MAUI_02447108] [COSMOS IT BRANCH + 11A + MAUI] check-ins
 * VPI for indicator Popup.
 *
 * 02 25 2012 ankur.mathur
 * [MAUI_03107256] Checkins for MRE DLUI Settings CP
 * .
 *
 * 02 22 2012 wei.fu
 * [MAUI_03053506] Plug-in check in
 * .
 *
 * 02 13 2012 wei.fu
 * [MAUI_03053506] Plug-in check in
 * SAP check in.
 *
 * 02 10 2012 ch.ko
 * [MAUI_03109614] [DLUI] Check-in launcher, screen lock, and widget patches
 * Check-in launcher VPI.
 *
 * 01 13 2012 stella.yang
 * [MAUI_03117076] [DLUI] Screen Lock VPI
 * .
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef __VPI_INTERFACE_ID_H__
#define __VPI_INTERFACE_ID_H__

#include "gs_id.h"

/* DOM-NOT_FOR_SDK-BEGIN */

/***************************************************************************** 
 * VPI Engine
 *****************************************************************************/
#define IID_IVpiObjectFacroty               0xFF000001

#define IID_IVpiObject                      0xFF000002
#define IID_IVpiObjectDelegator             0xFF000003

#define IID_IVpiFrame                       0xFF000004
#define IID_IVpiFrameDelegator              0xFF000005

#define IID_IVpiControl                     0xFF000006
#define IID_IVpiControlDelegator            0xFF000007
#define IID_IVpiArchive                     0xFF000008

#define IID_IVpiImageFrame                  0xFF000009
#define IID_IVpiAnimImageFrame              0xFF00000A
#define IID_IVpiTextFrame                   0xFF00000B

#define IID_IVpiBaseTimeline                0xFF00000C
#define IID_IVpiS32Timeline                 0xFF00000D
#define IID_IVpiFloatTimeline               0xFF00000E
#define IID_IVpiColorTimeline               0xFF00000F
#define IID_IVpiPointTimeline               0xFF000010
#define IID_IVpiFPointTimeline              0xFF000011
#define IID_IVpiSizeTimeline                0xFF000012
#define IID_IVpiRectTimeline                0xFF000013
#define IID_IVpiTransformTimeline           0xFF000014

#define IID_IVpiTimer                       0xFF000015
#define IID_IVpiTimerStatic                 0xFF000016

#define IID_IVpiFrameFilter                 0xFF000017
#define IID_IVpiFrameFilterDelegator        0xFF000018

#define IID_IVpiOwnerDraw                   0xFF000019
#define IID_IVpiOwnerDrawDelegator          0xFF00001A

#define IID_IVpiOwnerDrawControl            0xFF00001B
#define IID_IVpiOwnerDrawControlDelegator   0xFF00001C

#define IID_IVpiScreen                      0xFF00001D

#define IID_IVpiBasePopup                   0xFF00001E
#define IID_IVpiBasePopupDelegator          0xFF00001F

#define IID_IVpiAsyncSignalQueue            0xFF000020

#define IID_IVpiAutoAnimate                 0xFF000021

#define IID_IVpiRenderer                    0xFF000022

#define IID_IVpiTopLevel                    0xFF000023

#define IID_IVpiFontDesc                    0xFF000024

#define IID_IVpiFontEffect                  0xFF000025

/***************************************************************************** 
 * VPI Engine
 *****************************************************************************/
#define IID_IVpiAppScr                      0xFF100001
#define IID_IVpiMainScr                     0xFF100002
#define IID_IVpiMainScrStatic               0xFF100003
#define IID_IVpiPage                        0xFF100004
#define IID_IVpiPageDelegator               0xFF100005
#define IID_IVpiPageTransition              0xFF100006
#define IID_IVpiPageTransitionDelegator     0xFF100007
#define IID_IVpiPageBar                     0xFF100008
#define IID_IVpiPageBarDelegator            0xFF100009

/***************************************************************************** 
 * Components
 *****************************************************************************/
#define IID_IVpiTextView                    0xFF200001
#define IID_IVpiTextEditor                  0xFF200002

#define IID_IVpiScrollable                  0xFF200003
#define IID_IVpiScrollableDelegator         0xFF200004
#define IID_IVpiScrollableView              0xFF200005
#define IID_IVpiScrollableViewDelegator     0xFF200006

#define IID_IVpiBaseMenu                    0xFF200007
#define IID_IVpiBaseMenuDelegator           0xFF200008
#define IID_IVpiBaseMenuLayout              0xFF200009
#define IID_IVpiBaseMenuLayoutDelegator     0xFF20000A

#define IID_IVpiConfirmPopup                0xFF20000B
#define IID_IVpiIndicatorPopup              0xFF20000C

#define IID_IVpiSettingsBasePage            0xFF20000D
#define IID_IVpiSettingsStandardPage        0xFF20000E
#define IID_IVpiSettingsSelListPage         0xFF20000F

#define IID_IVpiNotification                0xFF200010

/***************************************************************************** 
 * Application
 *****************************************************************************/
#define IID_IVpiWidget                      0xFF300001
#define IID_IVpiWidgetKit                   0xFF300002
#define IID_IVpiWidgetId                    0xFF300003
#define IID_IVpiWidgetProvider              0xFF300004
#define IID_IVpiWidgetProviderDelegator     0xFF300005

#define IID_IVpiLauncherProvider            0xFF300006
#define IID_IVpiLauncherProviderDelegator   0xFF300007

#define IID_IVpiScreenLockProvider          0xFF300008
#define IID_IVpiScreenLockProviderDelegator 0xFF300009

#define IID_IVpiWallpaperProvider           0xFF30000A
#define IID_IVpiWallpaperProviderDelegator  0xFF30000B
#define IID_IVpiWallpaper                   0xFF30000C
#define IID_IVpiWallpaperKit                0xFF30000D

/* DOM-NOT_FOR_SDK-END */

#endif /* __VPI_INTERFACE_ID_H__ */

