/*******************************************************************************
 * XEOS - X86 Experimental Operating System
 * 
 * Copyright (c) 2010-2013, Jean-David Gadina - www.xs-labs.com
 * All rights reserved.
 * 
 * XEOS Software License - Version 1.0 - December 21, 2012
 * 
 * Permission is hereby granted, free of charge, to any person or organisation
 * obtaining a copy of the software and accompanying documentation covered by
 * this license (the "Software") to deal in the Software, with or without
 * modification, without restriction, including without limitation the rights
 * to use, execute, display, copy, reproduce, transmit, publish, distribute,
 * modify, merge, prepare derivative works of the Software, and to permit
 * third-parties to whom the Software is furnished to do so, all subject to the
 * following conditions:
 * 
 *      1.  Redistributions of source code, in whole or in part, must retain the
 *          above copyright notice and this entire statement, including the
 *          above license grant, this restriction and the following disclaimer.
 * 
 *      2.  Redistributions in binary form must reproduce the above copyright
 *          notice and this entire statement, including the above license grant,
 *          this restriction and the following disclaimer in the documentation
 *          and/or other materials provided with the distribution, unless the
 *          Software is distributed by the copyright owner as a library.
 *          A "library" means a collection of software functions and/or data
 *          prepared so as to be conveniently linked with application programs
 *          (which use some of those functions and data) to form executables.
 * 
 *      3.  The Software, or any substancial portion of the Software shall not
 *          be combined, included, derived, or linked (statically or
 *          dynamically) with software or libraries licensed under the terms
 *          of any GNU software license, including, but not limited to, the GNU
 *          General Public License (GNU/GPL) or the GNU Lesser General Public
 *          License (GNU/LGPL).
 * 
 *      4.  All advertising materials mentioning features or use of this
 *          software must display an acknowledgement stating that the product
 *          includes software developed by the copyright owner.
 * 
 *      5.  Neither the name of the copyright owner nor the names of its
 *          contributors may be used to endorse or promote products derived from
 *          this software without specific prior written permission.
 * 
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT OWNER AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE, TITLE AND NON-INFRINGEMENT ARE DISCLAIMED.
 * 
 * IN NO EVENT SHALL THE COPYRIGHT OWNER, CONTRIBUTORS OR ANYONE DISTRIBUTING
 * THE SOFTWARE BE LIABLE FOR ANY CLAIM, DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
 * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN ACTION OF CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
 * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF OR IN CONNECTION WITH
 * THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE, EVEN IF ADVISED
 * OF THE POSSIBILITY OF SUCH DAMAGE.
 ******************************************************************************/

/* $Id$ */

/*!
 * @header          atomic.h
 * @author          Jean-David Gadina
 * @copyright       (c) 2010-2013, Jean-David Gadina - www.xs-labs.com
 */

#ifndef __XEOS_LIB_SYSTEM_LOCALE_H__
#define __XEOS_LIB_SYSTEM_LOCALE_H__

#include <stdbool.h>
#include <system/types/locale_t.h>

typedef struct __System_Locale_Collate   * System_Locale_CollateRef;
typedef struct __System_Locale_CType     * System_Locale_CTypeRef;
typedef struct __System_Locale_Messages  * System_Locale_MessagesRef;
typedef struct __System_Locale_Monetary  * System_Locale_MonetaryRef;
typedef struct __System_Locale_Numeric   * System_Locale_NumericRef;
typedef struct __System_Locale_Time      * System_Locale_TimeRef;

typedef struct __System_Locale * System_LocaleRef;

System_LocaleRef System_Locale_GetCurrentLocale( void );
System_LocaleRef System_Locale_GetDefaultLocale( void );
System_LocaleRef System_Locale_GetCLocale( void );
System_LocaleRef System_Locale_GetPOSIXLocale( void );
System_LocaleRef System_Locale_GetLocale( const char * name );
char           * System_Locale_SetLocale( int category, const char * name );
struct lconv   * System_Locale_GetLConv( void );
System_LocaleRef System_Locale_Create( int categoryMask, const char * name, System_LocaleRef base );

System_LocaleRef System_Locale_Use( System_LocaleRef locale );
void             System_Locale_Free( System_LocaleRef locale );
System_LocaleRef System_Locale_Duplicate( System_LocaleRef locale );

System_Locale_CollateRef  System_Locale_GetCollate( System_LocaleRef locale );
System_Locale_CTypeRef    System_Locale_GetCType( System_LocaleRef locale );
System_Locale_MessagesRef System_Locale_GetMessages( System_LocaleRef locale );
System_Locale_MonetaryRef System_Locale_GetMonetary( System_LocaleRef locale );
System_Locale_NumericRef  System_Locale_GetNumeric( System_LocaleRef locale );
System_Locale_TimeRef     System_Locale_GetTime( System_LocaleRef locale );

bool System_Locale_CType_IsAlphaNumeric( System_Locale_CTypeRef ctype, int c );
bool System_Locale_CType_IsAlpha( System_Locale_CTypeRef ctype, int c );
bool System_Locale_CType_IsBlank( System_Locale_CTypeRef ctype, int c );
bool System_Locale_CType_IsControl( System_Locale_CTypeRef ctype, int c );
bool System_Locale_CType_IsDigit( System_Locale_CTypeRef ctype, int c );
bool System_Locale_CType_IsGraph( System_Locale_CTypeRef ctype, int c );
bool System_Locale_CType_IsLower( System_Locale_CTypeRef ctype, int c );
bool System_Locale_CType_IsPrint( System_Locale_CTypeRef ctype, int c );
bool System_Locale_CType_IsPunct( System_Locale_CTypeRef ctype, int c );
bool System_Locale_CType_IsSpace( System_Locale_CTypeRef ctype, int c );
bool System_Locale_CType_IsUpper( System_Locale_CTypeRef ctype, int c );
bool System_Locale_CType_IsXDigit( System_Locale_CTypeRef ctype, int c );
bool System_Locale_CType_IsASCII( System_Locale_CTypeRef ctype, int c );
int  System_Locale_CType_ToLower( System_Locale_CTypeRef ctype, int c );
int  System_Locale_CType_ToUpper( System_Locale_CTypeRef ctype, int c );
int  System_Locale_CType_ToASCII( System_Locale_CTypeRef ctype, int c );

#endif /* __XEOS_LIB_SYSTEM_LOCALE_H__ */
