#include<iostream>
using namespace std;

class sorting_algorithms{
	private:
		int i,j,temp;
	public:
		void bubble_sort(int a[],int len){
			cout<<"\nBUBBLE SORT: ";
			
			for(i=0;i<len;i++){
				for(int j=i+1;j<len;j++){
					if(a[i] > a[j])
					{
						temp = a[i];
						a[i] = a[j];
						a[j] = temp;
					}
				}
			}

			display(a,len);
		}
		
		void selection_sort(int a[],int len){
			cout<<"\nINSERTION SORT: ";
			
			for(int i=0;i<len;i++)
			{
				temp = a[i];

				for(j=i-1;j>=0;j--)
				{
					if(a[j] > temp){
						a[j+1] = a[j];
					}
					else{
						a[j+1] = temp;
						break;
					}	
				}
			}

			display(a,len);
			
		}	
		void display(int arr[],int len){
			for(int i=0;i<len;i++)
				cout<<arr[i]<<+" ";
		}
};

int main()
{
	sorting_algorithms sorting;
	int arr[] = {5,2,7,9,12,4};
	int len = sizeof arr / sizeof arr[0];
	

	const string name = "ramakrishna";
	string last_name = "saidu";
	
	const string *const ptr = &name;
	
	//ptr = &last_name;
	// *ptr = "RAMAKRISHNA";
		
	cout<<*ptr<<endl;

	return 0;
}
