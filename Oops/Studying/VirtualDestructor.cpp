#include<bits/stdc++.h>
using namespace std;
class Base {
public:
    virtual ~Base(){
        cout << "Base" << endl;
    }
};
class Derived : public Base {
public:
    ~Derived(){
        cout << "Derived" << endl;
    }
};
int main(){
    Base* ptr = new Derived();
    delete ptr;
}