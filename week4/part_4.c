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
	friend bool operator==(const string a, const string b);
	A operator+(const A & rhs);
	A operator-(const A & rhs);
	A operator*(const A & rhs);
	A operator/(const A & rhs);

};

bool operator==(const string a, const string b){
	if (a==b){
		return true;
	}
	else{
		return false;
	}
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
	if (lvalue == "0"){
		ret.values = rvalue;
		return ret;
	}
	
	if (rvalue == "0"){
		ret.values = lvalue;
		return ret;
	}


	// adjust the s1 and s2 size

	unsigned int i, lsize, rsize;
	lsize = lvalue.size();
	rsize = rvalue.size();
	if (lsize<rsize){
		for (i=0; i< rsize-lsize; i++){
			lvalue = "0" + lvalue;
		}
	}
	else{
		for (i=0; i<lsize-rsize; i++){
			rvalue = "0" + rvalue;
		}
	}

	int n1, n2;
	n2 =0;
	lsize = lvalue.size();
	string res= "";
	reverse(lvalue.begin(), lvalue.end());
	reverse(rvalue.begin(), rvalue.end());
	
	for (i=0; i<lsize; i++){
		n1 = (lvalue[i]-'0'+ rvalue[i]-'0'+n2 )%10;	
		n2 = (lvalue[i]-'0'+ rvalue[i]-'0'+n2 )/10;
		res = res + char (n1 + '0');
	}
	
	if (n2 == 1){
		res = res + "1";
	}

	reverse(res.begin(), res.end());
	ret.values = res;
	return ret;


};


A A::operator-(const A & rhs){
	A ret;
	string lvalue(values),rvalue(rhs.values);
	if (rvalue == "0"){
		ret.values = lvalue;
		ret.flag= true;
		return ret;
	}
	if (lvalue == "0"){
		ret.values =rvalue;
		ret.flag = false;
		return ret;
	}
	unsigned int i,lsize,rsize;
	lsize=lvalue.size();
	rsize=rvalue.size();
	if (lsize > rsize){
		for (i=0; i< lsize-rsize; i++){
			rvalue = "0" + rvalue;
		}
	}
	if (rsize > lsize){
		for (i=0; i < rsize-lsize; i++){
			lvalue = "0" + lvalue;
		}
	}
	
	int t = lvalue.compare(rvalue);
	if(t<0){
		ret.flag=false;
		string tmp = lvalue;
		lvalue = rvalue;
		rvalue = tmp;
	}
	else if (t>0){
		ret.flag = true;
	}
	else{
		ret.flag=true;
		ret.values="0";
		return ret;
	}

	unsigned int j;
	lsize=lvalue.size();
	string res="";
	reverse(lvalue.begin(), lvalue.end());
	reverse(rvalue.begin(), rvalue.end());
	
	for (int i=0; i<lsize;i++){
		if (lvalue[i]<rvalue[i]){
			j=1;
			while (lvalue[i+j]=='0'){
				lvalue[i+j]=='9';
				j++;
			}
			lvalue[i+j]-=1;
			res = res + char(lvalue[i] + ':' - rvalue[i]);
		}
		else{
			res = res + char(lvalue[i] - rvalue[i] + '0');
		}
	}
	reverse(res.begin(),res.end());
	res.erase(0, res.find_first_not_of('0'));
	ret.values = res;
	return ret;

};

A A::operator*(const A & rhs){
	A ret;
	string lvalue(values), rvalue(rhs.values);

	if (lvalue=="0"|| rvalue=="0"){
		ret.flag= true;
		ret.values='0';
		return ret;
	}
	
	unsigned int lsize, rsize;
	lsize=lvalue.size();
	rsize=rvalue.size();
	string temp;
	A res, itemp;

	if(lvalue<rvalue){
		temp=lvalue;
		lvalue = rvalue;
		rvalue = temp;
		lsize = lvalue.size();
		rsize = rvalue.size();
	}
	
	int i,j,n1,n2,n3,t;
	reverse(lvalue.begin(),lvalue.end());
	reverse(rvalue.begin(),rvalue.end());
	for (int i=0; i< rsize ;i ++){
		temp = "";
		n1 =n2=n3=0;
		for (int j=0; j<i; j++){
			temp = temp + "0";
		}
		n3 = rvalue[i] -'0';
		for (int j=0; j<lsize; j++){
			t=(n3*(lvalue[j]-'0')+n2);
			n1 = t%10;
			n2 = t/10;
			temp=temp+char(n1+'0');
		}
		if (n2){
			temp = temp + char(n2+'0');
		}
		reverse(temp.begin(),temp.end());
		itemp.values = temp;
		res = res+ itemp;
	}
	ret= res;
	return ret;

};


A A::operator/(const A & rhs){
	A ret;
	string lvalue(values), rvalue(rhs.values);
	string quotient;
	
	if(rvalue == "0"){
		ret.values="error"; 
		ret.flag= true;
		return ret;
	}
	if(lvalue == "0"){
		ret.values = "0";
		ret.flag=true;
		return ret;
	}
	if (compare(lvalue,rvalue)<0){
		ret.values="0";
		ret.flag=true;
		return ret;
	}
	else if (compare(lvalue,rvalue)==0){
		ret.values = "1";
		ret.flag=true;
	}
	else {
		string temp;
		unsigned int lsize, rsize;
		lsize=lvalue.size();
		rsize=rvalue.size();
		int i;
		if(rsize>1) temp.append(lvalue,0, rsize-1);
		for (i=rsize -1; i<lsize; i++){
			temp= temp + lvalue[i];
			for (char c='9'; c>='0'; c--){
				A t = (A)rvalue * (A)string(1,c);
				A s = (A) temp -t;

				if (s.flag == true){
					temp = s.values;
					quotient = quotient +c;
					break;
				}
			}
		}
	}

	quotient.erase(0, quotient.find_first_not_of('0'));
	ret.values = quotient;
	ret.flag=true;
	return ret;



};


int main(){
	A a, b, result;
	char op;
	cin>>a>>op>>b;
//	cout<<a<<op<<b<<endl;
	switch(op){
		case '+': result = a+b; break;
		case '-': result = a-b; break;
		case '*': result = a*b; break;
		case '/': result = a/b; break;
	}
	cout<<result<< endl;

	return 0;
	

}



