#include <iostream>
#include <vector>
#include <map>
#include <string>

using namespace std;
int n;
map<string, vector<string>> graph; // ще направим насочен граф от благородници, където реброто със своята посока показва кой на кого е баща
vector<string> fathers; // списък с бащите 
map<string, string> has_parent; // списък със синовете - ключът е син, стойността - баща
int DFS(string father, int& curr_gen){
    for(int i = 0; i < graph[father].size(); i++){
        curr_gen++;
        DFS(graph[father][i], curr_gen);
    }
    return curr_gen;
}
int main(){
    cin >> n;
    string father, son;
    bool error = false;
    string error_son = "";
    for(int i = 0; i < n; i++){
        cin >> father >> son; // въвеждаме двойката баща и син
        fathers.push_back(father); // слагаме в списъка с бащи бащата
        if(has_parent.find(son) != has_parent.end()){ // ако синът вече има баща
            if(has_parent[son] != father){ // и този баща е различен от сегашния въведен
                if(!error){ // имаме нашия отговор, който е грешката, означаваме го за true и слагаме сина за сбъркания
                    error = true;
                    error_son = son;
                }
            }
        }else{
            has_parent[son] = father; // в противен случай ако синът няма баща, слагаме сегашния баща за баща
            graph[father].push_back(son); // и ги свързваме в графа
        }
    }

    if(error){
        cout << error_son << endl;
        return 0;
    }
    int curr_gen = 0, max_gen = 0;
    string big_father = "";
    for(int i = 0; i < fathers.size(); i++){
        if(has_parent.find(fathers[i]) == has_parent.end()){
            curr_gen = 0;
            curr_gen = DFS(fathers[i], curr_gen);
            if(max_gen < curr_gen || (max_gen == curr_gen && big_father < fathers[i])){
                big_father = fathers[i];
                max_gen = curr_gen;
            }
        }
    }
    cout << big_father << endl;
    return 0;
}

// ДИНАСТИИ
// http://www.math.bas.bg/infos/files/2012-04-07-C1.pdf