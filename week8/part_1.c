#include <iostream> 
#include <iterator> 
#include <set> 

using namespace std;
int main() { 
    int a[] = {8,7,8,9,6,2,1}; 
    set<int> v(a,a+sizeof(a)/sizeof(*a));
    ostream_iterator<int> o(cout," ");
    copy( v.begin(),v.end(),o); 
    cout<<sizeof(a)<<" "<<sizeof(*a)<<endl;
    return 0;
}

