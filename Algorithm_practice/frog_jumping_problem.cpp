#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;

struct PLANT
{
	int x,y;
};

int main(int argc,const char * argv[]){
	int r=6,n=14,c=7,i,j,step,dX,dY,pX,pY;
	PLANT plant;
	int maxstep=2;
	PLANT plants[14] = {{2,1},{6,6},{4,2},{2,5},{2,6},{2,7},{3,4},\
						  {6,1},{6,2},{2,3},{6,3},{6,4},{6,5},{6,7}};
	sort(plants,plants+14);

	for(i=0;i<14;i++){
		cout<<plants[i].x<<" "<<plants[i].y<<endl;
	}

	for(i=0;i<n-1;i++){ 
		for(j=i+1;j<n;j++){ 
			dX=plants[j].x-plants[i].x;
			dY=plants[j].y-plants[i].y;
			pX=plants[i].x-dX;
			pY=plants[i].y-dY;
			if(pX<=r&&pY<=c&&pX>=1&&pY>=1){ 
				continue;
			}
			if(plants[i].x+dX*(maxstep-1)>r){
				break;
			}
			pY=plants[i].y+dY*(maxstep-1);
			if(pY>c||pY<1)
				continue;
			step=0;
			plant=plants[i];
			cout<<"print posiible pairs:"<<endl;
			cout<<plant.x<<" "<<plant.y<<endl;
			while(binary_search(plants,plants+14,plant)&&plant.x<=r&&plant.x>=1\
				  &&plant.y<=c&&plant.y>=1){ 
				plant.x=plant.x+dX;
				plant.y=plant.y+dY;
				step++;
			}
			if (step>maxstep){
				maxstep=step;
			}
			
		}
	}

	cout<<maxstep<<endl;

	return 0;
}

bool operator<(const PLANT &A,const PLANT &B){
	if(A.x==B.x) 
		return A.y<B.y;
	return A.x<B.x;
}