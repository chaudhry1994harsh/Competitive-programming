#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
using namespace std;


void way (vector<char> v, int row, int col, int x,vector<int> ip){
    if(ip.empty()){
        vector<int>::iterator itr;
        //for (int i = ceil(x/row)*row; i < v.size()-row+2; i+=row)
        //{
            //cout<<"\n"<<i<<"\n";
            //for (int j = i; j < col+i; j++)
            for (int j = 0; j < v.size(); j++)
            {
                //cout<<j<<" j \n";
                //cout<<"second loop: "<<v[j];
                if (v[j]=='.' )
                {
                    //cout<<"enter if";
                    if(j<row || j%row==0 || (j+1)%row==0 || j>row*col-row){
                        //cout<<j<<":selected \n";
                        ip.push_back(j);
                    }
                }
            }   
        //}
        sort(ip.begin(),ip.end());
        itr = unique(ip.begin(), ip.end()); 
        ip.resize(distance(ip.begin(), itr));
        if(ip.empty()){
            cout<<"invalid\n";
        }
        else{
            //v[ip[0]]='#';
            way(v,row,col,ip[0],ip);
        }
    }
    else if(ip.size()>2 || ip.size()<2){
            cout<<"invalid\n";
    }
    else{
        if(x==ip[1]){
            cout<<"valid\n";
        }        
        else{
            //v[x]='?';
            if(x-row>=0 && v[x-row]=='.'){
                //cout<<x<<": 1 .\n";
                v[x] = '?';
                way(v,row,col,(x-row),ip);
            }   
            else if(x+row<v.size() && v[x+row]=='.'){
                //cout<<x<<": 2 .\n";
                v[x] = '?';
                way(v,row,col,(x+row),ip);
            }
            else if(v[x+1]=='.' && (x+1)%row!=0){
                //cout<<x<<": 3 .\n";
                v[x] = '?';
                way(v,row,col,(x+1),ip);
            }
            else if(v[x-1]=='.' && x%row!=0){
                //cout<<x<<": 4 .\n";
                v[x] = '?';
                way(v,row,col,(x-1),ip);
            }

            else if(x-row>=0 && v[x-row]=='?'){
                //cout<<x<<": 1 ?\n";
                v[x] = '#';
                way(v,row,col,(x-row),ip);
            }   
            else if(x+row<v.size() && v[x+row]=='?'){
                //cout<<x<<": 2 ?\n";
                v[x] = '#';
                way(v,row,col,(x+row),ip);
            }
            else if(v[x+1]=='?' && (x+1)%row!=0){
                //cout<<x<<": 3 ?\n";
                v[x] = '#';
                way(v,row,col,(x+1),ip);
            }
            else if(v[x-1]=='?' && x%row!=0){
                //cout<<x<<": 4 ?\n";
                v[x] = '#';
                way(v,row,col,(x-1),ip);
            }

            else{
                cout<<"invalid\n";
            }
        }
    }
}

int main(){
    int count,row,col = 0;
    vector<char> ip;
    vector<int> it(2);
    char car;
    cin>> count;

    for (int i = 0; i < count; i++)
    {
        cin>>row>>col;
        for (int m = 0; m < row*col; m++)
        {
            //for (int j = 0; j < col; j++)
            //{
                cin>>car;
                ip.push_back(car);
            //}
        }  
        it.clear();
        way(ip,col,row,0,it);
        row = col = 0;


        ip.clear();
    }
    return 0;   
}


//https://stackoverflow.com/questions/2850312/use-of-for-each-on-map-elements
//https://www.geeksforgeeks.org/recursion/