//algo-code from geeks4geeks
#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<unordered_set>
#include<cmath>
#include<cstring>

using namespace std; 

  
long int UnboundedKnapsack(long int W,long int n, long int weight[],long int val[]){
        long int dp[W+1];
        for(int i=0;i < W+1;i++){
            dp[i]=0;                            
        }
        for(int i=0;i < W+1;i++){
            for(int j=0;j < n;j++){
                if(weight[j] < i){
                    dp[i] = max(dp[i], dp[i-weight[j]] + val[j]);   
                }
            }
        }
        return dp[W];
    }
    int main(){
        //  The no. of items : 
        long int n = 4;
        //  Weights of all the items : 
        long int wt[4] = {20,30,40,60};
        //  Enter values of all the items : 
        long int val[4] = {2,4,5,6};
        // Enter the knapsack capacity : 
        long int Capacity = 100;
        cout << UnboundedKnapsack(Capacity,n,wt,val)<<endl;;
        return 0;
    }
