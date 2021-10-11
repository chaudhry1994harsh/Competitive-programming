#include <iostream>
#include <vector>
#include <unordered_map>    
#include <map>  
#include <set>  
using namespace std;


class DisjointSet{
    unordered_map<int,int> parent;
    unordered_map<int, int> sz;
    multiset<int> rks;
    multiset <int> :: iterator itr; 

    public:
    void makeSet(vector<int> const &wholeset){
        
        for (int i = 1; i < wholeset.size(); i++)
        {
            parent[i] = i;
            sz[i] = 1;
            rks.insert(1);
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
            itr = rks.find(sz[m]);
            rks.erase(itr);
            itr = rks.find(sz[n]);
            rks.erase(itr);
            if (sz[m] < sz[n])
                swap(m, n);
            parent[n] = m;
            sz[m] += sz[n];
            rks.insert(sz[m]);
            
        }   
    }
    int Size(int m){
        return sz[Find(m)];
    }
    void minmax(){
        cout<<(*rks.rbegin())-(*rks.begin())<<endl;
    }
};


int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int cases,user1,user2, min , max,sz=0;
    vector<int> wholeset;
    wholeset.push_back(0);
    DisjointSet dis;

    cin>>sz>>cases;
    
    for (int i = 1; i <= sz; i++)
    {
        wholeset.push_back(i);
    }
    
    dis.makeSet(wholeset);

    while (cases>0){
        cin>>user2>>user1;
        dis.Union(dis.Find(user1), dis.Find(user2));
        dis.minmax();

        cases--;
    }


    return 0;
}