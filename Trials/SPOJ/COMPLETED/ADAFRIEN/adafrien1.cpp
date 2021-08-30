#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
#include <unordered_map>

using namespace std;

unordered_map<string,long long> lst;
long long sz;

void sendit(){
    long long max = 0,total = 0;
    multiset<long long> longcon;
    multiset<long long>::reverse_iterator rit;

    for (auto &&x : lst)
    {
        longcon.insert(x.second);
    }

    for (rit = longcon.rbegin(); rit != longcon.rend(); rit++){
        if(max<sz){
            total += *rit;
            max ++;
        }
    }
    
    cout<<total;
}



int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long cases;
    long long cost;
    string name;


    cin>>cases>>sz;

    while(cases--){
        cin>>name>>cost;
        lst[name] += cost;
    }

    sendit();

    return 0;
}