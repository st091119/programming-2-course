#include <iostream>
#include <algorithm>

struct Task {
	int priority;
	int time;
};

bool compareTasks(const Task& a, const Task& b) {
	return a.priority < b.priority;
}

void fiber(Task tasks[], int taskAmount) {
	std::sort(tasks, tasks + taskAmount, compareTasks);

	int currentTime = 0;

	for (int i = 0; i < taskAmount; ++i) {
		while (tasks[i].time > 0) {
			std::cout << "The process with priority " << tasks[i].priority << " is running." << std::endl;
			tasks[i].time--;
			currentTime++;
		}
		std::cout << "Process with priority " << tasks[i].priority << " is finished." << std::endl;
	}

	std::cout << "All tasks completed in " << currentTime << " units of time." << std::endl;
}

int main() {
	const int n = 6;
	Task tasks[n] = { {5, 3}, {8, 2}, {3, 4}, {6, 3}, {1, 1}, {3, 2} };

	fiber(tasks, n);

	return 0;
}
