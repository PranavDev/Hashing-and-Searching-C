# include<stdio.h>
# include<conio.h>
void Linear_Probing(int Ht[],int key);                     //For Loading.
void Linear_Prob_Searching(int Ht[],int key);              //For Searching.

int main()
{
    int Ht[10] = {NULL},key,n,k;
    printf("Enter the total no. of elements : ");
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        printf("Enter the Key No. %d to be entered in the HashTable : ",i+1);
        scanf("%d",&key);
        Linear_Probing(Ht,key);
    }
    printf("\n");
    printf("Enter a Key Element to be Searched : ");
    scanf("%d",&k);
    Linear_Prob_Searching(Ht,k);
    printf("\n");
    return 0;
}


void Linear_Probing(int Ht[],int key)
{
    int index,i;
    index = key % 10;
    if(Ht[index] == '\0')
    {
        Ht[index] = key;
    }
    else
    {
        i = index + 1;
        while(i!=index)
            {
                if(Ht[i] == '\0')
                {
                    Ht[i] = key;
                    break;
                }
                i = (i + 1) % 10;
            }
    }
}


void Linear_Prob_Searching(int Ht[],int k)
{
    int i,index;
    index = k % 10;
    if(Ht[index] == k)
    {
        printf("The key element %d is found at position %d.",k,index);
    }
    else
    {
        i = index + 1;
        while(i!=index)
        {
            if(Ht[i] == k)
            {
                printf("The key element %d is found at position %d.",k,i);
                break;
            }
            i = (i + 1) % 10;
            if(i == index)
                {
                    printf("Key Element not found.");
                }
        }
    }
}

