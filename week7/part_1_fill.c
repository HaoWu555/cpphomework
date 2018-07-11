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
    T1 *operator[](int C){
        return addr + C*b;
    };
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

