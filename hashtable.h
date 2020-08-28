#ifndef HASHTABLE_H
#define HASHTABLE_H


template <typename t>
class dnode{

	public:
	t add;
	t blockno;

	dnode<t>* next;
	dnode<t>* prev;
	template <typename u>
	friend class list;

	dnode();
	dnode(dnode<t> *a,t add,t blockno);
	dnode(t add,t blockno);
	dnode(dnode<t> *a,dnode<t> *b, t add=0,t blockno=0);

};

template <typename t>
class list{

	public:
	dnode<t> *head;
	dnode<t> *tail;

	void deleteallnodes();
	list();
    list(dnode<t>* a,dnode<t> *b);
//dodeepcopy
   void dodeepcopy(const list<t>& list);
//copy constructor
	list(const list<t>& list);
//assignment operator
	list<t>& operator=(const list<t>& d);
    void insertatlast(t a,t b);
    void removefromlast();
    dnode<t>* search(int k);
    void printall();
	~list();

};

template <typename t>
class hashing{

	private:
	list<t> *l;
    int Size;

	public:
	hashing(int a);
	int getcapacity();
    //key calculation
	int hashkey(int k);
	void insert(int k,t add,t blockno);
    void print();
};

#endif // HASHTABLE_H
