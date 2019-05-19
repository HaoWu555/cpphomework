#include <string>
#include <iostream>
#include <cstdlib>
#include <stdio.h>
#include <algorithm>
using namespace std;

class A{
private: 
	string values;
	bool flag;
	inline int compare(string s1, string s2){
		if (s1.size() < s2.size())
			return -1;
		else if (s1.size() > s2.size())
			return 1;
		else
			return s1.compare(s2);
	}
public:
	A():values("0"),flag(true){};
	A(string str){
		values=str;
		flag=true;
	}

public: 
	friend ostream& operator<<(ostream & os, const A & a);
	friend istream& operator>>(istream & is, A & a);
	A operator+(const A & rhs);
/*	A operator-(const A & rhs);
	A operator*(const A & rhs);
	A operator/(const A & rhs);
*/
};

ostream & operator<<(ostream & os, const A & a){
	if (!a.flag){
		os<< '-';
	}
	os<< a.values;
	return os;
};

istream & operator>>(istream & is, A & a){
	string str;
	is >> str;
	a.values = str;
	a.flag = true;
	return is;
};

A A::operator+(const A & rhs){
	A ret;
	ret.flag= true; // positive value add
	string lvalue(values),rvalue(rhs.values);
	if (lvalue == '0'){
		ret.values = rvalue;
		return ret;
	}
	
	if (rvalue == '0'){
		ret.values = lvalue;
		return ret;
	}

	// adjust the s1 and s2 size

	unsigned int i, lsize, rsize;
	lsize = lvalues.size();
	rsize = rvalues.size();
	if (lsize<rsize){
		for (i=0; i< rsize-lsize; i++){
			lvalues = "0" + lvalues;
		}
	}
	else{
		for (i=0; i<lsize-rsize; i++){
			rvalues = "0" + rvalues;
		}
	}

	int n1, n2;
	n2 =0;
	lsize = lvalues.size();
	string res= "";
	reverse(lvalues.begin(), lvalues.end());
	reverse(rvalues.begin(), rvalues.end());
	
	for (i=0; i<lsize; i++){
		n1 = (lvalues[i]-'0'+ rvalues[i]-'0'+n2 )%10;	
		n2 = (lvalues[i]-'0'+ rvalues[i]-'0'+n2 )/10;
		res = res + char (n1 + '0');
	}
	
	if (n2 == 1){
		res = res + "1";
	}

	reverse(res.begin(), res.end());
	ret.values = res;
	return ret;


};



int main(){
	A a, b, result;
	char op;
	cin>>a>>op>>b;
	cout<<i<<o<<j<<endl;
	switch(op){
		case '+': result = a+b; break;
		case '-': result = a-b; break;
	}
	cout<<result<< endl;

	return 0;
	

}



