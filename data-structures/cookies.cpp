#include <iostream>
#include <list>
#include <queue>
#include <iterator>
using namespace std;
void delete_element(list<int>& l, int& n){
    list<int>::iterator it;
    for (it=l.begin(); it!=l.end(); it++){
        if(*it == n){
            break;
        }
    }
    l.erase(it);
}
int mixing_cookies(list<int>& cookies, priority_queue<int, std::vector<int>, std::greater<int>>& least_sweet, const int& k){
    int minimum_operations = 0;
    bool is_ready = false;
    if(least_sweet.top() >= k){
        return -1;
    }
    while(!is_ready){
        int cookie1 = least_sweet.top();
        least_sweet.pop();
        int cookie2 = least_sweet.top();
        least_sweet.pop();
        int new_cookie = cookie1 + 2 * cookie2;
        delete_element(cookies, cookie1);
        delete_element(cookies, cookie2);
        cookies.push_front(new_cookie);
        least_sweet.push(new_cookie);
        minimum_operations++;
        if(least_sweet.top() >= k){
            is_ready = true;
        }
    }
    return minimum_operations;
}
int main(){
    int n, k;
    list<int>cookies_sweetness;
    priority_queue<int, std::vector<int>, std::greater<int>>least_sweet;

    cin >> n >> k;
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        cookies_sweetness.push_back(x);
        least_sweet.push(x);
    }
    
    cout << mixing_cookies(cookies_sweetness, least_sweet, k);
    return 0;
}