#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

int main(){
    int count,io;
    vector<int> ip;

    cin>>count;
    for (int i = 0; i < count; i++)
    {
        cin>>io;
        ip.push_back(io);
    }

    for (auto x : ip)
    {
        count =0;
        for (int i = 5; x / i >= 1; i *= 5) 
            count += x / i; 
        cout<<count<<"\n";
    }
    return 0;
}

//https://www.geeksforgeeks.org/count-trailing-zeroes-factorial-number/