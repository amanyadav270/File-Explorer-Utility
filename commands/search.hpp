#ifndef SEARCH_HPP
#define SEARCH_HPP

#include <iostream>
#include <string>
#include <filesystem>

using namespace std;
namespace fs = std::filesystem;

void search_file(fs::path root_path, string file_name) {
    bool found = false;

    fs::recursive_directory_iterator it(root_path), end;
    while (it != end) {
        if (fs::is_regular_file(*it)) {
            if (it->path().filename() == file_name) {
                cout << "Found: " << it->path() << endl;
                found = true;
            }
        }
        ++it;
    }

    if (!found) {
        cout << "File \"" << file_name << "\" not found in " << root_path << endl;
    }
}

#endif