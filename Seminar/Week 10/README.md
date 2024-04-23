<h1>Статично и динамично свързване. Виртуални функции. Виртуални таблици. Ключови думи override и final. Полиморфизъм. Чисто виртуални функции. Абстрактни класове.</h1>

<h3>Статично vs динамично свързване</h3>

Пример за **статично** свързване:

```c++
#include <iostream>

struct A
{ 
    void f() const 
    {
	    std::cout << "A::f()\n";
    }	
};

struct B : public A
{
    void f() const 
    {
	    std::cout << "B::f()\n";
    }	
};

int main()
{
	B* bPtr = new B();

	A* aPtr = bPtr;
	
	bPtr->f(); // B::f()
	aPtr->f(); // A::f()
	
	delete bPtr;
}
```

- **Статично** свързване - изборът на функцията, която трябва да се изпълни става **по време на компилация**.
- **Динамично** свързване – изборът на функцията, която трябва да се изпълни става **по време на изпълнение на програмата**.

```c++
#include <iostream>

struct A
{
    virtual void f() const 
    {
	    std::cout << "A::f()\n";
    }	
};

struct B : public A
{
    void f() const 
    {
       std::cout << "B::f()\n";
    }	
};

struct C : public A
{
    void f() const 
    {
       std::cout << "C::f()\n";
    }	
};

int main()
{
	A* ptrs[3];
	A obj1;
	B obj2;
	C obj3;
	
	ptrs[0] = &obj1;
	ptrs[1] = &obj2;
	ptrs[2] = &obj3;
	
	ptrs[0]->f(); // A::f()
	ptrs[1]->f(); // B::f()
	ptrs[2]->f(); // C::f()
}
```

<h3>Виртуални фунцкии и виртуални таблици</h3>

Виртуални таблици - таблица с указатели към функции. 

```c++
struct A
{
	virtual int f()
	{
		return 1;
	}
	virtual int g()
	{
		return 1;
	}
};

struct B : public A
{
	int f() override
	{
		return 2;
	}
};

struct C : public B
{
	int f() override
	{
		return 3;
	} 
	int g() override
	{
		return 3;
	}
};
```

<h3>override и final</h3>

- override указва, че дадена функция презаписва функция от базовия клас. Ако в базовия клас няма такава функция, то кодът няма да се компилира.

- final указва, че дадена функция не може да се презависва надолу по йерархията или че даден клас не може да се наследява.

<h3>Полиморфизъм</h3>

Едни и същи действия се реализират по различен начин в
зависимост от обектите, върху които се прилагат.

- Действията се наричат полиморфни.
- Реализира се чрез виртуални функции.
- Класовете, върху които ще се прилага, трябва да имат общ родител или прародител, т.е. да са наследници на един и същ клас.
- В класа се дефинира виртуален метод, съответстващ на полиморфното действие.
- Всеки клас предефинира или не виртуалния метод.
- Активирането става чрез указател към базов клас, на който може да се присвоят адресите на обекти на който и да е от базовите класове от йерархията

**Важно!** При полиморфна йерархия ще изтриваме обектите чрез указатели от базовия клас. За да се извикват правилните деструкори задължително **деструкторът на базовият клас** трябва е деклариран като виртуален!

```c++
#include<iostream>

struct Animal
{
	virtual void sayHello() const
	{
		std::cout << "Hello, I am a random animal" << std::endl;
	}

	virtual ~Animal(){} //!!!
};
struct Dog : public Animal
{
	void sayHello() const override
	{
		std::cout << "Hello, I am a dog!" << std::endl;
	}
};

struct Cat : public Animal
{
	void sayHello() const override
	{
		std::cout << "Hello, I am a cat!" << std::endl;
	}
};

struct Mouse : public Animal
{
};

int main()
{
	Animal** animals = new Animal*[3];

	animals[0] = new Dog();
	animals[1] = new Cat();
	animals[2] = new Mouse();


	//from base-class pointer
	animals[0]->sayHello(); // Hello, I am a dog!
	animals[1]->sayHello(); // Hello, I am a cat!
	animals[2]->sayHello(); // Hello, I am a random animal!

	delete animals[0], animals[1], animals[2];
	delete[] animals;
}
```

<h3>Абстрактен клас</h3>

- Чисто виртуална функция (**pure virtual function**) - вруална функция без тяло.
- Клас е **абстрактен**, ако в него има поне една **чисто виртуална функция**.

Тогава класът е предназначен единствено за наследяване и няма да може да създаваме обекти от него.
Така във всеки наследник ще трябва да се разпише имплементация на функцията. Ако някой наследник няма собствена имплементация, то и той става абстрактен клас.

```c++
#include<iostream>

struct Animal
{
	virtual void sayHello() const = 0;


	virtual ~Animal(){} //!!!
};
struct Dog : public Animal
{
	void sayHello() const override
	{
		std::cout << "Hello, I am a dog!" << std::endl;
	}
};

struct Cat : public Animal
{
	void sayHello() const override
	{
		std::cout << "Hello, I am a cat!" << std::endl;
	}
};

struct Mouse : public Animal
{
	void sayHello() const override
	{
		std::cout << "Hello, I am a mouse!" << std::endl;
	}
};

struct PrehistoricAnimal : public Animal
{};

int main()
{
	// Animal* pa1 = new Animal(); No! Animal is an abstract class!
	// Animal* pa2 = new PrehistoricAnimal(); No! PrehistoricAnimal is also an abstract class!

	Animal** animals = new Animal*[3];

	animals[0] = new Dog();
	animals[1] = new Cat();
	animals[2] = new Mouse();


	//from base-class pointer
	animals[0]->sayHello(); // Hello, I am a dog!
	animals[1]->sayHello(); // Hello, I am a cat!
	animals[2]->sayHello(); // Hello, I am a mouse!

	delete animals[0]
	delete animals[1]
	delete animals[2];
	delete[] animals;
}
```

<h3>Диамантен проблем</h3>

При множествено наследяване може да се получи така, че наследяваме един базов клас повече от веднъж. С други думи имаме следната ситуация:

![](https://i.ibb.co/82vjrrY/images.png)

Тогава ще имаме всички данни на базовия клас(PoweredDevice) два пъти, в зависимост от кой родител ги достъпим. Ето и пример за това, което ще се случи при такава структура. Тук конструкторът на `Person` ще се извика два пъти, защото съществуват два такива обекта в нашият `TA` обект.

```c++
#include <iostream>

class Person{
   // Data members of person 
public:
    Person(int x){ std::cout << "Person::Person(int ) called\n"; }
};
 
class Faculty : public Person{
   // data members of Faculty
public:
    Faculty(int x):Person(x){ std::cout<<"Faculty::Faculty(int ) called\n"; }
};
 
class Student : public Person{
   // data members of Student
public:
    Student(int x):Person(x){ std::cout<<"Student::Student(int ) called\n"; }
};
 
class TA : public Faculty, public Student{
public:
    TA(int x):Student(x), Faculty(x){ std::cout<<"TA::TA(int ) called\n"; }
};

int main(){
    TA ta1(30);
}
```

Изходът е:

```
Person::Person(int ) called
Faculty::Faculty(int ) called
Person::Person(int ) called
Student::Student(int ) called
TA::TA(int ) called
```

Желаният ефект обаче, би бил следният:

![](https://i.ibb.co/vBZmnfy/diamondproblem.png)

Да направим, така че данните да се използват само веднъж. От тук идва и името на проблема, тъй като графиката прилича на ромбоид(диамант).

Решението на проблема е с виртуално наследяване. Реализацията ще изглежда така:

```c++
#include <iostream>

class Person{
   // Data members of person 
public:
    Person(int x){ std::cout << "Person::Person(int ) called\n"; }
};
 
class Faculty : virtual public Person{
   // data members of Faculty
public:
    Faculty(int x):Person(x){ std::cout<<"Faculty::Faculty(int ) called\n"; }
};
 
class Student : virtual public Person{
   // data members of Student
public:
    Student(int x):Person(x){ std::cout<<"Student::Student(int ) called\n"; }
};
 
class TA : public Faculty, public Student{
public:
    TA(int x):Student(x), Faculty(x){ std::cout<<"TA::TA(int ) called\n"; }
};

int main(){
    TA ta1(30);
}
```

Изходът е:

```
Person::Person(int ) called
Faculty::Faculty(int ) called
Student::Student(int ) called
TA::TA(int ) called
```

Крайният резултат, който успяхме да постигнем:

![](https://i.ibb.co/K031yVB/two-diagrams-showing-how-virtual-inheritance-helps.webp)

<h3>Домашно</h3>

**Задача 1:**
Съществуват различни видове броячи - някои могат само да увеличават
бройката, която пазят, други могат и да я намалят, а трети имат
ограничение до колко могат да отброяват.

**Клас *Counter***

Най-простият брояч - само нагоре, без ограничение.

- Конструктор без параметри: началната стойност е 0 и стъпката на брояча
е 1
- Конструктор с 1 параметър int initial: началната стойност е initial,
а стъпката е 1
- Конструктор с 2 параметъра int initial, unsigned step: началната
стойност е initial, а стъпката e step
- increment(): увеличава текущата стойност със стъпката на брояча
- getTotal(): връща int - текущата отброена стойност
- getStep(): връща unsigned - стъпката на брояча (не трябва да може да
бъде променяна)

**Клас *TwowayCounter***

Брояч, който може и да намалява отброяваната стойност.
Освен всичко изброено в Counter, съдържа и:

- decrement(): намалява текущата стойност със стъпката на брояча

**Клас *LimitedCounter***

Брояч, който отброява само до дадена максимална стойност.

- Конструктор с 1 параметър int max: максималната стойност е max,
началната е 0, а стъпката е 1
- Конструктор с 2 параметъра int max, int initial: максималната
стойност е max, началната е initial, а стъпката е 1
- Конструктор с 3 параметъра int max, int initial, unsigned step:
максималната стойност е max, началната е initial, а стъпката е step
- increment(): увеличава текущата стойност със стъпката на брояча само
ако няма да надмине максималната
- getMax(): връща int - максималната стойност на брояча
- getTotal(): същия като този на Counter
- getStep(): същия като този на Counter

**Клас *LimitedTwowayCounter***

Той е и LimitedCounter и TwowayCounter едновременно: може да отброява
нагоре до определена максимална стойност и надолу до определена
минимална стойност.

- Конструктор с 2 параметъра int min, int max: минималната стойност е
min, максималната стойност е max, началната е 0, а стъпката е 1
- Конструктор с 3 параметъра int min, int max, int initial:
минималната стойност е min, максималната стойност е max, началната е
initial, а стъпката е 1
- Конструктор с 4 параметъра int min, int max, int initial,
unsigned step: минималната стойност е min, максималната стойност е
max, началната е initial, а стъпката е step
- increment(): същия като на LimitedCounter
- decrement(): намаля текущата стойност със стъпката на брояча само
ако няма да стане по-ниска от минималната
- getMin(): връща минималната стойност на брояча
- getMax(): същия като този на LimitedCounter
- getTotal(): същия като този на Counter
- getStep(): същия като този на Counter

**Клас *Semaphore***

Най-простия бинарен семафор - това е LimitedTwowayCounter, който има
минимална стойност 0, максимална стойност 1 и стъпка 1. Използва се от
процесите в операционнитe системи за синхронизационни цели.

- Конструктор без параметри - началната стойност на брояча е 0.
- Конструктор с един параметър bool - при true началната стойност на
брояча е 1, а при false е 0.
- isAvailable(): връща bool, показващ дали стойността на брояча е над
0
- wait() - прави същото като decrement() на LimitedTwowayCounter
- signal() - прави същото като increment() на LimitedTwowayCounter

**Задача 2:**
Направете система, която да дава възможност за комуникация чрез заявки
между разработчици и техния ръководител на екип. Имплементирайте
функционалности за изпращане на заявка за напускане и заявка за
повишаване на заплатата.

**Клас *Developer***

Разработчик.

- Име (символен низ);
- Заплата (double);
- Ръководител на екип (указател към обект от клас TeamLead);
- Конструктор с 1 параметър const string& name: името е name,
заплатата е 0, указателят сочи към nullptr;
- getName(): връща string - текущата стойност на името;
- getSalary(): връща double - текущата стойност на заплатата;
- getTeamLead(): връща TeamLead * - текущата стойност на указателя към
ръководителя;
- setInitialSalary(double amount): присвоява за заплатата подадената
сума amount, само ако нейната текуща стойност е 0; (Ако не е да не
присвоява стойност)
- void sendLeavingRequest();: подава към ръководителя
LeavingRequest с името на разработчика;
- void sendPromotionRequest(double amount);: подава към
ръководителя PromotionRequest с името на разработчика и
количеството на заплатата, подадено в аргумента на функцията;

**Клас *TeamLead***

Ръководител на екип.
Освен всичко изброено в Developer, съхранява и:

- вектор с указатели към обекти от клас Developer; (ръководителят не е
част от екипа)
- заявки за напускане (LeavingRequest);
- заявки за повишаване на заплатата (PromotionRequest);
- Конструктор с 2 параметъра const string& name, double salary:
името е name, заплатата е salary, a указателят към ръководителят на
екипа сочи към текущият обект;
- getTeam(): връща `Vector<Developer*>` - текущият вектор, който
представлява екипа;
- void addDeveloperToTeam(Developer * developer, double salary);:
добавя разработчик към екипа и задава заплатата му да бъде със
стойност salary. Трябва за разработчикът да се промени, че вече има
ръководител на екипа; (Възможно е да има разработчици в екипа с
еднакви имена. Съобразете дали developer не сочи към nullptr.)
- void removeDeveloperFromTeam(const string& name);: премахва
разработчик от екипа по подадено име name. (Ако не се намери търсения
разработчик, не последва действие. Ако намери разработчици с еднакво
име премахва последния.)
- void increaseTeamSalariesBy(double amount);: повишава заплатите
на разработчиците в екипа със стойност amount;
- void decreaseTeamSalariesBy(double amount);: понижава заплатите
на разработчиците в екипа със стойност amount;
- void addLeavingRequest(const LeavingRequest& leavingRequest);:
добавя на съхранение заявка за напускане;
- void addPromotionRequest(const PromotionRequest&
promotionRequest);: добавя на съхранение заявка за повишаване на
заплатата;
- void fulfillLeavingRequests();: изпълнява всички съхранени заявки
за напускане, като премахва от екипа изпратилите заявките, променя
техният ръководител (TeamLead * да сочи към nullptr) и изчиства
всички изпълнени заявки;
- void fulfillPromotionRequests();: изпълнява всички съхранени
заявки за повишаване на заплатата, повишава заплатата на изпратилите
заявките и изчиства всички изпълнени заявки;

**Клас *Request***

Заявка.

- Съобщение (символен низ)
- Изпращач (символен низ) (името на този, който я изпраща)
- Брояч (цяло число) - започва от 0 и се увеличава с всеки създаден обект
от тип Request или негови наследници;
- ID (цяло число) - уникален идентификатор, който има стойността на
брояча в момента на създаването му (ако сме създали два обекта от тип
Request или негови наследници, първият ще има ID със стойност 1, а
вторият ID със стойност 2);
- Конструктор с 2 параметъра const string& message, const string&
sender: съобщението е message, изпращачът е sender, броячът се
увеличава с 1, ID приема стойността на брояча;
- getMessage() : връща string - текущата стойност на съобщението;
- getSender(): връща string - текущата стойност на изпращача;
- getCount(): връща int - текущата стойност на брояча;
- getID(): връща int - текущата стойност на ID;

**Клас *LeavingRequest***

Заявка за напускане.
Освен всичко изброено в Request:

- Конструктор с 1 параметъра const string& sender: съобщението е "I
want to leave!", изпращачът е sender, броячът се увеличава с 1, ID
приема стойността на брояча;

**Клас *PromotionRequest***

Заявка за повишаване на заплатата.
Освен всичко изброено в Request:

- Kоличество (double) - количество, с което да се увеличи заплатата;
- Конструктор с 2 параметъра const string& sender, double amount:
съобщението е "I want a raise!", изпращачът е sender, количеството
е amount , броячът се увеличава с 1, ID приема стойността на брояча;
- getAmount(): връща double - текущата стойност на количеството;
При решението на задачата и работатата с указатели НЕ трябва да се създават копия