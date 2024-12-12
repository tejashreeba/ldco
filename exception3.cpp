#include<iostream>
using namespace std;

class publication{
protected:
 string title;
 float price;
 
 public:
 publication(string t="",float p=0.0){}
 };
 
 class book:public publication{
 int pages;
 
 public:
 book(string t="",float p=0.0,int pa=0){}
 void getb();
 void displayb();
 };
 
 class tape:public publication{
 protected:
 float min;
 public:
 tape(string t="",float p=0.0,float m=0.00){}
 void gett();
 void displayt();
 };
 
 void book::getb(){
 cout<<"Enter the book details";
 cout<<"\nEnter the title of the book:";
 cin.ignore(1,'\n');
 getline(cin,title);
 cout<<"\nEnter the price of the book:";
 cin>>price;
 cout<<"\nEnter the pages of the book:";
 cin>>pages;
  
    try{
      if(pages>500 && pages<1500){
          if(price>100 && price<2000){
                displayb();
          }
      }
      else{
           throw(pages);
      }
    }
    catch(int x){
      cout<<"Enter valid data!"<<endl;
      title="";
      pages=00;
      price=0.00;
      displayb();
      throw;
    }
 }
 
 void book::displayb(){
 cout<<"\nBook details:"<<endl;
 cout<<"Title of the book:"<<title<<endl;
 cout<<"Price of the book:"<<price<<endl;
 cout<<"Number of pages:"<<pages<<endl;
 }
 
 void tape::gett(){
 cout<<"Enter the tape details";
 cout<<"\nEnter the title of the tape:";
 cin.ignore(1,'\n');
 getline(cin,title);
 cout<<"\nEnter the price of the tape:";
 cin>>price;
 cout<<"\nEnter the playing time(in minutes):";
 cin>>min;
    
    try{
      if(min>30.00 && min<90.00){
          if(price>500 && price<1000){
                displayt();
          }
      }
      else{
           throw(min);
      }
    }
    catch (float f){
      cout<<"Enter valid data!"<<endl;
      title="";
      min=00;
      price=0.00;
      displayt();
      throw;
    }
 }
 
 void tape::displayt(){
 cout<<"\nTape details:"<<endl;
 cout<<"Title of the tape:"<<title<<endl;
 cout<<"Price of the tape:"<<price<<endl;
 cout<<"Playtime of the tape"<<min<<endl;
 }
 
 int main (){
    book b;
    tape t;
    int choice;
    cout<<"\nDo you want to buy a book or tape:"<< endl<<"1.Book"<<endl<<"2.Tape"<<endl;
    cin>>choice;
    
    switch(choice){
        case 1:
           try{
              b.getb();
           }
           catch(int x){
              cout<<"exception caught"<<endl;
           }
           break;
               
        case 2:
           try{
              t.gett();
           }
           catch(float f){
              cout<<"exception caught"<<endl;
           }
           break;
           
        default:
        cout<<"Wrong choice Entered."<<endl<<"Please enter 1 or 2"<<endl;
    }
    return 0;
 }