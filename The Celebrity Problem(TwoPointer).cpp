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
    
    int a=0;
    int b=n-1;
    
    while(a<b)
    {
        if(knows(a,b, M))
            a++;
        else
            b--;
    }
    
    int c=a;
    
    for(int i=0;i<n;i++)
    {
        if((c!=i) && (knows(c,i, M) || !knows(i,c, M)))
            return -1;
    }
    return c;
    
}
