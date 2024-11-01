#include <iostream>
#include "char_counter.h"

int main() {
    std::string input;
    
    // Запрос ввода строки у пользователя
    std::cout << "Введите строку: ";
    std::getline(std::cin, input);
    
    // Получение наиболее часто встречающегося символа
    auto result = most_frequent_char(input);
    
    // Вывод результата
    std::cout << "Результат: ['" << result.first << "', " << result.second << "]" << std::endl;

    return 0;
}

