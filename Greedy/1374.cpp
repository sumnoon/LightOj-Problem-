///*BISMILLAHIR RAHMANIR RAHIM*///
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int a[10010];
bool check[10010];
int main(){
	int tc, cases = 0, n, i;
	bool flag1, flag2;
	scanf("%d", &tc);
	while ( tc-- ) {
		memset(check, false, sizeof check);
		flag1 = true;
		scanf("%d", &n);
		for ( i = 0; i < n; i++ ) {
			scanf("%d", a + i );
			if ( a[i] > n - 1 ) flag1 = false;
		}
		sort ( a, a + n );
		
		for ( i = 0; i < n; i++ ) {
			int x = a[i];
			if ( check[x] == false ) {
				check[x] = true;
			}
			else if ( check[n-x-1] == false ) {
				check[n-x-1] = true;
			}
			else {
				// cout << x << endl;
				// cout << check[4] << endl;
				flag1 = false;
				break;
			}
		}

		if ( flag1 ) printf("Case %d: yes\n", ++cases);
		else printf("Case %d: no\n", ++cases);
	}
	return 0;
}
