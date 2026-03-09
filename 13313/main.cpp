#include <iostream>
using namespace std;

int main() {
    int n=33;
    int m=6+27*2+3+4;

    cout<<n<<" "<<m<<"\n";
    cout<<"1 2\n1 3\n1 4\n2 3\n2 4\n3 4\n";
    for (int i=5;i<=31;i++) cout<<i<<" 3\n"<<i<<" 4\n";

    cout<<"32 5\n32 3\n32 4\n";
    cout<<"33 6\n33 3\n33 4\n32 33\n";
    cout<<"1 2 3 4 1 2";

    for (int i=7;i<=31;i++) cout<<" 1";
    cout<<" 2 1\n";

    return 0;
}
