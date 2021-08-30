//https://codeforces.com/problemset/problem/118/A

#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
#include<cmath>
#include<cstring>

using namespace std;




int main() 
{ 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string cases;
    cin>>cases;

    transform(cases.begin(), cases.end(), cases.begin(), ::tolower); 

    char chars[] = "aeiouy";
    for (unsigned int i = 0; i < strlen(chars); ++i)
    {
        cases.erase (std::remove(cases.begin(), cases.end(), chars[i]), cases.end());
    }
    
    for (auto &&x : cases)
    {
        cout<<"."<<x;
    }cout<<endl;
    
    
    return 0;
} 
