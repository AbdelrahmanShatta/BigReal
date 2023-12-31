#ifndef BIGREAL_H
#define BIGREAL_H

using namespace std;
class BigReal {
protected:  
string integer;
string decimal;
int sign;
void split(string realNumber);
//_______________________________________________________________________________________________________________________________________

public:
bool isValidReal(string realNumber);  // True if correct real
    
//_______________________________________________________________________________________________________________________________________
BigReal();
//_______________________________________________________________________________________________________________________________________
BigReal(string realNumber);
//_______________________________________________________________________________________________________________________________________
BigReal(const BigReal& other);
//_______________________________________________________________________________________________________________________________________
void operator=(BigReal& other);
//_______________________________________________________________________________________________________________________________________
void setNum(string realNumber);
//_______________________________________________________________________________________________________________________________________
int size();
//_______________________________________________________________________________________________________________________________________
BigReal& add(BigReal& n2);
//_______________________________________________________________________________________________________________________________________
BigReal& minus(BigReal& n2);
//_______________________________________________________________________________________________________________________________________
BigReal& operator+(BigReal& n2);
//_______________________________________________________________________________________________________________________________________
BigReal& operator-(BigReal& n2);
//_______________________________________________________________________________________________________________________________________
bool operator>  (BigReal& anotherReal);
//_______________________________________________________________________________________________________________________________________
bool operator<  (BigReal& anotherReal);
//_______________________________________________________________________________________________________________________________________
bool operator== (BigReal& anotherReal);

//_______________________________________________________________________________________________________________________________________
friend ostream &operator<<(ostream &os, BigReal &m);

};
#endif


