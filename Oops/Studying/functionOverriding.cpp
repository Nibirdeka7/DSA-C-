#include<bits/stdc++.h>
using namespace std;
class Base{
public:
    virtual void show(){
        cout << "Base ka show";
    }
};
class Derived: public Base{
public:
    void show(){
        cout << "Derived ka show";
    }
};
int main(){
    Derived d1;
    Base* ptr;
    ptr = &d1;
    ptr->show();
}