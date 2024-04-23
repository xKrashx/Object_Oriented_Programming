#ifndef __DUMP_DYN_ARRAY_HPP
#define __DUMP_DYN_ARRAY_HPP

class DumbDynArray
{
    public:
        DumbDynArray(const char* str);
        ~DumbDynArray();

        void Print() const;

    private:
        unsigned short* array;
        unsigned short size;

        bool IsDigit(char c) const;
        unsigned short CountDigits(const char* str) const;
};

#endif
