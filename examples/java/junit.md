# JUnit
<img src="https://upload.wikimedia.org/wikipedia/commons/thumb/5/59/JUnit_5_Banner.png/440px-JUnit_5_Banner.png" width="200"  />


**JUnit** -- фреимворк для автоматического модульного тестирования.
- Последняя версия: 5.9.2
- [junit.org/junit5](https://junit.org/junit5/)
  - Руководство: https://junit.org/junit5/docs/current/user-guide/
- имя зависимости для подключения: `org.junit.jupiter:junit-jupiter`


```Java
import org.junit.jupiter.api.DisplayName;
import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;       // assertEquals

class MyTest {
    // @Test -- аннотация, помечает метод как тест
    // @DisplayName -- аннотация, задающая понятное, текстовое название теста
    @Test
    @DisplayName("Add two numbers")
    void test_sum(){
        assertEquals(4, 2+2);
    }
}
```

# Ссылки
- Туториал по JUnit 5  - Введение [habr.com/ru/post/590607](https://habr.com/ru/post/590607)
- [junit.org/junit5](https://junit.org/junit5/)
  - Руководство: https://junit.org/junit5/docs/current/user-guide/
- Создание тестов в IntelliJ IDEA - https://www.jetbrains.com/help/idea/junit.html
