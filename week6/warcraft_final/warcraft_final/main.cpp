//
//  main.cpp
//  warcraft_final
//
//  Created by 吴昊 on 2018/7/9.
//  Copyright © 2018年 Hao Wu. All rights reserved.
//
#include <iostream>
#include <string>
#include<vector>
#include <cstdio>
using namespace std;

enum Knight_name{dragon, ninja,iceman,lion,wolf};
enum Weapon_name{sword,bomb,arrow};
string Knight[5]={"dragon", "ninja","iceman","lion","wolf"};
Knight_name Order[2][5]={{iceman,lion,wolf,ninja,dragon},{lion,dragon,ninja,iceman,wolf}};

string Color[2] = {"red","blue"};
string Weapons_[3] = {"sword","bomb","arrow"};

int Attack_[5];
int Loyal_reduce;
int Hour,Minute;
int Total_Minutes;
int Lif_make[5];
int arrow_attack;
void Print_time(){ // print the time
    cout.width(3); cout.fill('0');
    cout<<Hour<<':'; cout.width(2);
    cout<<Minute<<' ';
}

class City;
class Command;
class Weapon{
private:
    int name, sword_attack, arrow_usetime;
public:
    Weapon(int i, int satt):name(i), sword_attack(satt), arrow_usetime(3){};
    bool sword_dull(){
        sword_attack = int(sword_attack * 0.8);
        return sword_attack;
    }
    int &usetime(){return arrow_usetime;}
    int sw_atk(){return sword_attack;}
};

class Warrior{
private:
    int Num, Life, Attack, Loyal, Step, l_life;
    Knight_name name;
    double Morale;
    City* City_Belong_to;
    Command *Command_Belong_to;
    bool If_win, If_kill;
    Weapon* weapon[3];
public:
    Warrior(int n, Knight_name &name_, int &life, int &t_life,Command *COMD){
        Num=n; name=name_; Life=life; Attack=Attack_[name]; Step=0; l_life=0;
        weapon[0]=NULL; weapon[1]=NULL;weapon[2]=NULL;
        switch(name){
            case dragon:
            case iceman: weapon[Num%3]=new Weapon(Num%3, int(Attack_[name]*0.2)); break;
            case ninja:
                weapon[Num %3] = new Weapon(Num%3, int (Attack_[name]*0.2));
                weapon[(Num+1)%3] = new Weapon((Num+1)%3, int (Attack_[name]*0.2));break;
            default: break;
    }
        if (weapon[sword]) if(!weapon[sword]->sw_atk()) weapon[sword]=NULL;
        Morale = double(t_life)/double(Life);
        Loyal = t_life; If_win =false; If_kill=false;
        City_Belong_to = NULL; Command_Belong_to=COMD;
        cout<<Knight[name]<<' '<<Num<<" born\n";
        if (name == dragon){
            cout<< "Its morale is";
            cout.precision(2);
            cout<<fixed<<Morale<<endl;
        }
        if (name==lion){cout<<"Its loyalty is "<<Loyal<<endl;}
    }
    bool & IF_win(){return If_win;}
    bool& IF_kill(){return If_kill;}
    int life(){return Life;}
    bool Minute_5();
    void Minute_10(bool);
    void Minute_30(int);
    voide Be_shot();
    
};

    



int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
