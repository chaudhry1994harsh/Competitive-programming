#include<iostream>
#include<vector>
#include<map>
#include<cmath>
using namespace std;

int main(){
    int count,max= 0;
    int min =10001;
    bool check = false;
    vector<int> ip(2);
    map<int, bool> prime;
    prime.insert(pair<int,bool>(1,false));
    cin>>count;
    map<int, vector<int>> target;
    for (int j = 0; j < count; j++)
    {
        for (int i = 0; i < 2; i++){                                         
            cin>>ip[i];
            if(max<ip[i])
                max = ip[i];
            if(min>ip[i])
                min = ip[i];
        }
        target[j] = ip;
    }

    for (int i = min; i < max+1; i++)
    {
        if(i>1){
            check  =true;
        }
        if (i%2==0 && i!=2)
        {
            check = false;
        }
        else{
            for (int j = 3; j < i; j = j+2)
            {
                if(i%j == 0){
                    check = false;
                    prime.insert(pair<int,bool>(i,check));
                }
            }
        }
        if(check ==  true){
            prime.insert(pair<int,bool>(i,check));
        }
    }
    
    for (int j = 0; j < count; j++)
    {                                       
        for (int z = target[j][0]; z < target[j][1]+1; z++)
        {
            if(prime[z]==true)
                cout<<z<<"\n";
        }
        cout<<"\n";
    }
    return 0;
}