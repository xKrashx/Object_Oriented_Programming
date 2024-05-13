#include "CompositeTask.hpp"
#include <iostream>

int main(){

    SimpleTask t1("Login page", 3);
    SimpleTask t2("Create contact page", 2);
    SimpleTask t3("Contacts list page", 4);
    CompositeTask c1("Write Code");

    c1.AddTask(&t1);
    c1.AddTask(&t2);
    c1.AddTask(&t3);

    SimpleTask t4("Test App", 2);

    SimpleTask t5("Create AWS account", 1);
    SimpleTask t6("Run deployment", 1);
    CompositeTask c2("Deploy");

    c2.AddTask(&t5);
    c2.AddTask(&t6);

    CompositeTask c3("Create \"My Contacts\" App");
    c3.AddTask(&c1);
    c3.AddTask(&t4);
    c3.AddTask(&c2);

    c3.Print();
    std::cout << c3.Duration() << '\n';

    return 0;

}