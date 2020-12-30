#pragma once
#include <vector>
#include <iterator>
#include <iostream>
#include <fstream>

template<class T>
class DataManager
{
	std::vector<T> data_;
public:
	void push(T elem) {
		if (data_.size() < 64) {
			if (data_.size() != 0) {
				auto iter = data_.begin();
				for (size_t i = 0; i < data_.size(); ++i)
				{
					if (elem < data_[i]) {
						iter++;
					}
					else {
						break;
					}
				}
				data_.insert(iter, elem);
			}
			else {
				data_.push_back(elem);
			}
		}
		else {
			serialize();
			data_.clear();
			data_.push_back(elem);
		}
	}
	void push(T elems[], size_t n) {
		for (size_t i = 0; i < n; ++i)
		{
			push(elems[i]);
		}
	}
	T peek() {
		if (data_.size() > 2) {
			return data_[1];
		}
		else {
			return 0;
		}
	}
	T pop() {
		if (data_.size() != 0) {
			T elem = data_.front();
			data_.erase(data_.begin());
			return elem;
		}
		return 0;
	}
	void serialize() {
		std::ofstream fout("dump.dat");
		for (int i = 0; i < data_.size(); ++i) {
			fout << data_[i] << std::endl;
		}
		fout.close();
	}
	void print() {
		std::ostream_iterator<T> cout_it(std::cout, " ");
		std::copy(data_.begin(), data_.end(), cout_it);
	}
};


template <>
class DataManager<char> {
	std::vector<char> dataChar_;
public:
	void push(char elem) {
		if (elem == ',' || elem == '.' || elem == '!' || elem == '?' || elem == ':' || elem == ';' || elem == '-') {
			elem = '_';
		}
		if (dataChar_.size() < 64) {
			if (dataChar_.size() != 0) {
				auto iter = dataChar_.begin();
				for (size_t i = 0; i < dataChar_.size(); ++i)
				{
					if (elem < dataChar_[i]) {
						iter++;
					}
					else {
						break;
					}
				}
				dataChar_.insert(iter, elem);
			}
			else {
				dataChar_.push_back(elem);
			}
		}
		else {
			serialize();
			dataChar_.clear();
			dataChar_.push_back(elem);
		}
	}
	void push(char elems[], size_t n) {
		for (int i = 0; i < n; ++i) {
			push(elems[i]);
		}
	}
	char peek() {
		if (dataChar_.size() > 2) {
			return dataChar_[1];
		}
		else {
			return 0;
		}
	}
	char pop() {
		if (dataChar_.size() != 0) {
			char elem = dataChar_.front();
			dataChar_.erase(dataChar_.begin());
			return elem;
		}
		return 0;
	}
	char popUpper() {
		return toupper(pop());
	}
	char popLower() {
		return tolower(pop());
	}

	void serialize() {
		std::ofstream fout("dump.dat");
		for (int i = 0; i < dataChar_.size(); ++i) {
			fout << dataChar_[i] << std::endl;
		}
		fout.close();
	}
	void print() {
		std::ostream_iterator<char> cout_it(std::cout);
		std::copy(dataChar_.begin(), dataChar_.end(), cout_it);
	}
};


