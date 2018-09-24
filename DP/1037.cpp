///*BISMILLAHIR RAHMANIR RAHIM*///
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int dp[(1<<16)+5], health[16], power[16][16];
int n;
int func ( int mask ) {
	if ( mask == ( 1 << n ) - 1 ) return 0;
	if ( dp[mask] != -1 ) return dp[mask];
	dp[mask] = INT_MAX;
	for ( int i = 0; i < n; i++ ) {
		if ( !(mask & ( 1 << i ) ) ) {
			for ( int j = 0; j < n; j++ ) {
				if ( mask & (1 << j) ) {
					if ( power[j][i] == 0 ) continue;
					int need = ( health[i] ) / power[j][i];
					if ( health[i] % power[j][i] ) need++;
					dp[mask] = min ( dp[mask], need + func ( mask | ( 1 << i ) ) );
				}
			}
			dp[mask] = min ( dp[mask], health[i] + func ( mask | ( 1 << i ) ) );
		}
	}
	return dp[mask];
}
int main () {
	int tc, cs = 0, i, j, ans, res;
	char c;
	scanf ("%d", &tc);
	while(tc--){
		scanf("%d", &n);
		memset( dp, -1, sizeof dp );
		for ( i = 0; i < n; i++ ) {
			scanf("%d", health + i);
		}
		for ( i = 0; i < n; i++ ) {
			for ( j = 0; j < n; j++ ) {
				cin >> c;
				power[i][j] = c - '0';
			}
		}
		ans = INT_MAX;
		for ( i = 0; i < n; i++ ) {
			res = health[i] + func ( 1 << i );
			ans = min ( ans, res );
		}
		printf("Case %d: %d\n", ++cs, ans);
	}
	return 0;
}