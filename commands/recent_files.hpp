#include <string>
#include <vector>
#include <filesystem>
#include <iostream>
#include <algorithm>

using namespace std;
namespace fs = filesystem;

struct fileinfo{
    string path;
    time_t time;
};

bool compare(fileinfo x, fileinfo y){
    return (x.time >y.time);
}

void recent_files(string dir){
    vector<fileinfo> files_vector;

    fs:: recursive_directory_iterator r_iterator(dir);
    fs:: recursive_directory_iterator end;
    int i = 0;
    while(r_iterator != end){
        if(fs::is_regular_file(*r_iterator)){
            fileinfo details;
            details.path = (*r_iterator).path().string();
            details.time = last_write_time(*r_iterator).time_since_epoch().count();
            files_vector.push_back(details);
        }
        r_iterator++;
    }
    if(!files_vector.size()){
        cout<<"No files found."<<endl;
    }else{
        cout<<"Recently Modified Files:"<<endl;
        sort(files_vector.begin(), files_vector.end(),compare);
        while(i < files_vector.size()){
            cout<<i+1<<"."<<files_vector[i].path<<endl;
            i++;
        }
    }
}