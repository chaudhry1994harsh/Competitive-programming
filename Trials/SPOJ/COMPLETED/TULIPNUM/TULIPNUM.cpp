#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<unordered_set>

using namespace std;

unordered_map<int,int> mp;
unordered_set<int> st;


int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int cases, sz,query,temp,a,b;

    cin>>cases;

    for (int jj = 1; jj <= cases; jj++)
    {
        cout<<"Case "<<jj<<":"<<endl;
        mp.clear();
        cin>>sz>>query;

        for (int i = 1; i <= sz; i++)
        {
            cin>>temp;
            mp[i]=temp;
        }
        
        for (int i = 0; i < query; i++)
        {
            cin>>a>>b;
            st.clear();
            for (int z = a; z <= b; z++)
            {
                st.insert(mp.at(z));
            }
            cout<<st.size()<<endl;
        }

    }

    return 0;
}