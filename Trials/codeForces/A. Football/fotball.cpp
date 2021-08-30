//https://codeforces.com/problemset/problem/281/A

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

    int a=0,b=0;

    for (auto &&x : st)
    {
        if(a>6 || b>6) break;
        if(x == '1'){
            a++;
            b=0;
        }
        if(x == '0'){
            b++;
            a=0;
        } 
        //cout<<a<<" "<<b<<endl;
    }

    if(a>6 || b>6) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
    
    return 0;
} 
