#include <stdio.h>
#include <assert.h>
#include <string.h>

#include "../app/common.h"

static void linewordbeginnings(int index, char *contents, int cursor, void *data);

void showwordbeginnings(text txt)
{
    process_forward(txt, linewordbeginnings, NULL);
}

static void linewordbeginnings(int index, char *contents, int cursor, void *data)
{
    /* Функция обработчик всегда получает существующую строку */
    assert(contents != NULL);

    /* Декларируем неиспользуемые параметры */
    UNUSED(index);
    UNUSED(cursor);
    UNUSED(data);
    

    printf("%c", contents[0]);
    
    for (int i = 1; i < (int)strlen(contents); i++)
    {
	if (contents[i] == ' ')
	    printf("%c", contents[i + 1]);
    }
    printf("\n");
}
