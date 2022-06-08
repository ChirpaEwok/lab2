#include <stdio.h>

#include "../text/_text.h"
#include "../text/text.h"
#include "../app/common.h"

void ce(text txt)
{
    if (txt->length == 0)
	return;
    char buf[MAXLINE];
    strcpy(buf, txt->cursor->line->contents);
    while (txt->cursor->line->next)
    {
	strcpy(txt->cursor->line->contents, txt->cursor->line->next->contents);
	txt->cursor->line = txt->cursor->line->next;
    }
    strcpy(txt->end->contents, buf);
    show(txt);
}
