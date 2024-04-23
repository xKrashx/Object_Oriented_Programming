# Задачи за наследяване

## Задача 
Да се реализира клас `Point`, който има за член-данни - `x` и `y` координати на точката.
Да се напишат: 
- подходящи конструктори;
- `Get/SetX/Y` - функции за достъп за член-данните (селектори и мутатори);
- `Print` - метод за отпечатване по подаден поток;
- `DistanceTo` - метод за намиране на разстоянието до точка подадена като параметър.

```cpp
class Point {
public:
    Point();
    Point(double x, double y);

    double GetX() const;
    double GetY() const;

    void SetX(double x);
    void SetY(double y);

    void Print(std::ostream& os = std::cout) const;

    double DistanceTo(const Point& other) const;

private:
    double x; 
    double y; 
};

Point::Point() {
    // TODO: Implement default constructor
}

Point::Point(double x, double y) {
    // TODO: Implement constructor with parameters
}

double Point::GetX() const {
    // TODO: Implement GetX method
}

double Point::GetY() const {
    // TODO: Implement GetY method
}

void Point::SetX(double x) {
    // TODO: Implement SetX method
}

void Point::SetY(double y) {
    // TODO: Implement SetY method
}

void Point::Print(std::ostream& os) const {
    // TODO: Implement Print method
}

double Point::DistanceTo(const Point& other) const {
    // TODO: Implement DistanceTo method
}
```

Да се реализира клас `Triangle`, който има член-данни 3 точки.
Да се напишат:
- конструктор с параметри;
- `GetPerimeter` - метод за намиране на периметъра на триъгълника;
- `GetArea` - метод за намиране на лице по Херонова формула;
- `Print` - метод за подходящо извеждане на данните на триъгълника по подаден поток.

Да се реализира клас `Quadrilateral`, който описва четириъгълник с член-данни 4 точки.
Да се напишат: 
- подходящи конструктори;
- `GetArea`, `GetPerimeter` - методи за намиране на периметър и лице;
- `Print` - метод за подходящо извеждане на данните на четириъгълника по подаден поток. 

Упътване: Лицето на произволен изпъкнал четириъгълник може да намерите като използвате помощния клас за триъгълник, разделяйки го на два триъгълника спрямо единия диагонал и събирайки тези две лица.

Да се реализира клас `Trapezoid`, описващ трапец и клас `Parallelogram`, описващ успоредник. Те са наследници на клас `Quadrilateral`. 
Да се реализира клас `Rhombus`, описващ ромб, клас `Rectangle`, описващ правоъгълник и клас `Square`, описващ квадрат. Те са наследници на клас `Parallelogram`. 
За всички тях да се напишат: 
- подходящи конструктори;
- където е необходимо, собствени реализации на методите `Print`, `GetArea`, `GetPerimeter`.
### Схема на йерархията:
<br>![](https://github.com/xKrashx/Object_Oriented_Programming/blob/main/Practicum/Week%2009/img/Hierarchy.png?raw=true)

### ***Забележки:*** 
- Помислете за неточността при сравнението за равенство на числата с плаваща точка.
- Да се използват познатите формули за намиране на лице за съответните фигури, а не разделянето на два триъгълника.
- Помислете за лесен начин за намиране на височините на необходимите места, както е показано на примера с трапеца по-долу:
<br>![](https://github.com/xKrashx/Object_Oriented_Programming/blob/main/Practicum/Week%2009/img/Height.png)


