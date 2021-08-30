#include<iostream>
#include<vector>
#include<map>
#include<cmath>
using namespace std;

//the basic sieve is called by primesinRange function.
//for a given max integer, finds prime form 2 to the decided integer 
//sieve finds integers in an opposite of the conventional way, instead of marking an integer as prime, 
    //it marks all multiples of known primes as non primes in the given range 
//simple sive taskes as input, max integer named "limit" to find primes below it and a refernece to the vector "prime" that contains the primes 
void simpleSieve(int limit, vector<int>& prime) 
{ 
    vector<bool> mark(limit+1,false);
    //vector of type boolean is created with all values as false, in this case, when traversal begins, if an integer is flase, it is prime.
    for (int i = 2; i <= limit; ++i) { 
        //loop id started from two so as to avoid poistions 0 and 1 as they can never be primes or no primes.
        if (mark[i] == false) { 
            prime.push_back(i); 
            //as soon as a prime is found, it is added to the refernce vector passed at the beginning 
            for (int j = i; j <= limit; j += i) 
                mark[j] = true; 
                //all multiples of the prime that was found are marked as not prime ie., true in this case. 
        } 
    } 
}
  
 //primesinRange fuction is called from the main function.
 //this function is what adds the segmented part to the normal sieve. the simple sieve function is called from here. 
 //it takes as input 2 integers, which has the range of the in which primes are to be found
void primesInRange(int low, int high) 
{ 
    int limit = floor(sqrt(high)) + 1; 
    vector<int> prime; 
    simpleSieve(limit, prime); 
    //the floor of the square root of the high number +1 is taken along wit a integer vector. These two are sent to the simpleseive meathod 
    //calling this function updates the prime vector with primes till the limit integer
  
    int n = high - low + 1; 
    vector<bool> mark(n+1,false);
    //new integer is calculated to figure out the size of range in which primes are yet to be found 
    //vector of boolean is created with range size and all indexes are marked false. false in this case means prime.  

    for (int i = 0; i < prime.size(); i++) { 
        int loLim = floor(low / prime[i]) * prime[i];
        //in the loop the known prime numbers are iterated to find the rest of the non primes in the list 
        //new int is created so that it is the smallest multiple of prime in the given range 
        if (loLim < low)    
            loLim += prime[i]; 
        if(loLim==prime[i]) 
            loLim += prime[i]; 
            //the above two cases take care of the cases if in case the int is below the given range or is the prime number i itself 
        for (int j = loLim; j <= high; j += prime[i]) 
            mark[j - low] = true; 
            //the loop is started from the lowest multiple to high end of range and is iterated in multiples of the prime i
            //position [j-low] in mark is put to true. j- low as vector mark does not contain the entire range of primes. true here is non prime.
    } 

    //mark is used in the given range to print the primes 
    for (int i = low; i <= high; i++) 
        if (!mark[i - low]) 
            cout << i << "\n";
            //if the position in mark is not true i.e., false. it is a prime and is printed.
            //new line is used to format the output as per requirnments 
}

//main function that calls the primesinRnage function.
//takes care of the input from the user ie., the range to find primes in 
int main() 
{ 
    int count;
    vector<int> ip(2);
    map<int, vector<int>> target;
    
    //count is used to input the amount of ranges that will be input from the user. 
    cin>>count;

    //vector is created to take multiple inputs from one line. this vector is then saved in a map. 
    for (int j = 0; j < count; j++)
    {
        for (int i = 0; i < 2; i++){                                         
            cin>>ip[i];
            if (ip[i]==1 || ip[i]==0)
                ip[i]=2;
        }
        target[j] = ip;
    }

    //loop is called to iterate map of inputs. 
    //primesinRange function is called for each range and new line is used to format the output as per requirnments 
    for(int z = 0; z<count; z++){
        primesInRange(target[z][0],target[z][1]);
        cout<<"\n";
    }
    return 0; 
} 






//https://stackoverflow.com/questions/26201489/how-does-segmentation-improve-the-running-time-of-sieve-of-eratosthenes
//https://www.geeksforgeeks.org/how-is-the-time-complexity-of-sieve-of-eratosthenes-is-nloglogn/?ref=leftbar-rightbar
//https://www.geeksforgeeks.org/segmented-sieve/
//https://www.geeksforgeeks.org/sieve-of-eratosthenes/
//https://www.geeksforgeeks.org/memset-in-cpp/
//https://www.geeksforgeeks.org/initialize-a-vector-in-cpp-different-ways/
//https://www.geeksforgeeks.org/vectorpush_back-vectorpop_back-c-stl/
//https://www.geeksforgeeks.org/segmented-sieve-print-primes-in-a-range/    