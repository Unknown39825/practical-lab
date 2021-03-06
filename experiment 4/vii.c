#include<stdio.h>
#include<stdlib.h>
//z matrix with non zero value in first row , RIGHT DIAGONAL and last row

struct Matrix
{

    int *A;
    int n;
};
typedef struct Matrix Matrix;

void inputRMO(struct Matrix *l )
{
    int i,j,m;

    int val;
    printf("Enter the input in normal form: \n");
    for(i=1;i<=l->n;i++)
    {
        for(j=1;j<=l->n;j++)
        {
            scanf("%d",&val);
            if(i==1)
                l->A[j-1]=val;
            else if(i==l->n)
                l->A[(2*l->n)-2 +j-1]=val;
            else if(i+j==l->n+1)
                l->A[l->n +i-2]=val;



        }

    }
}
void inputCMO(struct Matrix *l )
{
    int i,j,m;
    int n=3*l->n-2;
    int val;
    printf("Enter the input in normal form: \n");
    for(i=1;i<=l->n;i++)
    {
        for(j=1;j<=l->n;j++)
        {
            scanf("%d",&val);
            if(i==1&&j==1)
                {
                    l->A[0]=val;

                }
            else if(i==l->n&&j==1)
                {
                    l->A[1]=val;

                }
            else if(i==1&&j==l->n)
                {
                    l->A[n-2]=val;

                }
            else if(i==l->n&&j==l->n)
                {
                    l->A[n-1]=val;

                }
            else if(i==1||i==l->n||i+j==l->n+1)
            {

                if(i==1)
                    l->A[2+3*(j-2)]=val;
                else if(i==l->n)
                    l->A[2+3*(j-2)+2]=val;
                else if(i+j==l->n+1)
                    l->A[2+3*(j-2)+1]=val;
            }


        }

    }
}




void displayRMO(struct Matrix m)
{

    int i,j;


    for(i=1;i<=m.n;i++)
    {
        for(j=1;j<=m.n;j++)
        {
            if(i==1)
                printf("%d  ",m.A[j-1]);
            else if(i==m.n)
                printf("%d  ",m.A[(2*m.n)-2 +j-1]);
            else if(i+j==m.n+1)
                printf("%d  ",m.A[m.n +i-2]);
            else
                printf("0  ");
        }
        printf("\n");
    }
}

void displayCMO(struct Matrix m)
{

    int i,j;
    int n=3*m.n-2;

    for(i=1;i<=m.n;i++)
    {
        for(j=1;j<=m.n;j++)
        {
            if(i==1&&j==1)
                printf("%d  ",m.A[0]);
            else if(i==m.n&&j==1)
                printf("%d  ",m.A[1]);
            else if(i==1&&j==m.n)
                printf("%d  ",m.A[n-2]);
            else if(i==m.n&&j==m.n)
                printf("%d  ",m.A[n-1]);

            else if(i==1||i==m.n||i+j==m.n+1)
            {
                if(i==1)
                printf("%d  ",m.A[2+3*(j-2)]);

                else if(i==m.n)
                printf("%d  ",m.A[2+3*(j-2)+2]);

                else if(i+j==m.n+1)
                printf("%d  ",m.A[2+3*(j-2)+1]);
            }
            else
                printf("0  ");
        }
        printf("\n");
    }
}


int main()
{
    printf("Z MATRIX\n");
    struct Matrix m;
    printf("enter the value of n ie. size of matrix: ");
    scanf("%d",&m.n);
    m.A=malloc(sizeof(int)*(3*m.n-2));

    int choice;

    printf("Enter 1 for rmo form 2 for cmo form");
    scanf("%d",&choice);
    if(choice==1)
    {
        printf("\n RMO\n");
        inputRMO(&m);
        displayRMO(m);
        printf("\n\n the RMO form of the following matrix is : \n ");
        int i;
        for(i=0;i<(3*m.n-2);i++)
            printf("%d ",m.A[i]);
    }
    if(choice==2)
    {
        printf("\n CMO\n");
        inputCMO(&m);
        displayCMO(m);
        printf("\n\n the CMO form of the following matrix is : \n ");
        int i;
        for(i=0;i<(3*m.n-2);i++)
            printf("%d ",m.A[i]);
    }




}
