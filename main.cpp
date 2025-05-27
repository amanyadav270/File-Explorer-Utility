//   use this bash command " g++ .\main.cpp .\Shell.cpp -o main.exe ; if ($?) { .\main.exe } " 
//   to run the code and then refresh the directory then run main.exe.

//  use this bash command if the main.exe permission denied error comes " taskkill /f /im main.exe "

// use readme file from github repo if still not working , REPO LINK - "https://github.com/amanyadav270/File-Explorer-Utility"


#include <iostream>
#include "Shell.hpp"

int main(){
    Shell Shell1;
    Shell1.run();
    return 0;
}
