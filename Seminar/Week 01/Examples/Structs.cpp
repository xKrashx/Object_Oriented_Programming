#include <iostream>
#include <assert.h>


struct Rational{

    int nom;
    int denom;

};

bool isValid(Rational const &rat){
    return rat.denom != 0;
}

void printRational(Rational const &rat){
    std::cout << rat.nom << " / " << rat.denom << '\n';
}

unsigned getGcd(unsigned a, unsigned b){

    if(a < b) std::swap(a, b);
        
    while(b != 0){

        int remainder = a % b;
        a = b;
        b = remainder;

    }

    return a;

}

void rationalize(Rational &rat){

    assert(isValid(rat));

    unsigned gcd = getGcd((unsigned int)rat.nom, (unsigned int)rat.denom);
    
    rat.nom /= gcd;
    rat.denom /= gcd;

}

Rational &plusEq(Rational &lhs, Rational const &rhs){

    assert(isValid(lhs) && isValid(rhs));

    lhs.nom *= rhs.denom;
	lhs.nom += rhs.nom*lhs.denom;
    lhs.denom *= rhs.denom;    

    rationalize(lhs);

    return lhs;

}

Rational plusRationals(Rational const &lhs, Rational const &rhs){

    assert(isValid(lhs) && isValid(rhs));

    Rational lhsCopy = lhs;
    plusEq(lhsCopy, rhs);

    return lhsCopy;

}

int main(){

    Rational r1{1,4};
    Rational r2{1,3};

    Rational r3 = plusRationals(r1, r2);

    printRational(r3);
    
    plusEq(r3, r1);
    
    printRational(r3);
	
}