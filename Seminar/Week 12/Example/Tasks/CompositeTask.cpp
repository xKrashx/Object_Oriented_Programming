#include "CompositeTask.hpp"
#include <iostream>
#include <utility>

CompositeTask::CompositeTask(std::string const &name) : SimpleTask(name){}

CompositeTask::CompositeTask(CompositeTask const &other) : SimpleTask(other.m_Name){
    Copy(other);
}

CompositeTask::CompositeTask(CompositeTask &&other) : SimpleTask(other.m_Name){
    Move(std::move(other));
}

CompositeTask &CompositeTask::operator =(const CompositeTask &other){

    if(this == &other) return *this;

    *this = CompositeTask(other);

    return *this;

}

CompositeTask &CompositeTask::operator =(CompositeTask &&other){

    if(this == &other) return *this;

    SimpleTask::operator =(std::move(other));
    Free();
    Move(std::move(other));

    return *this;

}

CompositeTask::~CompositeTask(){
    Free();
}

void CompositeTask::AddTask(SimpleTask *task){
    if(task) m_Tasks.push_back(task);
}

unsigned CompositeTask::Duration() const{

    unsigned total = 0;

    for(size_t i = 0; i < m_Tasks.size(); ++i)
        total += m_Tasks[i] -> Duration();

    return total;

}

void CompositeTask::Print() const{

    for(size_t i = 0; i < m_Tasks.size(); ++i)
        m_Tasks[i] -> Print();

}

SimpleTask *CompositeTask::Clone() const{
    return new CompositeTask(*this);
}

void CompositeTask::Copy(CompositeTask const &other){

    for(size_t i = 0; i < other.m_Tasks.size(); ++i)
        m_Tasks.push_back(other.m_Tasks[i] -> Clone());

}

void CompositeTask::Move(CompositeTask &&other){

    for(size_t i = 0; i < other.m_Tasks.size(); ++i)
        m_Tasks[i] = std::exchange(other.m_Tasks[i], nullptr);

}

void CompositeTask::Free(){

    for(size_t i = 0; i < m_Tasks.size(); ++i)
        delete m_Tasks[i];

}