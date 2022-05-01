#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;
#define N 105
#define INF 0x3f3f3f3f

struct node
{
    int x, y, t, key, snake;
    node() {}
    node(int x, int y, int t, int key, int snake) : x(x), y(y), t(t), key(key), snake(snake) {}
};
bool vis[N][N][10][40];
int n, m, sx, sy, ex, ey;
int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1};
char maze[N][N];

bool check(int x, int y)
{
    if(0<=x&&x<n&&0<=y&&y<n&&maze[x][y]!='#') return true;
    return false;
}

void bfs()
{
    int ans = INF;
    memset(vis, 0, sizeof(vis));
    queue<node> que;
    while(!que.empty()) que.pop();
    que.push(node(sx, sy, 0, 0, 0));
    while(!que.empty()) {
        node top = que.front(); que.pop();
        int x = top.x, y = top.y, key = top.key, snake = top.snake, t = top.t;
        if(key == m && maze[x][y] == 'T') {
            ans = min(ans, t);
        }
        if(vis[x][y][key][snake] != 0) continue;
        vis[x][y][key][snake] = 1;
        for(int i = 0; i < 4; i++) {
            int nx = x + dx[i], ny = y + dy[i];
            if(!check(nx, ny)) continue;
            node now = top;
            if('A' <= maze[nx][ny] && maze[nx][ny] <= 'G') {
                //只有五条蛇，不能写 <= 'Z'
                int s = maze[nx][ny] - 'A';
                if((1<<s) & now.snake) ; //如果蛇被打了
                else {
                    now.snake |= (1<<s); //没被打
                    now.t++;
                }
            } else if(maze[nx][ny] - '0' == now.key + 1) {
                now.key++;
            }
            now.t++;
            que.push(node(nx, ny, now.t, now.key, now.snake));
        }
    }
    if(ans != INF) printf("%d\n", ans);
    else printf("impossible\n");
}

int main()
{
    while(~scanf("%d%d", &n, &m), n+m) {
        int cnt = 0;
        for(int i = 0; i < n; i++) {
            scanf("%s", maze[i]);
        }
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(maze[i][j] == 'K') sx = i, sy = j;
                if(maze[i][j] == 'S') {maze[i][j] = cnt+'A'; cnt++;}
            }
        }
        bfs();
    }
    return 0;
}

/*
4 2
KS1.
2SS.
SSSS
STSS
0 0
*/
