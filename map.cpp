#include <iostream>
#include <map>
#include <string>
using namespace std;

int main(){
    map<string,int>state; 
    state["Maharashtra"]=39538223;
    state["Karnataka"]=29145505;
    state["Gujarat"]=21538187;
    state["Uttar Pradesh"]=20201249;
    state["West Bengal"]=13002700;


map<string,int>::iterator it;
  cout<<"List of states:\n";
for(it= state.begin();it!= state.end();++it)
{cout<<it->first<<endl;}
   
   
    string statename;
    cout<<"\nEnter the name of a state: ";
    getline(cin,statename);


it= state.find(statename);
if(it!= state.end())
{
  cout<<"The population of "<<statename<<" is "<<state[statename]<<"."<<endl;"\n";
    }else{
        cout<<"State not found.\n";
    }
  return 0;
} 