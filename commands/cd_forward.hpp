#include <iostream>
#include <filesystem>
#include "list.hpp"
namespace fs = std::filesystem;

bool cd_forward(){
    fs::directory_iterator dir(fs::current_path()); //set iterator to the dir
    fs::directory_iterator end; //end iterator
    fs::directory_entry g;
    int i = 0;
    while(dir != end){//iterator iterates through all the file and stops when end iterator matches end interator
        i++;
        if(i > 1){
            std::cout<<"Multiple directories exists, use 'cd folder_name' command"<<std::endl;
            list(fs::current_path());
            return 0;
        }
        g = *dir;
        dir++;
    }
    fs::current_path(g); // change current directory
    return true;
}

