<h1>Колекции от обекти в полиморфна йерархия. Factory pattern. Шаблони.</h1>

### Задача 1 
Да се имплементира метод read(istream& in) за фигурите от Week10, който да чете съответната фигура от in и да се имплементира оператор>> за FigureCollection, който при вход приема първо типа на фигурата(Square, Triangle, etc.), а после съответните аргументи за създаване на фигурата.
Да се имплементират операторите:
- operator += с Figure* - Да добавя елемент от тип Figure*
- operator * с цяло число - да се копира съдържанието на вектора в самия него n пъти. 

Примерен вход и изход:
```
Enter number of Figures: 2
Enter type of Figure: Triangle
Enter А: 0 3
Enter B: 4 0
Enter C: 0 0
Succesfully read the Triangle
Enter type of Figure: Square
Enter А: 0 3
Enter B: 4 0
Enter C: 0 0
Enter D: 4 3
Succesfully read the Square
```