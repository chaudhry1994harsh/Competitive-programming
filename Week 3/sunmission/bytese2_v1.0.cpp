#include <iostream> 
#include <string> 
#include <algorithm>
#include <set>
#include<vector>
#include <algorithm>
using namespace std; 
  


int main() 
{ 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int count, cases, entry, exit = 0;
    //set<int> en;
    //set<int> ex;
    vector<int> en;
    vector<int> ex;
    int max, ty=0;

    cin>> count;

    while(count>0){
        cin >> cases;
        en.clear();
        ex.clear();
        while(cases>0){
            cin>>entry>>exit;
            //en.insert(entry);
            //ex.insert(exit);
            en.push_back(entry);
            ex.push_back(exit);
            cases--;
        }

        max = ty =0;

        sort(en.begin(), en.end());
        sort(ex.begin(), ex.end());  

        for (auto &&x : ex)
        {
            //cout<<"start"<<x<<endl;
            ty =0;
            for (int i = 0; i < ex.size(); i++)
            {
                if(en[i]<x)
                    ty++;
                else
                    break;
            }
            for (int i = 0; i < ex.size(); i++)
            {
                if(ex[i]<x)
                    ty--;
                else
                    break;
            }
            if(ty>max){
                max=ty;
                //cout<<"max"<<endl;
            }
        }
        cout<<max<<endl;
        count--;
    }
  
    return 0; 
} 