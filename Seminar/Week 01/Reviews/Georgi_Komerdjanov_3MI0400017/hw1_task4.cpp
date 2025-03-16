#include <iostream>
// Отново, употребяваш забранена библиотека.
#include <vector>
#include <iomanip>

// Отново, лоша практика!
using namespace std;

struct Student {

    int facultyNumber;
    int year;
    double averageGrade;
};

struct Group {

    vector<Student> students;

    double computeAverageGrade() const {

        double sum = 0;
        // Този вид цикъл все още не е изучаван и се въздържаме от употребата му,
        // ако не искаме преподавателите да ни задават неудобни въпроси.
        // auto е строго забранен идентификатор и се таксува!
        for (const auto& student : students) {

            sum += student.averageGrade;
        }
        return students.empty() ? 0 : sum / students.size();
    }

    int countScholarshipStudents(double minGrade) const {

        int count = 0;
        // Същите забележки тук!
        for (const auto& student : students) {

            if (student.averageGrade >= minGrade) {

                count++;
            }
        }
        return count;
    }
};

bool isValidStudent(int facultyNumber, int year, double averageGrade) {

    return (facultyNumber >= 10000 && facultyNumber < 100000) &&
        (year >= 1 && year <= 4) &&
        (averageGrade >= 2.0 && averageGrade <= 6.0);
}

int main() {

    int N;
    cin >> N;
    if (N < 1 || N > 500) {

        cerr << "Error. N must be: 1 <= N <= 500" << endl;
        return 1;
    }

    Group group;
    for (int i = 0; i < N; ++i) {

        int facultyNumber, year;
        double averageGrade;
        cin >> facultyNumber >> year >> averageGrade;

        if (!isValidStudent(facultyNumber, year, averageGrade)) {

            cerr << "Invalid student data" << endl;
            return 1;
        }

        group.students.push_back({ facultyNumber, year, averageGrade });
    }

    double minScholarshipGrade;
    cin >> minScholarshipGrade;

    double avgGrade = group.computeAverageGrade();
    int scholarshipCount = group.countScholarshipStudents(minScholarshipGrade);

    cout << fixed << setprecision(4) << avgGrade << " " << scholarshipCount << endl;

    return 0;
}
