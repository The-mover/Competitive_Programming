/**
    In the name of Allah, the Most Gracious, the Most Merciful.
**/

#include <bits/stdc++.h>
using namespace std;

#define MAXI 0
const int mx = 1e5 + 10;
int ara[mx];
int tree[mx * 4];
int dp1[mx];
int dp2[mx];
int ele[mx];
int elem[mx];
int mn_ara[mx];

void init(int node, int b, int e) {
    if (b == e) {
        tree[node] = 0;
        return;
    }
    int Left = node * 2;
    int Right = node * 2 + 1;
    int mid = (b + e) / 2;
    init(Left, b, mid);
    init(Right, mid + 1, e);
    tree[node] = max(tree[Left], tree[Right]);
}

int query(int node, int b, int e, int i, int j) {
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

void update(int node, int b, int e, int i, int newvalue) {
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
        //freopen("out.txt", "w", stdout);
    #endif /// _OFFLINE_

/**
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
**/

    int t, n, cs = 0;
    scanf( "%d", &t );
    while( t-- && scanf("%d", &n) == 1 ) {

        for(int i=1; i<=n; i++) {
            scanf("%d", &ele[i]);
            elem[i] = ele[i];
        }
        sort( elem + 1, elem + 1 + n );
        for( int i=1; i<=n; i++ ) {
            ele[i] = lower_bound( elem + 1, elem + 1 + n, ele[i] ) - elem;
        }
//        cerr << n << "\n";
        memset(ara, 0, sizeof ara);
        memset(dp1, 0, sizeof dp1);
        memset(dp2, 0, sizeof dp2);
        memset(mn_ara, 0, sizeof mn_ara);

        init(1, 1, n);
        for(int i=1; i<=n; i++) {
            int val = ele[i] - 1;
            int x = query(1, 1, n, 1, val);
            dp1[i] = x + 1;
            update(1, 1, n, ele[i], x+1);
        }
//        for(int i=1; i<=n; i++) {
//            cerr << dp1[i] << " ";
//        } cerr << endl;

        reverse(ele+1, ele+n+1);

        memset(ara, 0, sizeof ara);
        init(1, 1, n);

        for(int i=1; i<=n; i++) {
            int val = ele[i] - 1;
            int x = query(1, 1, n, 1, val);
            dp2[i] = x + 1;
            update(1, 1, n, ele[i], dp2[i]);
        }

        reverse(dp2+1, dp2+n+1);

//        for(int i=1; i<=n; i++) {
//            cerr << dp2[i] << " ";
//        } cerr << endl;

        for(int i=1; i<=n; i++) {
            mn_ara[i] = min(dp1[i], dp2[i]);
        }

        int MINI = 0;
        for(int i=1; i<=n; i++) {
            MINI = max(mn_ara[i], MINI);
        }
        //cerr << MINI << "\n";
        printf("Case %d: %d\n", ++cs, MINI * 2 - 1);
    }

    return 0;
}

/// LIS Lagbe
/// First of all amra number gulake compress kore felbo
/// Then nLogN e amra LIS ber korbo initial array er
/// dp1 array te save kore rakhbo amra LIS er value gula
/// Seg tree abar initialize korbo
/// initial array ja chilo setake amra reverse kore felbo
/// then nLogN e LIS ber kore dp2 te save kore rakbo
/// mn_ara te save kore rakbo dp1 and dp2 er minimum value gula
/// mn_ara theke maximum element ta pick korbo
/// and print kore dibo MINI * 2 - 1
