#ifndef SHELL_H
#define SHELL_H


#include <string>
class Shell{
public:
    
    Shell(){}
    
    void run();
    
    void cmd_caller(std::string input);

};


#endif