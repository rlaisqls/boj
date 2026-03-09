#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n,m;
  cin>>n>>m;

  map<string,int> words;
  for (int i=0;i<n;i++) {
    string s;
    cin>>s;
    if (s.length()<m) continue;
    words[s]++;
  }

  vector<pair<string,int>> v(words.begin(), words.end());
  sort(v.begin(), v.end(), [](const pair<string,int>& a, const pair<string,int>& b) {
    if (a.second != b.second) return a.second > b.second;
    if (a.first.size() != b.first.size()) return a.first.size() > b.first.size();
    return a.first < b.first;
  });

  for (auto& p : v) cout<<p.first<<'\n';

  return 0;
}
