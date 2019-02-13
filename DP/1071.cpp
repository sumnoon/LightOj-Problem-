///*BISMILLAHIR RAHMANIR RAHIM*///
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[101][101], dp[101][101][101][3], n, m;
ll func ( ll i, ll j1, ll j2, ll way ) {
	if ( i == n && j1 == m - 1 && j2 == m && way == 0 ) return 0;
	ll &ret = dp[i][j1][j2][way];
	if ( ret != -1 ) return ret;
	ret = 0;
	if ( way == 2 ) {
		if ( j1 < j2 && i + 1 <= n ) ret = max ( ret, func ( i + 1, j1, j2, 0 ) + a[i+1][j1] + a[i+1][j2] );
	}
	else if ( way == 0 ) {
		if ( j1 + 1 < j2 ) ret = max ( ret, func ( i, j1 + 1, j2, 0 ) + a[i][j1+1] );
		ret = max ( ret, func ( i, j1, j2, 1 ) );
	}
	else {
		if ( j2 + 1 <= m ) ret = max ( ret, func ( i, j1, j2 + 1, 1 ) + a[i][j2+1] );
		if ( j2 > j1 ) ret = max ( ret, func ( i, j1, j2, 2)) ;
	}
	return ret;
}
int main() {
	int tc, cases = 0;
	ll i, j, ans;
	scanf("%d", &tc);
	while (tc--) {
		scanf("%lld %lld", &n, &m);
		for ( i = 1; i <= n; i++ ){
			for ( j = 1; j <= m; j++ ){
				scanf("%lld", &a[i][j]);
			}
		}
		memset( dp, -1, sizeof dp );
		ans = func ( 1, 1, 1, 0 ) + a[1][1];
		printf("Case %d: %lld\n", ++cases, ans); 
	}
	return 0;
}
