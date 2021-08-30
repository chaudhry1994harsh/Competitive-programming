#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
#include<cstring>
#include<unordered_map>

using namespace std;


set<pair<pair<long,long>,string>> st;
unordered_map<string,pair<pair<long,long>,string>> mp;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long cases,s,p,temp;
    string lol; char c;
    bool phaltu;
    long damn = 0;
    cin>>cases;

    while(cases--){
        cin>>c>>lol;

        if(c == 'A'){
            cin>>s>>p;

            mp.insert(make_pair(lol,make_pair(make_pair(s,p),lol)));
            st.insert(make_pair(make_pair(s,p),lol));
            set<pair<pair<long,long>,string>>::iterator itr = st.find(make_pair(make_pair(s,p),lol));
            
            if((st.rbegin())->second == lol){
                if( st.size()>1){
                    itr--;
                    damn = damn + p * itr->first.second;
                }
            }
            else if((st.begin())->second == lol ){
                itr++;
                damn = damn + itr->first.second * p;
            }
            else{
                itr++;
				long next = itr->first.second;
				itr--; itr--;
				long prev = itr->first.second;

                damn =  damn - next * prev;
                damn = damn + p * next;
                damn = damn + p * prev;
            }
        }

        else{
            set<pair<pair<long,long>,string>>::iterator itr = st.find(mp[lol]);
            long pro = itr->first.second;

            if(lol == (st.rbegin())->second){
                if( st.size()>1){
                    itr--;
                    damn = damn - pro * itr->first.second;
                }
            }
            else if(lol == (st.begin())->second){
                itr++;
                damn = damn - pro * itr->first.second;
            }
            else{
                itr++;
				long next = itr->first.second;
				itr--;	itr--;
				long prev = itr->first.second;

                damn = damn + next * prev;
                damn = damn - pro * prev;
                damn = damn - pro * next;
            }
            st.erase(mp[lol]);
            mp.erase(lol);
            
        }
        /*for (auto &&x : mn)
        {
            cout<<x.second<<" "<<x.first.first<<" "<<x.first.second<<endl;
        }*/
        
        cout<<damn<<endl;
    }

    return 0;
}