//has been solved using diffarray from geeks4geeks

#include<iostream>
#include<vector>
#include<set>
#include<algorithm>

using namespace std;


vector<int> temp;

vector<int> initializeDiffArray(vector<int>& A) 
{ 
    int n = A.size(); 
    vector<int> D(n + 1); 
  
    D[0] = A[0], D[n] = 0; 
    for (int i = 1; i < n; i++) 
        D[i] = A[i] - A[i - 1]; 
    return D; 
} 
  

void update(vector<int>& D, int l, int r, int x) 
{ 
    D[l] += x; 
    D[r + 1] -= x; 
} 

void printSPOT(vector<int>& A, vector<int>& D) 
{ 
    temp.clear();
    for (int i = 0; i < A.size(); i++) { 
        if (i == 0) {
            A[i] = D[i];
            //temp.push_back(A[i]); 
        }
        else{
            A[i] = D[i] + A[i - 1];
            //temp.push_back(A[i]); 
        }
        temp.push_back(A[i]); 
        /*if(i == loc)
            cout << A[i] << endl;*/ 
    } 
    //cout << endl; 
} 

int main() 
{ 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int cases,sz,req,pp,a,b,c;

    cin>>cases;

    while(cases--){
        cin>>sz>>req;
        vector<int> A(sz,0) ;
        /*for (auto &&x : A)
        {
            cout<<x<<" ";
        }
        cin>>a;*/
        

        vector<int> targ = initializeDiffArray(A); 
        for (int i = 0; i < req; i++)
        {
            cin>>a>>b>>c;
            update(targ,a,b,c);
        }
        cin>>pp;
        printSPOT(A,targ);
        for (int i = 0; i < pp; i++)
        {
            cin>>a;
            cout<<temp[a]<<endl;
        }
    }

    return 0;

} 

//algo from geeks4geeks

