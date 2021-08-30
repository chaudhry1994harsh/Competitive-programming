#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
#include <unordered_map>

using namespace std;

multiset<int> lst;


int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int cases,lol;
    cin>>cases;

    while(cases--){
        cin>>lol;
        lst.insert(lol);
    }

    for (auto &&x : lst)
    {
        cout<<x<<endl;
    }
    
    return 0;
}