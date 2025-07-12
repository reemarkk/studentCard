// Student.h
#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include <vector>
#include <string>

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

Student FindStudentWithID(std::vector<Student>& sList, int ID);

#endif // STUDENT_H
