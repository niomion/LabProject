#pragma once
#include <iostream>
#include <string>

using namespace std;

class Boolean {
public:
   static bool logical_and(bool a, bool b) { return a && b; }
   static bool logical_or(bool a, bool b) { return a || b; }
   static bool logical_not(bool a) { return !a; }
};

template<typename T>
class Functor {
public:
    Boolean boolean;

    T operator()(T a, char op, T b) {
        try {
            switch (op) {
            case '+': return a + b;
            case '-': return a - b;
            case '*': return a * b;
            case '/':
                if (b == 0) throw invalid_argument("Division by zero");
                return a / b;
            case '%':
                if (b == 0) throw invalid_argument("Division by zero");
                return a % b;
            default:
                throw invalid_argument("Unknown operation");
            }
        }
        catch (invalid_argument& e) {
            cerr << "Error: " << e.what() << endl;
            return a;
        }
    }

    bool operator()(T a, string op, T b) {
        try {
            if (op == "==") return a == b;
            else if (op == "!=") return a != b;
            else if (op == ">") return a > b;
            else if (op == "<") return a < b;
            else if (op == ">=") return a >= b;
            else if (op == "<=") return a <= b;
            else {
                throw invalid_argument("Unknown operation");
            }
        }
        catch (invalid_argument& e) {
            cerr << "Error: " << e.what() << endl;
        }
    }

    T negate(T a) {
        return -a;
    }
};
