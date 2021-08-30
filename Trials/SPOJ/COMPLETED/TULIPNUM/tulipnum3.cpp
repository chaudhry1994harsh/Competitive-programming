//algo-code from geeks4geeks
#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<unordered_set>
#include<cmath>
#include<cstring>

using namespace std; 

using namespace std; 
  
const int MAX = 1000; 
  
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
  
void answeringQueries(int arr[], int n, Query queries[], int q)
{ 
    vector<int> bit(n+1);
    int last_visit[MAX]; 
    memset(last_visit, -1, sizeof(last_visit)); 
  
    vector<int> ans(q); 
    int query_counter = 0; 
    cout<<"before loop"<<endl;
    for (int i=0; i<n; i++) 
    { 
        cout<<"FOR i: "<<i<<endl;
        cout<<"lasvisit !=-1 : "<<last_visit[arr[i]]<<endl;
        if (last_visit[arr[i]] !=-1) 
            update (last_visit[arr[i]] + 1, -1, bit, n); 
  
        last_visit[arr[i]] = i; 
        update(i + 1, 1, bit, n); 

        for (auto &&x : bit)
        {
            cout<<x<<" ";
        }cout<<endl;
        
  
        while (query_counter < q && queries[query_counter].r == i) 
        { 
            cout<<"while: "<<query(queries[query_counter].r + 1, bit, n)<<" - "<<query(queries[query_counter].l, bit, n)<<endl; 
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
    int a[] = {1, 2,2,4,5}; 
    int n = sizeof(a)/sizeof(a[0]); 
    Query queries[3]; 
    queries[0].l = 0; 
    queries[0].r = 4; 
    queries[0].idx = 0; 
    queries[1].l = 1; 
    queries[1].r = 3; 
    queries[1].idx = 1; 
    queries[2].l = 2; 
    queries[2].r = 4; 
    queries[2].idx = 2; 
    cout<<"q inputted"<<endl;
    int q = sizeof(queries)/sizeof(queries[0]); 
    sort(queries, queries+q, cmp); 
    cout<<"q sorted"<<endl;
    answeringQueries(a, n, queries, q); 
    return 0; 
} 

/*int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int cases,x,y,n,q;
    cin>>cases;

    for (int jj = 1; jj <= cases; jj++)
    {
        cout<<"Case "<<jj<<":"<<endl;
        cin>>n>>q;

        vector<int> a;

        for (int i = 0; i < n; i++)
        {
            cin>>x;
            a.push_back(x);
        }
        
        vector<Query> queries(q);

        for (int i = 0; i < q; i++)
        {
            cin>>x>>y;
            //queries.push_back({x,y,i});
            queries[i].l = x; 
            queries[i].r = y; 
            queries[i].idx = i; 
        }

        sort(queries.begin(), queries.end(), cmp); 

        answeringQueries(a, n, queries, q); 
    }
    
    return 0; 

}*/