#include "third_party/gdtoa/gdtoa.internal.h"

/* clang-format off */
/****************************************************************

The author of this software is David M. Gay.

Copyright (C) 1998 by Lucent Technologies
All Rights Reserved

Permission to use, copy, modify, and distribute this software and
its documentation for any purpose and without fee is hereby
granted, provided that the above copyright notice appear in all
copies and that both that the copyright notice and this
permission notice and warranty disclaimer appear in supporting
documentation, and that the name of Lucent or any of its entities
not be used in advertising or publicity pertaining to
distribution of the software without specific, written prior
permission.

LUCENT DISCLAIMS ALL WARRANTIES WITH REGARD TO THIS SOFTWARE,
INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS.
IN NO EVENT SHALL LUCENT OR ANY OF ITS ENTITIES BE LIABLE FOR ANY
SPECIAL, INDIRECT OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER
IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION,
ARISING OUT OF OR IN CONNECTION WITH THE USE OR PERFORMANCE OF
THIS SOFTWARE.

****************************************************************/

/* Please send bug reports to David M. Gay (dmg at acm dot org,
 * with " at " changed at "@" and " dot " changed to ".").	*/

int
strtopd(CONST char *s, char **sp, double *d)
{
	static const FPI fpi0 = { 53, 1-1023-53+1, 2046-1023-53+1, 1, SI, 0 /*unused*/ };
	ULong bits[2];
	Long exp;
	int k;
#ifdef Honor_FLT_ROUNDS
#include "third_party/gdtoa/gdtoa_fltrnds.inc"
#else
#define fpi &fpi0
#endif

	k = strtodg(s, sp, fpi, &exp, bits);
	ULtod((ULong*)d, bits, exp, k);
	return k;
	}
