#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;
class Complex {
private:
    double r,i;
public:
    void Print() {
        cout << r << "+" << i << "i" << endl;
    }
	void operator = (const char *s){
		string str=s;
	    int pos = str.find("+",0);
	    string sTmp = str.substr(0,pos);
   		 r = atof(sTmp.c_str());
    	sTmp = str.substr(pos+1, str.length()-pos-2);
    	i = atof(sTmp.c_str());

	}


 
};
int main() {
    Complex a;
    a = "3+4i"; a.Print();
    a = "5+6i"; a.Print();
    return 0;
}
