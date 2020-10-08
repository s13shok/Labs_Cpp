// Написать свой аналог стандартной функции обработки строк из файла cstring, в
// соответствии с вариантом. В функции main на тестовых данных продемонстрировать
// результат работы как стандартной функции, так и собственной версии. Ввод - вывод
// данных организовать средствами cstdio.
//                             Варинт №7
// Функция strchr.
// Формат char* strchr(char* s, int c).
// Функция находит в строке s первое вхождение символа с и возвращает подстроку,
// начинающуюся с этого символа.
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstring>
char* myStrchr(char* s, int c, int length) {
	int substrLength = 0;
	bool isFound = false;
	for (size_t i = 0; i < length; i++)
	{
		if (s[i] == c) {
			substrLength = length - i;
			isFound = true;
			break;
		}
	}
	if (isFound) {
		char* substring = new char[substrLength];
		for (size_t i = 0; i < substrLength; i++)
		{
			substring[i] = s[length - substrLength + i];
		}
		return substring;
	}
	else {
		return nullptr;
	}
	return 0;
}
int main() {
	char string[100] = "sc 2 lotv";
	std::printf("Find a substring in a string:\"%s\"\n",string);

	char letter;
	std::scanf("%c", &letter);

	char* systemOutput = strchr(string, (int)letter);
	std::printf("%s\n", systemOutput);

	char* myOutput = myStrchr(string, (int)letter, sizeof(string) / sizeof(char));
	std::printf("%s\n", myOutput);
	delete[] myOutput;
	return 0;
}