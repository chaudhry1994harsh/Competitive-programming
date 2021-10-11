#include<set>
#include<algorithm>
#include<iostream>
#include<iterator>
using namespace std;


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int cases,sub;
    multiset<int> target;
    //multiset <int> :: iterator itr; 

    cin>>cases;

    while (cases>0)
    {
        cin>>sub;
        target.insert(sub);
        cases--;
    }

    for (auto &&x : target)
    {
        cout<<x<<endl;
    }
    
    return 0;
} 