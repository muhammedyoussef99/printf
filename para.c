#include "main.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>
#include <limits.h>

/**
 * init_para - clears structed fields and back bufs
 * @para: parameters struction
 * @zp: arg pointer
 * Return: void
*/

void init_para(parat *para, va_list zp)
{
	para->unsign = 0;

	para->plusf = 0;
	para->spacef = 0;
	para->hashf = 0;
	para->zerof = 0;
	para->minusf = 0;

	para->width = 0;
	para->prec = UINT_MAX;

	para->hzby = 0;
	para->lzby = 0;
	(void)zp;
}
