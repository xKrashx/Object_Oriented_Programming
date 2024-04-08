#include <iostream>
#include <iomanip> // std::setprecision

class Count
{
private:
    int value;

public:
    // Constructor to initialize count to 5
    Count() : value(5) {}

    // // Overload ++ when used as prefix
    // void operator++()
    // {
    //     ++value;
    // }

    // // Overload ++ when used as postfix
    // void operator++(int)
    // {
    //     value++;
    // }

    // Overload ++ when used as prefix
    Count operator++()
    {
        Count temp;

        // Here, value is the value attribute of the calling object
        temp.value = ++value;

        return temp;
    }

    // Overload ++ when used as postfix
    Count operator++(int)
    {
        Count temp;

        // Here, value is the value attribute of the calling object
        temp.value = value++;

        return temp;
    }

    Count operator+(const Count &rhs)
    {
        Count temp;
        temp.value = this->value + rhs.value;
        return temp;
    }

    Count operator+(int rhs)
    {
        Count temp;
        temp.value = this->value + rhs;
        return temp;
    }

    friend Count operator+(int lhs, const Count &rhs);

    operator double()
    {
        return static_cast<double>(this->value);
    }

    // was the class changed?
    operator bool()
    {
        return this->value != 5;
    }

    void print()
    {
        std::cout << "Count: " << value << std::endl;
    }
};

Count operator+(int lhs, const Count &rhs)
{
    Count temp;
    temp.value = lhs + rhs.value;
    return temp;
}

int main()
{
    Count count1;

    // Call the "void operator ++ (int)" function
    count1++;
    count1.print();

    // Call the "void operator ++ ()" function
    ++count1;

    count1.print();

    Count result;

    // Error - we need operator ++ to return Count
    // result = ++count1;

    // Call the "Count operator ++ ()" function
    result = ++count1;
    result.print();

    // Call the "Count operator ++ (int)" function
    result = count1++;
    result.print();

    // We can also do
    (count1++).print();
    (++count1).print();

    std::cout << std::setprecision(3) << std::fixed << (double)count1 << std::endl;
    // std::cout << std::setprecision(3) << std::fixed << count1 << std::endl; // more than one operator matches

    if (!count1)
    {
        std::cout << "count1 has not been changed!" << std::endl;
    }
    else
    {
        std::cout << "count1 has been changed!" << std::endl;
    }
}