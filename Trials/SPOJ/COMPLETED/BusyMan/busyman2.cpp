#include<iostream>
#include<vector>
#include<set>
#include<algorithm>

using namespace std;


bool activityCompare(pair<int , int> s1, pair<int , int> s2) 
{ 
    return (s1.second < s2.second); 
} 
  

void printMaxActivities(vector <pair<int,int>> arr, int n) 
{ 
    int count = 1;
    sort(arr.begin(), arr.end(), activityCompare); 
  
    int i = 0; 
    for (int j = 1; j < n; j++) 
    { 
        if (arr[j].first >= arr[i].second) 
        { 
            count++;
            i = j; 
        } 
    } 
    cout<<count<<endl;
} 
      
int main() 
{ 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int cases,sz,a,b;

    cin>>cases;

    while(cases--){
        vector <pair<int,int>> end;
        cin>>sz;
        for (int i = 0; i < sz; i++)
        {
            cin>>a>>b;
            end.push_back(make_pair(a,b));
        }
        printMaxActivities(end,sz); 
    }

    return 0;

} 

//algo from geeks4geeks