#ifndef __QUADRILATERAL_HPP
#define __QUADRILATERAL_HPP

#include "Point.hpp"
#include "Figure.hpp"

class Quadrilateral : public Figure
{
    public:
        Quadrilateral(const Point& p1, const Point& p2, const Point& p3, const Point& p4);

        Quadrilateral* Clone() const override; // Втори начин: Figure* Clone() const override;

        double GetPerimeter() const override;
        double GetArea() const override;

        void Print(std::ostream& os = std::cout) const override;

    protected:
        // Добре е член-данни да не са protected, защото частично се нарушава капсулацията,
        // затова използваме функции за достъп до член-данните.
        const Point& GetP1() const;
        const Point& GetP2() const;
        const Point& GetP3() const;
        const Point& GetP4() const;
        
        // Може да е със спецификатор на достъп protected, защото е константа.
        static const double EPS; 

    private:
        Point p1, p2, p3, p4;
};

#endif
