#include<iostream>
using namespace std;

int main(){
	int val = 6789;
	int *p = &val;
	int **pp = &p;

	cout<<"Double pointer: "<<**pp<<endl;
	cout<<"*p value with **pp: "<<*pp<<endl;
	cout<<"*P address with **PP(pp): "<<pp<<endl;
	cout<<"*P addres  with &P: "<<(&p)<<endl;

	return 0;
}
