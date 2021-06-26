#include <string>
#include <vector>

extern const std::vector< std::string > NAMES;      // extern -- эта константа будет определена в другом модуле

std::string random_name();                          // возвращает случайное имя из NAMES