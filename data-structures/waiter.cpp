#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;
bool isPrime(int number) {
    int counter = 0;
    for (int j = 2; j < number; j++) {
        if (number % j == 0) {
            counter = 1;
            break;
        }
    }
    if (counter == 0) {
        return true;
    }
    else return false;
}
void prime_generator(vector<int>& primes, int q) {
    int n = 2, i = 0;
    while (i < q) {
        if (isPrime(n)) {
            primes.push_back(n);
            i++;
        }
        n++;
    }
}
vector<int> waiter(vector<int> numbers, int q) {
    stack<int>A;
    stack<int>B;
    vector<int>answers;
    vector<int> primes;
    prime_generator(primes, q);
    int it = 0;
    while (it < q) {
        while (!numbers.empty()) {
            if (numbers[numbers.size() - 1] % primes[it] == 0) {
                B.push(numbers[numbers.size() - 1]);
            }
            else A.push(numbers[numbers.size() - 1]);
            numbers.pop_back();
        }
        it++;
        while (!B.empty()) {
            answers.push_back(B.top());
            B.pop();
        }
        while (!A.empty()) {
            numbers.push_back(A.top());
            A.pop();
        }
        reverse(numbers.begin(), numbers.end());
    }
    while (!numbers.empty()) {
        answers.push_back(numbers[numbers.size() - 1]);
        numbers.pop_back();
    }

    return answers;
}
int main() {
    int n, q;
    cin >> n >> q;
    vector<int>input;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        input.push_back(x);
    }

    vector<int>answers = waiter(input, q);
    for (unsigned int i = 0; i < answers.size(); i++) {
        cout << answers[i] << endl;
    }
    return 0;
}

// Waiter
// https://www.hackerrank.com/challenges/waiter/problem