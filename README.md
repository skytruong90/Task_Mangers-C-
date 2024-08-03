# Tasks Manger

This is a C++ program designed to monitor tasks by periodically checking the status of running processes and their CPU usage.

## How to Install:

1. Clone the repository.
2. The main code is located in a file called `group.cpp` in the downloaded folder.
3. Open the project with an IDE that supports C++ development, such as CLion or Visual Studio.

## Summary:

The program uses a struct named `Task` to store details about a running process, including its process ID, name, and CPU usage. The `getTasks()` function leverages the `ps` command to retrieve a list of running processes along with their CPU usage and stores them in a vector of `Task` objects. The `main()` function calls `getTasks()` and prints the list of tasks with their CPU usage every 5 seconds.

**Note:** The `ps` command may not be available or may differ on some systems. You might need to modify the command depending on your operating system.

## How to Run the Code:

- Ensure a C++ compiler like `g++` is installed on your system.
- Compile the program using a command similar to: `g++ group.cpp -o group`.
- Run the compiled executable: `./group`.

## Sceenshot:
<img src= "Capture.PNG" width="400">
