#include <iostream>
#include <queue>
#include <stack>
#include <vector>
#include <cmath>
using namespace std;
const int MAX = 10000;
// не се сетих за по-умен начин да генерирам списък от прости числа
bool is_prime(const int& num){
    for(int i = 2; i <= sqrt(num); i++){
        if(num % i == 0){
            return false;
        }
    }
    return true;
}
void generate_primes(vector<int>& primes){
    for(int i = 2; i <= MAX; i++){
        if(is_prime(i)){
            primes.push_back(i);
        }
    }
}
void add_to_answers(vector<int>& answers, stack<int>& to_be_added){
    while(!to_be_added.empty()){
        answers.push_back(to_be_added.top());
        to_be_added.pop();
    }
}
void empty_stack(stack<int>& s){
    while(!s.empty()){
        s.pop();
    }
}
void show_stack(stack<int> s){
    while(!s.empty()){
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;
}
void distribute_plates(stack<int> a, int q){
    vector<int>primes, answers;
    generate_primes(primes);
    
    for(int i = 1; i <= q; i++){
        stack<int> ai;
        stack<int> bi;
        while(!a.empty()){
            if(a.top() % primes[i] == 0){
                bi.push(a.top());
            }else{
                ai.push(a.top());
            }
            a.pop();
        }
        add_to_answers(answers, bi);
        if(i == q) add_to_answers(answers, ai);
        a = ai;
        empty_stack(ai);
        empty_stack(bi);
    }

    for(int i = 0; i < answers.size(); i++){
        cout << answers[i] << " ";
    }
    
}
int main(){
    int n, q;
    cin >> n >> q;
    stack<int>a;
    
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        a.push(x);
    }

    distribute_plates(a, q);
    return 0;
}