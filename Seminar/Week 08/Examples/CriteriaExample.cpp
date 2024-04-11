#include <iostream>

typedef bool(*FunctionPointer)(int);

class Function{

public:
    Function(FunctionPointer func){
        this -> func = func;
    }

    bool operator()(int a){
        return func(a);
    }

private:
    FunctionPointer func;

};

class Set{

public:
    Set(Function criteria): criteria(criteria){}

    void Add(int a){
        if(criteria(a) && size < MAX_SIZE) arr[size++] = a;
    }

    void Print() const{
        for(size_t i = 0; i < size; ++i)
            std::cout << arr[i] << ' ';
        std::cout << '\n';
    }

private:
    static size_t const MAX_SIZE = 100;
    Function criteria;
    size_t size = 0;
    int arr[MAX_SIZE];

};

bool IsOdd(int a){
    return a % 2;
}

bool IsEven(int a){
    return !IsOdd(a);
}

int main(){

    Set oddSet(IsOdd);
    Set evenSet(IsEven);

    oddSet.Add(1);
    oddSet.Add(2);
    oddSet.Add(3);
    oddSet.Add(4);

    evenSet.Add(1);
    evenSet.Add(2);
    evenSet.Add(3);
    evenSet.Add(4);

    std::cout << "Odd:\n";
    oddSet.Print();
    std::cout << "Even:\n";
    evenSet.Print();

    return 0;

}