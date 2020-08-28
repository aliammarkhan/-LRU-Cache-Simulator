#include "DLL.h"
#include <iostream>
using namespace std;

template<typename T>
Node<T>::Node()
   {
    next=0;
    prev=0;
    data = 0;
    blockno = 0;
   }
template<typename T>
Node<T>::Node(T *no,int blocksize,int blockno,Node<T>*n,Node<T>*p)
	{

		next=p;
		prev=p;
		this->blockno = blockno;
		this->blocksize = blocksize;
		int nn = blocksize/sizeof(no[0]);

        data = new T(nn);
        for(int i =0 ; i< nn; i++)
          data[i] = no[i];


}
template<typename T>

int Node<T>:: getblocksize()
{
  return blocksize;
}
template<typename T>
Node<T>* Node<T>::getnext()
	{
		return next;

	}
template<typename T>
Node<T>* Node<T>:: getprev()
	{
		return prev;

	}

template<typename T>
DLL<T>::DLL()
    {
        head=0;
        tail=0;
        blocksize = 0;
        capacity = 0;
        currentsize = 0;
    }
template<typename T>
DLL<T> :: DLL(int n1,int n2)
{
  head  = 0;
  tail = 0 ;
  blocksize = n1;
  capacity = n2;
  currentsize = 0;
}
template<typename T>
 void DLL<T>::setcapacity(int n){

   if(n<=capacity)
   cout<<"\n\ncannot reduce cache size!!\n\n";
   else
   capacity = n;

 }

template<typename T>
void DLL<T>:: insertatfront(T *n,int blockno)
	{

         if(currentsize + 1 <= capacity){
         currentsize++;

       Node<T>*newptr=new Node<T>(n,blocksize,blockno);
		if(head==0)
		{
			head=newptr;
			tail=newptr;

		}
		else
		{

			newptr->next=head;
			head->prev=newptr;
			head=newptr;

		}
    }
    else
    cout<<"\nCache is full \n";

	}
template<typename T>
 void DLL<T>:: insertatlast(T *n,int blockno)
	{

		if(currentsize + 1 <= capacity){
		currentsize++;
		Node<T>*newptr=new Node<T>(n,blocksize,blockno);
        if(tail==0)
		{

			tail=newptr;
			head = newptr;


		}
		else
		{

			newptr->prev=tail;
			tail->next=newptr;
			tail=newptr;
			}
        }
        else
        cout<<"\n\nCache is full \n\n";

	}
template<typename T>

void DLL<T> :: printblock(T *data,int blockno)
{
  int nn = blocksize/sizeof(data[0]);


 if(nn>0){
  cout<<"block no "<<blockno<<":";
  for(int i =0 ;i <nn ; i++)
   cout<<data[i]<<" ";
   cout<<endl;
  }

}

template<typename T>
void DLL<T>::printfromhead()
	{

		Node<T>*temp;
		temp=head;

		while(temp->next!=0)
		{

		   printblock(temp->data,temp->blockno);
           temp=temp->next;

		}

		printblock(temp->data,temp->blockno);
	}
template<typename T>
void DLL<T>:: printfromtail()
	{
			Node<T>*temp;
		temp=tail;

		while(temp->prev!=0)
		{

		printblock(temp->data,temp->blockno);
        temp=temp->prev;

		}

		printblock(temp->data,temp->blockno);
	}
template<typename T>
void DLL<T>::removefromhead()
	{

		if(head==tail)
		{
			delete head;
			head=tail=NULL;


		}
	else	if(head!=0)
		{
		  Node<T>*temp;
		  temp=head;
		  head=temp->next;
		  head->prev=0;
		  temp->next=0;
		  delete temp;
		  temp=0;
	    	}
}

template<typename T>
void DLL<T>::removefromtail()
	{

		if(head==tail)
		{
			delete tail;
			head=tail=NULL;


		}
	else if(tail!=0)
		{
		  Node<T>*temp;
		  temp=tail;
		  tail=temp->prev;
		  tail->next=0;
		  temp->prev=0;
		  delete temp;
		  temp=0;
	    	}
}



template<typename T>
void DLL<T>:: Reverselist(Node<T>*current)
		{
			if(current->next==0)
			{
				head=current;
				head->prev=0;
				return;
		    }
		    Reverselist(current->next);
		    Node<T>*temp;
		   if(current->prev==NULL){
		    tail=current;
		    temp=current->next;

		    temp->next=current;

		    current->prev=temp;

		    current->next=NULL;
		}

}
template<typename T>
void DLL<T> ::deleteall()
 		{
 			int i=1;
 			Node<T>* temp=head;

 			while(head!=0)
 			{
 				temp=temp->next;
 			    delete head;
 				head=temp;
 				i++;
 			}
 			head=0;
 			tail=0;


		 }
template<typename T>
bool DLL<T> :: read(int n,int index)
{

  bool found = false;
  Node<T>*temp;
  temp=head;

  while(temp!=0)
  {

    if(temp->blockno == n)
    {
      int nn = blocksize/sizeof(temp->data[0]);
      found = true;
      cout<<"\n\nBlock found !! \n\n";
      printblock(temp->data,temp->blockno);

      if(index<nn){
      cout<<"data at index "<< index<<":"<<temp->data[index]<<endl;
      }

      else
      {
        cout<<"\n\nInvalid index \n\n";
      }

      currentsize--;
      //delete node at insert it from front
      if(temp == head)
        break;
      else if (temp == tail){
       insertatfront(temp->data,temp->blockno);
       removefromtail();
       }
       else{

           if (temp->next != NULL)
          temp->next->prev = temp->prev;

           if (temp->prev != NULL)
          temp->prev->next = temp->next;

           insertatfront(temp->data,temp->blockno);
           delete temp;
           temp = 0;
           break;


       }



    }
    temp = temp->next;



  }
  if(!found){
  cout<<"\n\nThe block is not in cache\n\n";
  return false;
  }
  return true;


}

template<typename T>
bool DLL<T> :: write(int n,int index,T text)
{
   bool found = false;
  Node<T>*temp;
  temp=head;

  while(temp!=0)
  {

    if(temp->blockno == n)
    {
      int nn = blocksize/sizeof(temp->data[0]);
      found = true;
      cout<<"\n\nBlock found !! \n\n";
      printblock(temp->data,temp->blockno);

      if(index<nn){
        temp->data[index] = text;
      }

      else
      {
        cout<<"\n\nInvalid index \n\n";
      }

      currentsize--;
      //delete node at insert it from front
      if(temp == head)
        break;
      else if (temp == tail){
       insertatfront(temp->data,temp->blockno);
       removefromtail();
       }
       else{

           if (temp->next != NULL)
          temp->next->prev = temp->prev;

           if (temp->prev != NULL)
          temp->prev->next = temp->next;

           insertatfront(temp->data,temp->blockno);
           delete temp;
           temp = 0;
           break;


       }



    }
    temp = temp->next;



  }
  if(!found){
  cout<<"\n\nThe block is not in cache\n\n";
   return false;

  }
  return true;


}

template<typename T>
DLL<T>::~DLL()
	{
	   deleteall();

	}




