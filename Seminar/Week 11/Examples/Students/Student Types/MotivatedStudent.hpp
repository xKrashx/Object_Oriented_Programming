#ifndef __MOTIVATED_STUDENT_HPP_
#define __MOTIVATED_STUDENT_HPP_

#include "Student.hpp"

class MotivatedStudent : public Student{

public:
    MotivatedStudent(char const *name, size_t fn);

public:
    double PercentageToPassTheExam() const override;
    unsigned HoursSpentPerDayStudying() const override;
    Student *Clone() const override;

};

#endif