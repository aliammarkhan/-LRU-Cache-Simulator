#include "hashtable.h"
#include<iostream>
using namespace std;

template <typename t>
dnode<t>::dnode()
{
    prev = 0;
    next = 0;
    add = 0;
    blockno = 0;

}
template <typename t>
dnode<t>::dnode(dnode<t> *a,t add,t blockno)
{

    prev = a;
    next = 0;
    this->add = add;
    this->blockno = blockno;

}
template <typename t>
dnode<t>::dnode(t add,t block)
{
  prev = 0;
  next = 0;
  this->add = add;
  this->blockno = blockno;
}
template <typename t>
dnode<t>::dnode(dnode<t> *a,dnode<t> *b, t add,t block)
{
    prev = a;
    next = b;
    this->add = add;
    this->blockno = blockno;


}
template<typename t>
	void list<t> :: deleteallnodes(){
		if(head!=0 && tail!=0){
			dnode<t> *temp=head;
			dnode<t> *deletor;

			while(temp!=0){
				cout<<"\nDeleting location: "<<temp;
				deletor=temp;
				temp=temp->next;
				delete deletor;
			}

			cout<<"\n\nAll nodes destroyed\n";
		}
		else{
			cout<<"\nNo nodes found\n";
		}
	}
template<typename t>
   list<t> :: list(){
        head = 0;
        tail = 0;

   }

template<typename t>
list<t> :: list(dnode<t>* a,dnode<t> *b){

         head = a;
         tail = b;
}
template<typename t>
void list<t> :: dodeepcopy(const list<t>& list){
		dnode<t> *temp=list.head;
		dnode<t> *ptr=0;

		this->head=0;
		this->tail=0;

		while(temp!=0){
			ptr=new dnode<t>(temp->data);
			if(head==0 && tail==0){
				head=ptr;
				tail=ptr;
			}
			else{
				tail->next=ptr;
				ptr->prev=tail;
				tail=ptr;
				ptr->next=0;
			}
				temp=temp->next;
		}
	}
template<typename t>
	//copy constructor
	list<t>::list(const list<t>& list){
		dodeepcopy(list);

	}
template<typename t>
	//assignment operator
	list<t>& list<t>::operator=(const list<t>& d){
		if(this!=&d){
			delete this;
			dodeepcopy(d);
		}
		else return (*this);
	}
template<typename t>
	void list<t> :: insertatlast(t a,t b){
		dnode<t> *newnode=new dnode<t>(a,b);
		if(head==0 && tail==0){
			head=newnode;
			tail=newnode;
		}
		else{
			newnode->next=0;
			newnode->prev=tail;
			tail->next=newnode;
		    tail=newnode;
		}
	}
template<typename t>
	void list<t>::removefromlast(){
		dnode<t> *temp;
		if(head==0){
			cout<<"\nEmpty list\n";
		}
		else if(head==tail){
			delete head;
			head=0;
			tail=0;
		}
		else{
			temp=tail;
			tail=tail->prev;
			tail->next=0;
			delete temp;
		}
	}
template<typename t>
    dnode<t>* list<t> :: search(int k){
    	dnode<t> *temp=head;
    	while(temp->data!=k){
    		temp=temp->next;
		}
		return temp;
	}
template<typename t>

	void list<t> :: printall(){
		dnode<t> *temp=head;
		while(temp!=0){
			cout<<temp->data<<" ";
			temp=temp->next;
		}
	}
template<typename t>
	list<t>::~list(){
		deleteallnodes();
		head=0;
	}
template<typename t>
hashing<t>::hashing(int a){
		Size=a;
		l=new list<t>[a];
	}
template<typename t>
	int hashing<t> :: getcapacity(){
		return Size;
	}
template<typename t>
	//key calculation

	int hashing<t> :: hashkey(int k){
		return (k%Size);
	}
template<typename t>
	void hashing<t> :: insert(int k,t add,t blockno){
		int hash_index=hashkey(k);
		l[hash_index].insertatlast(add,blockno);
	}



template<typename t>
	void hashing<t> :: print(){
		for(int i=0;i<Size;i++){
			l[i].printall();
			cout<<endl;
		}
	}
