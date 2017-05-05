#pragma once
#include "stdafx.h"

template<typename T>
class TemplateContainer{
private:
	std::vector<T> elements;
public:
	typedef typename std::vector<T>::iterator iterator;

	iterator begin() {
		return elements.begin();
	}

	iterator end() {
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
		if (index > elements.size()) {
			throw std::out_of_range("Индекс находится вне диапазона!");
		}
		elements.erase(elements.begin() + index - 1);
		return *this;
	}

	void clear() {
		elements.clear();
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
		std::ostream_iterator<T> cout_it(cout, "\r\n");
		for (TemplateContainer<T>::iterator iter = cont.begin(); iter != cont.end(); ++iter, ++i) {
			cout << "\r\nЗапись № " << std::to_string(i) << std::endl;
			*cout_it++ = *iter;
		}
		return cout;
	}

	//вывод в файл
	void print_to_file(std::string file_name) {
		std::ofstream fout(file_name);
		if (!fout.is_open()) {
			throw std::invalid_argument("Не удалось открыть файл на запись!");
		}
		std::ostream_iterator<T> out(fout, "\r\n");
		for (TemplateContainer<T>::iterator iter = elements.begin(); iter != elements.end(); ++iter) {
			*out++ = *iter;
		}
		fout.close();
	}

	//чтение из файла
	bool read_from_file(std::string file_name) {
		std::ifstream fin(file_name);
		if (!fin.is_open()) {
			throw std::invalid_argument("Не удалось открыть файл для чтения!");
		}

		std::istream_iterator<T> in(fin);
		T buf;
		bool result = true;
        bool is_correct = true;
		while (!fin.eof()) {
			try {
                if (is_correct) {
                    Add(*in);
                }
                is_correct = true;
                in++;
			}
			catch (std::exception e) {
				result = false;
                is_correct = false;
			}
		}
        if (is_correct) {
            Add(*in);
        }
		return result;
	}

	~TemplateContainer() {
		elements.clear();
	};
};

