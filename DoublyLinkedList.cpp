#include<iostream>
#include <string>
#include "DoublyLinkedList.h"

using namespace std;

template<class T>
    DoublyLinkedList<T>::DoublyLinkedList()
    {
        head = NULL;
	tail = NULL;
        length = 0;
    }

    template<class T>
    DoublyLinkedList<T>::~DoublyLinkedList()
    {
      struct NodeType<T> *p = head;

      struct NodeType<T> *tmp = p->next;

      while (p != NULL) {
	delete p;
	p = tmp;
	tmp = tmp->next;
      }
      
    }

    template<class T>
    void DoublyLinkedList<T>::insertItem(T &item)
    {
       struct NodeType<T>*newNode = new struct NodeType<T>;
        newNode->back = NULL;
        newNode->data = item;
        newNode->next = NULL;
        //head = newNode;
        //tail = newNode;
        NodeType<T> *p;

        //when list is empty
	cout << "Inserting: " << item << "length:" << this->length << endl;
        if(lengthIs()== 0)
        {
            head = newNode;
            head->back = NULL;
            head->next= NULL;
            this->length++;
	    return;
        }
        //inserting while keeping sorted order
        NodeType<T> *currentPos;
        currentPos = head;
        p = NULL;

        while(currentPos!= NULL)
        {
	    cout << currentPos->data << "->";
            if(newNode->data > currentPos->data)
            {
	        p = currentPos;
	        if (currentPos->next != NULL) {
		  currentPos = currentPos->next;
		} else {
		  // insert newNode here
		  cout << "\nInserting node at the end of list\n";
		  currentPos->next=newNode;
		  newNode->back = p;

		  length++;
		  break;

		}
            }else if( newNode->data < currentPos->data)
            {
                p->next = newNode;
                newNode->back = p;
                newNode->next = currentPos;
                length++;
                break;
            }
        }
    }


    template<class T>
    void  DoublyLinkedList<T>::deleteItem(T &item)
    {
        NodeType<T>*newNode = new NodeType<T>;
        newNode->back = NULL;
        newNode->data = item;
        newNode->next = NULL;
        //head = newNode;
	//tail = newNode;
        NodeType<T> *q;
        q = NULL;

        NodeType<T> *currentPos;
        currentPos = head;

        //deleting from an empty list
        if(head == NULL)
        {
            cout<<"You cannot delete from an empty list.";
        }
        //
        while(currentPos->next !=NULL)
        {
            if(newNode->data != currentPos->data)
            {
	      q = currentPos;
	      currentPos = currentPos->next;
                //q = q->next;
            } else {   
                currentPos = currentPos->next;
                q->next = currentPos;
                if (currentPos != NULL)
		  currentPos->back = q;
		
                delete newNode;
                length--;
                cout << "item deleted from the list." << endl;
		return;
	    }/*else if(newNode->data != currentPos->data && currentPos->next==NULL)
            {
                cout<<"Item not in list!";
            }*/
	}

	cout << "Item not in list!" << endl;
    }

    template<class T>
    int  DoublyLinkedList<T>::lengthIs()
    {
        return this->length;
    }

    template<class T>
    void  DoublyLinkedList<T>::print()
    {
        NodeType<T> *p = head;
        while(p != NULL)
        {
            cout<<p->data<<" ";
            p = p->next;
        }
        cout<<endl;
    }

    template<class T>
    void  DoublyLinkedList<T>::printReverse()
    {
        NodeType<T> *p = head;
        NodeType<T> *temp;

	while (p != NULL) {
	  temp = p;
	  p = p->next; //this is to go to the end of the list
	}
        while (temp != NULL) {
	  cout << temp->data << " ";

	  temp = temp->back;
	}

	/*
        while(p != NULL)
        {
            temp = p->next;
            p->next = p->back;
            p->back = temp;
            p = p->next;

            //checks for the head of the list
            if(p->next == NULL)
            {
                head = p;
            }
            cout<<p->data<<" ";
	    }*/
        cout<<endl;
    }

    //deletes numbers between a lower and upper boundary
    template<class T>
    void  DoublyLinkedList<T>::deleteSubsection(int lowerBound, int upperBound)
    {
      NodeType<T> *p,*q, *s = new NodeType<T>;
        this->lowerBound = lowerBound;
        this->upperBound = upperBound;
	p =NULL;
	q=NULL;
	s=NULL;
        cout<<"Enter lower bound: ";
        cin>> lowerBound;
        cout<<endl;

        cout<<"Enter upper bound: ";
        cin>>upperBound;
        cout<<endl;

        p->data = lowerBound;
        q->data = upperBound;
        s->data = p->data;
        while(true)
        {
            deleteItem(s->data);
            s = s->next;

            //check if the pointer is on the upperBound
            if(s->data == q->data)
            {
                deleteItem(s->data);
                break;
            }
        }


    }

    template<class T>
    void  DoublyLinkedList<T>::mode()
    {

        cout<<"Mode: ";
    }

template<class T>
    void  DoublyLinkedList<T>::swapAlternate()
    {
      NodeType<T> *temp = head;
      while(temp != NULL && temp->next != NULL ){
	swap(temp->data, temp->next->data);

	temp = temp->next->next;
      }
    }    

template<class T>
void DoublyLinkedList<T>::initialize(T number) {
    this->value = number;
}

template class DoublyLinkedList<int>;
template class DoublyLinkedList<float>;
template class DoublyLinkedList<string>;

