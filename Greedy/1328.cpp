///*BISMILLAHIR RAHMANIR RAHIM*///
#include <bits/stdc++.h>
using namespace std;
#define mod 1000007
typedef long long ll;
ll a[100010], sum[100010];
int main() {
	int tc, cases = 0;
	ll n, k, c, i, ans;
	scanf("%d", &tc);
	while ( tc-- ) {
		ans = 0;
		memset(sum, 0ll, sizeof sum);
		scanf("%lld %lld %lld %lld", &k, &c, &n, &a[0]);
		for ( i = 1; i < n; i++ ) {
			ll tmp = ( k * a[i-1] ) % mod ;
			a[i] = ( ( tmp + c ) ) % mod;
			// cout << a[i] << " ";
		}
		sort(a, a + n);
		sum[0] = a[0];
		for ( i = 1; i < n; i++ ) {
			sum[i] = sum[i-1] + a[i]; 
		}
		for ( i = 0; i < n; i++ ) {
			ans += abs ( ( n - i ) * a[i] - sum[n-1] + sum[i-1] );
		}
		printf("Case %d: %lld\n", ++cases, ans);
	}
	return 0;
}
