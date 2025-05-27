#include <iostream>
#include <filesystem>
#include <string>

namespace fs = std::filesystem;

void gotodir(std::string new_dir){
    if(fs::exists(new_dir)){
        if(fs::is_directory(new_dir)){
            fs::current_path(new_dir);
        }else{
            std::cout<<"Path exists, but it's not a directory."<<std::endl;
        }
    }else{
        std::cout<<"Directory does not exists."<<std::endl;
    }
}