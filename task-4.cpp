#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Task {
    string description;
    bool completed;
};

vector<Task> tasks;

void addTask(const string& description) {
    Task newTask;
    newTask.description = description;
    newTask.completed = false;
    tasks.push_back(newTask);
}

void viewTasks() {
    if (tasks.empty()) {
        cout << "No tasks available.\n";
        return;
    }

    for (size_t i = 0; i < tasks.size(); ++i) {
        cout << i + 1 << ". " << tasks[i].description 
             << (tasks[i].completed ? " [Completed]" : " [Pending]") << endl;
    }
}

void markTaskAsCompleted(int index) {
    if (index < 1 || index > tasks.size()) {
        cout << "Invalid task number.\n";
        return;
    }

    tasks[index - 1].completed = true;
    cout << "Task marked as completed.\n";
}

void removeTask(int index) {
    if (index < 1 || index > tasks.size()) {
        cout << "Invalid task number.\n";
        return;
    }

    tasks.erase(tasks.begin() + index - 1);
    cout << "Task removed.\n";
}

int main() {
    while (true) {
        cout << "\nTo-Do List Manager\n";
        cout << "1. Add Task\n";
        cout << "2. View Tasks\n";
        cout << "3. Mark Task as Completed\n";
        cout << "4. Remove Task\n";
        cout << "5. Exit\n";
        cout << "Choose an option: ";

        int choice;
        cin >> choice;
        cin.ignore();  // Ignore newline left in the input buffer

        switch (choice) {
            case 1: {
                cout << "Enter task description: ";
                string description;
                getline(cin, description);
                addTask(description);
                break;
            }
            case 2:
                viewTasks();
                break;
            case 3: {
                cout << "Enter task number to mark as completed: ";
                int index;
                cin >> index;
                markTaskAsCompleted(index);
                break;
            }
            case 4: {
                cout << "Enter task number to remove: ";
                int index;
                cin >> index;
                removeTask(index);
                break;
            }
            case 5:
                return 0;
            default:
                cout << "Invalid option.\n";
        }
    }

    return 0;
}
