#include<iostream>
using namespace std;
class complex{
	int real;
	int imag;
	public:
	complex(){
		real=0;
		imag=0;
	}
	complex operator+(complex);
	complex operator *(complex);
	friend istream &operator>>(istream &input,complex &t) //declaration of overloaded input stream operator>>for complex type
	//allows object of type complex to be read from an input stream
	//friend keyword allows func to access private and protected mem of class
	{
		cout<<"Enter the real part:";
		cin>>t.real;  //reads the real part of complex no.
		cout<<"Enter the imaginary part:";
		cin>>t.imag;
	}
	friend ostream &operator <<(ostream &output,complex &t){
		output<<t.real<<"+"<<t.imag<<"i"<<endl;
	}
};
complex complex::operator +(complex c){ //parameter passed to operator which represents 2nd complex no..
	complex temp;
	temp.real=real+c.real;
	temp.imag=imag+c.imag;
	return temp;
}
complex complex ::operator*(complex c){
	complex temp2;
	temp2.real=(real*c.real)-(imag*c.imag);
	temp2.imag=(real*c.imag)+(imag*c.real);
	return temp2;
}

int main(){
	complex c1,c2,c3,c4;  ///declare complex no.variables
	cout<<"Default constructor value=\n";
	cout<<c1;
	cout<<"Enter the first complex number\n";
	cin>>c1;
	cout<<"Enter the second complex number\n";
	cin>>c2;
	c3=c1+c2;
	c4=c1*c2;
	cout<<"The sum of the complex numbers is:\n";
	cout<<c3;
	cout<<"The product of the complex numbers is:\n";
	cout<<c4;
	return 0;
}