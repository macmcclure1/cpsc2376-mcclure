#include <iostream>
#include <list>
using namespace std;

void taskManager() {
    list<string> tasks;
    int choice;
    string task;
    
    do {
        cout << "1. Add Task\n2. Remove Task\n3. Show Tasks\n4. Exit\nChoice: ";
        cin >> choice;
        cin.ignore();
        
        switch (choice) {
            case 1:
                cout << "Enter task: ";
                getline(cin, task);
                tasks.push_back(task);
                cout << "Task added!\n";
                break;
            case 2:
                if (!tasks.empty()) {
                    cout << "Enter task number to remove: ";
                    int index;
                    cin >> index;
                    if (index > 0 && index <= tasks.size()) {
                        auto it = tasks.begin();
                        advance(it, index - 1);
                        tasks.erase(it);
                        cout << "Task removed!\n";
                    } else {
                        cout << "Invalid task number!\n";
                    }
                } else {
                    cout << "No tasks to remove!\n";
                }
                break;
            case 3:
                cout << "Tasks:\n";
                int i = 1;
                for (const auto& t : tasks) {
                    cout << i++ << ". " << t << "\n";
                }
                break;
            case 4:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice!\n";
        }
    } while (choice != 4);
}

int main() {
    taskManager();
    return 0;
}