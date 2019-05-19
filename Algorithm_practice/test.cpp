#include<iostream>
using namespace std;
int main(int argc, const char * argv[] ){
	int a = 5;
	int & r =a;
	
	cout<<r<<endl;
	cout<<a<<endl;
	cout<<r<<endl;
	return 0;
}