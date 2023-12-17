#include <bits/stdc++.h>
#include <cmath>
#include <iostream>
using namespace std;
#include "BigReal.h"


 void BigReal:: split(string realNumber) {
        if (realNumber.find('.') == string::npos) {
            integer = realNumber;
            decimal = "0";
        } else {
            integer = realNumber.substr(0, realNumber.find('.'));
            decimal = realNumber.substr(realNumber.find('.') + 1, realNumber.size());
        }
    }
//_______________________________________________________________________________________________________________________________________
 bool   BigReal:: isValidReal(string realNumber)  // True if correct real
    {
        auto it = realNumber.begin();
        if (*it == '+' or *it == '-') {
            it++;
        }
        bool dot = false;
        while (it != realNumber.end()) {
            if (isdigit(*it) or *it == '.') {
                if (*it == '.') {
                    if (dot == true) {
                        return false;
                    } else {
                        dot = true;
                    }
                }
                it++;

            }

            else {
                return false;
            }
        }
        return true;
    }
//_______________________________________________________________________________________________________________________________________
  BigReal::  BigReal() {  // Default constructor
        integer = "0";
        decimal = "0";
    }
//_______________________________________________________________________________________________________________________________________
 BigReal::BigReal(string realNumber) { 
        if (isValidReal(realNumber)) { // constructor
            if (realNumber[0] == '-') {
                sign = -1;
                realNumber.erase(0, 1);
            } else {
                sign = 1;
                if (realNumber[0] == '+') {
                    realNumber.erase(0, 1);
                } else if (realNumber[0] == '.') {
                    realNumber = '0' + realNumber;
                }
            }
            split(realNumber);

        } else {
            integer = "0";
            decimal = "0";
        }
    }
//_______________________________________________________________________________________________________________________________________
BigReal ::BigReal(const BigReal& other) {  // copy constructor 
        integer = other.integer;
        decimal = other.decimal;
        sign = other.sign;
    }
//_______________________________________________________________________________________________________________________________________
void BigReal :: operator=(BigReal& other) { //overloading assigment operator 
        integer = other.integer;
        decimal = other.decimal;
        sign = other.sign;
    }
//_______________________________________________________________________________________________________________________________________
void BigReal :: setNum(string realNumber) { //sets the number given to the Bigreal
        if (isValidReal(realNumber)) {
            if (realNumber[0] == '-') {
                sign = -1;
                realNumber.erase(0, 1);
            } else {
                sign = 1;
                if (realNumber[0] == '+') {
                    realNumber.erase(0, 1);
                } else if (realNumber[0] == '.') {
                    realNumber = '0' + realNumber;
                }
            }
            split(realNumber);

        } else {
            integer = "0";
            decimal = "0";
        }
    }
//_______________________________________________________________________________________________________________________________________
int  BigReal:: size()  // gets the size of the given number
    {
        return integer.size() + decimal.size();
    }
//_______________________________________________________________________________________________________________________________________
BigReal& BigReal::add(BigReal& n2) //adds the two given numbers witha fucntion then use it in the operator

 {
    string intresult = "";
        string floatresult = "";
        string int2 = n2.integer;
        string dec2 = n2.decimal;
        int difference;
        int sum;
        int carry = 0;
        int y;
        //__________________________________________________________________________________        
        // FLOAT  for decimal part 
        difference = 0;
        sum = 0;
        carry = 0;
        y = max(dec2.size(), decimal.size());
        if (y == dec2.size()) {
            difference = dec2.size() - decimal.size();
            string zeros(difference, '0');
            decimal = decimal + zeros;
        }
        if (y == decimal.size()) {
            difference = decimal.size() - dec2.size();
            string zeros(difference, '0');
            dec2 = dec2 + zeros;
        }
        for (int i = y - 1; i >= 0; i--) {
            sum = ((dec2[i] - '0') + (decimal[i] - '0') + carry) % 10;
            carry = ((dec2[i] - '0') + (decimal[i] - '0') + carry) / 10;
            char digit = sum + '0';
            floatresult = digit + floatresult;
        }
        //__________________________________________________________________________________
        // INT for integer part
        difference = 0;
        sum = 0;
        y = max(int2.size(), integer.size());
        if (y == int2.size()) {
            difference = int2.size() - integer.size();
            string zeros(difference, '0');
            integer = zeros + integer;
        }
        if (y == integer.size()) {
            difference = integer.size() - int2.size();
            string zeros(difference, '0');
            int2 = zeros + int2;
        }
        for (int i = y - 1; i >= 0; i--) {
            sum = ((int2[i] - '0') + (integer[i] - '0') + carry) % 10;
            carry = ((int2[i] - '0') + (integer[i] - '0') + carry) / 10;
            char digit = sum + '0';
            intresult = digit + intresult;
        }

        if (carry == 1) {
            intresult = '1' + intresult;
        }
        //__________________________________________________________________________________
        n2.integer = intresult;
        n2.decimal = floatresult;
        return n2; 
 }
//_______________________________________________________________________________________________________________________________________
BigReal& BigReal :: minus(BigReal& n2) //minuses the two given numbers witha fucntion then use it in the operator
{
     string intresult = "";
        string floatresult = "";
        string int2 = n2.integer;
        string dec2 = n2.decimal;
        string temp_int;
        bool nve=false;
        int difference;
        int diff;
        int borrow = 0;
        int y;
        //__________________________________________________________________________________
        // FLOAT for decimal part
        difference = 0;
        diff = 0;
        
        y = max(dec2.size(), decimal.size());
        if (y == dec2.size()) 
        {
            difference = dec2.size() - decimal.size();
            string zeros(difference, '0');
            decimal = decimal+zeros ;
        }
        if (y == decimal.size())
        {
            difference = decimal.size() - dec2.size();
            string zeros(difference, '0');
            dec2 =   dec2 + zeros;
        }
        if(*this>n2)  //bigger>smaller
        {
        for (int i = y - 1; i >= 0; i--) 
        {
           
            
            diff = ((decimal[i] - '0') - (dec2[i] - '0')+borrow) ;
            if(diff<0)
            {
                diff=((decimal[i] - '0') - (dec2[i] - '0')+borrow+10);
                borrow=-1;
                
            }
            else
            {
                borrow=0;
            }
        char digit = diff+ '0';
        
        floatresult =   digit + floatresult;
    
        }
        n2.decimal=floatresult;
        }
        //___________________________________
        else
        {
            for (int i = y - 1; i >= 0; i--) 
        {
           
            
            diff = ((dec2[i] - '0') - (decimal[i] - '0')+borrow) ;
            if(diff<0)
            {
                diff=((dec2[i] - '0') - (decimal[i] - '0')+borrow+10);
                borrow=-1;
                
            }
            else
            {
                borrow=0;
            }
        char digit = diff+ '0';
        
        floatresult =   digit + floatresult;
    
        }
        n2.decimal=floatresult;
        }
        //__________________________________________________________________________________
        // INT for integer part
        difference = 0;
        diff = 0;
        
        y = max(int2.size(), integer.size());
        if (y == int2.size()) 
        {
            difference = int2.size() - integer.size();
            string zeros(difference, '0');
            integer = zeros + integer;
        }
        if (y == integer.size())
        {
            difference = integer.size() - int2.size();
            string zeros(difference, '0');
            int2 = zeros + int2;
        }
        if(*this>n2)  //bigger>smaller
        {
            
        for (int i = y - 1; i >= 0; i--) 
        {
            
            
            diff = ((integer[i] - '0') - (int2[i] - '0')+borrow) ;
            if(diff<0)
            {
                diff=((integer[i] - '0') - (int2[i] - '0')+borrow+10);
                borrow=-1;
                
            }
            else
            {
                borrow=0;
            }
            
            
        
        char digit = diff+ '0';
        
        intresult = digit + intresult;
      
        }
        n2.integer=intresult;
        }
        //___________________________________
        else
        {
             for (int i = y - 1; i >= 0; i--) 
        {
           
            
            diff = ((int2[i] - '0') - (integer[i] - '0')+borrow) ;
            if(diff<0)
            {
                diff=((int2[i] - '0') - (integer[i] - '0')+borrow+10);
                borrow=-1;
                
            }
            else
            {
                borrow=0;
            }
            
            
        
        char digit = diff+ '0';
        
        intresult = digit + intresult;
        
        }
        n2.sign=-1;
        n2.integer=intresult;
        }
        return n2;
}
//_______________________________________________________________________________________________________________________________________
BigReal& BigReal:: operator+(BigReal& n2) { //overloading the + operator 
        
    if(this->sign==-1 and n2.sign==1) //takes into consideration the different cases of -ve and +ve
       {
        sign=sign*-1;
       return n2.minus(*this);     //if -a + b   == b-a 
       
       }
    else if(this->sign==1 and n2.sign==-1)
    {
        n2.sign=n2.sign*-1;
        return this->minus(n2);    //if a + -b   == a-b 
    }
    else if(this->sign==-1 and n2.sign==-1)
    {
        
        return this->add(n2);     //if -a + -b == -(a+b) 

        
    }
    else
    {
        return this->add(n2);     //if a + b   ==   a+b
    }
     
    }
//_______________________________________________________________________________________________________________________________________
BigReal& BigReal :: operator-(BigReal& n2) { //overloading the - operator 

    if(this->sign==-1 and n2.sign==1)//takes into consideration the different cases of -ve and +ve
    {
        n2.sign=n2.sign*-1;
        return this->add(n2); //if -a - b == -(a+b) 
    } 
    else if(this->sign==1 and n2.sign==-1)
    {   
        n2.sign=n2.sign*-1;
        return this->add(n2);  //if a - -b   ==   a+b
    }
    else if(this->sign==-1 and n2.sign==-1)
    {
        for(int i=0;i<this->integer.size();i++) //if the two numbers are zeros then sign is positive
        {
        if(this->integer[i]=='0'&& n2.integer[i]=='0')
        {
            sign=1;
        }
        }   
        return n2.minus(*this);  //if -a  -  -b   == b-a 
    }
    else{
         return this->minus(n2); //if a-b == a-b
    }
        
    }
//_______________________________________________________________________________________________________________________________________
bool BigReal :: operator>  (BigReal& anotherReal) //compares the two different objects/overloading the  > operator
{   
        string n2 = anotherReal.integer;
        string d2 = anotherReal.decimal;
        string n1 = this->integer;
        string d1 = this->decimal;
        int y = max(n1.size(), n2.size());
        if (y == n2.size()) 
        {
            int difference = n2.size() - n1.size();
            string zeros(difference, '0');
            n1 = zeros + n1 ;
        }
        if (y == n1.size())
        {
            int difference = n1.size() - n2.size();
            string zeros(difference, '0');
            n2 =   zeros+n2;
        }
        y = max(d1.size(), d2.size());
        if (y == d2.size()) 
        {
            int difference = d2.size() - d1.size();
            string zeros(difference, '0');
            d1 = d1+zeros ;
        }
        if (y == d1.size())
        {
            int difference = d1.size() - d2.size();
            string zeros(difference, '0');
            d2 = d2 + zeros;
        }
        if(anotherReal.sign==-1 && this->sign==1)
        {
            return true;
        }
        if(anotherReal.sign==1 && this->sign==-1)  //this>anothereal
        {
            return false;
        }
        if(anotherReal.sign==-1 && this->sign==-1)  
        {
            BigReal a(*this);
            a.sign=1;
            BigReal b(anotherReal);
            b.sign=1;
            return (a<b);
        }
        string num1 = n1+d1;//822>823
        string num2 = n2+d2;
        for(int i =0; i<num1.size();i++){
            if(num2[i]<num1[i]){
                return true;
            }
            else if(num2[i]>num1[i])
            {
                return false;
            }
            else if(num2[i]==num1[i])
            {
                continue;
            }
        }
        return false;
        

}
//_______________________________________________________________________________________________________________________________________
bool BigReal :: operator<  (BigReal& anotherReal){ //compares the two different objects/overloading the  < operator
        string n2 = anotherReal.integer;
        string d2 = anotherReal.decimal;
        string n1 = this->integer;
        string d1 = this->decimal;
        int y = max(n1.size(), n2.size());
        if (y == n2.size()) 
        {
            int difference = n2.size() - n1.size();
            string zeros(difference, '0');
            n1 = zeros + n1 ;
        }
        if (y == n1.size())
        {
            int difference = n1.size() - n2.size();
            string zeros(difference, '0');
            n2 =   zeros+n2;
        }
        y = max(d1.size(), d2.size());
        if (y == d2.size()) 
        {
            int difference = d2.size() - d1.size();
            string zeros(difference, '0');
            d1 = d1+zeros ;
        }
        if (y == d1.size())
        {
            int difference = d1.size() - d2.size();
            string zeros(difference, '0');
            d2 = d2 + zeros;
        }
        if(anotherReal.sign==-1 && this->sign==1)
        {
            return false;
        }
        if(anotherReal.sign==1 && this->sign==-1)  //this<anothereal
        {
            return true;
        }
        if(anotherReal.sign==-1 && this->sign==-1)  
        {
            BigReal a(*this);
            a.sign=1;
            BigReal b(anotherReal);
            b.sign=1;
            return (a>b);
        }
        string num1 = n1+d1;
        string num2 = n2+d2;
        for(int i =0; i<num1.size();i++){
            if(num2[i]>num1[i]){
                return true;
            }
            else if(num2[i]<num1[i])
            {
                return false;
            }
            else if(num2[i]==num1[i])
            {
                continue;
            }
        }
        return false;
        
        
}
//_______________________________________________________________________________________________________________________________________
bool BigReal :: operator== (BigReal& anotherReal)  //compares the two different objects
{
        string n2 = anotherReal.integer;
        string d2 = anotherReal.decimal;
        string n1 = this->integer;
        string d1 = this->decimal;
        int y = max(n1.size(), n2.size());
        if (y == n2.size()) 
        {
            int difference = n2.size() - n1.size();
            string zeros(difference, '0');
            n1 = zeros + n1 ;
        }
        if (y == n1.size())
        {
            int difference = n1.size() - n2.size();
            string zeros(difference, '0');
            n2 =   zeros+n2;
        }
        y = max(d1.size(), d2.size());
        if (y == d2.size()) 
        {
            int difference = d2.size() - d1.size();
            string zeros(difference, '0');
            d1 = d1+zeros ;
        }
        if (y == d1.size())
        {
            int difference = d1.size() - d2.size();
            string zeros(difference, '0');
            d2 = d2 + zeros;
        }
        if(this->sign!=anotherReal.sign)
        {
            return false;
        }
        string num1 = n1+d1;
        string num2 = n2+d2;
    for(int i =0; i<num1.size();i++){
            if(num2[i]>num1[i]){
                return false;
            }
            else if(num2[i]<num1[i])
            {
                return false;
            }
            else if(num2[i]==num1[i])
            {
                continue;
            }
        }
        return true;
}
//_______________________________________________________________________________________________________________________________________
 ostream&  operator<<(ostream &os, BigReal &m) //overloads the cout function;
{ 
     
    string num = m.integer + '.' + m.decimal;
        if (m.sign == -1) {
            num = '-' + num;
        }
        
    
    return os << num;
    
}