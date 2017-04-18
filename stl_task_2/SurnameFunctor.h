#pragma once
class SurnameFunctor {
public:
	SurnameFunctor(std::string surname) {
		if (surname == "") {
			throw std::invalid_argument("Фамилия не может быть пустой!");
		}
		this->surname = surname;
		this->name = surname;
	}

	bool operator()(Bill bill) {
		return bill.getSurname() == surname;
	}

	static bool equals(Bill bill) {
		return bill.getSurname() == name;
	}

	Bill constructValue() {
		Bill* bill = new Bill();
		bill->setSurname(surname);
		return *bill;
	}
private:
	std::string surname;
	static std::string name;
};

