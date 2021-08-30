#include<iostream>
#include<vector>
#include<algorithm>
#include<sstream>
using namespace std;

int main(){
    int out,count;
    vector<int> ip(2);
    cin>>count;
    string rev;
    stringstream halpp;

    for (int j = 0; j < count; j++)
    {
        for (int i = 0; i < 2; i++){                                         
            cin>>ip[i];
            halpp<<ip[i];
            halpp>>rev;
            reverse(rev.begin(), rev.end()); 
            halpp.clear();
            halpp<<rev;
            halpp>>ip[i];
            halpp.clear();
        }   
        out = ip[0]+ip[1];
        halpp<<out;
        halpp>>rev;
        halpp.clear();
        reverse(rev.begin(), rev.end()); 
        halpp<<rev;
        halpp>>out;
        halpp.clear();
        cout<<out<<"\n";
    }
    return 0;   
}

//https://www.geeksforgeeks.org/reverse-a-string-in-c-cpp-different-methods/
//https://www.geeksforgeeks.org/converting-strings-numbers-cc/
//https://www.javatpoint.com/cpp-int-to-string
//https://www.geeksforgeeks.org/stdreverse-in-c/