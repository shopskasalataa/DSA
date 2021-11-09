#include <iostream>
#include <string>
#include <stack>
using namespace std;

bool closed(string brackets){
    stack<char> left;
    for (int i = 0; i < brackets.length(); i++){
       if(brackets[i] == '(' || brackets[i] == '{' || brackets[i] == '[')
            left.push(brackets[i]);
        else if(left.empty()) return false;
            else if ((brackets[i] == ')' && left.top() == '(') || 
                    (brackets[i] == '}' && left.top() == '{') || 
                    (brackets[i] == ']' && left.top() == '[')) 
                        left.pop();
                    else return false;
    }
    if(!left.empty()) return false;
}
int main(){
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        string brackets;
        cin >> brackets;
        cout << (closed(brackets) ? "YES" : "NO") << endl;
    }
    return 0;
}

// Balanced brackets
// https://www.hackerrank.com/challenges/balanced-brackets/problem