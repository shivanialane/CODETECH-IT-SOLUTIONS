#include <bits/stdc++.h>
using namespace std;
struct Task{
    string desc;
    bool finished;
};
class ToDoList{
private:
    vector<Task> t;
public:
    // 1)Function to add a task to list.
    void addTask(const string& desc) {
        Task new_task = {desc, false};
        t.push_back(new_task);
        cout << "Task added successfully." <<"\n";
    }
    //2) Function to view the tasks in list.
    void viewTasks() {
        if (t.empty()) {
            cout <<"No tasks available."<<"\n";
            return;
        }
        cout << "Task List:" <<"\n";
        cout << setw(5) << "ID" << setw(20) << "Description" << setw(15) << "Status" <<"\n";
        for (size_t i = 0; i<t.size();i++){
            cout<<setw(5)<< i + 1 << setw(20) << t[i].desc<<setw(15)
            << (t[i].finished ? "Completed" : "Pending") << "\n";
        }
    }
    // 3)Function to mark a task as completed 
    void markTaskCompleted(size_t TaskId) {
        if(TaskId > 0 && TaskId <= t.size()) {
            t[TaskId - 1].finished = true;
            cout <<"Task marked as completed."<<"\n";
        }
		else{
            cout <<"Invalid task ID."<<"\n";
        }
    }
    // 4) Function to remove a task from the ToDoList
    void removeTask(size_t TaskId) {
        if (TaskId > 0 && TaskId <= t.size()) {
            t.erase(t.begin() + TaskId - 1);
            cout << "Task removed successfully." <<"\n";
        }
		else {
            cout << "Invalid task ID." <<"\n";
        }
    }
};
int main() {
    ToDoList List;
    while (true) {
        cout << "\n------- TO-DO LIST --------" <<"\n";
        cout << "1. Add Task\n2. View Tasks\n3. Mark Task as Completed\n4. Remove Task\n5. Exit\n";
        cout << "Choose an option (1-5): ";
        int ch;
        cin>>ch;
        switch (ch) {
            case 1: {
                string desc;
                cout << "Enter task description: ";
                cin.ignore(); 
                getline(cin, desc);
                List.addTask(desc);
                break;
            }
            case 2:
                List.viewTasks();
                break;
            case 3: {
                size_t TaskId;
                cout << "Enter task ID to mark as completed: ";
                cin >> TaskId;
                List.markTaskCompleted(TaskId);
                break;
            }
            case 4:{
                size_t TaskId;
                cout << "Enter task ID to remove: ";
                cin >> TaskId;
                List.removeTask(TaskId);
                break;
            }
            case 5:
                cout << "Exit from the list" << "\n";
                return 0;
            default:
                cout << "Invalid choice. Please choose a valid option." << "\n";
        }
    }

    return 0;
}

