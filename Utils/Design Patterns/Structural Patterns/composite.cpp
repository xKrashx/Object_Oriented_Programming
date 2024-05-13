#include <algorithm>
#include <iostream>
#include <vector>
#include <new>

class Shape {
public:
	virtual void Display() = 0;
	virtual void Append(Shape *) {}
	virtual void Remove(Shape *) {}

	virtual Shape *Child(size_t) { return nullptr; }

	virtual ~Shape() = default;
};

class Line : public Shape {
public:
  	void Display() override { std::cout << "Line\n"; }
};

class Rect : public Shape {
public:
  	void Display() override { std::cout << "Rectangle\n"; }
};

class Picture : public Shape {
public:
  	void Display() override {
		for (Shape *&shape : m_Shapes) {
			shape->Display();
		}
	}

	void Append(Shape *shape) override {
		m_Shapes.emplace_back(shape);
	}

	void Remove(Shape *shape) override {
		for(std::vector<Shape *>::iterator iter = m_Shapes.begin(); iter != m_Shapes.end(); ++iter)
			if(*iter == shape)
				m_Shapes.erase(iter--);
	}

  	Shape *Child(size_t n) override { return m_Shapes[n]; }

private:
	std::vector<Shape *> m_Shapes;
};

int main() {
	Picture picture;
	Line line;
	Rect rect;

	picture.Append(&line);
	picture.Append(&rect);
	picture.Display();  // 12

	picture.Remove(&line);
	picture.Display();  // 2

	return 0;
}
