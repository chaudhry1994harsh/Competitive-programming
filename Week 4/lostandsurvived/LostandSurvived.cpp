#include <iostream>
#include <vector>
#include <unordered_map>    
#include <map>    
using namespace std;


class DisjointSet{
    unordered_map<int,int> parent;
    map<int, int> sz;

    public:
    void makeSet(vector<int> const &wholeset){
        /*for (int i : wholeset)
        {
            parent[i] = i;
            sz[i] = 1;
        }*/
        for (int i = 1; i <= wholeset.size(); i++)
        {
            parent[i] = i;
            sz[i] = 1;
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
            if (sz[m] < sz[n])
                swap(m, n);
            parent[n] = m;
            sz[m] += sz[n];
        }   
    }
    int Size(int m){
        return sz[Find(m)];
        //cout<<sz[m]<<endl;
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
        min =1000000;
        max = 0;
        for (int i = 1; i <= sz; i++)
        {
            int d = dis.Size(i);
            if(d>max){
                max = d;
            }
            if(d<min){
                min = d;
            }
        }
        /*for (auto &&x : wholeset)
        {
            int d = dis.Size(x);
            if(d>max){
                max = d;
            }
            if(d<min){
                min = d;
            }
        }*/
        
        cout<<max-min<<endl;
        cases--;
    }


    return 0;
}