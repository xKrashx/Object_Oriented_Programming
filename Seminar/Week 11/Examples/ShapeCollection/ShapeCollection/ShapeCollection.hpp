#ifndef __SHAPE_COLLECTION_
#define __SHAPE_COLLECTION_

#include "../Shapes/Shape.hpp"

class ShapeCollection{

public:
	ShapeCollection();
	ShapeCollection(ShapeCollection const &);
	ShapeCollection(ShapeCollection &&) noexcept;
	ShapeCollection &operator =(ShapeCollection const &);
	ShapeCollection &operator =(ShapeCollection &&) noexcept;
	~ShapeCollection() noexcept;

	void AddShape(Shape * const shape);

	Shape *&operator [](size_t index);
	Shape * const operator [](size_t index) const;

	size_t Size() const;
	size_t Capacity() const;
	bool Empty() const;

private:
	void Resize();
	void Copy(ShapeCollection const &other);
	void Move(ShapeCollection &&other) noexcept;
	void Free() noexcept;

private:
	size_t m_Size = 0, m_Capacity = 0;
	Shape **m_Shapes = nullptr;

};

#endif