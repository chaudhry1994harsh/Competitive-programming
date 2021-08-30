#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
#include<set>

using namespace std;


multiset<int> lst;


void printS(){
    for (auto &&x : lst)
    {
        cout<<x<<" ";
    }
    cout<<endl;
}


long long sendIT(){
    long long tempr = 0;
    tempr = abs((*lst.begin())-(*lst.rbegin()));
    lst.erase(lst.begin());
    lst.erase(prev(lst.end()));
    //cout<<"+"<<tempr<<endl;
    return tempr;
}


int main() 
{ 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int cases, sz,temp ;
    long long max = 0;

    cin>>cases;

    while(cases--){
        cin>>sz;
        for (int i = 0; i < sz; i++)
        {
            cin>>temp;
            lst.insert(temp);
            //printS();
        }
        //printS();
        max = max + sendIT();
    }

    cout<<max<<endl;

    return 0;
} 
