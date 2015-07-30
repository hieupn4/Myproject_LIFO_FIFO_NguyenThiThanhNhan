#include<stdio.h>
#include<conio.h>
#include<iostream>
#include<fstream>
#include<stdlib.h>
int k=0; // lưu số phần tử có trong danh sách LIFO
int demdc =0; // lưu số phần tử của danh sách FIFO
struct node
{
	int so;
	struct node *next;
};
// hàm đọc tệp các số nguyên ra một danh sách LIFO được trỏ bởi con trỏ first
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
// hàm kiểm tra một số có phải là dương và chẵn hay không 
int kiemTraDuongChan(int x)
{
   if((x>0)&&((x%2)==0))
   return 1;
   else
   return 0;
}
// hàm đọc từ danh sách LIFO first thành một danh sách FIFO bao gồm các số dương và chẵn
struct node *doctepFIFO(struct node *first)
{
    // con trỏ này để trỏ đến danh sách FIFO, nó đến phần tử đầu tiên
    struct node *second=NULL;
    // biến dem nay để xác định nút đầu tiên trong danh sách FIFO
    int dem =0;
    // con trỏ này dùng để khởi tạo các nút khi có nút mới thêm vào
    struct node *tam;
    // con trỏ này sẽ luôn trỏ vào nút thêm vào mới nhất
    struct node *luutru;
    // thao tác đưa từng phần tử từ LIFO vào danh sách FIFO
    for(int i=0;i<k;i++)
    {
    	// thao tác duyệt danh sách
		int n = first->so;
		first=(first->next);
	//nếu đúng là dương và chẵn thì mới đưa vào FIFO
        if(kiemTraDuongChan(n)==1)
        {
            // cấp phát bộ nhớ cho con trỏ khi có nút mới thêm vào
            tam = ( struct node*)malloc(1*sizeof(struct node));
            // set giá trị cho nút mới thêm vào
            tam->so = n;
            std::cout <<"...."<<n;
            demdc ++;
            // nếu là phần tử đầu tiên thì cả hai con trỏ second và luutru sẽ cùng trỏ vào nó
            if(dem==0)
            {
               //con trỏ second luôn trỏ vào phần tử đầu tiên của danh sách FIFO
               second = tam;
               luutru = tam;
            }
            else
            {
            	      // con trỏ lưu trữ thì luôn trỏ đến nút thêm vào danh sách FIFO mới nhất
		      luutru->next = tam;
            }
           dem++;
        }
    }
	return second;
}
// hàm hiện thị danh sách
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
