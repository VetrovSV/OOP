# SQLite + Java + JavFX

Необходимые пакеты и файлы
```java
import java.sql.Connection;     // класс для подключения и взаимодействия с CУБД
import java.sql.DriverManager;  // класс для создания подключений
import java.sql.SQLException;
import java.sql.Statement;      // класс для выполнения SQL запросов
import java.sql.ResultSet;      // класс для хранения результатов запроса

// java.sql не подключается по умолчанию.
// в файл module-info.java (дискриптор модуля проекта) нужно добавить requires java.sql;
// см. Модули в Java

// JDBC (Java DataBase Connectivity) -- стандарт взаимодействия с СУБД;
// всё взаимодействие происходи через специальный драйвер. Для каждой СУБД он свой.
// скачать JDBC драйвер (jar файл) для sqlite: https://mvnrepository.com/artifact/org.xerial/sqlite-jdbc
// добавить драйвер в проект: Project Structure >
//      Project Settings | Modules | вкладка Dependencies |
//      + > As JARs > выбрать jar файл драйвера 
```
<br>

Подключение
```java
// объект для подключения к СУБД ( использует JDBC драйвер )
Connection db_con;

// строка подключения (конфигурация подключения): название_стандарта:название_драйвера:имя_sqlite_файла
String con_str = "jdbc:sqlite:my_sqlite.db";

try {
    // подключение
    db_con = DriverManager.getConnection(con_str);
    // если sqlite файла не существует, то он будет создан (полностью путысм) 
    
} catch (SQLException e) {
    System.out.println(e.toString());
}
```

<br>

Создание таблицы
```java
try {
    Statement create = db_con.createStatement();
    create.execute("create table students  (" +
        "id integer constraint table_name_pk primary key autoincrement " +
        ",name       text not null" +
        ",UML        real" +
        ",Model      real" +
        ",ui         real" +
        ",Controller real);" );
    System.out.println("DB created");
} catch (SQLException e) {
    e.printStackTrace();
    throw new RuntimeException(e);
}
```

Полученые данных
```java
try {
    // объект для SQL запросов
    Statement stmt = db_con.createStatement();
    // выполнение запроса
    ResultSet resultSet = stmt.executeQuery("select * from students;");
    
    // получение записей
    while (resultSet.next()){
        // получение данных из полей
        System.out.print(   resultSet.getLong(1) + "; ");     // нумерация полей начинается с единицы
        System.out.print(   resultSet.getString(2) + "; " );
        System.out.print(   resultSet.getDouble(3) + "; " );
        System.out.print(   resultSet.getDouble(4) + "; " );
        System.out.print(   resultSet.getDouble(5) + "; " );
        System.out.println( resultSet.getDouble(6) );
        }
} catch (SQLException e) {
    System.out.println( e.toString() );
    throw new RuntimeException(e);
}
```


# Ссылки
- Документация по пакету SQL https://docs.oracle.com/en/java/javase/17/docs/api/java.sql/java/sql/package-summary.html
- Памятка/шпаргалка по SQL https://habr.com/ru/post/564390/
- JDBC драйвер (jar файл) для sqlite: https://mvnrepository.com/artifact/org.xerial/sqlite-jdbc
