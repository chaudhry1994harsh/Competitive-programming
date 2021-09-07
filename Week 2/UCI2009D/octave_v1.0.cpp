#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;


void oct(vector<char> main,vector<char> ip, int x,bool eight,int place, map<int, vector<int>> octave,vector<int> target, vector<int> rev){
    if(eight==false){
        int count =0;
        for (int i = 0; i < ip.size(); i++)
        {
            if (ip[i]=='#')
            {
                count++;
            }
        }
        //cout<<"total #: "<<count<<"\n";
        if(count<8)
            cout<<"0\n";
        else
            oct(main,ip,x,true,place,octave,target,rev);
    }
    else{
        if(target.size()==8){
            //cout<<"checking oct\n";
            vector<int>::iterator itr;
            sort(target.begin(),target.end());
            itr = unique(target.begin(), target.end()); 
            target.resize(distance(target.begin(), itr));
            //place++;
            if(octave.empty() && target.size()==8){
                cout<<"first oct\n";
                octave.insert({0,target});
                target.clear();
                place++;
                oct(main,main,place,true,place,octave,target,rev);
            }
            else if(target.size()==8){
                bool checker = 0;
                for (int i = 0; i < octave.size(); i++)
                {
                    if(octave[i]==target)
                        checker=true;
                }
                if(checker==false){
                    cout<<"next oct \n";
                    octave.insert({octave.size(),target});
                    target.clear();
                    place++;
                    oct(main,main,place,true,place,octave,target,rev);
                }
                else{
                    cout<<"same oct found again\n";
                    target.clear();
                    place++;
                    oct(main,main,place,true,place,octave,target,rev);
                }
            }
            else{
                cout<<"false +ve";
                oct(main,ip,x,true,place,octave,target,rev);
            }
            //target.clear();
            //oct(main,main,place,true,place,octave,target);
        }
        else if (place == ip.size()){
            cout<<octave.size()<<"\n";
        }
        else if(main[x]=='#'){
            //cout<<place<<" pos\n";
            //target.push_back(x);
            //ip[place]='.';

            
            if(x+3<ip.size() && ip[x+3]=='#'){
                cout<<x<<" down ?\n";
                ip[x]='?';
                target.push_back(x);
                if(!rev.empty()){
                    ip[rev[0]]='#';
                    rev.erase (rev.begin() + 0);
                    /*int r = rev[rev.size()-1];
                    int r2 = rev[rev.size()-2];
                    rev.pop_back();
                    rev.pop_back();
                    for (int i = 0; i < rev.size(); i++)
                    {
                        ip[rev[i]]='#';
                    }
                    rev.clear();
                    rev.push_back(r);
                    rev.push_back(r2);*/
                }
                for (int i = 0; i < 3; i++)
                {
                    for (int j = i*3; j < (i*3)+3; j++)
                    {
                        cout<<ip[j];
                    }
                    cout<<"\n";
                }
                oct(main,ip,x+3,true,place,octave,target,rev);
            }
            else if(ip[x+1]=='#' && (x+1)%3!=0){
                cout<<x<<" right ?\n";
                ip[x]='?';
                target.push_back(x);
                if(!rev.empty()){
                    ip[rev[0]]='#';
                    rev.erase (rev.begin() + 0);
                    /*int r = rev[rev.size()-1];
                    int r2 = rev[rev.size()-2];
                    rev.pop_back();
                    rev.pop_back();
                    for (int i = 0; i < rev.size(); i++)
                    {
                        ip[rev[i]]='#';
                    }
                    rev.clear();
                    rev.push_back(r);
                    rev.push_back(r2);*/
                }
                for (int i = 0; i < 3; i++)
                {
                    for (int j = i*3; j < (i*3)+3; j++)
                    {
                        cout<<ip[j];
                    }
                    cout<<"\n";
                }
                oct(main,ip,x+1,true,place,octave,target,rev);
            }
            else if(x-3>=0 && ip[x-3]=='#'){
                cout<<x<<" up ?\n";
                ip[x]='?';
                target.push_back(x);
                if(!rev.empty()){
                    ip[rev[0]]='#';
                    rev.erase (rev.begin() + 0);
                    /*int r = rev[rev.size()-1];
                    int r2 = rev[rev.size()-2];
                    rev.pop_back();
                    rev.pop_back();
                    for (int i = 0; i < rev.size(); i++)
                    {
                        ip[rev[i]]='#';
                    }
                    rev.clear();
                    rev.push_back(r);
                    rev.push_back(r2);*/
                }
                for (int i = 0; i < 3; i++)
                {
                    for (int j = i*3; j < (i*3)+3; j++)
                    {
                        cout<<ip[j];
                    }
                    cout<<"\n";
                }
                oct(main,ip,x-3,true,place,octave,target,rev);
            }
            else if(ip[x-1]=='#' && x%3!=0){
                cout<<x<<" left ?\n";
                ip[x]='?';
                target.push_back(x);
                if(!rev.empty()){
                    ip[rev[0]]='#';
                    rev.erase (rev.begin() + 0);
                    /*int r = rev[rev.size()-1];
                    int r2 = rev[rev.size()-2];
                    rev.pop_back();
                    rev.pop_back();
                    for (int i = 0; i < rev.size(); i++)
                    {
                        ip[rev[i]]='#';
                    }
                    rev.clear();
                    rev.push_back(r);
                    rev.push_back(r2);*/
                }
                for (int i = 0; i < 3; i++)
                {
                    for (int j = i*3; j < (i*3)+3; j++)
                    {
                        cout<<ip[j];
                    }
                    cout<<"\n";
                }
                oct(main,ip,x-1,true,place,octave,target,rev);
            }


            else if(ip[x]=='#'){
                cout<<x<<"last # \n";
                //cout<<"place: "<<place<<"\n";
                ip[x]='?';
                target.push_back(x);
                //place++;
                //oct(main,main,place,true,place,octave,target);
                for (int i = 0; i < 3; i++)
                {
                    for (int j = i*3; j < (i*3)+3; j++)
                    {
                        cout<<ip[j];
                    }
                    cout<<"\n";
                }
                oct(main,ip,x,true,place,octave,target,rev);
            }   


            else if(x-3>=0 && ip[x-3]=='?'){
                cout<<x<<": rev.\n";
                ip[x] = '.';
                target.erase(find(target.begin(),target.end(),x));
                rev.push_back(x);
                for (int i = 0; i < 3; i++)
                {
                    for (int j = i*3; j < (i*3)+3; j++)
                    {
                        cout<<ip[j];
                    }
                    cout<<"\n";
                }
                oct(main,ip,x-3,true,place,octave,target,rev);
            }   
            
            else if(ip[x+1]=='?' && (x+1)%3!=0){
                cout<<x<<": rev.\n";
                ip[x] = '.';
                target.erase(find(target.begin(),target.end(),x));
                rev.push_back(x);
                for (int i = 0; i < 3; i++)
                {
                    for (int j = i*3; j < (i*3)+3; j++)
                    {
                        cout<<ip[j];
                    }
                    cout<<"\n";
                }
                oct(main,ip,x+1,true,place,octave,target,rev);
            }
            else if(x+3<ip.size() && ip[x+3]=='?'){
                cout<<x<<": rev.\n";
                ip[x] = '.';
                target.erase(find(target.begin(),target.end(),x));
                rev.push_back(x);
                for (int i = 0; i < 3; i++)
                {
                    for (int j = i*3; j < (i*3)+3; j++)
                    {
                        cout<<ip[j];
                    }
                    cout<<"\n";
                }
                oct(main,ip,x+3,true,place,octave,target,rev);
            }
            else if(ip[x-1]=='?' && x%3!=0){
                cout<<x<<": rev.\n";
                ip[x] = '.';
                target.erase(find(target.begin(),target.end(),x));
                rev.push_back(x);
                for (int i = 0; i < 3; i++)
                {
                    for (int j = i*3; j < (i*3)+3; j++)
                    {
                        cout<<ip[j];
                    }
                    cout<<"\n";
                }
                oct(main,ip,x-1,true,place,octave,target,rev);
            }


            else{
                cout<<"nothing left\n";               
                place++;
                target.clear();
                for (int i = 0; i < 3; i++)
                {
                    for (int j = i*3; j < (i*3)+3; j++)
                    {
                        cout<<ip[j];
                    }
                    cout<<"\n";
                }
                oct(main,main,place,true,place,octave,target,rev);
            }
        }
        else{
            //cout<<"Hit a . at: "<<x<<"\n";
            place++;
            //cout<<"place: "<<place<<"\n";
            oct(main,main,place,true,place,octave,target,rev);
        }
    }
}


int main(){
    int count,size = 0;
    vector<char> ip;
    vector<int> target;
    vector<int> rev;
    char car;
    map<int, vector<int>> octave;
    cin>> count;

    for (int i = 0; i < count; i++)
    {
        cin>>size;
        for (int m = 0; m < size*3; m++)
        {
                cin>>car;
                ip.push_back(car);
        }        
        oct(ip,ip,0,false,0,octave, target,rev);
        size = 0;
        ip.clear();
    }
    return 0;   
}

//https://stackoverflow.com/questions/5768316/pop-a-specific-element-off-a-vector-in-c/5768334