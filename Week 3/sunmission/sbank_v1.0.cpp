#include <iostream> 
#include <string> 
#include <algorithm>
#include <set>
using namespace std; 
  


int main() 
{ 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int count, cases = 0;
    string str; 
    multiset<string> target;
    set<string> lol;
    //set <int> target;

  
    cin>> count;

    while(count>0){
        cin >> cases;
    
        while(cases>0){
            getline(cin,str);
            while (str.length()==0 ) 
                getline(cin, str); 
            target.insert(str);
            lol.insert(str);
            cases--;
        }
        
        for (auto &&x : lol)
        {
            cout<<x<<""<<target.count(x)<<endl;
        }
        
        cout<<endl;
        target.clear();
        lol.clear();

        count--;
    }
  
    return 0; 
} 