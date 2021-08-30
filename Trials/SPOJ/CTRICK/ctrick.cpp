#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;

queue <int> gquiz; 


void sendIT(int sz){
    vector<int> tar(sz+1,0);
    int plc = 2  ,temp,skip,t;

    tar[2] = 1;

    for (int i = 2; i < tar.size()-1; i++)
    {
        cout<<"itr: "<<i<<endl;
        temp = t = i;
        t++;
        while(t>0){
            if(plc>=sz) plc = plc%sz;

            if(tar[plc + 1]==0){
                t--;
                plc = plc + 1;
                cout<<"plc: "<<plc<<endl;
            }
            else{
                plc = plc + 1;
                cout<<"adv: "<<plc<<endl;
            }
        }
        tar[plc] = i;
        for (auto &&x : tar)
        {
            cout<<x<<" ";
        }cout<<endl;
        
    }
    for (int i = 1; i < tar.size(); i++)
    {
        if (tar[i]==0) tar[i] = sz;
        cout<<tar[i]<<" ";
    }cout<<endl;
    
    for (auto &&x : tar)
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

        sendIT(sz);
    }

    return 0;
}