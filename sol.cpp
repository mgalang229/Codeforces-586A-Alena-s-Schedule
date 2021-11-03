#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	// skip all the 0s in the beginning
	auto it = find(a.begin(), a.end(), 1);
	int cnt = 0;
	for (int i = it - a.begin(); i < n; i++) {
		int temp = i;
		int index = i;
		// traverse the sequence and count the subarray containing 0s
		// if the size of the subarray is greater than 1, then Alena will go home ('cnt' will not increase)
		// otherwise, she needs to stay in the campus ('cnt' will increase)
		// note: if the last element is a 0, then don't count it since there are no more subjects after
		while (a[index] == 0 && index < n) {
			index++;
		}
		if ((index - temp == 1 && index != n) || a[i] == 1) {
			cnt++;
		}
		// also, don't forget to change the value of 'i' (subtract 'index' by 1, since 'i' will be incremented again in the for-loop)
		if (index > i) {
			i = index - 1;
		}
	}
	cout << cnt << '\n';
	return 0;
}
