#include <iostream>
#include <string>
#include <filesystem>

namespace fs = std::filesystem;

bool pathExists(const std::string& path) {
    if (fs::exists(path)) {
        std::cout << " Path exists: " << path << "\n";
        return true;
    } else {
        std::cout << " Path does not exist: " << path << "\n";
        return false;
    }
}