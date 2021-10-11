#include<unordered_map>
#include<algorithm>
#include<iostream>
#include<iterator>
using namespace std;


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int cases,sub;
    string op;
    int homo=0;
    bool hetro;
    unordered_map<int,int> target;

    cin>>cases;

    while (cases>0)
    {
        cin>>op>>sub;
        hetro = false;
        if (op=="insert"){
            if(target[sub]>=1){
                target[sub] = target[sub]++;
                homo++;
            }
            else{
                target[sub]=1;
            }
        }
        else{
        //else if (op =="delete"){    
            if(target[sub]>1){
                target[sub] = target[sub]--;
                homo--;
            }
            else if(target[sub]=1){
                target.erase(sub);
            }
        }

        if(target.size()>1){
            hetro = true;
        }
        //cout<<homo<<endl;
        if(homo >0 && hetro == true){
            cout<<"both\n";
        }
        else if(homo >0){
            cout<<"homo\n";
        }
        else if(hetro == true){
            cout<<"hetero\n";
        }
        else{
            cout<<"neither\n";
        }
        
        cases--;
    }
    
    return 0;
} 