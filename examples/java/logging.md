# Логгирование 

#### **Библиотеки логирования**
1. **Log4j 2**  
   - **Популярность**: Очень высокая (мощный и гибкий инструмент).  
   - **Особенности**: Высокая производительность, асинхронное логирование, поддержка множества форматов конфигурации.  
   - **Ссылка**: [Apache Log4j 2](https://logging.apache.org/log4j/2.x/)

2. **SLF4J + Logback**  
   - **Популярность**: Широко используется (де-факто стандарт для многих проектов).  
   - **Особенности**:  
     - SLF4J — это фасад (абстракция), Logback — реализация.  
     - Удобный API, хорошая интеграция с другими библиотеками.  
   - **Ссылка**: [SLF4J](http://www.slf4j.org/), [Logback](https://logback.qos.ch/)

3. **java.util.logging (JUL)**  
   - **Популярность**: Средняя (встроен в JDK, но менее гибкий).  
   - **Особенности**: Не требует внешних зависимостей, простая настройка.  

4. **Tinylog**  
   - **Популярность**: Низкая, но растет.  
   - **Особенности**: Минималистичный, легковесный, простая настройка.  
   - **Ссылка**: [Tinylog](https://tinylog.org/v2/)

---

#### **Что выбрать?**
- **Для простоты**: `Tinylog` или `SLF4J + Logback`.  
- **Для производительности и гибкости**: `Log4j 2`.  
- **Без зависимостей**: `java.util.logging`.



# `java.util.logging` (JUL)

#### **Основные компоненты**
- **Logger**: основной объект для записи логов.
- **Handler**: куда отправляются логи (консоль, файл и т.д.).
- **Formatter**: форматирование сообщений (текст, XML).
- **Level**: уровень логирования (`SEVERE`, `WARNING`, `INFO`, `CONFIG`, `FINE`, `FINER`, `FINEST`).

---

#### **Быстрый старт**
```java
import java.util.logging.Logger;
import java.util.logging.Level;

public class Main {
    private static final Logger logger = Logger.getLogger(Main.class.getName());

    public static void main(String[] args) {
        logger.info("Старт программы");
        try {
            int result = 10 / 0;
        } catch (Exception e) {
            logger.log(Level.SEVERE, "Ошибка деления", e);
        }
    }
}
```

---

#### **Уровни логирования** (по возрастанию строгости)
| Уровень     | Описание                          |
|-------------|-----------------------------------|
| `FINEST`    | Детальная отладочная информация   |
| `FINER`     | Трассировка вызовов методов       |
| `FINE`      | Общая отладочная информация       |
| `CONFIG`    | Конфигурационные параметры        |
| `INFO`      | Информационные сообщения         |
| `WARNING`   | Предупреждения                    |
| `SEVERE`    | Критические ошибки                |

---

#### **Настройка через код**
```java
// Создать логгер
Logger logger = Logger.getLogger("MyLogger");

// Установить уровень
logger.setLevel(Level.FINE);

// Добавить обработчик для консоли
ConsoleHandler consoleHandler = new ConsoleHandler();
consoleHandler.setLevel(Level.ALL);
logger.addHandler(consoleHandler);

// Добавить обработчик для файла
FileHandler fileHandler = new FileHandler("app.log");
fileHandler.setFormatter(new SimpleFormatter());
logger.addHandler(fileHandler);
```

---

#### **Настройка через файл `logging.properties`**
1. Создайте файл `logging.properties` в папке `src/main/resources`.
2. Пример содержимого:
```properties
# Уровень глобального логгера
.level = INFO

# Обработчик для консоли
handlers = java.util.logging.ConsoleHandler

# Формат сообщений
java.util.logging.ConsoleHandler.formatter = java.util.logging.SimpleFormatter
java.util.logging.SimpleFormatter.format = [%1$tF %1$tT] [%4$s] %5$s %n

# Уровень для обработчика консоли
java.util.logging.ConsoleHandler.level = FINE
```

3. Загрузите конфиг при запуске:
```bash
java -Djava.util.logging.config.file=src/main/resources/logging.properties Main
```

---

#### **Плюсы и минусы JUL**
| **Плюсы**                          | **Минусы**                          |
|------------------------------------|-------------------------------------|
| Встроен в JDK (не нужны зависимости) | Менее гибкий, чем Log4j или Logback |
| Простая базовая настройка          | Сложная кастомизация форматов       |
| Подходит для небольших проектов    | Ограниченные возможности фильтрации |

---

#### **Советы**
1. **Используйте уровни адекватно**:  
   - `INFO` для ключевых событий.  
   - `SEVERE` только для критических ошибок.
2. **Избегайте логирования в цикле** — это замедлит работу.
3. **Для сложных проектов** лучше выбрать Log4j 2 или SLF4J + Logback.

