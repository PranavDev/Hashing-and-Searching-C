# include<stdio.h>
void Chaining_Linear_Probing(struct HashTable Ht[],int key);
void Searching(struct HashTable Ht[],int key);

struct HashTable
    {
        int key;
        int index;
    }Ht[10];


int main()
{
    int N;
    printf("Enter the No. of Elements : ");
    scanf("%d",&N);

    Ht[10] = {NULL};
    int k,key,index,Search;

    printf("Enter the Elements To be placed in the HashTable:\n");
    for(int i=0;i<N;i++)
    {
        printf("Enter Element %d : ",i+1);
        scanf("%d",&k);
        Chaining_Linear_Probing(Ht,k);
    }
    printf("\n");

    printf("The HashTable is : \n");
    for(int i=0;i<N;i++)
    {
        printf("%d ",Ht[i]);
    }
    printf("\n");
    printf("Enter An Element to be Searched : ");
    scanf("%d",&Search);
    printf("\n");
    Searching(Ht,Search);
    /*int i=0,count;
    while(i<N)
    {
        count[Ht[i].index]=0;
        while(count[Ht[i].index]<=0)
        {
            printf("%d ",Ht[i]);
            if(Ht[i].index == '\0')
            {
                i++;
                continue;
            }
            else
            {
                printf("%d",Ht[index].key);
                count[Ht[i].index]++;
                i++;
            }
        }
    }*/
    return 0;
}

void Chaining_Linear_Probing(struct HashTable Ht[],int key)
{
    int i,index;
    index = key % 10;
    if(Ht[index].key == '\0')
    {
        Ht[index].key = key;
    }
    else
    {
        i = index + 1;
        while(i!=index)
        {
            if(Ht[i].key == '\0')
            {
                Ht[i].key = key;
                break;
            }
            i = (i+1)%10;
        }
    }
    if(i!=index)
    {
        while(Ht[index].index == '\0')
        {
            Ht[index].index = i;
        }
        index = Ht[index].index;
    }
    else
    {
        printf("The HashTable is full!!");
    }
}

void Searching(struct HashTable Ht[],int key)
{
    int i,index;
    index = key % 10;
    if(Ht[index].key == key)
    {
        printf("Element %d Found at Index %d",key,index+1);
    }
    else
    {
        i = index + 1;
        while(i!=index)
        {
            if(Ht[i].key == key)
            {
                printf("Element %d Found at Index %d",key,i+1);
                break;
            }
            i = ( i + 1 ) % 10;
            if(i==index)
            {
                printf("Element Not Found");
            }
        }
    }
}
