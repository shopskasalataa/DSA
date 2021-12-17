#include <iostream>
#include <string>
#include <stack>

using namespace std;

void append(stack<string>& s,const string to_append){
    s.push(s.top() + to_append);
}
void to_delete(stack<string>& s, const int kth){
    string top = s.top();
    string new_s = top.substr(0, top.length() - kth);
    s.push(new_s);
}
void print(const stack<string>& s, const int kth){
    string top = s.top();
    cout << top[kth - 1] << endl;
}
void undo(stack<string>& s){
    s.pop();
    if(s.empty()){
        s.push("");
    }
}
int main(){
    stack<string>history;
    history.push("");
    int n;
    cin >> n;
    int operation; 
    string input;
    for(int i = 0; i < n; i++){
        cin >> operation;
        if(operation == 1){
            string to_append;
            cin >> to_append;
            append(history, to_append);
        }
        if(operation == 2){
            int kth_operation;
            cin >> kth_operation;
            to_delete(history, kth_operation);
        }
        if(operation == 3){
            int last_kth;
            cin >> last_kth;
            print(history, last_kth);
        }
        if(operation == 4){
            undo(history);
        }
    }
    return 0;
}

// Simple text editior
// https://www.hackerrank.com/challenges/simple-text-editor/problem