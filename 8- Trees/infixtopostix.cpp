#include <iostream>
using namespace std;

int precedence(char op) {
    if (op == '+' || op == '-') {
        return 1;
    }
    if (op == '*' || op == '/') {
        return 2;
    }
    if(op == '^') {
        return 3;
    }
    return 0; //ye sab operators ke liye precedence return kar raha hai
}

