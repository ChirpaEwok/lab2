#include <stdio.h>
#include "../text/_text.h"
#include "../text/text.h"
#include "../app/common.h"

/**
 * Перемещает курсор на n-ый символ m-ой cтроки
 */

void move(text txt, int m, int n)
{
    int cpis = 0; /* current position in string */
    node *current = txt->begin;
    while(current)
    {
		if (cpis == m)     
	    	break;
		current = current->next;
		cpis++;
    }
    txt->cursor->line = current;
    int currentstrlen = (int)strlen(current->contents) - 1;
    if (n <= currentstrlen)
    {
		txt->cursor->position = n;
    }
    else
    {
		txt->cursor->position = currentstrlen;
    }
	if (n < 0)
	{
		txt->cursor->position = 0;	
	}
}
