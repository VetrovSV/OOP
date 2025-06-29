/**
 * @file main.c
 * @brief Пример использования автоматических тестов через библиотеку Unity
 * 
 * Библиотека Unity: https://www.throwtheswitch.org/unity#unity-get-section 
 * См. файлы библиотеки в папке unity
 */

#include "unity/unity.h"


/// Вычисляет путь, который пройдёт точка, за время t двигаясь с начальной скоростью v0 и постоянным ускорением a
float calc_path(float v0, float a, float t){
    return v0*t + a / 2 * t*t;
}

// setUp - функция, которая вызывается для настройки окружения перед тестом. Может быть пустой.
// tearDown - аналогично setUp, но вызывается вызывать после теста.
void setUp(void)   { /* ... */ }
void tearDown(void){ /* ... */ }


void TEST_calc_path_normal() {
    TEST_ASSERT_EQUAL_FLOAT( calc_path(1.0, 1.0, 10.0), 60.0 );
}

int main(){
    UNITY_BEGIN();
    RUN_TEST(TEST_calc_path_normal);
    return UNITY_END();
}


/*
Компиляция:
    clang -o main my_tests.c unity/unity.c --std=c23

Результат запуска тестов:
    main.c:29:TEST_calc_path_normal:PASS

    -----------------------
    1 Tests 0 Failures 0 Ignored 
    OK

*/