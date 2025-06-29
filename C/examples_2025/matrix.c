#include <stdio.h>
#include <stdlib.h>


void matrix_random_fill(int** mat, size_t rows, size_t cols) {
	// Заполнение матрицы случайными числами
	for (size_t i = 0; i < rows; i++)			// перебор номеров строк
		for (size_t j = 0; j < cols; j++)		// перебор номеров столбцов (элементов внутри строки)
			mat[i][j] = rand() % 10;

}

void matrix_static_random_fill(int mat[124][124]) {
	// Заполнение матрицы случайными числами
	for (size_t i = 0; i < 124; i++)			// перебор номеров строк
		for (size_t j = 0; j < 124; j++)		// перебор номеров столбцов (элементов внутри строки)
			mat[i][j] = rand() % 10;

}

int main() {

	size_t n = 4;	// число строк
	size_t m = 3;	// число  столбцов

	int matr2[124][124];
	matrix_static_random_fill(matr2);

	int matr3[123][123];
	matrix_static_random_fill(matr3);		// ошибка!

	//// одномерный динамический массив
	//int *arr = malloc( n * sizeof(int) );
	//free(arr);

	// Выделение памяти для динамического двумерного массива (матрица)
	// двумерный динамический массив - матрица
	int **matr = malloc(n * sizeof(int*));		// выделена память под n указателей на массивы
	for (size_t i = 0; i<n; i++)	// перебор номеров строк
		matr[i] = malloc(m * sizeof(int));		// выделение памяти под строку матрицы

	//// Заполнение матрицы случайными числами
	//for (size_t i = 0; i < n; i++)			// перебор номеров строк
	//	for (size_t j = 0; j < m; j++)		// перебор номеров столбцов (элементов внутри строки)
	//		matr[i][j] = rand() % 10;
	matrix_random_fill(matr, n, m);

	// вывод матрицы на экран
	for (size_t i = 0; i < n; i++) {		// перебор номеров строк
		for (size_t j = 0; j < m; j++)		// перебор номеров столбцов (элементов внутри строки)
			printf("%3d", matr[i][j]);
		puts("");
	}

	// Освобождение памяти матрицы
	for (size_t i = 0; i < n; i++)	// освобождение памяти строк
		free(matr[i]);
	free(matr);					// освобождение памяти массива указателей на строки
	matr = NULL;
	

	return 0;
}

