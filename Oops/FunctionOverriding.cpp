#include<bits/stdc++.h>
using namespace std;
class A{ // base class
public:
     //int abc;
    virtual void show(){
        cout<<"A ka Show"<<endl;
    }
};
class B: public A{ // derived class
public:
     void show(){
        cout<<"B ka Show"<<endl;
    }
};
class C: public B{ // derived class
public:
     void show(){
        cout<<"C ka Show"<<endl;
    }
};
int main(){
    A *a;
    B *b;
    b=new C;
    b->show();

}