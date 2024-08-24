#include <iostream>
using namespace std;

 int main()
 {
    int i,j,k,n,m,z,arr[100][100];
    cout<<"types of matrices and sparse matrice programs!\n";
    cout<<"enter the number of rows!\n";
    cin>>n;
    cout<<"enter the number columns!\n";
    cin>>m;
    cout<<"enter the elements of the matrix!\n";
    for(i=0;i<=n-1;i++)
    {
        for(j=0;j<=m-1;j++)
        {
            cin>>arr[i][j];
        }
    }
    cout<<"the given matrix is!:\n";
      for(i=0;i<=n-1;i++)
    {
        for(j=0;j<=m-1;j++)
        {
            cout<<arr[i][j];
        }
        cout<<"\n";
    }
    while(k!=0)
    { int  h=0,arr1[100];
	
      cout<<"enter the type of matrix!\n";
      cout<<"enter 1 for upper diagonal matrix\n";
      cout<<"enter 2 for lower diagonal matrix\n";
      cout<<"enter 3 for the diagonal matrix\n";
      cout<<"enter 4 for the tri diagonal matrix\n";
      cout<<"enter 5 for row major and 6 for column major!\n";
      cin>>z;
     if(z==1)
      {
        for(i=0;i<=n-1;i++)
    {
        for(j=0;j<=m-1;j++)
        {
           if(i<=j)
           {arr1[h]=arr[i][j];
            h++;
		   }
        }

    }
      }
     
    else if(z==2)
     {
     for(i=0;i<=n-1;i++)
    {
        for(j=0;j<=m-1;j++)
        {
           if(i>=j)
            {arr1[h]=arr[i][j];
            h++;
			 } 
        }
    }

     } 
    if(z==3)
     {
     for(i=0;i<=n-1;i++)
    {
        for(j=0;j<=m-1;j++)
        {
           if(i==j)
          {arr1[h]=arr[i][j];
            h++;
		   } 
        }
    }
     }

     else if(z==4)
     {
     for(i=0;i<=n-1;i++)
    {
        for(j=0;j<=m-1;j++)
        {
           if(i==j || j==i+1 || i==j+1)
    
            {arr1[h]=arr[i][j];
            h++;
			 } 
        }
    }
     }  
      else if(z==5)
      {
     for(i=0;i<=n-1;i++)
      {
        for(j=0;j<=m-1;j++)
        {
           cout<<arr[i][j];
        }
      }

    }
    else if(z==6)
      {
     for(i=0;i<=n-1;i++)
      {
        for(j=0;j<=m-1;j++)
        {
           cout<<arr[j][i];
        }
      }

    }
    

       cout<<"\n the matrix in 1d is !\n";

    for(i=0;i<=h-1;i++)
    {
        cout<<arr1[i]<<" ";
    }
   cout<<"\n enter 0 to contnue the program or 1 to exit!:\n";
  cin>>k;
}
    
  cout<<"\n thanks for using my program!";
 }
 
