//https://codeforces.com/problemset/problem/158/A

#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
#include<unordered_map>
#include<cmath>

using namespace std;


unordered_map<int,int> mp;

int main() 
{ 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int cases,sz,count=0,temp;
    cin>>cases>>sz;

    for (int i = 1; i <= cases; i++)
    {
        cin>>temp;
        mp[i] = temp;
    }
    cout<<sz<<endl;
    for (int i = 1; i <= cases; i++)
    {
        //cout<<mp[i]<<" ";
        if (mp[i]>=mp[sz] && mp[i]>0) count++;
    }
    

    cout<<count<<endl;
    
    return 0;
} 
