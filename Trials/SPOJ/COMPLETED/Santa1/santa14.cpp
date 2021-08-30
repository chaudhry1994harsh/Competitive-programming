#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;


vector<pair<pair<int,int>,string>> mn;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int cases,s,p,temp;
    string lol; char c;
    bool phaltu;
    long damn = 0;
    cin>>cases;

    while(cases--){
        cin>>c>>lol;

        if(c == 'A'){
            cin>>s>>p;
            phaltu = true;
            for (int i = 0; i < mn.size(); i++)
            {
                if(mn[i].second == lol){
                    temp = i;
                    phaltu = false;
                    break;
                }
            }
        
            if(phaltu == true){
                mn.push_back(make_pair(make_pair(s,p),lol));
                sort(mn.begin(),mn.end());
                
                if(mn[mn.size()-1].second == lol){
                    if( mn.size()>1)
                    damn = damn + mn[mn.size()-2].first.second * mn[mn.size()-1].first.second;
                }
                else if(mn[0].second == lol ){
                    damn = damn + mn[1].first.second* mn[0].first.second;
                }
                else{
                    for (int i = 1; i < mn.size()-1; i++)
                    {
                        if(mn[i].second == lol){
                            temp = i;
                            break;
                        }
                    }
                    damn =  damn - (mn[temp-1].first.second * mn[temp+1].first.second);
                    damn = damn + (mn[temp].first.second * mn[temp+1].first.second);
                    damn = damn + (mn[temp].first.second * mn[temp-1].first.second);
                }
            }
            else{
                mn[temp] = make_pair(make_pair(s,p),lol);
                sort(mn.begin(),mn.end());
                
                if(mn[mn.size()-1].second == lol && mn.size()>1){
                    if( mn.size()>1)
                    damn = damn + mn[mn.size()-2].first.second * mn[mn.size()-1].first.second;
                }
                else if(mn[0].second == lol ){
                    damn = damn + mn[1].first.second* mn[0].first.second;
                }
                else{
                    for (int i = 1; i < mn.size()-1; i++)
                    {
                        if(mn[i].second == lol){
                            temp = i;
                            break;
                        }
                    }
                    damn =  damn - (mn[temp-1].first.second * mn[temp+1].first.second);
                    damn = damn + (mn[temp].first.second * mn[temp+1].first.second);
                    damn = damn + (mn[temp].first.second * mn[temp-1].first.second);
                }
            }
        }

        else{

            for (int i = 0; i < mn.size(); i++)
            {
                if(mn[i].second == lol){
                    temp = i;
                    break;
                }
            }
            if(temp == mn.size()-1){
                if( mn.size()>1)
                damn = damn - mn[temp].first.second* mn[temp-1].first.second;
            }
            else if(temp == 0){
                damn = damn - mn[temp].first.second* mn[temp+1].first.second;
            }
            else{
                damn = damn + mn[temp+1].first.second* mn[temp-1].first.second;
                damn = damn - mn[temp].first.second* mn[temp+1].first.second;
                damn = damn - mn[temp].first.second* mn[temp-1].first.second;
            }
            mn.erase(mn.begin()+temp);
            //sort(mn.begin(),mn.end());

            
        }
        /*for (auto &&x : mn)
        {
            cout<<x.second<<" "<<x.first.first<<" "<<x.first.second<<endl;
        }*/
        
        cout<<damn<<endl;
    }

    return 0;
}