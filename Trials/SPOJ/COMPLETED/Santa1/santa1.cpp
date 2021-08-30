#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<map>
#include<map>
#include<queue>
#include<string>

using namespace std;

vector<string> nam;
vector<pair<int,int>> v;


void sendIT(){
    vector<pair<int,int>> tar(v);
    sort(tar.begin(),tar.end());
    long long temp = 0;

    /*for (int i = tar.size() - 1; i >= 0; i--)
    {
        cout<<tar[i].first<<" "<<tar[i].second<<endl;
    }cout<<endl*/

    for (int i = 1; i < tar.size(); i++)
    {
        temp = temp + (tar[i].second * tar[i-1].second);
    }
    
    /*for (int i = tar.size() - 1; i > 0; i--)
    {
        temp = temp + (tar[i].second * tar[i-1].second);
    }*/
    cout<<temp<<endl;
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int cases,s,p;
    cin>>cases;

    string lol; char c;
    while(cases--){
        cin>>c>>lol;

        int temp;

        if(c == 'R'){
            //cout<<"r"<<endl;
            for (int i = 0; i < nam.size(); i++)
            {
                if(nam[i] ==lol){
                    nam.erase(nam.begin()+i);
                    v.erase(v.begin()+i);
                    break;
                }
            }
        }
        else{
            cin>>s>>p;
            nam.push_back(lol);
            v.push_back(make_pair(s,p));
        }
        if(nam.size()<2) cout<<0<<endl;
        else sendIT();
    }

    return 0;
}