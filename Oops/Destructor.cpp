#include<bits/stdc++.h>
using namespace std;
class Bike{
    public: 
        int tyreSize;
        int engineSize;
        Bike(int tyreSize, int engineSize){
            this->tyreSize=tyreSize;
            this->engineSize=engineSize;
            cout<<"Constructor is called"<<endl;
        }
       // destructor , it is called after the scope of an object
       ~Bike(){
            cout<<"Destructor is called"<<endl;
       }
};
int main(){
    Bike tvs(12,150);
    Bike honda(15,200);
    Bike royalEnfield(20,250);

    cout<<tvs.tyreSize<<" "<<tvs.engineSize<<endl;

    bool flag=true;
    if(flag==true){
        Bike bmw(8,1000);
        cout<<bmw.tyreSize<<" "<<bmw.engineSize<<endl;

    }
    cout<<honda.tyreSize<<" "<<honda.engineSize<<endl;
    cout<<royalEnfield.tyreSize<<" "<<royalEnfield.engineSize<<endl;


}