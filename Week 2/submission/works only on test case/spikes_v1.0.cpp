#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
#include<cmath>
using namespace std;


void way(vector<char> o_v,vector<char> v, int row, int col, int x, vector<int> ip, int lives, int o_lives, bool treasure,int pos){
    if(ip.empty()){
        bool check = false;
        vector<int>::iterator itr;

        for (int j = 0; j < v.size(); j++)
        {
            if (v[j]=='@' )
            {
                if(j<row || j%row==0 || (j+1)%row==0 || j>row*col-row){
                    ip.push_back(j);
                }
            }
            if(v[j]=='x' ){
                check = true;
            }
        }   

        sort(ip.begin(),ip.end());
        itr = unique(ip.begin(), ip.end()); 
        ip.resize(distance(ip.begin(), itr));
        if(ip.empty() || check != true){
            cout<<"IMPOSSIBLE\n";
        }
        else{
            //v[ip[0]]='#';
            way(o_v,v,row,col,ip[0],ip, lives, o_lives,treasure,pos);
        }
    }

    else{
        if(lives<0){
            pos++;
            if(pos<ip.size())
                way(o_v,o_v,row,col,ip[pos],ip, o_lives, o_lives,false,pos);
            else{
                cout<<"IMPOSSIBLE\n";
            }
        }


        else if(treasure==true){
            if (x-row>=0 && v[x-row]=='@'){
                //cout<<x<<": 1 .\n";
                //v[x] = '?';
                //way(v,row,col,(x-row),ip,lives, o_lives,true,pos);
                cout<<"POSSIBLE\n";
            }   
            else if(x+row<v.size() && v[x+row]=='@'){
                //cout<<x<<": 2 .\n";
                //v[x] = '?';
                //way(v,row,col,(x+row),ip,lives, o_lives,true,pos);
                cout<<"POSSIBLE\n";
            }
            else if(v[x+1]=='@' && (x+1)%row!=0){
                //cout<<x<<": 3 .\n";
                //v[x] = '?';
                //way(v,row,col,(x+1),ip,lives, o_lives,true,pos);
                cout<<"POSSIBLE\n";
            }
            else if(v[x-1]=='@' && x%row!=0){
                //cout<<x<<": 4 .\n";
                //v[x] = '?';
                //way(v,row,col,(x-1),ip,lives, o_lives,true,pos);
                cout<<"POSSIBLE\n";
            }

            else if(x-row>=0 && v[x-row]=='.'){
                //cout<<x<<": 1 .\n";
                //v[x] = '?';
                way(o_v,v,row,col,(x-row),ip,lives, o_lives,treasure,pos);
            }   
            else if(x+row<v.size() && v[x+row]=='.'){
                //cout<<x<<": 2 .\n";
                //v[x] = '?';
                way(o_v,v,row,col,(x+row),ip,lives, o_lives,treasure,pos);
            }
            else if(v[x+1]=='.' && (x+1)%row!=0){
                //cout<<x<<": 3 .\n";
                //v[x] = '?';
                way(o_v,v,row,col,(x+1),ip,lives, o_lives,treasure,pos);
            }
            else if(v[x-1]=='.' && x%row!=0){
                //cout<<x<<": 4 .\n";
                //v[x] = '?';
                way(o_v,v,row,col,(x-1),ip,lives, o_lives,treasure,pos);
            }


            else if(x-row>=0 && v[x-row]=='?'){
                //cout<<x<<": 1 .\n";
                v[x] = '#';
                way(o_v,v,row,col,(x-row),ip,lives, o_lives,treasure,pos);
            }   
            else if(x+row<v.size() && v[x+row]=='?'){
                //cout<<x<<": 2 .\n";
                v[x] = '#';
                way(o_v,v,row,col,(x+row),ip,lives, o_lives,treasure,pos);
            }
            else if(v[x+1]=='?' && (x+1)%row!=0){
                //cout<<x<<": 3 .\n";
                v[x] = '#';
                way(o_v,v,row,col,(x+1),ip,lives, o_lives,treasure,pos);
            }
            else if(v[x-1]=='?' && x%row!=0){
                //cout<<x<<": 4 .\n";
                v[x] = '#';
                way(o_v,v,row,col,(x-1),ip,lives, o_lives,treasure,pos);
            }

            else if(x-row>=0 && v[x-row]=='s'){
                //cout<<x<<": 1 .\n";
                lives--;
                way(o_v,v,row,col,(x-row),ip,lives, o_lives,treasure,pos);
            }   
            else if(x+row<v.size() && v[x+row]=='s'){
                //cout<<x<<": 2 .\n";
                lives--;
                way(o_v,v,row,col,(x+row),ip,lives, o_lives,treasure,pos);
            }
            else if(v[x+1]=='s' && (x+1)%row!=0){
                //cout<<x<<": 3 .\n";
                lives--;
                way(o_v,v,row,col,(x+1),ip,lives, o_lives,treasure,pos);
            }
            else if(v[x-1]=='s' && x%row!=0){
                //cout<<x<<": 4 .\n";
                lives--;
                way(o_v,v,row,col,(x-1),ip,lives, o_lives,treasure,pos);
            }


            else
            {
                pos++;
                if(pos<ip.size())
                    way(o_v,o_v,row,col,ip[pos],ip, o_lives, o_lives,false,pos);
                else
                    cout<<"IMPOSSIBLE\n";
            }
            
        }


        


        else if (x-row>=0 && v[x-row]=='x'){
            //cout<<x<<": 1 .\n";
            if(o_lives-lives<=lives){
            //if(lives>=ceil((double)o_lives/2)){
                cout<<"POSSIBLE\n";
                /*cout<<lives<<endl;
                cout<<o_lives<<endl;
                cout<<ceil((double)o_lives/2);*/
            }
            else{
                v[x] = '!';
                way(o_v,v,row,col,(x-row),ip,lives, o_lives,true,pos);
            }
        }   
        else if(x+row<v.size() && v[x+row]=='x'){
            //cout<<x<<": 2 .\n";
            if(o_lives-lives<=lives){
            //if(lives>=ceil((double)o_lives/2)){
                cout<<"POSSIBLE\n";
                /*cout<<lives<<endl;
                cout<<o_lives<<endl;
                cout<<ceil((double)o_lives/2);*/
            }
            else{
                v[x] = '!';
                way(o_v,v,row,col,(x+row),ip,lives, o_lives,true,pos);
            }
        }
        else if(v[x+1]=='x' && (x+1)%row!=0){
            //cout<<x<<": 3 .\n";
            if(o_lives-lives<=lives){
            //if(lives>=ceil((double)o_lives/2)){
                cout<<"POSSIBLE\n";
                /*cout<<lives<<endl;
                cout<<o_lives<<endl;
                cout<<ceil((double)o_lives/2);*/
            }
            else{
                v[x] = '!';
                way(o_v,v,row,col,(x+1),ip,lives, o_lives,true,pos);
            }
        }
        else if(v[x-1]=='x' && x%row!=0){
            //cout<<x<<": 4 .\n";
            if(o_lives-lives<=lives){
            //if(lives>=ceil((double)o_lives/2)){
                cout<<"POSSIBLE\n";
                /*cout<<lives<<endl;
                cout<<o_lives<<endl;
                cout<<ceil((double)o_lives/2);*/
            }
            else{
                v[x] = '!';
                way(o_v,v,row,col,(x-1),ip,lives, o_lives,true,pos);
            }
        }


        else if(x-row>=0 && v[x-row]=='.'){
            //cout<<x<<": 1 .\n";
            v[x] = '?';
            way(o_v,v,row,col,(x-row),ip,lives, o_lives,treasure,pos);
        }   
        else if(x+row<v.size() && v[x+row]=='.'){
            //cout<<x<<": 2 .\n";
            v[x] = '?';
            way(o_v,v,row,col,(x+row),ip,lives, o_lives,treasure,pos);
        }
        else if(v[x+1]=='.' && (x+1)%row!=0){
            //cout<<x<<": 3 .\n";
            v[x] = '?';
            way(o_v,v,row,col,(x+1),ip,lives, o_lives,treasure,pos);
        }
        else if(v[x-1]=='.' && x%row!=0){
            //cout<<x<<": 4 .\n";
            v[x] = '?';
            way(o_v,v,row,col,(x-1),ip,lives, o_lives,treasure,pos);
        }


        else if(x-row>=0 && v[x-row]=='s'){
            //cout<<x<<": 1 .\n";
            lives--;
            way(o_v,v,row,col,(x-row),ip,lives, o_lives,treasure,pos);
        }   
        else if(x+row<v.size() && v[x+row]=='s'){
            //cout<<x<<": 2 .\n";
            lives--;
            way(o_v,v,row,col,(x+row),ip,lives, o_lives,treasure,pos);
        }
        else if(v[x+1]=='s' && (x+1)%row!=0){
            //cout<<x<<": 3 .\n";
            lives--;
            way(o_v,v,row,col,(x+1),ip,lives, o_lives,treasure,pos);
        }
        else if(v[x-1]=='s' && x%row!=0){
            //cout<<x<<": 4 .\n";
            lives--;
            way(o_v,v,row,col,(x-1),ip,lives, o_lives,treasure,pos);
        }

        else if(x-row>=0 && v[x-row]=='?'){
            //cout<<x<<": 1 .\n";
            v[x] = '#';
            way(o_v,v,row,col,(x-row),ip,lives, o_lives,treasure,pos);
        }   
        else if(x+row<v.size() && v[x+row]=='?'){
            //cout<<x<<": 2 .\n";
            v[x] = '#';
            way(o_v,v,row,col,(x+row),ip,lives, o_lives,treasure,pos);
        }
        else if(v[x+1]=='?' && (x+1)%row!=0){
            //cout<<x<<": 3 .\n";
            v[x] = '#';
            way(o_v,v,row,col,(x+1),ip,lives, o_lives,treasure,pos);
        }
        else if(v[x-1]=='?' && x%row!=0){
            //cout<<x<<": 4 .\n";
            v[x] = '#';
            way(o_v,v,row,col,(x-1),ip,lives, o_lives,treasure,pos);
        }



        else{
            pos++;
            if(pos<ip.size())
                way(o_v,o_v,row,col,ip[pos],ip, o_lives, o_lives,false,pos);
            else{
                cout<<"IMPOSSIBLE\n";
            }
        }
    }
}


int main(){
    int row,col, lives= 0;
    //int count = 0;
    vector<char> ip;
    vector<int> it;
    char car;
    //cin>> count;

    //for (int i = 0; i < count; i++)
    //{
        cin>>row>>col>>lives;
        for (int m = 0; m < row*col; m++)
        {
            //for (int j = 0; j < col; j++)
            //{
                cin>>car;
                ip.push_back(car);
            //}
        }  
        it.clear();
        //way(ip,col,row,0,it);
        way(ip,ip,col,row,0,it, lives, lives,false,0);
        row = col = 0;


        ip.clear();
    //}
    return 0;   
}


//https://stackoverflow.com/questions/33273359/in-c-using-the-ceil-a-division-is-not-working