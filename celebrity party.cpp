#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include<stack>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
       int n;
    cin>>n;
    int m;
    cin>>m;
    if(m==0)
    {
        cout<<-1;
        return 0;
    }
    bool matrix[n][n]={0};
    for(int i=0;i<m;i++)
    {
        int a;
        int b;
        cin>>a;
        cin>>b;
        matrix[a][b]=1;
    }
stack<int> s;

    int C; // Celebrity

    // Push everybody to stack
    for (int i = 0; i < n; i++)
        s.push(i);

    // Extract top 2
    int A = s.top();
    s.pop();
    int B = s.top();
    s.pop();

    // Find a potential celevrity
    while (s.size() > 1)
    {
        if (matrix[A][B])
        {
            A = s.top();
            s.pop();
        }
        else
        {
            B = s.top();
            s.pop();
        }
    }

    // Potential candidate C
    C = s.top();
    s.pop();

    if (matrix[A][B])
        C = B;

    if (matrix[C][A])
        C = A;


    for (int i = 0; i < n; i++)
    {

        if ( (i != C) && (matrix[C][i] || !matrix[i][C]))
                 {

                    cout<<-1;
                    return 0;
                 }
    }

    cout<<C;
    return 0;
}
