#include "farction.hpp"
#include <iostream>

    int findGCD(int a, int b) {
        if (b == 0)
            return a;
            return findGCD(b, a % b);
    }

    int Fraction::getNum()const{
        return this->num;
    }
    int Fraction::getDenum() const{
        return this->denum;
    }
    double Fraction::value() const{
        return (num*1.0/denum*1.0);
    }
    void Fraction::setNum(int num){
        this->num = num;
    }
    void Fraction::setDenum(int denum){
        if(denum != 0)this->denum = denum;
        else std::cout<<"ne";
    }
    void Fraction::add(const Fraction &other){
        if(this->denum == other.denum){
            this->num += other.num;
        }
        else{
            this->num = this->num*other.denum + other.num*this->denum;
            this -> denum = this->denum*other.denum;
        }
        this->reduce();
    }
    void Fraction::subtract(const Fraction &other){
        if(this->denum == other.denum){
            this->num -= other.num;
        }
        else{
            this->num = this->num*other.denum - other.num*this->denum;
            this -> denum = this->denum*other.denum;
        }
        this->reduce();
    }
    void Fraction::divide(const Fraction &other){
        this->num *=other.denum;
        this->denum/=other.num;
        this->reduce();
    }
    void Fraction::mult(const Fraction &other){
        this->num *= other.num;
        this->denum*=other.denum;
        this->reduce();
    }
    void Fraction::reverse(){
        std::swap(this->denum,this->num);
    }
    bool Fraction::compare(const Fraction &other)const{
        if(this->value()>other.value())return true;
        return false;
    }
    void Fraction::print(){
        std::cout<<this->num<<'/'<<this->denum;
    } 
    void Fraction::reduce(){
        int denom;
        denom = findGCD(this->num,this->denum);
        this->num/=denom;
        this->denum/=denom;
    }
