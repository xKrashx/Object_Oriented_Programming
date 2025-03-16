#include <iostream>
// Тази библиотека ви е строго забранено да я ползвате,
// освен ако не е казано изрично, че можете.
#include <vector>
// Тази библиотека няма да ви е разрешена освен, ако не е опоменато.
// За базови сортиращи алгоритми трябва да сте говорили по УП.
#include <algorithm> //sort
#include <iomanip> //setprecision
// Липсва cmath библиотеката!

//Задача 4
struct Student {
   int facultyNumber;
   int course;
   double grade;

   void uniStudent(int fn, int c, double g) {
       facultyNumber = fn;
       course = c;
       grade = g;
   }

   void printStudent() const {
       std::cout << facultyNumber << " " << course << " " << std::fixed << std::setprecision(2) << grade << std::endl;
   }
};

struct Group {
   std::vector<Student> students;

   void addStudent(const Student& s) {
       students.push_back(s);
   }

   double averageGrade() const {
       double sum = 0;
        // За този тип цикъл все още не сме учили, така че се въздържай от употребата му.
        // auto е строго забранено за употреба!!!
       for (const auto& student : students) {
           sum += student.grade;
       }
       return students.empty() ? 0.0 : sum / students.size();
   }

   //Функцията countScholarshipStudents е написана от chatGPT
   int countScholarshipStudents(double minGrade) const {
       int count = 0;
       for (const auto& student : students) {
           if (student.grade >= minGrade) {
               count++;
           }
       }
       return count;
   }
};

int main() {
   int N;
   std::cin >> N;

   Group group;
   for (int i = 0; i < N; i++) {
       int fn, course;
       double grade;
       std::cin >> fn >> course >> grade;

       Student s;
       s.uniStudent(fn, course, grade);
       group.addStudent(s);
   }

   double minGrade;
   std::cin >> minGrade;

   std::cout << std::fixed << std::setprecision(2) << group.averageGrade() << " " << group.countScholarshipStudents(minGrade) << std::endl;

   return 0;
}