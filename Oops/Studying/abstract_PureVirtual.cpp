#include<bits/stdc++.h>
using namespace std;
class Animal{
public:
    virtual void makeSound() = 0;
};
void Animal::makeSound(){
    cout << "Animal Makes sound" << endl;
}
class Dog : public Animal{
public:
    void makeSound(){
        Animal::makeSound();
        cout << "Dog barks";
    }
};
int main(){
    Dog d;
    d.makeSound();
}