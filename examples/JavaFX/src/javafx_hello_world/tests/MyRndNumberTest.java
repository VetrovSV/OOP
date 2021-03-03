package javafx_hello_world.tests;

import javafx_hello_world.MyRndNumber;

import static org.junit.jupiter.api.Assertions.*;
// junit скорее всего придётся скачать: alt+Enter на junit > Add JUnit5 to classpath > окно скачивания: Ok
// пакет скачается и сохранится в папку с вашим проектом


// Создание этого теста: https://www.jetbrains.com/help/idea/create-tests.html
// Запуск теста: в дереве проекта выбрать тест > нажать ПКМ > Run ...

public class MyRndNumberTest {

    @org.junit.jupiter.api.Test
    public void setMax() {
        MyRndNumber num = new MyRndNumber();
        num.setMax(1001);
        assertEquals(1001, num.getMax());
    }

    @org.junit.jupiter.api.Test
    public void setMin() {
        // todo: доделать тест
    }
}