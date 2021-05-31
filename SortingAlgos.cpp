#include<iostream>
using namespace std;

class sorting_algorithms{
	private:
		int i,j,temp;
	public:
		void bubble_sort(int a[],int len){
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

	return 0;
}
