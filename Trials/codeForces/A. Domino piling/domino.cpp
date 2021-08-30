//https://codeforces.com/problemset/problem/50/A

#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
#include<unordered_map>
#include<cmath>

using namespace std;




int main() 
{ 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    float x,y,z;
    cin>>x>>y;

    x = x*y;

    //cout<<(x/2)<<endl;
    cout<<floor(x/2)<<endl;
    
    return 0;
} 
