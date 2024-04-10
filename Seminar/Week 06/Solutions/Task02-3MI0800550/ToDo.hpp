#include <iostream>
#include <cstring>

class ToDo
{
public:
    ToDo();
    ToDo(const ToDo &other);
    ToDo(const char* description);
    ToDo &operator=(const ToDo &other);
    ~ToDo();

    void Do();
    char *GetDescription();

    int task_id;
private:
    char *description;
    static int ids;
    bool done;

    void copy(const ToDo &other)
    {
        description = new (std::nothrow) char[strlen(other.description) + 1];
        strcpy(description, other.description);
        task_id = other.task_id;
        done = other.done;
    }

    void free()
    {
        delete[] description;
    }
};
