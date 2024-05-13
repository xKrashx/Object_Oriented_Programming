#ifndef __SIMPLE_TASK_HPP_
#define __SIMPLE_TASK_HPP_

#include <string>

class SimpleTask{

public:
    SimpleTask(std::string const &name);
    SimpleTask(std::string const &name, unsigned time);
    virtual ~SimpleTask() = default;

    virtual SimpleTask* Clone() const;

public:
    virtual unsigned Duration() const;
    virtual void Print() const;

protected:
    std::string m_Name;

private:
    unsigned m_Time = 0;

};

#endif