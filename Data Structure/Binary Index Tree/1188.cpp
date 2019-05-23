///*BISMILLAHIR RAHMANIR RAHIM*///
#include<bits/stdc++.h>
using namespace std;
#define N 1000010
int a[N], t[N], last_visit[N], ans[50010];
struct node {
    int l, r, id;
};
node queries[50010];
bool comp ( node a, node b ) {
    return a.r < b.r;
}
int read( int idx, int n ){
    int sum=0;
    while(idx>0){
        sum += t[idx];
        idx -= (idx & -idx);
    }
    return sum;
}
void update( int idx,int x, int n ){
    while(idx<=n){
        t[idx]+=x;
        idx+=(idx&-idx);
    }
}
int query(int i,int j, int n){
    return read(j+1, n)-read(i, n);
}
int main(){
    //freopen("out.txt","w",stdout);
    int tc, cases = 0, n, q, i;
    scanf(" %d ", &tc );
    while ( tc-- ) {
        memset ( t, 0, sizeof t );
        memset ( last_visit, -1, sizeof last_visit );
        scanf(" %d %d ", &n, &q );
        for ( i = 0; i < n; i++ ) {
            scanf(" %d ", a + i );
        }
        int le, ri;
        for ( i = 0; i < q; i++ ) {
            scanf("%d %d", &le, &ri);
            queries[i].l = le - 1;
            queries[i].r = ri - 1;
            queries[i].id = i; 
        }
        sort ( queries, queries + q, comp );
        int cnt = 0;
        for ( i = 0; i < n; i++ ) {
            if ( last_visit[a[i]] != -1 ) {
                update ( last_visit[a[i]] + 1, -1, n );
            }
            last_visit[a[i]] = i;
            update ( i + 1, 1, n );
            while ( cnt < q && queries[cnt].r == i ) {
                ans[queries[cnt].id] = query ( queries[cnt].l, queries[cnt].r, n );
                cnt++;
            }
        }
        printf("Case %d:\n", ++cases);
        for ( i = 0; i < q; i++ ) {
            printf("%d\n", ans[i]);
        }
    }
    return 0;
}

