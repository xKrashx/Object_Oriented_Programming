#include "SimpleTask.hpp"
#include <iostream>

SimpleTask::SimpleTask(std::string const &name){ m_Name = name; }

SimpleTask::SimpleTask(std::string const &name, unsigned time){

    m_Name = name;
    m_Time = time;

}

SimpleTask *SimpleTask::Clone() const{ return new SimpleTask(*this); }

unsigned SimpleTask::Duration() const{ return m_Time; }

void SimpleTask::Print() const{ std::cout << m_Name << ' ' << m_Time << '\n'; }
