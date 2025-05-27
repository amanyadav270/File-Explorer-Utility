#include <iostream>
using namespace std;

void help() {
    cout << "ByteArch File Explorer - Help Menu\n";
    cout << "-----------------------------------\n";
    cout << "General Commands:\n";
    cout << "  help                  - Show this help menu\n";
    cout << "  exit                  - Exit the explorer\n";
    cout << "\n";

    cout << "Directory Navigation:\n";
    cout << "  cd <foldername>       - Change into a folder\n";
    cout << "  cd--                  - Go back to parent directory\n";
    cout << "  cd++                  - Go forward (if supported)\n";
    cout << "  gotodir               - Go to an absolute path\n";
    cout << "  cdir                  - Show current directory\n";
    cout << "\n";

    cout << "Listing and Information:\n";
    cout << "  list                  - List files and folders in current directory\n";
    cout << "  exists <file/folder>  - Check if a file or folder exists\n";
    cout << "\n";

    cout << "File & Folder Operations:\n";
    cout << "  del                   - Delete file/folder (use d** to delete current folder)\n";
    cout << "  copy                  - Copy file/folder\n";
    cout << "  search <filename>     - Search for a file\n";
    cout << "\n";

    cout << "Recent & Auto Events:\n";
    cout << "  rfiles                - Show recent files in a directory\n";
    cout << "  event_auto            - Log file/directory events automatically (if enabled)\n";
    cout << "\n";

    cout << "Utility:\n";
    cout << "  clear                 - Clear the screen\n";
    cout << "\n";
}
