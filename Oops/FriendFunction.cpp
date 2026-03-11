#include<bits/stdc++.h>
using namespace std;
class ComplexNumber{
public:
    int imaginary;
    int real;

    friend ComplexNumber operator +(ComplexNumber &c1,ComplexNumber &c2);
    
};
 ComplexNumber operator +(ComplexNumber &c1,ComplexNumber &c2){
            ComplexNumber c3;
            c3.imaginary=c1.imaginary+c2.imaginary;
            c3.real=c1.real+c2.real;
            return c3;
 }
int main(){
    ComplexNumber a1,a2;
    a1.imaginary=10;
    a1.real=5;
    a2.imaginary=2;
    a2.real=3;
    ComplexNumber a3=a1+a2;
    cout<<a3.real<<" + i "<<a3.imaginary;
}