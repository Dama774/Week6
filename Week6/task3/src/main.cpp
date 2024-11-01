#include <iostream>
#include "file_searcher.h"

int main() {
    // Укажите директорию, в которой хотите производить поиск
    std::string directory = "./"; // текущая директория

    // Создаем объект FileSearcher
    FileSearcher fileSearcher(directory);

    // Поиск файла по имени
    std::string fileNameToSearch; // переменная для имени файла
    std::cout << "Введите имя файла для поиска: ";
    std::getline(std::cin, fileNameToSearch); // считываем имя файла от пользователя

    std::vector<std::string> foundFilesByName = fileSearcher.searchByName(fileNameToSearch);

    if (foundFilesByName.empty()) {
        std::cout << "Файлы с именем "" << fileNameToSearch << "" не найдены." << std::endl;
    } else {
        std::cout << "Найденные файлы с именем "" << fileNameToSearch << "":" << std::endl;
        for (const auto& filePath : foundFilesByName) {
            std::cout << filePath << std::endl;
        }
    }

    // Поиск файла по содержимому
    std::string keywordToSearch; // переменная для ключевого слова
    std::cout << "Введите ключевое слово для поиска в содержимом: ";
    std::getline(std::cin, keywordToSearch); // считываем ключевое слово от пользователя

    std::vector<std::string> foundFilesByContent = fileSearcher.searchByContent(keywordToSearch);

    if (foundFilesByContent.empty()) {
        std::cout << "Файлы, содержащие "" << keywordToSearch << "", не найдены." << std::endl;
    } else {
        std::cout << "Найденные файлы, содержащие "" << keywordToSearch << "":" << std::endl;
        for (const auto& filePath : foundFilesByContent) {
            std::cout << filePath << std::endl;
        }
    }

    return 0;
}

