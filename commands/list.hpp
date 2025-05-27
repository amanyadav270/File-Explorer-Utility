#ifndef LIST_HPP
#define LIST_HPP


#include <string>
#include <filesystem>
using namespace std;
namespace fs = std::filesystem;

void list(fs::path current_path){
    int check = 0;
    fs::directory_iterator dir(current_path); //set iterator to the dir
    fs::directory_iterator end; //end iterator
    
    while(dir != end){//iterator iterates through all the file and stops when end iterator matches end interator
        fs::directory_entry i = *dir; //gives path to i
        if(i.is_directory()){
            check = 1;
            cout<<"Folder:"<<i.path().filename().string()<<endl;//using .filename() gives folder name .path gives path of the current iterator and then converted that path to string before printing
        }
        dir++;
    }
    if(!check){
        cout<<"No Folder in this directory"<<endl;
    }
}

#endif // LIST_HPP