#pragma once
#include <iostream>
#include <vector>

template<class T>
class Cache
{
	std::vector<T> cache_;
public:
	void put(T elem)
	{
		cache_.push_back(elem);
	}
	void operator+=(T elem)
	{
		cache_.push_back(elem);
	}
	bool contains(T elem)
	{
		return std::find(cache_.begin(), cache_.end(), elem) != cache_.end();
	}
};

template<>
class Cache<std::string>
{
	std::vector<std::string> cache_;
public:
	bool contains(std::string elem)
	{
		for (auto& i : cache_)
		{
			if (elem[0] == i[0]) {
				return true;
			}
			else {
				return false;
			}
		}
	}
	void put(std::string elem)
	{
		try
		{
			if (cache_.size() < 101) {
				cache_.push_back(elem);
			}
			else {
				throw cache_.size();
			}
		}
		catch (...)
		{
			std::cout << "Error! Maximum number of lines reached!" << std::endl;
		}
	}
	void operator+=(std::string elem)
	{	
		cache_.push_back(elem);
	}
};

