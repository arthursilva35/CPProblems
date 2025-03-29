#include <bits/stdc++.h>
#define int long long

using namespace std;


// acha o n-esimo numero de fibonacci usando PD
int fibo( int n, vector<int>& memo){
    
    if(memo[n] != -1){
        return memo[n];
    }

    int result =  fibo(n-1, memo) + fibo(n-2, memo);
    memo[n] = result;

    return result;
}
signed main()
{

    /*
    int  n = 50;

    vector<int> memo(1000, -1); // guarda a sequencia de fibonacci;

    // casos base
    memo[0] = 0;
    memo[1] = 1;


    // cout << fibo(n, memo) << endl;



    // Saquinho de moedas: Tome um conjunto de moedas que tem valor = {v1,v2,...,vk}. 
    // Qual o menor número de moedas que somadas totalizam T?


    vector<int> moedas = {1, 4, 5};

    int target = 13;

    vector<int> dp(target + 1, INT32_MAX);

    dp[0] = 0;

    for(int i = 1; i <= target; i++){
        for(auto moeda: moedas){
            if(i - moeda < 0) continue;

            dp[i] = min(dp[i], dp[i - moeda] + 1);
        }
    }

    // cout << dp[target];

    */

    // QUESTAO: https://atcoder.jp/contests/dp/tasks/dp_b

    /* int n, k;

    cin >> n >> k;

    vector<int> stones(n);

    vector<int> dp(n, INT32_MAX);

    dp[0] = 0;

    for(int i = 0; i < n; i++){
       
        cin >> stones[i];
    
    }


    for(int i = 1; i < n; i++){
        for(int j = max((int)0, (i-k)); j < i; j++){
            int cur = abs(stones[i] - stones[j]) + dp[j];
            
            dp[i] = min(dp[i], cur);
        }
    }

    cout << dp[n-1]; */

    // Knapsack dp

    struct item{
        int v; // value
        int w; // weight
    } a, b, c;


    a.v = 30; a.w = 3;
    b.v = 50; b.w = 4;
    c.v = 60; c.w = 5;

    vector<item> itens = {a, b, c}; int s = itens.size();
    int max_w = 8;

    vector<vector<int>> tbl(s, vector<int>(max_w, -1)); // matriz com qtd de itens linhas e capacidade da mochila + 1 colunas
    // tbl guarda o valor máximo que conseguimos carregar usando os i primeiros itens da lista em uma mochila de capacidade j 

    
    for(int i = 0; i < s; i++){ // casos base: capacidade da mochila é 0
        tbl[i][0] = 0;
    }


    for(int i = 0; i < s; i++){ // casos base: capacidade da mochila é 0
        for(int j = 0; j < max_w; j++){ // casos base: capacidade da mochila é 0
            
            if( j - itens[i].w < 0) continue; // adicionar o item violaria a capcidade da mochila
            else if( tbl[i-1][j- itens[i].w] != -1) continue;  // o subproblema anterior (preencher mochila de capacidade j - w_i, usando os itens anteriores a i) pode ser resolvido?
            

            tbl[i][j] = max(tbl[i-1][j], tbl[i-1][j- itens[i].w] + itens[i].v); // devemos pegar o item ou não?
        }
    }

    cout << tbl[s-1][max_w-1];



}