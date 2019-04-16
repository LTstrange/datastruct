#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(){
    string a,b;
    cin>>a;
    cin>>b;
    int m=a.size();
    int n= b.size();
    string c(m+n,'0');
    int sum=0;
    int p,q;
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            p = m-i + n-j;
            sum += (a[m-i-1] - '0')*(b[n-j-1] - '0');
            sum += c[p-1]-'0';
            c[p-1] = sum%10 + '0';
            sum = sum / 10;
        }

    }
    while (*(c.begin()) == '0'){
        c.erase(c.begin());
    }
    cout<<c<<endl;
    return 0;
}
