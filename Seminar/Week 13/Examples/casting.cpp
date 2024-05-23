#include<iostream>

void print(char* str){
	std::cout << str << '\n';
}

class Base { virtual void dummy() {} };
class Derived : public Base { int a; };

int main() {

	char const *myStr = "ConstCast?";

	//print(myStr); :(
	print(const_cast<char *>(myStr));
	//const_cast can be used to remove the constance 

	char c = 10;

	int *p = (int *)&c; // unsafe
	*p = 15000; //run - time error stack around c is corrupted 

	int *p1 = static_cast<int*>(c); //invalid type converse COMPILATION time error 
	// static_cast similar to C - style casts
	int x = 10, y = 3;

	double res = static_cast<double>(x) / y;

	try{

		Base *pba = new Derived;
		Base *pbb = new Base;
		Derived *pd;

		pd = dynamic_cast<Derived *>(pba); // pba is Derived *, so conversion is fine.
		if(!pd) std::cout << "Null pointer on first type-cast.\n";

		pd = dynamic_cast<Derived *>(pbb); // pbb is Base *, can't convert it to Derived *!
		if(!pd) std::cout << "Null pointer on second type-cast.\n";

	}
    catch(std::exception const &e){
		std::cout << "Exception: " << e.what() << '\n'; 
	}

	// dynamic_cast can be used for both upcasts and downcasts
	// when pointers used -> NULL 
	// when references -> exception

	class A { /* ... */ };
	class B { /* ... */ };
	A *a = new A;
	B *b = reinterpret_cast<B *>(a);

	// reinterpret_cast all to all , casting bits , so can be very unsafe
	// usage : casting between pointer to functions

    return 0;

}