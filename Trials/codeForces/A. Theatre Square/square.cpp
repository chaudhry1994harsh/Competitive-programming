//https://codeforces.com/problemset/problem/1/A


#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
#include<cmath>

using namespace std;


double cases,sz,z;

void checkIT() 
{ 
    long long x,y;
    //cout<<cases/z<<" "<<sz/z<<endl;
    x = ceil(cases/z);
    y = ceil(sz/z);
    cout<<x*y<<endl;
} 

int main() 
{ 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    //int cases,sz,z;
    cin>>cases>>sz>>z;

    checkIT();
    
    return 0;
} 
