#pragma once
#include "stdafx.h"
#include "BaseFunctor.h"
#include <functional>

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
	size_t size() {
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
	TemplateContainer<T>* GetElemsIf(BaseFunctor<T>* func) {
		TemplateContainer<T>* result = new TemplateContainer<T>();
		std::copy_if(elements.begin(), elements.end(), std::back_inserter(result->elements), std::bind1st(std::mem_fun(&BaseFunctor<T>::operator()), func));
		for (TemplateContainer<T>::iterator it = result->begin(); it != result->end(); ++it) {
			elements.erase(std::remove(elements.begin(), elements.end(), *it));
		}
		return result;
	}

	//выборка элементов по критерию с предварительной сортировкой
	TemplateContainer<T>* GetElemsIfBinary(BaseFunctor<T>* func) {
		TemplateContainer<T>* result = new TemplateContainer<T>();
        std::function<bool(T, T)> comp = func->GetComparator();
		SortElemsBy(comp);
		int start = BinarySearch(comp, std::bind1st(std::mem_fun(&BaseFunctor<T>::operator()), func), func->GetValue());
		if (start != -1) {
			for (TemplateContainer<T>::iterator it = begin() + start; (it != end()) && (func->operator()(*it)); ++it) {
				result->Add(*it);
			}
			for (TemplateContainer<T>::iterator it = begin() + start - 1; (it != begin()) && (func->operator()(*it)); --it) {
				result->Add(*it);
			}
		}
		for (TemplateContainer<T>::iterator it = result->begin(); it != result->end(); ++it) {
			elements.erase(std::remove(elements.begin(), elements.end(), *it));
		}
		return result;
	}

	void PushBack(TemplateContainer<T>* cont) {
		for (TemplateContainer<T>::iterator it = cont->begin(); it != cont->end(); ++it) {
			this->Add(*it);
		}
	}

	//бинарный поиск по контейнеру
	template<typename Pred>
	int BinarySearch(std::function<bool(T,T)> comp, Pred pred, T val) {
		size_t left = 0, right = elements.size() - 1, middle;
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
	void SortElemsBy(std::function<bool(T,T)> comp) {
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
		for (TemplateContainer<T>::iterator iter = elements.begin(); iter != elements.end() - 1; ++iter) {
			*out++ = *iter;
		}
		fout << *(elements.end() - 1);
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

