#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int cases,sub;
    string op;
    vector<int> target;
    vector<int>::iterator itr;
    bool homo, hetro;

    cin>>cases;


    while (cases>0){
        cin>>op>>sub;
        homo = hetro = false;
        if (op=="insert"){
            target.push_back(sub);
        }
        else if (op =="delete"){    
            itr = find(target.begin(), target.end(),sub);
            if(itr!=target.end())
                target.erase(itr);
        }

        if(target.size()>1){
            for (int j = 0; j < target.size(); j++)
            {
                for (int i = j+1; i < target.size(); i++)
                {
                    if(target[j]==target[i])
                        homo = true;
                    if(target[j]!=target[i])
                        hetro = true;
                }
            }
            
            if(homo == true && hetro == true){
                cout<<"both\n";
            }
            else if(homo == true){
                cout<<"homo\n";
            }
            else if(hetro == true){
                cout<<"hetro\n";
            }
            else{
                cout<<"neither\n";
            }
        }
        else{
            cout<<"neither\n";
        }

        cases--;
    }
    
    //cout<<target.size();
    
    return 0;

}