#include <iostream>
int sorted[10];
using namespace std;

class Heap
{
    public:
    int array[10];

    int var_sort;
    int heap_size;
    Heap();
    void add_value_in_heap(int);
    void display();
    void check_condition_add(int *temp,int);
    void delete_value_in_heap();
    void display_Left_right_parent();
    void Is_heap(int *temp);
};
Heap::Heap()
{
    int a;
    for(a=0;a<10;a++)
    {
        array[a]=0;
        sorted[a]=0;
    }
        heap_size=0;
        var_sort=0;
}
void Heap::add_value_in_heap(int data)
{
        if(array[0]==0&&heap_size==0)
        {
            array[0]=data;
        }
        else
        {
            if(array[(2*heap_size)+1]==0)
            {
                array[(2*heap_size)+1]=data;
                check_condition_add(array,(2*heap_size)+1);
            }
            else
            {
                array[(2*heap_size)+2]=data;
                check_condition_add(array,(2*heap_size)+2);
                heap_size++;
            }
        }
}
void Heap::display()
{
    int a;
    for(a=0;a<10;a++)
    cout << sorted[a] << endl;
}
void Heap::check_condition_add(int *temp,int index)
{
    while(true)
    {
    if(index==0)
    {
        break;
    }
    else if(temp[(index-1)/2]<temp[index])
    {
        int var=temp[(index-1)/2];
        temp[(index-1)/2]=temp[index];
        temp[index]=var;
        index=(index-1)/2;
    }
    else
    {
         index=(index-1)/2;
    }
    }
}
void Heap::delete_value_in_heap()
{
    sorted[var_sort]=array[0];
    var_sort++;
    if(array[(2*heap_size)+1]==0)
    {
        array[0]=array[2*heap_size];
        array[2*heap_size]=0;
        heap_size--;
    }
    //If right of node is missing because it only heap size++ when right is found
    else if(array[(2*heap_size)+1]!=0)
    {
        array[0]=array[(2*heap_size)+1];
        array[(2*heap_size)+1]=0;
    }
    int a=0;
    while(true)
    {
        if(a>heap_size)
        {
            break;
        }
        else if(array[2*a+1]>array[a]&&array[2*a+1]>array[2*a+2])//check for both childs
        {
            int var=array[2*a+1];
            array[2*a+1]=array[a];
            array[a]=var;
            a++;
        }
        else if(array[2*a+2]>array[a]&&array[2*a+2]>array[2*a+1])
        {
            int var=array[2*a+2];
            array[2*a+2]=array[a];
            array[a]=var;
            a++;
        }
        else
        {
            a++;
        }
    }
}
void Heap::display_Left_right_parent()
{
    int a;
    for(a=0;a<=heap_size;a++)
    {
        cout << "Left :> " << array[2*a+1] << endl;
        cout << "right :> " << array[2*a+2] << endl;
        cout << "parent :> " << array[a] << endl;
    }
}
void Heap::Is_heap(int *temp)
{
    int a;
    for(a=0;a<2;a++)
    {
        if(temp[a]==0)
        {
            cout << "It is not heap\n";
            break;
        }
        if(temp[2*a+1]>temp[a]||temp[2*a+2]>temp[a])
        {
            cout << "It is not heap\n";
            break;
        }
    }
    if(a==2)
    {
        cout << "It is heap\n";
    }
}
int main()
{
    Heap object;
    object.add_value_in_heap(20);
    object.add_value_in_heap(10);
    object.add_value_in_heap(30);
    object.add_value_in_heap(40);
    object.add_value_in_heap(50);
    object.add_value_in_heap(4);
    object.add_value_in_heap(2);
    object.add_value_in_heap(900);
    object.add_value_in_heap(19);
    object.add_value_in_heap(2000);
    object.display();
    cout << "Now delete function is working\n";
    object.delete_value_in_heap();
    object.delete_value_in_heap();
    object.delete_value_in_heap();
    object.delete_value_in_heap();
    object.delete_value_in_heap();
    object.delete_value_in_heap();
    object.delete_value_in_heap();
    object.delete_value_in_heap();
    object.delete_value_in_heap();
    object.delete_value_in_heap();
    object.display();
    object.display_Left_right_parent();
    int array[5]={10,3,5,2,1};
    object.Is_heap(array);
}
