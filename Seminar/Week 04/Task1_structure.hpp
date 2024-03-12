// Да се реализират функциите...

class Complex{

    public:
        int getReal() const;
        int getImag() const;

        void setReal(const int &);
        void setImag(const int &);

        void print() const;
        
    private:
        int real, imag;

};

Complex add(const Complex &, const Complex &);
Complex subtract(const Complex &, const Complex &);
Complex multiply(const Complex &, const Complex &);