#ifndef __STUDENT_HPP_
#define __STUDENT_HPP_

#include <cstddef>

class Student{

public:
    Student(char const *name, size_t fn);
    Student(Student const &other);
    Student(Student &&other) noexcept;
    virtual ~Student() noexcept;

    Student &operator =(Student const &other);
    Student &operator =(Student &&other) noexcept;

private:
    void Copy(Student const &other);
    void Move(Student &&other) noexcept;
    void Free() noexcept;

public:
    char const *GetName() const;
    size_t GetFN() const;

public:
    virtual double PercentageToPassTheExam() const = 0;
    virtual unsigned HoursSpentPerDayStudying() const = 0;
    virtual Student *Clone() const = 0;

public:
    static size_t AliveStudents();

private:
    static size_t numberOfStudentsCreated;
    char *m_Name = nullptr;
    size_t m_Fn = 0;

};

#endif