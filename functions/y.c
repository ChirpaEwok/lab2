#include <stdio.h>
#include <string.h>

#include "../text/_text.h"
#include "../text/text.h"
#include "../app/common.h"

void y(text txt, char *str)
{
    char *swc = txt->cursor->line->contents; /* string with cursor */
    int csl = strlen(swc); /* current srting length */
    int isl = strlen(str); /* input string length */
    int cp = txt->cursor->position; /* cursor position */
    if (isl + csl > MAXLINE)
    {
	fprintf(stderr, "Too many letters\n");
	return;
    }
    for (int i = 0; i <= MAXLINE; i++)
	txt->cursor->line->contents[cp + i] = *"\0";
    for (int i = 0; i <= isl; i++)
	txt->cursor->line->contents[cp + i] = str[i];
    txt->cursor->line->contents[cp + isl] = *"\n";
    show(txt);
}
