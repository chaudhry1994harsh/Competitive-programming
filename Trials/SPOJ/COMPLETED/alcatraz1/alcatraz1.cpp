#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<unordered_set>
#include<cmath>
#include<string>

using namespace std;

void checkIT(string st){
    long long total = 0;
    int temp;

    for (int i = 0; i < st.length(); i++)
    {
        temp = st[i] - '0';
        total += temp;
    }
    
    cout<<total<<endl;
}


int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int cases, sz;

    cin>>cases;
    
    string st;

    while (cases--)
    {
        cin>>st;
        checkIT(st);
    }
    

    return 0;
}