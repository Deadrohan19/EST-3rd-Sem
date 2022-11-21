#include<iostream>
using namespace std;

struct Queue{
    int front, rear, size;
    int* arr;

    Queue(int s){
        front=rear=0;
        size=s;
        arr = new int[size];
    }

    void display(){
        if(rear==front){
            cout<<"Queue is Empty!\nFirst Insert some elements :)\n";
            return;
        }
        cout<<"Queue Elements: ";
        for(int i=0;i<rear;++i)
            cout<<arr[i]<<" ";
        cout<<"\n";
    }

    void getFront(){
        if(rear==front)
            cout<<"Queue is Empty!\n";
        else{
            cout<<"First Element: "<<arr[0]<<"\n";
        }
    }

    void push(int val){
        if(rear>=size){
            cout<<"Insertion Unsuccesful!\nQueue is Full.\n";
        }
        else{
            arr[rear]=val;
            rear++;
        }
    }

    void pop(){
        if(rear==front){
            cout<<"Deletion Unsuccesful!\nQueue is Empty!\n";
        }
        else{
            for(int i=0;i<rear-1;++i)
                arr[i]=arr[i+1];
            rear--;
        }
    }
};

int main(){
    cout<<"Enter Size of the Queue: ";
    int size;cin>>size;

    Queue q(size);

    bool flag = true;
    while(flag){
        std::cout<<"\nQueue basic operation Menu :-\n";
        std::cout<<"1. Display\n2. Get Front\n3. push.\n4. Delete.\n5. Exit Program\n\n";
        std::cout<<"Your choice: ";
        std::string choice; std::cin>>choice;

        if(choice.size()>1) // for tackling when input is alphabet and strings.
            choice[0]='6'; 

        switch (choice[0])
        {
        case '1':
            q.display();
            break;
        case '2':
            q.getFront();
            break;
        case '3':
            std::cout<<"Enter the value of Element you want to push: ";
            int val;std::cin>>val;
            q.push(val);
            break;
        case '4':
            q.pop();
            break;
        case '5':
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