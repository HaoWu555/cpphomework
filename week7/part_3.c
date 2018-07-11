#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

int main(){
	int i;
	cin>>i;
	cout<<hex<<i<<endl;
	cout<<dec<<setw(10)<<setfill('0')<<i<<endl;
}
