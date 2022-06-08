/**
 * show.c -- реализует команду вывода хранимого текста на экран
 *
 * Copyright (c) 2017, Alexander Borodin <aborod@petrsu.ru>
 *
 * This code is licensed under a MIT-style license.
 */

#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <stdlib.h>
#include "../text/_text.h"
#include "../text/text.h"
#include "../common.h"

static void show_line(int index, char *contents, int cursor, void *data);

/**
 * Выводит содержимое указанного файла на экран
 */
void show(text txt)
{
    /* Применяем функцию show_line к каждой строке текста */
    process_forward(txt, show_line, NULL);
}

/**
 * Выводит содержимое указанного файла на экран
 */
static void show_line(int index, char *contents, int cursor, void *data)
{
    /* Функция обработчик всегда получает существующую строку */
    assert(contents != NULL);
    
    /* Декларируем неиспользуемые параметры */
    UNUSED(index);
    UNUSED(data);
    int cln = strlen(contents);
    int maxln = cln - 1;
    int reqpos = maxln > cursor ? maxln: cursor;

    if (cursor != cln)
    {
	for(int i = 0; i <= reqpos; i++)
	{
	    if(i == cursor)
		printf("|");
	    if(i <= maxln)
		printf("%c", contents[i]);
	}
    }
    else
    {
	/* Выводим строку на экран */
	printf("%s", contents);
    }
}
