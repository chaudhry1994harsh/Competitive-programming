#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<unordered_set>
#include<cmath>

using namespace std;

unordered_map<int,int> mp;

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);


    int cases, sz,query,temp,a,b;

    cin>>sz>>cases;

    for (int i = 0; i < sz; i++)
    {
        cin>>a;
        if(mp.find(a) == mp.end()) mp[a] = i;
    }
    
    while (cases--)
    {
        cin>>a;
        if(mp.find(a) != mp.end()) cout<<mp[a]<<endl;
        else cout<<"-1"<<endl;
    }
    
    

    return 0;
}