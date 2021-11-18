#include <iostream>
#include <vector>
#include <stack>
#include <utility>
using namespace std;

int days_to_die(vector<int> p){
    stack<pair<int, int>> s;
    int total_days = 0;
    for(int plant = p.size() - 1; plant >= 0; plant--){
        int days = 0;
        while(!s.empty() && p[plant] < p[s.top().first]){
            days = max(days + 1, s.top().second);
            s.pop();
        }
        s.push(make_pair(plant, days));
        total_days = max(total_days, days);
    }

    return total_days;
}
int main(){
    int n;
    cin >> n;
    vector<int>input;
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        input.push_back(x);
    }

    cout << days_to_die(input) << endl;
    return 0;
}

// Poisonous Plants
// https://www.hackerrank.com/challenges/poisonous-plants/problem