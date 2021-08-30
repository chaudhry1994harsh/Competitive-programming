#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<unordered_set>

using namespace std;



int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int cases, sz1,sz2;

    cin>>sz1>>sz2;
    cin>>cases;

    while(cases--)
    {
        int ca1,ca2,cb1,cb2,m1,m2,mouse,cat1,cat2,ms;
        cin>>m1>>m2>>ca1>>ca2>>cb1>>cb2;
        bool tr = false;

        mouse = min( min(abs(m1-sz1) , abs(m1-1)) , min(abs(m2-sz2) , abs(m2-1)) );

        if(mouse == abs(m1-sz1) && tr == false){
            //cout<<"c1 "<<mouse<<endl;
            cat1 = abs(ca1 - sz1) + abs(ca2 - m2);
            cat2 = abs(cb1 - sz1) + abs(cb2 - m2);
            //cout<<cat1<<" "<<cat2<<endl;
            /*if(mouse > cat1 && mouse > cat2){
                cout<<"YES"<<endl;
            }
            else{
                cout<<"NO"<<endl;
            }*/
            ms =mouse;
            ms ++;
            while(ms -- ){
                if(ms>0){
                cat1--;cat2--;}
            }

            if(cat1>=1 && cat2>=1){
                tr = true;
            }
        }
        if(mouse == abs(m1-1) && tr == false){
            //cout<<"c2 "<<mouse<<endl;
            cat1 = abs(ca2-1) + abs(ca2 - m2);
            cat2 = abs(cb2-1) + abs(cb2 - m2);
            //cout<<cat1<<" "<<cat2<<endl;
            ms =mouse;
            ms ++;
            while(ms -- ){
                if(ms>0){
                cat1--;cat2--;}
            }

            if(cat1>=1 && cat2>=1){
                tr = true;
            }
        }
        if(mouse == abs(m2-sz2) && tr == false){
            //cout<<"c3 "<<mouse<<endl;
            cat1 = abs(ca2 - sz2) + abs(ca1 - m1);
            cat2 = abs(cb2 - sz2) + abs(cb1 - m1);
            //cout<<cat1<<" "<<cat2<<endl;
            ms = mouse;
            ms ++;
            while(ms -- ){
                if(ms>0){
                cat1--;cat2--;}
            }
            //cout<<"check: "<<cat1<<" "<<cat2<<endl;
            if(cat1>=1 && cat2>=1){
                tr = true;
            }
        }
        if(mouse == abs(m2-1) && tr == false ){
            //cout<<"c4 "<<mouse<<endl;
            cat1 = abs(cb2-1) + abs(cb1 - m1);
            cat2 = abs(ca2-1) + abs(ca1 - m1);
            //cout<<cat1<<" "<<cat2<<endl;
            ms =mouse;
            ms ++;
            while(ms -- ){
                if(ms>0){
                cat1--;cat2--;}
            }

            if(cat1>=1 && cat2>=1){
                tr = true;
            }
        }
        if(tr) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }

    return 0;
}