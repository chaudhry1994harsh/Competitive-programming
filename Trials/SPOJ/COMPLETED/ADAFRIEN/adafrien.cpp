#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
#include <unordered_map>

using namespace std;

unordered_map<string,long long> lst;
long sz;

void sendit(){
    long max,total = 0;
    string temp;

    for (int i = 0; i < sz; i++)
    {
        max = 0;
        for (auto &&x : lst)
        {
            if(x.second>max){
                max = x.second;
                temp = x.first;
            }
        }
        //cout<<max<<endl;
        lst[temp] = 0;
        total = total + max;
    }
    
    /*for (auto &&x : lst)
    {
        cout<<x.first<<" "<<x.second<<endl;
    }*/
    cout<<total;
}


int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int cases;
    long cost;
    string name;

    cin>>cases>>sz;

    while(cases--){
        cin>>name>>cost;
        if(lst.find(name) == lst.end()){
            lst.insert(make_pair(name,cost));
        }
        else{
            lst[name] = lst[name]+cost;
        }
    }

    sendit();

    return 0;
}