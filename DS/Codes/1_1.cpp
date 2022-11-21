#include<iostream>
using namespace std;

int* insert(int *ptr, int &size, int &maxSize, int ele, int pos){
    if(pos-1>size){
        cout<<"Index OUT OF BOUND!\nInsertion Unsuccessful";
        return ptr;
    }
    if(size==maxSize){
        maxSize *= 2; 
        size++;
        int *tmp = new int[maxSize];
        for(int i=0;i<pos-1;++i)
            tmp[i]=ptr[i];
        tmp[pos-1]=ele;
        for(int i=pos;i<size;++i)
            tmp[i]=ptr[i-1];
        
        delete[] ptr;
        return tmp;
    }
    else{
        for(int i=size-1;i>=pos-1;--i)
            ptr[i+1]=ptr[i];
        ptr[pos-1] =ele;
        size++;
        return ptr;
    }
}
void del(int *ptr,int &size, int pos){
    if(size==0){
        cout<<"Array is Empty!";
        return;
    }
    if(pos>size){
        cout<<"Index OUT OF BOUND!\nDeletion Unsuccesful!";
        return;
    }
    for(int i=pos-1;i<size-1;++i)
        ptr[i]=ptr[i+1];
    ptr[size-1]=0;
    size--;
}
void display(int *ptr, int size){
    if(size==0){
        cout<<"Array is empty!";
        return; 
    }
    cout<<"Array Elements: ";
    for(int i=0;i<size;++i)
        cout<<ptr[i]<<" ";
    cout<<"\n";
}

int main(){
    cout<<"Enter size of Array: ";
    int size, maxSize;cin>>size;
    maxSize = size;
    cout<<"Enter "<<size<<" Elements: ";
    int *ptr = new int[size];
    for(int i=0;i<size;++i)
        cin>>ptr[i];
  
    bool flag = true;
    while(flag){
        std::cout<<"\n\nARRAY basic operation Menu :-\n";
        std::cout<<"1. Insert Element at some position\n2. Delete Element from some position\n3. Display all Elements of Array.\n4. Exit Program\n\n";
        std::cout<<"Your choice: ";
        std::string choice; std::cin>>choice;

        if(choice.size()>1) // for tackling when input is alphabet and strings.
            choice[0]='5'; 

        int pos,val;
        switch (choice[0])
        {
        case '1':
            std::cout<<"Position and Element, you want to Tinsert into Array: ";
            std::cin>>pos>>val;
            ptr = insert(ptr, size, maxSize, val, pos);
            break;
        case '2':
            std::cout<<"Position of Element you want to delete: ";
            std::cin>>pos;
            del(ptr, size, pos);
            break;
        case '3':
            display(ptr, size);
            break;
        case '4':
            flag = false;
            std::cout<<"Exiting.......";
            break;
        default:
            std::cout<<"Invalid Choice... try again!";
            break;
        }
        std::cout<<"\n";
        system("pause");
        std::cout << "\033[2J\033[1;1H"; //for clearing screen in terminal.
    }
    std::cout<<"Program Stopped!!";
}