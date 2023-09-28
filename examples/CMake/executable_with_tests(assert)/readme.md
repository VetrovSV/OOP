# Пример тестового проекта для CMake
Проект состоит из
- папки с основным кодом (`src`)
- папки с кодом, выполняющим тесты (`test`)
	- `test.cpp` (компилируется в исполняемый файл, который должен вернуть 0 если все тесты успешны)
	- отдельный файл конфигурации сборки для тестов `CMakeLists.txt`
- основной файл конфигурации сборки проекта (без тестов) `CMakeLists.txt`


### Запуск тестов
Сборка тестового проекта
```bash
cd test
cmake      -B build .
cmake --build build
```

Запуск тестов
```bash
cd build
ctest .
```

Пример вывода программы
```
   Start 1: FirstTest
1/1 Test #1: FirstTest ........................   Passed    0.00 sec

100% tests passed, 0 tests failed out of 1

Total Test time (real) =   0.00 sec
```