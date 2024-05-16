#include "Major/Major.hpp"
#include "Factory/Factory.hpp"
#include <iostream>

int main(){

    try{

        Major major;
        Student *ptr = Factory(StudentType::LazyStudent, "Hristo", 21312);
        major.AddStudent(ptr);
        delete ptr;
        ptr = Factory(StudentType::MotivatedStudent, "Nikoleta", 44444);
        major.AddStudent(ptr);
        delete ptr;
        ptr = Factory(StudentType::LazyStudent, "Andrey", 11111);
        major.AddStudent(ptr);
        delete ptr;
        ptr = Factory(StudentType::MotivatedStudent, "Bogdan", 33333);
        major.AddStudent(ptr);
        delete ptr;

        std::cout << major.TakeExam() << '\n';
        std::cout << std::boolalpha << major.IsAdequateMajor() << '\n';

        for(size_t i = 0; i < major.Size(); ++i)
            std::cout << major[i] -> GetName() << ' ' << major[i] -> HoursSpentPerDayStudying() << '\n';

    }
    catch(std::bad_alloc&){
        std::cerr << "Bad alloc\n";
    }
    catch(std::invalid_argument const &ex){
        std::cerr << ex.what() << '\n';
    }
    catch(std::out_of_range const &ex){
        std::cerr << ex.what() << '\n';
    }

    return 0;

}