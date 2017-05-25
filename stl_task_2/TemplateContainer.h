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

	//�����������
	TemplateContainer<T>() {
		elements = std::vector<T>();
	};

	std::vector<T>& Elems() {
		return elements;
	}

	//������ ����������
	size_t size() {
		return elements.size();
	}

	//������� � �����
	TemplateContainer<T>& Add(T elem) {
		elements.push_back(elem);
		return *this;
	}

	//�������� �� �������
	TemplateContainer<T>& Erase(int index) {
		if (index > elements.size()) {
			throw std::out_of_range("������ ��������� ��� ���������!");
		}
		elements.erase(elements.begin() + index - 1);
		return *this;
	}

	void clear() {
		elements.clear();
	}

	//������� ��������� �� ��������
	TemplateContainer<T>* GetElemsIf(BaseFunctor<T>* func) {
		TemplateContainer<T>* result = new TemplateContainer<T>();
		std::copy_if(elements.begin(), elements.end(), std::back_inserter(result->elements), std::bind1st(std::mem_fun(&BaseFunctor<T>::operator()), func));
		for (TemplateContainer<T>::iterator it = result->begin(); it != result->end(); ++it) {
			elements.erase(std::remove(elements.begin(), elements.end(), *it));
		}
		return result;
	}

	//������� ��������� �� �������� � ��������������� �����������
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

	//�������� ����� �� ����������
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
			throw std::out_of_range("������ ��� ���������!");
		}
		return elements[index - 1];
	}

	//���������� �� ��������
	void SortElemsBy(std::function<bool(T, T)> comp) {
		std::sort(elements.begin(), elements.end(), comp);
	}

	~TemplateContainer() {
		elements.clear();
	};
};

