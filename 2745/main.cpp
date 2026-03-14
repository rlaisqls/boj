#include <iostream>
#include <string>
#include <cmath>
#include <map>
using namespace std;

int res=0;
map<char,int> num;
void init() {
  for (char c='0';c<='9';c++) num[c]=c-'0';
  for (char c='A';c<='Z';c++) num[c]=c-'A'+10;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  init();

  string n;
  int b;
  cin>>n>>b;
  for (int i=0;i<n.length();i++) {
    res += pow(b, i) * num[n[n.length()-1-i]];
  }
  cout<<res;
  return 0;
}
