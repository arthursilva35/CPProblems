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
        dp[i][0] = 0; 
    }
    
    
    for(int i = 1; i <= m; i++){
        for(int j = 1; j<= n; j++){
            dp[i][j]  = dp[i-1][j];
            

            if(j - w[i-1].c >= 0 && w[i-1].a >= w[i-1].b && dp[i-1][j- w[i-1].c] != -1){
                dp[i][j] = max(dp[i][j], dp[i-1][j - w[i-1].c] + w[i-1].d);            
                
            }

            else if(j - w[i-1].c > 0 && dp[i][j- w[i-1].c] != -1 ){ // testa repetição de elementos
                if(w[i-1].a >= w[i-1].b * (int) j/(j-w[i-1].c)){
                    dp[i][j] = max(dp[i][j], dp[i][j - w[i-1].c] + w[i-1].d);
                }
            }
            
            if(j - nat_c >= 0){ // da pra fazer whey natural
                dp[i][j] = max(dp[i][j], ((int) (j / nat_c)) * nat_d); // vale a pena fazer whey natural ou nao
                
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
