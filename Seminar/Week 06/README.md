<h1>Копиращ конструктор и оператор=. Голямата четворка. Семантики за преместване. Голямата шестица. Ключови думи default, delete и explicit. Return value optimization.</h1>

<h3>Копиращ конструктор</h3>

Конструктор с параметър от тип `const <името-на-класа>&`. Целта му е да създаде нов обект със стойности на полетата същите като тези на другия подаден като аргумент. Ако бъде пропуснат ще се генерира автоматично такъв от компилатора, който прави т. нар. `shallow copy`.

<h5>Синтаксис</h5>

```c++
class Test
{
public:
    Test(const Test& other)
    {
        i = other.i;
        d = other.d;
    }    
private:
    int i;
    double d;
};
```

<h3>Кога се извиква</h3>

- При създаване на нови обекти от други, вече съществуващи, обекти.
- Неявно при създаване на нов локален обект за дадена функция.
- При връщане на копие на обект от функция

```c++ 
void doSomethingWithTest(Test t) // Извиква копиращ конструктор
{
}

Test doSomethingElseWithTest(Test t) // Извиква копиращ конструктор
{
    return t; // Извиква копиращ конструктор
}

int main()
{
    Test t, t1(t), t2 = t1; // t1 и t2 извикват копиращ конструктор
    return 0;
}
```

<h3>Оператор =</h3>

Дясно асоциативен оператор за присвояване на стойност на вече съществуващ обект. След извършване на промените по текущия обект, той бива върнат като резултат. Това позволява наслагване на равенство между няколко обекта.

<h3>Синтаксис</h3>

```c++
class Test
{
private:
    int i;
    double d;
public:
    // стандартна имплементация на operator= 
    Test& operator=(const Test& rhs)
    {
        if(this != &rhs)
        {
            i = rhs.i;
            d = rhs.d;
        }
        return *this;
    }
};
```

<h3>Кога се извиква</h3>

При присвояване на нова стойност на вече съществуващ обект. 

```c++
int main()
{
    Test t, t1(t), t2 = t1;
    t = t1;
    t = t1 = t2; // еквивалентно на t.operator=(t1.operator=(t2));
    return 0;
}
```

**Забележка:** Копиращият конструктор създава нов обект, а оператор= модифицира вече съществуващ такъв!

<h3>Shallow vs deep copy</h3>

Когато копираме данните на обекти обикновено искаме всеки обект да разполага сам с паметта на данните си. Това означава да се заделя памет при създаване на обекта и да се изтрива при унищожаването му.

<h5>Shallow copy</h5>

```c++
class Test
{
private:
    char* name;
    int age;
public:
    Test(const Test& other)
    {
        // shallow copy - the memory for name is now shared between this and other
        name = other.name;
        age = other.age;
    } 
    Test& operator=(const Test& rhs)
    {
        // Same here.
        name = rhs.name;
        age = rhs.age;
        return *this;
    }
};
```

![enter image description here](https://i.ibb.co/q5rfGBf/Capture.png)

<h5>Deep copy</h5>

```c++
class Test
{
private:
    char* name;
    int age;
public:
    // deep copy - we now manage our own memory
    Test(const Test& other)
    {
        age = other.age;
        name = new(std::nothrow) char[strlen(other.name) + 1];
        if(!name) return;
        strcpy(name, other.name);
    }
    Test& operator=(const Test& rhs)
    {
        if(this != &rhs)
        {
            // here name already exists so we have to manage the memory first
            delete[] name;
            age = rhs.age;
            name = new(std::nothrow) char[strlen(other.name) + 1];
            if(!name) return *this;
            strcpy(name, other.name);
        }
        return *this;
    }
};
```

![enter image description here](https://i.ibb.co/XZq5rGT/33.png)

<h3>Голямата четворка</h3>

- Конструктор по подразбиране (конструктор без параметри)
- Конструктор за копиране
- Оператор = за копиране
- Деструктор

<h5>Примерна имплементация:</h5>

```c++
class Person
{
public:
	Person(): name{nullptr}, age{0} {}
	Person(const Person& other)
	{	
		copy(other); // копираме
	}
	Person& operator=(const Person& other)
	{
		if (this != &other)
		{
			free(); //трием
			copy(other); //копираме
		}
		return *this;
	}
	~Person()
	{
		free(); //трием
	}
private:
    void copy(const Person& other)
    {
        age = other.age;
        name = new(std::nothrow) char[strlen(other.name) + 1];
        if(!name) return;
        strcpy(name, other.name);
    }

    void free()
    {
        delete[] name;
    }

    char *name;
    int age;
};
```

При всички класове, които използват динамична памет, тези функции изглеждат по този начин. Разликите са в имплементациите на функциите **free** и **copy**.

<h3>lvalue vs rvalue</h3>

- **lvalue** - обект, който заема някакво конкретно място в паметта. (стойността в паметта може да се модифицира)
- **rvalue** - обект, който не е  *lvalue* .

<h5>Подаване на стойност по rvalue:</h5>

```c++
#include <iostream>

void f(int& n)
{
	std::cout << n << std::endl;
}

int main()
{
	int number = 10;
    int &ref = number;
	f(number); // OK!
	f(ref);    // OK!
	f(3);      // Error!
    return 0;
}
```

"Висящата" константа 3 **няма адрес в паметта**. За това подаването и като параметър на функцията f ще доведе до компилационна грешка. 

**&&** - за стойности без адрес в паметта

<h5>Пример за използването на lvalue:</h5>

```c++
#include <iostream>

void f(int&& n)
{
	std::cout << n << std::endl;
}

int main()
{
	int number = 10;                    // OK!
    int &ref = number;                  // OK!
    int &&rvalueRef = number;           // Error!
    int &&rvalueRef = (int &&)number;   // OK!
    int &&rvalue = 2;                   // OK!
	f(number);                          // Error!
	f(rvalue);                          // Error!
	f((int &&)number);                  // OK!
	f((int &&)rvalue);                  // OK!
	f(3);                               // OK!
    return 0;
}
```

Тук грешката възниква при подаването на променлива, която **има адрес в паметта**.

Вместо ръчно да кастваме към rvalue reference, можем да използваме стандартната функция std::move, която го прави вместо нас и работи за всякакви типове.

```c++
#include <iostream>

void f(int &&n)
{
    std::cout << n << '\n';
}

int main()
{
    int number = 10;
    f(std::move(number));
    return 0;
}
```

Друга полезна функция, която можем да използваме за move семантики е std::exchange. Функцията приема два аргумента като им разменя стойностите и връща оригиналната. Пример за употреба:

```c++
int main()
{
    char *name1 = new(std::nothrow) char[10];
    if(!name1) return;
    char *name2 = std::exchange(name1, nullptr); // -> name2 = адреса, който е имал name1, а name1 = nullptr.
    delete[] name2;
    return 0;
}
```

<h3>Излишни копия?</h3>

Да разгледаме следният програмен фрагмент:
 
```c++
#include<iostream>
#include "Person.h"

Person createPerson(const char* name, int age)
{
	Person p(name, age);
	return p;
}

int main()
{
	Person p2("Petur", 18);
	p2 = createPerson("Ivan", 23);
}
```

Тук се изпълняват следните функции на Person:

1. Конструктор на Person (за p2).
2. Конструктор на Person (за p).
3. Копиращ конструктор (за *return p*).
4. Деструктор (в края на функцията *createPerson*).
5. Оператор = (за *p2 = create...* ).
6. Деструктор (в края на функцията *main*).

Проблемът тук е, че правим излишни копия.  Обектът създаден в *createPerson* **се копира два пъти докато се присвои** на p2.

<h3>Move конструктор и move оператор =</h3>

За да избегнем излишните копия, може да "преместим" данните на обектът, който се създава във функцията, в данните на p2.

```c++
//Move constructor
Person::Person(Person&& rhs)
{
	age = rhs.age;
	name = rhs.name;
	rhs.name = nullptr;
}

//Move operator=
Person& Person::operator=(Person&& rhs)
{
	if (this != &rhs)
	{
		free();
		age = rhs.age;
		name = rhs.name;
		rhs.name = nullptr;
	}
	return *this;
}
```
 
Важно е да се обърне внимание, че тук данните **не се копират**, а се **местят**. Т.е приемаме, че rhs **няма да се използва след изпълнението на функцията**.

Сега при изпълнението на първоначално разгледания код:

1. Конструктор на Person (за p2).
2. Конструктор за Person (на p).
3. **Move конструктор** (за *return p*)
4. Деструктор (в края на функцията *createPerson*).
5. **Move оператор =** (за *p2 = create...* ).
6. Деструктор (в края на функцията *main*).

Т.е. тук си спестихме 2 копия за динамичната памет в Person.

<h3>Ключови думи default, delete и explicit</h3>

<h5>default</h5>

Ключовата дума default служи за да подскажем на компилатора, че искаме да създаде конструктор или оператор със стандартно очаквана имплементация. Нека разгледаме следният пример:

```c++
class T
{
public:
    T(const int x): x(x){}

private:
    int x;
};

int main()
{
    T el[10]; // Error!
    return 0;
}
```

Какво става, ако искаме да ползваме default конструкторът на T? Ще ни даде грешка, както при декларирането на масив от този клас. Това е, защото когато дефинираме параметризиран конструктор в класа, компилаторът спира автоматично да генерира такъв по подразбиране. За целта можем да направим следното:

```c++
class T
{
public:
    T() = default;
    T(const int x): x(x){}

private:
    int x;
};

int main()
{
    T el[10]; // OK!
    return 0;
}
```

Така сме показали на компилатора, че искаме да ни създаде такъв конструктор, без да има нужда да го разписваме.

<h5>delete</h5>

Ключовата дума delete служи за да подскажем на компилатора, че не искаме да създаде конструктор или оператор със стандартно очаквана имплементация. Нека разгледаме следният пример:

```c++
class T
{
public:
    T(const char *str)
    {
        if(!str) return;
        this->str = new(std::nothrow) char[strlen(str)];
        if(this->str) strcpy(this->str, str);
    }
    ~T()
    {
        delete[] str;
    }

private:
    char *str = nullptr;
};

int main()
{
    T string("Hello");
    T temp(string);
    return 0;
}
```

Кодът ще се компилира, но ще използва стандартна имплементация на копиращият конструктор създадена от компилатора. Проблемът в случаят е, че тя работи на база shallow copy и се получават проблеми. Ако искаме да избегнем това поведение може да подскажем на компилатора да не го създава по следният начин:

```c++
class T
{
public:
    T(const char *str)
    {
        if(!str) return;
        this->str = new(std::nothrow) char[strlen(str)];
        if(this->str) strcpy(this->str, str);
    }
    T(const T&) = delete;
    ~T()
    {
        delete[] str;
    }

private:
    char *str = nullptr;
};

int main()
{
    T string("Hello");
    T temp(string); // Error!
    return 0;
}
```

Така сме оказали на компилатора да не създава копиращ конструктор и вече компилаторът ще ни се скара, че се опитваме да копираме нещо, което не може да се копира.

<h5>explicit</h5>

Ключовата дума explicit служи за да подскажем на компилатора, че искаме да конструкторът на някакъв клас трябва да бъде експлицитно извикан и не може да бъде извикан, чрез конверсия. Нека разгледаме следният пример:

```c++
class A
{
public:
    A(int) { }      // converting constructor
    A(int, int) { } // converting constructor (C++11)
};

int main()
{
    A a1 = 1;      // OK: copy-initialization selects A::A(int)
    A a2(2);       // OK: direct-initialization selects A::A(int)
    A a3 {4, 5};   // OK: direct-list-initialization selects A::A(int, int)
    A a4 = {4, 5}; // OK: copy-list-initialization selects A::A(int, int)
    A a5 = (A)1;   // OK: explicit cast performs static_cast
    return 0;
}
```

Има ситуации, в които не е добра идея да викаме копие, на някакъв клас с число например. Затова можем да използваме ключовата дума explicit, която да забрани това поведение и то става по следният начин:

```c++
class A
{
public:
    explicit A(int) { }      // converting constructor
    explicit A(int, int) { } // converting constructor (C++11)
};

int main()
{
    A a1 = 1;      // Error: copy-initialization selects A::A(int)
    A a2(2);       // OK: direct-initialization selects A::A(int)
    A a3 {4, 5};   // OK: direct-list-initialization selects A::A(int, int)
    A a4 = {4, 5}; // Error: copy-list-initialization selects A::A(int, int)
    A a5 = (A)1;   // OK: explicit cast performs static_cast
    return 0;
}
```

С помощта на тази ключова дума сме забранили тези не очевидни извиквания и странно поведение на нашият клас.

<h3>Return value optimization(RVO)</h3>

Това е вид оптимизация, която компилаторът ни прилага още по време на компилация. Целта на RVO е да намали създаването на копия, който се подават към или се връщат от функции. Нека разгледаме следният пример:

```c++
T f()
{
    T t;
    return t;
}

int main()
{
    T p = f();
    return 0;
}
```

Тук очакваме да се случат две извиквания на копиращ конструктор за T. Единият е, когато връщаме стойността от функцията, за да я премести в main преди да се отърве от scope-а на функцията f. А другият е, когато създаваме p. С други думи две копирания за 1 обект. Целта на тази оптимизация е да разпознава такива проблеми от рано и да ги реши. Решението е като разбере, къде е крайната дестинация на която трябва да живее този временен обект. А именно в нашия случай в main. Така той директно във функцията f ще конструира обекта в паметта, която се намира в стековата рамка на main. Или с други думи ще извикаме само един конструктор по подразбиране.

За кодът по-горе можем да пробваме да го компилираме по следните 2 начина:

```bash
g++ --std=c++11 -fno-elide-constructors main.cpp -o main.exe
```

По този начин изключваме тази оптимизация и компилаторът е принуден да вика копиращ или местещ конструктор винаги. Така ще извикаме копиращият конструктор 2 пъти.

```bash
g++ --std=c++11 main.cpp -o main.exe
```

По този начин компилаторът ще оптимизира създаването на обекта и няма да вика копиращият или местещ конструктор.

Тази оптимизация, дори и включена, не винаги може да бъде приложена. Нека разгледаме следният пример:

```c++
T f(bool b)
{
    T t1;
    T t2;
    if (b) return t1;
    else return t2;
}

int main()
{
    T p = f(true);
    return 0;
}
```

Когато имаме разклонение на кода компилаторът няма как да е сигурен дали да използва мястото за t1 или за t2, за да го сложи в пространството заделено за p в main. И така е принуден да извиква копиращ или местещ конструктор.

<h5>Стандарта c++17</h5>

По стандарт след стандарта c++17 компилаторът е задължен да прави тази оптимизация, дори и да не съществува копиращ конструктор за T. Преди това обаче компилаторът ще се скара, че нямаме копиращ конструктор, дори и да не го използва.

```bash
g++ --std=c++11 main.cpp -o main.exe
```

Тук компилаторът ще ви даде следната грешка:

```c++
test.cpp: In function 'Noisy f(int)':
test.cpp:19:12: error: use of deleted function 'Noisy::Noisy(const Noisy&)'
   19 |     return v;
      |            ^
test.cpp:7:5: note: declared here
    7 |     Noisy(const Noisy&) = delete;
      |     ^~~~~
```

```bash
g++ --std=c++17 main.cpp -o main.exe
```

Тук кодът работи нормално.

<h3>Домашно</h3>

**Задача 1:** Напишете клас *Laptop*. Един лаптоп се нуждае от марка и модел (стринг с произволна дължина), цена, размер на екрана (в инчове), процесор (помислете как да представите процесора с нужните му характеристики - тактова честота, брой ядра и размер на КЕШ паметта), РАМ памет и капацитет на батерията. Напишете следните специални методи:

- Конструктор по подразбиране
- Конструктор за копиране
- Конструктор(и) с параметри, данните за един лаптоп
- Оператор за присвояване
- Деструктор

Напишете подходящи методи за upgrade на процесора и РАМ-а, както и метод за подходящо принтиране на информацията.

**Задача 2:** Напишете клас *ToDo*, който описва задача, която трябва да се изпълни. Всяка задача си има id, описание и индикатор за това дали тя е изпълнена или не. Напишете следните специални методи на класа:

- Конструктор по подразбиране
- Конструктор за копиране
- Оператор за присвояване
- Деструктор
- Метод за изпълнение на задачата

**Задача 3:** Магьосникът Маг-О-Кодерски е магьосник в местното за ФМИ заведение BeerOverflow. Там той изпълнява всяка вечер своя коронен номер - всеки посетител на BeerOverflow пуска нещо в "магическата кутия" на Маг-О-Кодерски, а в края на вечерта кутия изхвърля един предмет във въздуха, на случаен принцип.

Маг-О-Кодерски също е и програмист. Той иска да напише програма, в която да въвежда променливи от целочислен тип, и при извикване на даден метод, "кутията" да му връща случайна променлива от вече въведените.

Да се напише клас **MagicalBox** със следните:

**Полета:**

- Динамичен масив (който да се разширява при необходимост)

**Методи:**

- *insert()* - добавя елемент към кутията 
- *pop()* - премахва случаен елемент от кутията. Ако кутията е празна, да показва  подходящо съобщение 

Може да дефинирате допълнителни методи и полета.