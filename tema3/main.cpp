#include<iostream>
using namespace std;
#include<thread>
#include <mutex>
class Lock{
public:
explicit Lock(mutex *pm)
: mutexPtr(pm)
{ mutexPtr->lock(); cout<<"Lock mutex\n";} // acquire resource
~Lock() { mutexPtr->unlock(); cout<<"Unlock mutex\n"; } // release resource
private:
Lock(const Lock& t);
Lock& operator=(const Lock& t);
mutex *mutexPtr;
};
class cladire {
int nrCamere,geamuri,dimensiune;
   public:
      static cladire *make_cladire(int choice);
      cladire() {
         nrCamere=0;
         geamuri=0;
         dimensiune=0;
         cout<<"Constructing cladire\n ";
      }
     virtual ~cladire() {
         cout<<"Destructing cladire\n";
      }
      virtual void getObject()
      {
         cout<<"Sunt cladire"<<"\n";
      }
};
class casa: public cladire {
   public:
      casa() {
         cout<<"Constructing casa\n";
      }
      ~casa() {
         cout<<"Destructing casa\n";
      }
        void getObject()
      {
         cout<<"Sunt casa"<<"\n";
      }
};

class apartament:public cladire{
public:
      apartament() {
         cout<<"Constructing apartament\n";
      }
      ~apartament() {
         cout<<"Destructing apartament\n";
      }
        void getObject()
      {
         cout<<"Sunt apartament"<<"\n";
      }
};
int main() {
   int choice=1;
   mutex m;
   Lock ml(&m);
   // Lock ml2(ml1);
   std::shared_ptr<cladire>c(cladire::make_cladire(choice));
   c->getObject();
   return 0;
}
cladire*cladire::make_cladire(int choice)
{
  if (choice == 1)
    return new casa;
  else if (choice == 2)
    return new apartament;
  else
    return NULL;
}
