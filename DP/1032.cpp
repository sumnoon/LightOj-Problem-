///*BISMILLAHIR RAHMANIR RAHIM*///
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll dp[40][40][2];
vector<ll>digit;
void preprocess ( ll n ) {
    while ( n ) {
        digit.push_back( n % 2 );
        n /= 2;
    }
}
ll func ( ll pos, ll cnt, ll prev, ll flag ) {
    if ( pos < 0 ) return cnt;
    ll &ret = dp[pos][cnt][prev];
    if ( flag == 0 && ret != -1 ) return ret;
    ll limit = ( flag ) ? digit[pos] : 1;
    ll res = 0;
    for ( ll i = 0; i <= limit; i++ ) {
        if ( i && prev ) res += func ( pos - 1, cnt + 1, i, flag && i == limit );
        else res += func ( pos - 1, cnt, i, flag && i == limit );
    }
    return ret = res;
}
int main(){
    int tc, cs = 0;
    ll n, ans;
    scanf("%d", &tc);
    while (tc--) {
        scanf("%lld", &n);
        digit.clear();
        memset(dp, -1, sizeof dp);
        if ( n == 0 ) {
            printf("Case %d: 0\n", ++cs);
            continue;
        }
        preprocess(n);
        ll len = (ll)digit.size();
        ans = func ( len - 1, 0, 0, 1 );
        printf("Case %d: %lld\n", ++cs, ans);
    }
    return 0;
}
