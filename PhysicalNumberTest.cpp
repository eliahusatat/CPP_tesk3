/**
 * Examples of automatic tests for the exercise on physical numbers.
 *
 * @author Erel Segal-Halevi
 * @since 2019-02
 */


#include <iostream>


using std::cout, std::endl, std::istringstream;
#include "PhysicalNumber.h"
using ariel::PhysicalNumber, ariel::Unit;
#include "badkan.hpp"

int main() {
  badkan::TestCase testcase;
  int grade=0;
  int signal = setjmp(badkan::longjmp_buffer);
  if (signal == 0) {

    // BASIC TESTS - DO NOT CHANGE
    PhysicalNumber A(1000, Unit::KM);
    PhysicalNumber a(2, Unit::KM);
    PhysicalNumber b(300, Unit::M);
    PhysicalNumber c(2, Unit::HOUR);
    PhysicalNumber d(30, Unit::MIN);


    PhysicalNumber a1(350, Unit::M);
    PhysicalNumber a2(4, Unit::KM);
    PhysicalNumber a3(2000, Unit::CM);

    PhysicalNumber b1(45, Unit::MIN);
    PhysicalNumber b2(7, Unit::HOUR);
    PhysicalNumber b3(360, Unit::SEC);

    PhysicalNumber c1(3, Unit::TON);
    PhysicalNumber c2(70, Unit::KG);
    PhysicalNumber c3(1000, Unit::G);

    PhysicalNumber d1(-3, Unit::TON);
    PhysicalNumber d2(-70, Unit::KG);
    PhysicalNumber d3(-1000, Unit::G);

     PhysicalNumber e1(-45, Unit::MIN); 
    PhysicalNumber e2(-7, Unit::HOUR);
    PhysicalNumber e3(-360, Unit::SEC); 

    PhysicalNumber f1(-350, Unit::M);
    PhysicalNumber f2(-4, Unit::KM);
    PhysicalNumber f3(-2000, Unit::CM);

    testcase
    .setname("Basic output")
    .CHECK_OUTPUT(a, "2[km]")
    .CHECK_OUTPUT(b, "300[m]")

    .setname("Compatible dimensions")
    .CHECK_OUTPUT(b+a, "2300[m]")
    .CHECK_OUTPUT((a+=b), "2.3[km]")
    .CHECK_OUTPUT(a, "2.3[km]")
    .CHECK_OUTPUT(a+a, "4.6[km]")
    .CHECK_OUTPUT(b-b, "0[m]")
    .CHECK_OUTPUT(c, "2[hour]")
    .CHECK_OUTPUT(d, "30[min]")
    .CHECK_OUTPUT(d+c, "150[min]")

    .setname("Incompatible dimensions")
    .CHECK_THROWS(a+c)
    .CHECK_THROWS(a+d)
    .CHECK_THROWS(b+c)
    .CHECK_THROWS(b+d)

    .setname("Basic input")
    .CHECK_OK(istringstream("700[kg]") >> a)
   .CHECK_OUTPUT((a += A), "1700[kg]")

    // YOUR TESTS - INSERT AS MANY AS YOU WANT
    .setname("our test checking throws:")
    // checking throws
    .CHECK_THROWS(a1 == c2)
    .CHECK_THROWS(a2 + b3)
    .CHECK_THROWS(b2 - c1)
    .CHECK_THROWS(b1 += a3)
    .CHECK_THROWS(a1 == c2)
    .CHECK_THROWS(a2 + b2)
    .CHECK_THROWS(b1 - c3)
    .CHECK_THROWS(b1 -= a1)
    .CHECK_THROWS(a2 == c2)
    .CHECK_THROWS(a3 + b1)
    .CHECK_THROWS(b2 - c2)
    .CHECK_THROWS(b1 += c2)
    
    .CHECK_THROWS(b1 < c3)
    .CHECK_THROWS(b1 > a1)
    .CHECK_THROWS(a2 == c2)
    .CHECK_THROWS(a3 != b1)
    .CHECK_THROWS(b2 >= c2)
    .CHECK_THROWS(b1 <= c2)


    .setname("our test checking output:")
    
    .CHECK_OUTPUT(a1, "350[m]")
    .CHECK_OUTPUT(a2, "4[km]")
    .CHECK_OUTPUT(a3, "2000[cm]")

    .CHECK_OUTPUT(b1, "45[min]")
    .CHECK_OUTPUT(b2, "7[hour]")
    .CHECK_OUTPUT(b3, "360[sec]")

    .CHECK_OUTPUT(c1, "3[ton]")
    .CHECK_OUTPUT(c2, "70[kg]")
    .CHECK_OUTPUT(c3, "1000[g]")


    .CHECK_OUTPUT(a1+a2, "4350[m]")
    .CHECK_OUTPUT((a2+=a1), "4.35[km]")
    .CHECK_OUTPUT(a2, "4.35[km]")
    .CHECK_OUTPUT(a2-a1, "4[km]")
    .CHECK_OUTPUT(b1-b1, "0[min]")

    .CHECK_OUTPUT(c3, "1000[g]")
    .CHECK_OUTPUT(b2, "7[hour]")
    .CHECK_OUTPUT(b1-b3, "39[min]")
   .CHECK_OUTPUT((b1-=b3), "39[min]")
    .CHECK_OUTPUT((c1+=c2), "3.07[ton]")
   .CHECK_OUTPUT(a1, "350[m]")
   .CHECK_OUTPUT(b-b, "0[m]")

   .CHECK_OUTPUT((c1>c2), "1")
   .CHECK_OUTPUT((c3<c2) ,"1")
   .CHECK_OUTPUT((c1<c3), "0")
   .CHECK_OUTPUT((b1<=b2), "1")
   .CHECK_OUTPUT((b2>=b3), "1")
   .CHECK_OUTPUT((b1==b2), "0")
   .CHECK_OUTPUT((a1==a2), "0")
   .CHECK_OUTPUT((c1==c2), "0")
   .CHECK_OUTPUT((c1==c1), "1")
   .CHECK_OUTPUT((c1!=c3), "1")
   .CHECK_OUTPUT((c1!=c1), "0")
    .CHECK_OUTPUT((a1!=a2), "1")
   .CHECK_OUTPUT((a!=b), "1")
    .CHECK_OUTPUT((b1==b2), "0")
    .CHECK_OUTPUT((b1!=b3), "1")
    




   
    .CHECK_OUTPUT(d, "30[min]")
    .CHECK_OUTPUT(d+c, "150[min]")
    .CHECK_OK(cout << a << " <<<<<<<<<< " << b << endl)
   .CHECK_OUTPUT(b+a, "2600[m]")
   .CHECK_OUTPUT((a+=b), "2.6[km]")
   .CHECK_OUTPUT(a, "2.6[km]")
   .CHECK_OUTPUT(a+a, "5.2[km]")
    .CHECK_OUTPUT(b-b, "0[m]")
    .CHECK_OUTPUT(c, "2[hour]")
    .CHECK_OUTPUT(d, "30[min]")
    .CHECK_OUTPUT(d+c, "150[min]")
   .CHECK_OUTPUT(b+a, "2900[m]")
   .CHECK_OUTPUT((a+=b), "2.9[km]")
   .CHECK_OUTPUT(a, "2.9[km]")
   .CHECK_OUTPUT(a+a, "5.8[km]")
    .CHECK_OUTPUT(b-b, "0[m]")
    .CHECK_OUTPUT(c, "2[hour]")
    .CHECK_OUTPUT(d, "30[min]")
    .CHECK_OUTPUT(d+c, "150[min]")





      .print(cout, /*show_grade=*/false);
      grade = testcase.grade();
    } else {
      testcase.print_signal(signal);
      grade = 0;
    }
    cout <<  "*** Grade: " << grade << " ***" << endl;
    return grade;
}
