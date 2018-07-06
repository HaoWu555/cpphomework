#include <iostream>
#include <cstring>
using namespace std;

class Array2{
private:
	int row; int col; int *array;
public:
	Array2(int a=0, int b=0){
		row =a;
		col =b;
		array = new int [row*col];
	}
	Array2(Array2 & a){
		row = a.row;
		col = a.col;
		if (array) delete []array;
		array = new int [row*col];
		memcpy(array,a.array,sizeof(int)*col*row);
	}
	
	Array2 & operator=(const Array2 & a){
        row = a.row;
        col = a.col;
        if (array) delete []array;
        array = new int [row*col];
        memcpy(array,a.array,sizeof(int)*col*row);
		return *this;
	}
	~Array2(){
		if (array) delete [] array;
	}

	int * operator[](int i){
		return array+i*col;
	}

	int & operator()(int i, int j){
		return array[i*col+j];
	}
};


int main() {
    Array2 a(3,4);
    int i,j;
    for(  i = 0;i < 3; ++i )
        for(  j = 0; j < 4; j ++ )
            a[i][j] = i * 4 + j;
    for(  i = 0;i < 3; ++i ) {
        for(  j = 0; j < 4; j ++ ) {
            cout << a(i,j) << ",";
        }
        cout << endl;
    }
    cout << "next" << endl;
    Array2 b;     b = a;
    for(  i = 0;i < 3; ++i ) {
        for(  j = 0; j < 4; j ++ ) {
            cout << b[i][j] << ",";
        }
        cout << endl;
    }
    return 0;
}
