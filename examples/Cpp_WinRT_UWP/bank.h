/// ���� � ��������� ������� ������ ���������� �������: ���������� ��������� �� �������

#pragma once
#include <math.h>

///  ��������� ����� �� ������ � ��������� ������ sum �� time ������ ������� � perc ��������� � ��. �������
float calc_profit(float sum, float time, float perc) {
	return sum * powf( 1 + perc / 100, time) - sum;
}