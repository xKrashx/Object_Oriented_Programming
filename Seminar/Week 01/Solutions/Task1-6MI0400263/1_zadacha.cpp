#include <iostream>
struct Point
    {
        double x;
        double y;
    };
struct Triangle 
{
    Point A;
    Point B;
    Point C;
    double area;
    
};
int main()
{
    int N;
    Triangle p;
    std::cin >> N;
    if (N < 1 && N > 1000) return -1;
    for(size_t i = 0; i < N; ++i)
    {
        
    }
}