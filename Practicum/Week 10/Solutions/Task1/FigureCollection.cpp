#include "FigureCollection.hpp"

#include <new>
#include <stdexcept>

FigureCollection::FigureCollection() : array(nullptr)
{
    this->array = new Figure*[INITIAL_CAPACITY];
    this->size = 0;
    this->capacity = INITIAL_CAPACITY;
}

FigureCollection::FigureCollection(const FigureCollection& other) : array(nullptr)
{
    this->Copy(other);
}

FigureCollection::FigureCollection(FigureCollection&& other) : array(nullptr)
{
    this->Move(std::move(other));
}

FigureCollection::~FigureCollection()
{
    this->Deallocate();
}

FigureCollection& FigureCollection::operator=(const FigureCollection& other)
{
    if(this != &other)
    {
        this->Deallocate();
        this->Copy(other);
    }
    return *this;
}

FigureCollection& FigureCollection::operator=(FigureCollection&& other)
{
    if(this != &other)
    {
        this->Deallocate();
        this->Move(std::move(other));
    }
    return *this;
}

Figure*& FigureCollection::operator[](unsigned int index)
{
    if(index >= this->size)
    {
        std::invalid_argument("Invalid index!");
    }

    return this->array[index];
}

const Figure* FigureCollection::operator[](unsigned int index) const
{
    if(index >= this->size)
    {
        std::invalid_argument("Invalid index!");
    }

    return this->array[index];
}

void FigureCollection::Add(const Circle& circle)
{
    if(this->size + 1 > this->capacity)
    {
        bool resized = Resize();
        if(!resized) return;
    }

    this->array[this->size] = new Circle(circle);
    this->size++;
}

void FigureCollection::Add(const Triangle& triangle)
{
    if(this->size + 1 > this->capacity)
    {
        bool resized = Resize();
        if(!resized) return;
    }

    this->array[this->size] = new Triangle(triangle);
    this->size++;
}

void FigureCollection::Add(const Quadrilateral& quadrilateral)
{
    if(this->size + 1 > this->capacity)
    {
        bool resized = Resize();
        if(!resized) return;
    }

    this->array[this->size] = new Quadrilateral(quadrilateral);
    this->size++;
}

void FigureCollection::Add(const Trapezoid& trapezoid)
{
    if(this->size + 1 > this->capacity)
    {
        bool resized = Resize();
        if(!resized) return;
    }

    this->array[this->size] = new Trapezoid(trapezoid);
    this->size++;
}

void FigureCollection::Add(const Parallelogram& parallelogram)
{
    if(this->size + 1 > this->capacity)
    {
        bool resized = Resize();
        if(!resized) return;
    }

    this->array[this->size] = new Parallelogram(parallelogram);
    this->size++;
}

void FigureCollection::Add(const Rhombus& rhombus)
{
    if(this->size + 1 > this->capacity)
    {
        bool resized = Resize();
        if(!resized) return;
    }

    this->array[this->size] = new Rhombus(rhombus);
    this->size++;
}

void FigureCollection::Add(const Rectangle& rectangle)
{
    if(this->size + 1 > this->capacity)
    {
        bool resized = Resize();
        if(!resized) return;
    }

    this->array[this->size] = new Rectangle(rectangle);
    this->size++;
}

void FigureCollection::Add(const Square& square)
{
    if(this->size + 1 > this->capacity)
    {
        bool resized = Resize();
        if(!resized) return;
    }

    this->array[this->size] = new Square(square);
    this->size++;
}

void FigureCollection::Add(Figure const * const figure)
{
	if(this->size + 1 > this->capacity)
    {
        bool resized = Resize();
        if(!resized) return;
    }

    this->array[this->size] = figure->Clone();
    this->size++;
}

void FigureCollection::Remove(unsigned int index)
{
    if(index >= this->size)
    {
        std::invalid_argument("Invalid index!");
    }

    Figure* save = this->array[index];

    for(int j = index; j < this->size - 1; j++)
    {
        this->array[j] = this->array[j + 1];
    }
    this->size--;

    delete save;
}

unsigned int FigureCollection::GetSize() const
{
    return this->size;
}

bool FigureCollection::Empty() const
{
	return this->size == 0;
}

void FigureCollection::Print(unsigned int index) const
{
    if(index >= this->size)
    {
        std::invalid_argument("Invalid index!");
    }
    this->array[index]->Print();
    std::cout << std::endl;
}

void FigureCollection::Print() const
{
    for(unsigned int i = 0; i < this->size; i++)
    {
        this->array[i]->Print();
        std::cout << std::endl << "----------------------------------" << std::endl;
    }
}

void FigureCollection::Copy(const FigureCollection& other)
{
    this->array = new Figure*[other.capacity];
    
    for(unsigned int i = 0; i < other.size; i++)
    {
        this->array[i] = other.array[i]->Clone();
    }

    this->size = other.size;
    this->capacity = other.capacity;
}

void FigureCollection::Deallocate()
{
    for(unsigned int i = 0; i < this->size; i++)
    {
        delete this->array[i];
    }
    delete[] this->array;
    this->array = nullptr;
}

void FigureCollection::Move(FigureCollection&& other)
{
    this->array = other.array;
    other.array = nullptr;

    this->size = other.size;
    other.size = 0;

    this->capacity = other.capacity;
    other.capacity = 0;
}

bool FigureCollection::Resize()
{
    Figure** newArray = new(std::nothrow) Figure*[this->capacity * INCREASE_STEP];
    if(!newArray)
    {
        std::cout << "Memory problem!" << std::endl;
        return false;
    }

    for(unsigned i = 0; i < this->size; i++)
    {
        newArray[i] = this->array[i]; 
    }

    delete[] this->array;
    
    this->array = newArray;
    newArray = nullptr;

    this->capacity *= INCREASE_STEP;

    return true;
}
