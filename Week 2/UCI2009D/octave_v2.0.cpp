#include<iostream>
#include<vector>
#include<map>
#include<queue> 
#include<algorithm>
using namespace std;

struct Node 
{ 
    int key; 
    vector<Node *>child; 
}; 
   
 // Utility function to create a new tree node 
Node *newNode(int key) 
{ 
    Node *temp = new Node; 
    temp->key = key; 
    return temp; 
} 
  
// Prints the n-ary tree level wise 
void LevelOrderTraversal(Node * root) 
{ 
    if (root==NULL) 
        return; 
   
    // Standard level order traversal code 
    // using queue 
    queue<Node *> q;  // Create a queue 
    q.push(root); // Enqueue root  
    while (!q.empty()) 
    { 
        int n = q.size(); 
  
        // If this node has children 
        while (n > 0) 
        { 
            // Dequeue an item from queue and print it 
            Node * p = q.front(); 
            q.pop(); 
            cout << p->key << " "; 
   
            // Enqueue all children of the dequeued item 
            for (int i=0; i<p->child.size(); i++) 
                q.push(p->child[i]); 
            n--; 
        } 
   
        cout << endl; // Print new line between two levels 
    } 
} 


void oct(vector<char> ip,int x, vector<int> target,bool check, Node *root){
    
    if(check == false){
        root =newNode(x);
        oct(ip, x , target, true, root);
    }
    else if((x+3<ip.size() && ip[x+3]=='#')||(ip[x+1]=='#' && (x+1)%3!=0)||(x-3>=0 && ip[x-3]=='#')||(ip[x-1]=='#' && x%3!=0)){
        if(x+3<ip.size() && ip[x+3]=='#'){
            (root->child).push_back(newNode(x+3)); 
            
        }
        if(ip[x+1]=='#' && (x+1)%3!=0){
            (root->child).push_back(newNode(x+1)); 
        }
        if(x-3>=0 && ip[x-3]=='#'){
            (root->child).push_back(newNode(x-3)); 
        }
        if(ip[x-1]=='#' && x%3!=0){
            (root->child).push_back(newNode(x-1)); 
        }
    }
}


int main(){
    int count,size = 0;
    vector<char> ip;
    vector<int> target;
   // vector<int> rev;
    char car;
    //map<int, vector<int>> octave;
    cin>> count;
    Node *root =NULL;

    for (int i = 0; i < count; i++)
    {
        cin>>size;
        for (int m = 0; m < size*3; m++)
        {
                cin>>car;
                ip.push_back(car);
        }        
        //oct(ip,ip,0,false,0,octave, target,rev);
        oct(ip,0, target,false,root);
        size = 0;
        ip.clear();
    }
    return 0;   
}