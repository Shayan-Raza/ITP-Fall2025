#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
using namespace std;

struct Student {
    int student_id ;
    string name;
    string major;
    int total_credits ;
    double gpa;
    Student* next;
};

struct Course {
    string course_code ;
    string course_name ;
    int credits;
    int capacity;
    int enrolled_count ;
    string* prerequisites ;
    int prereq_count ;
    Course* next;
};

struct Enrollment {
    int student_id ;
    string course_code ;
    char grade;
    string semester;
    Enrollment * next;
};

Student* find_student(Student* student_list ,int student_id ){
    // traversing the linked list until we dont hit a nullptr
    Student* curr = student_list;
    while(curr != nullptr){
        if(curr->student_id == student_id){
            return curr;
        }
        curr = curr->next;
    }
    return nullptr; // if student not found
}

Course* find_course (Course* course_list , const string& course_code ){
    // traversing the linked list until we dont hit a nullptr
    Course* curr = course_list;
    while(curr != nullptr){
        if(curr->course_code == course_code){
            return curr;
        }
        curr = curr->next;
    }
    return nullptr; // if course not found
}

bool already_enrolled (Enrollment * enrollment_list , int student_id , const string& course_code ){
    // traversing the list till we dont hit a nullptr
    Enrollment* curr = enrollment_list;
    while(curr != nullptr){
        if(curr->course_code == course_code && curr->student_id == student_id){
            return true;
        }
        curr = curr->next;
    }
    return false; // if not found
}

void add_student (Student *& student_list ,int id ,const string& name ,const string& major){
    // adding to the students linked list
    Student* newStudent = new Student;
    newStudent->student_id = id;
    newStudent->name = name;
    newStudent->major = major;
    newStudent->total_credits = 0;
    newStudent->gpa = 0.0;
    newStudent->next = student_list;
    student_list = newStudent;
}

bool update_major (Student* student_list , int student_id , const string& new_major){
    // using the function above to find the student then update the major
    Student* curr = find_student(student_list, student_id);//finding student location
    if(curr != nullptr){ // making sure the student exists
        curr->major = new_major; //updating major
        return true;
    } else {
        return false;
    }
}

void remove_student (Student *& student_list , Enrollment *& enrollment_list , int student_id ){
    // removing from the linked list
    Student* curr = student_list;
    Student* prev = nullptr;

    while(curr!= nullptr && curr->student_id != student_id){
        prev = curr;
        curr = curr->next;
    }
    if(curr == nullptr){
        cout<<"Student not found."<<endl;
        return;
    }

    Enrollment* ecurr = enrollment_list;
    Enrollment* eprev = nullptr;
    while(ecurr != nullptr){
        if(ecurr->student_id == student_id){
            Enrollment* temp = ecurr;
            if(eprev == nullptr) enrollment_list = ecurr->next;
            else eprev->next = ecurr->next;
            ecurr = ecurr->next;
            delete temp;
        } else {
            eprev = ecurr;
            ecurr = ecurr->next;
        }
    }
    if(prev == nullptr){
        student_list = curr->next;
    } else {
        prev->next = curr->next;
    }
    delete curr;
}

void add_course (Course *& course_list , const string& code , const string& name , int credits ,int capacity){
    // adding into the linked list
    Course* newCourse = new Course;
    newCourse->course_code = code;
    newCourse->course_name = name;
    newCourse->credits = credits;
    newCourse->capacity = capacity;
    newCourse->enrolled_count = 0;
    newCourse->prerequisites = nullptr;
    newCourse->prereq_count = 0;
    newCourse->next = course_list;
    course_list = newCourse;
}

void add_prerequisite (Course* course ,const string& prereq_code){
    string* arr = new string[course->prereq_count + 1];
    for(int i=0; i<course->prereq_count; i++){
        arr[i] = course->prerequisites[i];
    }
    arr[course->prereq_count] = prereq_code;
    delete[] course->prerequisites;
    course->prerequisites = arr;
    course->prereq_count++;
}

bool remove_course (Course *& course_list , Enrollment * enrollment_list , const string& course_code){
    // remove from linked list
    Course* curr = course_list;
    Course* prev = nullptr;
    while(curr != nullptr){
        if(curr->course_code == course_code){
            if(curr->enrolled_count>0){
                return false;
            }
            if(prev == nullptr){
                course_list = curr->next;
            } else {
                prev->next = curr->next;
            }
            delete[] curr->prerequisites;
            delete curr;
            return true;
        }
        prev = curr;
        curr= curr->next;
    }
    return false;
}

bool check_prerequisites (Enrollment * enrollment_list , Course* course , int student_id ){
    if(course->prereq_count == 0){
        return true;
    }
    for(int i = 0; i < course->prereq_count; i++) {
        string prereq = course->prerequisites[i]; 
        bool found = false;
        Enrollment* curr = enrollment_list;
        while(curr != nullptr){
            if(curr->student_id == student_id && curr->course_code == prereq &&
               (curr->grade == 'A' || curr->grade == 'B' || curr->grade == 'C')){
                found = true;
                break;
            }
            curr = curr->next;
        }
        if(!found) return false;
    }
    return true;
}

bool check_credit_limit(Enrollment* enrollment_list,Course* course_list,int student_id,const string& semester,int new_course_credits) {
    // keep adding the credit hours then return if they are less than 18
    int total_credits = 0;
    Enrollment* eCurr = enrollment_list;
    while (eCurr) {
        if (eCurr->student_id == student_id && eCurr->semester == semester) {
            Course* c = find_course(course_list, eCurr->course_code);
            if (c) total_credits += c->credits;
        }
        eCurr = eCurr->next;
    }
    total_credits += new_course_credits;
    return total_credits <= 18;
}

bool enroll_student(Student* student_list,Course* course_list,Enrollment*& enrollment_list,int student_id,const string& course_code,const string& semester) {
    Student* s = find_student(student_list, student_id);
    if (!s) return false;

    Course* c = find_course(course_list, course_code);
    if (!c) return false;

    if (already_enrolled(enrollment_list, student_id, course_code))
        return false;

    if (!check_prerequisites(enrollment_list, c, student_id))
        return false;

    if (!check_credit_limit(enrollment_list, course_list, student_id, semester, c->credits))
        return false;

    if (c->enrolled_count >= c->capacity)
        return false;

    Enrollment* newEnroll = new Enrollment{student_id, course_code, 'P', semester, enrollment_list};
    enrollment_list = newEnroll;
    c->enrolled_count++;
    return true;
}

bool drop_course(Enrollment*& enrollment_list,Course* course_list,int student_id,const string& course_code) {
    // remove from linked list
    Enrollment* curr = enrollment_list;
    Enrollment* prev = nullptr;

    while (curr) {
        if (curr->student_id == student_id && curr->course_code == course_code) {
            Course* c = find_course(course_list, course_code);
            if (c && c->enrolled_count > 0) c->enrolled_count--;

            if (!prev) enrollment_list = curr->next;
            else prev->next = curr->next;

            delete curr;
            return true;
        }
        prev = curr;
        curr = curr->next;
    }
    return false;
}

bool assign_grade(Enrollment* enrollment_list,int student_id,const string& course_code,char grade) {
    Enrollment* curr = enrollment_list;
    while (curr) {
        if (curr->student_id == student_id && curr->course_code == course_code) {// when the student is found change the grade
            curr->grade = grade;
            return true;
        }
        curr = curr->next;
    }
    return false;
}

void update_gpa(Student* student_list,Enrollment* enrollment_list,int student_id,Course* course_list) {
    Student* s = find_student(student_list, student_id);
    if (!s) return;

    double total_points = 0;
    int total_credits = 0;
    int credits_completed = 0;

    Enrollment* curr = enrollment_list;
    while (curr) {
        if (curr->student_id == student_id) {
            Course* c = find_course(course_list, curr->course_code);
            if (c) {
                double gp = 0;
                switch (curr->grade) {
                    case 'A': gp = 4; break;
                    case 'B': gp = 3; break;
                    case 'C': gp = 2; break;
                    case 'D': gp = 1; break;
                    case 'F': gp = 0; break;
                    default: gp = -1;
                }
                if (gp >= 0) {
                    total_points += gp * c->credits;
                    total_credits += c->credits;
                    if (gp >= 2) credits_completed += c->credits;
                }
            }
        }
        curr = curr->next;
    }
    s->gpa = (total_credits > 0) ? total_points / total_credits : 0.0; // if total credits are more than 0 calculate GPA else it is a zero
    s->total_credits = credits_completed;
}

void list_student_courses(Enrollment* enrollment_list,Course* course_list,int student_id,const string& semester) {
    cout << "Courses for student " << student_id << " in " << semester << ":\n";
    Enrollment* curr = enrollment_list;
    while (curr) { // keep looping until nullptr and output all the courses of the student
        if (curr->student_id == student_id && curr->semester == semester) {
            cout << curr->course_code << " Grade: " << curr->grade << "\n";
        }
        curr = curr->next;
    }
}

void list_course_students(Enrollment* enrollment_list,Student* student_list,const string& course_code) {
    cout << "Students in course " << course_code << ":\n";
    Enrollment* curr = enrollment_list;
    while (curr) { // keep looping until nullptr and print all students
        if (curr->course_code == course_code) {
            Student* s = find_student(student_list, curr->student_id);
            if (s) cout << s->student_id << " " << s->name << " Grade: " << curr->grade << "\n";
        }
        curr = curr->next;
    }
}

void generate_transcript(Student* student_list,Enrollment* enrollment_list,Course* course_list,int student_id) {
    Student* s = find_student(student_list, student_id);
    if (!s) {
        cout << "Student not found\n";
        return;
    }
    cout << "Transcript for " << s->name << " (" << s->student_id << ")\n";
    cout << left << setw(12) << "Course" << setw(8) << "Credits" << setw(6) << "Grade" << "\n";

    Enrollment* curr = enrollment_list;
    while (curr) {
        if (curr->student_id == student_id) {
            Course* c = find_course(course_list, curr->course_code);
            if (c) {
                cout << left << setw(12) << c->course_code<< setw(8) << c->credits<< setw(6) << curr->grade << "\n";
            }
        }
        curr = curr->next;
    }
    cout << "GPA: " << s->gpa << " Total Credits: " << s->total_credits << "\n";
}
ostream& operator<<(ostream& out, const Student& s) {
    out << "ID: " << s.student_id<< " , Name: " << s.name<< " , Major: " << s.major<< " , Credits: " << s.total_credits<< ", GPA: " << fixed << setprecision(2) << s.gpa;
    return out;
}

void save_system(Student* student_list, Course* course_list, Enrollment* enrollment_list) {
    // opening all three files and inserting the contents of the linked list to each
    ofstream sf("students.txt");
    for(Student* s = student_list; s; s = s->next)
        sf << s->student_id << "," << s->name << "," << s->major << "," << s->total_credits << "," << s->gpa << "\n";
    sf.close();

    ofstream cf("courses.txt");
    for(Course* c = course_list; c; c = c->next) {
        cf << c->course_code << "," << c->course_name << "," << c->credits << "," << c->capacity << ",";
        for(int i = 0; i < c->prereq_count; i++) {
            cf << c->prerequisites[i];
            if(i != c->prereq_count - 1) cf << ";";
        }
        cf << "\n";
    }
    cf.close();

    ofstream ef("enrollments.txt");
    for(Enrollment* e = enrollment_list; e; e = e->next)
        ef << e->student_id << "," << e->course_code << "," << e->grade << "," << e->semester << "\n";
    ef.close();
}

void load_system(Student*& student_list, Course*& course_list, Enrollment*& enrollment_list) {
    //start with empty lists
    student_list = nullptr;
    course_list = nullptr;
    enrollment_list = nullptr;
    string line, temp;

    ifstream sf("students.txt");
    while(getline(sf, line)) {
        stringstream ss(line);
        Student* s = new Student;
        getline(ss, temp, ','); s->student_id = stoi(temp);
        getline(ss, s->name, ',');
        getline(ss, s->major, ',');
        getline(ss, temp, ','); s->total_credits = stoi(temp);
        getline(ss, temp); s->gpa = stod(temp);
        s->next = student_list;
        student_list = s;
    }
    sf.close();

    ifstream cf("courses.txt");
    while(getline(cf, line)) {
        stringstream ss(line);
        Course* c = new Course;
        string prereq;
        getline(ss, c->course_code, ',');
        getline(ss, c->course_name, ',');
        getline(ss, temp, ','); c->credits = stoi(temp);
        getline(ss, temp, ','); c->capacity = stoi(temp);
        getline(ss, prereq);

        c->prereq_count = 0;
        c->prerequisites = nullptr;
        if(!prereq.empty()) {
            stringstream ps(prereq);
            while(getline(ps, temp, ';')) c->prereq_count++;
            c->prerequisites = new string[c->prereq_count];
            ps.clear(); ps.str(prereq);
            int i = 0;
            while(getline(ps, temp, ';')) c->prerequisites[i++] = temp;
        }
        c->enrolled_count = 0;
        c->next = course_list;
        course_list = c;
    }
    cf.close();

    ifstream ef("enrollments.txt");
    while(getline(ef, line)) {
        stringstream ss(line);
        Enrollment* e = new Enrollment;
        getline(ss, temp, ','); e->student_id = stoi(temp);
        getline(ss, e->course_code, ',');
        getline(ss, temp, ','); e->grade = temp[0];
        getline(ss, e->semester);
        e->next = enrollment_list;
        enrollment_list = e;
    }
    ef.close();
}

int main() {
    Student* students = nullptr;
    Course* courses = nullptr;
    Enrollment* enrollments = nullptr;

    int choice;
    while(true) {
        cout << "=== University Course Registration System ===\n";
        cout << "1. Load data from files\n";
        cout << "2. Save data to files\n";
        cout << "3. Add student\n";
        cout << "4. Add course\n";
        cout << "5. Enroll student in course\n";
        cout << "6. Drop course\n";
        cout << "7. Assign grade\n";
        cout << "8. List student courses (by semester)\n";
        cout << "9. List course students\n";
        cout << "10. Generate transcript\n";
        cout << "11. Remove student\n";
        cout << "12. Exit\n";
        do { 
            cout << "Enter your choice: ";
            cin >> choice;
            if (cin.fail()) {
                cin.clear(); 
                cin.ignore(10000, '\n');
                cout << "Invalid input. Please enter a number.\n"; 
            }
        } while (choice >12 || choice < 1);

        if(choice == 12) break;

        if(choice == 3) {
            int id;
            string name, major;
            cout << "Enter student ID, name, major: ";
            cin >> id >> ws;
            getline(cin, name);
            getline(cin, major);
            add_student(students, id, name, major);
        } else if(choice == 4) {
            string code, name;
            int credits, capacity;
            cout << "Enter course code, name, credits, capacity: ";
            cin >> ws;
            getline(cin, code);
            getline(cin, name);
            cin >> credits >> capacity;
            add_course(courses, code, name, credits, capacity);
        } else if(choice == 5) {
            int id;
            string course_code, semester;
            cout << "Enter student ID, course code, semester: ";
            cin >> id >> ws;
            getline(cin, course_code);
            getline(cin, semester);
            if(enroll_student(students, courses, enrollments, id, course_code, semester))
                cout << "Enrollment successful.\n";
            else
                cout << "Enrollment failed.\n";
        } else if(choice == 6) {
            int id;
            string course_code;
            cout << "Enter student ID, course code: ";
            cin >> id >> ws;
            getline(cin, course_code);
            if(drop_course(enrollments, courses, id, course_code))
                cout << "Course dropped.\n";
            else
                cout << "Drop failed.\n";
        } else if(choice == 7) {
            int id;
            string course_code;
            char grade;
            cout << "Enter student ID, course code, grade: ";
            cin >> id >> ws;
            getline(cin, course_code);
            cin >> grade;
            if(assign_grade(enrollments, id, course_code, grade)) {
                update_gpa(students, enrollments, id, courses);
                cout << "Grade assigned.\n";
            } else {
                cout << "Failed to assign grade.\n";
            }
        } else if(choice == 8) {
            int id;
            string semester;
            cout << "Enter student ID, semester: ";
            cin >> id >> ws;
            getline(cin, semester);
            list_student_courses(enrollments, courses, id, semester);
        } else if(choice == 9) {
            string course_code;
            cout << "Enter course code: ";
            cin >> ws;
            getline(cin, course_code);
            list_course_students(enrollments, students, course_code);
        } else if(choice == 10) {
            int id;
            cout << "Enter student ID: ";
            cin >> id;
            generate_transcript(students, enrollments, courses, id);
        } else if(choice == 11) {
            int id;
            cout << "Enter student ID: ";
            cin >> id;
            remove_student(students, enrollments, id);
        } else if(choice == 1) {
            load_system(students, courses, enrollments);
        } else if(choice == 2) {
            save_system(students, courses, enrollments);
        } else {
            cout << "Invalid choice.\n";
        }

        cout << "\n";
    }

    return 0;
}