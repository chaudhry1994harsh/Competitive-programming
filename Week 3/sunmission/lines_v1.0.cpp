#include<iostream>
#include<unordered_set>
#include<vector>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int count;
    double x,y;
    unordered_set<double> target; 
    vector<pair<double,double>> temp;

    cin>>count;

    do
    {
        target.clear();
        temp.clear();
        while (count>0)
        {
            cin>>x>>y; 

            for (auto &&c : temp)
            {
                /*if(c.first - x == 0 || c.first - x == -0){
                    target.insert(1000);
                }
                else{
                    double m = (c.second - y)/(c.first - x);
                        target.insert(m);
                }
                */

                if(c.first - x !=0){
                    double m = (c.second - y)/(c.first - x);
                    target.insert(m);
                }
                else {
                    target.insert(2000);
                }
            }
            
            temp.push_back(make_pair(x,y));
            count --;
        }
        

        cout<<target.size()<<endl;
        cin>>count;

    } while (count != 0);
    

    return 0;
}
