#include<bits/stdc++.h>
using namespace std;
class Bike{
    public: 
        int tyreSize;
        int engineSize;
        // Bike(int tyreSize, int engineSize){
        //     this->tyreSize=tyreSize;
        //     this->engineSize=engineSize;
        //     cout<<"Constructor is called"<<endl;
        // }

        // initialisation list
        Bike(int ts,int es):tyreSize(ts),engineSize(es){}
};
int main(){
    Bike tvs(12,150);
    Bike honda(15,200);
    Bike royalEnfield(20,250);

    cout<<tvs.tyreSize<<" "<<tvs.engineSize<<endl;
    cout<<honda.tyreSize<<" "<<honda.engineSize<<endl;
    cout<<royalEnfield.tyreSize<<" "<<royalEnfield.engineSize<<endl;

}