#ifndef __MAJOR_HPP_
#define __MAJOR_HPP_

#include "../Student Types/Student.hpp"

class Major{

public:
    Major();
    Major(Major const &other);
    Major(Major &&other);
    ~Major();

    Major &operator =(Major const &other);
    Major &operator =(Major &&other);

private:
    void Resize(size_t newCapacity);
    void Copy(Major const &other);
    void Move(Major &&other);
    void Free();

public:
    Student *&operator [](size_t index);
    Student const *operator [](size_t index) const;

public:
    void AddStudent(Student *student);
    void YeetFromUni(size_t index);
    void SwapMajor(size_t index, Major &other);

public:
    size_t Size() const;
    size_t TakeExam() const;
    bool IsAdequateMajor() const;

private:
    size_t m_Size = 0, m_Capacity = 8;
    Student **m_Students = nullptr;

};

#endif