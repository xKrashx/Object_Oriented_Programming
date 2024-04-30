#ifndef __SHAPE_FACTORY_
#define __SHAPE_FACTORY_

#include "../Shapes/Circle.hpp"
#include "../Shapes/Rectangle.hpp"
#include "../Shapes/Triangle.hpp"
#include <type_traits>
#include <utility>

enum class ShapeType{
    Rectangle,
    Circle,
    Triangle
};

// Създаваме функция, която ще се грижи за създаването на обектите.
// Тъй като всеки конструктор има различен брой аргументи, ако просто прехвърлим
// аргументите към конструкторите ще ни се скара за различните извиквания.
// Това става, защото единият път ще извикаме за кръгът с 3 параметъра и той ще изгенерира код,
// който извиква конструкторите на всички обекти с тези 3 параметъра, което очевидно не е вярно
// и ще получим компилационна грешка.
template <typename ShapeType, typename... Args>
// Това е вградена структура, която позволява на функцията да бъде създадена, ако условието като
// първи шаблонен аргумент е вярно. Вторият шаблонен параметър е типът на връщане на функцията.
// Първият параметър е друга такава структура, която просто казва дали типът фигура,
// може да бъде конструиран от аргументите, които сме подали. 
std::enable_if_t<std::is_constructible<ShapeType, Args...>::value, Shape *>
CreateShape(Args&&... args){
    return new ShapeType(std::forward<Args>(args)...);
}

// Нужен ни е и втори вариант на функцията, ако дадена фигура, не може да бъде конструирана
// с броя параметри, които сме подали. Тук можем да хвърлим грешка или да върнем nullptr.
template <typename ShapeType, typename... Args>
std::enable_if_t<!std::is_constructible<ShapeType, Args...>::value, Shape *>
CreateShape(Args&&... args){
    return nullptr;
}

template <typename... Args>
// Подаваме аргументите като пакет, защото всеки конструктор приема различен брой.
Shape *Factory(ShapeType type, Args&&... args){

    switch (type){

        case ShapeType::Rectangle:
            return CreateShape<Rectangle>(std::forward<Args>(args)...);
        case ShapeType::Circle:
            return CreateShape<Circle>(std::forward<Args>(args)...);
        case ShapeType::Triangle:
            return CreateShape<Triangle>(std::forward<Args>(args)...);
        
        default:
            return nullptr;

    }

}

#endif