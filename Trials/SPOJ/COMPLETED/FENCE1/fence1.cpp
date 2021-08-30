#include<iostream>
#include <iomanip>  
#include<vector>
#include<algorithm>
#include<cmath>

using namespace std;


double domath(int ip){
    double r,ans;
    r = ip/3.14159265358979323846;
    ans = 3.14159265358979323846*r*r;
    return ans/2;
}


int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int ip;

    while(cin>>ip){
        if(ip != 0){
            cout << fixed << setprecision(2) << domath(ip) <<endl; 
        }
    }

    return 0;
}