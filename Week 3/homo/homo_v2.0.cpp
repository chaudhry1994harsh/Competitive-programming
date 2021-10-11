#include<set>
#include<algorithm>
#include<iostream>
#include<iterator>
using namespace std;


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int cases,sub;
    string op;
    bool homo, hetro;
    multiset<int> target;
    multiset <int> :: iterator itr; 

    cin>>cases;

    while (cases>0)
    {
        cin>>op>>sub;
        homo = hetro = false;
        if (op=="insert"){
            target.insert(sub);
        }
        else if (op =="delete"){    
            itr = find(target.begin(), target.end(),sub);
            if(itr!=target.end())
                target.erase(itr);
        }

        if(target.size()>1){
            for (auto &&x : target)
            {
                if(target.count(x)>1)
                    homo = true;
                if(target.count(x)<target.size())
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