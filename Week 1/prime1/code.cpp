#include<iostream>
#include<vector>
#include<map>
#include<cmath>
using namespace std;

int main(){
    int count;
    double itr;
    bool check = false;
    vector<int> ip(2);
    map<int, bool> prime;
    prime.insert(pair<int,bool>(1,false));
    cin>>count;

    while (count>0){
        for (int i = 0; i < 2; i++){                                         
            cin>>ip[i];
        }
        for (int i = ip[0]; i < ip[1]+1; i++)
        {
            itr =i;
            if(prime.count(itr)==0){
                if(itr>1){
                    check  =true;
                }
                while (itr>2)
                {
                    itr--;
                    if (floor(i/itr) == i/itr){
                        check = false;
                        prime.insert(pair<int,bool>(i,check));
                    }
                }
                if(check ==  true){
                    prime.insert(pair<int,bool>(i,check));
                    cout<<i<<"\n";
                }
            }
            else{
                if(prime[itr]==true){
                    cout<<itr<<"\n";
                }
            }
        }
        cout<<"\n";
        count--;
    }
    return 0;
}