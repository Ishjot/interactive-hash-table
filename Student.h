#ifndef STUDENT_H
#define STUDENT_H

#include <string>

class Student {

  private:
    std::string name;
    double gpa;

  public:
    Student(std::string name, double gpa) : name(name), gpa(gpa)
      {}

    void setName(std::string name) { this->name = name; }
    void setGPA(double gpa) { this->gpa = gpa; }
    const std::string getName() const { return name; }
    const double getGPA() const { return gpa; }
};

#endif
