
#include <iostream>
#include <sstream>
#include <stdexcept>
#include "Unit.h"

namespace ariel{
using namespace std;
class PhysicalNumber {

private :
Unit unit;
double size;


public :
PhysicalNumber(double size, Unit unit);
~PhysicalNumber();

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

friend ostream& operator<<(ostream&  os,const PhysicalNumber& pn);
friend istream& operator>>(istream& is ,PhysicalNumber& pn);

 };
 ostream& operator<<(ostream&  os,const PhysicalNumber& pn);
 istream& operator>>(istream& is ,PhysicalNumber& pn);

};
