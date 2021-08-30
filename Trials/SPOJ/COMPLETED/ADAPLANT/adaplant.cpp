#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
#include<set>

using namespace std;


multiset<long long> lst;
vector<long long> tp;


void printS(){
    for (auto &&x : lst)
    {
        cout<<x<<" ";
    }
    cout<<endl;
}



long long sendIT(long long gap, long long sz){
    long long first, max, temp;

    if(gap+2>=sz){
        for (auto &&x : tp)
        {
            lst.insert(x);
        }
        max= abs( (*lst.rbegin()) - (*lst.begin()) );
        return max;
    }


    for (long long i = 0; i < gap+2; i++)
    {
        lst.insert(tp[i]);
    }
    first = tp[0];
    max = abs( (*lst.rbegin()) - (*lst.begin()) );
    
    //printS();
    //cout<<"init done"<<endl;

    for (long long i = 1; i < tp.size(); i++)
    {
        if(i+gap+1 < tp.size()){
            std::multiset<long long>::iterator hit(lst.find(tp[i-1]));
            if (hit!= lst.end()) lst.erase(hit);

            //lst.erase(tp[i-1]);
            lst.insert(tp[i+gap+1]);
            temp = abs( (*lst.rbegin()) - (*lst.begin()) );
            if(max < temp)
                max = temp;
        }
        else{
            temp = abs( (*lst.rbegin()) - (*lst.begin()) );
            if(max < temp)
                max = temp;
            return max;
        }
        //printS();
    }
    return max;
}


int main() 
{ 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long cases, sz, gap;

    cin>>cases;

    while(cases--){
        cin>>sz>>gap;
        long long temp;
        tp.clear();
        lst.clear();

        for (long long i = 0; i < sz; i++)
        {
            cin>>temp;
            tp.push_back(temp);
        }
        
        cout<<sendIT(gap,sz)<<endl;

    }



    return 0;

} 
