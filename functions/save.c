#include <stdio.h>
#include "../text/_text.h"
#include "../text/text.h"
#include "../app/common.h"

/**
 * Сохраняет содержимое загруженного файла, с указанным именем
 */


void save(text txt, char *newfilename)
{
    FILE *f;

    if(txt == NULL || txt->length == 0)
    {
	printf("Nothing to save\n");
	return;
    }
    
    if ((f = fopen(newfilename, "w")) == NULL)
    {
	fprintf(stderr, "The file %s cannot be written\n", newfilename);
	return;
    }

    node * current = txt->begin;
	
    while(current)
    {
	fprintf(f, "%s", current->contents);
	current = current->next;
    }
    fclose(f);
}
