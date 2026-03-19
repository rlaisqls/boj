#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  string a;
  getline(cin,a);
  string b;
  getline(cin,b);

  int cnt=0;
  istringstream iss(a);
  string t;
  while(iss>>t) {
    if(t!=b&&t.size()>=b.size()&&t.compare(0,b.size(),b)==0) {
      cnt++;
    }
  }

  cout<<cnt<<"\n";
  return 0;
}
