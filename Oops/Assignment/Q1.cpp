#include<bits/stdc++.h>
using namespace std;
class Date{
private:
    int date;
    int month;
    int year;
public:
    Date(int d,int m,int y){
        date=d;
        month=m;
        year=y;
    }
    int getDate(){
        return date;
    }
    int getMonth(){
        return month;
    }
    int getYear(){
        return year;
    }
    void setDate(int d){
        date=d;
    }
    void setMonth(int m){
        month=m;
    }
    void setYear(int y){
        year=y;
    }
    void CompareDates(Date &other){
        if(date==other.date && month==other.month && year==other.year)
        cout<<"Equal"<<endl;
        else cout<<"Not equal";
    }
    
};
int main(){
    Date date1(29,01,2025);
    Date date2(29,01,2025);
    date1.CompareDates(date2);
}