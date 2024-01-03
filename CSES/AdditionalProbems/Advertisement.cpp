#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
	int n;
	cin >> n;
	vector<ll> heights(n);
	for (ll &i : heights) { cin >> i; }

	stack<int> mono_stack;
	vector<ll> area(n, 0);

	// left to right
	for (int i = 0; i < n; i++) {
		while (!mono_stack.empty() && heights[mono_stack.top()] >= heights[i]) {
			mono_stack.pop();
		}
		int width = i - (mono_stack.empty() ? -1 : mono_stack.top());
		area[i] += width * heights[i];
		mono_stack.push(i);
	}
	while (!mono_stack.empty()) { mono_stack.pop(); }

	// right to left
	for (int i = n - 1; i >= 0; i--) {
		while (!mono_stack.empty() && heights[mono_stack.top()] >= heights[i]) {
			mono_stack.pop();
		}
		int width = (mono_stack.empty() ? n : mono_stack.top()) - i;
		area[i] += (width - 1) * heights[i];
		mono_stack.push(i);
	}

	cout << *max_element(area.begin(), area.end()) << endl;
}