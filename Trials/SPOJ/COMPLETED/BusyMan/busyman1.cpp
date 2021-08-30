#include<iostream>
#include<vector>
#include<set>
#include<algorithm>

using namespace std;


int sendit(set<pair<int, int>> tt){
    int count,Tcount = 0;
    set <pair<int,int> > :: reverse_iterator y; 
    for (y = tt.rbegin(); y != tt.rend() ; y++){
        count = 0;
        int start, end,tempS,tempE;
        set <pair<int,int> > :: reverse_iterator x; 
        for (x = y; x != tt.rend() ; x++)
        {
            if(count == 0){
                start = (*x).first;
                end = (*x).second;
                count++;
                //cout<<"on pair: "<<start<<" "<<end<<endl;
            }
            else{
                tempS = (*x).first;
                tempE = (*x).second;
                //cout<<"on pair: "<<tempS<<" "<<tempE<<endl;
                if(start == tempS){
                    //cout<<"smaller"<<endl;
                    if(abs(start-end) > abs(tempE - tempS)){
                        start = (*x).first;
                        end = (*x).second;
                    }
                }
                else if(end>=tempS){
                    //cout<<"next slot fits"<<endl;
                    count++;
                    end = tempE;
                    start = tempS;
                }
                /*else{
                    cout<<"skip"<<endl;
                }*/
            }
        }
        if(Tcount<count){
            Tcount = count;
        }
    }
    return Tcount;
}

int letsSEE(    set<pair<int, int>> tt){
    int timechk, count = 0;
    set <pair<int,int> > :: reverse_iterator y; 
    for (y = tt.rbegin(); y != tt.rend() ; y++){
        if(count == 0){
            timechk = (*y).second;
            count ++;
        }
        else if(timechk >= (*y).first){
            count++;
            timechk = (*y).second;
        }
    }
    return count;
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int cases,sz,a,b;

    cin>>cases;

    while(cases--){
        set<pair<int, int>> tt;
        cin>>sz;
        for (int i = 0; i < sz; i++)
        {
            cin>>a>>b;
            /*if(a == 0)
                a = 1000000;
            if(b == 0)
                b = 1000000;*/
            tt.insert(make_pair(b,a));
        }
        cout<<sendit(tt)<<endl;
        cout<<letsSEE(tt)<<endl;
    }

    return 0;
}