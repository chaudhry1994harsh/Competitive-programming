#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<unordered_set>
#include<cmath>
#include<cstring>

using namespace std; 


int main() {
	int cases, n, q, x, y;
	scanf("%i", &cases);

	for(int tt = 1; tt <= cases; tt++) {
		scanf("%i %i", &n, &q);
		vector<int> pre(n+1);
		scanf("%i", &x);
		pre[0] = 0; pre[1] = 1;
		for(int i = 1; i < n; i++) {
			scanf("%i", &y);
			if (y != x)
				pre[i+1] = pre[i] + 1;
			else
				pre[i+1] = pre[i];
			x = y;
		}
		printf("Case %i:\n", tt);
		for(int i = 0; i < q; i++) {
			scanf("%i %i", &x, &y);
			if (pre[x] != pre[x-1])
				printf("%i\n", pre[y] - pre[x-1]);
			else
				printf("%i\n", pre[y] - pre[x-1] + 1);
		}
	}
	return 0;
}
//code from online source, I had a very similar approch but dont know why it did not work 