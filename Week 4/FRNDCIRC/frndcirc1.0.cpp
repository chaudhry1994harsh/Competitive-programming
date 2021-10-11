#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;


class DisjointSet{
    unordered_map<string, string> parent;
    unordered_map<string, int> sz;
    bool checker;

    public:
    void makeSet(vector <string> const &wholeset){
        checker = false;
        string com,ncom ="";
        vector<string> temp;
        for (auto &&i : wholeset){
            if(Find(i)!=""){
                com = Find(i);
                checker = true;
                if(i == wholeset[0]){
                    ncom = wholeset[1];
                    temp.push_back(wholeset[1]);
                }
                else{
                    ncom = wholeset[0];
                    temp.push_back(wholeset[0]);
                }
            }
        }
        if(checker == true){
            if(temp.size()==1){
                parent[ncom] = ncom;
                sz[ncom] = 1;
                Union(ncom,Find(com));
            }
            else if(temp.size() == 2){
                Union(Find(temp[0]),Find(temp[1]));
            }
            temp.clear();
            Size(Find(ncom));
        }
        else{
            for (auto &&i : wholeset){
                parent[i] = i;
                sz[i] = 1;
            }
            Union(wholeset[0],wholeset[1]);
            Size(Find(wholeset[0]));
        }
    }

    string Find(string l){
        if (parent[l] == l) 
            return l;
        return Find(parent[l]);
    }

    void Union (string m, string n){
        m = Find(m);
        n = Find(n);
        if (m != n) {
            if (sz[m] < sz[n])
                swap(m, n);
            parent[n] = m;
            sz[m] += sz[n];
        }   
    }
    void Size(string m){
        cout<<sz[m]<<endl;
    }
    void clr(){
        parent.clear();
        sz.clear();
    }
};


int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int count,cases=0;

    cin>>count;
    
    while(count>0){
        vector<string> wholeset(2);
        cin>>cases;
        DisjointSet dis;

        while (cases>0){
            cin>>wholeset[0]>>wholeset[1];
            dis.makeSet(wholeset);
            cases--;
        }

        cout<<endl;
        count--;
    }

    return 0;
}