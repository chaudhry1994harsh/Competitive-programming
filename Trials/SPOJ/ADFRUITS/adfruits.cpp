#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<unordered_set>
#include<cmath>
#include<cstring>

using namespace std;




void lcs( char *X, char *Y, int m, int n ) 
{ 
   int L[201][201]; 
  
   /* Following steps build L[m+1][n+1] in bottom up fashion. Note 
      that L[i][j] contains length of LCS of X[0..i-1] and Y[0..j-1] */
   for (int i=0; i<=m; i++) 
   { 
     for (int j=0; j<=n; j++) 
     { 
        if (i == 0 || j == 0) 
            L[i][j] = 0; 
        else if (X[i-1] == Y[j-1]) 
            L[i][j] = L[i-1][j-1] + 1; 
        else
            L[i][j] = 1 + min(L[i-1][j], L[i][j-1]); 
     } 
   } 
  
   // Following code is used to print LCS 
   int index = L[m][n]; 
  
   // Create a character array to store the lcs string 
   char lcs[201]; 
   lcs[index] = '\0'; // Set the terminating character 

   string rcs;
  
   // Start from the right-most-bottom-most corner and 
   // one by one store characters in lcs[] 
   int i = m, j = n; 
   while (i > 0 && j > 0) 
   { 
        // If current character in X[] and Y are same, then 
        // current character is part of LCS 
        if (X[i-1] == Y[j-1]) 
        { 
            rcs.push_back(X[i-1]);
            lcs[index-1] = X[i-1]; // Put current character in result 
            i--; j--; index--;     // reduce values of i, j and index 
        } 
    
        // If not same, then find the larger of two and 
        // go in the direction of larger value 
        else if (L[i-1][j] > L[i][j-1]) {
            rcs.push_back(Y[j-1]);
            i--; 
        }
        else{
            rcs.push_back(X[i-1]);
            j--;
        } 
   } 
   if(i>0){
       while (i>0)
       {
           rcs.push_back(X[i-1]);
           i--;
       }
       
   }
   if(j>0){
       while (j>0)
       {
           rcs.push_back(Y[j-1]);
           j--;
       }
   }
  
   // Print the lcs 
   reverse(rcs.begin(),rcs.end());
   cout << lcs<<" "<<rcs<<endl; 
}  


int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string m,n;
    int x,y;

    while(cin>>m){
        cin>>n;

        char a[101] ,b[101];

        strcpy(a, m.c_str()); 
        strcpy(b, n.c_str()); 

        lcs(a, b, strlen(a), strlen(b)); 
    }


    return 0;
}