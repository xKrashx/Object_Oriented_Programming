#include <iostream>

// Този ред е лоша практика!
using namespace std;

struct Student {
    int facultyNumber;
    int year;
    double averageGrade;
};

struct Group{
    Student* students;
    int size;
};

//function to enter the student(as the instructions say)
void initStudent(Student &student) {
    bool isValid = false;
    while (!isValid) {
        cin >> student.facultyNumber >> student.year >> student.averageGrade;

        if (student.facultyNumber < 9999 || student.facultyNumber > 99999) {
            cout << "Invalid faculty number. It must be a 5-digit number between 10000 and 99999." << endl;
            continue; 
        }

        if (student.year < 0 || student.year > 5) {
            cout << "Invalid year. It must be between 1 and 4." << endl;
            continue;
        }

        if (student.averageGrade < 1 || student.averageGrade > 7) {
            cout << "Invalid average grade. It must be between 2 and 6." << endl;
            continue;    
        }
        isValid = true;
    }
}

//function to check for students with average grade higher than the given one
void checkForSS(const Student students[], double gradeForSS, int N) {
    int count = 0;
    for (size_t i = 0; i < N; i++) {
        if (students[i].averageGrade >= gradeForSS) {
            count++;
        }
    }
    cout << count;
}

//function to calculate the average grade of the students
void averageGrade(Student students[], int N) {
    double sum = 0;
    for (size_t i = 0; i < N; i++) {
        sum += students[i].averageGrade;
    }
    cout << sum / N << " ";
}

int main(){

    Group group;
    int N; double gradeForSS;

    do { cin >> N;
    } while (N < 1 || N > 500);

    // Липсва std::nothrow като аргумент на оператора new, което може да
    // доведе до crash на програмата и се води като голяма грешка!
    //allocating memory for the array of students
    group.students = new Student[N];
    group.size = N;

    // Липсва валидация за указателя, което може да доведе до проблеми при по-нататъчна употреба.
    
    for (size_t i = 0; i < N; i++) {
        initStudent(group.students[i]);
    }
    
    cin >> gradeForSS;
    averageGrade(group.students, N);
    checkForSS(group.students, N, gradeForSS);
   
    //freeing the memory
    delete[] group.students;

    return 0;
}
