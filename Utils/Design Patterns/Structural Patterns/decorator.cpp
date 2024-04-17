// !!! C++17+ only !!!

#include <type_traits>
#include <iostream>
#include <tuple>

class Shape{
public:
	virtual void Display() = 0;
	virtual ~Shape() = default;
};

template <template <typename> class... T>
class Line : public Shape, public T<Line<>>...{
public:
	void Display() override{
		std::apply([](auto &&...x)
				   { (x.Display(), ...); },
				   std::forward_as_tuple(T<Line<>>()...));
		std::cout << "line\n";
	}
};

template <template <typename> class... T>
class Text : public Shape, public T<Text<>>...{
public:
	void Display() override{
		std::apply([](auto &&...x)
				   { (x.Display(), ...); },
				   std::forward_as_tuple(T<Text<>>()...));
		std::cout << "text\n";
	}
};

template <typename T>
class ColorDecorator{
public:
	void Display(){
		if constexpr (std::is_constructible_v<Line<> *, T *>){
			std::cout << "red ";
		}
		else{
			std::cout << "black ";
		}
	}
};

template <typename T>
class WeightDecorator{
public:
	void Display(){
		if constexpr (std::is_constructible_v<Line<> *, T *>){
			std::cout << "bold ";
		}
		else{
			std::cout << "normal ";
		}
	}
};

int main(){
	Line line1;
	Line<ColorDecorator> line2;
	Line<WeightDecorator> line3;
	Line<ColorDecorator, WeightDecorator> line4;

	line1.Display(); // line
	line2.Display(); // red line
	line3.Display(); // bold line
	line4.Display(); // red bold line

	Text text1;
	Text<ColorDecorator> text2;
	Text<WeightDecorator> text3;
	Text<ColorDecorator, WeightDecorator> text4;

	text1.Display(); // text
	text2.Display(); // black text
	text3.Display(); // normal text
	text4.Display(); // black normal text

	return 0;
}
