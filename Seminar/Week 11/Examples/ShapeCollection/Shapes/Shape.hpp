#ifndef __SHAPE_H_
#define __SHAPE_H_

#include <cstddef>

class Shape{   // Abstract class - no instances of Shape are allowed!

public:
	Shape(size_t const pointsCount);

	Shape(Shape const &other);
	Shape(Shape &&other) noexcept;

	Shape &operator =(Shape const &other);
	Shape &operator =(Shape &&other) noexcept;

	virtual ~Shape() noexcept; //!!!!!!

public:
	void SetPoint(size_t pointIndex, int x, int y);

	virtual double GetArea() const = 0; //pure virtual
	virtual double GetPer()  const = 0; // pure virtual
	virtual bool IsPointIn(int x, int y) const = 0;
	virtual Shape *Clone() const = 0;

protected:
	struct Point{

		Point() = default;
		Point(int x, int y): x(x), y(y){}

		double GetDistance(Point const other) const;

		int x = 0, y = 0;

	};

	Point const GetPointAtIndex(size_t index) const;

private:
	void Copy(Shape const &other);
	void Move(Shape &&other) noexcept;
	void Free() noexcept;

private:
	Point *m_Points = nullptr;
	size_t m_NumberOfPoints = 0;

};

#endif