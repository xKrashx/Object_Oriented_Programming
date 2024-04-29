<h1>Колекции от обекти в полиморфна йерархия. Специфики при копиране и триене. Factory pattern. Шаблони.</h1>

<h3>Хетерогенни контейнери</h3>

Можем да реализираме колекция от различни типове (но с общ базов клас), чрез масив от указатели. Указателите трябва да са от типа на базовия клас.

```c++
struct Fruit
{
	virtual void printColor() const = 0;

	virtual ~Fruit(){}
};

struct Apple : public Fruit
{
	 void printColor() const override
	{
		std::cout << "Red or green!\n";
	}
};

struct Orange : public Fruit
{
	void printColor() const override
	{
		std::cout << "Orange!\n";
	}
	
};

struct Lemon : public Fruit
{
	Lemon(size_t sourness) : sourness(sourness){}
	
	size_t sourness;
	void printColor() const override
	{
		std::cout << "Yellow!\n";
	}
};

class FruitStore
{
public:
	FruitStore();
	FruitStore(const FruitStore&);
	FruitStore(FruitStore&&);
	FruitStore& operator=(const FruitStore&);
	FruitStore& operator=(FruitStore&&);
    ~FruitStore();

    void AddFruit(Fruit *fruit);

private:
	Fruit** fruits;
	size_t capacity;
	size_t size;

    void Resize();
    void Copy(const FruitStore& other);
    void Free();
};

void FruitStore::AddFruit(Fruit *fruit)
{
    if(size == capacity) Resize();
	fruits[size++] = fruit;
}
```

<h5>Триене</h5>

Понеже колекцията, която правим вече не е масив от обекти, а е масив от `указатели` към обекти, трябва да изтрием първо всеки указател по отделно и тогава да освободим целия масив.
Също така имаме виртуален деструктор в базовия клас, поради което не се интересуваме в колекцията какви са обектите, които трием.

```c++
void FruitStore::Free()
{
	for(size_t i = 0; i < size; i++)
		delete fruits[i];
	delete[] fruits;
}
```

<h5>Копиране</h5>

Искаме да реализираме копиране на колекцията.
Това трябва да стане без да нарушаваме абстракцията - искаме обектите да се копират без да се налага да запитваме за техния тип.
За това дефинираме виртуална функция Clone, която ще връща копие на обекта(виртуален конструктор за копиране). Тази функция я разписваме във всеки от наследниците.

```c++
struct Fruit
{
	virtual void printColor() const = 0;
	virtual ~Fruit(){}

    virtual Fruit* clone() const = 0; //!
};

struct Apple : public Fruit
{
    void printColor() const override
	{
		std::cout << "Red or green!\n";
	}
	Fruit* clone() const override
	{
		return new Apple(*this);
    }
};

struct Orange : public Fruit
{
	void printColor() const override
	{
		std::cout << "Orange!\n";
	}
	
	Fruit* clone() const override
	{
		return new Orange(*this);
	}
};

struct Lemon : public Fruit
{
	Lemon(size_t sourness) : sourness(sourness){}
	
	size_t sourness;
	void printColor() const override
	{
		std::cout << "Yellow!\n";
	}
	Fruit* clone() const override
	{
		return new Lemon(*this);
    }
};
```

От тук копирането става по следният начин:

```c++
void FruitStore::Copy(const FruitStore& other)
{
	fruits = new Fruit*[other.capacity];
	for(size_t i = 0; i < other.size; i++)
		fruits[i] = other.fruits[i]->Clone();

	size = other.size;
	capacity = other.capacity;
}
```

<h3>Factory pattern</h3>

Идеята на този принцип за дизайн е да изкараме спецификата за това как се създават конкретни обекти в една функция. Тази функция, ще получава само типът(enum от типовете) на обекта, който искаме да създадем и аргументите, които ще са необходими за създаването на дадения обект.

По този начин, когато искаме да създадем обект от нашата полиморфна йерархия ще извикваме само Factory-то като казваме какъв обект искаме да създадем.

```c++
enum class FruitTypes
{
    Apple,
    Orange,
    Lemon
};

Fruit *Factory(FruitTypes type)
{
    switch(type)
    {
        case FruitTypes::Apple:
            return new Apple();
        case FruitTypes::Orange:
            return new Orange();
        case FruitTypes::Lemon:
            return new Lemon();
        default:
            return nullptr;
    }
}
```

Сега можем да използваме нашият контейнер с нашата фабрика за обекти по следният начин:

```c++
int main()
{
    FruitStore container;
    container.AddFruit(Factory(FruitTypes::Apple));
    container.AddFruit(Factory(FruitTypes::Orange));
    container.AddFruit(Factory(FruitTypes::Lemon));

    return 0;
}
```

По този начин ние използваме на всякъде указатели към базовия клас освен в нашата фабрика. Или с други думи сме изнесли цялата специфика в една конкретна функция.

<h3>Шаблони</h3>

Идеята на шаблоните е да напишем код, който може да се преизползва за различни типове. Пример за това е колекция от типа на vector например. Имаме един код, който описва колекцията и той е еднакъв за всички типове, с които го използваме.

<h5>Синтаксис</h5>

```c++
template <typename T>
void f(T t){}

int main()
{
    f<int>(10);
    return 0;
}
```

Компилаторът вижда функцията/класът, който е направен като template и в зависимост с какви типове е бил използван в кода ни тези типове биват създадени. Ако извикването на f го няма, компилирания assembler код ще изглежда така:

```assembly
main:
        Push    rbp
        mov     rbp, rsp
        mov     eax, 0
        Pop     rbp
        ret
```

А с извикването на f изглежда така:

```assembly
main:
        Push    rbp
        mov     rbp, rsp
        mov     edi, 10
        call    void f<int>(int) ; Извиква се f в main
        mov     eax, 0
        Pop     rbp
        ret
; Генерира се кода за функцията f с T = int
void f<int>(int):
        Push    rbp
        mov     rbp, rsp
        mov     DWORD PTR [rbp-4], edi
        nop
        Pop     rbp
        ret
```

Това означава, че кода, който пишем е един буквален "шаблон", който компилаторът да използва, за да изгенерира кода, в зависимост от това с какви типове е използван.

<h5>Разделна компилация</h5>

Тъй като кодът се генерира спрямо използването, стандартната разделна компилация няма да работи.
Нека разгледаме следният пример:

```c++
// header
template <typename T>
void f(T t);
```

```c++
// cpp файл с имплементация
template <typename T>
void f(T t){}
```

```c++
// cpp файл с main
int main()
{
    f<int>(10);
    return 0;
}
```

Двата файла, които ще компилираме са cpp-тата с имплементацията и с main.

- При компилиране на имплементационния cpp файл нямаме никъде използване на template-ния клас => няма да бъде генериран никакъв код. С други думи няма да създадем имплементация на функцията.
- При компилиране на cpp файлът с main имаме използване на f<int> ще се генерира прототипа на функцията от header файлът, с тип int. Обаче той няма да има дефиниция.

Крайният резултат е, че генерираме само прототип без имплементация.

Как се решава този проблем?

Има два варианта да бъде имплементирано, така че да работи.

1. В cpp файла с имплементацията добавяме спецификации, за това с какви типове ще бъде използвано.

```c++
// cpp файл с имплементация
template <typename T>
void f(T t){}

template void f<int>;
template void f<double>;
```

Кода, който ще се генерира в от имплементационният файл е следният:

```assembly
void f<int>(int):
        Push    rbp
        mov     rbp, rsp
        mov     DWORD PTR [rbp-4], edi
        nop
        Pop     rbp
        ret
void f<double>(double):
        Push    rbp
        mov     rbp, rsp
        movsd   QWORD PTR [rbp-8], xmm0
        nop
        Pop     rbp
        ret
```

Както виждаме в зависимост от типовете, които специфицираме, показваме кои да бъдат генерирани.
Този вариант обаче изисква от нас всеки път, когато ще използваме шаблона с нов тип да влезнем и да го добавим.

2. Да нямаме имплементационнен cpp файл и да вкараме всичкия код за шаблона в header-а.

```c++
template <typename T>
struct A
{
    void f();
};

template <typename T>
void A<T>::f(){}
```

С този подход, всеки cpp файл, който добавя този header, ще си генерира шаблона с конкретните типове, които са използвани в дадения файл.

<h5>Параметри на шаблони</h5>

Параметрите на шаблоните могат да бъдат следните:

1. template < parameter-list > type-parameter-key name (optional)
    - Параметри с опционално име
2. template < parameter-list > type-parameter-key name (optional) = default
    - Параметри с опционално име и стойност по подразбиране
3. template < parameter-list > type-parameter-key ... name (optional)
    - Пакет от параметри с опционално име

*Пакетите от параметри приемат 0 или повече аргументи.

Примери за използване на тези параметри:

```c++
// Шаблон, който изисква да му бъде подадено име, експлицитно или имплицитно.
template <typename T>
void f(T t){}

// По подразбиране, ако не бъде посочен тип за шаблона, ще бъде създадена функцията с T = int.
template <typename T = int>
T g(){ return (T)10; }

// Шаблон, който приема 0 или повече типа, като аргументи
template <typename ...Args>
void h(Args... args){}

int main()
{
    f<int>(10);             // Ще използва експлицитно посоченият тип int.
    f(2.3);                 // Ще използва имплицитно посоченият тип double.
    g<double>();            // Ще използва експлицитно посоченият тип double.
    g();                    // Ще използва имплицитно посоченият тип по подразбиране int
    h();                    // Ще използва h без да дава параметри на шаблона.
    h<>();                  // Ще използва h без да дава параметри на шаблона.
    h(10);                  // Ще използва h с имплицитно посоченият тип int.
    h<double>(10);          // Ще използва h с експлицитно посоченият тип double.
    h(10, 2.3);             // Ще използва h с имплицитно посочените типове int и double.
    h<int, int>(10, 2.3);   // Ще използва h с експлицитно посочените типове int и int.
    return 0;
}
```

Параметрите не е задължително да бъдат само типове. Може да се подават и стойности, като lvalue, rvalue и др.

```c++
template <int N = 10>
void f()
{
    int arr[N];
}

int main()
{
    f<5>(); // Ще зададе стойност на N 5, когато компилаторът генерира кода.
    f();    // Ще използва стойността, която е подадена по подразбиране(10).
}
```

<h5>Влагане на шаблони</h5>

Има ситуации, в които искаме на обект с един шаблонен тип да подадем друг обект с различен шаблонен тип. Тогава ни трябва влагане на шаблони в класът.

```c++
template <typename T>
class Vector
{
public:
    // Vector interface...

    // Копиращ конструктор, който да копира вектор с друг шаблонен тип
    // Например от Vector<float> да копираме данните в Vector<double>.
    template <typename U>
    Vector(const Vector<U>& other);

private:
    // Vector internals...
};
```

<h5>Развиване на пакетни шаблони</h5>

Пакетните шаблони се подават като едно съвкупност от всичките типове/стойности.
За да ги развием и да ползваме отделните елементи има два варианта:

1. Индексация

```c++
template <typename... Args>
void f(Args... args)
{
    // Това ще покаже броят на елементите в пакета.
    std::cout << sizeof...(Args) << '\n';
    // Достъп до първият елемент от аргументите.
    args...[0];
    // Достъп до последният елемент от аргументите.
    args...[sizeof...(Args) - 1];

    // Разписването на цикъл да се минава през всички става елементарно с горепосочените оператори.
}
```

2. Рекурсивно разгъване

```c++
template <typename T, typename... Args>
void f(T value, Args... args)
{
    // Изпечатваме първият елемент в пакета от аргументи.
    std::cout << value << '\n';
    // Подаваме остатъкът от аргументите, за да се вземе първият като value и останалите остават в пакета.
    // Това ще продължава докато няма повече аргументи.
    f(args...);
}

int main()
{
    f(1, 2.3, 'a');
}
```

<h5>Шаблонна спецификация</h5>

Можем да специфицираме държанието на даден/а клас/функция спрямо типът, който е подаден. Ето и един нагледен пример как се специализира шаблон:

```c++
template <typename T>
void sort(T arr[], size_t size)
{
    // Сортиращ алгоритъм...
    // Проверката в сортиращият алгоритъм ще бъде извършена с оператор >.
}

template <>
void sort<char *>(char *arr[], size_t size)
{
    // Същият сортиращ алгоритъм...
    // Проверката в сортиращият алгоритъм ще бъде извършена с употребата на strcmp.
}
```

По този начин специфицираме специално поведение, при някои конкретни типове.

- Добър пример за шаблонна специализация е имплементацията на std::vector. Той има спецификация за bool, която се държи по различен начин от останалите типове. Тъй като bool използва 1 бит, но заема 1 байт, защото не може по-малко, тази спецификация създава масив от char-ове, където всеки char може да побере 8 bool-а.

<h5>Библиотеката type_traits</h5>

В тази библиотека има доста полезни предефинирани типове, които могат да бъдат използвани като шаблонни параметри. Например: is_default_constructible, is_copy_constructible, is_integral, is_base_of и много др. Можете да си ги разгледате на спокойствие, ако решите да задълбавате в тях.

<h3>Домашно</h3>

**Задача 1:** Реализирайте структурата от данни опашка. Опашката трябва да работи с `произволни типове`. След като е добавен един елемент в края на опашката, той ще може да бъде извлечен (премахнат) единствено след като бъдат премахнати всички елементи преди него в реда, в който са добавени.

<h5>Пример за работа:</h5>

```c++
int main()
{
	Queue<int> q;
	q.Push(3);
	q.Push(5);
	q.Push(10);

	std::cout << q.Peek() << '\n'; //3
	q.Pop();

	std::cout << q.Peek() << '\n'; //5
	q.Pop();

	std::cout << q.Peek() << '\n'; //10
	q.Pop();

	std::cout << q.isEmpty() << '\n'; //1	
}
```

**Задача 2:** Създайте `шаблонна` опашка с k приоритета. При взимане на елемент от опашката трябва да се връща най-отдавна добавения елемент от тези с най-висок приоритет. **Важно:** Използвайте имплементацията на опашка от предната задача!
 
```c++
int main()
{
	KPriorityQueue<char> q(4); // 4 priorities - 0, 1, 2 и 3.

	q.Push('A',0): //adds A with lowest priority: 0
	q.Push('B',3);
	q.Push('C',2);
	q.Push('D',2);
	q.Push('E',1);

	//q.Push('F', 5); //error! No such priority!

	q.Peek(); // B
	q.Pop();

	q.Peek(); // C
	q.Pop();

	q.Peek(); // D
	q.Pop();

	q.Peek(); // E
	q.Pop();

	q.Peek(); // A
	q.Pop();
}
```

**Задача 3:** Да се направи хетерогенен контейнер имитиращ папка с файлове.

Типовете файлове, които ще поддържаме са .csv, .txt, .xml.

Да се реализират методи за работа с тези файлове, като
open, save, close и print.

**Бонус:** Да се направи, така че тези методи да работят с реални файлове в директорията на проекта.