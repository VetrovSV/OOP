/// Файл с описанием функций логики предметной области: вычисление процентов по вкладам

#pragma once
#include <math.h>

///  вычисляет доход по вкладу с начальной суммой sum за time едениц времени и perc процентов в ед. времени
float calc_profit(float sum, float time, float perc) {
	return sum * powf( 1 + perc / 100, time) - sum;
}