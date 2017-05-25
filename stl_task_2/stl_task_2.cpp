// stl_task_2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <Windows.h>

/*Результатом должна быть консольная программа с текстовым меню. Программа должна содержать шаблонный класс для управления данными согласно заданию. Для хранения данных необходимо выбрать оптимальный с точки зрения задания контейнер. 
1. Предусмотреть операции добавления, изменения и удаления элемента контейнера. 
2. Реализовать ввод и вывод элементов контейнера с использованием потоковых итераторов на экран и в файл. 
3. Реализовать операции поиска по заданным критериям и выборки подмножества элементов по заданным критериям. Реализовать поиск в двух вариантах: линейный поиск и двоичный поиск на отсортированном контейнере. 
4. Предусмотреть вывод подмножества выборки на экран и в файл. 
Варианты заданий. 
8. Структура записи о коммунальном платеже содержит поля: адрес квартиры,
фамилия владельца, вид платежа, дата платежа, сумма платежа, процент пени,
количество дней просрочки платежа. 
Поиск по номеру дома, квартиры, владельцу, дате, наличии долга. 
Вывод суммы долга в результатах поиска. */

void FillMenu(TemplateContainer<Bill>* cont, CommandList* list) {
	list->Clear();
	list->RegisterCommand(new ExitCommand("Выход."));
	list->RegisterCommand(new ReadFromFileCommand<Bill>("Заполнение из файла.", cont));
	if (cont->size() != 0) {
		list->RegisterCommand(new PrintToFileCommand<Bill>("Вывод в файл.", cont));
		list->RegisterCommand(new PrintCommand<Bill>("Вывод в консоль.", cont));
	}
	list->RegisterCommand(new AddBillCommand("Добавление записи.", cont));
	if (cont->size() != 0) {
		list->RegisterCommand(new EditRecordCommand("Редактирование записи.", cont));
		list->RegisterCommand(new RemoveCommand("Удаление записи.", cont));
		list->RegisterCommand(new SelectCommand("Выборка записей.", cont));
	}
}

int main()
{
	setlocale(LC_ALL, "russian");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	TemplateContainer<Bill>* cont = new TemplateContainer<Bill>();
    CommandList* main_menu = new CommandList();
    int choice = -1;
    while (choice != 0) {
		FillMenu(cont, main_menu);
        main_menu->PrintTitles("Выберите один из пунктов меню:");
        getChoice(0, main_menu->Size(), choice);
        main_menu->ExecuteCommand(choice);
    }
	return 0;
}

