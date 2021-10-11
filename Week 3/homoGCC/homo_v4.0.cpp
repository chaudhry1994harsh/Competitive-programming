#include<unordered_map>
#include<algorithm>
#include<iostream>
#include<iterator>
using namespace std;


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int cases,sub,ty;
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
            //cout<<"ins"<<endl;
            if(target[sub]>=1){
                //cout<<"++"<<endl;
                ty = target[sub];
                ty++;
                target[sub] = ty;
                homo++;
            }
            else{
                //cout<<"add"<<endl;
                target[sub]=1;
            }
        }
        else{
        //else if (op =="delete"){    
            //cout<<"del"<<endl;
            if(target[sub]>1){
                //cout<<"--"<<endl;
                ty = target[sub];
                ty--;
                target[sub] = ty;
                homo--;
            }
            else if(target[sub]=1){
                //cout<<"erase"<<endl;
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