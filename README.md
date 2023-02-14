# Title: Tasks Manger
### This is a C++ program that can monitors tasks by periodically checking the status of running processes and their CPU usage.

## How to install:
1. Clone the repository: 
2. The main code is inside a folder called group.py when you download everything.
3. Run the project with a Pycharm IDE.

## Summary: 
This code defines a Task struct to store information about a running process, including its process ID, name, and CPU usage. The getTasks() function uses the ps command to obtain a list of running processes with their CPU usage, and returns a vector of Task objects. The main() function repeatedly calls getTasks() and prints out the list of tasks and their CPU usage every 5 seconds.

Note that the ps command used in this code may not be available on all systems, and may have different options and output formats on different platforms. You may need to adjust the command to work on your particular system. 

## Sceenshot:
<img src= "Capture.PNG" width="400">
