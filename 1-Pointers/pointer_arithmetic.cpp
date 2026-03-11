#include <iostream>
using namespace std;
void ChangeA(int &ref) {
    ref=30;
}
int main(){
    //pass by ref using alias
    int x=10;
    ChangeA(x);
    cout<<x<<endl;//30 because pass by reference using alias

}
