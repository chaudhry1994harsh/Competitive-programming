#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<unordered_set>
#include<cmath>
#include<cstring>

using namespace std; 


int sz,bag;
vector<int> wt;
vector<int> val;
  
void printer(vector<int> best){
    for (auto &&x : best)
    {
        cout<<x<<" ";
    }cout<<endl<<endl;
}

void checkIT(){
    int temp;
    vector<int> best(bag+1,0);

    for (int i = 1; i <= bag; i++)
    {
        best[i] = best[i-1];
        for (int j = 1; j <= sz; j++)
        {
            if(i>=wt[j]){
                temp = val[j]+best[i-wt[j]];
                if(temp>best[i]){
                    best[i]=temp;
                    //printer(best);
                }
            }
        }
    }
    cout<<best[bag]<<endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int cases,temp;
    cin>>cases;

    while(cases--){
        cin>>bag>>sz;
        wt.clear(); val.clear();
        wt.push_back(0); val.push_back(0);

        for (int i = 0; i < sz; i++)
        {
            cin>>temp;
            wt.push_back(temp);
        }
        for (int i = 0; i < sz; i++)
        {
            cin>>temp;
            val.push_back(temp);
        }
        checkIT();
    }

    
    return 0; 

}