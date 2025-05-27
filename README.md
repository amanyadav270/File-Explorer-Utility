# ByteArch File Explorer

**ByteArch File Explorer** is a **command-line utility built in C++** that provides a suite of common file system operations. It allows users to navigate directories, manage files and folders, and perform various utility tasks—all directly from the terminal.

## Features

### Directory Navigation
- cd <foldername> — Change into a specified folder.
- cd-- — Go back to the parent directory.
- cd++ — Go forward to a directory (if only one directory exists).
- gotodir — Navigate to an absolute path.
- cdir — Display the current working directory.

### Listing and Information
- list — List all folders within the current directory.
- exists <file/folder> — Check if a specified file or folder exists.

### File & Folder Operations
- del — Delete files or folders.  
  (Use d** to delete the current directory.)
- copy — Copy files or folders from a source to a destination.
- search <filename> — Search for a specific file within the current directory and its subdirectories.

### Recent & Auto Events
- rfiles — Show a list of recently modified files in a specified or current directory.
- event — Start monitoring the current directory for new files/folders and log them to event_log.txt.

### Utility
- clear — Clear the terminal screen.
- help — Display the help menu with all available commands.
- exit — Terminate the file explorer application.

---

## How to Compile and Run

### 1. Clone the Repository
```bash
git clone https://github.com/amanyadav270/File-Explorer-Utility
cd File-Explorer-Utility
```

### 2. Run Terminal Directly using main.exe
Use the main.exe to run the terminal.

### 3. Compile using g++
Navigate to the directory containing main.cpp, Shell.cpp, and all .hpp files.

```bash
g++ .\main.cpp .\Shell.cpp -o main.exe ; if ($?) { .\main.exe }
```

- g++: The C++ compiler.
- -I.: Includes the current directory for header files.
- main.cpp Shell.cpp: The source files to compile.
- -o main.exe: Specifies the output executable name.
- && ./main.exe: Auto-runs the executable if compilation is successful (for Bash on Linux/macOS or Git Bash on Windows).

---

### Troubleshooting (Permission Denied)

If you see a "permission denied" error while running main.exe, it might be due to a previously running instance. Use:

```bash
pkill -f main.exe
```

Then try running the executable again:

```bash
./main.exe
```

---

## Run the Executable

```bash
./main.exe
```

---

## Usage

Once the executable is running, a command prompt will appear with your current directory:

```
ByteArch File Explorer [Version 1.0.0]
(c) ByteArch Technologies. All rights reserved.

C:\Users\YourUser\>
```

Type help to view a list of available commands.

---

## Project Structure

| File/Folder          | Description |
|----------------------|-------------|
| main.cpp           | Entry point of the application. |
| Shell.hpp/.cpp     | Handles command-line interface logic and dispatch. |
| cd.hpp             | Implements the cd command. |
| cd_back.hpp        | Implements the cd-- command. |
| cd_forward.hpp     | Implements the cd++ command. |
| cdir.hpp           | Returns the current directory path. |
| clear.hpp          | Clears the console screen. |
| copy.hpp           | Copies files and folders. |
| delete.hpp         | Deletes files and folders. |
| event_auto.hpp     | Monitors and logs file system events. |
| exists.hpp         | Checks if a given path exists. |
| exit.hpp           | Exits the application. |
| gotodir.hpp        | Navigates to an absolute path. |
| help.hpp           | Displays help information. |
| list.hpp           | Lists folders in the current directory. |
| recent_files.hpp   | Lists recently modified files. |
| search.hpp         | Searches for a file in a directory tree. |
| event_log.txt      | Logs file system events when event is used. |

---

Feel free to open an issue or contribute to the repository!

## Contributions:

### Aman Yadav (24csu012)
Lead Developer and Core Architect

- Core Application Logic  
  Designed and implemented the main application flow and command handling in:  
  - main.cpp  
  - Shell.hpp  
  - Shell.cpp

- Directory Navigation Commands  
  Developed robust navigation features for seamless traversal:  
  - cd.hpp  
  - cd_back.hpp  
  - cd_forward.hpp  
  - cdir.hpp  
  - gotodir.hpp

- File and Folder Management  
  Enabled comprehensive file system operations:  
  - copy.hpp  
  - delete.hpp  
  - list.hpp  
  - recent_files.hpp  
  - search.hpp

- Utility Commands  
  Enhanced user experience with:  
  - clear.hpp  
  - help.hpp

### Deepesh Yadav (24csu051)
- Event Logging  
  Developed event_auto.hpp, enabling real-time monitoring and logging of file system events.

### Dhruv Gupta (24csu358)
- Existence Check  
  Contributed exists.hpp, providing the capability to verify the presence of files or folders.

### Abhishek Kumar (24csu005)
- Application Exit  
  Implemented graceful termination of the application via exit.hpp.
