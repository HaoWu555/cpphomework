#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;

struct PLANT
{
	int x,y;
};

int main(int argc,const char * argv[]){
	int r=6,n=14,c=7,i,j,step,dX,dY;
	PLANT plant;
	int maxstep=2;
	PLANT plants[14] = {{2,1},{6,6},{4,2},{2,5},{2,6},{2,7},{3,4},\
						  {6,1},{6,2},{2,3},{6,3},{6,4},{6,5},{6,7}};
	sort(plants,plants+14);

	for(i=0;i<14;i++){
		cout<<plants[i].x<<" "<<plants[i].y<<endl;
	}

	for(i=0;i<n-1;i++)
		for(j=i+1;j<n;j++)
			dX=plants[j].x-plants[i].x;
			dY=plants[j].y-plants[j].y;
			pX=plants[i].x-dX;
			pY=plants[i].y-dY;
			if(pX<=r&&pY<=c&&pX>=1&&pX>=1){ 
				continue;
			}
			if(plants[i]+dX*(maxstep-1)>r&&plants[i]+dY*(maxstep-1)>c){
				break;
			}

			step=0;
			plant = plants[i];
			while(plant.x<r&&plant.y<c&&binary_search(plants,plants+14,plant))
				plant.x=plant.x+dX;
				plant.y=plant.y+dY;
				step++;
			if (step>maxstep)
				maxstep=step;

	cout<<maxstep<<endl;

	return 0;
}

bool operator<(const PLANT &A,const PLANT &B){
	if(A.x==B.x) 
		return A.y<B.y;
	return A.x<B.x;
}