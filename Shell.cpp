//g++ -I. main.cpp Shell.cpp -o main.exe            
//taskkill /f /im main.exe

//Libraries
#include<iostream>
#include<sstream>
#include "Shell.hpp"
#include <filesystem>

using namespace std;
namespace fs = std::filesystem;

//commands/features
#include "cd.hpp"
#include "exists.hpp"
#include "list.hpp"
#include "cdir.hpp"
#include "exit.hpp"
#include "recent_files.hpp"
#include "cd_back.hpp"
#include "clear.hpp"
#include "delete.hpp"
#include "copy.hpp"
#include "gotodir.hpp"
#include "cd_forward.hpp"
#include "event_auto.hpp"
#include "search.hpp"
#include "help.hpp"


string cmd_name(string input){
    int len = input.size();
    string new_string;
    for(int i = 0; i < len; i++){
        if(input[i] == ' ') break;
        new_string +=input[i];
    }
    return new_string;
}

string folder_name(string input){
    int i = 0,len = input.size();
    string new_string;
    for(int i = 0; i < len; i++){
        if(input[i] == ' '){
            for(int j = i+1; j < len ; j++){
                new_string += input[j];
            }
            return new_string;
        }
    }
    return " ";
}


void Shell::run() {
    string input;
    cout << "ByteArch File Explorer [Version 1.0.0]" << endl;
    cout << "(c) ByteArch Technologies. All rights reserved." << endl;
    cout << endl;

    while(true){
        cout<<fs::current_path().string()<<">";
        getline(cin,input);

        if(input.empty()){
            continue;          //skip below steps and then move to while again
        }
        cmd_caller(input);
    }
};

void Shell::cmd_caller(string input){
    if(input == "list"){
        list(fs::current_path());
    }else if("cd" == cmd_name(input)){
        if(input.size()==2);
        else if(!cd(folder_name(input))){
        cout << "Folder not found." << endl;
        }
    }else if(input == "cd--"){
        if(!cd_back()){
            cout<<"Already at root directory, can't go back "<<endl;
        }
    }
    else if(input == "rfiles"){
        string input2;
        cout<<"Enter directory or cdir for current directory:"<<endl;
        cin>>input2;
        cin.ignore();
        if(input2 == "cdir"){
            recent_files(fs::current_path().string());
        }else{
            recent_files(input2);
        }
    }else if(input == "clear"){
        clear();
        cout << "ByteArch File Explorer [Version 1.0.0]" << endl;
        cout << "(c) ByteArch Technologies. All rights reserved." << endl;
        cout << endl;
    }
    else if(input=="fprop"){
        //displayFileProperties(fs::current_path().string());
    }
    else if ("del" == cmd_name(input)) {
        string input2, input3;
        cout << "Enter directory or 'cdir' for current directory: ";
        cin >> input2;
        cout << "Enter folder or file name or 'd**' to delete current folder: ";
        cin >> input3;
        cin.ignore();

        if (input2 == "cdir" && input3 == "d**") {
            del(fs::current_path().string());
        }
        else if (input2 == "cdir" && input3 != "d**") {
            del(fs::current_path().string(), input3);
        }
        else if (input2 != "cdir" && input3 != "d**") {
            del(input2, input3);
        }
        else if (input2 != "cdir" && input3 == "d**") {
            del(input2);
        }
        else {
            cout << "Invalid delete command." << endl;
        }
    }
    else if ( input  == "copy"){
        string input2, input3,source,destination;
        cout << "Enter source path or 'cdir' for current directory: ";
        cin >> input2;

        if (input2 == "cdir") {
            string fname;
            string input4;
            cout << "Enter file or folder name in current directory to copy or cdir again to copy current directory: ";
            cin >> fname;
            if(fname == "cdir"){
                source = fs::current_path().string();

            }else{
                source = (fs::path(fs::current_path()) / fname).string();
            }
        } else {
            source = input2;
        }
        cout << "Enter target folder path or 'cdir' for current directory: ";
        cin >> input3;
        if (input3 == "cdir") {
            destination = fs::current_path().string();
        } else {
            destination = input3;
        }
        cin.ignore();
        copy_item(source, destination);

    }
    else if (input == "gotodir"){
        string input2;
        cout<<"Enter directory: ";
        cin>>input2;
        gotodir(input2);
        cin.ignore();
    }
    else if (input == "search") {
    string file_name;
    cout<<"Enter file name: ";
    cin >> file_name;
        if (file_name.empty()) {
            cout << "Usage: search <file_name>\n";
        }else {
            search_file(fs::current_path().string(), file_name);
        }
    }
    else if(input == "event" )
    {
        eventauto();
    }
    else if (cmd_name(input) == "exists") {
        string filename = folder_name(input);
        pathExists(filename);
    }
    else if(input == "help"){
        help();
    }
    else if (input == "cd++"){
        cd_forward();
    }
    else if(input == "cdir"){
        cout<<cdir()<<endl;
    }else if (input == "exit"){
        ex();
    }
    else{
        cout<<"Invalid Command"<<endl;
    }
}

