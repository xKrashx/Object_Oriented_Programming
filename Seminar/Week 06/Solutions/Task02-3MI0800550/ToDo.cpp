#include "ToDo.hpp"

int ToDo::ids = 1;

ToDo::ToDo()
{
    task_id = ids;
    description = new(std::nothrow) char[1];
    description[0] = ' ';
    done = false;
    ids++;
}

ToDo::ToDo(const ToDo &other)
{
    copy(other);
}

ToDo::ToDo(const char *description)
{
    this->description = new (std::nothrow) char[strlen(description) + 1];
    strcpy(this->description, description);
}

ToDo &ToDo::operator=(const ToDo &other)
{
    if (this != &other)
    {
        free();
        copy(other);
    }
    return *this;
}

ToDo::~ToDo()
{
    free();
}

void ToDo::Do()
{
    char* temp = this->description;
    this->description = new(std::nothrow) char[strlen(this->description)+9];
    strcpy(this->description, "**DONE** ");
    strcat(this->description,temp);
    this->done = true;
    delete[] temp;
}

char *ToDo::GetDescription()
{
    return this->description;
}
