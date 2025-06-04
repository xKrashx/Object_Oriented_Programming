# Седмица 14: Шаблони (Templates) в Elder Thing

## Задача: Финализиране на проекта с използване на шаблони

Тази седмица ще завършим проекта Elder Thing, като въведем шаблони в C++. Шаблоните ще ни позволят да пишем по-гъвкав и преизползваем код, като абстрахираме типовете данни.

### 1. Шаблонни функции

- **Генерична функция за извеждане на информация:**
  Създайте шаблонна функция `printInfo`, която може да извежда информация за всякакъв тип обект от йерархията (`Entity`, `Character`, `Spell` и т.н.), стига обектът да има метод `getInfo()` или предефиниран `operator<<`.
  ```cpp
  template <typename T>
  void printInfo(const T& object) {
      // Предполагаме, че обектът има getInfo() или operator<<
      std::cout << object << std::endl; 
  }
  ```

- **Шаблонна функция с променлив брой аргументи (Variadic Template):**
  Имплементирайте шаблонна функция `logMessage`, която приема форматиращ низ и променлив брой аргументи, подобно на `printf`.
  ```cpp
  template <typename... Args>
  void logMessage(const std::string& format, Args... args) {
      // Логика за форматиране и извеждане на съобщението
      // Може да се използва std::stringstream или подобен подход
  }
  ```

### 2. Шаблонни класове

- **Генеричен контейнер `Inventory<T>`:**
  Създайте шаблонен клас `Inventory`, който може да съхранява колекция от всякакви предмети (оръжия, магии, консумативи).
  ```cpp
  template <typename T>
  class Inventory {
  private:
      T* items;
      size_t capacity;
      size_t size;
      void resize(unsigned factor); // Функция за увеличаване на капацитета при нужда
  public:
      Inventory(size_t cap);
      void addItem(const T& item);
      void removeItem(const T& item);
      bool contains(const T& item) const;
      void displayItems() const;
      // Предефиниране на operator<< и operator>> за инвентара
      template <typename U>
      friend std::ostream& operator<<(std::ostream& os, const Inventory<T>& inv) {
          // ...
      }
      // operator>> може да бъде по-сложен, например за четене от файл
  };
  ```
  - Използвайте го за инвентара на `Character`.

- **Шаблонен клас `Attribute<T>`:**
  Създайте шаблонен клас `Attribute`, който може да представлява характеристика на герой (напр. `Attribute<int>` за сила, `Attribute<double>` за магическа съпротива).
  ```cpp
  template <typename T>
  class Attribute {
  private:
      char* name;
      T value;
      T minValue;
      T maxValue;
  public:
      Attribute(const std::string& n, T val, T minVal, T maxVal);
      T getValue() const;
      void setValue(T val);
      // Предефиниране на оператори за удобство (+, -, +=, -=, <<)
      Attribute<T>& operator+=(const T& amount);
      // ... други оператори
      template <typename U>
      friend std::ostream& operator<<(std::ostream& os, const Attribute<T>& attr) {
          // ...
      }
  };
  ```
  - Интегрирайте `Attribute` в класа `Character` за неговите статистики.

### 3. Предефиниране на `operator<<` и `operator>>` с шаблони

- **За шаблонните класове:**
  Както е показано в примерите за `Inventory<T>` и `Attribute<T>`, предефинирайте `operator<<` (и евентуално `operator>>`) за вашите шаблонни класове, за да улесните работата с тях.

### 4. Специализация на шаблони (Template Specialization) - По желание

- Можете да изследвате как да специализирате шаблон, ако искате различно поведение за определен тип. Например, `Inventory<Spell>` може да има специфична логика за "подреждане" на магиите.

### Обобщение на проекта Elder Thing

След тази седмица, проектът Elder Thing ще е преминал през следните ключови етапи на ООП:
- **Седмица 5:** Класове и обекти (`Player`, `Weapon`).
- **Седмица 6:** Конструктори, деструктори, изключения (`Enemy`).
- **Седмица 7:** Константни членове, Move семантика (`Spell`).
- **Седмица 9:** Предефиниране на оператори.
- **Седмица 10:** Наследяване (`Character`, `Astrologer`, `Confessor`, йерархия на `Spell`).
- **Седмица 11:** Виртуални методи и полиморфизъм (`CombatManager`).
- **Седмица 13:** Абстрактни класове, интерфейси, фабрики (`Entity`, `MagicUser`, `Combatant`, `EntityFactory`, `Battlefield`).
- **Седмица 14:** Шаблони (Templates) за генеричност и преизползваемост.

