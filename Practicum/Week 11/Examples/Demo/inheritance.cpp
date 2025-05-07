// source: https://leimao.github.io/blog/CPP-Virtual-Table/
class Drug
{
public:
    Drug(int property) : m_property{property} {};
    virtual ~Drug() = default;
    virtual void foo() = 0;
    virtual void baz() = 0;
    int m_property;
};

class Fruit
{
public:
    Fruit(double size, int id, char country)
        : m_size{size}, m_id{id}, m_country{country} {};
    virtual ~Fruit() = default;
    virtual void foo() = 0;
    virtual void bar(){};
    double m_size;
    int m_id;
    char m_country;
};

class Apple : public Fruit
{
public:
    Apple(double size, int id, char country, int color)
        : Fruit{size, id, country}, m_color{color} {};
    ~Apple() = default;
    void foo() override {}
    void get_color() const {}
    virtual void apple_foo() {}
    int m_color;
};

class Orange : public Fruit, public Drug
{
public:
    Orange(double size, int id, char country, double weight)
        : Fruit{size, id, country}, Drug{4}, m_weight{weight} {};
    ~Orange() = default;
    // Overriding Fruit virtual functions.
    void foo() override {}
    void bar() override {}
    // Overriding Drug virtual functions.
    void baz() override {}
    // Orange non-virtual functions.
    void get_weight() const {}
    // Orange virtual functions.
    virtual void orange_bar() {}
    double m_weight;
};

int main()
{
    double const apple_size{1.0};
    int const apple_id{1};
    char const apple_country{'c'};
    int const apple_color{2};
    double const orange_size{0.8};
    int const orange_id{2};
    char const orange_country{'n'};
    double const orange_weight{0.6};
    Apple apple{apple_size, apple_id, apple_country, apple_color};
    Orange orange{orange_size, orange_id, orange_country, orange_weight};
}