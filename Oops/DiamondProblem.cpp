#include<iostream>
using namespace std;
class A{
private:
    int A_ka_private;

public:
    int A_ka_public;
};

class B:virtual public A{ // if virtual keyword is not used then there would be 2 instances of A in D
public:
    int B_ka_public;
};
class C:virtual public A{ // if virtual keyword is not used then there would be 2 instances of A in D
public:
    int C_ka_public;
    
};
class D:public B, public C{
public:
    int D_ka_public;
    void show(){
        A_ka_public;
    }
    
};
int main(){
    C c;
    

    
}