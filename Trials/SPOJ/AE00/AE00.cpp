#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<unordered_set>
#include<cmath>

using namespace std;

void checkIT(int cas){
    int sq = sqrt(cas);
    int total = 0;
    cout<<"sq"<<sq<<endl;
    for (int i = 1; i <= sq; i++)
    {
        total = cas + floor(cas/i) - (i-1);
        cout<<total<<endl;
    }
    
    //total = cas + floor(cas/2) -1;
    cout<<total;
}


int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int cases, sz;

    cin>>cases;

    if(cases == 1) cout<<1;
    else checkIT(cases);

    return 0;
}