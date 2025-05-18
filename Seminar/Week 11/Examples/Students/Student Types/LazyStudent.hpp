#ifndef __LAZY_STUDENT_HPP_
#define __LAZY_STUDENT_HPP_

#include "Student.hpp"

class LazyStudent : public Student{

public:
    LazyStudent(char const *name, size_t fn);

public:
    double PercentageToPassTheExam() const override;
    unsigned HoursSpentPerDayStudying() const override;
    Student *Clone() const override;

};

#endif