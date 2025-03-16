// Същите забележки както на първа задача.
#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

struct Student {
    int facultyNumber;
    int year;
    double averageGrade;

    Student(int facultyNumber, int year, double averageGrade)
        : facultyNumber(facultyNumber), year(year), averageGrade(averageGrade) {
    }
};

struct Group {
    vector<Student> students;

    double averageGrade() const {
        double sum = 0;
        for (const auto& student : students) {
            sum += student.averageGrade;
        }
        return sum / students.size();
    }

    int countScholarship(double minGrade) const {
        int count = 0;
        for (const auto& student : students) {
            if (student.averageGrade >= minGrade) {
                count++;
            }
        }
        return count;
    }
};

int main() {
    int N;
    cin >> N;

    Group group;
    for (int i = 0; i < N; i++) {
        int facultyNumber, year;
        double averageGrade;
        cin >> facultyNumber >> year >> averageGrade;
        group.students.push_back(Student(facultyNumber, year, averageGrade));
    }

    double minGrade;
    cin >> minGrade;

    cout << fixed << setprecision(4) << group.averageGrade() << " " << group.countScholarship(minGrade) << endl;

    return 0;
}
