#include <bits/stdc++.h>
#define int long

using namespace std;

struct whey{
  int a, b, c, d;  
};

signed main(){
    int n, m, nat_c, nat_d;
    
    cin >> n >> m >>  nat_c >> nat_d;
    
    vector<whey> w(m);
    
     // dp[i][j] guarda o maximo de birls que da p fazer usando j grams de caseina, com as i primeiras essências 
    vector<vector<int>> dp(m+1, vector<int>(n+1, -1));
    
    for(int i = 0; i < m; i++){
        
        whey cur;
        
        cin >> cur.a >> cur.b >> cur.c >> cur.d;
        
        w[i] = cur;
    }
    
    
    // caso base
    for(int i = 0; i <= m; i++){
        dp[i][0] = 0; // com 0 gramas de caseina nao da pra fazer nenhum whey
    }

    for(int j = 0; j <= n; j++){
        dp[0][j] = ((int) j / nat_c) * nat_d; // com 0 sabores só dá pra fazer why natural
    }
    
    for(int i = 1; i <= m; i++){

        for(int j = 1; j<= n; j++){
            dp[i][j]  = dp[i-1][j]; // no take
            
            int max_k = min(j/ w[i -1].c, w[i-1].a/ w[i-1].b); // limita pela quantitade de caseina ou essencia

            if(dp[i][j - w[i-1].c] >= 0){
                
                for(int k = 1; k <= max_k; k++){
                    if(j - w[i -1].c * k >= 0 && dp[i-1][j - k * w[i-1].c] != -1){
                        dp[i][j] = max(dp[i][j], dp[i-1][j - k * w[i-1].c] + k * w[i-1].d); // take
                    }
                }   
            }
        }
    }
    
    
    cout << dp[m][n];
        
/*     for(int i = 0; i <= m; i++){
            for(int j = 0; j <= n; j++){
                cout << dp[i][j] << " ";
            }

            cout << endl;
    }  */
}