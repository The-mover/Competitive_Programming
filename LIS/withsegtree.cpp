/**
    In the name of Allah, the Most Gracious, the Most Merciful.
**/

#include <bits/stdc++.h>
using namespace std;

#define mx 100001
#define MAXI 0

int ara[mx];
int tree[mx * 3];
int dp[mx];
int ele[mx];

void init(int node, int b, int e)
{
    if (b == e) {
        tree[node] = ara[b];
        return;
    }
    int Left = node * 2;
    int Right = node * 2 + 1;
    int mid = (b + e) / 2;
    init(Left, b, mid);
    init(Right, mid + 1, e);
    tree[node] = max(tree[Left], tree[Right]);
}

int query(int node, int b, int e, int i, int j)
{
    if (i > e || j < b)
        return MAXI;
    if (b >= i && e <= j)
        return tree[node];
    int Left = node * 2;
    int Right = node * 2 + 1;
    int mid = (b + e) / 2;
    int p1 = query(Left, b, mid, i, j);
    int p2 = query(Right, mid + 1, e, i, j);
    int ans = max(p1, p2);
    return ans;
}

void update(int node, int b, int e, int i, int newvalue)
{
    if (i > e || i < b)
        return;
    if (b >= i && e <= i) {
        tree[node] = newvalue;
        return;
    }
    int Left = node * 2;
    int Right = node * 2 + 1;
    int mid = (b + e) / 2;
    update(Left, b, mid, i, newvalue);
    update(Right, mid + 1, e, i, newvalue);
    tree[node] = max(tree[Left], tree[Right]);
}

int main() {
    #ifdef _OFFLINE_
        freopen("in.txt", "r", stdin);
    #endif /// _OFFLINE_

    int n;
    cin >> n;
    for(int i=1; i<=n; i++) {
        cin >> ele[i];
    }
    memset(ara, 0, sizeof ara);
    init(1, 1, n);

    for(int i=1; i<=n; i++) {
        int val = ele[i] - 1;
        int x = query(1, 1, n, 1, val);
        dp[i] = x + 1;
        update(1, 1, n, ele[i], x + 1);
    }

    for(int i=1; i<=n; i++) {
        cout << dp[i] << " ";
    } cout << "\n";

    return 0;
}
