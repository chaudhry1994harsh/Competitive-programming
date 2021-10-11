#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class DisjointSet { //to represent disjoint set
    unordered_map<int, int> parent;
    unordered_map<int, int> size;
    public:
    void makeSet(vector<int> const &wholeset){
    //perform makeset operation
        for (int i : wholeset)
        {
            parent[i] = i;
            size[i] = 1;
        }
         // create n disjoint sets //(one for each item)
            //parent[i] = i;
    }
    int Find(int l) { // Find the root of the set in which element l belongs
        if (parent[l] == l) // if l is root
            return l;
        return Find(parent[l]); // recurs for parent till we find root
    }
    void Union(int m, int n) { // perform Union of two subsets m and n  
        int a = Find(m);
        int b = Find(n);
        //parent[x] = y;
        if (a != b) {
            if (size[a] < size[b])
                swap(a, b);
            parent[b] = a;
            size[a] += size[b];
        }   
    }
    void siz(int m){
        cout<<size[m]<<endl;
    }
};

void print(vector<int> const &universe, DisjointSet &dis) {
    for (int i : universe)
        cout << dis.Find(i) << " ";
        cout << '\n';
}


int main() {
vector<int> wholeset = { 0,1,2,3,4,5,6,7,8,9,10 }; // items of whole set
DisjointSet dis; //initialize DisjointSet class
dis.makeSet(wholeset); // create individual set of the items of wholeset
cout<<dis.Find(1)<<endl;
cout<<dis.Find(0)<<endl;
cout<<dis.Find(11)<<endl;

print(wholeset, dis);

dis.Union(5, 6); // 7,6 are in same set
dis.siz(9);
dis.siz(6);
dis.siz(10);
dis.siz(5);
print(wholeset, dis);

dis.Union(6,10);
dis.siz(9);
dis.siz(6);
dis.siz(10);
dis.siz(5);
print(wholeset, dis);

dis.Union(10,5);
dis.siz(9);
dis.siz(6);
dis.siz(10);
dis.siz(5);
print(wholeset, dis);
/*if (dis.Find(5) == dis.Find(6)) // if they are belong to same set or not.
    cout<<"Yes"<<endl;
else
    cout<<"No";
if (dis.Find(10) == dis.Find(5))
    cout<<"Yes"<<endl;
else
    cout<<"No";*/
return 0;
}




/*
checker = false;
        string com,ncom ="";
        cout<<wholeset[0]<<" "<<wholeset[1]<<endl;
        for (auto &&i : wholeset){
            if(Find(i)!=""){
                cout<<"fouund"<<Find(i)<<endl;
                checker = true;
            }
        }
        if(checker == true){
            cout<<"common found"<<endl;
            for (auto &&i : wholeset){
                if(Find(i)!=""){
                    cout<<"inside if"<<endl;
                    com = Find(i);
                }
                parent[i] = i;
                sz[i] = 1;
            }
            Union(wholeset[0],wholeset[1]);
            Union(Find(wholeset[0]),Find(com));
            Size(Find(wholeset[0]));
        }

        */