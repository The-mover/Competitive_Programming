/**
    In the name of Allah, the Most Gracious, the Most Merciful.
**/

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 1e3 + 4;

int dx[] = { +0, +0, +1, -1 };
int dy[] = { +1, -1, +0, +0 };
int dis[N][N], vis[N][N], n, m, k;
string s[N];

int bfs(int x1, int y1, int x2, int y2 ) {
    memset(dis, -1, sizeof dis);
    dis[x1][y1] = 0;
    vis[x1][y1] = 1;
    queue < pair < int, int > > q;
    q.push( {x1, y1} );
    while( !q.empty() ) {
        auto top = q.front();
        q.pop();
        int xx = top.first;
        int yy = top.second;
        for(int i=0; i<4; i++) {
            int tx = xx;
            int ty = yy;
            for(int j=0; j<k; j++) {
                tx += dx[i];
                ty += dy[i];
                if( tx < 0 || tx >= n || ty < 0 || ty >= m || s[tx][ty] == '#' ) break;
                if( !vis[tx][ty] ) {
                    dis[tx][ty] = dis[xx][yy] + 1;
                    vis[tx][ty] = 1;
                    q.push( {tx, ty} );
                }
                if( dis[tx][ty] < dis[xx][yy] + 1 ) break;  /// This line used for optimization
            }
        }
    }
    return vis[x2][y2] ? dis[x2][y2] : -1;
}

int main()
{
    #ifdef _OFFLINE_
        freopen("D.txt", "r", stdin);
    #endif /// _OFFLINE_

    int x1, y1, x2, y2;
    cin >> n >> m >> k;
    for(int i=0; i<n; i++) {
        cin >> s[i];
    }
    cin >> x1 >> y1 >> x2 >> y2;
    x1--;
    y1--;
    x2--;
    y2--;
    cout << bfs( x1, y1, x2, y2 ) << "\n";

    return 0;
}
