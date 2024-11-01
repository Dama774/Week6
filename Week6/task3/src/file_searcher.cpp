#include "file_searcher.h"
#include <filesystem>
#include <fstream>
#include <iostream>

namespace fs = std::filesystem;

FileSearcher::FileSearcher(const std::string& directory) : directory(directory) {}

void FileSearcher::searchInDirectory(const std::string& dir, const std::string& keyword, std::vector<std::string>& results) {
    for (const auto& entry : fs::directory_iterator(dir)) {
        if (fs::is_regular_file(entry.path())) {
            std::ifstream file(entry.path());
            std::string line;
            while (std::getline(file, line)) {
                if (line.find(keyword) != std::string::npos) {
                    results.push_back(entry.path().string());
                    break;
                }
            }
        }
    }
}

std::vector<std::string> FileSearcher::searchByContent(const std::string& keyword) {
    std::vector<std::string> results;
    searchInDirectory(directory, keyword, results);
    return results;
}

std::vector<std::string> FileSearcher::searchByName(const std::string& name) {
    std::vector<std::string> results;
    // Реализация поиска по имени файла
    for (const auto& entry : fs::directory_iterator(directory)) {
        if (fs::is_regular_file(entry.path()) && entry.path().filename() == name) {
            results.push_back(entry.path().string());
        }
    }
    return results;
}

