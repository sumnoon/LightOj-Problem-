///*BISMILLAHIR RAHMANIR RAHIM*///
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int white[101], black[101];
int main () {
	freopen("out.txt","w",stdout);
	int tc, cs = 0, n, i, x, y, ans;
	scanf("%d", &tc);
	while(tc--){
		scanf("%d", &n);
		for ( i = 0; i < n; i++ ) {
			scanf("%d", white + i);
		}
		for ( i = 0; i < n; i++ ) {
			scanf("%d", black + i);
			black[i] = black[i] - white[i] - 1;
		}
		ans = black[0];
		for ( i = 1; i < n; i++ ) {
			ans = ans ^ black[i];
		}
		printf("Case %d: ", ++cs);
		if ( ans == 0 ) printf("black wins\n");
		else printf("white wins\n");
	}
	return 0;
}
