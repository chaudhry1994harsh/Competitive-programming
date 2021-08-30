//https://codeforces.com/problemset/problem/158/B

#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
#include<cmath>

using namespace std;


multiset<int> lol;
set<int>::iterator str;
set<int>::iterator ed;

void checkIT() 
{ 
    int count = 0,temp;

    while(!lol.empty())
    {
        str = lol.begin();
        ed = lol.end(); ed--;
        if(lol.size() == 1){
            lol.erase(str);
            count++;
        }
        else if(*str + *ed == 4){
            lol.erase(str);
            lol.erase(ed);
            count++;
        }
        else if(*str + *ed < 4){
            temp =*str + *ed;
            lol.erase(str);
            lol.erase(ed);
            count++;
            while (!lol.empty())
            {
                str = lol.begin();
                //cout<<"t: "<<temp<<" st: "<<*str<<endl;
                if(temp + *str <= 4){
                    //cout<<"if"<<endl;
                    lol.erase(str);
                    temp = temp + *str;
                }
                else{
                    break;
                }
            }
        }
        else if (*ed == 4){
            //cout<<"packup"<<endl;
            count++;
            lol.erase(ed);
        }
        else if(*str < 4 ){
            count++;
            temp = *str;
            lol.erase(str);
            while (!lol.empty())
            {
                str = lol.begin();
                //cout<<"t: "<<temp<<" st: "<<*str<<endl;
                if(temp + *str <= 4){
                    //cout<<"if"<<endl;
                    lol.erase(str);
                    temp = temp + *str;
                }
                else{
                    break;
                }
            }
        }
        else{
            cout<<"split"<<endl;
            lol.erase(ed);
            lol.erase(str);
            count += 2;
        }
    }
    cout<<count<<endl;
} 

int main() 
{ 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int cases,sz;
    cin>>cases;

    while (cases--)
    {
        cin>>sz;
        lol.insert(sz);
    }
    
    checkIT();
    
    return 0;
} 
