int V,E;

#define MAXN 1024
#define MAXV 10

int dp[MAXN][MAXV];
vector<vi> dist;


int numOfHamWalks(){
    memset(dp, 0, sizeof(dp));
    for (int i=0; i<V; i++) {
        dp[1<<i][i] = 1;
    }
    for (int msk = 1; msk<(1<<V); msk++) { //dist[i][j] = 1 if there is a path 0 otherwise
        for (int cur = 0; cur<V; cur++) {
            if ( (msk & (1<<cur) ) == 0) {
                continue;
            }
            for (int nxt = 0; nxt<V; nxt++) {
                
                if (cur == nxt || (msk&(1<<nxt)) || dist[cur][nxt] == 0) {
                    continue;
                }else{
                    dp[msk][cur] += dp[msk^(1<<cur)][nxt];
                }
            }
        }
        
    }
    int ans = 0;
    for (int i=0; i<V; i++) {
        ans+=dp[(1<<V)-1][i];
    }
    return ans;
}


