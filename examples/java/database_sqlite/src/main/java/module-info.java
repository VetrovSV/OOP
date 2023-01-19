// Это дискриптор модуля
// Модуль -- набор связанных пакетов и Ресурсов. Модули появились в Java 9.
// Подробнее: https://habr.com/ru/post/499872/

module com.example.database_sqlite {

    // requires -- зависимости модуля
    requires javafx.controls;
    requires javafx.fxml;
    requires java.sql;

    // открыть reflection доступ к com.example.database_sqlite из пакета javafx.fxml
    opens com.example.database_sqlite to javafx.fxml;

    // пакеты, которые экспортирует этот модуль
    exports com.example.database_sqlite;
}



// Рефлексия (reflection) -- возможность отслеживать и модифицировать собственную структуру и поведение во время выполнения.
// к рефлексии относится получение информации о членах класса, изменение их области видимости, изменение самих членов класса и др.
