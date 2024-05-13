#ifndef __FIGURE_HPP
#define __FIGURE_HPP

#include <iostream>

class Figure
{
    public:
        virtual ~Figure() = default;

        virtual Figure* Clone() const = 0;

        virtual double GetPerimeter() const { return 0; }
        virtual double GetArea() const = 0;
        
        virtual void Print(std::ostream& os = std::cout) const {}
};

#endif
