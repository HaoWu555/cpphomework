#include<iostream>
#include<stdio.h>
#define MAXIN 75

using namespace std;

int minstep,w,h,to[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
char board[MAXIN+2][MAXIN+2];
bool mark[MAXIN+2][MAXIN+2]={false}; 

void search_path(int now_x,int now_y,int end_x,int end_y,int step, int f);
int main(int argc, const char* argv[]){
	int i,j;
	cout<<"Please input the width and height"<<endl;
	cout<<"width:"<<endl;
	cin>>w;
	cout<<"height:"<<endl;
	cin>>h;
	cout<<"input the board card:"<<endl;
	for(i=0;i<MAXIN+2;i++)board[i][0]=board[0][i]=' ';
	for(i=1;i<=h;i++){
		getchar();
		for(j=1;j<=w;j++){
			board[i][j]=getchar();
		}
	}
	for(i=0;i<w;i++)board[h+1][i+1]=' ';
	for(i=0;i<h;i++)board[i+1][w+1]=' ';

	for(i=0;i<h+2;i++){
		for(j=0;j<w+2;j++){
			cout<<board[i][j]<<" ";
		}
		cout<<endl;
	}
	int x1,y1,x2,y2;
	int count=0;
	cout<<"input the start position and end position:"<<endl;
	while(scanf("%d,%d,%d,%d",&y1,&x1,&y2,&x2) && x1>0 && y1>0){
		count++;
		minstep=1000;
		search_path(x1,y1,x2,y2,0,-1);
		printf("Pair: %d minstep: %d.\n",count,minstep);
	}	
}


void search_path(int now_x,int now_y,int end_x,int end_y,int step, int f){
	cout<<"step:"<<step<<","<<"direction:"<<f<<endl;
	cout<<now_y<<" "<<now_x<<endl;
	// break out requirement
	if(step>minstep)return;
	if(now_x==end_x&&now_y==end_y){
		if(minstep>step)
			minstep=step;
			cout<<"minstep:"<<minstep<<endl;
		return;
	}
	int i,new_x,new_y;
	for(i=0;i<4;i++){ 
		new_x=now_x+to[i][0];
		new_y=now_y+to[i][1];
		if((new_x<w+2)&&(new_y<h+2)&&(new_x>-1)&&(new_y>-1)&&\
			(((board[new_y][new_x]==' ')&&(mark[new_y][new_x]==false))||\
			((board[new_y][new_x]=='x')&&(new_x==end_x)&&(new_y==end_y)))){
			mark[new_y][new_x]=true;
			if(f==i){
				search_path(new_x,new_y,end_x,end_y,step,i);
			}
			else{
				search_path(new_x,new_y,end_x,end_y,step+1,i); 
			} 
			mark[new_y][new_x]=false;
		}
	}

}

