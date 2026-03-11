#include<iostream>
using namespace std;
class player{
private:
    int health;
    int age;
    int score;
    bool alive;
public:
    int getHealth(){
        return health;
    }
    int getAge(){
        return age;
    }
    int getScore(){
        return score;
    }
    int isAlive(){
        return alive;
    }
    // this. is defining that the names is of the class
    void setHealth(int health){
       this->health =  health;
    }
    void setAge(int age){
        this->age =age;
    }
    void setScore(int score){
        this->score= score;
    }
    void setAlive(bool alive){
        this->alive= alive;
    }
};
player getMaxscorePlayer(player a, player b){
    if(a.getScore()>b.getScore()) return a;
    else return b;   // player return kar raha hai
}
int addScore(player a,player b){
    return a.getScore()+b.getScore();
}
int main(){
   player naitik; // pbject creation, statically
   player nibir; // compile time, static allocation

   player *xyz= new player; // run time, dynamic allocation
   /* M1 */ player xyzObject=*xyz;
   /* M2 */ xyz->setHealth(78);

   naitik.setAge(14);
   naitik.setScore(70);
   naitik.setHealth(80);
   naitik.setAlive(true);

   nibir.setAge(19);
   nibir.setScore(65);
   nibir.setHealth(91);
   nibir.setAlive(true);

   xyzObject.setScore(40);
   xyzObject.setAge(22);

   cout<<xyzObject.getScore()<<endl;
   cout<<xyzObject.getAge()<<endl;
   cout<<xyz->getHealth()<<endl;
   cout<<addScore(naitik,nibir)<<endl;
   //cout<< getMaxscorePlayer(naitik,nibir);
   player najnu=getMaxscorePlayer(naitik,nibir);
   cout<<najnu.getScore();
}