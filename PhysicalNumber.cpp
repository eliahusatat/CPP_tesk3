
#include <iostream>
#include <sstream>
#include <string>
#include "PhysicalNumber.h"
#include <exception>

using namespace ariel;

  
ariel::PhysicalNumber::PhysicalNumber(double  size ,Unit unit){
 this->unit=unit;
 this->size=size;
}
ariel::PhysicalNumber::~PhysicalNumber(){

}



//PhysicalNumber &first  // Good
 bool ariel::CheckIsthesameGroup(PhysicalNumber& first,PhysicalNumber& secend )
    {

        if ((first.getunit()==M||first.getunit()==KM||first.getunit()==CM)&& (secend.getunit()==M||secend.getunit()==KM||secend.getunit()==CM)) 
              return true;
        else if ((first.getunit()==HOUR||first.getunit()==MIN||first.getunit()==SEC) && (secend.getunit()==HOUR||secend.getunit()==MIN||secend.getunit()==SEC))
                return true;  
        else if   ((first.getunit()==TON||first.getunit()==KG||first.getunit()==G) && (secend.getunit()==TON||secend.getunit()==KG||secend.getunit()==G)) 
                return true ; 
        else 
              return false  ; 
            
  }





  bool ariel::CheckIsthesameGroup( const PhysicalNumber& first,const PhysicalNumber& secend )
    {

        if (first.getunit()==M||first.getunit()==KM||first.getunit()==CM){
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
 PhysicalNumber ariel::ConvertType(PhysicalNumber& first ,Unit type)
   {
     switch (type)
     {
       case Unit::TON:
       if(first.getunit() == Unit::KG) {first.setsize(first.getsize()/1000);first.setunit(Unit::TON);}
       else if(first.getunit() == Unit::G) {first.setsize(first.getsize()/1000000);first.setunit(Unit::TON);}
       break;
       case Unit::KG:
       if(first.getunit() == Unit::TON) {first.setsize(first.getsize()*1000);first.setunit(Unit::KG);}
       else if(first.getunit() == Unit::G) {first.setsize(first.getsize()/1000);first.setunit(Unit::KG);}
       break;
       case Unit::G:
       if(first.getunit() == Unit::TON) {first.setsize(first.getsize()*1000000);first.setunit(Unit::G);}
       else if(first.getunit() == Unit::KG) {first.setsize(first.getsize()*1000);first.setunit(Unit::G);}
       break;
       case Unit::KM:
       if(first.getunit() == Unit::M) {first.setsize(first.getsize()/1000);first.setunit(Unit::KM);}
       else if(first.getunit() == Unit::CM) {first.setsize(first.getsize()/100000);first.setunit(Unit::KM);}
       break;
       case Unit::M:
       if(first.getunit() == Unit::KM) {first.setsize(first.getsize()*1000);first.setunit(Unit::M);}
       else if(first.getunit() == Unit::CM) {first.setsize(first.getsize()/100);first.setunit(Unit::M);}
       break;
       case Unit::CM:
       if(first.getunit() == Unit::KM) {first.setsize(first.getsize()*100000);first.setunit(Unit::CM);}
       else if(first.getunit() == Unit::M) {first.setsize(first.getsize()*100);first.setunit(Unit::CM);}
       break;
       case Unit::HOUR:
       if(first.getunit() == Unit::MIN) {first.setsize(first.getsize()/60);first.setunit(Unit::HOUR);}
       else if(first.getunit() == Unit::SEC) {first.setsize(first.getsize()/3600);first.setunit(Unit::HOUR);}
       break;
       case Unit::MIN:
       if(first.getunit() == Unit::HOUR) {first.setsize(first.getsize()*60);first.setunit(Unit::MIN);}
       else if(first.getunit() == Unit::SEC) {first.setsize(first.getsize()/60);first.setunit(Unit::MIN);}
       break;
       case Unit::SEC:
       if(first.getunit() == Unit::HOUR) {first.setsize(first.getsize()*3600);first.setunit(Unit::SEC);}
       else if(first.getunit() == Unit::MIN) {first.setsize(first.getsize()*60);first.setunit(Unit::SEC);}
       break;
       
     }
     return first ;
   }
// 5 =  7 + 6 
PhysicalNumber PhysicalNumber::operator+(PhysicalNumber& pn){

 bool flag  = false;
 flag = CheckIsthesameGroup(*this,pn);


 if (flag == false)__throw_runtime_error("the argoment not the same grop10");
 else {
     if (this->getunit()==pn.getunit())
     {
         return PhysicalNumber(this->getsize()+pn.getsize(),this->getunit()) ;
     }
     else
     {
         PhysicalNumber clone  (pn.getsize(),pn.getunit()) ;
         clone =ConvertType(clone,this->getunit());
         clone.size=(this->size)+(clone.getsize());
         return clone;
     }
     
 }
//return pn;
}

PhysicalNumber& PhysicalNumber::operator+=(const PhysicalNumber& pn){
   



 cout << *this << "<<<<<<<<<<<<<<<<<<<<<<" << endl;
   cout << pn << "<<<<<<<<<<<<<<<<<<<<<< shibot" << endl;
bool flag  = false;
 flag = CheckIsthesameGroup(*this,pn);
 if (flag == false)__throw_runtime_error("the argoment not the same grop2");
  
     if (this->getunit() == pn.getunit())
     {
       this->size= this->getsize() + pn.getsize();
         return *this  ;
     }
     else
     {
        PhysicalNumber shibot (pn.getsize(),pn.getunit()) ;
        
        shibot =ConvertType(shibot,this->getunit());
         this->size=(this->size)+(shibot.getsize());
         return *this;
     }
     
    }

const PhysicalNumber PhysicalNumber::operator+(){
    
    
         return *this;
     
     
 
}

PhysicalNumber  PhysicalNumber::operator-(PhysicalNumber& pn){
    
 bool flag  = false;
 flag = CheckIsthesameGroup(*this,pn);


 
 if (flag == false)__throw_runtime_error("the argoment not the same grop2");
 else {
     if (this->getunit()==pn.getunit())
     {
         return PhysicalNumber(this->getsize()-pn.getsize(),this->getunit()) ;
     }
     else
     {
        PhysicalNumber clone  (pn.getsize(),pn.getunit()) ;
         clone =ConvertType(clone,this->getunit());
         clone.size=(this->size)-(clone.getsize());
         return clone;
     }
     
 }
    }
PhysicalNumber& PhysicalNumber ::operator-=(const PhysicalNumber& pn){
    
 bool flag  = false;
 flag = CheckIsthesameGroup(*this,pn);


 
 if (flag == false)__throw_runtime_error("the argoment not the same grop3");
 else {
     if (this->getunit()==pn.getunit())
     {
         this->size=this->getsize()-pn.getsize() ;
         return *this;
     }
     else
     {
         PhysicalNumber shibot (pn.getsize(),pn.getunit()) ;
        shibot =ConvertType(shibot,this->getunit());
         this->size=(this->size)-(shibot.getsize());
         return *this;
     }
     
 }
    }


const PhysicalNumber PhysicalNumber::operator-(){
        this->size=-1*this->getsize();
         return PhysicalNumber(this->getsize(),this->getunit());
     
}
PhysicalNumber& PhysicalNumber::operator++(){
    this->size=this->getsize()+1;
    return *this;
}
PhysicalNumber& PhysicalNumber::operator--(){
    this->size=this->getsize()-1;
    return *this;
}

 bool PhysicalNumber::operator>(const PhysicalNumber& pn){
    bool flag  = false;
    // KM  = 2.1 MT = 3100

     
 flag = CheckIsthesameGroup(*this,pn);
 if (flag == false)__throw_runtime_error("the argoment not the same grop4");
 else {
     if (this->getunit()==pn.getunit()){
         if (this->getsize()>pn.getsize()){return true;}
         else return false;
     }
     else{
       PhysicalNumber  shibot (pn.getsize(),pn.getunit());
       shibot =ConvertType(shibot,this->getunit());
       if (this->getsize()>shibot.getsize()){return true;}
        else {return false;}

     }
   }

}
 bool PhysicalNumber::operator<(const PhysicalNumber& pn){
 bool flag  = false;
 


 flag = CheckIsthesameGroup(*this,pn);
 if (flag == false)__throw_runtime_error("the argoment not the same grop5");
 else {
     if (this->getunit()==pn.getunit()){
         if (this->getsize()<pn.getsize()){return true;}
         else return false;
     }
     else{
       PhysicalNumber  shibot (pn.getsize(),pn.getunit());
       shibot =ConvertType(shibot,this->getunit());
       if (this->getsize()<shibot.getsize()){return true;}
        else {return false;}

     }
   }
}
 bool PhysicalNumber::operator>=(const PhysicalNumber& pn){
 bool flag  = false;
    
 flag = CheckIsthesameGroup(*this,pn);
 if (flag == false)__throw_runtime_error("the argoment not the same grop6");
 else {
     if (this->getunit()==pn.getunit()){
         if (this->getsize()>=pn.getsize()){return true;}
         else return false;
     }
     else{
       PhysicalNumber  shibot (pn.getsize(),pn.getunit());
       shibot =ConvertType(shibot,this->getunit());
       if (this->getsize()>=shibot.getsize()){return true;}
        else {return false;}

     }
   }
}
 bool PhysicalNumber::operator<=(const PhysicalNumber& pn){
 bool flag  = false;
     
 flag = CheckIsthesameGroup(*this,pn);
 if (flag == false)__throw_runtime_error("the argoment not the same grop7");
 else {
     if (this->getunit()==pn.getunit()){
         if (this->getsize()<=pn.getsize()){return true;}
         else return false;
     }
     else{
       PhysicalNumber  shibot (pn.getsize(),pn.getunit());
       shibot =ConvertType(shibot,this->getunit());
       if (this->getsize()<=shibot.getsize()){return true;}
        else {return false;}

     }
   }
}
 bool PhysicalNumber::operator==(const PhysicalNumber& pn){
 bool flag  = false;
     
 flag = CheckIsthesameGroup(*this,pn);
 if (flag == false)__throw_runtime_error("the argoment not the same grop8");
 else {
     if (this->getunit()==pn.getunit()){
         if (this->getsize()==pn.getsize()){return true;}
         else return false;
     }
     else{
       PhysicalNumber  shibot (pn.getsize(),pn.getunit());
       shibot =ConvertType(shibot,this->getunit());
       if (this->getsize()==shibot.getsize()){return true;}
        else {return false;}

     }
   }
}

 bool PhysicalNumber::operator!=(const PhysicalNumber& pn){
 bool flag  = false;
     
 flag = CheckIsthesameGroup(*this,pn);
 if (flag == false)__throw_runtime_error("the argoment not the same grop9");
 else {
     if (this->getunit()==pn.getunit()){
         if (this->getsize()!=pn.getsize()){return true;}
         else return false;
     }
     else{
       PhysicalNumber  shibot (pn.getsize(),pn.getunit());
       shibot =ConvertType(shibot,this->getunit());
       if (this->getsize()!=shibot.getsize()){return true;}
        else {return false;}

     }
   }
}

ostream& ariel::operator<<(ostream&  out,const PhysicalNumber& pn){
 std::string unit ; 
 switch (pn.getunit())
    {
      case 0 : unit = "km" ; break;
      case 1 : unit = "m" ; break;
      case 2 : unit = "cm" ; break;
      case 3 : unit = "hour" ; break;
      case 4 : unit =  "min" ; break;
      case 5 : unit =  "sec" ; break; 
      case 6 : unit = "ton" ; break;
      case 7 : unit =  "kg" ; break;
      case 8 : unit = "g" ; break;
    }
return (out << pn.getsize()  << "["  <<  unit  << "]" );
}


istream& ariel::operator>>(istream& is ,PhysicalNumber& pn){
  std::string input ;
  is >> input ;

  string sizeInput = input.substr(0,input.find("["));
  // stringstream sizeStream(sizeInput); 
  // double tempSize ; 
  // sizeStream >> tempSize ; 
  // pn.setsize(tempSize);
  string unitInput = input.substr(input.find('[')+1,input.find(']')-2);


      cout << unitInput << endl ; 
      if(unitInput.compare("g") == 0 ) pn.setunit(G) ; 
      if(unitInput.compare("km") == 0 )  pn.setunit(KM); 
      if(unitInput.compare("m") == 0) pn.setunit(M) ; 
      if(unitInput.compare("cm") == 0 ) pn.setunit(CM); 
      if(unitInput.compare("hour") == 0) pn.setunit(HOUR) ; 
      if(unitInput.compare("min") == 0) pn.setunit(MIN) ; 
      if(unitInput.compare("sec") == 0)  pn.setunit(SEC) ;
      if(unitInput.compare("ton") == 0) pn.setunit(TON) ; 
      if(unitInput.compare("kg") == 0) pn.setunit(KG); 


   return is ; 
 }








