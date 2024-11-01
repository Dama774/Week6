#ifndef FILE_SEARCHER_H
#define FILE_SEARCHER_H

#include <string>
#include <vector>

class FileSearcher {
public:
    FileSearcher(const std::string& directory);
    std::vector<std::string> searchByContent(const std::string& keyword);
    std::vector<std::string> searchByName(const std::string& name); // Объявление метода

private:
    void searchInDirectory(const std::string& dir, const std::string& keyword, std::vector<std::string>& results);
    std::string directory;
};

#endif // FILE_SEARCHER_H

