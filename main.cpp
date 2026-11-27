// Day1 - LinkedList:
// ======================
//    //1. indsert node after given node
//         void InsertAfter(int data, int afterData); 
//    //2. indsert node before given node
//         void InsertBefore(int data, int beforeData); 	
//    //3. get number of nodes 
//         int GetCount();
//    //4. get data in the given 		 			               
//         int GetDataByIndex(int index);


#include <iostream>
using namespace std;




struct node {
    int data;
    node * next;
    node *prev;
};

class linkedList{
    node*head;
    node * tail;

  
    public:

      linkedList(){
        head = nullptr;
        tail = nullptr;

    }
    ~linkedList(){

    node *temp;

    while(head != nullptr){

        temp = head;
        head = head->next;

        delete temp;
    }
    

    tail = nullptr;
}

    linkedList(const linkedList& other) {

    head = nullptr;
    tail = nullptr;

    node* temp = other.head;

    while(temp != nullptr) {

        push(temp->data);

        temp = temp->next;
    }
}

    linkedList& operator=(const linkedList& other) {

    if(this == &other)
        return *this;

    while(head != nullptr) {

        node* temp = head;
        head = head->next;

        delete temp;
    }

    tail = nullptr;

    node* temp = other.head;

    while(temp != nullptr) {

        push(temp->data);
        temp = temp->next;
    }

    return *this;
}

    void push(int value){

        node *newnode = new node;

        if(head == nullptr){
            node *newnode = new node;
            head = newnode;
            tail = newnode;
            newnode->prev = nullptr;
            newnode->next = nullptr;
            newnode->data = value;
            return ;
        }

        tail->next = newnode;
        newnode->prev = tail;
        newnode->next = nullptr;
        newnode->data = value;
        tail = newnode;
        
    }

    void InsertAfter(int value, int after){
        node *temp = head;
    
       
        while(temp != nullptr && temp->data != after ){
            
            temp = temp->next;
        }

        if(temp == nullptr){
            cout<<"NOT FOUND"<<endl;
            return ;
        }

        node *newnode = new node;
        newnode->data = value;
        newnode->next = temp->next;
        if(temp->next != nullptr){
            newnode->next->prev = newnode;
        }
        temp->next = newnode;
        newnode->prev = temp;

    }

    void InsertBefore(int value, int before){

        node *temp = head;
        node *newnode = new node;

        while(temp != nullptr && temp->next->data != before){
                temp = temp->next;
        
        };

        if(temp == nullptr){
            cout<<"NOT FOUND"<<endl;
            return ;
        }

        newnode->next = temp->next ;
            if(temp->next->prev != nullptr)
                temp->next->prev = newnode;

            temp->next = newnode;
            newnode->prev = temp;
            newnode->data = value;

    }
    int GetCount(){
        if (head == nullptr){
            cout<<"EMPTY "<<endl;
            return -1;
        }
        node *count = new node;
        count = head;
        int counter = 0;
        while(count != nullptr){
            count = count->next;
            counter++;
        }
        delete count;

        return counter;

    }
        void display(){

        if (head ==nullptr){

            cout<<"Queue is empty"<<endl;
            return;
        }
        node *dis = head;

        while(dis != nullptr){
            cout<<dis->data<<" ";
            dis = dis->next;

        };
        cout<<endl;
    }

    void GetDataByIndex(int index){
        node *current = head;
        int temp = 0;
        for(int i = 1 ; i <=index ; i++){
            temp = current->data;
            current = current->next;
        }
        cout<<"Index "<<index<<" = "<<temp;

    }

    
};

int main() {
    linkedList l1;
    l1.push(10);
    l1.push(20);
    l1.push(30);
    l1.push(40);
    l1.display();
    l1.InsertAfter(25,20);
    l1.InsertBefore(35,40);
    cout<<"Nodes = "<<l1.GetCount()<<endl;
    l1.display();
    l1.GetDataByIndex(2);
    cout<<endl;
    
}

