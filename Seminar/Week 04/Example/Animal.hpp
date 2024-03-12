#pragma once

class Animal{

public:
    // Enum for types
    enum class Type{
        Cat,
        Dog,
        Fish,
        Monkey
    };

    // Initializing an animal and freeing it's memory
    void Init(char const *name, unsigned age, Type type);
    void Deallocate();

    // Speak
    void Speak();

    // Setters
    void SetName(char const *name);
    void SetAge(unsigned const age);
    void SetType(Type const type);

    // Getters
    char const *GetName() const;
    unsigned GetAge() const;
    Type GetType() const;

private:
    // Fields
    char *name = nullptr;
    unsigned age = 0;
    Type type = Type::Cat;

};