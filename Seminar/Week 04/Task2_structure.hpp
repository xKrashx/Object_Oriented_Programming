// Да се реализират методите на класът...

class Car{

    public:
        int getGas() const;
        int getHorsePower() const;
        int getDistanceTraveled() const;

        void setGas(const int &);
        void setHorsePower(const int &);
        void setDistanceTraveled(const int &);

        void upgrade();
        void fill();
        void drive(const int &);

    private:
        int gas, horsePower, distanceTraveled;

};