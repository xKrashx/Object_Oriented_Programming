#ifndef __DATE_HPP
#define __DATE_HPP

class Date
{
    public:
        Date(unsigned short day, unsigned short month, unsigned short year);

        unsigned short GetDay() const;
        unsigned short GetMonth() const;
        unsigned short GetYear() const;

        void Print() const;

    private:
        unsigned short day;
        unsigned short month;
        unsigned short year;

        static bool IsLeapYear(unsigned short year);
};

#endif
