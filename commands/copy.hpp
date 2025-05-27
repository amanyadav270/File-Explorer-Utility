#include <iostream>
#include <string>
#include <filesystem>

using namespace std;
namespace fs = std::filesystem;

bool copy_item(string source_path, string destination_path) {
    if (!fs::exists(source_path)) {
        cout << "Source path does not exist." << endl;
        return false;
    }

    if (!fs::exists(destination_path)) {
        cout << "Destination path does not exist." << endl;
        return false;
    }

    fs::path dest = fs::path(destination_path) / fs::path(source_path).filename();

    if (fs::is_directory(source_path)) {
        fs::copy(source_path, dest, fs::copy_options::recursive);
        cout << "Folder copied to: " << dest.string() << endl;
    } else {
        fs::copy(source_path, dest);
        cout << "File copied to: " << dest.string() << endl;
    }

    return true;
}