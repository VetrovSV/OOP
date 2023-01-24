/// Программа для тестов. Запускается отдельно программой ctest
// Таких программ для тестов может быть несколько

#include <cassert>
#include <iostream>
#include "geometry.h"
// этот файл находится в другой папке, но благодаря настройкам в CMakeLists.txt при сборке не возникает проблем

const double eps = 1e-6;

int int main(int argc, char const *argv[]){	
	// можно подавать тестовые данные через параметры и запускать эту программу несколько раз

	assert( abs( hypotenuse(  3,  4) -   5.0        ) < eps );
	assert( abs( hypotenuse(  1,  1) -   1.41421356 ) < eps );
	assert( abs( hypotenuse(132, 14) - 132.740348048) < eps );

	std::cout << "TEST [OK]\n";

	return 0;
}