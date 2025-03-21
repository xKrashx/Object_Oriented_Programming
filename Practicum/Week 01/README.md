# Седмица 1 - Работа с изброени типове и анонимни namespace-ове

## Изглед
Ако ви се вижда твърде много работата, всичко, свързано с **Emergency** е опционално.

## Имплементация

### 1. Създаване на изброен тип
Създайте изброен тип `BuildingType` със следните стойности:
- Жилищна сграда (RESIDENTIAL)
- Болница (HOSPITAL)
- Полиция (POLICE)
- Пожарна (FIRE_STATION)

Създайте изборен тип `EmergencyLevel` със следните стойности:
- Ниско (LOW)
- Средно (MEDIUM)
- Високо (HIGH)

### 2. Помощни функции
В анонимен namespace дефинирайте:
1. Константи:
   - Минимална и максимална стойност за типа сграда
   - Масив с имената на типовете сгради и типовете 

2. Помощни функции:
   - Функция за валидация на избора
   - Функция за показване на меню

### 3. Фабрики
Създайте функция `getBuildingTypeFromUser` и `getEmergencyLevelFromUser`, които:
- Използват помощните функции от анонимния namespace
- Приемат число (или низ) от потребителя
- Валидират входа
- Връщат съответната стойност от изброения тип

### 4. Функции за принтиране
Създайте функция `printBuildingType`, която:
- Използва масива с имена от анонимния namespace
- Извежда избрания тип сграда

### 5. Главна програма
В `main` функцията:
- Извикайте фабрика функцията
- Изведете резултата

## Структура на кода

```cpp
enum BuildingType { ... }

enum EmergencyLevel { ... }

namespace {
    // Константи
    const int MIN_BUILDING_TYPE = ...;
    const char* const BUILDING_NAMES[] = ...;
    
    // Помощни функции
    bool isValidBuildingType(int choice) { ... }
    bool isValidEmergencyLevel(int choice) { ... }
    void printMenuBuilding() { ... }
    void printMenuEmergency() { ... }
}

BuildingType getBuildingTypeFromUser() { ... }
EmergencyLevel getEmergencyLevelFromUser() { ... }
void printBuildingType(BuildingType type) { ... }
void printEmergencyLevel(EmergencyLevel level) { ... }
int main() { ... }
```

## Примерен изход

```
Изберете тип сграда:
0 - Жилищна сграда
1 - Болница
2 - Полиция
3 - Пожарна
Въведете номер: 1

Избран тип: Болница

Изберете ниво на спешност:
0 - Ниско
1 - Средно
2 - Високо
Въведете номер: 2

Избрано ниво: Високо
```

## Възможни разширения

- Добавяне на повече типове сгради
- Разширяване на помощните функции
- Добавяне на функции за форматиране на изхода