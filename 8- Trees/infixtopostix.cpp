#include <iostream>
#include <string>
#include <cctype>   // ✅ for isalnum
using namespace std;

#define MAX_SIZE 100   // thoda safe size

struct Stack
{
    char arr[MAX_SIZE];
    int topIndex;

    Stack()
    {
        topIndex = -1;
    }

    void push(char value)
    {
        if (topIndex >= MAX_SIZE - 1)
        {
            cout << "Stack Overflow!" << endl;
            return;
        }
        arr[++topIndex] = value;
    }

    void pop()
    {
        if (topIndex == -1)
        {
            cout << "Stack Underflow!" << endl;
            return;
        }
        topIndex--;
    }

    char top()
    {
        if (topIndex == -1)
            return '\0'; 
        return arr[topIndex];
    }

    bool empty()
    {
        return topIndex == -1;
    }
};

int precedence(char op)
{
    switch (op)
    {
        case '*': case '/': case '%': return 5;
        case '+': case '-': return 4;
        case '>': case '<': return 3;
        case '=': case '!': return 2;
        case '&': return 1;
        case '|': return 0;
        default: return -1;   // ✅ important fix
    }
}

string infixToPostfix(string infix)
{
    Stack s;
    string postfix = "";

    for (int i = 0; i < (int)infix.size(); i++)
    {
        char c = infix[i];

        if (c == ' ')
            continue;

        if (isalnum(c))
        {
            postfix += c;
        }
        else if (c == '(')
        {
            s.push(c);
        }
        else if (c == ')')
        {
            while (!s.empty() && s.top() != '(')
            {
                postfix += s.top();
                s.pop();
            }
            if (!s.empty())
                s.pop();
        }
        else
        {
            while (!s.empty() && precedence(s.top()) >= precedence(c))
            {
                postfix += s.top();
                s.pop();
            }
            s.push(c);
        }
    }

    while (!s.empty())
    {
        postfix += s.top();
        s.pop();
    }

    return postfix;
}

int main()
{
    string infix;
    cout << "Enter infix expression: ";
    getline(cin, infix);

    string postfix = infixToPostfix(infix);
    cout << "Postfix expression: " << postfix << endl;

    return 0;
}