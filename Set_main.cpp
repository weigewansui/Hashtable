#include "Set.cpp"

int main(){

	Set a,b,c,d,e,f;

	//test is_element;
	cout <<"-------is_element() test-------------\n";
	cout <<a.is_element(5555555)<<endl;
	cout <<"-------insert() test----------------\n";
	a.insert(1);
	a.insert(2);
	a.insert(3);
	a.insert(4);
	a.insert(5);
	a.insert(55);
	a.insert(22);
	a.insert(25);
	a.insert(221);
	a.insert(0);
	a.insert(-2);

	b.insert(5);
	b.insert(8);
	b.insert(9);
	b.insert(2);
	b.insert(3);
	b.insert(44);
	b.insert(22);
	b.insert(33);
	cout <<"the sets are:\n"<<"a = "<< a <<endl;

	cout <<"--------erase() test--------------\n";
	a.erase(1);
	//a.erase(4);
	cout <<"the sets are:\n"<<"a = "<< a <<endl;

	cout <<"--------sunion() test-------------\n";

	cout <<"a is: "<<a<<endl;
	cout <<"b is: "<<b<<endl;

	c = sunion(a,b);
	cout <<"union of a and b is: "<<c<<endl;

	cout <<"---------test sintersection()-----------------\n";
	cout <<"a is: "<<a<<endl;
	cout <<"b is: "<<b<<endl;

	e = sintersection(a,b);
	cout <<"sintersection(a,b)= "<<e<<endl;


	cout <<"---------test +-----------------\n";
	cout <<"a is: "<<a<<endl;
	cout <<"b is: "<<b<<endl;

	d = a+b;
	cout <<"a+b= "<<d<<endl;

	cout <<"---------test- -----------------\n";
	cout <<"a is: "<<a<<endl;
	cout <<"b is: "<<b<<endl;

	f = a-b;
	cout <<"a-b= "<<f<<endl;
}
