
#include <iostream>
#include <sstream>
#include <stdexcept>
#include "Unit.h"

namespace ariel{
using namespace std;
class PhysicalNumber {

private :
Unit unit;
   double  size;


public :

PhysicalNumber(double size, Unit unit);
~PhysicalNumber();
double getsize(){ return size;}
Unit getunit(){return unit;}
void setsize(double a){size=a;}
void setunit(Unit a){unit=a;}
PhysicalNumber operator+(PhysicalNumber& pn);
PhysicalNumber& operator+=(const PhysicalNumber& pn);
const PhysicalNumber operator+();

PhysicalNumber operator-(PhysicalNumber& pn);
PhysicalNumber& operator-=(const PhysicalNumber& pn);
const PhysicalNumber operator-();

PhysicalNumber& operator++();
PhysicalNumber& operator--();

const bool operator>(const PhysicalNumber& pn);
const bool operator<(const PhysicalNumber& pn);
const bool operator>=(const PhysicalNumber& pn);
const bool operator<=(const PhysicalNumber& pn);
const bool operator==(const PhysicalNumber& pn);
const bool operator!=(const PhysicalNumber& pn);
friend bool CheckIsthesameGroup(PhysicalNumber first ,PhysicalNumber secend);
friend PhysicalNumber ConvertType(PhysicalNumber first ,PhysicalNumber secend);
friend ostream& operator<<(ostream&  os,const PhysicalNumber& pn);
friend istream& operator>>(istream& is ,PhysicalNumber& pn);

 };
 ostream& operator<<(ostream&  os,const PhysicalNumber& pn);
 istream& operator>>(istream& is ,PhysicalNumber& pn);

};
