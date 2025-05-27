#include <string>
#include <filesystem>
namespace fs = std::filesystem;

std::string cdir(){
    return fs::current_path().string();
}


