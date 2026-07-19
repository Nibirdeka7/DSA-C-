#include<bits/stdc++.h>
using namespace std;
class Base {
public:
    virtual void show(){
        cout << "Base ka show" << endl;
    }
};
class Derived : public Base {
public:
    void show(){
        cout << "Derived ka show" << endl;
    }
};
int main(){
    Derived d;
    Base* ptr;
    ptr = &d;
    ptr->show();
}