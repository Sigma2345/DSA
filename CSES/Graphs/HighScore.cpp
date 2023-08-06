#include <bits/stdc++.h>
using namespace std;
#define int long long
#define minval -1e17

signed main() {

#ifndef ONLINE_JUDGE
  freopen("input.txt", "r",
          stdin); // file input.txt is opened in reading mode i.e "r"
  freopen("output.txt", "w",
          stdout); // file output.txt is opened in writing mode i.e "w"
#endif

  int n, m;
  cin >> n >> m;

  // since we need to take maximum score reverse the path weights
  // and calculate minimum weight possible
  vector<vector<int>> v;
  vector<vector<int>> adj1(n + 1);
  vector<bool> vis1(n+1, false); 
  for (int i = 0; i < m; i++) {
    int x, y, dist;
    cin >> x >> y >> dist;
    v.push_back({x, y, dist});
    adj1[v[i][0]].push_back(v[i][1]);
  }

  queue<int> q1;
  q1.push(1);
  vis1[1] = true;
  while (!q1.empty()) {
    int x = q1.front();
    q1.pop();
    for (int y : adj1[x]) {
      if (!vis1[y]) {
        q1.push(y);
        vis1[y] = true ;
	  }
	}
  }

  vector<int> distFromSrc(n + 1, minval);
  distFromSrc[1] = 0;
  for (int i = 0; i < n - 1; i++) {
    for (int j = 0; j < v.size(); j++) {
      if (distFromSrc[v[j][1]] < distFromSrc[v[j][0]] + v[j][2])
        distFromSrc[v[j][1]] = distFromSrc[v[j][0]] + v[j][2];
    }
  }

  vector<bool> affected(n + 1);
  for (int j = 0; j < v.size(); j++) {
    if (distFromSrc[v[j][1]] < distFromSrc[v[j][0]] + v[j][2])
      affected[v[j][1]] = true;
  }

  vector<vector<int>> h(n + 1);
  for (int i = 0; i < v.size(); i++) {
    h[v[i][1]].push_back(v[i][0]);
  }

  vector<int> vis(n + 1, false);
  vis[n] = true;
  queue<int> q;
  q.push(n);
  while (!q.empty()) {
    auto x = q.front();
    if (affected[x] && vis1[x]) {
      cout << -1 << endl;
      return 0;
    }
    q.pop();
    for (int y : h[x]) {
      if (!vis[y] )   {
        vis[y] = true;
        q.push(y);
      }
    }
  }

  //   for (int i = 1; i <= n; i++) {
  //     cout << distFromSrc[i] << ' ' << newDist[i] << endl;
  //   }
  cout << distFromSrc[n] << endl;

  return 0;
}