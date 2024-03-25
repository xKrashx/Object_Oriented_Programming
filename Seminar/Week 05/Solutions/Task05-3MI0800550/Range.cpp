#include "Range.hpp"

bool isPrime(int n)
{
    if (n <= 1)
        return false;

    for (int i = 2; i <= n / 2; i++)
        if (n % i == 0)
            return false;

    return true;
}

bool isPalindrome(int n)
{
    int rev = 0, temp = n;
    while (temp > 0)
    {
        rev = rev * 10 + temp % 10;
        temp /= 10;
    }

    return rev == n;
}

bool hasRepeatingDigits(int n)
{
    if (n >= -10 && n <= 10)
    {
        return true;
    }
    int size = 0;
    int digits[10];
    int digit = 0;
    while (n != 0)
    {
        digit = n % 10;
        n /= 10;
        for (size_t i = 0; i < size; i++)
        {
            if (digit == digits[i])
            {
                return false;
            }
        }
        digits[size] = digit;
        size++;
    }
    return true;
}

bool IsPowerOfTwo(size_t x)
{
    return (x != 0) && ((x & (x - 1)) == 0);
}

Range::Range()
{
    this->a = 0;
    this->b = 0;
}

Range::Range(const int a, const int b)
{
    if (a <= b)
    {
        this->a = a;
        this->b = b;
    }
    else
    {
        this->a = 0;
        this->b = 0;
    }
}

void Range::SetA(const int a)
{
    if (a > this->b)
    {
        this->a = 0;
    }
    else
        this->a = a;
}

void Range::SetB(const int b)
{
    if (b < this->a)
    {
        this->b = this->a;
    }
    else
        this->b = b;
}

int Range::Lenght()
{
    return this->b - this->a;
}

bool Range::IsInRange(const int c)
{
    if (this->a <= c && c <= this->b)
    {
        return true;
    }
    return false;
}

size_t Range::NumOfPrimes()
{
    size_t count = 0;
    for (int i = this->a; i <= this->b; i++)
    {
        if (isPrime(i))
            count++;
    }
    return count;
}

size_t Range::NumOfPalindromes()
{
    size_t count = 0;
    for (int i = this->a; i <= this->b; i++)
    {
        if (isPalindrome(i))
            count++;
    }
    return count;
}

size_t Range::NumOfNonrepeating()
{
    size_t count = 0;
    for (int i = this->a; i <= this->b; i++)
    {
        if (hasRepeatingDigits(i))
            count++;
    }
    return count;
}

bool Range::PowerOfTwo()
{
    if (IsPowerOfTwo(this->a) && IsPowerOfTwo(this->b))
    {
        return true;
    }
    return false;
}

Range Range::Intersect(const Range second)
{
    if (second.a >= this->a && second.b <= this->b)
    {
        return Range(second.a, second.b);
    }
    else if (second.a < this->a && second.b <= this->b)
    {
        return Range(this->a, second.b);
    }
    else if (second.a >= this->a && second.b > this->b)
    {
        return Range(second.a, this->b);
    }
    else
        return Range(this->a, this->b);
}

Range Range::Union(const Range second)
{
    int newA = std::min(this->a, second.a); // New start point
    int newB = std::max(this->b, second.b); // New end point

    return Range(newA, newB);
}

bool Range::IsSubRange(const Range second)
{
    return (this->a >= second.a && this->b <= second.b);
}

std::ostream &operator<<(std::ostream &out, const Range &range)
{
    out << '[' << range.a << ',' << range.b << ']';
    return out;
}


// Range Range::operator=(const Range &range)
// {
    
// }

