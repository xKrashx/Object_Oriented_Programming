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

<h3>Домашно</h3>

**Задача 1:** Да се направи хетерогенен контейнер имитиращ папка с файлове.

Типовете файлове, които ще поддържаме са .csv, .txt, .xml.

Да се реализират методи за работа с тези файлове, като
open, save, close и print.

**Бонус:** Да се направи, така че тези методи да работят с реални файлове в директорията на проекта.