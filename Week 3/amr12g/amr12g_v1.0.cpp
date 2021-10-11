#include<iostream>
#include<algorithm>
#include<set>
using namespace std;

int main(){
    int count, cases, multiplier,tries = 0;
    string obj;
    multiset<char> target;
    cin>>count;

    while (count>0)
    {
        target.clear();
        cin>>cases>>multiplier>>tries;
        //cases = cases * multiplier;
        while (cases>0)
        {
            cin>>obj;
            //cout<<obj[0]<<endl;
            //cout<<obj<<endl;
            //cout<<obj[0]<<endl; 
            target.insert(obj[0]);
            //cin.clear();
            //fflush(stdin);
            obj.clear();
            cases--;
        }
        //cout<<"size"<<target.size()<<endl;



        for (auto &&x : target)
        {
            //cout<<x<<endl;
            if(tries==0){
                break;
            }
            if(target.find('.')!=target.end()){
                target.erase(target.find('.'));
                target.insert('*');
                tries--;
            }
            else{
                target.erase(target.find('*'));
                target.insert('.');
                tries--;
            }
        }
        
        cout<<target.count('*') * multiplier <<endl;
        
        count--;
    }
    
     return 0;
}