#ifndef __FIGURE_COLLECTION_HPP
#define __FIGURE_COLLECTION_HPP

#include "Figure.hpp"
#include "Circle.hpp"
#include "Triangle.hpp"
#include "Quadrilateral.hpp"
#include "Trapezoid.hpp"
#include "Parallelogram.hpp"
#include "Rhombus.hpp"
#include "Rectangle.hpp"
#include "Square.hpp"

class FigureCollection
{
    public:
        FigureCollection();
        FigureCollection(const FigureCollection& other);
        FigureCollection(FigureCollection&& other);

        ~FigureCollection();

        FigureCollection& operator=(const FigureCollection& other);
        FigureCollection& operator=(FigureCollection&& other);

        Figure*& operator[](unsigned int index);
	    const Figure* operator[](unsigned int index) const;

        void Add(const Circle& circle);
        void Add(const Triangle& triangle);
        void Add(const Quadrilateral& quadrilateral);
        void Add(const Trapezoid& trapezoid);
        void Add(const Parallelogram& parallelogram);
        void Add(const Rhombus& rhombus);
        void Add(const Rectangle& rectangle);
        void Add(const Square& square);

        void Add(Figure const * const figure);

        void Remove(unsigned int index);

        unsigned int GetSize() const;

        bool Empty() const;

        void Print(unsigned int index) const;
        void Print() const;

    private:
        static const unsigned short INITIAL_CAPACITY = 2;
        static const unsigned short INCREASE_STEP = 2;

        Figure** array;
        unsigned int size;
        unsigned int capacity;

        void Copy(const FigureCollection& other);
        void Deallocate();
        void Move(FigureCollection&& other);

        bool Resize();
};

#endif
