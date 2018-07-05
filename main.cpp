//
//  main.cpp
//  warcraft
//
//  Created by 吴昊 on 2018/7/4.
//  Copyright © 2018年 Hao Wu. All rights reserved.
//

#include <iostream>
#include <stdio.h>
#include <string>
#include <iomanip>
using namespace std;

class headquarters{
private:
    int totalhealth;
    int count;
    int blueorred;
    int Order[5];
    int warriorNum[5];
    string headquartersname;
    string warriorname[5];
    int warriorvalue[5];
public:
//    initialize the class headquarters
    headquarters(const int thetotalhealth, const int theblueorred, const int *thewarriorvalue, const string *theheadquartersname, const string *thewarriorname,const int *order);
    int getHealth(){return totalhealth;}
    int getWarriorvalue(int position) {return warriorvalue[position];}
    void print(int time, int position);

};

headquarters::headquarters(const int thetotalhealth, const int theblueorred, const int *thewarriorvalue, const string *theheadquartersname, const string *thewarriorname, const int *order){
    count =0;
    totalhealth = thetotalhealth;
    blueorred=theblueorred;
    headquartersname = theheadquartersname[blueorred];
    for (int i=0; i<5;i++){
        warriorNum[i] = 0;
        warriorname[i] = thewarriorname[order[i]];
        warriorvalue[i] = thewarriorvalue[order[i]];
    }
}

void headquarters::print(int time, int position){
    count++;
    warriorNum[position]++;
    cout<< setfill('0') <<setw(3)<<time<<" "<<headquartersname<<" "<<warriorname[position]<<" "<<count<<" "<<"born with strength "<< warriorvalue[position]<<","<<warriorNum[position]<<" "<<warriorname[position]<<" in "<< headquartersname <<" headquarter"<<endl;
    totalhealth -= warriorvalue[position];
}

int main(){
    const int redorder[5] ={2,3,4,1,0};
    const int blueorder[5]={3,0,1,2,4};
    const string headquartersname[2]={"red","blue"};
    const string warriorname[5] ={"dragon","ninja","iceman","lion","wolf"};
    int n;
    cin>>n;  //obtain the test value
    for (int i=1;i<=n;i++)
    {
        int Warriorvalue[5], redposition=0, blueposition=0, minhealth=0, Totalhealth=0;
        bool redHadStop=false, blueHadStop=false;
        cout<<"input Totalhealth";
        cin>>Totalhealth; //obtain total health
//        obtain every warrior life value
        for (int j=0; j<5;j++){
            cin>>Warriorvalue[j];
        }
        cout<<"Case:"<< i <<endl;
//        obtain the minivalue
        minhealth = Warriorvalue[0];
        for (int k=1; k<5; k++ ){
            if (Warriorvalue[k]<minhealth){
                minhealth = Warriorvalue[k];
            }
        }
    
//        initialize the headquarters
    headquarters redone = headquarters(Totalhealth, 0, Warriorvalue, headquartersname, warriorname, redorder) ;
    headquarters blueone = headquarters(Totalhealth, 1, Warriorvalue, headquartersname, warriorname, blueorder) ;
    for (int time = 0; ((!redHadStop) || (!blueHadStop)); time++)
    {
        if (!redHadStop)
        {
            if ( redone.getHealth()<minhealth)
            {
                cout<<setfill('0')<<setw(3)<<time<< " red headquarter stops making warriors" << endl;
                redHadStop = true;
            }
            else
            {
                    while(true)
                    {
                    if (redone.getHealth() >= redone.getWarriorvalue(redposition))
                    {
                        redone.print(time, redposition);
                        redposition == 4 ? redposition = 0 : redposition++;
                        break;
                    }
                    else
                    {
                        redposition==4 ? redposition=0 : redposition++;
                    }
                }
            }
        }
            
        if (!blueHadStop){
            if ( blueone.getHealth()<minhealth)
            {
                cout<<setfill('0')<<setw(3)<<time<< " blue headquarter stops making warriors" << endl;
                blueHadStop = true;
            }
            else
            {
                while(true)
                {
                        if (blueone.getHealth() >= blueone.getWarriorvalue(blueposition))
                        {
                            blueone.print(time, blueposition);
                            blueposition == 4 ? blueposition = 0 : blueposition++;
                            break;
                        }
                        else
                        {
                            blueposition==4?blueposition=0 : blueposition;
                        }
                }
            }
        }
    }
}
return 0;
}

