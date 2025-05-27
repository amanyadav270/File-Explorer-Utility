#include <string>
#include <filesystem>
using namespace std;
namespace fs = std::filesystem;

int cd(string folder){
    fs::directory_iterator dir(fs::current_path()); //set iterator to the dir
    fs::directory_iterator end; //end iterator
    
    while(dir != end){//iterator iterates through all the file and stops when end iterator matches end interator
        fs::directory_entry i = *dir; // gives path to i
        if(i.is_directory()){
            if(folder == i.path().filename().string()){
                fs::current_path(i); // change current directory
                return 1;
            }
        }
        dir++;
    }
    return 0;
}


