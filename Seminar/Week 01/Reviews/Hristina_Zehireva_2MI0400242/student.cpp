#include <iostream>
#include <iomanip>

struct Student{
    int fn;
    int course;
    double avgGrade;
};

struct Group{
    // Целта на задачата беше да въведем размера
    // на този масив и да го заделим динамично.
    Student students[500];
    double averageGrade;
    int studentCount;

    
    
    // За методи не е говорено, така че нека не бързаме с материала!
    void calcAvgGrade()
    {
        double totalGrade = 0;
        for (int i = 0; i < studentCount; i++)
        {
            totalGrade += students[i].avgGrade;
        }
        averageGrade = totalGrade / studentCount;
    }
    
    int countScholarEligible(double minGrade) const{
        int count = 0;
        for (int i = 0; i < studentCount; i++)
        {
            if (students[i].avgGrade >= minGrade)
            {
                count++;
            }
            
        }
        return count;
    }
};

Student initStudent(int fn, int course, double avgGrade)
{
    Student student;
    student.fn = fn;
    student.course = course;
    student.avgGrade = avgGrade;
    return student;
}

void printStudent(const Student &student)
{
    std::cout << student.fn << student.course << student.avgGrade << std::endl;
}

int main()
{
    int N;
    std::cin >> N;

    if (N < 1 || N > 500)
    {
        std::cerr << "Invalid input";
        // Един return нямаше да е лоша идея, тъй като така само
        // принтираме съобщението и продължаваме нататък!
    }

    Group group;
    group.studentCount = N;
    
    for (int i = 0; i < N; i++)
    {
        int fn, course;
        double avgGrade;
        std::cin >> fn >> course >> avgGrade;

        if (fn < 10000 || fn >= 100000)
        {
            std::cerr << "invalid input" << '\n';
            return 1;
        }
        if (course < 1 || course > 4)
        {
            std::cerr << "invalid" << '\n';
            return 1;
        }
        if (avgGrade < 2 || avgGrade > 6)
        {
            std::cerr << "invalid input" << '\n';
            return 1;
        }
        
        group.students[i] = initStudent(fn, course, avgGrade);
    }

    double minGrade;
    std::cin >> minGrade;

    group.calcAvgGrade();
    int scholarStud = group.countScholarEligible(minGrade);

    std::cout << std::fixed << std::setprecision(4) << group.averageGrade <<' ' << scholarStud << std::endl;
    
    

    return 0;
}