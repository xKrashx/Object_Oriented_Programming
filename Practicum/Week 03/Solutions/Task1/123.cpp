#include <iostream>

// define a class
class Person {
    private:
        int age = 0;

    public:
        void displayAge() {
            std::cout << "Age = " << age << std::endl;
        }

        void birthday() {
            age++;
        }
        void setAge(const int NewAge)
        {
            this->age = NewAge;
        }
        int getAge() const
        {
            return age;
        }
};

int main() {
    
    int NewAge;
    Person p;
    std::cin >> NewAge;
    p.setAge(NewAge);

    return 0;
}