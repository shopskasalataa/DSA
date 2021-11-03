#include <iostream>
#include <string>
#include <stack>
using namespace std;
bool valid(string brackets){
    for (int i = 0; i < brackets.length(); i++){
        if (brackets[i] != '{' && brackets[i] != '}' && 
            brackets[i] != '[' && brackets[i] != ']' &&
            brackets[i] != '(' && brackets[i] != ')'){
            return false;
        }
    }
    return true;
}

bool closed(string brackets){
    if (!valid(brackets)){
        return false;
    }
    
    stack<char> left;

    for (int i = 0; i < brackets.length(); i++){
        if (brackets[i] == '(' || brackets[i] == '{' || brackets[i] == '['){
            left.push(brackets[i]);
            continue;
        }
        if ((brackets[i] == '}' && left.top() != '{') ||
            (brackets[i] == ']' && left.top() != '[') ||
            (brackets[i] == ')' && left.top() != '(')){
            return false;
        }
        if (left.empty()){
            return false;
        }
        left.pop();
    }
    return left.empty();
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