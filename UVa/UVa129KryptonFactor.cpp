#include <cstdio>
#include <cstring>

using namespace std;

const int MAX_LEN = 100;
int sequence[MAX_LEN];
int n,l,cnt;

int dfs(int cur)
{
    if(cnt == n)
    {
        for(int i = 0;i < cur;i++)
        {
            if(i != 0 && i % 4 == 0)
            {
                if(i / 4 % 16 == 0)
                    printf("\n");
                else
                    printf(" ");
            }
            printf("%c",'A' + sequence[i]);
        }
        puts("");
        printf("%d\n",cur);
        return 1;
    }

    for(int i = 0;i < l;i++)
    {
        sequence[cur] = i;
        if(cur != 0)
        {
            int ok = 0;
            for(int j = 1;j * 2 <= cur + 1;j++)
            {
                int equ = 1;
                for(int p = 0;p < j;p++)
                {
                    if(sequence[cur - p] != sequence[cur - p - j])
                        break;
                    if(p + 1 == j)
                        equ = 0;
                }
                if(equ == 0)
                {
                    ok = 1;
                    break;
                }
            }
            if(ok == 1)
                continue;
        }

        cnt++;
        if(dfs(cur + 1) == 1)
            return 1;
    }
    return 0;
}

int main()
{
    while(~scanf("%d%d",&n,&l) && n != 0 && l != 0)
    {
        cnt = 0;
        dfs(0);
    }
    return 0;
}
