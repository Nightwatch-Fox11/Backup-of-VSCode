// 预处理，map
#include <bits/stdc++.h>
using namespace std;
map<int, int> mp;
int a[2010][2010];
int b[2016];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m, i, j, q, l, r;
    cin >> n >> m;
    for (i = 1; i <= n; i++)
        cin >> b[i];
    for (i = 1; i <= n; i++)
    {
        mp.clear();
        for (j = i; j <= n; j++)
        {
            mp[b[j]]++;
            a[i][j] = mp.size();
        }
    }
    cin >> q;
    while (q--)
    {
        cin >> l >> r;
        cout << a[l][r] << endl;
    }
    return 0;
}

/* 法二
dp[i][j] 表示第i天到第j天做了多少种运动

#include <stdio.h>
#include <string.h>
#include <algorithm>
#define LL long long
using namespace std;
int dp[2010][2010], a[2010], visit[2010];
int main()
{
    int n, m, q, l, r, i, j;
    scanf("%d%d", &n, &m);
    for (i = 1; i <= n; i++)
    {
        scanf("%d", &a[i]);
        dp[i][i] = 1;
    }
    for (i = 1; i <= n; i++)
    {
        memset(visit, 0, sizeof(visit));
        visit[a[i]] = 1;
        for (j = i + 1; j <= n; j++)

        {
            if (!visit[a[j]])
                dp[i][j] = dp[i][j - 1] + 1;
            else
                dp[i][j] = dp[i][j - 1];
            visit[a[j]] = 1;
        }
    }
    scanf("%d", &q);
    while (q--)
    {
        scanf("%d%d", &l, &r);
        printf("%d\n", dp[l][r]);
    }
    return 0;
}

法三
dp[i][j] 表示第1天到第i天做了多少天运动j

#include <stdio.h>
#include <string.h>
#include <algorithm>
#define LL long long
using namespace std;
int dp[2010][110];
int main()
{
    int n, m, q, l, r, u;
    int i, j;
    scanf("%d%d", &n, &m);
    for (i = 1; i <= n; i++)
    {
        scanf("%d", &u);
        dp[i][u] = 1;
        for (j = 1; j <= m; j++)
            dp[i][j] += dp[i - 1][j];
    }
    scanf("%d", &q);
    while (q--)
    {
        scanf("%d%d", &l, &r);
        int sum = 0;
        for (i = 1; i <= m; i++)
            if (dp[l - 1][i] < dp[r][i])
                sum++;
        printf("%d\n", sum);
    }
    return 0;
}


法四：线段树

法五：
前缀和思想
在输入的时候直接维护ans[ i ][ j ]，表示在[1,i ]中j 出现了多少次，维护的时候注意把前一个的所有信息都要维护的这一项；
然后每次询问扫M，判断ans[ y ][ i ]-ans[ x-1 ][ i ]是否大于0 。用cott计数；
#include <cstdio>
#include <cstring>
#define LOCAL
using namespace std;
int ans[2002][108];
int main()
{
    #ifdef LOCAL
    freopen("a.txt","r",stdin);
    #endif // LOCAL
    int N,M,Q,x,y,cott,n;
    scanf("%d%d",&N,&M);
    memset(ans,0,sizeof(ans));
    for(int i=1;i<=N;i++){
        scanf("%d",&n);                                //原来的n[maxn]也可以省掉了
        ans[i][n]++;
        for(int j=1;j<=M;j++) ans[i][j]+=ans[i-1][j];  //边输入边维护 前面的所有信息都要维护过来1-M的出现次数
        //前面用了j<i，i可能很大，不越界才怪,改的时候，不要漏地方没改
    }
 
    scanf("%d",&Q);
    while(Q--){
        cott=0;
        scanf("%d%d",&x,&y);
        for(int i=1;i<=M;i++){
            if((ans[y][i]-ans[x-1][i])>0) cott++;    //注意索引
        }
        printf("%d",cott);
        if(Q) printf("\n");
    }
    return 0;
}
*/