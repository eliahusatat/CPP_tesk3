
#include <iostream>
#include <sstream>
#include <stdexcept>
#include "Unit.h"

namespace ariel
{
using namespace std;
class PhysicalNumber
{

private:
  Unit unit;
  long double size;

public:
  PhysicalNumber(double size, Unit unit);
  ~PhysicalNumber();
  double getsize() const { return size; }
  Unit getunit() const { return unit; }
  void setsize(double a) { size = a; }
  void setunit(Unit a) { unit = a; }

  PhysicalNumber operator+(const PhysicalNumber &pn) const;
  PhysicalNumber &operator+=(const PhysicalNumber &pn);
  PhysicalNumber operator+() const;

  PhysicalNumber operator-(const PhysicalNumber &pn) const;
  PhysicalNumber &operator-=(const PhysicalNumber &pn);
  PhysicalNumber operator-() const;

  PhysicalNumber &operator++();
  PhysicalNumber &operator--();
  PhysicalNumber operator++(int dummy_flag_for_postfix_increment)
  {
    PhysicalNumber copy = *this;
    size++;
    return copy;
  }
  PhysicalNumber operator--(int dummy_flag_for_postfix_increment)
  {
    PhysicalNumber copy = *this;
    size--;
    return copy;
  }

  bool operator>(const PhysicalNumber &pn) const;
  bool operator<(const PhysicalNumber &pn) const;
  bool operator>=(const PhysicalNumber &pn) const;
  bool operator<=(const PhysicalNumber &pn) const;
  bool operator==(const PhysicalNumber &pn) const;
  bool operator!=(const PhysicalNumber &pn) const;

  friend ostream &operator<<(ostream &os, const PhysicalNumber &pn);
  friend istream &operator>>(istream &is, PhysicalNumber &pn);
};

ostream &operator<<(ostream &os, const PhysicalNumber &pn);
istream &operator>>(istream &is, PhysicalNumber &pn);

bool CheckIsthesameGroup(const PhysicalNumber &first, const PhysicalNumber &secend);
PhysicalNumber ConvertType(PhysicalNumber &first, Unit type);

}; // namespace ariel
