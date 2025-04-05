
#include <bits/stdc++.h>
#define int long long
using namespace std;


int BFS(int s, int target, vector<vector<int>>& g) // retorna a distancia de s até target (faz uma DFS pra achar)
{
    queue<int> q;
    vector<bool> used(g.size());
    
    int total = 0;
    
    q.push(s);
    
    while(!q.empty()){
        int cur = q.front();
        q.pop();
        
        if(used[cur]){
            
            total--;
            
            continue;
        }
        else{

            used[cur] = true;            
            
            if(cur == target) break;
            total++;

            cout << "visitando " << cur <<  " total atual " << total << endl;

            vector<int> v = g[cur];
            
            for(int i = 0; i < v.size(); i++){

                q.push(v[i]);
            }
        }
    }

    cout << "achou " << target <<  " total " << total << endl;
    
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

    cout << BFS(0, 3, graph);
    
/*     for(int i = 0; i < n; i++){
        int total = 0;
        
        for(int j = 0; j < n; j++){
            if(i == j) continue;

            total += DFS(i, j, graph);
        }

        cout << total << " ";
    } */
    
}