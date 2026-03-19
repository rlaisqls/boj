#include <iostream>
#include <vector>
using namespace std;

const int MAX=7400000;

int main() {
  int k;
  cin>>k;

  vector<bool> sieve(MAX+1,true);
  sieve[0]=sieve[1]=false;
  for(int i=2;i*i<=MAX;i++)
    if(sieve[i])
      for(int j=i*i;j<=MAX;j+=i)
        sieve[j]=false;

  int cnt=0;
  for(int i=2;i<=MAX;i++) {
    if(sieve[i]) cnt++;
    if(cnt==k) {cout<<i<<"\n";return 0;}
  }
  return 0;
}
