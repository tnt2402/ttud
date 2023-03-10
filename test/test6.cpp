#include <iostream>
#include <vector>
#include "math.h"

using namespace std;

int main() {

    int n,k;
    cin>>n>>k;
    vector <int> a(n);
    vector <int> r(k,0);
    for(int i=0;i<n;i++)
    {   
        cin>>a[i];
        r[a[i]%k]++;
    }
    int ctr=min(1,r[0]);
    for(int a=1;a<(k/2+1);a++)
    {
        if(a!=k-a)
            ctr+=max(r[a],r[k-a]);
    }

    if(k%2==0&&r[k/2]!=0)
        ctr++;
    cout<<ctr;
    return 0;
}