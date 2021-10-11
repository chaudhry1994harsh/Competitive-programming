#include <iostream>
#include <unordered_map>
using namespace std;


unordered_map<int,int> parent;

int Find(int l){
    if (parent[l] == l) 
        return l;
    return parent[l] = Find(parent[l]);
}

void Union(int m,int n){
	m = Find(m);
    n = Find(n);
    if (m != n) {
        parent[n] = m;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long int sz, cases,user1, user2, counter = 0;

    cin>>sz>>cases;
    counter = sz;

    for (int  i = 0; i < cases; i++)
    {
        cin>>user1>>user2;

        if(!parent[user1]){
            parent[user1] = user1;
        }
        if(!parent[user2]){
            parent[user2] = user2;
        }

        user1 = Find(user1);
        user2 = Find(user2);

        if(user1 != user2){
            counter--;
            Union(user1,user2);
        }
    }
    cout<<counter;

    return 0;
}
