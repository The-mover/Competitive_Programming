#include<bits/stdc++.h>
using namespace std;

const int N = 1e6 + 5;

string s;
vector <string> ve;

struct node {
    int cnt;
    node* next[26 + 1];
    node() {
        cnt = 0;
        for (int i = 0; i < 26; i++)
            next[i] = NULL;
    }
} * root;

void insrt() {
    int len = s.size();
    node* cur = root;
    for (int i = 0; i < len; i++) {
        int id = s[i] - 'a';
        if (cur->next[id] == NULL) {
            cur->next[id] = new node();
        }
        cur = cur->next[id];
        cur->cnt++;
    }
}

int search_(string str)
{
    int len = str.size();
    node* curr = root;
    int ans = 0;
    int mx = 1e9 + 5;

    for (int i = 0; i < len; i++) {
        int id = str[i] - 'a';
        if (curr->next[id]->cnt < mx) {
            ans++;
            mx = curr->next[id]->cnt;
        }
        curr = curr->next[id];
    }
    return ans;
}

void del(node* cur) {
    for (int i = 0; i < 26; i++)
        if (cur->next[i])
            del(cur->next[i]);

    delete (cur);
}

int main()
{
#ifdef _OFFLINE_
    freopen("in.txt", "r", stdin);
#endif /// _OFFLINE_


    int n ;
    while(scanf("%d", &n) == 1) {
        ve.clear();
        root = new node();
        for(int i = 1; i <= n; i++) {
            char str[N];
            scanf("%s", str);
            s = str;
            insrt();
            ve.push_back(s);
        }
        int ans = 0;
        for(int i=0; i<n; i++) {
            ans += search_(ve[i]);
        }
        double res = (double)ans / n;
        printf("%.2f\n", res);

        del(root);
    }

    return 0;
}
