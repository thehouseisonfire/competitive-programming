#include <bits/stdc++.h>
using namespace std;
 
const int MAX = 100005;
const int LIM = 263005;
 
#define inchar          getchar_unlocked
#define outchar(x)      putchar_unlocked(x)
 
template<typename T> void inpos(T &x){x=0;register T c=inchar();while(((c<48)||(c>57))&&(c!='-'))c=inchar();bool neg=false;if(c=='-')neg=true;for(;c<48||c>57;c=inchar());for(;c>47&&c<58;c=inchar())x=(x<<3)+(x<<1)+(c&15);if(neg)x=-x;}
template<typename T> void outpos(T n){if(n<0){outchar('-');n*=-1;}char snum[65];int i=0;do {snum[i++]=n%10+'0';n/=10;}while(n);i=i-1;while(i>=0)outchar(snum[i--]);outchar('\n');}
 
int inp[MAX];
vector< pair<int,int> > nums;
vector<int> seg[LIM];
 
void build_merge_sort(int t, int i, int j) {
	if (i==j) {
		seg[t].push_back(nums[i].second);
		return ;
	}
	int left = t<<1, right = left|1, mid = (i+j)/2;
	build_merge_sort(left, i, mid);
	build_merge_sort(right, mid+1, j);
	merge(seg[left].begin(), seg[left].end(), seg[right].begin(), seg[right].end(), back_inserter(seg[t]));
}
 
int query_kth(int t, int i, int j, int l, int r, int k) {
	if (i == j) {
		return seg[t][0];
	}
	int left = t<<1, right = left|1, mid = (i+j)/2, total;
	auto it = upper_bound(seg[left].begin(), seg[left].end(), r);
	total = it - lower_bound(seg[left].begin(), seg[left].end(), l);
	if (total >= k) {
		return query_kth(left, i, mid, l, r, k);
	}
	else {
		return query_kth(right, mid+1, j, l, r, k-total);
	}
}
 
int main() {
	int n, m, x, y, k, idx, ans;
	inpos(n), inpos(m);
	for(int i=0; i<n; ++i) {
		inpos(x);
		inp[i] = x;
		nums.push_back(make_pair(x, i));
	}
	sort(nums.begin(), nums.end());
	build_merge_sort(1, 0, n-1);
	while (m--) {
		inpos(x), inpos(y), inpos(k);
		--x; --y;
		idx = query_kth(1, 0, n-1, x, y, k);
		ans = inp[idx];
		outpos(ans);
	}
	return 0;
} 