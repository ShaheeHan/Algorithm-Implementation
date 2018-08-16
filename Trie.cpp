#include <bits/stdc++.h>

#define rep(i,n) for(i=0; i<n; i++)
#define repl(i,n) for(i=1; i<=n; i++)

#define sz(x) (int) x.size()
#define pb(x) push_back(x)

#define mem(x, y) memset(x, y, sizeof(x));
#define sf(x) scanf("%d", &x)


int setBit(int N, int pos) { return N=N | (1<<pos); }
int resetBit(int N, int pos) { return N= N & ~(1<<pos); }
bool checkBit(int N, int pos) { return (bool)(N & (1<<pos)); }

using namespace std;

typedef long long LL;
typedef unsigned long long ULL;


struct node {
    bool endFlag;
    node *next[26];

    node() {
        endFlag = false;
        mem(next, 0);
    }
} *root;

void Insert(char str[]) {
    int i, len = strlen(str);
    node *cur = root;

    rep(i, len) {
        int adr = str[i] - 'A';
        if(cur->next[adr] == NULL) cur->next[adr] = new node();
        cur = cur->next[adr];
    }

    cur->endFlag = true;
}

void del(node *cur) {
    int i;

    rep(i, 26) {
        if(cur->next[i]) del(cur->next[i]);
    }

    delete(cur);
}

int main() {
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);

    char str[1000];
    int n;

    root = new node();

    sf(n);
    while(n--) {
        gets(str);
        Insert(str);
    }

    del(root);

    return 0;
}
