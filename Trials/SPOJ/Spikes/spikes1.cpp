#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
#include<cmath>
using namespace std;

char mz[45][45];
int row , col;


bool checkTHIS(string code,int lives, pair<int,int> entry,bool treas){
    cout<<"CASE: "<<code<<" "<<entry.first<<" "<<entry.second<<endl;

    if(lives<0){
        cout<<"no lives"<<endl;
        return false;
    }

    if(code == "left"){
        if(mz[entry.first][entry.second -1] == '.' && (entry.second -1)>0){
            code = "up";
            cout<<"found ."<<endl;
            if(checkTHIS(code,lives, make_pair(entry.first,entry.second -1),treas)) return true;
        }
        if(mz[entry.first][entry.second +1] == '.' && (entry.second +1)<=row){
            code = "down";
            cout<<"found ."<<endl;
            if(checkTHIS(code,lives, make_pair(entry.first,entry.second +1),treas)) return true;
        }
        if(mz[entry.first -1][entry.second] == '.' && (entry.first -1)>0){
            code = "left";
            cout<<"found ."<<endl;
            if(checkTHIS(code,lives, make_pair(entry.first -1,entry.second),treas)) return true;
        }
        if(mz[entry.first][entry.second -1] == 's' && (entry.second -1)>0){
            code = "up";lives--;
            cout<<"found s,  lives: "<<lives<<endl;
            if(checkTHIS(code,lives, make_pair(entry.first,entry.second -1),treas)) return true;
        }
        if(mz[entry.first][entry.second +1] == 's' && (entry.second +1)<=row){
            code = "down";lives--;
            cout<<"found s,  lives: "<<lives<<endl;
            if(checkTHIS(code,lives, make_pair(entry.first,entry.second +1),treas)) return true;
        }
        if(mz[entry.first -1][entry.second] == 's' && (entry.first -1)>0){
            code = "left";lives--;
            cout<<"found s,  lives: "<<lives<<endl;
            if(checkTHIS(code,lives, make_pair(entry.first -1,entry.second),treas)) return true;
        }
        if(mz[entry.first][entry.second -1] == 'x' && (entry.second -1)>0){
            code = "found";
            cout<<"found x"<<endl;
            if(checkTHIS(code,lives, make_pair(entry.first,entry.second -1),true)) return true;
        }
        if(mz[entry.first][entry.second +1] == 'x' && (entry.second +1)<=row){
            code = "found";
            cout<<"found x"<<endl;
            if(checkTHIS(code,lives, make_pair(entry.first,entry.second +1),true)) return true;
        }
        if(mz[entry.first -1][entry.second] == 'x' && (entry.first -1)>0){
            code = "found";
            cout<<"found x"<<endl;
            if(checkTHIS(code,lives, make_pair(entry.first -1,entry.second),true)) return true;
        }
        if(mz[entry.first][entry.second -1] == '@' && (entry.second -1)>0 && treas == true){
            cout<<"found @"<<endl;
            return true;
        }
        if(mz[entry.first][entry.second +1] == '@' && (entry.second +1)<=row && treas == true){
            cout<<"found @"<<endl;
            return true;
        }
        if(mz[entry.first -1][entry.second] == '@' && (entry.first -1)>0 && treas == true){
            cout<<"found @"<<endl;
            return true;
        }

    }
    if(code == "right"){
        if(mz[entry.first][entry.second -1] == '.' && (entry.second -1)>0){
            code = "up";
            cout<<"found ."<<endl;
            if(checkTHIS(code,lives, make_pair(entry.first,entry.second -1),treas)) return true;;
        }
        if(mz[entry.first][entry.second +1] == '.' && (entry.second +1)<=row){
            code = "down";
            cout<<"found ."<<endl;
            if(checkTHIS(code,lives, make_pair(entry.first,entry.second +1),treas)) return true;
        }
        if(mz[entry.first +1][entry.second] == '.' && (entry.first +1)<=col){
            code = "right";
            cout<<"found ."<<endl;
            if(checkTHIS(code,lives, make_pair(entry.first +1,entry.second),treas)) return true;
        }
        if(mz[entry.first][entry.second -1] == 's' && (entry.second -1)>0){
            code = "up"; lives--;
            cout<<"found s,  lives: "<<lives<<endl;
            if(checkTHIS(code,lives, make_pair(entry.first,entry.second -1),treas)) return true;
        }
        if(mz[entry.first][entry.second +1] == 's' && (entry.second +1)<=row){
            code = "down"; lives--;
            cout<<"found s,  lives: "<<lives<<endl;
            if(checkTHIS(code,lives, make_pair(entry.first,entry.second +1),treas)) return true;
        }
        if(mz[entry.first +1][entry.second] == 's' && (entry.first +1)<=col){
            code = "right"; lives--;
            cout<<"found s,  lives: "<<lives<<endl;
            if(checkTHIS(code,lives, make_pair(entry.first +1,entry.second),treas)) return true;
        }
        if(mz[entry.first][entry.second -1] == 'x' && (entry.second -1)>0){
            code = "found"; 
            cout<<"found x"<<endl;
            if(checkTHIS(code,lives, make_pair(entry.first,entry.second -1),true)) return true;
        }
        if(mz[entry.first][entry.second +1] == 'x' && (entry.second +1)<=row){
            code = "found"; 
            cout<<"found x"<<endl;
            if(checkTHIS(code,lives, make_pair(entry.first,entry.second +1),true)) return true;
        }
        if(mz[entry.first +1][entry.second] == 'x' && (entry.first +1)<=col){
            code = "found"; 
            cout<<"found x"<<endl;
            if(checkTHIS(code,lives, make_pair(entry.first +1,entry.second),true)) return true;
        }
        if(mz[entry.first][entry.second -1] == '@' && (entry.second -1)>0 && treas == true){
            cout<<"found @"<<endl;
            return true;
        }
        if(mz[entry.first][entry.second +1] == '@' && (entry.second +1)<=row && treas == true){
            cout<<"found @"<<endl;
            return true;
        }
        if(mz[entry.first +1][entry.second] == '@' && (entry.first +1)<=col && treas == true){
            cout<<"found @"<<endl;
            return true;
        }
    }
    if(code == "up"){
        if(mz[entry.first -1][entry.second] == '.' && (entry.first -1)>0){
            code = "left";
            cout<<"found ."<<endl;
            if(checkTHIS(code,lives, make_pair(entry.first -1,entry.second),treas)) return true;
        }
        if(mz[entry.first +1][entry.second] == '.' && (entry.first +1)<=col){
            code = "right";
            cout<<"found ."<<endl;
            if(checkTHIS(code,lives, make_pair(entry.first +1,entry.second),treas)) return true;
        }
        if(mz[entry.first][entry.second -1] == '.' && (entry.second -1)<=row){
            code = "up";
            cout<<"found ."<<endl;
            if(checkTHIS(code,lives, make_pair(entry.first,entry.second -1),treas)) return true;
        }
        if(mz[entry.first -1][entry.second] == 's' && (entry.first -1)>0){
            code = "left"; lives -- ;
            cout<<"found s,  lives: "<<lives<<endl;
            if(checkTHIS(code,lives, make_pair(entry.first -1,entry.second),treas)) return true;
        }
        if(mz[entry.first +1][entry.second] == 's' && (entry.first +1)<=col){
            code = "right"; lives -- ;
            cout<<"found s,  lives: "<<lives<<endl;
            if(checkTHIS(code,lives, make_pair(entry.first +1,entry.second),treas)) return true;
        }
        if(mz[entry.first][entry.second -1] == 's' && (entry.second -1)<=row){
            code = "up"; lives -- ;
            cout<<"found s,  lives: "<<lives<<endl;
            if(checkTHIS(code,lives, make_pair(entry.first,entry.second -1),treas)) return true;
        }
        if(mz[entry.first -1][entry.second] == 'x' && (entry.first -1)>0){
            code = "found"; 
            cout<<"found x"<<endl;
            if(checkTHIS(code,lives, make_pair(entry.first -1,entry.second),true)) return true;
        }
        if(mz[entry.first +1][entry.second] == 'x' && (entry.first +1)<=col){
            code = "found"; 
            cout<<"found x"<<endl;
            if(checkTHIS(code,lives, make_pair(entry.first +1,entry.second),true)) return true;
        }
        if(mz[entry.first][entry.second -1] == 'x' && (entry.second -1)<=row){
            code = "found"; 
            cout<<"found x"<<endl;
            if(checkTHIS(code,lives, make_pair(entry.first,entry.second -1),true)) return true;
        }
        if(mz[entry.first -1][entry.second] == '@' && (entry.first -1)>0 && treas == true){
            cout<<"found @"<<endl;
            return true;
        }
        if(mz[entry.first +1][entry.second] == '@' && (entry.first +1)<=col && treas == true){
            cout<<"found @"<<endl;
            return true;
        }
        if(mz[entry.first][entry.second -1] == '@' && (entry.second -1)<=row && treas == true){
            cout<<"found @"<<endl;
            return true;
        }
    }
    if(code == "down"){
        if(mz[entry.first -1][entry.second] == '.' && (entry.first -1)>0){
            code = "left";
            cout<<"found ."<<endl;
            if(checkTHIS(code,lives, make_pair(entry.first -1,entry.second),treas)) return true;
        }
        if(mz[entry.first +1][entry.second] == '.' && (entry.first +1)<=col){
            code = "right";
            cout<<"found ."<<endl;
            if(checkTHIS(code,lives, make_pair(entry.first +1,entry.second),treas)) return true;
        }
        if(mz[entry.first][entry.second +1] == '.' && (entry.second +1)>0){
            code = "down";
            cout<<"found ."<<endl;
            if(checkTHIS(code,lives, make_pair(entry.first,entry.second +1),treas)) return true;
        }
        if(mz[entry.first -1][entry.second] == 's' && (entry.first -1)>0){
            code = "left"; lives --;
            cout<<"found s,  lives: "<<lives<<endl;
            if(checkTHIS(code,lives, make_pair(entry.first -1,entry.second),treas)) return true;
        }
        if(mz[entry.first +1][entry.second] == 's' && (entry.first +1)<=col){
            code = "right"; lives --;
            cout<<"found s,  lives: "<<lives<<endl;
            if(checkTHIS(code,lives, make_pair(entry.first +1,entry.second),treas)) return true;
        }
        if(mz[entry.first][entry.second +1] == 's' && (entry.second +1)>0){
            code = "down"; lives --;
            cout<<"found s,  lives: "<<lives<<endl;
            if(checkTHIS(code,lives, make_pair(entry.first,entry.second +1),treas)) return true;
        }
        if(mz[entry.first -1][entry.second] == 'x' && (entry.first -1)>0){
            code = "found"; 
            cout<<"found x"<<endl;
            if(checkTHIS(code,lives, make_pair(entry.first -1,entry.second),true)) return true;
        }
        if(mz[entry.first +1][entry.second] == 'x' && (entry.first +1)<=col){
            code = "found"; 
            cout<<"found x"<<endl;
            if(checkTHIS(code,lives, make_pair(entry.first +1,entry.second),true)) return true;
        }
        if(mz[entry.first][entry.second +1] == 'x' && (entry.second +1)>0){
            code = "found"; 
            cout<<"found x"<<endl;
            if(checkTHIS(code,lives, make_pair(entry.first,entry.second +1),true)) return true;
        }
        if(mz[entry.first -1][entry.second] == '@' && (entry.first -1)>0 && treas == true){
            cout<<"found @"<<endl;
            return true;
        }
        if(mz[entry.first +1][entry.second] == '@' && (entry.first +1)<=col && treas == true){
            cout<<"found @"<<endl;
            return true;
        }
        if(mz[entry.first][entry.second +1] == '@' && (entry.second +1)>0 && treas == true){
            cout<<"found @"<<endl;
            return true;
        }
    }
    if(code == "found"){
        if(mz[entry.first][entry.second +1] == '.' && (entry.second +1)<=row){
            code = "down"; 
            cout<<"found ."<<endl;
            if(checkTHIS(code,lives, make_pair(entry.first,entry.second+1),true)) return true;
        }
        if(mz[entry.first -1][entry.second] == '.' && (entry.first -1)>0){
            code = "left"; 
            cout<<"found ."<<endl;
            if(checkTHIS(code,lives, make_pair(entry.first-1,entry.second),true)) return true;
        }
        if(mz[entry.first +1][entry.second] == '.' && (entry.first +1)<=col){
            code = "right"; 
            cout<<"found ."<<endl;
            if(checkTHIS(code,lives, make_pair(entry.first+1,entry.second),true)) return true;
        }
        if(mz[entry.first][entry.second -1] == '.' && (entry.second -1)>0){
            code = "up"; 
            cout<<"found ."<<endl;
            if(checkTHIS(code,lives, make_pair(entry.first,entry.second-1),true)) return true;
        }
        if(mz[entry.first][entry.second +1] == 's' && (entry.second +1)<=row){
            code = "down";  lives--;
            cout<<"found s"<<endl;
            if(checkTHIS(code,lives, make_pair(entry.first,entry.second+1),true)) return true;
        }
        if(mz[entry.first -1][entry.second] == 's' && (entry.first -1)>0){
            code = "left";  lives--;
            cout<<"found s"<<endl;
            if(checkTHIS(code,lives, make_pair(entry.first-1,entry.second),true)) return true;
        }
        if(mz[entry.first +1][entry.second] == 's' && (entry.first +1)<=col){
            code = "right";  lives--;
            cout<<"found s"<<endl;
            if(checkTHIS(code,lives, make_pair(entry.first+1,entry.second),true)) return true;
        }
        if(mz[entry.first][entry.second -1] == 's' && (entry.second -1)>0){
            code = "up"; lives--;
            cout<<"found s"<<endl;
            if(checkTHIS(code,lives, make_pair(entry.first,entry.second-1),true)) return true;
        }
        if(mz[entry.first][entry.second +1] == '@' && (entry.second +1)<=row){
            code = "down";  
            cout<<"found @"<<endl;
            return true;
        }
        if(mz[entry.first -1][entry.second] == '@' && (entry.first -1)>0){
            code = "left";  
            cout<<"found @"<<endl;
            return true;
        }
        if(mz[entry.first +1][entry.second] == '@' && (entry.first +1)<=col){
            code = "right";  
            cout<<"found @"<<endl;
            return true;
        }
        if(mz[entry.first][entry.second -1] == '@' && (entry.second -1)>0){
            code = "up"; 
            cout<<"found @"<<endl;
            return true;
        }

    }
    if(code == "none"){
        if(entry.first == 1){
            cout<<"right"<<endl;
            checkTHIS("right",lives, entry,false);
        }
        if(entry.first == col){
            cout<<"left"<<endl;
            checkTHIS("left",lives, entry,false);
        }   
        if(entry.second == 1){
          cout<<"down"<<endl;
          checkTHIS("down",lives, entry,false);
        }
        if(entry.second == row){
           cout<<"up"<<endl;
           checkTHIS("up",lives, entry,false);
        }
    }

    return false;
    
}





int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int lives;
    char car;

    cin>>row>>col>>lives;
    vector<pair<int,int>> ip;
    bool poss = false;

    for (int m = 1; m <= row; m++)
    {
        for (int j = 1; j <= col; j++)
        {
            cin>>car;
            mz[m][j] = car;
            if(car == '@') ip.push_back(make_pair(j,m));
        }
    }  

    for (int m = 1; m <= row; m++)
    {
        for (int j = 1; j <= col; j++)
        {
            cout<<mz[m][j];
        }
        cout<<endl;
    }  



    for (auto &&x : ip)
    {
        cout<<"POINT: "<<x.first<<" "<<x.second<<endl;
        if(checkTHIS("none",lives,x,false)){
            poss = true;
            //break;
        }
    }
    
    if(poss) cout<<"POSSIBLE"<<endl;
    else cout<<"IMPOSSIBLE"<<endl;

    return 0;   
}
