#include <iostream>
#include "DLL.h"
#include "DLL.cpp"
#include "hashtable.h"
#include "hashtable.cpp"
#include<stdlib.h>
#include<time.h>

void showblock(int n)
{

cout<<endl;
for(int i = 0 ;i<n ;i++)
 cout<<"Block "<<i<<endl;
 cout<<endl;


}

void getblock(int blocksize,int *p)
{
  int n = blocksize/sizeof(int);

  for(int i = 0 ;i <n ;i ++)
  {
    srand (time(NULL));
    p[i] =rand() % 10 + 1;
  }



}



using namespace std;

int main()
{
 int cachesize = 0,blocksize = 0,opt;

 int index=0;
 bool found = false;
 int text = 0;

 cout<<"Enter cache capacity:";
 cin>>cachesize;
 cout<<"Enter block Size:";
 cin>>blocksize;

  while(blocksize%4!=0)
  blocksize++;
  DLL<int> l(blocksize,cachesize);
  int block[blocksize/sizeof(int)];


while(1){
 cout<<"\t\tLRU CAHCE SIMULATOR\n\n";
 cout<<"1.increase cache size"<<endl;
 cout<<"2.Read block"<<endl;
 cout<<"3.Write block"<<endl;
 cout<<"4.View cache"<<endl;
 cout<<"5.exit"<<endl;
 cout<<"Option: "<<endl;
 cin>>opt;


 if(opt==1)
 {
  cout<<"Enter cache size:";
  cin>>cachesize;
  l.setcapacity(cachesize);
 }

 else if(opt == 2)
 {

   showblock(cachesize);
   cout<<"option:";
   cin>>opt;
   cout<<"Enter index:";
   cin>>index;
   if(opt<cachesize){
   found =l.read(opt,index);
   if(!found){
    getblock(blocksize,block);
    l.insertatfront(block,opt);
  }
}
   else
   cout<<"\n\nInvalid block no !!\n\n";
}

else if (opt == 3)
{
   showblock(cachesize);
   cout<<"option:";
   cin>>opt;
   cout<<"Enter index:";
   cin>>index;
   cout<<"Enter text:";
   cin>>text;
   if(opt<cachesize){
   found =l.write(opt,index,text);
   if(!found){
    getblock(blocksize,block);
    l.insertatfront(block,opt);
  }
}
   else
   cout<<"\n\nInvalid block no !!\n\n";


}
 else if(opt == 4)
 l.printfromhead();

 else if(opt == 5)
  break;
}



    return 0;
}
