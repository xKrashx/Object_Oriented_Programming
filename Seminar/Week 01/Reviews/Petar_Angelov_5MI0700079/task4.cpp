#include <iostream>
#include <iomanip>
// Този ред е много лоша практика!
using namespace std;
 
struct Student {
    int facNum;
    int course;
    double grade;
};
 
struct Group {
    Student* students;
    int count;
    double avgGrade;
};
 
void initStudent(Student &s) {
    cin >> s.facNum >> s.course >> s.grade;
}
 
int countScholarship(const Group &g, double minGrade) {
    int count = 0;
    for (int i = 0; i < g.count; i++){
        if(g.students[i].grade >= minGrade)
            count++;
    }
    return count;
}
 
int main(){
    int n;
    cin >> n;
    // Нямаш валидация за n.
    // Какво ще стане ако въведа отрицателно число?
    Group group;
    group.count = n;
    // Липсва ти std::nothrow като аргумент на оператора new.
    // Това потенциално може да доведе до crash в програмата ти и се счита за сериозна грешка!
    group.students = new Student[n];
    // Нямаш валидация за това дали масивът се е заделил коректно, отново се счита за голяма грешка.
    double sum = 0;
    for (int i = 0; i < n; i++){
        initStudent(group.students[i]);
        sum += group.students[i].grade;
    }
    group.avgGrade = sum / n;
    double minGrade;
    cin >> minGrade;
    int scholarshipCount = countScholarship(group, minGrade);
    cout << fixed << setprecision(4) << group.avgGrade << " " << scholarshipCount;
    delete[] group.students;
    return 0;
}
