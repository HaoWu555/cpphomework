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

