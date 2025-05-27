#include <filesystem>
#include <fstream>
#include <string>
#include <iostream>

namespace fs = std::filesystem;

void eventauto() {
    std::string log_path = "event_log.txt";
    std::string folder = fs::current_path().string();

    std::cout << "Monitoring directory: " << folder << "\n";

    while (true) {
        for (auto& entry : fs::directory_iterator(folder)) {
            std::string name = entry.path().filename().string();

            // Check if already logged
            bool found = false;
            std::ifstream in_file(log_path);
            std::string line;
            while (std::getline(in_file, line)) {
                if (line == name) {
                    found = true;
                    break;
                }
            }
            in_file.close();

            if (!found) {
                std::ofstream out_file(log_path, std::ios::app);
                out_file << name << "\n";
                out_file.close();
                std::cout << "New item detected: " << name << "\n";
            }
        }

    
    }
}
