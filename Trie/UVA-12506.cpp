/**
    In the name of Allah, the Most Gracious, the Most Merciful.
**/

#include <bits/stdc++.h>
using namespace std;

struct node {
    int cnt;
    node* next[26 + 1];
    node() {
        cnt = 0;
        for(int i = 0; i < 26; i++) {
            next[i] = NULL;
        }
    }
} * root;

void _insert(string str, int len) {
    node* curr = root;
    for(int i = 0; i < len; i++) {
        int id = str[i] - 'a';
        if(curr->next[id] == NULL)
            curr->next[id] = new node();
        curr = curr->next[id];
        curr->cnt++;
    }
}

int _search(string str, int len) {
    node* curr = root;
    int ans = 0;
    for (int i = 0; i < len; i++) {
        int id = str[i] - 'a';
        if(curr->next[id]->cnt == 1) {
            return ans+1;
        }
        curr = curr->next[id];
        ans++;
    }
}

void del(node* cur) {
    for (int i = 0; i < 26; i++)
        if (cur->next[i])
            del(cur->next[i]);

    delete (cur);
}

int main() {
    #ifdef _OFFLINE_
        freopen("in.txt", "r", stdin);
    #endif /// _OFFLINE_

    int t, n;
    cin >> t;
    while( t-- ) {
        root = new node();
        cin >> n;
        string ara[n+5], s;
        for(int i=0; i<n; i++) {
            cin >> s;
            ara[i] = s;
            int len = s.size();
            _insert(s, len);
        }
        int sum = 0;
        for(int i=0; i<n; i++) {
            string s = ara[i];
            int len = s.size();
            int val = _search(s, len);
            sum += val;
        }
        cout << sum << "\n";
        del(root);
    }

    return 0;
}

