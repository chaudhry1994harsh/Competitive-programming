//https://codeforces.com/problemset/problem/71/A


#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
#include<cmath>

using namespace std;


string st;

void checkIT() 
{ 
    string r = st.substr(1, st.size()-2); 
    cout<<st[0]<<r.size()<<st[st.size()-1]<<endl;
} 

int main() 
{ 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    
    int cases;
    cin>>cases;

    while (cases--)
    {
        cin>>st;

        if(st.size()>10) checkIT();
        else cout<<st<<endl;
    }
    


    
    return 0;
} 
