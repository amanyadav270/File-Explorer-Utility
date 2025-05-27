#include <filesystem>
namespace fs = std::filesystem;

bool cd_back(){
    fs::path c_path = fs::current_path();

    fs::path p_path = c_path.parent_path();

    if(c_path == p_path || p_path.empty()) return false;

    fs::current_path(p_path);
    return true;
}

