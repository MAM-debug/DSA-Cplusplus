#include <iostream>
using namespace std;
int main() {
    // pointer 
    int var = 20;   // actual variable declaration
    cout << &var << endl;

    int *ptr=&var; // pointer variable declaration
    cout << ptr << endl;
    cout << *ptr << endl; // dereferencing pointer
    float price=110.2;
    float *ptr2=&price;
    cout << ptr2 << endl;
    cout << *ptr2 << endl; // dereferencing pointer
    return 0;
    
}