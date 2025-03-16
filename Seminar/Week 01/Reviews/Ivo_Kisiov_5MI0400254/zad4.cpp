// Преговори референциите!
#include<iostream>

struct student
{
    unsigned int fn, year;
    double grade;
};

// Подаването на двоен указател не е грешно, но трябваше да се направи структура Group, която да ги пази тези неща.
void readStudentData(student** s, unsigned int n)
{
    for (int i = 0; i < n; i++)
    {
        s[i] = new (std::nothrow) student;
        if (!s[i])
        {
            std::cout << "Memory Error!";
            for (unsigned int j = 0; j <= i; j++)
                delete s[j];
            delete[] s;
            // exit е системна примитива, която е много опасна за употреба.
            // Желателно е да не я използваш, защото ще започнат неудобните въпроси от наша страна.
            // За да избегнеш в случая този проблем, можеш просто да си заделиш паметта в main-а.
            // По този начин тук не трябва да се грижиш да заделяш и четеш.
            // Това "и" във функциите е много ключово.
            // Идеята на една функция е да изпълнява едно действие не повече.
            // Така че в момента, в който се усетиш, че имаш "и" във функционалността,
            // нещо се е объркало и има по-прост начин.
            exit(-1);
        }

        std::cin >> s[i]->fn >> s[i]->year >> s[i]->grade;
        if(s[i]->fn >= 100000 || s[i]->fn < 10000 || s[i]->year == 0 || s[i]->year > 4 || s[i]->grade < 2 || s[i]->grade > 6)
        {
            std::cout << "Invalid data";
            for (unsigned int j = 0; j <= i; j++)
                delete s[j];
            delete[] s;
            // Същите забележки важат и тук!
            exit(-1);
        }
    }
}

double getAverageGrade(student** s, unsigned int n)
{
    if(n == 1)
    {
        return s[n - 1]->grade;
    }

    // Харесва ми attempt-а за рекурсия, но ми се струва, че формулата няма да работи.
    // Резултатът, който ще получиш изглежда, че ще бъде грешен.
    return ((n - 1) * getAverageGrade(s, n - 1) + s[n - 1]->grade) / n;
}

int countNumOfScolarships(student** s, unsigned int n, double reqGrade)
{
    unsigned int count = 0;
    for (int i = 0; i < n; i++)
    {
        if(s[i]->grade >= reqGrade)
        {
            count++;
        }
    }
    return count;
}

int main()
{
    unsigned int n;
    double reqGrade;
    double avrgGrade;
    std::cin >> n;
    if(n == 0 || n > 500)
    {
        std::cout << "Invalid data";
        return -1;
    }

    student** s = new (std::nothrow) student*[n];
    if(!s)
    {
        std::cout << "Memory Error!";
        return -1;
    }

    readStudentData(s, n);

    std::cin >> reqGrade;

    avrgGrade = getAverageGrade(s, n);

    std::cout << avrgGrade << " " << countNumOfScolarships(s, n, reqGrade) << std::endl;

    for (unsigned int i = 0; i < n; i++)
        delete s[i];
    delete[] s;
}