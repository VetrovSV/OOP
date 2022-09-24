#include <iostream>
#include <iomanip>		// для настроек ввода и вывода


using namespace std;


/// выводит двумерный массив (матрицу) arr размерности rows x cols на экран
void print_matr(int** arr, unsigned rows, unsigned cols){
		// в функцию передаётся указатель на массив из массивов
		// поэтому его элементы можно изменить при желании
		for (int i = 0; i < rows; ++i){
			for (int j = 0; j < cols; ++j)
				cout << setw(11) << arr[i][j] << " ";		// вывод числа в поле шириной 11 символов
			cout << "\n";}
}

int main()
{
	
	const unsigned N = 10;				// число строк
	const unsigned M = 4;				// число столбцов

	// выделение памяти под двумерный массив
	// двумерный массив -- это массив из массивов
	int * *matr = new int*[N];	
	// выделение памяти под двумерный массивы (строки матрицы)
	for (int i = 0; i < N; ++i)
		matr[i] = new int[M];

	print_matr(matr, N, M);

	// освбождение памяти
	for (int i = 0; i < N; ++i)
		delete[] matr[i];
	delete[] matr;

	return 0;
}