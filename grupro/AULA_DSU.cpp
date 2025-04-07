#include <bits/stdc++.h>
#define int long long

using namespace std;

vector<int> pai, tam;


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

    pai[a] = b;
    
    tam[b] += tam[a];

}


bool same(int a, int b){

    if(find(a) == find(b)) return true;

    return false;

}



signed main(){

    int n = 4;

    pai.resize(n); tam.resize(n);


    for(int i = 0; i < n; i++){
        pai[i] = i; tam[i] = 1;
    }




}