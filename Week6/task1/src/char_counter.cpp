#include "char_counter.h"
#include <unordered_map>
#include <algorithm>

std::pair<char, int> most_frequent_char(const std::string& s) {
    std::unordered_map<char, int> frequency_map;

    // Подсчет частоты каждого символа
    for (char c : s) {
        frequency_map[c]++;
    }

    // Нахождение символа с максимальной частотой
    char most_frequent = '0';
    int max_count = 0;

    for (const auto& pair : frequency_map) {
        if (pair.second > max_count) {
            max_count = pair.second;
            most_frequent = pair.first;
        }
    }

    return {most_frequent, max_count};
}

