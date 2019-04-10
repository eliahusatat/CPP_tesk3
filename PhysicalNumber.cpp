
#include <iostream>
#include <sstream>
#include <string.h>
#include "PhysicalNumber.h"
#include <exception>
using namespace ariel;

  
PhysicalNumber::PhysicalNumber(double  size ,Unit unit){
 this->unit=unit;
 this->size=size;
}
PhysicalNumber::~PhysicalNumber(){

}

//PhysicalNumber &first 
 bool CheckIsthesameGroup( const PhysicalNumber *first ,PhysicalNumber  secend)
    {
        if (first->getunit()==M||first.getunit()==KM||first.getunit()==CM){
            if (secend.getunit()==M||secend.getunit()==KM||secend.getunit()==CM){     return true;  }
             else {return false;}
            }
        else if (first.getunit()==HOUR||first.getunit()==MIN||first.getunit()==SEC){
             if (secend.getunit()==HOUR||secend.getunit()==MIN||secend.getunit()==SEC){     return true;  }
             else {return false;}
            }
        else  {
                 if (secend.getunit()==TON||secend.getunit()==KG||secend.getunit()==G){     return true;  }
                else {return false;}
            }
  }
 PhysicalNumber ConvertType(PhysicalNumber first ,Unit type)
   {
       if (type==M||type==CM||type==KM){
           if (type==M){
               if (first.getunit()==KM){
                  first.setsize((first.getsize()*1000) );
                  first.setunit(M);
                  return first;
               }
               else
               {
                  first.setsize((first.getsize()/100) );
                  first.setunit(M);
                  return first;               }
               
           }
           else if (type==CM)
           {
                 if (first.getunit()==KM){
                  first.setsize((first.getsize()*100000) );
                  first.setunit(CM);
                  return first;
               }
               else
                 {
                  first.setsize((first.getsize()*100) );
                  first.setunit(CM);
                  return first;            
                  }
               
                }
           
           else {
                 if (first.getunit()==M){
                  first.setsize((first.getsize()*100000) );
                  first.setunit(KM);
                  return first;
                 }
                  else
                 {
                    first.setsize((first.getsize()*100) );
                    first.setunit(KM);
                     return first;             
                    }
               
                  }
           }
       
     else  if ( type==HOUR||type==MIN||type==SEC){if (type==M){
         if (type=SEC){
               if (first.getunit()==HOUR){
                  first.setsize((first.getsize()*3600) );
                  first.setunit(SEC);
                  return first;
               }
               else
               {
                  first.setsize((first.getsize()*60) );
                  first.setunit(SEC);
                  return first;               }
               
           }
           else if (type==MIN)
           {
                 if (first.getunit()==SEC){
                  first.setsize((first.getsize()/60) );
                  first.setunit(MIN);
                  return first;
               }
               else
                 {
                  first.setsize((first.getsize()*60) );
                  first.setunit(MIN);
                  return first;            
                  }
               
                }
           
           else  {
                    if (first.getunit()==MIN){
                    first.setsize((first.getsize()/60) );
                    first.setunit(HOUR);
                    return first;
                  }
                   else
                    {
                    first.setsize((first.getsize()/3600) );
                    first.setunit(HOUR);
                     return first;             
                    }
               
                  }
         
     }
       else {if (type=TON){
               if (first.getunit()==KG){
                  first.setsize((first.getsize()*1000) );
                  first.setunit(TON);
                  return first;
               }
               else
               {
                  first.setsize((first.getsize()*1000000) );
                  first.setunit(TON);
                  return first;               }
               
           }
           else if (type==G)
           {
                 if (first.getunit()==TON){
                  first.setsize((first.getsize()/1000000) );
                  first.setunit(G);
                  return first;
               }
               else
                 {
                  first.setsize((first.getsize()/1000) );
                  first.setunit(G);
                  return first;            
                  }
               
                }
           
           else  {
                    if (first.getunit()==TON){
                    first.setsize((first.getsize()/1000) );
                    first.setunit(KG);
                    return first;
                  }
                   else
                    {
                    first.setsize((first.getsize()/1000) );
                    first.setunit(KG);
                     return first;             
                    }
               
                  }
         

       }
  
        
   
    }
   }

PhysicalNumber PhysicalNumber ::operator+(PhysicalNumber& pn){
 //   ConvertType
 //CheckIsthesameGroup
 bool flag=false;
  flag = CheckIsthesameGroup(this,pn);
 if (flag==false)throw exception("the argoment not the same grop");
 else {
     if (this->getunit()==pn.getunit()){
         this->size=(this->size)+(pn.getsize());
         return *this;
     }
     else
     {
         PhysicalNumber b (pn.getsize(),pn.getunit()) ;
         b =ConvertType(b,this->unit);
         this->size=(this->size)+(b.getsize());
         return *this;
     }
     
 }
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







