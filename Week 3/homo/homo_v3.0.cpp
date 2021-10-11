#include<unordered_set>
#include<algorithm>
#include<iostream>
#include<iterator>
using namespace std;


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int cases,sub,cs;
    string op;
    bool homo, hetro;
    unordered_multiset<int> target;
    unordered_multiset <int> :: iterator itr; 

    cin>>cases;

    while (cases>0)
    {
        cin>>op>>sub;
        homo = hetro = false;
        if (op=="insert"){
            target.insert(sub);
        }
        else if (op =="delete"){    
            itr = target.find(sub);
            if(itr!=target.end())
                target.erase(itr);
        }

        if(target.size()>1){
            for (auto &&x : target)
            {   
                if(homo == true && hetro == true)
                    break;
                else
                    cs = target.count(x);
                if(homo == false && cs>1)
                    homo = true;
                if(hetro == false && cs<target.size())
                    hetro = true;
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

    return 0;
} 