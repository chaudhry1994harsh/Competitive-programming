
#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<cmath>
using namespace std;
//find min area of square created by 2 rectangles of same size

int main()
{
    int count,l,b,z=0;
    cin >> count;
    vector<int> ip;

    while(count>0){
        cin >> l >> b;
        if (l < b) {
            z = l;
            l = b;
            b = z;
        }
        if (l == b) {
            cout << pow((2 * l), 2) << "\n";
        }
        else if (2*b==l) {
            cout << l * l << "\n";
        }
        else if (l - b == b) {
            cout << b * b << "\n";
        }
        else {
            for (int i = 0; i < l+1; i++)
            {
                if(((l-i) + (2 * i))>=2*b)
                    ip.push_back(pow((l-i )+ (2 * i), 2));
            }
            sort(ip.begin(), ip.end());
            cout << ip[0]<<endl;
            ip.clear();

        }
        count--;
    }
    return 0;
}
