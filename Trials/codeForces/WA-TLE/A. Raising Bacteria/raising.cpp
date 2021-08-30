//https://codeforces.com/problemset/problem/579/A

#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
#include<unordered_map>
#include<cmath>

using namespace std;



int main() 
{ 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long cases,count;
    cin>>cases;

    for (long long i = 1; i <= cases; i = 2*i)
    {
        count = i;
        cout<<count<<endl;
    }
    
    count=cases-count;
    count++;
    cout<<count<<endl;
    
    return 0;
} 
