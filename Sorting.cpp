#include <iostream>

using namespace std;
void insert(int *ptr,int size)
{
 int a;
 for(a=size;a>0;a--)
 {
   if(ptr[a]<ptr[a-1])
   {
       int temp=ptr[a];
       ptr[a]=ptr[a-1];
       ptr[a-1]=temp;
   }
 }
}
void display(int *ptr,int size)
{
    int a;
    for(a=0;a<size;a++)
    {
        cout << ptr[a] << endl;
    }
}
void moveMin(int *ptr,int size,int doh)
{
   int a,min=ptr[doh],index=doh;
 for(a=doh;a<size;a++)
 {
   if(ptr[a+1]<min)
   {
       min=ptr[a+1];
       index=a+1;
   }
 }
 int temp=ptr[doh];
 ptr[doh]=min;
 ptr[index]=temp;
}
void insertion_sort(int *ptr,int size)
{
    int a;
    for(a=0;a<=size;a++)
    {
        insert(ptr,a);
    }
}
void selection_sort(int *ptr,int size)
{
    int a,b=size;
    for(a=0;a<size;a++)
    {
        moveMin(ptr,b,a);
    }
}
void merge(int *ptr1,int *ptr2,int *ptr3,int size1_2,int size3)
{
 int pointer1=0,pointer2=0;
 int a;
 for(a=0;a<size3;a++)
 {
     if(ptr2[pointer2]<ptr1[pointer1]&&pointer2<7)
     {
        ptr3[a]=ptr2[pointer2];
        pointer2++;
     }
     else if(ptr2[pointer2]>ptr1[pointer1]&&pointer1<7)
     {
        ptr3[a]=ptr1[pointer1];
        pointer1++;
     }
     else if(pointer1<7&&pointer2>=7)
     {
        ptr3[a]=ptr1[pointer1];
        pointer1++;
     }
     else if(pointer1>=7&&pointer2<7)
     {
        ptr3[a]=ptr2[pointer2];
        pointer2++;
     }
 }
}
void merge(int *array, int l, int m, int r) {
   int i, j, k, nl, nr;
   //size of left and right sub-arrays
   nl = m-l+1; nr = r-m;
   int larr[nl], rarr[nr];
   //fill left and right sub-arrays
   for(i = 0; i<nl; i++)
      larr[i] = array[l+i];
   for(j = 0; j<nr; j++)
      rarr[j] = array[m+1+j];
   i = 0; j = 0; k = l;
   //marge temp arrays to real array
   while(i < nl && j<nr) {
      if(larr[i] <= rarr[j]) {
         array[k] = larr[i];
         i++;
      }else{
         array[k] = rarr[j];
         j++;
      }
      k++;
   }
   while(i<nl) {       //extra element in left array
      array[k] = larr[i];
      i++; k++;
   }
   while(j<nr) {     //extra element in right array
      array[k] = rarr[j];
      j++; k++;
   }
}
void mergeSort(int *array, int l, int r) {
   int m;
   if(l < r) {
      int m = l+(r-l)/2;
      // Sort first and second arrays
      mergeSort(array, l, m);
      mergeSort(array, m+1, r);
      merge(array, l, m, r);
   }
}
int main()
{
    int array[7]={2,4,6,8,10,12,114};
    int array2[7]={1,3,5,7,9,11,50};
    int array3[14];
    int array4[10]={6,3,8,9,2,5,4,7,1,10};
   //insert(array,6);
   // moveMin(array,7);
   // insertion_sort(array,6);
   // selection_sort(array,7);
    merge(array,array2,array3,7,14);
    mergeSort(array4,0,9);
    display(array4,10);
    return 0;
}
