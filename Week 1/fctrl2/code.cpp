#include<iostream>
#include<map>
#include<vector>
#include<cmath>
using namespace std;

int main(){
    int count,carry,multi = 0;
    int max =1;
    vector<int> ip;
    map<int,vector<int>> fact;
    vector<int> ans(199,0);
    ans.push_back(1);
    vector<int> prev;

    cin>>count;
    for (int i = 0; i < count; i++)
    {
        cin>>multi;
        ip.push_back(multi);
        if(max<multi) 
            max = multi;
    }

    fact.insert(pair<int,vector<int>>(1,ans));

    for (int i = 2; i < max+1; i++)
    {   
        prev = fact[i-1];
        carry =0;
        for (int j = ans.size()-1; j >= 0; j--){
            multi= prev[j]*i+carry;
            //cout<<multi<<"multi \n";
            ans[j] =multi%10;
            carry = floor(multi/10);
            /*if(multi==0 && prev[j]==0){
                break;
            }*/
        }
        fact.insert(pair<int,vector<int>>(i,ans));
    }


    for (auto x : ip)
    {
        for (int j = 0; j < fact[x].size(); j++)
        {
            if (fact[x][j] != 0)
            {
                for(int z =j; z< fact[x].size(); z++){
                    cout<<fact[x][z];
                }
                break;
            }
        }
        cout<<"\n";
    }
        
    return 0;
}