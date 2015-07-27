#include<stdio.h>
#include<conio.h>
#include<iostream>
#include<fstream>
#include<stdlib.h>
int k=0;
int demdc =0;
struct node
{
	int so;
	struct node *next;
};
struct node *doctepLIFO(struct node *first)
{
    int *sn;
    int output;
    int n;
    struct node *tam;
    std::ifstream myFile("D:\\lifo.txt",std::ios::in);
    std::ifstream myFile2("D:\\lifo.txt",std::ios::in);
    if(!myFile)
    {
         std::cout<<" khong the mo duoc tep tin ";
    }
    else
    {
       std::cout<<" mo thanh cong tap tin "<<"\n";
       while (myFile >> output) // kiem tra so so nguyen co trong tep
            k++;
       myFile.close();
       if(k==0)
        std::cout<<"\n"<<" chang co gia tri nao trong tep ca ";
       else
       {
           for(int i=0;i<k;i++)
            {
              myFile2 >> n; // doc ky tu tu tep tin
              std::cout <<n<<"    ";
              tam = ( struct node*)malloc(1*sizeof(struct node));
		      tam->so = n;
		      tam->next = first;
		      first = tam;
            }
       }
    }
	return first;
}
int kiemTraDuongChan(int x)
{
   if((x>0)&&((x%2)==0))
   return 1;
   else
   return 0;
}
struct node *doctepFIFO(struct node *first)
{
    struct node *second=NULL;
	int dem =0;
    struct node *tam;
    struct node *luutru;
    for(int i=0;i<k;i++)
    {
		int n = first->so;
		first=(first->next);
        if(kiemTraDuongChan(n)==1)
        {
            tam = ( struct node*)malloc(1*sizeof(struct node));
            tam->so = n;
            std::cout <<"...."<<n;
            demdc ++;
            if(dem==0)
            {
               second = tam;
               luutru = tam;
            }
            else
            {
		      second->next = tam;
            }
           dem++;
        }
    }
	return second;
}

void xem(struct node *first)
{
	struct node *tam= first;
	printf("Danh Sach : ");
	while(tam != NULL)
	{
		printf("%d  ",tam->so);
		tam = tam->next;
	}
}

int main()
{
    struct node *first = NULL;
	first = doctepLIFO(first);
	printf("danh sach LIFO");
	xem(first);
    struct node *second1 = NULL;
    printf("danh sach FIFO");
	second1 = doctepFIFO(first);
    system("pause");
    
}
