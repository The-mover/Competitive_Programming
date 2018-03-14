#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 1e5 + 5;
const int B = 31;

struct node {
        node *next[2];
        int freq;
        node() {
                freq = 0;
                next[0] = next[1] = NULL;
        }
} *root;

void Add(int x) {
        node *cur = root;
        for(int i=B-1; i>=0; i--) {
                int b = (x >> i) & 1;
                if( cur->next[b] == NULL) {
                        cur->next[b] = new node();
                }
                cur = cur->next[b];
                cur->freq++;
        }
}

void Erase(node *cur, int x, int p) {
        if( cur == NULL || p == -1 ) {
                return;
        }
        int b = (x >> p) & 1;

        Erase(cur->next[b], x, p-1);

        if(cur->next[b]->freq - 1 == 0) {
                cur->next[b] = NULL;
        }
        else {
                cur->next[b]->freq--;
        }
}

int cal(int x) {
        node *cur = root;
        int res = 0;
        for(int i=B-1; i>=0; i--) {
                int b = (x >> i) & 1;
                if( cur->next[b^1] == NULL ) {
                        cur = cur->next[b];
                }
                else {
                        res += 1 << i;
                        cur = cur->next[b^1];
                }
        }
        return res;
}

int main() {
        #ifdef _OFFLINE_
                freopen("in.txt", "r", stdin);
        #endif /// _OFFLINE_

        int q;
        cin >> q;
        root = new node();
        Add(0);
        for(int i=1; i<=q; i++) {
               char t;
               int x;
               cin >> t >> x;
               if( t == '+') {
                        Add(x);
               }
               else if( t == '-') {
                        Erase(root, x, B-1);
               }
               else if( t == '?') {
                        int ans = cal(x);
                        cout << ans << "\n";
               }
        }

        return 0;
}
