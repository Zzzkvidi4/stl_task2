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

	//�����������
	TemplateContainer<T>() {
		elements = std::vector<T>();
	};

	//������� � �����
	TemplateContainer<T>& Add(T elem) {
		elements.push_back(elem);
		return *this;
	}

	//�������� �� �������
	TemplateContainer<T>& Erase(int index) {
		if (index >= elements.size()) {
			throw std::out_of_range("������ ��������� ��� ���������!")
		}
		elements.erase(elements.begin() + index - 1);
		return *this;
	}

	//������� ��������� �� ��������
	TemplateContainer<T>& GetElemsIf(bool pred) {
		TemplateContainer<T>* result = new TemplateContainer<T>();
		std::copy_if(elements.cbegin(), elements.cend, result->elements.begin(), pred);
		return *result;
	}

	//������� ��������� �� �������� � ��������������� �����������
	TemplateContainer<T>& GetElemsIfBinary(bool comp, bool pred, T val) {
		TemplateContainer<T>* result = new TemplateContainer<T>();
		SortElemsBy(comp);
		TemplateContainer<T>::iterator iter = BinarySearch(comp, pred, val);
		if (iter != end()) {
			for (TemplateContainer<T>::iterator it = iter; it != end(); ++it) {
				result->Add(*it);
			}
			for (TemplateContainer<T>::iterator it = iter - 1; (it != begin()) && (pred(*it); --it) {
				result->Add(*it);
			}
		}
	}

	//�������� ����� �� ����������
	TemplateContainer<T>::iterator& BinarySearch(bool comp, bool pred, T val) {
		int left = 0, right = elements.size - 1, middle;
		if (right == -1) {
			return end();
		}
		while (left < right) {
			middle = left + (right - left) / 2;
			if (comp(elements[middle], val)) {
				right = middle + 1;
			} else {
				left = middle;
			}
		}
		if (pred(right)) {
			return begin() + right;
		}
		return end();
	}

	//���������� �� ��������
	void SortElemsBy(bool comp) {
		std::sort(elements.begin(), elements.end(), comp);
	}

	//�����
	friend std::ostream& operator<<(std::ostream& cout, TemplateContainer<T> cont) {
		int i = 1;
		for (TemplateContainer<T>::iterator iter = cont.begin(); iter != cont.end(); ++iter, ++i) {
			cout << "������ � " << std::to_string(i) << std::endl << *iter << std::endl;
		}
		return cout;
	}

	//����� � ����
	void print_to_file(std::string file_name) {
		std::ofstream fout(file_name);
		if (!fout.is_open()) {
			throw std::invalid_argument("�� ������� ������� ���� �� ������!");
		}

		for (TemplateContainer<T>::iterator iter = elements.begin(); iter != elements.end(); ++iter) {
			if (iter != elements.begin()) {
				fout << std::endl;
			}
			fout << *iter;
		}
		fout.close();
	}

	//������ �� �����
	bool read_from_file(std::string file_name) {
		std::ifstream fin(file_name);
		if (!fin.is_open()) {
			throw std::invalid_argument("�� ������� ������� ���� ��� ������!")
		}

		std::string buf;
		bool result = true;
		while (!fin.eof()) {
			std::getline(fin, buf);
			try {
				Add(T(buf));
			}
			catch (std::exception e) {
				throw std::invalid_argument(e.what());
			}
		}
	}

	~TemplateContainer() {
		elements.clear();
	};
};

