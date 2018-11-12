///*BISMILLAHIR RAHMANIR RAHIM*///
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
	int tc, cases = 0, n, c, ans;
	scanf("%d", &tc);
	while ( tc-- ) {
		scanf("%d %d", &n, &c);
		if ( !n || !c ) ans = 0;
		else if ( n < c && 2 * n > c ) ans = 1;
		else if ( c % (2*n) == 0 ) ans = c/(2*n);
		else {
			ll t = c / (2*n);
			ll mx = t * ( c -  t * n );
			ll mx1 = (t+1)*(c - (t+1)*n);
			ans = t;
			if ( mx1 > 0 && mx1 > mx ) ans++;
		}
		printf("Case %d: %d\n", ++cases, ans);
	}
	return 0;
}
