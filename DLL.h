#ifndef DLL_H
#define DLL_H


template<typename T>
class DLL;

template<typename T>
class Node
{
	private:
	T  *data;
	int blockno;
	Node <T>*next;
	Node <T>*prev;
	int blocksize;

	public:

	Node();
	Node(T *no,int blocksize,int blockno,Node<T>*n=0,Node<T>*p=0);
    Node<T>* getnext();
    Node<T>* getprev();
    int getblocksize();
	friend class DLL<T>;
};
template<typename T>
 class DLL
 {

 	Node<T>*head;
 	Node<T>*tail;
 	int blocksize;
 	int capacity;
 	int currentsize;
 	public:

        DLL();
        DLL(int n1,int n2 );
        void insertatfront(T *n, int blockno);
	    void  insertatlast(T *n,int blockno);
	    void printfromhead();
	    void printfromtail();
	    void removefromhead();
        void removefromtail();
        void Reverselist(Node<T>*current);
        void deleteall();
        void setcapacity(int n);
        void printblock(T *data,int blockno);
        bool read(int n,int index);
        bool write(int n,int index, T text);

	   ~DLL();

};


#endif // DLL_H
