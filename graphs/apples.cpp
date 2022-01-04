#include <iostream>
#include <vector>
#include <utility>
#include <queue>

using namespace std;
int n, m, t;
vector<vector<int>>a;
queue<pair<int, int>>rooten;


int main() {
    cin >> n >> m >> t;
    a.resize(n + 1);
    for (int i = 0; i <= n; i++) {
        a[i].resize(m + 1);
    }
    int x, y;
    cin >> x >> y;
    rooten.push(make_pair(x, y));
    a[x][y] = 1;
    cin >> x >> y;
    rooten.push(make_pair(x, y));
    a[x][y] = 1;
    int root = 0;
    while (!rooten.empty()) {
        x = rooten.front().first;
        y = rooten.front().second;
        rooten.pop();

        int day = a[x][y] + 1;
        if (day > t + 1) break;
        if (x > 0 && (a[x - 1][y] == 0 || a[x - 1][y] <= day)) {
            a[x - 1][y] = day;
            rooten.push(make_pair(x - 1, y));
        }
        if (x < n + 1 && (a[x + 1][y] == 0 || a[x + 1][y] <= day)) {
            a[x + 1][y] = day;
            rooten.push(make_pair(x + 1, y));
        }
        if (y < m + 1 && (a[x][y + 1] == 0 || a[x][y + 1] <= day)) {
            a[x][y + 1] = day;
            rooten.push(make_pair(x, y + 1));
        }
        if (y > 0 && (a[x][y - 1] == 0 || a[x][y - 1] <= day)) {
            a[x][y - 1] = day;
            rooten.push(make_pair(x, y - 1));
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cout << a[i][j] << " ";
            if (a[i][j] != 0) {
                root++;
            }
        }
        cout << endl;
    }
    cout << endl;
    cout << n * m - root << endl;

    return 0;
}