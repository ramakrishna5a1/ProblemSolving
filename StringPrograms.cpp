#include <iostream>
#include <string>

using namespace std;


class string_programs
{
    public:
        void swap(string *c1,string *c2)
        {
            string *t = c1;
            c1 = c2;
            c2 = t;
		cout<<*c1<<*c2<<endl;	
	}
	
	void check_palindrome(string str)
	{
		int len = str.length();

		for(int i=0;i<len/2;i++)
		{
			if(str[i] != str[len - i -1])
			{
				cout<<"not palindrome."<<endl;
				return;	
			}

			cout<<"palindrome"<<endl;
			return;
		}
	}

	char get_max_char(char *ch){
		return 'N';	
	}
};

int main()
{
	string_programs sp;	
	string str1="krishna", str2 = "rama";
	
	sp.swap(&str1,&str2);
	cout<<str1<<str2<<endl;

	sp.check_palindrome("aba");
	sp.check_palindrome("krishna");
	
	string check;
	
	check.append("kri");
	cout<<check<<endl;

	check = "";
	cout<<check<<endl;

	check.append("hello rk");
	cout<<check<<endl;

	check.clear();
	cout<<check<<endl;	

	string letters = "aaaccaasdsdsdaa";
	cout<<"Repeating char: "+sp.get_max_char(&letters[0])<<endl;

	return 0;
}
