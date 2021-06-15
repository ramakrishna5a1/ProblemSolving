#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;


class string_programs
{
    public:
        void swap(string *c1,string *c2)
        {
            	string t = *c1;
            	*c1 = *c2;
            	*c2 = t;
	}
	
	void check_palindrome(const string str)
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

	int get_max_char(const char *ch,int len)
	{
		int maxCount=0,lookup[26] = {0};
		
		for(int i=0;i<len;i++)
			lookup[(int)(*(ch+i))-97]++;		
		
		for(int i=0;i<26;i++) maxCount = max(maxCount,lookup[i]);
		return maxCount;	
	}


	int get_str_len(const char *str)
	{
		int i=0,len = 0;

		while(*(str+i) != '\0'){ 
			len++;
			i++;
		}

		cout<<"Length: "<<len<<endl;
		return len;
	}

	void reverse_recursion_string(const char *str)
	{
		if(*str == '\0') return;
		reverse_recursion_string(str + 1);
		cout<<*str<<" ";	
	}

	void sort_strings(vector<string> names)
	{
		sort(names.begin(),names.end());
		for(int i=0;i<names.size();i++)
		{
			cout<<names[i]<<" ";
		}

		cout<<"\n";
	}

	void sort_string_chars(string str)
	{
		cout<<"sorting string: "<<str;
		//sort(str.begin(),str.end());
		
		int len = str.size();
		cout<<"\nlen of str: "+to_string(len)<<endl;

		sort(&str[0],&str[len]);		
		
		cout<<"\n"+str+"\n";
		

	}
};


int main()
{
	string_programs sp;	
	string str1="krishna", str2 = "rama";
	cout<<str1<<" / "<<str2<<endl;
	sp.swap(&str1,&str2);
	cout<<str1<<" / "<<str2<<endl;

	sp.check_palindrome("aba");
	sp.check_palindrome("krishna");
	
	char letters[] = "aaaccaasdsdsdaa";
	int len = sp.get_str_len(letters);
	cout<<"Repeating char: "<<sp.get_max_char(&letters[0],len)<<endl;
	
	string str3 = "krishna";
	char *char_str3 = &str3[0];
	
	int i=0;
	while(*(char_str3 + i)){
		cout<<*(char_str3 + i);
		i++;
	}
	
	cout<<endl;
	sp.reverse_recursion_string(&str3[0]);
	cout<<endl;
	
	cout<<"\nSorting the vector of Strings:\n";
	vector<string> names {"krishna","rama","bro","dude","happy","sad"};
	sp.sort_strings(names);

	sp.sort_string_chars("ramakrishna");	
	return 0;
}

