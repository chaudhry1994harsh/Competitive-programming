#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<unordered_set>

using namespace std;

unordered_map<int,pair<int,int>> mp;
int life,r,c;


void checkIT(){
    //cout<<"lol"<<endl;

    int MAXdud,idx,temp,lit,dim;
    for (int i = 0; i < life; i++)
    {
        MAXdud = mp[1].first;
        idx = 1;
        for (int jj = 2; jj <= mp.size(); jj++)
        {
            if(mp[jj].first > MAXdud){
                idx = jj;
                MAXdud = mp[jj].first;
            }
        }
        //cout<<MAXdud<<" "<<idx<<endl;
        
        dim = mp[idx].first;
        lit = mp[idx].second;
        mp[idx] = make_pair(lit,dim);
    }

    temp = 0;
    for (int i = 1; i <= mp.size(); i++)
    {
        temp += mp[i].second;
    }
    
    cout<<temp<<endl;
    
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int cases;

    cin>>cases;

    while(cases--)
    {
        cin>>r>>c>>life;
        string s;
        mp.clear();

        for (int i = 1; i <= r; i++)
        {
            cin>>s;
            mp[i] = make_pair(count(s.begin(), s.end(), '.'),count(s.begin(), s.end(), '*'));
        }


        /*for (int i = 1; i <= r; i++)
        {
            cout<<mp[i].first<<" "<<mp[i].second<<endl;
        }*/
        
        
        checkIT();


    }

    return 0;
}