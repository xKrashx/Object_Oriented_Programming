<h1>Изключения. Приятелски класове и функции. Mutable полета. Static полета и функции.</h1>

<h3>Изключения</h3>

Ключовата дума `throw` прекратява изпълнението на текущата функция/метод и започва процеса по разгъване на стека. Докато прави така нареченият *"Stack unwinding"* програмата извиква деструкторите на всички обекти в стековата рамка на функцията, в която се намира. Този процес продължава, докато грешката не бъде хваната или докато не терминира main функцията, с което и програмата.

```c++
int main()
{
    throw 20; // terminate called after throwing an instance of 'int'
}
```

**!!!Важно!!!**

1. При разгъване на стековата рамка може да се пренася само по 1 грешка в даден момент от време. Ако станат повече от 1 програмата директно се терминира, дори и обработваме грешките, някъде по-надолу в стека.

2. Никога не хвърляме грешка в деструктора на някой клас!!!
    - Хвърляйки грешка в деструктора на някой обект може да се появи следната ситуация:
        main -> f -> g.
        В f сме създали обект от тип T и той хвърля грешка от тип int в деструктора си.
        g хвърля грешка от тип char.
        В процеса на разгъване на стека g бива терминирана, след което и f, но f извиква деструктора на обекта от тип T, с което стават две различни грешки, които трябва да бъдат предадени и обработени.
        Програмата обаче не може да се ориентира, коя грешка е по-важна, с което прекратява нашата програма.

3. Ако хвърлим грешка в конструктора, на някой обект, то този обект няма да бъде създаден изобщо, но е хубаво преди да я хвърлим да освободим динамичната памет, която сме заделили.

<h3>try & catch</h3>

- В try блока пишем код който потенциално може да хвърли грешка.
- В catch блока хващаме грешките хвърлени от try блока и ги обработваме.

Можем да слагаме няколко catch блока един след друг с различни параметри.
Като накрая можем да сложим блокът `catch(...)`, който хваща всички останали изключения.

```c++
#include <iostream>

int main(){
    try
    {
        throw 20;
    }
    catch(int e)
    {
        std::cout << "Exception occurred exception code: " << e << '\n';
    }
    catch(char const *c)
    {
        std::cout << "Exception occurred: " << e << '\n';
    }
	catch(...)
	{
        std::cout << "Exception occurred!\n";
	}
}
```

<h3>Видове грешки</h3>

Стандартната библиотека за грешки `exception`. В нея има различни видове грешки, които можете да разгледате [тук](https://en.cppreference.com/w/cpp/error/exception).

```c++
#include <iostream>
#include <exception>

int main()
{
    try
    {
        throw std::invalid_argument("Exception occurred");
    }
    catch(const std::invalid_argument &e)
    {
        std::cerr << e.what() << '\n';
    }
}
```

<h3>Приятелски класове и приятелски функции</h3>

Декларират се с на запазената дума **friend** пред прототипа на функцията.  
Даденият friend-клас/функция има достъп до всички компоненти на класа. 
Т.е. всички членове на класа са public за friend-класовете/функциите приятели.

<h5>Пример за приятелски функции:</h5>

```c++
class Complex
{
private:
	double real;
	double im;
public:
	friend double getModulos(const Complex& other);
	.
	.
	.
}

double getModulos(const Complex& other)
{
	return sqrt((other.real – other.real) * (other.real – other.real) + (other.im – other.im ) * (other.im – other.im));
}
```

<h3>Mutable</h3>

Ключовата дума mutable се среща само в С++. Той позволява на поле на обект да превъзмогва константността на обекта. Така mutable поле на const обект не е const и може да бъде изменян.

```c++
struct Test
{
private:
	mutable int n;
public:
	void f() const
	{
		n++;
	}
};

int main()
{
	const Test t;
	t.f();
}
```

<h3>Ключова дума static</h3>

Тази ключова дума ни позволява да създадем полета и методи, които не са пряко обвързани към конкретен обект, ами към самият клас. Това означава, че можем да ги достъпваме както през обекти, така и през името на класа.

<h5>Пример за декларация на една променлива</h5>

```c++
class X { static int n; }; // декларация (използва 'static')
int X::n = 1;              // дефиниция (не използва 'static')
```

**Забележка:** статично поле може да бъде само дефинирано в header файл, но трябва да бъде инициализирано в *някой* cpp файл.

<h5>Пример за различни видове променливи</h5>

```c++
struct Foo;        // декларация, незавършен тип
struct S
{
   static int a[]; // декларация, незавършен тип
   static Foo x;   // декларация, незавършен тип
   static S s;     // декларация, незавършен тип (вътре в собствената си дефиниция)
};

int S::a[10];   // дефиниция, завършен тип
struct Foo {};  // дефиниция, завършен тип
Foo S::x;       // дефиниция, завършен тип
S S::s;         // дефиниция, завършен тип
```

Забележете, че тук можем да създадем променлива, от самия клас вътре в него, вместо указател към обекта. Това е възможно тъй като статичните променливи не са обвързани към конкретна инстанция, а към самият клас.

```c++
struct X
{
    static void f(); // декларация
    static int n;    // декларация
};

X g() { return X(); } // Някаква функция, която връща обект от тип X.

void f()
{
    X::f();  // X::f е валидно име на статичен метод.
    g().f(); // g().f() е израз за достъпване на статичен метод.
}

int X::n = 7; // дефиниция

void X::f() // дефиниция
{
    n = 1; // X::n може да се достъпи просто като n в този scope.
}
```

<h3>Singleton pattern</h3>

Това е принцип за дизайн на клас, който е необходимо да се инстанцира само веднъж. Такива класове са примерно Interface-ите (Input/Output). Идеята е да не се хаби памет да се правят излишни обекти за една и съща цел.

<h5>Пример за реализация с указател към обекта:</h5>

```c++
#include <iostream>

class Singleton
{
public:
	Singleton(Singleton const &) = delete;
	Singleton(Singleton &&) = delete;

	Singleton &operator =(Singleton const &) = delete;
	Singleton &operator =(Singleton &&) = delete;
	
	static Singleton *GetInstance();

	void Print() const;
private:
	Singleton() = default;
	static Singleton *instancePtr;
};

Singleton *Singleton::instancePtr = nullptr;

Singleton *Singleton::GetInstance()
{
	if(!instancePtr)
		instancePtr = new Singleton();
	return instancePtr;
}

void Singleton::Print() const
{
	std::cout << "I'm a singleton\n";
}

int main(){

    Singleton *instance = Singleton::GetInstance();
    Singleton *instance2 = Singleton::GetInstance();

    std::cout << std::boolalpha << (instance == instance2) << '\n';
    instance -> Print();
    delete[] instance;
    return 0;

}
```

<h5>Пример за реализация с референция към обекта:</h5>

```c++
class Singleton
{
public:
	Singleton(Singleton const &) = delete;
	Singleton(Singleton &&) = delete;

	Singleton &operator =(Singleton const &) = delete;
	Singleton &operator =(Singleton &&) = delete;
	
	static Singleton &GetInstance();

	void Print() const;
private:
	Singleton() = default;
};

Singleton &Singleton::GetInstance()
{
	static Singleton instance;
	return instance;
}

void Singleton::Print() const
{
	std::cout << "I'm a singleton\n";
}
```

**Забележка:** Премахваме конструкторите за копиране и местене, и съответните им операторите за присвояване, защото ние имаме само 1 инстанция на този клас в цялата програма. Няма смисъл да имплементираме тези неща, тъй като те няма да се използват.

<h3>Примерни задачи</h3>

1. Swaps counter
    - Брои колко размени на елементи са се случили в програмата

2. Self counting
    - Клас, който да брои, колко инстанции са направени от него и колко от тях са все още живи.

3. Pair
	- Клас, който съдържа 2 аргумента (first, second).