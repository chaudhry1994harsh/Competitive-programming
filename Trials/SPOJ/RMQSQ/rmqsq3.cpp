//sqrt decomp and sparse table rmq from geeks4geeks
#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<unordered_set>
#include<cmath>
#include<string>

using namespace std;




vector<vector<int>>lookup( 10000 , vector<int> (10000, 0));

  

struct Query 
{ 
    int L, R; 
}; 

void preprocess(vector<int> arr, int n) 
{ 
    for (int i = 0; i < n; i++) 
        lookup[i][0] = i; 
  
    for (int j=1; (1<<j)<=n; j++) 
    { 
        for (int i=0; (i+(1<<j)-1) < n; i++) 
        {  
            if (arr[lookup[i][j-1]] < arr[lookup[i + (1<<(j-1))][j-1]]) 
                lookup[i][j] = lookup[i][j-1]; 
            else
                lookup[i][j] = lookup[i + (1 << (j-1))][j-1];       
        } 
    } 
} 
  
int query(vector<int> arr, int L, int R) 
{ 
    int j = (int)log2(R-L+1); 
  
    //cout<<"q: ";
    //cout<<R - (1<<j) + 1<<endl;
    
    if (arr[lookup[L][j]] <= arr[lookup[R - (1<<j) + 1][j]]) 
        return arr[lookup[L][j]]; 
  
   else return arr[lookup[R - (1<<j) + 1][j]]; 
} 
  
void RMQ(vector<int> arr, int n, vector<Query> q, int m) 
{ 
    preprocess(arr, n); 
    /*for (int i = 0; i < 20; i++)
    {
        for (int j = 0; j < 20; j++)
        {
            cout<<lookup[i][j]<<" ";
        }
        cout<<endl;
    }*/
  
    for (int i=0; i<m; i++) 
    { 
        int L = q[i].L, R = q[i].R; 
        //cout<<L<<" "<<R<<endl;
        cout << query(arr, L, R) << endl; 
    } 
} 
  

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int cases, sz,temp,x,y;
    vector<int> a;
    vector<Query> q;

    cin>>cases;

    for (int i = 0; i < cases; i++)
    {
        cin>>temp;
        a.push_back(temp);
    }      

    cin>>sz;
    for (int i = 0; i < sz; i++)
    {
        cin>>x>>y;
        //cout<<x<<" "<<y<<endl;
        q.push_back({x,y});
    }
    
    RMQ(a, cases, q, sz); 

    
    

    return 0;
}