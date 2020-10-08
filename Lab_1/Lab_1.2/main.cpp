// Написать программу, которая преобразует одномерный массив(1D) в двумерный(2D)
// (или наоборот), в соответствии с вариантом. Необходимо оформить в отдельных
// функциях код следующих действий : 1) инициализация массива; 2) вывод массива; 3)
// преобразование массива(создание нового массива с другой структурой). Память под
// массивы выделять динамически и для доступа к элементам использовать указатели.
// Ввод - вывод данных организовать средствами iostream и iomanip.
//                             Варинт №7
// Преобразование: 2D → 1D.Двумерный массив 5х5 целых чисел необходимо выложить
// в один ряд по элементам слева направо и сверху вниз, исключая все элементы на
// нечетных строках.
// Инициализация : заполнить массив факториалами : x[i][j] = i!+ j!.
// Вывод на экран : на каждый элемент массива отвести 8 позиций.
// [  2   2   3   7  25
//    2   2   3   7  25
//    3   3   4   8  26
//    7   7   8  12  30
//   25  25  26  30  48 ]
//           =>
// [  2 2 3 7 25 7 7 8 12 30  ] 
#include <iostream>
#include <iomanip>
int factorial(int x) {
	if (x < 0 || x > 12) {
		return 0;
	}
	static const int table[] = { 1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880, 3628800, 39916800, 479001600 };
	return table[x];
}
void initializeArray(int** array, size_t rows, size_t columns) {
	int nol = 0;
	for (size_t i = 0; i < rows; ++i)
	{
		for (size_t j = 0; j < columns; ++j)
		{
			*(*(array + i) + j) = factorial(i) + factorial(j);
		}
	}
}
void printArray2D(int** array, size_t rows, size_t columns) {
	for (size_t i = 0; i < rows; ++i)
	{
		for (size_t j = 0; j < columns; ++j)
		{
			std::cout << std::setw(8) << *(*(array + i) + j);
		}
		std::cout << "\n";
	}
}
int* processArray(int** array, size_t rows, size_t columns, int* newLength) {
	*(newLength) = rows / 2 * columns;
	int* resultingArray = new int[(*newLength)];
	int position = 0;
	for (size_t i = 0; i < rows; ++i)
	{
		if (i % 2 != 0) {
			for (size_t j = 0; j < columns; ++j)
			{
				*(resultingArray + position) = *(*(array + i) + j);
				position++;
			}
		}
	}
	return resultingArray;
}
void printArray(int* array, size_t length) {
	for (size_t i = 0; i < length; ++i)
	{
		std::cout << *(array + i) << " ";
	}
	std::cout << "\n";
}
void deleteSubarrays(int** array, int number) {
	for (size_t i = 0; i < number; ++i)
	{
		delete[] * (array + i);
	}
	delete[] array;
}
void deleteArray(int* array) {
	delete[] array;
}
int main() {
	const size_t columns = 5;
	const size_t rows = 5;

	int** array2d = new int* [rows];
	for (size_t i = 0; i < rows; ++i)
	{
		*(array2d + i) = new int[columns];
	}

	initializeArray(array2d, rows, columns);
	printArray2D(array2d, rows, columns);
	int length = 0;
	int* resultingArray = processArray(array2d, rows, columns, &length);
	printArray(resultingArray, length);

	deleteSubarrays(array2d, columns);
	deleteArray(resultingArray);
	return 0;
}