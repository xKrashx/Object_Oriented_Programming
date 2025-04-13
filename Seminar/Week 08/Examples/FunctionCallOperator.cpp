// An object of this type represents a linear function of one variable a*x + b.
struct Linear
{
    double a, b;

    double operator()(double x) const
    {
        return a * x + b;
    }
};

int main()
{
    Linear f{2, 1};  // Represents function 2x + 1.
    Linear g{-1, 0}; // Represents function -x.
    // f and g are objects that can be used like a function.

    double f0 = f(0);
    double f1 = f(1);

    double g0 = g(0);
}