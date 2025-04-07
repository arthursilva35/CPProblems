#include <bits/stdc++.h>
#define int long long

using namespace std;

vector<int> pai, tam;
int num_conj;
int tam_max = 1;

int find(int a){
    if(pai[a] == a){
        
        return a;
    } else{
        
        return pai[a] = find(pai[a]); // compressao de caminho
    }
}

void une(int a, int b){
    a = find(a);

    b = find(b);

    if(a ==b) return;

    pai[a] = b;
    
    tam[b] += tam[a];

    tam_max = max(tam_max, tam[b]);

    num_conj--;

}



signed main(){

    int n, m;

    cin >> n >> m;

    num_conj = n; pai.resize(n); tam.resize(n);

    for(int i = 0; i < n; i++){
        pai[i] = i; tam[i] = 1;
    }

    for(int i = 0; i < m; i++){
        int a, b;

        cin >> a >> b;

        a--; b--;

        une(a, b);

        cout << num_conj << " "  << tam_max << endl;
    }

}