#include<iostream>
#include<vector>
#include<map>
using namespace std;



int main(){
    int count,max =0;
    int min = 10000000001;
    vector<int> ip(2);
    map<int, vector<int>> target;

    cin>>count;
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

    vector<bool> list(max+1, true);
    list[0] = list[1]=false;
    for (int p = 2; p*p < max+1; p++)
    {
        if (list[p]==true)
        {
            for (int i = p*p; i < max+1; i+=p)
            {
                list[i] = false; 
            }
        }
    }


    for (int z = 0; z < count; z++)
    {
        for (int p=target[z][0]; p<=target[z][1]; p++){ 
            if (list[p]==true) 
                cout << p << "\n";
        }
        cout<<"\n";
    }
   
    return 0;
}