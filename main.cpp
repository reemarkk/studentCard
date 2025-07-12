#include <iostream>
#include <vector>
using namespace std;

class Student {
private:
    int student_id;
    std::string student_name;
    std::vector<double> scores;
public:
    Student(int, std::string, std::vector<double>);
    void AddScore(double newScore);
    void updateName(const std::string& newName);
    double getAverage() const;
    void DisplayInfo() const;
    std::string GetStudentName() const;
    void UpdateID(int);
    int GetID() const;
    char GradeWithLetter() const;
};

Student::Student(int student_id, std::string student_name, std::vector<double> scores) {
    this->student_id = student_id;
    this->student_name = student_name;
    this->scores = scores;
}

void Student::AddScore(double newScore) {
    this->scores.push_back(newScore);
    cout << "➕ Score added successfully.\n";
}

void Student::updateName(const std::string& newName) {
    this->student_name = newName;
    cout << "✏️  Name updated.\n";
}

double Student::getAverage() const {
    if (scores.empty()) return 0.0;
    double sumOfGrades = 0;
    for (double s : scores) sumOfGrades += s;
    return sumOfGrades / scores.size();
}

std::string Student::GetStudentName() const {
    return this->student_name;
}

char Student::GradeWithLetter() const {
    if (scores.empty()) {
        cout << "There is no score yet. Enter your scores first!" << endl;
        return '-';
    }
    double avg = getAverage();
    if (avg >= 18) return 'A';
    else if (avg >= 15) return 'B';
    else if (avg >= 12) return 'C';
    else if (avg >= 10) return 'D';
    else return 'F';
}

void Student::DisplayInfo() const {
    std::cout << "\n-----------------------------\n";
    std::cout << "Student ID: " << this->student_id << endl;
    std::cout << "Student Name: " << this->student_name << endl;
    std::cout << "Student Grades: ";
    for (double score : scores) cout << score << " ";
    cout << endl;
    cout << "Average Score: " << getAverage() << endl;
    cout << "Grade Level: " << GradeWithLetter() << endl;
    std::cout << "-----------------------------\n";
}

void Student::UpdateID(int newId) {
    this->student_id = newId;
    cout << "🆔 ID updated.\n";
}

int Student::GetID() const {
    return this->student_id;
}

Student FindStudentWithID(vector<Student> sList, int ID) {
    for (Student& s : sList) {
        if (s.GetID() == ID) {
            cout << "🔍 Student with ID " << ID << " found.\n";
            return s;
        }
    }
    cout << "❌ No student found with ID: " << ID << endl;
    return sList.front(); 
}

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
