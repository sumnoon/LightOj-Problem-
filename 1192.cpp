///*BISMILLAHIR RAHMANIR RAHIM*///
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
	int tc, cs = 0, n, i, ans, pre, x;
	scanf("%d", &tc);
	while ( tc-- ) {
		scanf("%d", &n);
		scanf("%d", &pre);
		scanf("%d", &x);
		ans = x - pre - 1;
		for ( i = 2; i < 2*n; i++ ) {
			scanf("%d", &x);
			if ( i & 1 ) {
				ans = ans ^ ( x - pre - 1);
			}
			else pre = x;
		}
		printf("Case %d: ", ++cs);
		if ( ans != 0 ) printf("Alice\n");
		else printf("Bob\n");
	}
	return 0;
}