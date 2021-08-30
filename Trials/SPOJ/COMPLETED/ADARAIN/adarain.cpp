//has been solved using diffarray 

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
        }
        else{
            A[i] = D[i] + A[i - 1];

        }
        temp.push_back(A[i]); 

    } 

} 

int main() 
{ 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int sz,req,pp,a,b,c;

    cin>>req>>pp>>sz;

    vector<int> A(sz,0) ;
    vector<int> targ = initializeDiffArray(A); 

    while (req--)
    {
        cin>>a>>b;
        update(targ,a,b,1);
    }

    printSPOT(A,targ);

    while (pp--)
    {
        cin>>a;
        cout<<temp[a]<<endl;
    }
    

    return 0;

} 

//algo from geeks4geeks