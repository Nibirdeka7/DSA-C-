#include<iostream>
using namespace std;
class Gun{
public:
    int ammo;
    int damage;
    int scope;
};
class player{
private:
     class Helmet{
        int hp;
        int level;
    public:
        int setHp(int hp){
            this->hp = hp;
        }
        int setLevel(int level){
            this->level=level;
        }
        int getHp(){
            return hp;
        }
        int getLevel(){
            return level;
        }
    };
    int health;
    int age;
    int score;
    bool alive;
    Gun gun;
    Helmet helmet;

   

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
    Gun getGun(){
        return gun;
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
    void setGun(Gun gun){
        this->gun = gun;
    }
    void setHelmet(int level){
        Helmet *helmet=new Helmet; // dynamic alloc
        helmet->setLevel(level);
        int health = 0;

        if(level == 1)
             health=25;
        else if(level == 2)
             health=50;
        else if(level == 3)
             health=100;
        else
            cout<<"Error : invalid level!!";
        
        helmet->setHp(health);
        this->helmet=*helmet;
    }

    Helmet getHelmet(){
        return helmet; 
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
   player nibir;

   Gun akm;
   akm.ammo=100;
   akm.damage=50;
   akm.scope=2;

   naitik.setAge(14);
   naitik.setScore(70);
   naitik.setHealth(80);
   naitik.setAlive(true);
   naitik.setGun(akm);
   naitik.setHelmet(2);

   Gun awm;
   awm.ammo=15;
   awm.damage=150;
   awm.scope=8;

   nibir.setAge(19);
   nibir.setScore(65);
   nibir.setHealth(91);
   nibir.setAlive(true);
   nibir.setGun(awm);
   nibir.setHelmet(3);

   Gun gun123 = nibir.getGun();
   cout<<gun123.damage<<endl;
   cout<<gun123.ammo<<endl;
   cout<<gun123.scope<<endl;
  
   //cout<<addScore(naitik,nibir)<<endl;
   //cout<< getMaxscorePlayer(naitik,nibir);
//    player najnu=getMaxscorePlayer(naitik,nibir);
//    cout<<najnu.getScore();
}