#include<iostream>
#include<vector>
using namespace std;

int main(){
    int count;
    bool check;
    vector<int> ip(2);
    cin>>count;

    while (count>0){
        for (int i = 0; i < 2; i++){                                         
            cin>>ip[i];
        }
        check = false;
        for (int i = ip[0]; i < ip[1]+1; i++)
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
                    }
                }
            }
            if(check ==  true){
                printf("%d \n", i);
            }
        }
        
        printf("\n");
        count--;
    }
    return 0;
}