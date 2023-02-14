#include <iostream>
#include <vector>
#include <chrono>
#include <thread>
#include <string>
#include <algorithm>

using namespace std;

struct Task {
    int pid;
    string name;
    double cpuUsage;
};

vector<Task> getTasks() {
    vector<Task> tasks;
    FILE* fp;
    char buf[512];
    string cmd = "ps -eo pid,comm,%cpu | tail -n +2";
    if ((fp = popen(cmd.c_str(), "r")) == nullptr) {
        perror("popen failed");
        exit(1);
    }
    while (fgets(buf, sizeof(buf), fp)) {
        int pid;
        char name[256];
        double cpuUsage;
        sscanf(buf, "%d %s %lf", &pid, name, &cpuUsage);
        tasks.push_back({pid, name, cpuUsage});
    }
    pclose(fp);
    return tasks;
}

int main() {
    while (true) {
        vector<Task> tasks = getTasks();
        cout << "Process\t\tCPU Usage (%)\n";
        for (const auto& task : tasks) {
            printf("%-15s\t%.2f\n", task.name.c_str(), task.cpuUsage);
        }
        cout << "--------------------------------------------------\n";
        this_thread::sleep_for(chrono::seconds(5));
    }
    return 0;
}
