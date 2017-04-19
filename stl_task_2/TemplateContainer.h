#pragma once
#include "stdafx.h"

template<typename T>
class TemplateContainer{
private:
	std::vector<T> elements;
public:
	typedef typename std::vector<T>::iterator iterator;

	iterator begin() { // 2nd: add typename
		return elements.begin();
	}

	iterator end() { // 3rd: add typename
		return elements.end();
	}

	//конструктор
	TemplateContainer<T>() {
		elements = std::vector<T>();
	};

	std::vector<T>& Elems() {
		return elements;
	}

	//размер контейнера
	int size() {
		return elements.size();
	}

	//вставка в конец
	TemplateContainer<T>& Add(T elem) {
		elements.push_back(elem);
		return *this;
	}

	//удаление по индексу
	TemplateContainer<T>& Erase(int index) {
		if (index >= elements.size()) {
			throw std::out_of_range("Индекс находится вне диапазона!");
		}
		elements.erase(elements.begin() + index - 1);
		return *this;
	}

	//выборка элементов по критерию
	template<typename Pred>
	TemplateContainer<T>& GetElemsIf(Pred func) {
		TemplateContainer<T>* result = new TemplateContainer<T>();
		std::copy_if(elements.begin(), elements.end(), std::back_inserter(result->elements), func);
		return *result;
	}

	//выборка элементов по критерию с предварительной сортировкой
	template<typename Pred>
	TemplateContainer<T>& GetElemsIfBinary(bool comp(T,T), Pred pred, T val) {
		TemplateContainer<T>* result = new TemplateContainer<T>();
		SortElemsBy(comp);
		int start = BinarySearch(comp, pred, val);
		if (start != -1) {
			for (TemplateContainer<T>::iterator it = begin() + start; (it != end()) && (pred(*it)); ++it) {
				result->Add(*it);
			}
			for (TemplateContainer<T>::iterator it = begin() + start - 1; (it != begin()) && (pred(*it)); --it) {
				result->Add(*it);
			}
		}
		return *result;
	}

	//бинарный поиск по контейнеру
	template<typename Pred>
	int BinarySearch(bool comp(T, T), Pred pred, T val) {
		int left = 0, right = elements.size() - 1, middle;
		if (right == -1) {
			return -1;
		}
		while (left < right) {
			middle = left + (right - left) / 2;
			if (pred(elements[middle])) {
				return middle;
			}
			if (comp(val, elements[middle])) {
				right = middle - 1;
			} else {
				left = middle + 1;
			}
		}
		if (pred(elements[right])) {
			return right;
		}
		return -1;
	}

	T& operator[](int index) {
		if ((index > size()) || (index < 1)) {
			throw std::out_of_range("Индекс вне диапазона!");
		}
		return elements[index - 1];
	}

	//сортировка по критерию
	void SortElemsBy(bool comp(T, T)) {
		std::sort(elements.begin(), elements.end(), comp);
	}

	//вывод
	friend std::ostream& operator<<(std::ostream& cout, TemplateContainer<T> cont) {
		if (cont.size() == 0) {
			cout << "Записи не обнаружены!" << std::endl;
			return cout;
		}
		int i = 1;
		for (TemplateContainer<T>::iterator iter = cont.begin(); iter != cont.end(); ++iter, ++i) {
			if (iter != cont.begin()) {
				cout << std::endl;
			}
			cout << "Запись № " << std::to_string(i) << std::endl << *iter << std::endl;
		}
		return cout;
	}

	//вывод в файл
	void print_to_file(std::string file_name) {
		std::ofstream fout(file_name);
		if (!fout.is_open()) {
			throw std::invalid_argument("Не удалось открыть файл на запись!");
		}

		for (TemplateContainer<T>::iterator iter = elements.begin(); iter != elements.end(); ++iter) {
			if (iter != elements.begin()) {
				fout << std::endl;
			}
			fout << *iter;
		}
		fout.close();
	}

	//чтение из файла
	bool read_from_file(std::string file_name) {
		std::ifstream fin(file_name);
		if (!fin.is_open()) {
			throw std::invalid_argument("Не удалось открыть файл для чтения!");
		}

		T buf;
		bool result = true;
		while (!fin.eof()) {
			try {
				fin >> buf;
				Add(buf);
			}
			catch (std::exception e) {
				result = false;
			}
		}
		return result;
	}

	~TemplateContainer() {
		elements.clear();
	};
};

