// Написать программу обработки одномерного массива с n элементами, в соответствии с
// вариантом(приложение А).Необходимые действия должны производиться в
// функции processArray(), возвращающей определенное значение и формирующей
// еще один(выходной) массив данных(см.свой вариант).Память под массивы
// выделять статически(объявлять массивы локально в функции main) и для доступа к
// элементам использовать индексы.Ввод - вывод данных организовать средствами cstdio.
//                             Варинт №7
// Объявить массив из n = 15 вещественных чисел, проинициализировать нулями. Функция
// processArray() должна заполнить массив случайными числами от 20.0 до 100.0, а
// затем вычесть из каждого элемента массива минимальное значение в массиве. Это
// значение она также должна вернуть на выходе. Сформировать выходной
// вещественный массив, в котором все элементы, стоящие до позиции минимального
// элемента включительно, повторяют элементы входного массива, а остальные равны
// минимальному элементу массива.Вывести на экран результирующие массивы.
//  Вход:
//  [38 79 68 29 65 43 85 93 72 80 37 23 31 92 83]
//  Выход :
//	min Item = 23
//	[15 56 45 6 42 20 62 70 49 57 14 0 8 69 60]
//  [38 79 68 29 65 43 85 93 72 80 37 23 23 23 23]

#include <cstdio>
#include <cstdlib>
double processArray(double* array, double* resArray, size_t n) {

	for (size_t i = 0; i < n; i++)
	{
		array[i] = (double)(rand() % 80) + 20;
	}
	double minValue = 101;
	int minValuePos = 0;
	for (size_t i = 0; i < n; i++)
	{
		if (array[i] < minValue) {
			minValue = array[i];
			minValuePos = i;
		}
	}
	for (size_t i = 0; i < n; i++)
	{
		if (i < minValuePos) {
			resArray[i] = array[i];
		}
		else {
			resArray[i] = minValue;
		}
		array[i] -= minValue;
	}
	return minValue;
}
void printArray(double* array, size_t n) {
	for (size_t i = 0; i < n; ++i)
	{
		printf("%g ", array[i]);
	}
	printf("\n");
}
int main() {
	const size_t n = 15;

	double array[n] = {  };
	double resArray[n] = {  };

	srand(0);

	double minItem = processArray(array, resArray, n);

	printf("min Item = %g\n", minItem);
	printArray(array, n);
	printArray(resArray, n);
	return 0;
}