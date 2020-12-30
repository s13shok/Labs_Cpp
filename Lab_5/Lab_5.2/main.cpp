//  Ќаписать код дл€ чтени€ произвольного текстового файла и вывода на экран всех слов
//  размером более 3 букв, встречающихс€ в нем не менее 7 раз, в пор€дке убывани€
//  частоты встречаемости(приложение ј).¬ качестве разделителей слов рассматривать
//  пробел, точку, зап€тую, тире, двоеточие, восклицательный знак, точку с зап€той.
//  »спользовать контейнер std::map.

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <algorithm>
#include <string>

int main()
{
	std::map<std::string, int> map;
	std::ifstream file("sonnets.txt", std::ios::app);
	if (file.is_open())
	{
		while (file.peek() != -1)
		{
			const std::size_t length = 1024;
			char data[length];
			file.getline(data, length);
			char* substring = std::strtok(data, " .,-:!;");
			while (substring != 0)
			{
				std::string word = substring;
				std::transform(word.begin(), word.end(), word.begin(), std::tolower);
				auto it = map.find(word);
				if (it == map.end()) {
					map.insert(std::make_pair(word, 1));
				}
				else {
					map[word]++;
				}
				substring = std::strtok(0, " .,-:!;");
			}
		}
		file.close();
	}

	std::map <std::string, int> ::iterator iter = map.begin();
	std::multimap<int, std::string, std::greater<int>> sorted_map;
	for (size_t i = 0; iter != map.end(); ++iter, ++i) {
		if (iter->first.length() > 3 && iter->second > 6) {
			sorted_map.insert(std::make_pair(iter->second, iter->first));
		}
	}

	for (auto const& entry : sorted_map)
	{
		std::cout << entry.second << " " << entry.first << std::endl;
	}

	return 0;
}
