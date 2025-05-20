# Седмица 13: Полиморфизъм и абстрактни класове в Elder Thing

## Задача: Разширена система за магически способности и същества

За тази седмица ще разширим света на Elder Thing, като имплементираме напреднали концепции на ООП:
полиморфизъм, абстрактни класове, интерфейси, фабрики и виртуални функции.

### 1. Интерфейси и абстрактни класове

#### Интерфейс MagicUser
- Създайте интерфейс с чисти виртуални функции:
  ```cpp
  class MagicUser {
  public:
      virtual void castSpell(int spellIndex, Character* target) = 0;
      virtual bool canCastSpell(const Spell* spell) const = 0;
      virtual double calculateMagicPower() const = 0;
      virtual ~MagicUser() = default;
  };
  ```

#### Интерфейс Combatant
- Създайте интерфейс:
  ```cpp
  class Combatant {
  public:
      virtual void attack(Character* target) = 0;
      virtual void defend() = 0;
      virtual double calculateDamage() const = 0;
      virtual ~Combatant() = default;
  };
  ```

#### Абстрактен базов клас Entity
- Добавете чисти виртуални функции:
  - `virtual void updateState() = 0;`
  - `virtual EntityType getType() const = 0;`
  - `virtual void acceptVisitor(IEntityVisitor* visitor) = 0;`

### 2. Полиморфна йерархия на класовете

#### Наследници на Entity
- `Character` - Сега наследник на `Entity` и имплементира `Combatant`
- `ElderBeing` - Нов клас, наследяващ `Entity` с уникални способности
  - `God` - Наследява `ElderBeing` и имплементира `MagicUser`
  - `DemiGod` - Наследява `ElderBeing` и имплементира `Combatant`

#### Специализирани герои
Обновете съществуващите класове да използват новата йерархия:
- `Astrologer` наследява `Character` и имплементира `MagicUser`
- `Confessor` наследява `Character` и имплементира `MagicUser`
- Добавете нов клас `Warrior` наследяващ само `Character`

### 3. Множествено наследяване

Създайте клас, демонстриращ множествено наследяване:
- `Recluse` - наследява `Astrologer` и `Warrior` (решете проблема с "диамантеното наследяване")

### 4. Виртуални методи и runtime полиморфизъм

Имплементирайте runtime полиморфизъм за всички класове:
- Виртуални методи за атака, защита, кастване на магии
- Виртуални конструктори използвайки `clone()`
- Подходящи `override` спецификации за всички методи

### 6. Шаблон "Фабрика" (Factory Method)

Имплементирайте абстрактна фабрика и наследници:
```cpp
class EntityFactory {
public:
    virtual Entity* createEntity() const = 0;
    virtual ~EntityFactory() = default;
};

class CharacterFactory : public EntityFactory {...};
class GodFactory : public EntityFactory {...};
// Още конкретни фабрики
```

### 7. Полиморфни контейнери

- Създайте клас `Battlefield`, който съхранява колекция от полиморфни обекти:
  ```cpp
  class Battlefield {
      Entity** entities;
      size_t entityCount;
      size_t capacity;
  public:
      void addEntity(Entity* entity);
      void removeEntity(Entity* entity);
      void applyVisitorToAll(IEntityVisitor* visitor);
      // Други функционалности
  };
  ```

### 8. Демонстрация в main.cpp

Създайте програма, която демонстрира всички концепции:
- Използва фабрики за създаване на различни герои и същества
- Демонстрира полиморфизъм чрез виртуални методи
- Прилага посетители върху различни типове обекти
- Показва множественото наследяване
- Използва полиморфен контейнер за управление на бойно поле

### Изисквания за имплементация
- Управление на паметта чрез Rule of Five
- Използвайте `override` за всички предефинирани виртуални функции
- Имплементирайте виртуални деструктори за класовете, от които се наследява