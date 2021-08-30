#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<unordered_set>
#include<cmath>
#include<string>

using namespace std;

unordered_map<int,int> mp;


int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int cases = 8, sz,temp,a,b;
    long long total =0;

    for (int i = 1; i <= cases; i++)
    {
        cin>>temp;
        mp[i] =temp;
        total += temp;
    }

    cin>>sz;
    while (sz--)
    {
        cin>>a>>b;
        total = total - min(mp[a],mp[b]);
    }
    
    cout<<total<<endl;

    return 0;
}