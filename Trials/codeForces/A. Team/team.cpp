//https://codeforces.com/problemset/problem/231/A

#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
#include<cmath>

using namespace std;




int main() 
{ 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int cases,x,y,z,count=0,temp;
    cin>>cases;

    while (cases--)
    {
        temp = 0;
        cin>>x>>y>>z;
        temp = x+y+z;
        if(temp>1) count++;
    }
    cout<<count<<endl;
    
    return 0;
} 
