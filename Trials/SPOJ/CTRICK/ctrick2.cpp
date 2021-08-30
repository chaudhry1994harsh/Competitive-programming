#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include <deque>

using namespace std;


deque <int> q; 
deque<int> ans;

void sendIT(int sz){
    cout<<endl;


    for (int i = 1; i <= sz; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            q.push_back(q.front());
            q.pop_front();
            for (auto &&x : q)
            {
                cout<<x<<" ";
            }cout<<endl;
        }
        q.pop_back();
        q.push_back(i);

        for (auto &&x : q)
        {
            cout<<x<<" ";
        }cout<<endl;
    }
    for (auto &&x : q)
    {
        cout<<x<<" ";
    }cout<<endl;
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int cases, sz;
    
    cin>>cases;

    while(cases--){
        cin>>sz;
        q.clear();
        for (int i = 0; i < sz; i++)
        {
            q.push_back(0);
        }
        sendIT(sz);
    }

    return 0;
}