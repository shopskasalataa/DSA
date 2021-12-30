#include <iostream>
#include <vector>
#include <utility>
#include <queue>

using namespace std;
vector<vector<pair<int, int>>>graph;
vector<bool>used;

void BFS(int v, int k){
    queue<int>q;
    // опашка за наследниците за обхождане
    used[v] = true;
    // началния ни връх е обходен и го слагаме в опашката
    q.push(v);

    while(!q.empty()){
        // докато опашката не е празна, слагаме за начален връх следващия връх в опашката и обхождаме неговите съседи
        v = q.front();
        q.pop();
    
        for(int i = 0; i < graph[v].size(); i++){
            if(!used[graph[v][i].first] && graph[v][i].second >= k){
                // ако широчината на канала е >= k и този връх не е обходен, означаваме го за обходен и го слагаме в опашката
                used[graph[v][i].first] = true;
                q.push(graph[v][i].first);
            }
        }
    }
}
int main(){
    int n, m;
    cin >> n >> m;
    graph.resize(n + 1);
    used.assign(n+1, false);
    int v, u, w;
    // използваме списък на съседи и правим двойка от крайния връх и теглото на реброто
    for(int i = 0; i < m; i++){
        cin >> v >> u >> w;
        graph[v].push_back(make_pair(u, w));
        graph[u].push_back(make_pair(v, w));
    }
    int cnt = 0, k;
    cin >> k;
    // за да намерим броя на каналите, които трябва да се разширят, ще броим броя на компонентите, които се
    // получават с ширина на лодката k, тъй като не може да достигне по-тесни канали
    for(int i = 1; i <= n; i++){
        if(!used[i]){
            // всеки път щом имаме необходен връх, увеличаваме броя на компонентите и обхождаме всички върхове
            // в този компонент
            cnt++;
            BFS(i, k);
        }
    }
    
    cout << cnt - 1 << endl;

    return 0;
}

// РАЗШИРЯВАНЕ НА КАНАЛИ
// http://www.math.bas.bg/infos/files/2012-11-25-B3.pdf