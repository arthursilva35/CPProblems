
#include <bits/stdc++.h>
#define int long long
using namespace std;

// https://cp-algorithms.com/graph/breadth-first-search.html

int BFS(int s, vector<vector<int>>& g) // retorna a soma das distancia de s até todos os outros vertices (faz uma BFS pra achar)
{
    queue<int> q;
    vector<bool> used(g.size());
    vector<int> dist(g.size(), 0); // store the distance from the root to each node
    
    q.push(s);
    used[s] = true;
    
    while(!q.empty()){
        int cur = q.front();
        q.pop();
               
        for(auto i : g[cur]){

            if(!used[i]){
                used[i] = true;
                q.push(i);
                dist[i] = dist[cur] + 1;
            }
        }
    }

    int total = 0;

    for(int i = 0; i < g.size(); i++){
        total += dist[i];
    }

    return total;
}

signed main()
{
    int n;
    
    cin >> n;
    
    vector< vector<int>> graph(n);
    
    for(int i = 0; i < n-1; i++){
        
        int start, end; 
        
        cin >> start >> end;

        graph[start -1].push_back(end - 1);
        graph[end -1].push_back(start - 1);

    }
    
    for(int i = 0; i < n; i++){
        cout << BFS(i, graph) << " ";
    }
    
}