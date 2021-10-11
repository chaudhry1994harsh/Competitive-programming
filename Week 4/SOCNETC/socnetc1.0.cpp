#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;


class DisjointSet{
    unordered_map<int,int> parent;
    unordered_map<int, int> sz;

    public:
    void makeSet(vector<int> const &wholeset){
        for (int i : wholeset)
        {
            parent[i] = i;
            sz[i] = 1;
        }
    }

    int Find(int l){
        if (parent[l] == l) 
            return l;
        return Find(parent[l]);
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

    int cases,users,size,user2=0;
    char tp;
    vector<int> wholeset;
    DisjointSet dis;

    cin>>users>>size;
    cin>>cases;
    
    for (int i = 1; i <= users; i++)
    {
        wholeset.push_back(i);
    }
    
    dis.makeSet(wholeset);

    while (cases>0){
        cin>>tp;
        if(tp == 'A'){
            cin>>user2>>users;
            if( (dis.Size(dis.Find(user2)) + dis.Size(dis.Find(users))) <= size){
                dis.Union(dis.Find(users), dis.Find(user2));
                //cout<<dis.Find(users)<<"  "<<dis.Find(user2)<<endl;
            }
        }
        else if(tp == 'E'){
            cin>>user2>>users;
            if (dis.Find(user2) == dis.Find(users)) // if they are belong to same set or not.
                cout<<"Yes"<<endl;
            else
                cout<<"No"<<endl;
        }
        else{
            cin>>users;
            cout<<dis.Size(users)<<endl;
        }

        cases--;
    }


    return 0;
}