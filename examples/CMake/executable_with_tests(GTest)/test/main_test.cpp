#include <gtest/gtest.h>

// Пример тестовой функции
TEST(HelloTest, BasicAssertions) {

	EXPECT_STRNE("hello", "world");		// проверка неравенства строк
	EXPECT_EQ(7 * 6, 42);				// проверка равенства чисел
}
