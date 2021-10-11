#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;


class DisjointSet{
    unordered_map<int,int> parent;
    int count;

    public:
    DisjointSet(long long int x){
        count = x;
    }

    void makeSet(long long int i){
        if(!parent[i]){
            parent[i] = i;
        }
    }

    int Find(int l){
        if (parent[l] == l) 
            return l;
        return parent[l] = Find(parent[l]);
    }

    void Union (int m, int n){
        m = Find(m);
        n = Find(n);
        if (m != n) {
            parent[n] = m;
            count--;
        }   
    }

    void cnter(){
       cout<<count; 
    }
 
};


int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long int cases,user1,user2,sz=0;

    cin>>sz>>cases;
    DisjointSet dis(sz);


    while (cases>0){
        cin>>user2>>user1;

        dis.makeSet(user1);
        dis.makeSet(user2);

        dis.Union(user1,user2);

        cases--;
    }

    dis.cnter();

    return 0;
}

//major refernce: http://hmrockstar.blogspot.com/2016/11/foxlings-foxlings-solution.html