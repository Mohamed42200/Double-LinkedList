#include <iostream>

using namespace std;

struct Node{
    int data ;
    Node*next =nullptr;
    Node*prev = nullptr;
};

Node*head = nullptr ;

void append_Back(int v){
    Node*newNode = new Node();
    newNode->data = v ;

    if(head == nullptr){//If head is empty, I will add a new node
        head = newNode ;
        return ;
    }

    Node*ptr = head ;
    while(ptr->next!= nullptr){   //Add a new node at the back
        ptr = ptr->next ;
    }

    ptr->next = newNode ;
    newNode->prev = ptr ;


}

void append_Front(int v){
    Node*newNode = new Node() ;
    newNode->data = v ;
    if(head == nullptr){
        head = newNode ;
        return ;
    }

    Node*ptr=  head ;
    while(ptr->prev!=nullptr){
        ptr = ptr->prev ;
    }
    head = newNode;
    newNode->next = ptr ;
    ptr->prev = newNode ;



}

void append_Position(int key , int value){

    if(head == nullptr){ // Verify that the list is not empty before creating the new node
        cout<<"list is empty...\n";
        return ;
    }

    Node*newNode = new Node() ; // Create the new node
    newNode->data = value ;
    Node*ptr = head ;

    while(ptr!=nullptr){
        if(key == ptr->data){
            if(ptr->next!=nullptr){   //If the current node is not the last node
            newNode->next = ptr->next;
            newNode->prev = ptr ;
            ptr->next->prev = newNode ;
            ptr->next = newNode ;

            }
            else{  //If the current node is  the last node
            newNode->next = ptr->next;
            newNode->prev = ptr ;
            ptr->next = newNode ;
            }
            return ;

        }
        ptr = ptr->next ;
    }

    cout<<"key Not found...\n";// If the key is not found

    delete newNode ;  // Avoid memory leaks


}

void deleteNode(int key){

    if(head == nullptr){
        cout<<"List is Empty\n";
        return ;
    }
    Node*ptr = head ;

    while(ptr!=nullptr){
        if(key == ptr->data){
            if(ptr->prev==nullptr){// If the node to be deleted is the head
                head = ptr->next ;
                delete ptr ;
            }
            else {
                if(ptr->next==nullptr){//If the node to be deleted is the tail
                    ptr->prev->next = ptr->next;
                    delete ptr ;
                }
                else{//If the node to be deleted is in the middle of the list
                    ptr->prev->next = ptr->next;
                    ptr->next->prev = ptr->prev ;
                    delete ptr ;

                }

            }
            return ;
        }
        ptr = ptr->next ;

    }

    cout<<"Not Found\n";



}

void display(){

    Node*ptr = head ;

    while(ptr != nullptr){
        cout<< ptr->data<<" \n" ;
        ptr = ptr->next ;
    }








}

int main()
{
    append_Back(1);
    append_Back(2);
    append_Back(3);
    append_Back(4);


/*
    append_Back(1);
    append_Back(2);
    append_Back(3);
    append_Back(4);



    append_Front(1);
    append_Front(2);
    append_Front(3);
    append_Front(4);
     */

   append_Position(1,6);
    deleteNode(4);
    display();

    return 0;
}
