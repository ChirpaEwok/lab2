/**
 * editor.c -- строковый текстовый редактор
 * 
 * Copyright (c) 2017, Alexander Borodin <aborod@petrsu.ru>
 *
 * This code is licensed under a MIT-style license.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../text/text.h"
#include "common.h"

#define MAXLINE 255

int main()
{
    char cmdline[MAXLINE + 1];
    char *cmd;
    char *arg;
    
    /* Создаем объект для представления текста */
    text txt = create_text();

    /* Цикл обработки команд */
    while (1) {
        printf("ed > ");
        
        /* Получаем команду */
        fgets(cmdline, MAXLINE, stdin);

        /* Извлекаем имя команды */
        if ((cmd = strtok(cmdline, " \n")) == NULL) {
            continue;
        }

        /* Распознаем поддерживаемую команду */
        
        /* Завершаем работу редактора */
        if (strcmp(cmd, "quit") == 0) {
            fprintf(stderr, "Bye!\n");
            break;
        }

        /* Загружаем содержимое файла, заданного параметром */
        if (strcmp(cmd, "load") == 0) {
            if ((arg = strtok(NULL, " \n")) == NULL) {
                fprintf(stderr, "Usage: load filename\n");
            } else {
                load(txt, arg);
		move(txt, 0, 0);
            }
            continue;
        }

        /* Выводим текст */
        if (strcmp(cmd, "show") == 0) {
	    show(txt);
            continue;
        }

	if (strcmp(cmd, "swb") == 0) {
	    showwordbeginnings(txt);
	    continue;
	}

	/* Сохраняем содержимое в файл */
	if (strcmp(cmd, "save") == 0) {
	    if ((arg = strtok(NULL, " \n")) == NULL) {
                fprintf(stderr, "Usage: save filename\n");
            } else {
                save(txt, arg);
            }
	    continue;
	  }

	/* Передвежение курсора по тексту */
	if (strcmp(cmd, "move") == 0) {
	    char *m, *n;
	    if ((m = strtok(NULL, " \n")) == NULL || (n = strtok(NULL, " \n")) == NULL) {
                fprintf(stderr, "Usage: move m n (m-string n-symbol)\n");
            } else {
                move(txt, atoi(m), atoi(n));
            }
	    continue;
	}

	if (strcmp(cmd, "y") == 0) {
	    if ((arg = strtok(NULL, "\n")) == NULL) {
		fprintf(stderr, "Usage: y string you want to insert\n");
	    } else {
		y(txt, arg);
	    }
	    continue;
	}

	if (strcmp(cmd, "ce") == 0) {
	    ce(txt);
	    continue;
	}
        
        /* Если команда не известна */
        fprintf(stderr, "Unknown command: %s\n", cmd);
    }
	
    return 0;
}
