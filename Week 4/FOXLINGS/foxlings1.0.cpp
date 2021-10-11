#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;


class DisjointSet{
    unordered_map<int,int> parent;
    unordered_map<int, int> sz;
    vector<int> temp;

    public:
    void makeSet(vector<int> const &wholeset){
        /*for (auto &&i : wholeset)
        {
            parent[i] = i;
            sz[i] = 1;
        }*/
        for (int i = 1; i < wholeset.size(); i++)
        {
            parent[i] = i;
            sz[i] = 1;
        }
        
        /*for (int i : wholeset)
        {
            parent[i] = i;
            sz[i] = 1;
        }*/

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
            if (sz[m] < sz[n])
                swap(m, n);
            parent[n] = m;
            sz[m] += sz[n];
        }   
    }
    int Size(int m){
        return sz[Find(m)];
    }

    int ears(int l){
       if (parent[l] == l) 
                return l;
        return Find(parent[l]);
    }

    vector<int> Rem(vector<int> x, int i){
        //cout<<"removed: "<< i<<endl;
        x[i] = 0;
        if (parent[i] == i){
            return x;
        }
        return x = Rem(x,parent[i]);
    }
};


int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int cases,user1,user2,sz=0;
    
    //unordered_set<int> wholeset;
    //unordered_set<int> damn;
    

    cin>>sz>>cases;
    vector<int> wholeset;
    //vector<int> damn(sz+1,2000000009);
    unordered_set<int> emp;
    DisjointSet dis;
    wholeset.push_back(0);
    
    for (int i = 1; i <= sz; i++)
    {
        //wholeset[i]=i;
        //wholeset.insert(i);
        wholeset.push_back(i);
    }
    
    dis.makeSet(wholeset);

    while (cases>0){
        cin>>user2>>user1;
        dis.Union(dis.Find(user1), dis.Find(user2));

        cases--;
    }

    //cout<<"disjoint set made"<<endl;
    user2=0;
    for (int i = sz; i >= 1; i--)    
    //for (int i = 1; i <= sz; i++)
    {
        if(0 == wholeset[i]){
            //cout<<"discarded at 1 : "<<i<<endl;
            continue;
        }
        else if(0 == wholeset[dis.Find(i)]){
            wholeset[i] = 0;
            //cout<<"discarded at 2 : "<<i<<endl;
        }
        else{
            //cout<<"discarded at 3 : "<<dis.Find(i)<<"  "<<i<<endl; 
            user2++;
            wholeset =dis.Rem(wholeset, i );
            //wholeset[dis.Find(i)] = 0;
            //wholeset[i] = 0;
            //cout<<"increment count: "<<user2<<endl;
        }
    }
    cout<<user2;
/*
    for (int i = 1; i <= sz; i++)
    {
        emp.insert(dis.Find(i));
    }
    cout<<emp.size();
    */

    return 0;
}