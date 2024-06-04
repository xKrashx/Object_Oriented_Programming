<h1>Указатели към функции. Ламбда функции. Обекти имитиращи функции.</h1>

Нека си представим, че ни е дадена следната задача:
Да напишем функция, която обикаля масив и прилага дадена функция върху всеки един от елементите му. То това би изглеждало така:

```c++
int AddOne(const int x)
{
    return x + 1;
}

void Map(int * const array, const size_t size)
{
    for(size_t i = 0; i < size; ++i)
    {
        array[i] = AddOne(array[i]);
    }
}
```

Сега идва въпроса, ами какво става ако искам да направя същото нещо, обаче функцията, която ще променя елементите да прави друго нещо. Звучи лесно просто ще добавим още 2 функции за това.

```c++
int AddOne(const int x)
{
    return x + 1;
}

int Double(const int x)
{
    return 2 * x;
}

void MapWithAddOne(int * const array, const size_t size)
{
    for(size_t i = 0; i < size; ++i)
    {
        array[i] = AddOne(array[i]);
    }
}

void MapWithDouble(int * const array, const size_t size)
{
    for(size_t i = 0; i < size; ++i)
    {
        array[i] = Double(array[i]);
    }
}
```

Ами ако реша да добавя още 10 такива операции?

<h3>1. Указатели към функции</h3>

Тук би било редно да въведем първо, какво е указател към функция, преди да отговорим на въпросът по-горе.

- Указател към функция е както всички останали указатели. Той сочи към адрес в паметта.
- Разликата при този вид указател е, че не сочим към клетка с данни, ами към клетка с инструкции.
- Нашата програма се компилира до изпълним файл, в който инструкциите за всяка една функция живеят на някой адрес в паметта.

<h5>1.1 Синтаксис</h5>

```c++
void Print(int x)
{
    std::cout << "Hello World! Value is: " << x << '\n';
}

int main()
{
    void(*function)(int);

    function = &Print;
    function = Print;

    return 0;
}
```

Няколко неща, които е важно да се отбележат:

- Макар и страшният си вид, указателите към функции са както всички останали променливи. Имат си тип, име и можем да им присвояваме стойност.
- Типът на горепосоченият пример е следният: void(*)(), името на променливата е function, а стойностите, които присвояваме са &Print и Print.
- Защо можем да правим &Print и Print? Защото както знаем операторът & ни дава адреса на променлива или в случая на функция. Вторият вариант е по-модерен начин, който c++ позволява като синтаксис.
- Типът на функцията означава следното нещо:
    - void - Функцията, която ще присвоим ще връща void.
    - (*variable_name) - указва, че това е указател към функция
    - (int) - в тези скоби се отбелязва типът на променливите, които ще се подадат на присвоената функция като аргументи.

<h5>1.2 Употреба</h5>

Направили сме указател към функция. Сега въпросът е как да го използваме?

```c++
void Print(int x)
{
    std::cout << "Hello World! Value is: " << x << '\n';
}

int main()
{
    void(*function)(int) = Print;

    function(3);
    function(2);
    function(6);

    return 0;
}
```

Можем да извикваме променливата, както нормална функция и тя ще работи, както бихме очаквали.

<h3>2. Функции от по-висок ред</h3>

Сега с новопридобитите ни знания можем да се върнем на първоначалният въпрос. А именно, какво трябва да направим, ако искаме да имаме 10 различни функции за една и съща операция? Отговорът на този въпрос са функциите от по-висок ред.

`Функция от по-висок ред е функция, която приема функция като аргумент.`

```c++
int AddOne(const int x)
{
    return x + 1;
}

int Double(const int x)
{
    return 2 * x;
}

void Map(int * const array, const size_t size, int(*operation)(const int))
{
    for(size_t i = 0; i < size; ++i)
    {
        array[i] = operation(array[i]);
    }
}
```

По този начин, ако реша да добавя още операции, единственото, което трябва да променя е начинът, по който извиквам функцията Map.

Ето и финалният вариант на нашата програма.

```c++
int AddOne(const int x)
{
    return x + 1;
}

int Double(const int x)
{
    return 2 * x;
}

void Map(int * const array, const size_t size, int(*operation)(const int))
{
    for(size_t i = 0; i < size; ++i)
    {
        array[i] = operation(array[i]);
    }
}

int main()
{
    const size_t SIZE = 5;
    int array[SIZE] = {1, 2, 3, 4, 5};

    Map(array, SIZE, AddOne);

    for(size_t i = 0; i < SIZE; ++i)
    {
        std::cout << array[i] << ' ';
    }
    std::cout << '\n';

    Map(array, SIZE, Double);

    for(size_t i = 0; i < SIZE; ++i)
    {
        std::cout << array[i] << ' ';
    }
    std::cout << '\n';

    return 0;
}
```

<h3>3. Функции, които връщат функции, като резултат</h3>

```c++
void HelloWorld()
{
    std::cout << "Hello World!\n";
}

void HelloThere()
{
    std::cout << "Hello There!\n";
}

void (*PrintFactory(const bool flag))()
{
    if(flag)
    {
        return HelloWorld;
    }
    return HelloThere;
}

int main()
{
    PrintFactory(true)();
    PrintFactory(false)();

    return 0;
}
```

<h3>4. typedef и как ни помага</h3>

За писане на по-дълги или сложни типове, не е добра идея да бъдат изписвани всеки път. За тази цел имаме typedef. Той ни позволява да си дефинираме синоним на типът, който искаме да използваме.

```c++
typedef int** IntMatrix;

int main()
{
    IntMatrix matrix;
    return 0;
}
```

```c++
typedef void(*PrintFunction)();

void HelloWorld()
{
    std::cout << "Hello World!\n";
}

void HelloThere()
{
    std::cout << "Hello There!\n";
}

PrintFunction PrintFactory(const bool flag)
{
    if(flag)
    {
        return HelloWorld;
    }
    return HelloThere;
}

int main()
{
    PrintFunction func = PrintFactory(true);
    func();
    func = PrintFactory(false);
    func();
    return 0;
}
```

<h3>Задача</h3>

Нека имплементираме клас множество, на което се подава функция(критерии) в конструктора, по който да се определя дали можем да добавим даден елемент или не към множеството.

Нашият клас трябва да изглежда нещо подобно на това:

```c++
#include <vector>

typedef bool (*PredicateFunction)(int);

class Set{

public:
    Set(PredicateFunction predicate);

    void Add(int x);
    void Print() const;

private:
    std::vector<int> m_Members;
    PredicateFunction m_Predicate;

};
```

Разписани функциите изглеждат така:

```c++
#include "Set.hpp"
#include <iostream>

Set::Set(PredicateFunction predicate): m_Predicate(predicate){}

void Set::Add(int x){
    if(m_Predicate(x))
        m_Members.push_back(x);
}

void Set::Print() const{
    for(size_t i = 0; i < m_Members.size(); ++i)
        std::cout << m_Members[i] << ' ';
    std::cout << '\n';
}
```

Сега остава да си създадем такова множество и да му дадем критерии:

```c++
#include "Set.hpp"

bool IsEven(int x){
    return !(x % 2);
}

int main(){

    Set setOfEvenNumbers(IsEven);

    setOfEvenNumbers.Add(1);
    setOfEvenNumbers.Add(2);
    setOfEvenNumbers.Add(3);
    setOfEvenNumbers.Add(4);
    setOfEvenNumbers.Add(5);
    setOfEvenNumbers.Add(6);

    setOfEvenNumbers.Print(); // 2 4 6

    return 0;

}
```

<h3>5. Обекти имитиращи функции</h3>

С текущата ни имплементация идва следният проблем:
Какво ако искаме да направим класа Set да работи освен с предикатната функция за четни числа, така и с предикат, който ни казва дали числото е по-голямо от някакво n.

Тогава трябва да добавим в Set още едно поле за числото n. Ако решим да добавим и такъв, който да е за числа по-малки от m, трябва да добавим и още едно поле и т.н. За всеки специфичен критерии трябва да променяме как се държи класа Set. По-добра практика ще е ако класа Set се грижи само за самите елементи, а това дали трябва да принадлежат ще оставим на друг клас. Класовете предикати ще изглеждат така:

```c++
class Criteria{

public:
    virtual bool operator()(int) = 0;
    virtual ~Criteria() = default;

};

class EvenCriteria : public Criteria{

public:
    bool operator()(int x) override{
        return !(x % 2);
    }

};

class BiggerThanCriteria : public Criteria{

public:
    BiggerThanCriteria(int n): m_Threshold(n){}

    bool operator()(int x) override{
        return x > m_Threshold;
    }

private:
    const int m_Threshold;

};
```

И сега класът Set ще изглежда по следният начин:

```c++
#include <vector>
#include "Criteria.hpp"

class Set{

public:
    Set(Criteria *criteria);
    ~Set();

    // Премахваме копиране и местене, за да стане по-кратък примера.
    // В нормална задача тези ще трябва да се разпишат.
    Set(const Set& other) = delete;
    Set(Set&& other) = delete;
    Set &operator =(const Set& other) = delete;
    Set &operator =(Set&& other) = delete;

    void Add(int x);
    void Print() const;

private:
    std::vector<int> m_Members;
    Criteria *m_Criteria;

};
```

Разписани функциите изглеждат така:

```c++
#include "Set.hpp"
#include <iostream>

Set::Set(Criteria *criteria): m_Criteria(criteria){}
Set::~Set(){ delete m_Criteria; }

void Set::Add(int x){
    if(m_Criteria->operator()(x))
        m_Members.push_back(x);
}

void Set::Print() const{
    for(size_t i = 0; i < m_Members.size(); ++i)
        std::cout << m_Members[i] << ' ';
    std::cout << '\n';
}
```

Сега остава да си създадем такова множество и да му дадем критерии:

```c++
#include "Set.hpp"
#include "EvenCriteria.hpp"
#include "BiggerThanCriteria.hpp"

int main(){

    Set setOfEvenNumbers(new EvenCriteria);

    setOfEvenNumbers.Add(1);
    setOfEvenNumbers.Add(2);
    setOfEvenNumbers.Add(3);
    setOfEvenNumbers.Add(4);
    setOfEvenNumbers.Add(5);
    setOfEvenNumbers.Add(6);

    setOfEvenNumbers.Print(); // 2 4 6

    Set setOfNumbersBiggerThanN(new BiggerThanCriteria(3));

    setOfNumbersBiggerThanN.Add(1);
    setOfNumbersBiggerThanN.Add(2);
    setOfNumbersBiggerThanN.Add(3);
    setOfNumbersBiggerThanN.Add(4);
    setOfNumbersBiggerThanN.Add(5);
    setOfNumbersBiggerThanN.Add(6);

    setOfNumbersBiggerThanN.Print(); // 4 5 6

    return 0;

}
```

<h3>6. Ламбда функции</h3>

Ламбда функцията е механизъм за дефиниране на локална функция, която ще може да бъде употребявана само в scope-а, в който е дефинирана. Също така те са много удобни, когато искаме да използваме функции от по-висок ред и не искаме да подаваме глобални функции.

<h5>6.1. Синтаксис</h5>

```c++
[captures] <t-params> (params) exception_specifier(optional) trailing_type(optional) { body }
```

- [captures] - Това е списък от 0 или повече променливи/обекти, които ламбда функцията да може да достъпва.
    - [] - Има достъп само до глобални/статични променливи.
    - [n] - Взима n по копие от външния scope.
    - [&n] - Взима n по референция от външния scope.
    - [=] - Взима всички променливи от външния scope по копие.
    - [&] - Взима всички променливи от външния scope по референция.
    - Не можем да правим следните неща с capture list:
        - [&, &n] - Не можем да подадем n по референция, тъй като референцията е default.
        - [=, *this] - Грешен синтаксис.
        - [=, this] - Когато подаваме по =, this се подава автоматично.
        - [n, n] - n се повтаря.
        - [n](int n) - n е подадено като външна променлива и е създадена локална за функцията променлива със същото име.
- \<t-params> - Това е не празен списък с шаблонни параметри.
- (params) - Това е списъкът с параметри на функцията.
- exception_specifier - noexcept спецификатор, за това че функцията не хвърля грешка
- trailing_type - Пише се `->return_type` и определя типът на връщане на ламбда функцията. Ако го няма се подразбира void, като тип на връщане.
- body - Тялото на функцията.

<h5>6.2. Употреба</h5>

```c++
#include <iostream>

int main(){

    const double PI = 3.14;

    void (*printLambda)(int) = [PI](int x)->void{
        std::cout << x * PI << '\n';
    };

    printLambda(10); // 31.4
    printLambda(5);  // 15.7

    return 0;

}
```