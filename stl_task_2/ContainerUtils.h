#pragma once
#include "stdafx.h"

template <typename T>
class ContainerUtils {
public:
	static std::ostream& print_to_console(std::ostream& cout, TemplateContainer<T> cont) {
		if (cont.size() == 0) {
			cout << "Записи не обнаружены!" << std::endl;
			return cout;
		}
		int i = 1;
		cout << "Количество записей: " << cont.size() << std::endl;
		std::ostream_iterator<T> cout_it(cout, "\r\n");
		for (TemplateContainer<T>::iterator iter = cont.begin(); iter != cont.end(); ++iter, ++i) {
			cout << "\r\nЗапись № " << std::to_string(i) << std::endl;
			*cout_it++ = *iter;
		}
		return cout;
	}

	static void print_to_file(std::ofstream& fout, TemplateContainer<T> cont) {
		if (!fout.is_open()) {
			throw std::invalid_argument("Не удалось открыть файл на запись!");
		}
		std::ostream_iterator<T> out(fout, "\r\n");
		for (TemplateContainer<T>::iterator iter = cont.begin(); iter != cont.end() - 1; ++iter) {
			*out++ = *iter;
		}
		fout << *(cont.end() - 1);
		fout.close();
	}

	static bool read_from_file(std::ifstream& fin, TemplateContainer<T>& cont) {
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
					cont.Add(*in);
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
			cont.Add(*in);
		}
		return result;
	}

};
