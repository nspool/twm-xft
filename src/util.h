/*****************************************************************************/
/*

Copyright 1989, 1998  The Open Group

Permission to use, copy, modify, distribute, and sell this software and its
documentation for any purpose is hereby granted without fee, provided that
the above copyright notice appear in all copies and that both that
copyright notice and this permission notice appear in supporting
documentation.

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.  IN NO EVENT SHALL THE
OPEN GROUP BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN
AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

Except as contained in this notice, the name of The Open Group shall not be
used in advertising or otherwise to promote the sale, use or other dealings
in this Software without prior written authorization from The Open Group.

*/
/**       Copyright 1988 by Evans & Sutherland Computer Corporation,        **/
/**                          Salt Lake City, Utah                           **/
/**                        Cambridge, Massachusetts                         **/
/**                                                                         **/
/**                           All Rights Reserved                           **/
/**                                                                         **/
/**    Permission to use, copy, modify, and distribute this software and    **/
/**    its documentation  for  any  purpose  and  without  fee is hereby    **/
/**    granted, provided that the above copyright notice appear  in  all    **/
/**    copies and that both  that  copyright  notice  and  this  permis-    **/
/**    sion  notice appear in supporting  documentation,  and  that  the    **/
/**    name of Evans & Sutherland not be used in advertising    **/
/**    in publicity pertaining to distribution of the  software  without    **/
/**    specific, written prior permission.                                  **/
/**                                                                         **/
/**    EVANS & SUTHERLAND DISCLAIMs ALL WARRANTIES WITH REGARD    **/
/**    TO THIS SOFTWARE, INCLUDING ALL IMPLIED WARRANTIES  OF  MERCHANT-    **/
/**    ABILITY  AND  FITNESS,  IN  NO  EVENT SHALL EVANS & SUTHERLAND    **/
/**    BE LIABLE FOR ANY SPECIAL, INDIRECT OR CONSEQUENTIAL  DAM-    **/
/**    AGES OR  ANY DAMAGES WHATSOEVER  RESULTING FROM LOSS OF USE, DATA    **/
/**    OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER    **/
/**    TORTIOUS ACTION, ARISING OUT OF OR IN  CONNECTION  WITH  THE  USE    **/
/**    OR PERFORMANCE OF THIS SOFTWARE.                                     **/
/*****************************************************************************/
/* $XFree86: xc/programs/twm/util.h,v 1.6 2001/01/17 23:45:08 dawes Exp $ */


/***********************************************************************
 *
 * $Xorg: util.h,v 1.4 2001/02/09 02:05:37 xorgcvs Exp $
 *
 * utility routines header file
 *
 * 28-Oct-87 Thomas E. LaStrange		File created
 *
 ***********************************************************************/

#ifndef _UTIL_
#define _UTIL_

extern void MoveOutline ( Window root, int x, int y, int width, int height, 
			  int bw, int th );
extern void Zoom ( Window wf, Window wt );
extern char * ExpandFilename ( char *name );
extern void GetUnknownIcon ( char *name );
extern Pixmap FindBitmap ( char *name, unsigned int *widthp, 
			   unsigned int *heightp );
extern Pixmap GetBitmap ( char *name );
extern void InsertRGBColormap ( Atom a, XStandardColormap *maps, int nmaps, 
			       Bool replace );
extern void RemoveRGBColormap ( Atom a );
extern void LocateStandardColormaps ( void );
extern void GetColor ( int kind, Pixel *what, char *name );
extern void GetColorValue ( int kind, XColor *what, char *name );
extern void GetFont ( MyFont *font );
extern int MyFont_TextWidth( MyFont *font, char *string, int len);

#ifdef TWM_USE_XFT
/* Xft-related variables have "xft_" prefix: */
#define XFT_PFX(p,n)		p ## n
#define DRAW_WIN(t,w)		((t)->XFT_PFX(xft_,w))
#define DRAW_COL(t,c)		(&(t)->XFT_PFX(xft_,c))
#define DRAW_WIN_T		XftDraw*
#define DRAW_COL_T		XftColor*
#else
#define DRAW_WIN(t,w)		((t)->w)
#define DRAW_COL(t,c)		(&(t)->c)
#define DRAW_WIN_T		Drawable
#define DRAW_COL_T		ColorPair*
#endif

extern void MyFont_DrawImageString ( Display *dpy,
			DRAW_WIN_T d, MyFont *font, DRAW_COL_T col,
			int x, int y, char *string, int len );

extern void MyFont_DrawString ( Display *dpy,
			DRAW_WIN_T d, MyFont *font, DRAW_COL_T col,
			int x, int y, char *string, int len );

extern Status I18N_FetchName( Display *dpy, Window win, char **winname);
extern Status I18N_GetIconName( Display *dpy, Window win, char **iconname);
extern void SetFocus ( TwmWindow *tmp_win, Time time );
extern void Bell ( int type, int percent, Window win );

#ifdef TWM_USE_XFT
extern void CopyPixelToXftColor (Colormap cmap,
				unsigned long pixel, XftColor *col);
#endif
#ifdef TWM_USE_OPACITY	 /*opacity: 0 = transparent ... 255 = opaque*/
extern Atom opacityAtom;
extern void SetWindowOpacity (Window win, unsigned int opacity);
extern void PropagateWindowOpacity (TwmWindow *tmp);
#endif

extern int HotX, HotY;

#define	WM_BELL			0
#define	MINOR_ERROR_BELL	1
#define	MAJOR_ERROR_BELL	2
#define	INFO_BELL		3
#define	NUM_BELLS		4

#define	QUIET_BELL		-100
#define	MODERATE_BELL		0
#define	LOUD_BELL		100

#ifdef XKB
#include <X11/extensions/XKBbells.h>
#else
#define	XkbBI_Info			0
#define	XkbBI_MinorError		1
#define	XkbBI_MajorError		2
#endif

#endif /* _UTIL_ */
