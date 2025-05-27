#include <iostream>
#include <string>
#include <filesystem>

using namespace std;
namespace fs = std::filesystem;

bool del(string path) {
    if (!fs::exists(path)) {
        cout << "Path does not exist." << endl;
        return false;
    }

    if (fs::is_directory(path)) {
        fs::remove_all(path);
        cout << "Folder deleted: " << path << endl;
    } else {
        fs::remove(path);
        cout << "File deleted: " << path << endl;
    }

    return true;
}

bool del(string folder_path, string target) {
    fs::path full_path = fs::path(folder_path) / target;

    if (!fs::exists(full_path)) {
        cout << "File or folder not found." << endl;
        return false;
    }

    if (fs::is_directory(full_path)) {
        fs::remove_all(full_path);
        cout << "Folder deleted: " << full_path << endl;
    } else {
        fs::remove(full_path);
        cout << "File deleted: " << full_path << endl;
    }

    return true;
}