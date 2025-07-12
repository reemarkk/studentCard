// main.cpp
#include <iostream>
#include <vector>
#include "student.h"

using namespace std;

int main() {
    std::vector<Student> StudentList;

    cout << "\n=====================================\n";
    cout << "     🎓 STUDENT RECORD SYSTEM 🎓     \n";
    cout << "=====================================\n\n";

    while (true) {
        int id;
        string name;

        while (true) {
            cout << "Enter new student ID: ";
            cin >> id;
            if (cin.fail()) {
                cin.clear();
                cin.ignore(1000, '\n');
                cout << "Invalid input! Please enter a numeric ID.\n";
            } else {
                break;
            }
        }

        cout << "Enter student name: ";
        cin.ignore();  // clear leftover newline
        getline(cin, name);

        Student NewStudent(id, name, std::vector<double>{});
        cout << "✅ Student object created successfully.\n";

        char action;
        do {
            cout << "\nChoose action:\n"
                 << "(a)dd score\n(u)pdate name\n(d)isplay info\n(l)etter grade\n(q)uit: ";
            cin >> action;

            if (action == 'a') {
                double score;
                while (true) {
                    cout << "Enter score to add: ";
                    cin >> score;
                    if (cin.fail()) {
                        cin.clear();
                        cin.ignore(1000, '\n');
                        cout << "Please enter a valid numerical score!\n";
                    } else {
                        NewStudent.AddScore(score);
                        break;
                    }
                }

            } else if (action == 'u') {
                cin.ignore();
                string newName;
                cout << "Enter new name: ";
                getline(cin, newName);
                NewStudent.updateName(newName);

            } else if (action == 'd') {
                NewStudent.DisplayInfo();

            } else if (action == 'l') {
                cout << "Grade Level: " << NewStudent.GradeWithLetter() << endl;
            }

        } while (action != 'q');

        char editChoice;
        cout << "\nWould you like to change student information? (c to continue, anything else to skip): ";
        cin >> editChoice;

        if (editChoice == 'c' || editChoice == 'C') {
            do {
                cout << "\nChoose what to edit:\n"
                     << "(n)- name\n(d) - ID\n(q)- quit editing\nYour choice: ";
                cin >> editChoice;

                if (editChoice == 'd') {
                    int newID;
                    while (true) {
                        cout << "Enter new ID: ";
                        cin >> newID;
                        if (cin.fail()) {
                            cin.clear();
                            cin.ignore(1000, '\n');
                            cout << "Please enter a valid numeric ID.\n";
                        } else {
                            NewStudent.UpdateID(newID);
                            break;
                        }
                    }

                } else if (editChoice == 'n') {
                    cin.ignore();
                    string newName;
                    cout << "Enter new name: ";
                    getline(cin, newName);
                    NewStudent.updateName(newName);
                }

            } while (editChoice != 'q');
        }

        cout << "\n🎉 Final info for student:\n";
        NewStudent.DisplayInfo();

        StudentList.emplace_back(NewStudent);
        cout << "✅ Student saved to list.\n";

        char again;
        cout << "\nWould you like to add another student? (y/n): ";
        cin >> again;
        if (again != 'y' && again != 'Y') break;
    }

    cout << "\n==============================\n";
    cout << "📋 All Students Summary:\n";
    for (const Student& s : StudentList) {
        s.DisplayInfo();
    }

    int searchID;
    while (true) {
        cout << "\nEnter ID you want to search: ";
        cin >> searchID;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Please enter a valid numeric ID.\n";
        } else {
            break;
        }
    }

    Student foundStudent = FindStudentWithID(StudentList, searchID);
    foundStudent.DisplayInfo();

    return 0;
}
