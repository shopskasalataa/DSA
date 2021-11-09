#include <iostream>
#include <queue>
using namespace std;

int mixing_cookies(priority_queue<int, std::vector<int>, std::greater<int>>& cookies, const int& k){
    int minimum_operations = 0;
    bool is_ready = false;
    if(cookies.top() >= k){
        return 0;
    }
    if(cookies.empty()){
        return -1;
    }
    int cookie1, cookie2;
    while(!is_ready){
        if(!cookies.empty()){
            cookie1 = cookies.top();
            cookies.pop();
        }else return -1;
        if(!cookies.empty()){
            cookie2 = cookies.top();
            cookies.pop();
        }else return -1;
        int new_cookie = cookie1 + 2 * cookie2;
        cookies.push(new_cookie);
        minimum_operations++;
        if(cookies.top() >= k){
            is_ready = true;
        }
    }
    return minimum_operations;
}

int main(){
    int n, k;
    priority_queue<int, std::vector<int>, std::greater<int>>cookies_sweetness;

    cin >> n >> k;
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        cookies_sweetness.push(x);
    }
    
    cout << mixing_cookies(cookies_sweetness, k);
    return 0;
}

// Jesse and Cookies
// https://www.hackerrank.com/challenges/jesse-and-cookies/problem