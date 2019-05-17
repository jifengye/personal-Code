#include <iostream>  
using namespace std;  

int main()  
{    int n, m, i, ans;  
     while (cin >> n >> m)  
    {   ans = 0;  
        for (i = 2; i < n; ++i)  
            ans = (ans + m) % i;  
        cout << (n == 1 ? 1 : ans + 2) << endl;  
    }
    return 0;  
}  
          