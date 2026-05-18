# Компиляция и запуск программ на Java

## Предварительные шаги

1. **Установить JDK** (Java Development Kit). На Windows / macOS / Linux скачайте дистрибутив с официального сайта Oracle или любой другой:
   - Oracle JDK – https://www.oracle.com/java/technologies/downloads/
   - OpenJDK – https://openjdk.org/

2. **Добавить `bin`‑директорию JDK в `PATH`** — так вы сможете использовать `javac` и `java` из любой папки.

3. **Проверить установку** (JDK + JRE):
   ```sh
   java   --version   # выводит версию JRE (исполняет код)
   javac  --version   # выводит версию компилятора
   ```
   Если команды не находятся, проверьте переменную `PATH` и переменную `JAVA_HOME`.

4. **Разница JDK и JRE**
   - **JDK** – набор инструментов для разработки (компилятор `javac`, утилита `jar`, `javadoc`, отладчик и т.д.). Необходима разработчику.
   - **JRE** – только среда выполнения, необходимая для запуска уже скомпилированных программ. Необходима всем, кто будет запускать java программы.
   - Формат файлов `.class` (скомпилированный файлы `.java`) меняется от версии JDK; совместимость можно проверить командой `javap -verbose` или `file MyProg.class` (см. ниже).
При выборе JDK рекомендуется выбирать не самые последние версии JDK чтобы обеспечить совместимость с не очень новыми JRE у пользователей. Целевую версия JRE можно указывать при компиляции.

---

## Компиляция одного файла
```sh
javac Main.java
```
- После компиляции появляется `Main.class` — байт‑код, исполняемый JVM.
- Для **C‑программистов**: `javac` ≈ `gcc`, `Main.class` ≈ объектный файл `.o`.
- Для **Python‑программистов**: Java — предварительная компиляция, Python — интерпретация.

## Компиляция нескольких файлов
```sh
# Явный перечень
javac File1.java File2.java

# Или всё *.java в текущей директории
javac *.java
```

## Управление зависимостями (classpath)
Java ищет классы и JAR‑файлы в *classpath*.
- **UNIX** (разделитель `:`):
  ```sh
  javac -cp lib1.jar:lib2.jar Main.java
  ```
- **Windows** (разделитель `;`):
  ```bat
  javac -cp lib1.jar;lib2.jar Main.java
  ```
Можно также указать директорию с классами: `-cp out/`.

## Вывод скомпилированных файлов
По умолчанию `.class`‑файлы создаются рядом с исходниками. При больших проектах удобно собрать их в отдельную папку:
```sh
javac -d out src/MyProgram.java
```
- Параметр `-d` задаёт **директорию вывода**.

## Указание пути к исходникам и пакетам
Если исходники лежат в структуре пакетов, можно явно задать её:
```sh
javac -sourcepath src -d out src/com/example/App.java
```
`-sourcepath` — корень дерева исходных файлов.

## Запуск программы из скомпилированных классов
```sh
# Запуск из текущей директории (класс с методом main)
java Main
```


Если класс находится в пакете, например com.example, указываем полное имя. При этом стоит помнить, что имя пакета обычно совпадает со структурой папок. Например, если структура папок выглядит так:
```
src/
└── com/
    └── example/
        └── Main.java
```
То полное имя класса будет `com.example.Main`.

Тогда запускать программу следует из директории, где находится корневой пакет (`src` в примере).
```sh
java com.example.Main
```

```sh
Error: Could not find or load main class Main
Caused by: java.lang.ClassNotFoundException: Main
```


## Создание и запуск JAR‑файлов
### Минимальный JAR
```sh
# Создаём JAR из уже скомпилированных классов
jar cf myapp.jar -C out .
```
### Выполняемый JAR (указываем точку входа)
```sh
jar cfe myapp.jar com.example.Main -C out .
```
- `c` — create, `f` — файл, `e` — entry point (главный класс).
- После создания запускаем:
```sh
java -jar myapp.jar
```
#### «Fat‑jar» (все зависимости в одном архиве)
Если проект использует сторонние библиотеки, их тоже нужно добавить в JAR. Самый простой способ — собрать их в один архив:
```sh
# Предположим, что зависимости лежат в lib/
jar --create --file myapp-all.jar \
    --manifest=manifest.mf \
    -C out . \
    -C lib .
```
В `manifest.mf` должно быть указано `Main-Class: com.example.Main`.
Для более сложных проектов обычно используют сборщики (Maven Shade, Gradle shadow), но базовый способ выше подходит для учебных целей.

#### Права на запуск (Linux)
Для удобства можно сделать JAR исполняемым:
```sh
chmod +x myapp.jar
```
Тогда `./myapp.jar` будет работать, если в JAR указан `Main-Class`.

---

## Запуск с включёнными проверками и параметрами JVM
- **Assertions** (встроенные проверки) требуют флага `-ea`:
```sh
java -ea com.example.Main
```
- Для отладки иногда полезно задать параметры памяти:
```sh
java -Xmx512m -Xms128m com.example.Main
```
---

## Модули (Java 9+)
Начиная с Java 9 появился модульный слой. Если ваш проект использует `module-info.java`, компиляция и запуск выглядят так:
```sh
# Компиляция модуля
javac -d out --module-source-path src $(find src -name "*.java")

# Запуск модуля
java --module-path out -m com.example/com.example.Main
```
`-m` — имя модуля/полное имя класса.

---

## Часто задаваемые вопросы

| Вопрос | Ответ |
|---|---|
| **Что делать, если `java` не найден?** | Убедиться, что `JAVA_HOME/bin` добавлен в `PATH` и переменная `JAVA_HOME` указывает на корень JDK. |
| **Как проверить, какие версии JDK установлены?** | `javac -version` и `java -version`. |
| **Можно ли сразу собрать JAR?** | Да: `javac -d out src/**/*.java && jar cfe myapp.jar com.example.Main -C out .`. |
| **Как увидеть версию class‑file?** | `javap -verbose MyClass.class | grep "major version"` (пример: 61 → Java 17). |
| **Почему получаю `Error: Could not find or load main class …`?** | Неправильно указан classpath, пакетное имя или текущая директория не является корнем пакета. |
| **Как собрать «fat‑jar» с зависимостями?** | Либо добавить все `.class` из `lib/*.jar` в архив вручную (см. выше), либо использовать Maven/Gradle плагин Shade/Shadow. |

## Ссылки и доп. материалы
- Папка `examples/java/java-compile-n-run` содержит готовый пример проекта с несколькими файлами и скриптом сборки JAR.
- В `readme.md` описаны детали работы `jar`, `javac` и настройка IDE (IntelliJ IDEA).


# Системы сборки
Для крупных проектов удобнее пользоваться Maven или Gradle, которые автоматически компилируют, собирают зависимости и создают исполняемые JAR‑файлы.
- **Maven**: `mvn compile` → компиляция, `mvn package` → создание JAR, `mvn exec:java` → запуск.
- **Gradle**: `gradle build` → компиляция + упаковка, `gradle run` → запуск.
Эти команды используют те же подкапотные `javac`/`java`, но скрывают детали от пользователя.


# Maven
Maven - сборщик Java.

Аналоги: gradle, ant (устарел);


## Установка

Maven не входит в состав JDK поэтому устанавливается отдельно.


```bash
apt install maven
```
Последняя версия (май 2025) - 3.9.16

Проверка:
```bash
mvn --version
```

Для корректной работы нужно задать значение переменной окружения `JAVA_HOME` - путь к JDK, к папке, в которой лежит папка bin.
Например: `/usr/lib/jvm/java-20-openjdk-amd64`


### Существующая версия Maven
Maven может быть не доступен в системе напрямую. Но если система сборки использовалась через IDE, например IntellIJ IDEA, но Maven можно найти в папке вместе со скаченными зависимостями. В Ubuntu это: `~/.m2/wrapper/dists/apache-maven`.

В Windows это может быть C:\Users\<ваш_пользователь>\AppData\Local\JetBrains\IntelliJIdea<версия>\maven\

В IntelliJ IDEA можно посмотреть путь к maven в настройках: File → Settings → Build, Execution, Deployment → Build Tools → Maven → Maven home path


## Создание проекта
Создание проекта по шаблону `maven-archetype-quickstart`
```bash
mvn archetype:generate -DgroupId=com.mycompany.app -DartifactId=my_project_name -DarchetypeArtifactId=maven-archetype-quickstart
```
`-DgroupId=com.mycompany.app` - имя главного пакета (пространства имён) программы
`-DartifactId=my_project_name` - название проекта, название JAR файла проекта
Если не указать параметры -DgroupId=com.mycompany.app -DartifactId=my_project_name то они будут запрошены при создании каталогов и проекта.

```
|-pom.xml -- Project Object Model -- файл описывающий настройки сборки
|-src     -- папка для исходного кода
  |-main
    |-java
      |-com
        |-mycompany
          |-app
            |-App.java
  |-test
    |-java
      |-com
        |-mycompany
          |-app
            |-AppTest.java
  |-
```
Подробнее про файловую структуру проекта: https://maven.apache.org/guides/introduction/introduction-to-the-standard-directory-layout.html
Другие шаблоны проектов: https://maven.apache.org/guides/introduction/introduction-to-archetypes.html

Для явного указания версии JDK можно в файле `pom.xml` задать версию:
```xml
<properties>
    <maven.compiler.source>20</maven.compiler.source>
    <maven.compiler.target>20</maven.compiler.target>
  </properties>
```

Далее все операции должны происходит из папки с pom файлом.

Компиляция
```bash
mvn compile
```

Запуск тестов (включает compile)
```bash
mvn test
```

Создание JAR файла (включает test)
```bash
mvn package
```

Запуск jar файла
```bash
java -cp jarfilename.jar com.mycompany.MainClass
```


### Зависимости
Зависимости описываются в pom.xml.
Например, junit:
```bash
<dependencies>

    <dependency>
      <groupId>junit</groupId>
      <artifactId>junit</artifactId>
      <version>4.11</version>
      <scope>test</scope>
    </dependency>

  </dependencies>
```

Во время первой сборкой maven скачает их в локальный репозиторий.

Если зависимость представлена JAR файлом, то его тоже можно установить в локальный репозиторий (`${user.home}/.m2/repository`)
https://stackoverflow.com/questions/4955635/how-to-add-local-jar-files-to-a-maven-project


Допустимо (но depricated) указывать путь к отдельным файлам напрямую:
```xml
<dependency>
    <groupId>com.sample</groupId>
    <artifactId>sample</artifactId>
    <version>1.0</version>
    <scope>system</scope>
    <systemPath>${project.basedir}/src/main/resources/Name_Your_JAR.jar</systemPath>
</dependency>
```


**Сайт репозитория Maven**
https://mvnrepository.com/

На сайте есть поиск по библиотекам. Для каждой библиотеки приведены примеры описания зависимости в файлах сборки (в частности для Maven и Gradle). Можно отдельно скачать jar файл.

## Ссылки
1. Начальное руководство Maven: https://maven.apache.org/guides/getting-started/index.html
1. Соглашение о файловой структуре проекта: https://maven.apache.org/guides/introduction/introduction-to-the-standard-directory-layout.html
