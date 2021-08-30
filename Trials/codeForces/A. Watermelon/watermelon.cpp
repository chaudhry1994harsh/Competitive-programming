//https://codeforces.com/problemset/problem/4/A


#include<iostream>
#include<vector>
#include<set>
#include<algorithm>

using namespace std;




int checkIT(int a) 
{ 
    if(a == 2 || a%2 != 0) return 0;
    else return 1;
} 

int main() 
{ 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int cases,sz;

    cin>>cases;

    if(checkIT(cases) == 1) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
    
    /*while(cases--){
    }*/

    return 0;

} 
