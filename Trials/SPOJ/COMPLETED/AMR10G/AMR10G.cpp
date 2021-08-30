#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<unordered_set>
#include<cmath>
#include<set>

using namespace std;

vector<long long> st;
int sol;


void checkIT(){
    long long temp = 0;
    long long min = 999999999999999;
    for (int i = 0; i < st.size()-sol+1; i++)
    {
        temp = abs(st[i] - st[i+sol-1]);
        if(min>temp) min =temp;
    }
    cout<<min<<endl;
}


int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int cases,sz;
    long long temp;

    cin>>cases;

    while (cases--)
    {
        st.clear();
        cin>>sz>>sol;
        //cout<<"sz sol: "<<sz<<" "<<sol<<endl;
        while (sz--)
        {
            cin>>temp;
            st.push_back(temp);
        }
        if(sol == 1) cout<<0<<endl;
        else if(sol == sz){
            sort(st.begin(),st.end());
            cout<<abs(st[0] - st[st.size()-1])<<endl;
        }
        else{
            sort(st.begin(),st.end());
            checkIT();
        }
    }
    

    return 0;
}