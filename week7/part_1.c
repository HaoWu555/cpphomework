#include <iostream>
using namespace std;

template<class T1>
class CArray2D{
private:
	T1 *addr;
	int a,b;
public:
	CArray2D(){addr=NULL;}
	CArray2D(int A, int B):a(A),b(B){
		addr = new T1 [a*b];
	}
	~CArray2D(){
		if (addr != NULL)
			delete [] addr;
	}
	T1 *operator[](int C){ //重载第一个[],返回一个指针，
		return addr + C*b; //第二个[],则可以直接加，
	};					   // 与一维数组一样
};

template <class T>
class CArray3D{
private:
	int A,B,C;
	CArray2D<T> **array2D;
	T *addr;
public:
	CArray3D(){array2D= NULL;}
	CArray3D(int a, int b, int c){
		array2D = new CArray2D<T>* [a];
		for (int m=0; m<a; ++m){
			array2D[m] = new CArray2D<T>(b,c);
		}
	};
	
	CArray2D<T> & operator[](int i){
		return *array2D[i];
	}
	~CArray3D(){
		if(array2D != NULL) delete [] array2D;
	} 

};

int main()
{
    CArray3D<int> a(3,4,5);
    int No = 0;
    for( int i = 0; i < 3; ++ i )
        for( int j = 0; j < 4; ++j )
            for( int k = 0; k < 5; ++k )
                a[i][j][k] = No ++;
    for( int i = 0; i < 3; ++ i )
        for( int j = 0; j < 4; ++j )
            for( int k = 0; k < 5; ++k )
                cout << a[i][j][k] << ",";
    return 0;
}
