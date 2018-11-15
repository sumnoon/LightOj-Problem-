///*BISMILLAHIR RAHMANIR RAHIM*///
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll x[50005], y[50005];
int main(){
	int tc, cases = 0;
	ll m, n, q, i, u, v, total, w, ans, ansx, ansy;
	scanf("%d", &tc);
	while ( tc-- ) {
		for ( i = 0; i < 50000; i++ ) {
			x[i] = 0, y[i] = 0;
		}
		scanf("%lld %lld %lld", &m, &n, &q);
		total = 0;
		for ( i = 0; i < q; i++ ) {
			scanf("%lld %lld %lld", &u, &v, &w);
			x[u] += w, y[v] += w, total += w;
		}
		ans = 0;
		for ( ansx = 0; ansx < 50000 && (ans << 1) < total; ansx++ ) {
			ans += x[ansx];
		}
		ans = 0;
		for ( ansy = 0; ansy < 50000 && (ans << 1) < total; ansy++ ) {
			ans += y[ansy];
		}
		printf("Case %d: %lld %lld\n", ++cases, ansx - 1, ansy - 1);
	}
	return 0;
}
