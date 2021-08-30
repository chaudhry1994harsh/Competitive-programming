//algo-code from geeks4geeks
#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<unordered_set>
#include<cmath>
#include<cstring>

using namespace std; 

  
const int MAX = 100001; 

struct Query 
{ 
    int l, r, idx; 
}; 
  
bool cmp(Query x, Query y) 
{ 
    return x.r < y.r; 
} 
  
void update(int idx, int val, vector<int> &bit, int n) 
{ 
    for (; idx <= n; idx += idx&-idx) 
        bit[idx] += val; 
} 
  
int query(int idx, vector<int> bit, int n) 
{ 
    int sum = 0; 
    for (; idx>0; idx-=idx&-idx) 
        sum += bit[idx]; 
    return sum; 
} 
  

void answeringQueries(vector<int> arr, int n, vector<Query> queries, int q)
{ 
    vector<int> bit(n+1);
    vector<int> last_visit(n+1,-1);
    //int last_visit[MAX]; 
    //memset(last_visit, -1, sizeof(last_visit)); 
  
    vector<int> ans(q); 
    int query_counter = 0; 
    //cout<<"before loop"<<endl;
    for (int i=0; i<n; i++) 
    { 
        //cout<<"FOR i: "<<i<<endl;
        //cout<<"lasvisit !=-1 : "<<last_visit[arr[i]]<<endl;
        if (last_visit[arr[i]] !=-1) 
            update (last_visit[arr[i]] + 1, -1, bit, n); 
  
        last_visit[arr[i]] = i; 
        update(i + 1, 1, bit, n); 

        /*for (auto &&x : bit)
        {
            cout<<x<<" ";
        }cout<<endl;*/
        
  
        while (query_counter < q && queries[query_counter].r == i) 
        { 
            //cout<<"while: "<<query(queries[query_counter].r + 1, bit, n)<<" - "<<query(queries[query_counter].l, bit, n)<<endl; 
            ans[queries[query_counter].idx] = 
                     query(queries[query_counter].r + 1, bit, n)- 
                     query(queries[query_counter].l, bit, n); 
            query_counter++; 
        } 
    } 
  
    for (int i=0; i<q; i++) 
        cout << ans[i] << endl; 
} 
  

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int x,y,n,q;

    cin>>n;

    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin>>x;
        a[i] = x;
    }
    /*for (auto &&x : a)
    {
        cout<<x<<" ";
    }cout<<endl;*/
    cin>>q;
    
    vector<Query> queries(q);
    for (int i = 0; i < q; i++)
    {
        cin>>x>>y;
        //queries.push_back({x,y,i});
        queries[i].l = x-1; 
        queries[i].r = y-1; 
        queries[i].idx = i; 
    }
    /*for (auto &&x : queries)
    {
        cout<<x.l<<" "<<x.r<<" "<<x.idx<<endl;
    }*/
    

    sort(queries.begin(), queries.end(), cmp); 
    /*for (auto &&x : queries)
    {
        cout<<x.l<<" "<<x.r<<" "<<x.idx<<endl;
    }*/

    answeringQueries(a, n, queries, q); 
    
    return 0; 

}