#include "String.hpp"

String::String()
{
    this->size = 16;
    this->string = new (std::nothrow) char[this->size + 1];
    std::fill(this->string, this->string + this->size, ' ');
    this->string[this->size] = 0;
}

String::String(size_t size)
{
    this->size = size;
    this->string = new (std::nothrow) char[this->size + 1];
    std::fill(this->string, this->string + this->size, ' ');
    this->string[this->size] = 0;
}

String::String(char *string)
{
    size_t len = 0;
    for (size_t i = 0; string[i]; i++)
    {
        len++;
    }
    this->size = len;
    this->string = new (std::nothrow) char[this->size + 1];

    for (size_t i = 0; i <= this->size; i++)
    {
        this->string[i] = string[i];
    }
}

void String::print()
{
    std::cout << this->string << std::endl;
}

size_t String::Lenght()
{
    size_t len = 0;
    for (size_t i = 0; this->string[i]; i++)
    {
        len++;
    }
    return len;
}

void String::Clear()
{
    this->string[0] = '\0';
}

bool String::Empty()
{
    for (size_t i = 0; this->string[i]; i++)
    {
        return false;
    }

    return true;
}

char String::At(unsigned i)
{
    return this->string[i];
};

char String::operator[](unsigned i)
{
    return this->string[i];
};


void String::Copy(const String &str)
{
    size_t len = 0;
    for (size_t i = 0; str.string[i]; i++)
    {
        len++;
    }
    this->size = len;
    std::cout << len << std::endl;

    char *temp = this->string;

    this->string = new (std::nothrow) char[this->size];
    for (size_t i = 0; i <= this->size; i++)
    {
        this->string[i] = str.string[i];
    }

    delete[] temp; // DALI TRIE BUFERA SUS STARATA PAMET?
}

void String::Append(const String &str)
{
    size_t len = 0;
    for (size_t i = 0; str.string[i]; i++)
    {
        len++;
    }

    char *temp = this->string;
    this->string = new (std::nothrow) char[this->size + len];

    for (size_t i = 0; i < this->size; i++)
    {
        this->string[i] = temp[i];
    }

    for (size_t i = this->size; i <= this->size + len; i++)
    {
        this->string[i] = str.string[i - this->size];
    }

    this->size += len;
    delete[] temp;
}

String String::Combine(String &str)
{
    String temp(this->size);
    temp.Copy(this->string);
    temp.Append(str);
    // this->Append(str);
    return String(temp);
}

const char *String::c_str()
{
    return this->string;
}

std::ostream &operator<<(std::ostream &out, const String &str)
{
    for (size_t i = 0; str.string[i]; i++)
    {
        out << str.string[i];
    }
    return out;
}
