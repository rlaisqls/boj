#include <iostream>
#include <string>
#include <set>
using namespace std;

int main() {
  string s;
  cin>>s;
  set<string> st;
  int n=s.size();

  for(int i=0;i<n;i++)
    for(int j=1;j<=n-i;j++)
      st.insert(s.substr(i,j));

  cout<<st.size()<<"\n";
  return 0;
}
