#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>
using namespace std;


class DisjointSet{
    unordered_map<int,int> parent;
    unordered_map<int, int> sz;
    //multiset<int> heads;
    //multiset <int> :: iterator itr; 
    int count = 0;

    public:
    void makeSet(vector<int> const &wholeset){
        for (int i = 1; i < wholeset.size(); i++)
        {
            parent[i] = i;
            sz[i] = 1;
            //heads.insert(1);
        }
        count = wholeset.size() - 1;
    }

    int Find(int l){
        if (parent[l] == l) 
            return l;
        return parent[l] = Find(parent[l]);
    }

    void Union (int m, int n){
        if(count>1){
            m = Find(m);
            n = Find(n);
            if (m != n) {
                //itr = heads.find(sz[m]);
                //heads.erase(itr);
                //itr = heads.find(sz[n]);
                //heads.erase(itr);
                if (sz[m] < sz[n])
                    swap(m, n);
                parent[n] = m;
                sz[m] += sz[n];
                count--;
                //heads.insert(sz[m]);
            }   
        }
    }
    /*int Size(int m){
        return sz[Find(m)];
    }*/

    void cnter(){
       cout<<count; 
    }

    
};


int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int cases,user1,user2,sz=0;

    cin>>sz>>cases;
    if(sz>1){
    vector<int> wholeset;
    DisjointSet dis;
    wholeset.push_back(0);
    
    for (int i = 1; i <= sz; i++)
    {
        wholeset.push_back(i);
    }
    
    dis.makeSet(wholeset);

    while (cases>0){
        cin>>user2>>user1;
        dis.Union(dis.Find(user1), dis.Find(user2));
        cases--;
    }

    dis.cnter();
    }
    else{
        cout<<sz;
    }

    return 0;
}