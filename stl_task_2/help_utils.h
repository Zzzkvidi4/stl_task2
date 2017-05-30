#pragma once
#include "stdafx.h"

//функция для вывода сообщений
void print_message(std::string msg);

//функция получения одного из вариантов между min и max
void getChoice(int min, int max, int& choice_number);

//функция получения чисел больше min
void getIntGreater(int min, int& value);

bool input_query(std::string str);

bool checkInt(std::string str);

bool checkDouble(std::string str);

