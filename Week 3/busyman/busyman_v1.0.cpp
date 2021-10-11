#include<iostream>
#include<set>
#include<algorithm>
using namespace std;


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int count, cases,a,b, max,temp =0;
    set <pair<int,int>> target;

    cin>>count;
    while (count>0)
    {
        max = 0;
        target.clear();
        cin>>cases;
        while (cases>0)
        {
            cin>>a>>b;
            target.insert(make_pair(a,b));
            cases--;
        }

        for (auto &&x : target)
        {
            a = x.first;
            b = x.second;
            temp = 1;
            for (auto &&y : target)
            {
                if(b<=y.first){
                    temp++;
                    b=y.second;
                }
            }
            if(max<temp)
                max=temp;
        }

        cout<<max<<endl;

        count--;
    }
    


    return 0;
}

