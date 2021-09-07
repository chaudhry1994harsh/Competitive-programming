#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;


void oct(vector<char> ip, map<int, vector<int>>& octave, vector<int> travelled, int pos, vector<int> path, int x){ 
    
        vector<int>::iterator itr;
    if(pos == ip.size()){
        cout<<"ans: "<<octave.size()<<endl;
    }

    else if(octave.empty() && path.size()==8){
        octave.insert({0,path});
        path.clear();
        pos++;
        travelled.clear();
        cout<<pos<<endl;
        oct(ip,octave,travelled,pos,path,pos);
    }

    else if(path.size()==8){
        bool checker = 0;
        for (int i = 0; i < octave.size(); i++)
        {
            if(octave[i]==path)
                checker=true;
        }
        if(checker==false){
            cout<<"next oct \n";
            octave.insert({octave.size(),path});
            travelled.clear();
            path.clear();
            pos++;
            cout<<pos<<endl;
            oct(ip,octave,travelled,pos,path,pos);
        }
        else{
            cout<<"same oct found again\n";
            path.clear();
            travelled.clear();
            pos++;
            cout<<pos<<endl;
            oct(ip,octave,travelled,pos,path,pos);
        }
    }

    /*else if((x+3<ip.size() && ip[x+3]=='#' && find(travelled.begin(), travelled.end(),x+3)==travelled.end() )  || 
                (ip[x+1]=='#' && (x+1)%3!=0 && find(travelled.begin(), travelled.end(),x+1)==travelled.end() ) || 
                (x-3>=0 && ip[x-3]=='#' && find(travelled.begin(), travelled.end(),x-3)==travelled.end() )     || 
                (ip[x-1]=='#' && x%3!=0 && find(travelled.begin(), travelled.end(),x-1)==travelled.end() )     ){*/

        //cout<<"traversal"<<endl;

        else if(x+3<ip.size() && ip[x+3]=='#' && find(travelled.begin(), travelled.end(),x+3)==travelled.end() ){
            //cout<<x<<" down ?\n";
            path.push_back(x);
            travelled.push_back(x);
            
            sort(path.begin(),path.end());
            itr = unique(path.begin(), path.end()); 
            path.resize(distance(path.begin(), itr));

            oct(ip,octave,travelled,pos,path,x+3);
        }

        else if(ip[x+1]=='#' && (x+1)%3!=0 && find(travelled.begin(), travelled.end(),x+1)==travelled.end()){
            //cout<<x<<" right ?\n";
            path.push_back(x);
            travelled.push_back(x);
            
            sort(path.begin(),path.end());
            itr = unique(path.begin(), path.end()); 
            path.resize(distance(path.begin(), itr));

            oct(ip,octave,travelled,pos,path,x+1);
        }

        else if(x-3>=0 && ip[x-3]=='#' && find(travelled.begin(), travelled.end(),x-3)==travelled.end() ){
            //cout<<x<<" up ?\n";
            path.push_back(x);
            travelled.push_back(x);
            
            sort(path.begin(),path.end());
            itr = unique(path.begin(), path.end()); 
            path.resize(distance(path.begin(), itr));

            oct(ip,octave,travelled,pos,path,x-3);
        }

        else if(ip[x-1]=='#' && x%3!=0 && find(travelled.begin(), travelled.end(),x-1)==travelled.end()){
            //cout<<x<<" left ?\n";
            path.push_back(x);
            travelled.push_back(x);
            
            sort(path.begin(),path.end());
            itr = unique(path.begin(), path.end()); 
            path.resize(distance(path.begin(), itr));

            oct(ip,octave,travelled,pos,path,x-1);
        }
    //}
    else{
        travelled.clear();
        pos++;
        path.clear();
        cout<<pos<<endl;
        oct(ip,octave,travelled,pos,path,pos);
    }
}


int main(){
    int count,size = 0;
    vector<char> ip;
    vector<int> path;
    vector<int> travelled;
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
        //oct(ip,ip,0,false,0,octave, target,rev);
        oct(ip, octave, travelled, 0, path,0);
        size = 0;
        ip.clear();
    }
    return 0;   
}