#ifndef __STUDENT_HPP
#define __STUDENT_HPP

const unsigned short NUM_GRADES = 5;

class Student
{   
    public:
        void Init(const char* name, unsigned short classNumber);
        void Deallocate();

        const char* GetName() const;
        unsigned short GetClassNumber() const;
        double GetGrade(unsigned short index) const;

        void SetName(const char* name);
        void SetClassNumber(unsigned short classNumber);
        void SetGrade(unsigned short index, double newGrade);

        void Read();
        
        void Print() const;
        double AverageGrade() const;

        int Compare(const Student& other) const;

    private:
        char* name = nullptr;
        unsigned short classNumber = 1;
        double grades[NUM_GRADES];
};

#endif
