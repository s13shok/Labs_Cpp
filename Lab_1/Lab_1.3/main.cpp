// �������� ���� ������ ����������� ������� ��������� ����� �� ����� cstring, �
// ������������ � ���������. � ������� main �� �������� ������ ������������������
// ��������� ������ ��� ����������� �������, ��� � ����������� ������. ���� - �����
// ������ ������������ ���������� cstdio.
//                             ������ �7
// ������� strchr.
// ������ char* strchr(char* s, int c).
// ������� ������� � ������ s ������ ��������� ������� � � ���������� ���������,
// ������������ � ����� �������.
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