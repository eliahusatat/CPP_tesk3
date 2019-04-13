
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
         if (type==SEC){
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
       else {if (type==TON){
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
    return first ; 
   }
// 5 =  7 + 6 
PhysicalNumber PhysicalNumber::operator+(PhysicalNumber& pn){

 bool flag  = false;
 flag = CheckIsthesameGroup(*this,pn);


 if (flag == false)__throw_runtime_error("the argoment not the same grop");
 else {
     if (this->getunit()==pn.getunit())
     {
         return PhysicalNumber(this->getsize()+pn.getsize(),this->getunit()) ;
     }
     else
     {
         PhysicalNumber clone  (pn.getsize(),pn.getunit()) ;
         clone =ConvertType(clone,this->getunit());
         this->size=(this->size)+(clone.getsize());
         return *this;
     }
     
 }
//return pn;
}

PhysicalNumber& PhysicalNumber::operator+=(const PhysicalNumber& pn){
   



 
 if (CheckIsthesameGroup(*this,pn) == false)__throw_runtime_error("the argoment not the same grop");
 else {
     if (this->getunit()==pn.getunit())
     {
       this->size=this->getsize()+pn.getsize();
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
    }

const PhysicalNumber PhysicalNumber::operator+(){
    
    
         return *this;
     
     
 
}

PhysicalNumber  PhysicalNumber ::operator-(PhysicalNumber& pn){
    
 bool flag  = false;
 flag = CheckIsthesameGroup(*this,pn);


 
 if (flag == false)__throw_runtime_error("the argoment not the same grop");
 else {
     if (this->getunit()==pn.getunit())
     {
         return PhysicalNumber(this->getsize()-pn.getsize(),this->getunit()) ;
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
PhysicalNumber& PhysicalNumber ::operator-=(const PhysicalNumber& pn){
    
 bool flag  = false;
 flag = CheckIsthesameGroup(*this,pn);


 
 if (flag == false)__throw_runtime_error("the argoment not the same grop");
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
         return *this;
     
}
PhysicalNumber& PhysicalNumber::operator++(){
    this->size=this->getsize()+1;
    return *this;
}
PhysicalNumber& PhysicalNumber::operator--(){
    this->size=this->getsize()-1;
    return *this;
}

const bool PhysicalNumber::operator>(const PhysicalNumber& pn){
    bool flag  = false;
    // KM  = 2.1 MT = 3100

     
 flag = CheckIsthesameGroup(*this,pn);
 if (flag == false)__throw_runtime_error("the argoment not the same grop");
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
const bool PhysicalNumber::operator<(const PhysicalNumber& pn){
 bool flag  = false;
 


 flag = CheckIsthesameGroup(*this,pn);
 if (flag == false)__throw_runtime_error("the argoment not the same grop");
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
const bool PhysicalNumber::operator>=(const PhysicalNumber& pn){
 bool flag  = false;
    
 flag = CheckIsthesameGroup(*this,pn);
 if (flag == false)__throw_runtime_error("the argoment not the same grop");
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
const bool PhysicalNumber::operator<=(const PhysicalNumber& pn){
 bool flag  = false;
     
 flag = CheckIsthesameGroup(*this,pn);
 if (flag == false)__throw_runtime_error("the argoment not the same grop");
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
const bool PhysicalNumber::operator==(const PhysicalNumber& pn){
 bool flag  = false;
     
 flag = CheckIsthesameGroup(*this,pn);
 if (flag == false)__throw_runtime_error("the argoment not the same grop");
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

const bool PhysicalNumber::operator!=(const PhysicalNumber& pn){
 bool flag  = false;
     
 flag = CheckIsthesameGroup(*this,pn);
 if (flag == false)__throw_runtime_error("the argoment not the same grop");
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
      case 0 : unit = "KM" ; break;
      case 1 : unit = "M" ; break;
      case 2 : unit = "CM" ; break;
      case 3 : unit = "HOUR" ; break;
      case 4 : unit =  "MIN" ; break;
      case 5 : unit =  "SEC" ; break; 
      case 6 : unit = "TON" ; break;
      case 7 : unit =  "KG" ; break;
      case 8 : unit = "G" ; break;
    }
return out << pn.getsize()  << "["  <<  unit  << "]" << endl;
}


istream& ariel::operator>>(istream& is ,PhysicalNumber& pn){
  int temp ; 
  double size ; 
  is >> size ;
  pn.setsize(size); 
  is >> temp ; 
     switch (temp)
    {
      case 0 : pn.setunit(KM); break;
      case 1 : pn.setunit(M) ; break;
      case 2 : pn.setunit(CM); break;
      case 3 : pn.setunit(HOUR) ; break;
      case 4 : pn.setunit(MIN) ; break;
      case 5 : pn.setunit(SEC) ; break; 
      case 6 : pn.setunit(TON) ; break;
      case 7 : pn.setunit(KG); break;
      case 8 : pn.setunit(G) ; break;
    } 
   return is ; 
 }








