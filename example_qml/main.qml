import QtQuick 2.0
import QtQuick.Window 2.2

// Подключение элементов интерфейса (версия 1.4)
import QtQuick.Controls 1.4
// Некоторые элементы интерфейса имеют разные свойства в разных версиях

// Подключение C++ класса
import calc 1.0

// Этот файл можно редактировать вручную, или воспользоватся Дазайнером Форм
// Он включает описание всего, что должно быть расположено на окне,
// описывает свойиства и поведение элементов интерфейса

// Также в QML файле могут быть использованы пользовательские C++ классы (здесь это calc)

// Каждый элемент интерфейса описывается своим типом (здесь Window)
// См. др. типы: http://doc.qt.io/qt-5/qtquick-controls-qmlmodule.html
// далее, в фигурных скобках приводятся егоидентификатор (id),
// по которому к нему можно обращатся из любого места qml файла,
// а также описываются свойства этого элеента интерфейса (размер, цвет, и т.д.)

// Каждый элемент интерфейса может содержать обработчики событий
// Кроме того, один элемент интерфейса может включать в себя другие объекты
// и содежать функции



Window {
    visible: true
    width: 320
    height: 350
    title: qsTr("Нормальное распределение")
    color: "#eeeeee"
    // qsTr - функция, которая может подставить тот или иной текст,
    // в зависимости от языковых настроек (см. http://doc.qt.io/qt-5/qtquick-internationalization.html)
    // Если предполагается использование одного языка, то можно от неё отказаться

    // Класс с бизнес-логикой
    // Описан в файлах проекта.
    // Должен быть подключен к QML движку в main
    Calc{
        id: backend
    }

    Text {
        id: title
        font.pointSize: 14
        font.italic: true
        anchors.horizontalCenter: parent.horizontalCenter // anchor - привязка, якорь
        text: qsTr("Вычисление arg ( Φ(z) = p )")
    }
    // Задавать относительное расположение обхектов можно с помошью якорей (anchors).
    // Например привязать горизонтальное положение элемента к центру (по горизонтали)
    // родительского элемента (здесь: window)


    Text {
        id: p_value_label
        text: qsTr("p: ")

        // свойства и их параметры можно описывать не используя оператор .
        // margins - поля (все)
        anchors {
             horizontalCenter: parent.horizontalCenter;
             top: title.bottom;
             margins: 10; }
    }

    SpinBox {
        id: spinbox_pvalue
        minimumValue: 0.0001
        maximumValue: 0.9999
        value: 0.5
        stepSize: 0.05
        decimals: 4
        anchors {horizontalCenter: parent.horizontalCenter; top: p_value_label.bottom; margins: 10}

        // при изменении значения изменяется поле value объекта backend (класс Calc)
        onValueChanged: backend.pvalue = value
    }

    Text {
        id: z_value_label
        text: "z "
        anchors {
             horizontalCenter: parent.horizontalCenter;
             top: spinbox_pvalue.bottom;
             margins: 10; }
    }


    Text{
        id: z_value
        text: backend.z.toFixed(4)
        anchors {top: z_value_label.bottom; horizontalCenter: parent.horizontalCenter; margins: 10}
    }

    Image {
        id: normpdf_image
        source: "normal_pdf.jpg" // должен быть добавлен в ресурсы
        anchors { top: z_value.bottom;
                  horizontalCenter: parent.horizontalCenter;
                  margins: 10}
    }

}
