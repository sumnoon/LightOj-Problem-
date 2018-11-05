///*BISMILLAHIR RAHMANIR RAHIM*///
#include <bits/stdc++.h>
using namespace std;
#define N 500*500 + 10
typedef long long ll;
const int K = 26;
int ch[N][K], val[N], f[N], freq[N], last[N], ss, ind;
map<string, int>chk;
void insert ( string s ) {
	int u = 0;
	for ( char x : s ) {
		int c = x - 'a';
		if ( !ch[u][c] ) {
			ch[u][c] = ++ss;
			val[ss] = 0; 
		}
		u = ch[u][c];
	}
	val[u] = ind; // index of where i'th string has ended.
} 
void build_fail() {
	queue<int>q;
	int i;
	f[0] = 0; // f gives the index where we should go after we failed to traverse from i'th node
	for ( i = 0; i < 26; i++ ) {
		int u = ch[0][i];
		if ( u ){
			f[u] = 0;
			q.push(u);
			last[u] = 0;
		}
	}
	int r, u, v;
	while ( !q.empty() ) {
		r = q.front();
		q.pop();
		for ( int c = 0; c < 26; c++ ) {
			u = ch[r][c];
			if(!u)continue;
			q.push(u);
			v = f[r];
			while ( v && ch[v][c] == 0 ) v = f[v];
			f[u] = ch[v][c];

			last[u] = val[f[u]] ? f[u] : last[f[u]];
			// cout << u << " = " << f[u] << " & " << last[u]<< endl;
		}
	}
}
void print(int j ) {
	if ( j ) {
		++freq[val[j]]; // recursively increase frequency of each leaf
		print(last[j]);
	}
}
void search ( string s ) {
	int j = 0;
	for ( int i = 0; i < s.length(); i ++ ) {
		int c = s[i] - 'a';
		while ( j && ch[j][c] == 0 ) {
			j = f[j];
		}
		j = ch[j][c];
		if ( val[j] ) print(j);
		else if ( last[j] ) print(last[j]);
	}
}

void clr() {
	ind = 0, ss = 0;
	memset(ch, 0, sizeof ch);
	memset(freq, 0, sizeof freq);
	chk.clear();
}
string pat[N];
int main () {
	// freopen("in.txt","r",stdin);
	// freopen("out.txt","w",stdout);
	int tc, cases = 0, n, i;
	string txt;
	scanf("%d", &tc);
	while ( tc-- ) {
		clr();
		scanf("%d", &n);
		cin >> txt;
		for ( i = 1; i <= n; i++ ) {
			cin >> pat[i];
			if ( chk.count(pat[i]))continue;
			chk[pat[i]] = i;
			ind = i;
			insert(pat[i]);
		}
		build_fail();
		search(txt);
		printf("Case %d:\n", ++cases);
		for ( i = 1; i <= n; i++ ) {
			printf("%d\n", freq[chk[pat[i]]]);
		}
	}
	return 0;
}
