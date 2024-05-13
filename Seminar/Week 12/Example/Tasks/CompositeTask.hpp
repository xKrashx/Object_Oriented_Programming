#ifndef __COMPOSITE_TASK_HPP_
#define __COMPOSITE_TASK_HPP_

#include "SimpleTask.hpp"
#include <vector>

class CompositeTask : public SimpleTask
{
public:
    CompositeTask(std::string const &name);
    CompositeTask(CompositeTask const &other);
    CompositeTask(CompositeTask &&other);
    ~CompositeTask();

    CompositeTask &operator =(CompositeTask const &other);
    CompositeTask &operator =(CompositeTask &&other);

    SimpleTask *Clone() const override;

public:
    void AddTask(SimpleTask *task);
    unsigned Duration() const override;
    void Print() const override;

private:
    void Copy(CompositeTask const &other);
    void Move(CompositeTask &&other);
    void Free();

private:
    std::vector<SimpleTask *> m_Tasks;
};


#endif