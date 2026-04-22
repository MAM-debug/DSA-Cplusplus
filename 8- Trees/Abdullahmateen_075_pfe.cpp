#include <iostream>
using namespace std;

#define MAX 100

char stackChar[MAX];
int topChar = -1;

void pushChar(char x) {
    stackChar[++topChar] = x;
}

char popChar() {
    return stackChar[topChar--];
}

char peekChar() {
    return stackChar[topChar];
}

bool isEmptyChar() {
    return topChar == -1;
}


int stackNum[MAX];
int topNum = -1;

void pushNum(int x) {
    stackNum[++topNum] = x;
}

int popNum() {
    return stackNum[topNum--];
}

\
int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    if (op == '^') return 3;
    return 0;
}


string infixToPostfix(string exp) {
    string result = "";

    for (char c : exp) {

        // operand
        if (isalnum(c)) {
            result += c;
        }

        // opening bracket
        else if (c == '(') {
            pushChar(c);
        }

        // closing bracket
        else if (c == ')') {
            while (!isEmptyChar() && peekChar() != '(') {
                result += popChar();
            }
            popChar(); // remove '('
        }

        
        else {
            while (!isEmptyChar() && precedence(peekChar()) >= precedence(c)) {
                result += popChar();
            }
            pushChar(c);
        }
    }

    
    while (!isEmptyChar()) {
        result += popChar();
    }

    return result;
}


int evaluatePostfix(string exp) {

    for (char c : exp) {

        if (isdigit(c)) {
            pushNum(c - '0');
        }
        else {
            int val2 = popNum();
            int val1 = popNum();

            switch (c) {
                case '+': pushNum(val1 + val2); break;
                case '-': pushNum(val1 - val2); break;
                case '*': pushNum(val1 * val2); break;
                case '/': pushNum(val1 / val2); break;
            }
        }
    }

    return popNum();
}


int main() {

   
    string exp1 = "A+B*C";
    cout << "Postfix: " << infixToPostfix(exp1) << endl;

    /n
    string exp2 = "23*5+";
    cout << "Evaluation: " << evaluatePostfix(exp2) << endl;

    return 0;
}



