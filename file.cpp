#include<iostream>
#include<fstream>
#include<cstring>
using namespace std;

int main(){
    string name;
    int roll_no;

    ofstream outfile;
    outfile.open("data.txt", ios::out);
    
    cout<<"......writing to the file....."<<endl;

    cout<<"Enter your name:";
    getline(cin,name); 
    //read entire line from standard input cin 
    //and stores it in name variable
    outfile<<name<<endl;

    cout<<"enter roll no:";
    cin>>roll_no;
    outfile<<roll_no<<endl;
    cin.ignore(); //to clear input buffer
    //This is used to clear the input buffer. 
    //When cin is used to read an integer (cin >> roll_no), 
    //it leaves a newline character (\n) in the input buffer.
    // If another input operation (such as getline()) is 
    //done afterward, it might mistakenly read this 
    //leftover newline. cin.ignore() clears the buffer.
    outfile.close();

    //opening the file for reading 

    ifstream infile;
    infile.open("data.txt",ios::in);

    cout<<"Entered data is:\n";
    getline(infile,name);//reads 1st line from file
    infile>>roll_no;
    cout<<"name:"<<name<<endl;
    cout<<"roll no:"<<roll_no<<endl;
    
    infile.close();
    return 0;

}