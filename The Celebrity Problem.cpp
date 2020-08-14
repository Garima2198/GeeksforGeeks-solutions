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
int getId(int M[MAX][MAX], int n)
{
    //Your code here
    
    for(int i = 0; i < n; i++)
    {
        bool flag=true;
        for(int j=0;j<n;j++)
        {
            if(M[i][j]!=0)
            {
                flag=false;
                break;
            }
        }
        if(flag==true)  //can be -1 or can be i
        {
            for(int j = 0;j < n; j++)
            {
                 if(M[j][i]! = 1 && i! = j)
                  return -1;
            }
            return i;
        }
        
    }
    return -1;
        
}
