#include <iostream>
#include <cstddef>
#include <cmath>

struct Point{
    double x, y;
};

struct Triangle{
    Point A, B, C;
    double area;
};

double FindDistance(Point const &A, Point const &B){
    return sqrt((A.x - B.x) * (A.x - B.x) + (A.y - B.y) * (A.y - B.y));
}

void FindArea(Triangle &trie){

    double AB, AC, BC;
    AB = FindDistance(trie.A, trie.B);
    AC = FindDistance(trie.A, trie.C);
    BC = FindDistance(trie.B, trie.C);

    double halfPeri = (AB + AC + BC) / 2;

    trie.area = sqrt(halfPeri * (halfPeri - AB) * (halfPeri - AC) * (halfPeri - BC));

}

void Sort(Triangle *tries, size_t const size){

    for(size_t i = 0; i < size - 1; ++i){

        size_t minIndex = i;

        for(size_t j = i + 1; j < size; ++j)
            if(tries[i].area > tries[j].area)
                minIndex = j;
        
        if(i != minIndex) std::swap(tries[i], tries[minIndex]);

    }

}

int main(){

    size_t n;
    std::cin >> n;

    Triangle *tries = new(std::nothrow) Triangle[n];
    if(!tries){

        std::cout << "Memory error\n";
        return -1;

    }

    for(size_t i = 0; i < n; ++i){

        std::cin >> tries[i].A.x >> tries[i].A.y
                >> tries[i].B.x >> tries[i].B.y
                >> tries[i].C.x >> tries[i].C.y;
        FindArea(tries[i]);

    }

    Sort(tries, n);

    for(size_t i = 0; i < n; ++i)
        std::cout << tries[i].area << ' ';
    std::cout << '\n';

    delete[] tries;

    return 0;

}