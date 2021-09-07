#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
#include<map>
using namespace std;


void von(int ip_main[7][8], int ip[7][8], map<pair<int,int>,int> lib_main,map<pair<int,int>,int> lib,int l,int m, int x, int pos){
    if(pos==7*8){
        cout<<x<<endl;
    }
    else if (lib.empty())
    {
        x++;
        cout<<x<<endl;
        pos++;
        /*if(pos==7*8){
            cout<<x<<endl;
        }*/
        //else{
            l = floor(pos/8);
            m = pos%8;
            von(ip_main,ip_main,lib_main,lib_main, l, m,x,pos);

       // }
    }
    else if(ip[l][m]<9 && ip[l][m+1]<9 && l<7 && m<8 && (lib.find({ip[l][m],ip[l][m+1]}) != lib.end() || lib.find({ip[m][l],ip[m+1][l]}) != lib.end())){
        cout<<l<<m<<" right"<<endl;
        ip[l][m]=9;
        ip[l][m+1]=9; 
        pos=pos+2;
        if(l<=m)
            lib.erase({ip[l][m],ip[l][m+1]});
        else
            lib.erase({ip[m][l],ip[m+1][l]});
        von(ip_main,ip,lib_main,lib, l, m+1,x,pos);
    }
    else if(ip[l][m]<9 && ip[l+1][m]<9 && l<7 && m<8 && (lib.find({ip[l][m],ip[l+1][m]}) != lib.end() || lib.find({ip[m][l],ip[m][l+1]}) != lib.end())){
        cout<<l<<m<<" down"<<endl;
        ip[l][m]=9;
        ip[l+1][m]=9; 
        pos=pos+2;
        if(l<=m)
            lib.erase({ip[l][m],ip[l+1][m]});
        else
            lib.erase({ip[m][l],ip[m][l+1]});
        von(ip_main,ip,lib_main,lib, l+1, m,x,pos);
    }
    else if(ip[l][m]<9 && ip[l][m-1]<9 && l>=0 && m>=8 && (lib.find({ip[l][m],ip[l][m-1]}) != lib.end() || lib.find({ip[m][l],ip[m-1][l]}) != lib.end())){
        cout<<l<<m<<" left"<<endl;
        ip[l][m]=9;
        ip[l][m-1]=9;
        pos=pos+2;
        if(l<=m)
            lib.erase({ip[l][m],ip[l][m-1]});
        else
            lib.erase({ip[m][l],ip[m-1][l]});
        von(ip_main,ip,lib_main,lib, l, m-1,x,pos);
    }
    else if(ip[l][m]<9 && ip[l-1][m]<9 && l>=0 && m>=0 && (lib.find({ip[l][m],ip[l-1][m]}) != lib.end() || lib.find({ip[m][l],ip[m][l-1]}) != lib.end())){
        cout<<l<<m<<" right"<<endl;
        ip[l][m]=9;
        ip[l-1][m]=9; 
        pos=pos+2;
        if(l<=m)
            lib.erase({ip[l][m],ip[l-1][m]});
        else
            lib.erase({ip[m][l],ip[m][l-1]});
        von(ip_main,ip,lib_main,lib, l-1, m,x,pos);
    }

    else if(ip[l][m]==9){
        cout<<l<<m<<" find new"<<endl;
        for (int i = 0; i < 7; i++)
        {
            for (int j = 0; j < 8; j++)
            {
                if(ip[i][j]!=9){
                    l=i;
                    m=j;
                    i=j=8;
                    break;
                }
            }
        }
        if(ip[l][m]!=9){
            pos++;
            von(ip_main,ip,lib_main,lib, l, m, x, pos);
        }
        else{
            pos++;
            von(ip_main,ip,lib_main,lib, l, m, x, pos);
        }
    }
    
}

int main(){
    int count;
    //cases;
    map<pair<int,int>,int> lib;
    int ip[7][8];
    count=0;
    for (int i = 0; i < 7; i++)
    {
        for (int j = i; j < 7; j++)
        {
            cout<<i<<j<<endl;
            lib.insert({{i,j},count});
            count++;
        }
        
    }
    //cout<<count<<endl<<endl;
    //cout<<lib.size()<<endl;
    /*for (int i = 0; i < 28; i++)
    {
        cout<<lib[i].first<<" "<<lib[i].second<<endl;
    }*/
    
    count = 0;
    cin>>count;
    while(count>0){
        for (int i = 0; i < 7; i++)
        {
            for (int j = 0; j < 8; j++)
            {
                cin>>ip[i][j];
            }
        }
        //cases--;
        count--;
        
        cout<<endl<<"start check matrix"<<endl;
        von(ip, ip, lib, lib,0,0,0,0);

        /*for (int i = 0; i < 7; i++)
        {
            for (int j = 0; j < 8; j++)
            {
                cout<<ip[i][j];
            }
            cout<<endl;
        }*/
        cout<<endl<<"end matrix check"<<endl;
    }   
        return 0;
}

//https://stackoverflow.com/questions/5990919/insert-pair-as-map-value
//https://www.geeksforgeeks.org/pair-in-cpp-stl/
//https://www.geeksforgeeks.org/map-erase-function-in-c-stl/
//