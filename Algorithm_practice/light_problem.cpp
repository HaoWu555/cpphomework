#include <iostream>
using namespace std;

static int press[6][8]={0},puzzle[6][8]={0};

bool guess(){
	int i,j;
	for(i=1;i<5;i++){
		for(j=1;j<7;j++){
			press[i+1][j]=(press[i][j]+press[i][j-1]+press[i][j+1]+\
						press[i-1][j]+puzzle[i][j])%2;
		}
	}
	for(j=1;j<7;j++){
		if((press[5][j]+press[5][j-1]+press[5][j+1]+\
						press[4][j])%2!=puzzle[5][j]){ 
			return(false);
		}
	}
	return(true);
}

void enumerator(){
	int i;
	for(i=1;i<7;i++){
		press[1][i]=0;
	}
	while(guess()==false){
		press[1][1]++;
		i=1;
		while(press[1][i]>1){
			press[1][i]=0;
			i++;
			press[1][i]++;
		}
	}
}


int main(int argc, const char * argv[]) {
    // insert code here...
    // initialize the press
    int p[5][6] ={{0,1,1,0,1,0},{1,0,0,1,1,1},\
    			   {0,0,1,0,0,1},{1,0,0,1,0,1},\
    			   {0,1,1,1,0,0}};
    int i,j;
    for(i=1;i<6;i++){ 
    	for(j=1;j<7;j++){
    		puzzle[i][j]=p[i-1][j-1];
    	}
	}

	cout<<"Print the puzzle:"<<endl;
    for(i=1;i<6;i++){ 
    	for(j=1;j<7;j++){
    		cout<<puzzle[i][j]<<" ";
    	}
    	cout<<endl;
	}

	enumerator();

	cout<<"Print the Press:"<<endl;
    for(i=1;i<6;i++){ 
    	for(j=1;j<7;j++){
    		cout<<press[i][j]<<" ";
    	}
    	cout<<endl;
	}

    return 0;
}
