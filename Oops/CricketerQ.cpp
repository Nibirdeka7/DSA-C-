#include<iostream>
using namespace std;
class Cricketer{
    public:
    char name; 
    int age;
    int noOfTestMatches;
    int averageScore;
};
int main(){
    Cricketer virat;
    virat.name='V';
    virat.age=40;
    virat.noOfTestMatches=100;
    virat.averageScore=80;

    Cricketer dhoni;
    dhoni.name='M';
    dhoni.age=46;
    dhoni.noOfTestMatches=90;
    dhoni.averageScore=86;

    Cricketer cricketers[2]={virat, dhoni};
    
    for(int i=0;i<2;i++){
        cout<<cricketers[i].name<<endl;
        cout<<cricketers[i].age<<endl;
        cout<<cricketers[i].noOfTestMatches<<endl;
        cout<<cricketers[i].averageScore<<endl;

    }

}