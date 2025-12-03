#include <iostream> 
using namespace std; 

struct Student { 
    int student_id;
    string name;
    string major;
    int total_credits;
    double gpa;
    Student* next;
};

struct Course { 
    string course_code; 
    string course_name;
    int credits;
    int capacity;
    int enrolled_count; 
    string* prerequisites;
    int prereg_count;
    Course* next;
};

struct Enrollment { 
    int student_id;
    string course_code;
    char grade;
    string semester;
    Enrollment* next;
};