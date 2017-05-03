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

struct SurnameFunctor {
	SurnameFunctor(std::string surname):surname(surname) {}

	bool operator()(Bill bill) {
		return bill.getSurname() == surname;
	}

	Bill constructValue() {
		Bill* bill = new Bill();
		bill->setSurname(surname);
		return *bill;
	}
private:
	std::string surname;
};

struct HouseNumberFunctor {
public:
	HouseNumberFunctor(int num) {
		this->num = num;
	}

	bool operator()(Bill bill) {
		return bill.getHouseNumber() == num;
	}

	Bill constructValue() {
		Bill* bill = new Bill();
		bill->setHouseNumber(num);
		return *bill;
	}
private:
	int num;
};

struct ApartmentNumberFunctor {
public:
	ApartmentNumberFunctor(int num) {
		this->num = num;
	}

	bool operator()(Bill bill) {
		return bill.getApartmentNumber() == num;
	}

	Bill constructValue() {
		Bill* bill = new Bill();
		bill->setApartmentNumber(num);
		return *bill;
	}
private:
	int num;
};

struct HavePeniFunctor {
	HavePeniFunctor(bool val) : hasPeni(val) {};

	bool operator()(Bill bill) {
		return bill.countPeni() > DBL_EPSILON;
	}

	Bill constructValue() {
		Bill* bill = new Bill();
		bill->setHasPeni(hasPeni);
		return *bill;
	}
private:
	bool hasPeni;
};

struct DateFunctor {
public:
	DateFunctor(Date date) {
		this->date = date;
	}

	bool operator()(Bill bill) {
		return bill.getDate() == date;
	}

	Bill constructValue() {
		Bill* bill = new Bill();
		bill->setDate(date);
		return *bill;
	}
private:
	Date date;
};

//основное меню
void print_main_menu(TemplateContainer<Bill>& cont) {
	system("cls");
	std::cout << "Выберите один из пунктов меню:" << std::endl;
	std::cout << "1. Заполнение из файла." << std::endl;
	std::cout << "2. Запись в файл." << std::endl;
	std::cout << "3. Вывод." << std::endl;
	std::cout << "4. Добавление записи." << std::endl;
	std::cout << "5. Удаление записи." << std::endl;
	std::cout << "6. Редактирование записи." << std::endl;
	std::cout << "7. Выборка записей по критериям." << std::endl;
	std::cout << "8. Выборка записей по критериям(бинарный поиск)." << std::endl;
	std::cout << "0. Выход." << std::endl;
	if (cont.size() == 0) {
		std::cout << "Список счетов пуст. Некоторые действия недоступны." << std::endl;
	}
}

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

//действие заполнения из файла
void fill_from_file_action(TemplateContainer<Bill>& cont) {
	std::cout << "Введите имя файла (пустая строка для отмены):" << std::endl;
	std::string file_name;
	std::getline(std::cin, file_name);
	if (file_name != "") {
		cont.clear();
		try {
			if (!cont.read_from_file(file_name)) {
				print_message("Внимание, содержимое файла может быть отражено некорректно!");
			}
		}
		catch (std::exception e) {
			print_message("Файл поврежден необратимо. Содержимое не может быть отражено.");
		}
	}
}

//действие заполнения файла из контейнера
void fill_file_from_cont_action(TemplateContainer<Bill> cont) {
	std::cout << "Введите имя файла (пустая строка для отмены):" << std::endl;
	std::string file_name;
	std::getline(std::cin, file_name);
	if (file_name != "") {
		try {
			cont.print_to_file(file_name);
		}
		catch (std::exception e) {
			print_message(e.what());
		}
	}
}

//действие печати контейнера
void print_container_action(TemplateContainer<Bill> cont) {
	if (cont.size() == 0){
		print_message("Список счетов пуст!");
	} else {
		std::cout << cont << std::endl;
		system("pause");
	}
}

//действие добавления записи
void add_record_action(TemplateContainer<Bill>& cont) {
	if (input_query("Ввести запись? (Y/N) (N):")) {
		Bill bill = Bill();
		try {
			std::string str;

			std::cout << "Введите улицу:" << std::endl;
			std::getline(std::cin, str);
			bill.setStreetName(str);

			std::cout << "Введите номер дома:" << std::endl;
			std::getline(std::cin, str);
			bill.setHouseNumber(str);

			std::cout << "Введите номер строения (пустая строка для пропуска):" << std::endl;
			std::getline(std::cin, str);
			bill.setBlockNumber(str);

			std::cout << "Введите номер квартиры (пустая строка для пропуска):" << std::endl;
			std::getline(std::cin, str);
			bill.setApartmentNumber(str);

			std::cout << "Введите год платежа:" << std::endl;
			std::getline(std::cin, str);
			bill.getDate().setYear(str);

			std::cout << "Введите месяц платежа:" << std::endl;
			std::getline(std::cin, str);
			bill.getDate().setMonth(str);

			std::cout << "Введите день платежа:" << std::endl;
			std::getline(std::cin, str);
			bill.getDate().setDay(str);

			std::cout << "Введите фамилию владельца:" << std::endl;
			std::getline(std::cin, str);
			bill.setSurname(str);

			std::cout << "Введите тип платежа:" << std::endl;
			std::getline(std::cin, str);
			bill.setPaymentType(str);

			std::cout << "Введите сумму платежа:" << std::endl;
			std::getline(std::cin, str);
			bill.setPayment(str);

			std::cout << "Введите процент пени:" << std::endl;
			std::getline(std::cin, str);
			bill.setPeni(str);

			std::cout << "Введите количество дней просрочки:" << std::endl;
			std::getline(std::cin, str);
			bill.setDelayNumber(str);
		}
		catch (std::exception e) {
			print_message(e.what());
		}
		cont.Add(bill);
	}
}

//действие удаления записи
void remove_record_action(TemplateContainer<Bill>& cont) {
	if (cont.size() == 0) {
		print_message("Список счетов пуст!");
		return;
	}
	std::cout << "Введите позицию для удаления (0 - отмена):" << std::endl;
	int num;
	getChoice(0, cont.size(), num);
	if (num != 0) {
		cont.Erase(num);
	}
}

#pragma region select_functions_region

//выборка по фамилии
void select_records_by_surname(TemplateContainer<Bill> cont) {
	if (input_query("Ввести фамилию владельца? (Y/N) (N):")) {
		std::cout << "Введите фамилию владельца (пустая строка - отмена):" << std::endl;
		std::string str;
		std::getline(std::cin, str);
		if (str != "") {
			SurnameFunctor func = SurnameFunctor(str);
			TemplateContainer<Bill> result = cont.GetElemsIf(func);
			std::cout << result << std::endl;
			bool is_saving = input_query("Сохранить результат в файл? (Y/N) (N):");
			if (is_saving) {
				std::cout << "Введите имя файла (пустая строка - отмена):" << std::endl;
				std::getline(std::cin, str);
				if (str != "") {
					try {
						result.print_to_file(str);
					}
					catch (std::exception e) {
						print_message(e.what());
					}
				}
			}
		}
	}
}

//выборка во фамилии бинарная
void select_records_by_surname_binary(TemplateContainer<Bill> cont) {
	if (input_query("Ввести фамилию владельца? (Y/N) (N):")) {
		std::cout << "Введите фамилию владельца (пустая строка - отмена):" << std::endl;
		std::string str;
		std::getline(std::cin, str);
		if (str != "") {
			SurnameFunctor func = SurnameFunctor(str);
			TemplateContainer<Bill> result = cont.GetElemsIfBinary(Bill::surnameComparator, func, func.constructValue());
			std::cout << result << std::endl;
			bool is_saving = input_query("Сохранить результат в файл? (Y/N) (N):");
			if (is_saving) {
				std::cout << "Введите имя файла (пустая строка - отмена):" << std::endl;
				std::getline(std::cin, str);
				if (str != "") {
					try {
						result.print_to_file(str);
					}
					catch (std::exception e) {
						print_message(e.what());
					}
				}
			}
		}
	}
}

//выборка по номеру квартиры
void select_records_by_apartment_number(TemplateContainer<Bill> cont) {
	if (input_query("Ввести номер квартиры? (Y/N) (N):")) {
		std::cout << "Введите номер квартиры (пустая строка - отмена, 0 - нет номера квартиры):" << std::endl;
		std::string str;
		std::getline(std::cin, str);
		if (str != "") {
			try {
				int num = std::stoi(str);
				ApartmentNumberFunctor func = ApartmentNumberFunctor(num);
				TemplateContainer<Bill> result = cont.GetElemsIf(func);
				std::cout << result << std::endl;
				bool is_saving = input_query("Сохранить результат в файл? (Y/N) (N):");
				if (is_saving) {
					std::cout << "Введите имя файла (пустая строка - отмена):" << std::endl;
					std::getline(std::cin, str);
					if (str != "") {
						try {
							result.print_to_file(str);
						}
						catch (std::exception e) {
							print_message(e.what());
						}
					}
				}
			}
			catch (std::invalid_argument e) {
				print_message("Номер квартиры должен быть числом!");
			}
		}
	}
}

//выборка по номеру квартиры бинарная
void select_records_by_apartment_number_binary(TemplateContainer<Bill> cont) {
	if (input_query("Ввести номер квартиры? (Y/N) (N):")) {
		std::cout << "Введите номер квартиры (пустая строка - отмена, 0 - нет номера квартиры):" << std::endl;
		std::string str;
		std::getline(std::cin, str);
		if (str != "") {
			try {
				int num = std::stoi(str);
				ApartmentNumberFunctor func = ApartmentNumberFunctor(num);
				TemplateContainer<Bill> result = cont.GetElemsIfBinary(Bill::appartmentNumberComparator, func, func.constructValue());
				std::cout << result << std::endl;
				bool is_saving = input_query("Сохранить результат в файл? (Y/N) (N):");
				if (is_saving) {
					std::cout << "Введите имя файла (пустая строка - отмена):" << std::endl;
					std::getline(std::cin, str);
					if (str != "") {
						try {
							result.print_to_file(str);
						}
						catch (std::exception e) {
							print_message(e.what());
						}
					}
				}
			}
			catch (std::invalid_argument e) {
				print_message("Номер квартиры должен быть числом!");
			}
		}
	}
}

//выборка по номеру дома
void select_records_by_house_number(TemplateContainer<Bill> cont) {
	if (input_query("Ввести номер дома? (Y/N) (N):")) {
		std::string str;
		std::getline(std::cin, str);
		if (str != "") {
			try {
				int num = std::stoi(str);
				HouseNumberFunctor func = HouseNumberFunctor(num);
				TemplateContainer<Bill> result = cont.GetElemsIf(func);
				std::cout << result << std::endl;
				bool is_saving = input_query("Сохранить результат в файл? (Y/N) (N):");
				if (is_saving) {
					std::cout << "Введите имя файла (пустая строка - отмена):" << std::endl;
					std::getline(std::cin, str);
					if (str != "") {
						try {
							result.print_to_file(str);
						}
						catch (std::exception e) {
							print_message(e.what());
						}
					}
				}
			}
			catch (std::invalid_argument e) {
				print_message("Номер дома должен быть числом!");
			}
		}
	}
}

//выборка по номеру дома бинарная
void select_records_by_house_number_binary(TemplateContainer<Bill> cont) {
	if (input_query("Ввести номер дома? (Y/N) (N):")) {
		std::string str;
		std::getline(std::cin, str);
		if (str != "") {
			try {
				int num = std::stoi(str);
				HouseNumberFunctor func = HouseNumberFunctor(num);
				TemplateContainer<Bill> result = cont.GetElemsIfBinary(Bill::houseNumberComparator, func, func.constructValue());
				std::cout << result << std::endl;
				bool is_saving = input_query("Сохранить результат в файл? (Y/N) (N):");
				if (is_saving) {
					std::cout << "Введите имя файла (пустая строка - отмена):" << std::endl;
					std::getline(std::cin, str);
					if (str != "") {
						try {
							result.print_to_file(str);
						}
						catch (std::exception e) {
							print_message(e.what());
						}
					}
				}
			}
			catch (std::invalid_argument e) {
				print_message("Номер дома должен быть числом!");
			}
		}
	}
}

//выборка по дате
void select_records_by_date(TemplateContainer<Bill> cont) {
	if (input_query("Ввести дату? (Y/N) (N):")) {
		Date date = Date();
		try {
			std::cin >> date;
			DateFunctor func = DateFunctor(date);
			TemplateContainer<Bill> result = cont.GetElemsIf(func);
			std::cout << result << std::endl;
			bool is_saving = input_query("Сохранить результат в файл? (Y/N) (N):");
			if (is_saving) {
				std::cout << "Введите имя файла (пустая строка - отмена):" << std::endl;
				std::string str;
				std::getline(std::cin, str);
				if (str != "") {
					try {
						result.print_to_file(str);
					}
					catch (std::exception e) {
						print_message(e.what());
					}
				}
			}
		}
		catch (std::exception e) {
			print_message(e.what());
		}
	}
}

//выборка по дате бинарная
void select_records_by_date_binary(TemplateContainer<Bill> cont) {
	if (input_query("Ввести дату? (Y/N) (N):")) {
		Date date = Date();
		try {
			std::cin >> date;
			DateFunctor func = DateFunctor(date);
			TemplateContainer<Bill> result = cont.GetElemsIfBinary(Bill::dateComparator, func, func.constructValue());
			std::cout << result << std::endl;
			bool is_saving = input_query("Сохранить результат в файл? (Y/N) (N):");
			if (is_saving) {
				std::cout << "Введите имя файла (пустая строка - отмена):" << std::endl;
				std::string str;
				std::getline(std::cin, str);
				if (str != "") {
					try {
						result.print_to_file(str);
					}
					catch (std::exception e) {
						print_message(e.what());
					}
				}
			}
		}
		catch (std::exception e) {
			print_message(e.what());
		}
	}
}

//выборка по наличию пени
void select_records_by_having_peni(TemplateContainer<Bill> cont) {
	std::string str;
	HavePeniFunctor func = HavePeniFunctor(input_query("Выборка счетов с долгом? (Y/N) (N):"));
	TemplateContainer<Bill> result = cont.GetElemsIf(func);
	std::cout << result << std::endl;
	bool is_saving = input_query("Сохранить результат в файл? (Y/N) (N):");
	if (is_saving) {
		std::cout << "Введите имя файла (пустая строка - отмена):" << std::endl;
		std::getline(std::cin, str);
		if (str != "") {
			try {
				result.print_to_file(str);
			}
			catch (std::exception e) {
				print_message(e.what());
			}
		}
	}
}

//выборка по наличию пени бинарная
void select_records_by_having_peni_binary(TemplateContainer<Bill> cont) {
	std::string str;
	HavePeniFunctor func = HavePeniFunctor(input_query("Выборка счетов с долгом? (Y/N) (N):"));
	TemplateContainer<Bill> result = cont.GetElemsIfBinary(Bill::peniComparator, func, func.constructValue());
	std::cout << result << std::endl;
	bool is_saving = input_query("Сохранить результат в файл? (Y/N) (N):");
	if (is_saving) {
		std::cout << "Введите имя файла (пустая строка - отмена):" << std::endl;
		std::getline(std::cin, str);
		if (str != "") {
			try {
				result.print_to_file(str);
			}
			catch (std::exception e) {
				print_message(e.what());
			}
		}
	}
}

//меню выборок
void print_select_records_menu() {
	system("cls");
	std::cout << "Выберите один из пунктов меню выборок:" << std::endl;
	std::cout << "1. По фамилии." << std::endl;
	std::cout << "2. По номеру квартиры." << std::endl;
	std::cout << "3. По дате." << std::endl;
	std::cout << "4. По номеру дома." << std::endl;
	std::cout << "5. По наличии задолжности." << std::endl;
	std::cout << "0. Назад." << std::endl;
}

//совершение выборки
void create_select(TemplateContainer<Bill> cont, int choice) {
	switch (choice) {
	case 1: {
		select_records_by_surname(cont);
		break;
	}
	case 2: {
		select_records_by_house_number(cont);
		break;
	}
	case 3: {
		select_records_by_date(cont);
		break;
	}
	case 4: {
		select_records_by_house_number(cont);
		break;
	}
	case 5: {
		select_records_by_having_peni(cont);
		break;
	}
	default: {
		break;
	}
	}
}

//действие выборки
void select_records_action(TemplateContainer<Bill> cont) {
	int choice = -1;
	while (choice != 0) {
		print_select_records_menu();
		getChoice(0, 5, choice);
		if (choice != 0) {
			create_select(cont, choice);
		}
	}
}

//совершение выборки бинарной
void create_select_binary(TemplateContainer<Bill> cont, int choice) {
	switch (choice) {
	case 1: {
		select_records_by_surname_binary(cont);
		break;
	}
	case 2: {
		select_records_by_house_number_binary(cont);
		break;
	}
	case 3: {
		select_records_by_date_binary(cont);
		break;
	}
	case 4: {
		select_records_by_house_number_binary(cont);
		break;
	}
	case 5: {
		select_records_by_having_peni_binary(cont);
		break;
	}
	default: {
		break;
	}
	}
}

//действие выборки бинарной
void select_records_binary_action(TemplateContainer<Bill> cont) {
	int choice = -1;
	while (choice != 0) {
		print_select_records_menu();
		getChoice(0, 5, choice);
		if (choice != 0) {
			create_select_binary(cont, choice);
		}
	}
}


#pragma endregion

//основная программа
void create_action(TemplateContainer<Bill>& cont, int choice) {
	switch (choice) {
	case 1: {
		fill_from_file_action(cont);
		break;
	}
	case 2: {
		if (cont.size() != 0) {
			fill_file_from_cont_action(cont);
		}
		break;
	}
	case 3: {
		print_container_action(cont);
		break;
	}
	case 4: {
		add_record_action(cont);
		break;
	}
	case 5: {
		if (cont.size() != 0) {
			remove_record_action(cont);
		}
		break;
	}
	case 6: {
		if (cont.size() != 0) {
			change_record_action(cont);
		}
		break;
	}
	case 7: {
		if (cont.size() != 0) {
			select_records_action(cont);
		}
		break;
	}
	case 8: {
		if (cont.size() != 0) {
			select_records_binary_action(cont);
		}
		break;
	}
	default: {
		break;
	}
	}
}

int main()
{
	setlocale(LC_ALL, "russian");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	TemplateContainer<Bill> cont = TemplateContainer<Bill>();
	int choice = -1;
	while (choice != 0) {
		print_main_menu(cont);
		getChoice(0, 8, choice);
		create_action(cont, choice);
	}
	return 0;
}

