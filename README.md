# Простейший текстовый редактор.
[![CI/CD GitHub Actions](https://github.com/ChirpaEwok/lab2/actions/workflows/test-action.yml/badge.svg)](https://github.com/ChirpaEwok/lab2/actions/workflows/test-action.yml)
[![Coverage Status](https://coveralls.io/repos/github/ChirpaEwok/lab2/badge.svg?branch=master)](https://coveralls.io/github/ChirpaEwok/lab2?branch=master)
[![Bugs](https://sonarcloud.io/api/project_badges/measure?project=ChirpaEwok_lab2&metric=bugs)](https://sonarcloud.io/summary/new_code?id=ChirpaEwok_lab2)
[![Code Smells](https://sonarcloud.io/api/project_badges/measure?project=ChirpaEwok_lab2&metric=code_smells)](https://sonarcloud.io/summary/new_code?id=ChirpaEwok_lab2)

# Модуль tests.h
## Метод ASSERT_EQ
### Тест №2 (load, regular_file)
<b>Цель:</b> Проверить работу функции загрузки с обычным файлом <br/>
<b>Тип:</b> Позитивный <br/>
<b>Входные данные:</b> Файл input.txt <br/>
<b>Ожидаемый результат:</b> Будет создана переменная txt типа text, содержащая каждую строку исходного файла <br/>

### Тест №3 (save, correct_saving)
<b>Цель:</b> Проверить работу функции сохранения <br/>
<b>Тип:</b> Позитивный <br/>
<b>Входные данные:</b> Файл input.txt <br/>
<b>Ожидаемый результат:</b> Данные из input.txt будут сохранены в новом файле output.txt <br/>

### Тест №4 (save, save_to_not_writable_file)
<b>Цель:</b> Проверить работу функции сохранения, когда файл, куда будет производиться сохранение, неизменяемый <br/>
<b>Тип:</b> Негативный <br/>
<b>Входные данные:</b> Файл input.txt <br/>
<b>Ожидаемый результат:</b> Сообщение об ошибке сохранения: The file usr/lib cannot be written <br/>

### Тест №5 (save, nothing_to_save)
<b>Цель:</b> Проверить работу функции сохранения, при попытке сохранения пустого текста <br/>
<b>Тип:</b> Негативный <br/>
<b>Входные данные:</b> Пустая переменная txt типа text <br/>
<b>Ожидаемый результат:</b> Сообщение о том, что нету ничего для сохранения: Nothing to save <br/>

### Тест №6 (show, correct_showing)
<b>Цель:</b> Проверить отображение текста на экран <br/>
<b>Тип:</b> Позитивный <br/>
<b>Входные данные:</b> Файл input.txt с некоторым содержимым <br/>
<b>Ожидаемый результат:</b> Вывод содержимого файла input.txt на экран <br/>

### Тест №7 (show, show_empty)
<b>Цель:</b> Проверить отображение пустого текста на экран <br/>
<b>Тип:</b> Негативный <br/>
<b>Входные данные:</b> Пустая переменная txt типа text <br/>
<b>Ожидаемый результат:</b> Сообщение об ошибке, так как нету строк для вывода: There are already no any lines in the text! <br/>

### Тест №8 (move, correct_moving)
<b>Цель:</b> Проверить работу функции перемещения курсора в тексте <br/>
<b>Тип:</b> Позитивный <br/>
<b>Входные данные:</b> Файл input.txt с некоторым содержимым <br/>
<b>Ожидаемый результат:</b> Вывод содержимого файла input.txt на экран вместе с текущим положением курсора <br/>
<b>Описание процесса:</b> Запускаем функцию с различными параметрами и проверяем корректность вывода. <br/>

### Тест №9 (move, moving_out_of_bounds)
<b>Цель:</b> Проверить работу функции перемещения курсора в тексте, когда значения строки или позиции неверные <br/>
<b>Тип:</b> Негативный <br/>
<b>Входные данные:</b> Файл input.txt с некоторым содержимым <br/>
<b>Ожидаемый результат:</b> Вывод содержимого файла input.txt на экран вместе с текущим положением курсора <br/>
<b>Описание процесса:</b> Запускаем функцию с различными параметрами и проверяем корректность вывода, но значения строки или позиции заданы неправильно, т.е. слишком большие, отрицательные и тд., например: move(txt, 2, -10). В данном случае ожидается, что курсор будет в начале второй строки. Или результатом этого move(txt, -1, 1), ожидается, что курсор будет на нулевой строке в первой позиции. <br/>

### Тест №10 (move, moving_in_empty)
<b>Цель:</b> Проверить работу функции перемещения курсора в пустом тексте <br/>
<b>Тип:</b> Негативный <br/>
<b>Входные данные:</b> Пустая переменная txt типа text <br/>
<b>Ожидаемый результат:</b> Вывод пустой строки на экран <br/>

### Тест №11 (showwordbeginnings, correct_showing)
<b>Цель:</b> Проверить работу функции showwordbeginnings <br/>
<b>Тип:</b> Позитивный <br/>
<b>Входные данные:</b> Файл input.txt с некоторым содержимым <br/>
<b>Ожидаемый результат:</b> Вывод буквенных символов каждой строки, которым предшествует пробельный символ или начало строки <br/>

### Тест №12 (showwordbeginnings, show_empty)
<b>Цель:</b> Проверить работу функции showwordbeginnings с пустым текстом <br/>
<b>Тип:</b> Негативный <br/>
<b>Входные данные:</b> Пустая переменная txt типа text <br/>
<b>Ожидаемый результат:</b> Сообщение об ошибке, так как нету строк для вывода: There are already no any lines in the text! <br/>

### Тест №13 (y, correct_replacment)
<b>Цель:</b> Проверить работу функции y <br/>
<b>Тип:</b> Позитивный <br/>
<b>Входные данные:</b> Файл input.txt с некоторым содержимым <br/>
<b>Ожидаемый результат:</b> Замена строки от курсора и до конца заданной строкой <br/>
<b>Описание процесса:</b> Двигаем курсор на какое-то место в тексте и запускаем функцию с различными параметрами, проверяем корректность вывода. Например, когда курсор находится на месте 1, 1 (строка, столбец соответственно), строка выгляди так: q|wer. После выполнения функции: y(txt, "rt") она должна выглядеть так: q|rt <br/>

### Тест №14 (y, overflow)
<b>Цель:</b> Проверить работу функции y, когда происходит переполнение строки <br/>
<b>Тип:</b> Негативный <br/>
<b>Входные данные:</b> Файл input.txt с некоторым содержимым <br/>
<b>Ожидаемый результат:</b> Сообщение об ошибке, так как происходит переполнение строки: Too many letters <br/>

## Тест №15 (ce, correct_working)
<b>Цель:</b> Проверить работу функции ce <br/>
<b>Тип:</b> Позитивный <br/>
<b>Входные данные:</b> Файл input.txt с некоторым содержимым <br/>
<b>Ожидаемый результат:</b> Перемещение текущей строки в конец текста <br/>
<b>Описание процесса:</b>  Двигаем курсор на какое-то место в тексте и запускаем функцию. Также пробуем запустить функцию, когда уже находимся в конце текста <br/>

## Тест №16 (ce, ce_empty)
<b>Цель:</b> Проверить работу функции ce с пустым текстом <br/>
<b>Тип:</b> Негативный <br/>
<b>Входные данные:</b> Пустая переменная txt типа text <br/>
<b>Ожидаемый результат:</b> Пустая строка <br/>
