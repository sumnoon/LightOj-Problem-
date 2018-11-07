///*BISMILLAHIR RAHMANIR RAHIM*///
#include <bits/stdc++.h>
using namespace std;
#define N 1001
int a[N], dp[N][2], n;
int func ( int pos, int yes ) {
	if ( pos >= n ) return 0;
	if ( pos == n - 1 ) {
		if ( yes ) return a[pos];
		else return 0;
	} 
	int &ret = dp[pos][yes];
	if ( ret != -1 ) return ret;
	return ret = max ( func ( pos + 1, yes ), a[pos] + func ( pos + 2, yes ) );
}
int main(){
	int tc, cases = 0, i, ans;
	scanf("%d", &tc);
	while(tc--){
		memset(dp, -1, sizeof dp);
		scanf("%d", &n);
		for ( i = 0; i < n; i++ ) {
			scanf("%d", a + i );
		}
		ans = max ( func ( 0, 0 ), func ( 1, 1 ) );
		printf("Case %d: %d\n", ++cases, ans );
	}
	return 0;
}