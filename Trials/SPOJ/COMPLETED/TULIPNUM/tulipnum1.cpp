#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<unordered_set>
#include<cmath>

using namespace std;


int block; 
  
struct Query 
{ 
    int L, R; 
}; 
  

bool compare(Query x, Query y) 
{ 
    if (x.L/block != y.L/block) 
        return x.L/block < y.L/block; 
  
    return x.R < y.R; 
} 
  
void queryResults(vector<int> a, int n, vector<Query> q, int m) 
{ 
    block = (int)sqrt(n); 
  
    sort(q.begin(), q.end(), compare); 
  
    int currL = 0, currR = 0; 
    int currSum = 0; 

    for (int i=0; i<m; i++) 
    { 
        int L = q[i].L, R = q[i].R; 
  
        while (currL < L) 
        { 
            currSum -= a[currL]; 
            currL++; 
        } 
  
        while (currL > L) 
        { 
            currSum += a[currL-1]; 
            currL--; 
        } 
        while (currR <= R) 
        { 
            currSum += a[currR]; 
            currR++; 
        } 
  
        while (currR > R+1) 
        { 
            currSum -= a[currR-1]; 
            currR--; 
        } 
  
        cout << "Sum of [" << L << ", " << R 
             << "] is "  << currSum << endl; 
    } 
} 
  

/*int main() 
{ 
    int a[] = {1, 1, 2, 1, 3, 4, 5, 2, 8}; 
    int n = sizeof(a)/sizeof(a[0]); 
    Query q[] = {{0, 4}, {1, 3}, {2, 4}}; 
    int m = sizeof(q)/sizeof(q[0]); 
    queryResults(a, n, q, m); 
    return 0; 
} */
int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int> mp;
    vector<Query> q;

    int cases, sz,query,temp,a,b;

    cin>>cases;

    for (int jj = 1; jj <= cases; jj++)
    {
        cout<<"Case "<<jj<<":"<<endl;
        mp.clear();
        q.clear();
        cin>>sz>>query;

        for (int i = 1; i <= sz; i++)
        {
            cin>>temp;
            mp.push_back(temp);
        }
        
        for (int i = 0; i < query; i++)
        {
            cin>>a>>b;
            q.push_back({a,b});
        }
        queryResults(mp,mp.size(),q,q.size());
    }

    return 0;
}