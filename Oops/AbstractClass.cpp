#include<bits/stdc++.h>
using namespace std;
class A{ // base class
public:
    int abc;
    virtual void countMileage()=0;
    virtual void countSpeed()=0;
};
class B: public A{ // derived class
public:

    void countMileage(){
        cout<<"Mileage count hoga"<<endl;
    }
    void countSpeed(){
        cout<<"Speed count hoga"<<endl;
    }
};

int main(){ 
    B b;
    b.countMileage();
}