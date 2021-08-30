
#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<unordered_set>
#include<cmath>
#include<cstring>

using namespace std; 

  

void answeringQueries()
{ 
    cout<<"lol";
} 
  

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int cases,x,y,n,q;
    cin>>cases;

    for (int jj = 1; jj <= cases; jj++)
    {
        cout<<"Case "<<jj<<":"<<endl;
        cin>>n>>q;

        //vector<int> a(n+1);
        unordered_map<int,int> a;
        a[0]=0;
        for (int i = 1; i <= n; i++)
        {
            cin>>x;
            if(x>a[i-1]) a[i] = a[i-1] +1 ;
            else a[i] = a[i-1];
                
        }
        /*for (auto &&x : a)
        {
            cout<<x<<" ";
        }cout<<endl;*/
        

        for (int i = 0; i < q; i++)
        {
            cin>>x>>y;
            cout<<a[y] - a[x-1]<<endl;
        } 
    }
    
    return 0; 

}