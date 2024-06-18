#include <iostream>
#include <vector>
#include <chrono>
#include <thread>
#include <cstdio> // For popen, pclose

using namespace std;

struct Task {
    int pid;
    string name;
    double cpuUsage;
};

vector<Task> getTasks() {
    vector<Task> tasks;
    const char* cmd = "ps -eo pid,comm,%cpu | tail -n +2";
    FILE* fp = popen(cmd, "r");
    if (!fp) {
        cerr << "Failed to run command\n";
        exit(1);
    }

    char buffer[512];
    while (fgets(buffer, sizeof(buffer), fp) != nullptr) {
        int pid;
        char name[256];
        double cpuUsage;
        if (sscanf(buffer, "%d %255s %lf", &pid, name, &cpuUsage) == 3) {
            tasks.push_back({pid, string(name), cpuUsage});
        }
    }
    pclose(fp);
    return tasks;
}

int main() {
    while (true) {
        auto tasks = getTasks();
        cout << "Process\t\tCPU Usage (%)\n";
        for (const auto& task : tasks) {
            printf("%-15s\t%.2f\n", task.name.c_str(), task.cpuUsage);
        }
        cout << "--------------------------------------------------\n";
        this_thread::sleep_for(chrono::seconds(5));
    }
    return 0;
}
