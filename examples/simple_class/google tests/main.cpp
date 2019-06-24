#include <gtest/gtest.h>
#include "../seconds.h"

// Это отдельный проект для модульного тестирования
// - В него нужно скопировать папки include и src из google test
// - Добавить почти все файлы из src в этот проект (см. pro файл)
// - Добавить путь к заголовочным файлам google test (см. pro файл)

// Справка по google test:
// https://github.com/google/googletest/blob/master/googletest/docs/advanced.md


// Для запуска тестов можно запустить проект


// TEST - это макрос для объявления тестовой функции
// Первый параметр - название теста, второй - название части теста
// Здесь тестируется класс Seconds, конструктор
TEST( SecondsTest, constructor ){
  {   // отдельные проверки должны быть в отдельных блоках,
      // чтобы исклюить влияние одних проверок на другие
      Seconds s;
      ASSERT_EQ(s.seconds(), 0);   }

  {   Seconds *s = new Seconds;
      ASSERT_EQ(s->seconds(), 0);
      delete s;}

  {   Seconds *s = new Seconds(5);
      ASSERT_EQ(s->seconds(), 5);
      delete s;}

  {   Seconds s(0);
      ASSERT_EQ(s.seconds(), 0);   }

  {   Seconds s(42);
      ASSERT_EQ(s.seconds(), 42);  }

  {   Seconds s(59);
      ASSERT_EQ(s.seconds(), 59);  }

      // Ожидать искоючение: Seconds s(60) должен бросить исключение типа SecondsException
      ASSERT_THROW ( Seconds s(60), SecondsException);

      ASSERT_THROW( Seconds s(100), SecondsException);

      ASSERT_THROW( Seconds s(-1),  SecondsException);

      ASSERT_THROW( Seconds s(-100), SecondsException);
}


TEST( SecondsTest, setSeconds) {
    {   Seconds s;
        s.setSeconds(0);
        ASSERT_EQ(s.seconds(), 0);   }

    {
        Seconds s;
        s.setSeconds(42);
        ASSERT_EQ(s.seconds(), 42);  }

    {
        Seconds s;
        s.setSeconds(59);
        ASSERT_EQ(s.seconds(), 59);  }

    ASSERT_THROW( Seconds s; s.setSeconds(60), SecondsException);

    ASSERT_THROW( Seconds s; s.setSeconds(100), SecondsException);

    ASSERT_THROW( Seconds s; s.setSeconds(-1), SecondsException);

    ASSERT_THROW( Seconds s; s.setSeconds(-100), SecondsException);

}


TEST( SecondsTest, toString ){
    {   Seconds s(0);
        ASSERT_EQ(s.toString(), "0");   }

    {   Seconds s(5);
        ASSERT_EQ(s.toString(), "5");   }

    {   Seconds s(59);
        ASSERT_EQ(s.toString(), "59");   }
}


TEST( SecondsTest, plus_operator ){
    {   Seconds s1(13), s2(20);
        Seconds s = s1 + s2;
        ASSERT_EQ( s.seconds(),   33 );
    }

    {   Seconds s1(0), s2(20);
        Seconds s = s1 + s2;
        ASSERT_EQ( s.seconds(),   20 );
    }

    {   Seconds s1(0), s2(0);
        Seconds s = s1 + s2;
        ASSERT_EQ( s.seconds(),   0 );
    }

    {   Seconds s1(10), s2(49);
        Seconds s = s1 + s2;
        ASSERT_EQ( s.seconds(),   59 );
    }

    {   Seconds s1(10), s2(50);
        Seconds s = s1 + s2;
        ASSERT_EQ( s.seconds(),   0 );
    }
}


TEST( SecondsTest, increment_operator ){
    {   Seconds s;
        s++;
        ASSERT_EQ(s.seconds(),   1); }

    {   Seconds s(2);
        s++;
        ASSERT_EQ(s.seconds(),   3);}

    {   Seconds s(58);
        s++;
        ASSERT_EQ(s.seconds(),   58);}

    {   Seconds s(59);
        s++;
        ASSERT_EQ(s.seconds(),   0);}
}


TEST( SecondsTest, plus_increment ){
    Seconds s1, s2(12);
    Seconds s3 = s1 + s2++;
    ASSERT_EQ (s3.seconds(),   12);
    ASSERT_EQ (s2.seconds(),   13);
}


int main(int argc, char *argv[])
{
    ::testing::InitGoogleTest();
    // Будут запущены все тесты которые хдесь объявлены
    return RUN_ALL_TESTS();
}

// Запускать тесты можно как обычное приложение
// Но можно и через меню Инструменты - Тесты - Запустить всё.
// В этом случае вывод тестов интегрируется в Qt Creator (панель Результаты тестирования)
