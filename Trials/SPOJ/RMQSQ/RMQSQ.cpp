#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<unordered_set>
#include<cmath>
#include<string>

using namespace std;

unordered_map<int,int> mp;

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int cases, sz,temp,a,b;
    long min;

    cin>>cases;

    for (int i = 0; i < cases; i++)
    {
        cin>>temp;
        mp[i] = temp;
    }
    /*for (int i = 0; i<cases; i++)
    {
        cout<<mp[i]<<" ";
    }
    cout<<endl;*/
    

    cin>>sz;
    while (sz--)
    {
        long min =999999999;
        cin>>a>>b;
        for (int i = a; i <=  b; i++)
        {
            temp = mp[i];
            //cout<<"Case: "<<temp<<endl;
            if(temp<min) min = temp;
        }
        cout<<min<<endl;
    }
    
    

    return 0;
}