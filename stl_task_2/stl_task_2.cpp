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

//меню изменения
void print_change_record_menu() {
	std::cout << "Выберите один из пунктов меню редактирования:" << std::endl;
	std::cout << "1. Улица." << std::endl;
	std::cout << "2. Номер дома." << std::endl;
	std::cout << "3. Номер строения." << std::endl;
	std::cout << "4. Номер квартиры." << std::endl;
	std::cout << "5. Фамилия владельца." << std::endl;
	std::cout << "6. Год платежа." << std::endl;
	std::cout << "7. Месяц платежа." << std::endl;
	std::cout << "8. День платежа." << std::endl;
	std::cout << "9. Сумма платежа." << std::endl;
	std::cout << "10. Тип платежа." << std::endl;
	std::cout << "11. Процент пени." << std::endl;
	std::cout << "12. Количество дней задолжности." << std::endl;
	std::cout << "0. Назад." << std::endl;
}

//выполнение изменения
void create_changes(Bill& bill, int choice) {
	std::string str;
	try {
		switch (choice) {
		case 1: {
			std::cout << "Текущее значение: " << bill.getStreetName() << std::endl;
			std::cout << "Введите новую улицу (пустая строка - отмена):" << std::endl;
			std::getline(std::cin, str);
			if (str != "") {
				bill.setStreetName(str);
			}
			break;
		}
		case 2: {
			std::cout << "Текущее значение: " << bill.getHouseNumber() << std::endl;
			std::cout << "Введите новый номер дома (пустая строка - отмена):" << std::endl;
			std::getline(std::cin, str);
			if (str != "") {
				bill.setHouseNumber(str);
			}
			break;
		}
		case 3: {
			std::cout << "Текущее значение: " << bill.getBlockNumber() << std::endl;
			std::cout << "Введите новый номер строения (пустая строка - отмена, 0 - нет номера строения):" << std::endl;
			std::getline(std::cin, str);
			if (str != "") {
				if (str != "0") {
					bill.setBlockNumber(str);
				} else {
					bill.setBlockNumber("");
				}
			}
			break;
		}
		case 4: {
			std::cout << "Текущее значение: " << bill.getApartmentNumber() << std::endl;
			std::cout << "Введите новый номер квартиры (пустая строка - отмена, 0 - нет номера квартиры):" << std::endl;
			std::getline(std::cin, str);
			if (str != "") {
				if (str != "0") {
					bill.setApartmentNumber(str);
				} else {
					bill.setApartmentNumber("");
				}
			}
			break;
		}
		case 5: {
			std::cout << "Текущее значение: " << bill.getSurname() << std::endl;
			std::cout << "Введите новую фамилию владельца (пустая строка - отмена):" << std::endl;
			std::getline(std::cin, str);
			if (str != "") {
				bill.setSurname(str);
			}
			break;
		}
		case 6: {
			std::cout << "Текущее значение: " << bill.getDate().getYear() << std::endl;
			std::cout << "Введите новый год (пустая строка - отмена):" << std::endl;
			std::getline(std::cin, str);
			if (str != "") {
				bill.getDate().setYear(str);
			}
			break;
		}
		case 7: {
			std::cout << "Текущее значение: " << bill.getDate().getMonth() << std::endl;
			std::cout << "Введите новый месяц (пустая строка - отмена):" << std::endl;
			std::getline(std::cin, str);
			if (str != "") {
				bill.getDate().setMonth(str);
			}
			break;
		}
		case 8: {
			std::cout << "Текущее значение: " << bill.getDate().getDay() << std::endl;
			std::cout << "Введите новый день (пустая строка - отмена):" << std::endl;
			std::getline(std::cin, str);
			if (str != "") {
				bill.getDate().setDay(str);
			}
			break;
		}
		case 9: {
			std::cout << "Текущее значение: " << bill.getPayment() << std::endl;
			std::cout << "Введите новую сумму платежа (пустая строка - отмена):" << std::endl;
			std::getline(std::cin, str);
			if (str != "") {
				bill.setPayment(str);
			}
			break;
		}
		case 10: {
			std::cout << "Текущее значение: " << bill.getPaymentType() << std::endl;
			std::cout << "Введите новый тип платежа (пустая строка - отмена):" << std::endl;
			std::getline(std::cin, str);
			if (str != "") {
				bill.setPaymentType(str);
			}
			break;
		}
		case 11: {
			std::cout << "Текущее значение: " << bill.getPeni() << std::endl;
			std::cout << "Введите новый процент пени (пустая строка - отмена):" << std::endl;
			std::getline(std::cin, str);
			if (str != "") {
				bill.setPeni(str);
			}
			break;
		}
		case 12: {
			std::cout << "Текущее значение: " << bill.getDelayNumber() << std::endl;
			std::cout << "Введите новую сумму платежа (пустая строка - отмена):" << std::endl;
			std::getline(std::cin, str);
			if (str != "") {
				bill.setDelayNumber(str);
			}
			break;
		}
		default: {
			break;
		}
		}
	}
	catch (std::exception e) {
		print_message(e.what());
	}
}

//действие изменения записи
void change_record_action(TemplateContainer<Bill>& cont) {
	std::cout << "Введите позицию для редактирования:" << std::endl;
	int num;
	getChoice(1, cont.size(), num);
	int choice = -1;
	while (choice != 0) {
		std::cout << cont[num] << std::endl;
		print_change_record_menu();
		getChoice(0, 12, choice);
		if (choice != 0) {
			create_changes(cont[num], choice);
		}
		system("cls");
	}
}

int main()
{
	setlocale(LC_ALL, "russian");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	TemplateContainer<Bill>* cont = new TemplateContainer<Bill>();
	/*int choice = -1;
	while (choice != 0) {
		print_main_menu(cont);
		getChoice(0, 8, choice);
		create_action(cont, choice);
	}*/
    CommandList* main_menu = new CommandList();
    main_menu->RegisterCommand(new ReadFromFileCommand<Bill>("Заполнение из файла.", cont));
    main_menu->RegisterCommand(new PrintToFileCommand<Bill>("Вывод в файл.", cont));
    main_menu->RegisterCommand(new PrintCommand<Bill>("Вывод в консоль.", cont));
    main_menu->RegisterCommand(new AddBillCommand("Добавление записи.", cont));
	main_menu->RegisterCommand(new EditRecordCommand("Редактирование записи.", cont));
    int choice = -1;
    while (choice != 0) {
        main_menu->PrintTitles("Выберите один из пунктов меню:");
        getChoice(0, main_menu->Size(), choice);
        if (choice != 0) {
            main_menu->ExecuteCommand(choice);
        }
    }
	return 0;
}

