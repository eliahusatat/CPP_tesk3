
#include <iostream>
#include <sstream>
#include <string.h>
#include "PhysicalNumber.h"
using namespace ariel;

  
PhysicalNumber::PhysicalNumber(double size ,Unit unit){
 this->unit=unit;
 this->size=size;
}
PhysicalNumber::~PhysicalNumber(){

}

PhysicalNumber PhysicalNumber ::operator+(PhysicalNumber& pn){
return pn;
}

PhysicalNumber& PhysicalNumber ::operator+=(const PhysicalNumber& pn){
    return *this;
    }

const PhysicalNumber PhysicalNumber::operator+(){
    PhysicalNumber a(2, Unit::KM);
    return  a;
}

PhysicalNumber  PhysicalNumber ::operator-(PhysicalNumber& pn){
       PhysicalNumber a(2, Unit::KM);
    return  a;
    }
PhysicalNumber& PhysicalNumber ::operator-=(const PhysicalNumber& pn){
    return *this;
    }
const PhysicalNumber PhysicalNumber::operator-(){
       PhysicalNumber a(2, Unit::KM);
    return  a;
}
PhysicalNumber& PhysicalNumber::operator++(){
    return *this;
}
PhysicalNumber& PhysicalNumber::operator--(){
    return *this;
}

const bool PhysicalNumber::operator>(const PhysicalNumber& pn){
return false;
}
const bool PhysicalNumber::operator<(const PhysicalNumber& pn){
return false;
}
const bool PhysicalNumber::operator>=(const PhysicalNumber& pn){
return false;
}
const bool PhysicalNumber::operator<=(const PhysicalNumber& pn){
return false;
}
const bool PhysicalNumber::operator==(const PhysicalNumber& pn){
return false;
}

const bool PhysicalNumber::operator!=(const PhysicalNumber& pn){
return false;
}

 ostream& ariel::operator<<(ostream&  os,const PhysicalNumber& pn){
return os<<" " ;
}
 istream& ariel::operator>>(istream& is ,PhysicalNumber& pn){
return is;
}







