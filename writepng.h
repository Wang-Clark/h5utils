/* Copyright (c) 1999 Massachusetts Institute of Technology
 *
 * Permission is hereby granted, free of charge, to any person obtaining
 * a copy of this software and associated documentation files (the
 * "Software"), to deal in the Software without restriction, including
 * without limitation the rights to use, copy, modify, merge, publish,
 * distribute, sublicense, and/or sell copies of the Software, and to
 * permit persons to whom the Software is furnished to do so, subject to
 * the following conditions:
 * 
 * The above copyright notice and this permission notice shall be
 * included in all copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
 * IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY
 * CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,
 * TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE
 * SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 */

#ifndef WRITEPNG_H
#define WRITEPNG_H

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

/***********************************************************************/

#ifdef SINGLE_PRECISION
typedef float REAL;
#else
typedef double REAL;
#endif

typedef enum {
     GRAYSCALE,
     BLUE_WHITE_RED
} colormap_t;

void writepng(char *filename,
	      int nx, int ny, int transpose,
	      REAL skew, REAL scalex, REAL scaley,
	      REAL *data, int *mask,
	      REAL minrange, REAL maxrange,
	      int invert, colormap_t colormap);

void writepng_autorange(char *filename,
			int nx, int ny, int transpose,
			REAL skew, REAL scalex, REAL scaley,
			REAL *data, int *mask,
			int invert, colormap_t colormap);

void compute_outlinemask(int nx, int ny, REAL * data, int *mask,
			 REAL background_value);

/***********************************************************************/

#ifdef __cplusplus
} /* extern "C" */
#endif /* __cplusplus */

#endif /* WRITEPNG_H */