class MyString: public string{
public:
    MyString():string(){};
    MyString(const string & a):string(a){};
    MyString(const char* str):string(str){};
    MyString(MyString & A):string(A){};
    MyString operator()(const int start, const int length);
};

MyString MyString::operator()(const int start, int length){
    return this->substr(start,length);
};

