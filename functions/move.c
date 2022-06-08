#include <stdio.h>
#include "../text/_text.h"
#include "../text/text.h"
#include "../app/common.h"

/**
 * Перемещает курсор на n-ый символ m-ой cтроки
 */

void move(text txt, int m, int n)
{
    int cpit = 0; /* current position in text */
    node *current = txt->begin;
	if (m < 0)
	{
		txt->cursor->line = txt->begin;
		txt->cursor->position = n;
		return;
	}
    while(current)
    {
	    current = current->next;
		cpit++;
		if (cpit == m)     
	    	break;
    }
	if (cpit < m) {
		txt->cursor->line = txt->end;
	} else {
    	txt->cursor->line = current;
	}
    int currentstrlen = (int)strlen(current->contents) - 1;
    if (n <= currentstrlen) {
		txt->cursor->position = n;
    } else {
		txt->cursor->position = currentstrlen;
    }
	if (n < 0)
		txt->cursor->position = 0;
}
