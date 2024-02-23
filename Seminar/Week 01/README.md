<h1>Преговор на концепции от УП. Въведение в ООП. Структури, обединения, енумерации и пространства на имената.</h1>

<h3>Видове памет</h3>

<img src="https://media.geeksforgeeks.org/wp-content/uploads/memoryLayoutC.jpg" align="right" width=600 height=500 style="object-fit: contain;"/>

Паметта, която можем да използваме в **C++** има 4 основни типа:
<br/>

- **Глобална (Статична)**: в тази памет се записват статичните/глобалните променливи.
- **Стекова (stack)**: тя съдържа "локалните" променливи, т.е. онези, които са дефинирани в телата на функции и са същевременно не статични.
	  * Заделя се в момента на дефиниция на променливите и се освобождава в момента на изход от scope-a, в която е дефинирана;
	  * Последно заделената памет се освобождава първа (First in Last out);
	  * Количеството заделена памет е определена по време на компилация;
	  * Ние нямаме контрол над управлението над паметта
- **Динамична (heap)**: е "свободната" част от паметта, която се използва (*динамично*) в хода на програмата. 
	* Заделя се и се освобождава по всяко време на изпълнение на програмата;
	* Областта за динамична памет е набор от свободни блокове памет;
	* Програмата може да заяви блок с произволна големина;
	* Имаме контрол над управлението на паметта;	  
- **Program Code**: памет, в която се пази нашият компилиран код
	* Може да се достъпва с function pointer-и

<h3>Преговор на указатели, референции и динамична памет.</h3>

Създаване на променливи:

```c++
#include <iostream>

int main()
{
	int a = 10;				// int in the stack
	int* ptr = new int(30); // int in the dynamic memory (we use a pointer on the stack to point to the int)

	std::cout << "First number: " << a << " " << " second number: " << (*ptr) << std::endl;
	
	std::cout << "Address of second number" << ptr << std::endl;
	
	delete ptr; //!!! 
	
	ptr = &a;
	std::cout << "Address of first number" << ptr << std::endl;
	
	int& b = a; //another name for the variable
	b = 30;
	
	std::cout << "First number" << a << std::endl 

}
```

<h3>Подаване на параметри във функция</h3>

Подаване по копие:

```c++
#include <iostream>

void f(int a)
{
	a++;
}

int main()
{
	int a = 10;
	f(a);
	std::cout << a << std::endl; //10
}
```

Подаване по референция:

```c++
#include <iostream>

void f(int& a)
{
	a++; //a++ will increment the pointer
}

int main()
{
	int a = 10;
	f(a);
	std::cout << a << std::endl; //11
}
```

Подаване по указател:

```c++
#include <iostream>

void f(int* a)
{
	(*a)++; //a++ will increment the pointer
}

int main()
{
	int a = 10;
	f(&a); //&a returns a pointer to a.
	std::cout << a << std::endl; //11
}
```

<h3>Какво е ООП?</h3>

Както името подсказва Обектно Ориентираното Програмиране е програмна парадигма, която главно разчита на работа с **обекти**. Тя е една от много различни парадигми за програмиране, както функционално, логическо, системно, паралелно, императивно и много други видове парадигми за програмиране. Главната цел на ООП е да обедини данните и функционалността свързана с тези данни, под една шапка(обект). Съответно всеки обект е способен да получава съобщения, обработва данни и праща съобщения на други обекти.

<h3>Основните принципи на ООП</h3>

- Абстракция
	- Процесът на скриване на ненужни подробности от потребителя
- Капсулация
	- Един обект трябва да предоставя на ползващия го само пряко необходимите му средства за управление.
- Наследяване
	- Позволява да бъдат дефинирани и създавани обекти, които са специализирани варианти на вече съществуващи обекти.
	- Класът наследник взема всички полета и методи на класа-родител
- Полиморфизъм
	- Представлява свойството на обектите от един и същи тип да имат един и същи интерфейс, но с различна реализация на този интерфейс.

<h3>Structs (Структури)</h3>

Структурите в C++ се използват за групиране на елементи. Елементите, наричани още членове, могат да бъдат от различен тип и с различна дължина.

Дефиниране на нов тип:

```c++
struct Box
{
	double height;
	double width;
	double length;
}
```

Деклариране на обекти от новия тип:

```c++
Box b; //default values to height and width ans lenght

Box b2 = {3, 4, 3.4} // height = 3, width = 4, length = 3.4;

Box b3;
b3.height = 13;
b3.width = 14;
b3.lenght = 20;
```
	
Подаване във функции:

Ако няма да променяме обекта го подаваме по **константна референция.**

```c++
double calculcateVolume(const Box& b)
{
    return b.height * b.width * b.length;
}
```

Може и само по **референция**, но тогава може да се правят промени върху подадения аргумент.
   
```c++
void readBox(Box& b)
{
    std::cin >> b.height >> b.width >> b.length;
}
```

Може и да го подаваме по **копие**.

```c++
Box revertBox(Box b)
{
    int temp = b.height;
    b.height = b.width;
    b.width = temp;

    return b;
}
```

Създаване на динамични обекти:

```c++
#include <iostream>

struct Box
{
	double height;
	double width;
	double length;
};

double calculcateVolume(const Box& b)
{
    return b.height * b.width * b.length;
}

int main()
{
	Box* boxPtr = new Box();

	(*boxPtr).height = 3;
	(*boxPtr).width = 1;
	boxPtr->length = 4;
	
	std::cout << calculcateVolume(*boxPtr) << std::endl;
	
	delete boxPtr;
}
```

Влагане на обекти:

```c++
struct Box
{
	double height;
	double width;
	double length;
};

struct Warehouse
{
	char name[1024];
	Box b1;
	Box b2;
};

int main()
{
	Warehouse w = { "Ekont", { 1, 2, 3 }, { 4, 5, 3 } };

	std::cout << w.name;
}
```

Масиви от обекти:

```c++
struct Box
{
	double height;
	double width;
	double length;
};

int main()
{
	Box arr1[30]; //30 boxes
	Box* arr2 = new Box[20] //20 boxes in dynamic mem.
	
	std::cout << arr1[0].height << " " << arr2[3].width << std::endl;

	delete[] arr2;
}
```

<h3>Size and Padding (Размер на обекти и подравняване)</h3>

- Паметта е байт-адресируема, т.е. може да достъпва всеки байт индивидуално;
- Колко памет може да прочете процесорът за един memory read cycle, зависи от архитектурата му (x32 - 4 bytes, x64 - 8 bytes);
- В паметта променливите са разположени в същия ред, в който са декларирани в структурата;
- Подравняването на една структура става по големината на най-голямото поле (даже и в случая на вложена структура) на структурата (с цел минимизиране на подравняването);
- За да бъде минимална паметта, която ползва една структура, трябва да подредим нейните полета в нарастващ или намаляващ ред по големина на променливата

```c++
struct A
{
	bool b;
	int c;
};

int main()
{
	std::cout << sizeof(A) << std::endl; //8 (not 5)
}
```

![enter image description here](https://i.ibb.co/nsCKYLN/struct.png)

<h3>Unions (Обединения)</h3>

Обединенията са част от паметта, която се поделя при съхранение на две или повече променливи. Променливите, поделящи паметта могат да са от различни типове. Във всеки един момент обаче може да се ползва само една променлива от състава на обединението.

```c++
#include <iostream>

union A
{
	int a;
	char b;
	short c;
};


int main()
{
	A obj;

	obj.a = 32768;

	std::cout << obj.a << std::endl;
	std::cout << obj.b << std::endl;	
	std::cout << obj.c << std::endl;

}
```

![enter image description here](https://i.ibb.co/4m6m5Mg/union.png)

<h3>Enums (Енумерации)</h3>
Eнумерацията е отделен тип, чиято стойност е ограничена до диапазон от стойности, който може да включва няколко изрично посочени константи(енумератори). Стойностите на константите са стойности от интегрален тип, известен като основен тип на eнумерацията Eнумерацията има същия размер, представяне на стойност и изисквания за подравняване като неговия основен тип. Освен това всяка стойност на енумерацията има същото представяне като съответната стойност на основния тип.

```c++
enum <name>
{
	<element>, //0
	<element>, //1
	.
	.
	.
};

enum IceCream1
{
	vanilla, //0
	chocolate, //1
	strawberry, //2
	mango, //3
	oreo //4
};

enum IceCream2 : char
{
	vanilla, //0
	chocolate, //1
	strawberry, //2
	mango, //3
	oreo //4
};
```

<h5>Unscoped enumerations (plain enums) vs Scoped enumerations (enum class | struct)</h5>

```c++
enum class Color { red, green, blue }; // enum class
enum Animal { dog, cat, bird, human }; // plain enum 
```

- enum classes
	- енумераторите са локални за enum-a и техните стойности не се преобразуват имплицитно към други типове (another enum or int).
- Plain enums
	- енумераторите са в същия scope като enum-a и техните стойности се преобразуват имплицитно към integers и други типове.

```c++
enum Color { red, green, blue };                    // plain enum 
enum Card { red_card, green_card, yellow_card };    // another plain enum 
enum class Animal { dog, deer, cat, bird, human };  // enum class
enum class Mammal { kangaroo, deer, human };        // another enum class

void fun() {
    // examples of bad use of plain enums:
    Color color = Color::red;
    Card card = Card::green_card;

    int num = color;    // no problem

    if (color == Card::red_card) // no problem (bad)
        cout << "bad" << endl;

    if (card == Color::green)   // no problem (bad)
        cout << "bad" << endl;

    // examples of good use of enum classes (safe)
    Animal a = Animal::deer;
    Mammal m = Mammal::deer;

    int num2 = a;   // error
    if (m == a)     // error (good)
        cout << "bad" << endl;

    if (a == Mammal::deer) // error (good)
        cout << "bad" << endl;
}
```

Извод: enum class | struct трябва да се предпочитат, защото причиняват по-малко изненади, които потенциално биха могли да доведат до грешки.

<h3>Namespaces (Пространство на имената)</h3>

Пространствата от имена предоставят метод за предотвратяване на конфликти с имена.
Символите, декларирани вътре в namespace block, се поставят в наименуван scope, който не позволява да бъдат сбъркани със символи с идентични имена в други диапазони.

```c++
namespace A
{
    int i;
}
 
namespace B
{
    int i;
    int j;
 
    namespace C
    {
        namespace D
        {
            using namespace A; // all names from A injected into global namespace
 
            int j;
            int k;
            int a = i;         // i is B::i, because A::i is hidden by B::i
        }
 
        using namespace D; // names from D are injected into C
                           // names from A are injected into global namespace
 
        int k = 89; // OK to declare name identical to one introduced by a using
        int l = k;  // ambiguous: C::k or D::k
        int m = i;  // ok: B::i hides A::i
        int n = j;  // ok: D::j hides B::j
    }
}

namespace Q
{
    namespace V   	// V is a member of Q, and is fully defined within Q
    { 			 	// namespace Q::V // C++17 alternative to the lines above
        class C		// C is a member of V and is fully defined within V
		{ 
			 void m(); // C::m is only declared
		};
        void f(); // f is a member of V, but is only declared here
    }
 
    void V::C::m() // definition of V::C::m outside of the namespace (and the class body)
    {}             // enclosing namespaces are the global namespace, Q, and Q::V
}
```

<h3>Anonymous (Анонимност)</h3>

Анонимността е концепция, която позволява създаването на структури, обединение и т.н. които нямат реално име, към което да се обърнем. Съответно това идва с дадени лимитации:

- Не можем да създаваме обекти от този анонимен клас, освен глобалните такива, които се дефинират заедно с класа.
- Не можем да подаваме обекти от този клас, като аргументи на функции.

```c++
struct
{
	int a, b;
} obj; // obj е обект, който живее в scope-а в който е дефиниран (глобален в случая).

void f(obj temp) // Това дава компилационна грешка, защото obj е обект, а не тип.
{
	// stuff ...
}

int main()
{
	obj test; // Това дава компилационна грешка, защото obj е обект, а не тип.
	obj.a = obj.b = 10;
	std::cout << obj.a << ' ' << obj.b << '\n';
}
```

- Реален пример, къде би било полезно:

```c++
struct string
{
	union
	{
		struct
		{
			size_t size, capacity;
			char *str;
		};
		char data[24];
	}
}
```

<h3>Домашно</h3>

**Задача 1:** Въвежда се цяло число N и после N тригъгълника в равнината, определени от 3 точки(6 координати). Отпечатайте тригълниците сортирани по лицата им.

<h5>Input Format</h5>

На първият ред се въвежда цяло число N, на следващите N реда се въвеждат по 6 цели числа, координатите на триъгълника.

<h5>Constraints</h5>

```
1 <= N <= 1000
-100 <= xi, yi <= 100
```

<h5>Output Format</h5>

Да се принтират лицата на всички триъгълници, сортирани в нарастващ ред и разделени с един интервал.

<h5>Sample Input</h5>

```
3
0 0 1 0 0 1
7 1 4 6 0 2
0 8 5 5 5 4
```

<h5>Sample Output</h5>

```
0.5 2.5 16
```

<h5>Explanation</h5>

Първият триъгълник има лице 0.5, вторият има лице 16, а третият има лице 2.5. И в сортиран вид са 0.5, 2.5, 16.

**Задача 2:** Реализирайте структура, която моделира квадратно уравнение. Квадратното уравнение се дефинира с 3 коефициента a, b, c, които са произвилни реални числа. Напишете методи за изчисление на решенията ако има реални такива.

<h5>Input Format</h5>

На първият ред се въвеждат 3 реални числа a, b и c.

<h5>Constraints</h5>

```
-100 <= a, b, c <= 100
```

<h5>Output Format</h5>

На един ред на стандартният изход, да се изкара едно то следните три неща, в зависимост от решението на квадратното уравнение: - Няма корени -> "The equation does not have real solutions!" - Има 2 еднакви корена -> x1 = x2 = "{корен}" - Има 2 различни корена -> x1 = "{корен 1}", x2 = "{корен 2}" В последният случай нека x1 < x2.

<h5>Sample Input 0</h5>

```
1 -3 2
```

<h5>Sample Output 0</h5>

```
x1 = 1, x2 = 2
```

<h5>Explanation 0</h5>

Ако решим квадратното уравниение x^2-3x+2=0 и получаваме корените 1 и 2.

<h5>Sample Input 1</h5>

```
-60 -3 -59
```

<h5>Sample Output 1</h5>

The equation does not have real solutions!

<h5>Sample Input 2</h5>

```
1 4 4
```

<h5>Sample Output 2</h5>

```
x1 = x2 = -2
```

**Задача 3:** Да се създаде структура която представя комплексно число. Създайте функции, които събира, изваждат и умножават две комплексни числа. Създайте подходяща функция за извеждане принтиране на комплексни числа.

<h5>Input Format</h5>

На първият ред на стандартният вход на стандартният вход, ще бъдат подадени 4 цели числа a, b, c, d, коефициентите на комплексните числа(z1 = a + bi, z2 = c + di).

<h5>Constraints</h5>

```
-1000 <= a, b, c, d <= 1000
```

<h5>Output Format</h5>

На стандартният изход да се изпечатат резултатите от 3те операции събиране, изваждане и умножение на двете числа. Всеки резултат да е на нов ред.

<h5>Sample Input 0</h5>

```
6 -4 10 7
```

<h5>Sample Output 0</h5>

```
16+3i
-4-11i
88+2i
```

<h5>Sample Input 1</h5>

```
-7 0 9 0
```

<h5>Sample Output 1</h5>

```
2
-16
-63
```

<h5>Sample Input 2</h5>

```
5 0 5 5
```

<h5>Sample Output 2</h5>

```
10+5i
-5i
25+25i
```

**Задача 4:** Създайте структура описваща студент. Всеки студент се определя чрез факултетен номер, курс и средна оценка за курса. Всеки студент е в първи, втори, трети или четвърти курс. Факултетните номера винаги са петцифрени цели числа. Създайте подходящо параметризирана функция initStudent(...);, която въвежда коректни данни за студент. Да се напише функция, която принтира студент.

Създайте структура описваща група. Една група се състои от N на брой студенти. Структурата също така трябва да пази средния успех на групата. Напишете функция, която приема група и минимален успех за стипендия, и връща колко студента ще получават стипендия.

<h5>Input Format</h5>

На първият ред на стандартният вход се въвежда цяло число N, броят на студентите в групата. На следващите N реда се въвеждат факлутетен номер, курс и средна оценка, разделени с един интервал. На последният ред на входа се въвежда минималният успех за стипендия.

<h5>Constraints</h5>

```
1 <= N <= 500
10000 <= факлутетен номер < 100000
1 <= курс <= 4
2 <= оценка <= 6
```

<h5>Output Format</h5>

На стандартният изход да се изпечата две числа разделени с един интервал. Първо да се изпечата средният успех на групата и след него броят студенти, които ще получат стипендия.

<h5>Sample Input 0</h5>

```
5
38613 3 2.492
12494 3 5.568
18935 4 2.436
35935 2 4.184
28215 1 4.696
4.902
```

<h5>Sample Output 0</h5>

```
3.8752 1
```

<h5>Sample Input 1</h5>

```
10
17176 4 2.58
30502 4 3.4
10589 4 3.192
38710 3 5.984
17297 1 4.068
19393 3 4.648
40766 1 4.768
39741 4 5.272
28383 4 5.628
29548 3 3.456
5.312
```

<h5>Sample Output 1</h5>

```
4.2996 2
```