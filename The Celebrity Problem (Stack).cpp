#include<bits/stdc++.h>
using namespace std;
#define MAX 501

int getId(int M[MAX][MAX],int n);

int main()
{
    int T;
    cin>>T;
    int M[MAX][MAX];
    while(T--)
    {
        int N;
        cin>>N;
        memset(M,0,sizeof M);
        for(int i=0;i<N;i++)
        {
            for(int j=0;j<N;j++)
            {
                cin>>M[i][j];
            }
        }
        cout<<getId(M,N)<<endl;

    }
}

// } Driver Code Ends


// The task is to complete this function

// M[][]: input matrix
// n: size of matrix (n*n)
bool knows(int a, int b, int M[MAX][MAX])
{
    return M[a][b];
}

int getId(int M[MAX][MAX], int n)
{
    //Your code here

    stack<int> s;

    int c;

    for (int i = 0; i < n; i++)
        s.push(i);

    int a = s.top();
    s.pop();
    int b = s.top();
    s.pop();

    if(s.size()==0)
    {
        if(knows(a, b, M) && !knows(b, a, M))
            return b;
        else if(knows(b, a, M) && !knows(a, b, M))
            return a;
        else
            return -1;
    }

    while (s.size() > 1)
    {
        if (knows(a, b, M))
        {
            a = s.top();
            s.pop();
        }
        else
        {
            b = s.top();
            s.pop();
        }
    }

    c = s.top();
    s.pop();

    if (knows(c, b, M))
        c = b;

    if (knows(c, a, M))
        c = a;

    for (int i = 0; i < n; i++)
    {
        if ( (i != c) &&
                (knows(c, i, M) ||
                 !knows(i, c, M)) )
            return -1;
    }

    return c;
}
