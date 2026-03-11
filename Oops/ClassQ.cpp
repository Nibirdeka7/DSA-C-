#include<iostream>
using namespace std;
class book{
    public:
    char name;
    int price;
    int pages;
    int countBooks(int p){
        if(price<p) return 1;
        else return 0;
    }
    bool isBookPresent(char book){
        if(name == book) return true;
        else return false;
    }
};
int main(){
    book Nibir;
    Nibir.name='N';
    Nibir.price=100;
    Nibir.pages=500;

    cout<<Nibir.countBooks(200)<<endl;
    cout<<Nibir.isBookPresent('i');

}