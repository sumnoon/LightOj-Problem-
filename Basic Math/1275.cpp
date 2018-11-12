///*BISMILLAHIR RAHMANIR RAHIM*///
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
	int tc, cases = 0;
	ll n, c, ans;
	scanf("%d", &tc);
	while ( tc-- ) {
		scanf("%lld %lld", &n, &c);
		if ( !n || !c ) ans = 0;
		else if ( n < c && 2 * n > c ) ans = 1;
		else if ( c % (2*n) == 0 ) ans = c/(2*n);
		else {
			ll t = c / (2*n);
			ll mx = t * ( c -  t * n );
			ans = t;
			while ( c > ( t * n ) ) {
				if ( mx < t * ( c - n * t ) ) {
					mx = max ( mx, t * ( c - n * t ) );
					ans ++;
				}
				t++;
			}
		}
		printf("Case %d: %lld\n", ++cases, ans);
	}
	return 0;
}
