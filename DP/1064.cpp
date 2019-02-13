///*BISMILLAHIR RAHMANIR RAHIM*///
#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
ll dp[26][150], x;
ll func ( ll left, ll tot ) {
	if ( left == 0 ) {
		if ( tot >= x ) return 1;
		else return 0;
	}
	if ( dp[left][tot] != -1 ) return dp[left][tot];
	ll &ret = dp[left][tot];
	ret = 0;
	for ( ll i = 1; i <= 6; i++ ) {
		ret += func ( left - 1, i + tot );
	}
	return ret;
}
ll gcd ( ll a, ll b ) {
	if ( b == 0 ) return a;
	else return gcd ( b, a % b );
}
int main() {
	int tc, cases = 0;
	ll n, up, down;
	scanf("%d", &tc);
	while (tc--) {
		memset( dp, -1, sizeof dp );
		scanf("%llu %llu", &n, &x);
		up = func ( n, 0 );
		down = 1;
		for ( int i = 0; i < n; i++ ) down *= 6;
		ll gc = gcd ( up, down );
		up /= gc, down /= gc;
		if ( down == 1 || up == 0 )printf("Case %d: %llu\n", ++cases, up);
		else printf("Case %d: %llu/%llu\n", ++cases, up, down);
	}
	return 0;
}
