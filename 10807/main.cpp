#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,m;
    int arr[101];
    cin>>n;
    for (int i=0;i<n;i++) {
        cin>>arr[i];
    }
    cin>>m;

    int cnt=0;
    for (int i=0;i<n;i++) {
        if (arr[i]==m) {
            cnt++;
        }
    }

    cout<<cnt;
    return 0;
}
