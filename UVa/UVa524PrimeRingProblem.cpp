#include <cstdio>
#include <cstring>

using namespace std;

const int MAX_ELEMENT = 50;
int isp[MAX_ELEMENT];
int permutation[MAX_ELEMENT];
int n;
int vis[MAX_ELEMENT];

void dfs(int cur)
{
    if(cur == n && isp[permutation[0] + permutation[n - 1]] == 0)
    {
        for(int i = 0;i < n;i++)
        {
            if(i != 0)
                printf(" ");
            printf("%d",permutation[i]);
        }
        puts("");
        return ;
    }

    for(int i = 1;i <= n;i++)
    {
        if(vis[i] == 1)
            continue;
        if(isp[permutation[cur - 1] + i] == 1)
            continue;

        permutation[cur] = i;
        vis[i] = 1;
        dfs(cur + 1);
        vis[i] = 0;
    }
}

int main()
{
    isp[0] = isp[1] = 1;
    for(int i = 2;i < MAX_ELEMENT;i++)
    {
        if(isp[i] == 0)
        {
            for(int j = 2;j * i < MAX_ELEMENT;j++)
            {
                isp[i * j] = 1;
            }
        }
    }

    int kase = 0;
    while(~scanf("%d",&n))
    {
        if(kase != 0)
            puts("");
        printf("Case %d:\n",++kase);
        memset(vis,0,sizeof(vis));
        vis[1] = 1;
        permutation[0] = 1;
        dfs(1);
    }

    return 0;
}
