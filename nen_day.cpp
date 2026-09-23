#include <bits/stdc++.h>
#define int unsigned long long
using namespace std;
const int maxn = 1e5+5;
int n, a[maxn], poww[maxn], p2[18];
signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	p2[0]=1; for (int i=1; i<18; i++) p2[i]=p2[i-1]*2;
	for (int i=1; i<maxn; i++){
		int tmp=0;
		for (int j=1; j<18; j++){
			tmp+=(i/p2[j]);
		}
		poww[i]=tmp;
	}
	int res=0;
	cin>>n; int k=n-1;
	for (int i=1; i<=n; i++){
		cin>>a[i];
		if(poww[k]-poww[i-1]-poww[k-i+1]<=0){
			res^=a[i];
		}
	}
	cout<<res;
	return 0;
}
