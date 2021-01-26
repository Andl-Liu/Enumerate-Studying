#include <cstdio>
#include <cstdlib>
#include <cstring>

using namespace std;

const int BIGGEST_NODE = 26;
const int MAX_LEN = 10;
int graph[BIGGEST_NODE][BIGGEST_NODE];
int degree[BIGGEST_NODE];
int permutation[MAX_LEN];
int m_permutation[MAX_LEN];
int min_width;
int max_width;
int vis[BIGGEST_NODE];
int existence[BIGGEST_NODE];
int numofnodes;

void dfs(int cur)
{
    if(cur == numofnodes)
    {
        if(max_width < min_width)
        {
            min_width = max_width;
            for(int i = 0;i < numofnodes;i++)
            {
                m_permutation[i] = permutation[i];
            }
        }
        return ;
    }

    for(int i = 0;i < BIGGEST_NODE;i++)
    {
        if(vis[i] == 1 || existence[i] == 0)
            continue;

        permutation[cur] = i;
        int width = 0;
        int numofappear = 0;
        for(int j = 0;j < cur;j++)
        {
            if(graph[permutation[j]][permutation[cur]] == 0)
                continue;
            if(width < cur - j)
                width = cur - j;
            numofappear++;
        }

        if(width > min_width || degree[i] - numofappear >= min_width)
            continue;

        int temp = max_width;
        if(width > max_width)
        {
            max_width = width;
        }
        vis[i] = 1;
        dfs(cur + 1);
        vis[i] = 0;
        max_width = temp;
    }
}

int main()
{
    char line[1000];
    while(~scanf("%s",line) && line[0] != '#')
    {
        memset(graph,0,sizeof(graph));
        memset(degree,0,sizeof(degree));
        memset(existence,0,sizeof(existence));
        char *pos = line;
        char u,v;
        u = line[0];
        existence[u - 'A'] = 1;
        pos += 2;
        while((*pos) != '\0')
        {
            if(*pos == ';')
            {
                u = *(++pos);
                existence[u - 'A'] = 1;
                pos += 2;
            }
            v = *pos;
            existence[v - 'A'] = 1;
            graph[u - 'A'][v - 'A'] = 1;
            graph[v - 'A'][u - 'A'] = 1;
            pos++;
        }
        numofnodes = 0;
        for(int i = 0;i < BIGGEST_NODE;i++)
        {
            if(existence[i] == 1)
            {
                numofnodes++;
            }
            int cnt = 0;
            for(int j = 0;j < BIGGEST_NODE;j++)
            {
                if(graph[i][j] == 1)
                {
                    cnt++;
                }
            }
            degree[i] = cnt;
        }

        min_width = 0x7fffffff;
        max_width = 0;
        memset(vis,0,sizeof(vis));
        dfs(0);
        for(int i = 0;i < numofnodes;i++)
        {
            printf("%c ",'A' + m_permutation[i]);
        }
        printf("-> %d\n",min_width);
    }
    return 0;
}
