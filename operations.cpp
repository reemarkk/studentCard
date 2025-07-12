// Student.cpp
#include "student.h"

Student::Student(int student_id, std::string student_name, std::vector<double> scores) {
    this->student_id = student_id;
    this->student_name = student_name;
    this->scores = scores;
}

void Student::AddScore(double newScore) {
    this->scores.push_back(newScore);
    std::cout << "➕ Score added successfully.\n";
}

void Student::updateName(const std::string& newName) {
    this->student_name = newName;
    std::cout << "✏️  Name updated.\n";
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
        std::cout << "There is no score yet. Enter your scores first!" << std::endl;
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
    std::cout << "Student ID: " << this->student_id << std::endl;
    std::cout << "Student Name: " << this->student_name << std::endl;
    std::cout << "Student Grades: ";
    for (double score : scores) std::cout << score << " ";
    std::cout << std::endl;
    std::cout << "Average Score: " << getAverage() << std::endl;
    std::cout << "Grade Level: " << GradeWithLetter() << std::endl;
    std::cout << "-----------------------------\n";
}

void Student::UpdateID(int newId) {
    this->student_id = newId;
    std::cout << "🆔 ID updated.\n";
}

int Student::GetID() const {
    return this->student_id;
}

Student FindStudentWithID(std::vector<Student>& sList, int ID) {
    for (Student& s : sList) {
        if (s.GetID() == ID) {
            std::cout << "🔍 Student with ID " << ID << " found.\n";
            return s;
        }
    }
    std::cout << "❌ No student found with ID: " << ID << std::endl;
    return sList.front();
}
