//https://codeforces.com/problemset/problem/339/A

#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
#include<unordered_map>
#include<cmath>
#include<cstring>

using namespace std;


int main() 
{ 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string st;
    cin>>st;

    multiset<int> lol;

    if(st.size()<2) cout<<st<<endl;
    else{
        for (int i = 0; i < st.size(); i=i+2)
        {
            lol.insert(st[i]-'0');
        }

        //cout<<lol.size()<<endl;
        st.clear();
        for (auto &&x : lol)
        {
            st = st + to_string(x) +"+";
        }
        cout<<st.substr(0, st.size()-1);
    }

    return 0;
} 
