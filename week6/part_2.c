#include <iostream>
using namespace std;
class A {
// 在此处补充你的代码
};
class B:public A {
    public:
        ~B() { cout << "destructor B" << endl; }
};
int main() {
    A * pa;
    pa = new B;
    delete pa;
    return 0;
}