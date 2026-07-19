#include<bits/stdc++.h>
using namespace std;
class Base{
    public:
        int a;
    protected:
        int b;
    private:
        int c; 
};
class Derived : protected Base{
    public:
    void show(){
        cout << a << endl;
        cout << b << endl;
    }
};
class Derived2 : protected Derived{
    void show(){
        cout << a << endl;
        cout << b << endl;
        // cout << c << endl;
    }
};


// Multiple inheritance <--- ek derived class inherits from multiple base class
class A{
public:
    void show(){
        cout << "A show" << endl;
    }
};
class B{
public:
    void show(){
        cout << "B show" << endl;
    }
};
class C : public A, public B{
public:
    void show(){
        A::show();
        B::show();
    }
};
int main(){
    // Base b;
    // cout << b.a << endl; // only public can be accessed from main
    // // cout << b.b << endl; <--- cant access
    // // cout << b.c << endl; <--- cant access

    // Derived d;
    // cout << d.a << endl;
    // cout << d.b << endl; // error
    C obj;
    obj.show();
}