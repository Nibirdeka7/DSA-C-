#include<iostream>
using namespace std;
class A{
private:
    int A_ka_private;
protected:
    int A_ka_protected;
public:
    int A_ka_public;
};

class B:public A{
public:
    int B_ka_public;
    void show(){
        A_ka_protected;
    }
};
class C:public B{
public:
    int C_ka_public;
    void show(){
        A_ka_protected;
    }
};
int main(){
    C c;
    

    
}