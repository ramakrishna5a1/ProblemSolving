#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <bits/stdc++.h>

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
		//using predefined methods:
		/*
		cout<<"sorting string: "<<str;
		//sort(str.begin(),str.end());
		
		int len = str.size();
		cout<<"\nlen of str: "+to_string(len)<<endl;

		sort(&str[0],&str[len]);		
		
		cout<<"\n"+str+"\n";
		*/

		//using hashing method

		int ar[26]  {0};
		
		for(int i=0;i<str.size();i++)
		{
			ar[str[i] - 'a']++;
		}
		
		for(int i=0;i<26;i++)
		{
			while(ar[i]>0)
			{
				cout<<(char)(97+i);
				ar[i]--;
			}
		}		
	}

	void string_permutations(string a,int l,int r)
	{
		if(l == r)
		{
			cout<<a<<endl;
			return;
		}

		for(int i=l;i<=r;i++)
		{	
			a = swap_chars(a,l,i);
			string_permutations(a,l+1,r);
			a = swap_chars(a,l,i);
		}
	}

	string swap_chars(string a,int i,int j)
	{
		char temp = a[i];
		a[i] = a[j];
		a[j] = temp;

		return a;
	}

	bool anagrams_or_not(std::string str1,std::string str2)
	{	
		int len1 = str1.length();
		int len2 = str2.length();
		
		int *arr = new int[26];	

		if(len1 != len2)
		{
			return false;
		}
		
		int count[26] {0};
		
		for(int i=0;i<len1;i++)
		{
			count[(int)(str1[i]-'a')]++;
		}

		for(int i=0;i<len2;i++)
		{
			count[(int)(str1[i]-'a')]--;
		}

		for(int i=0;i<26;i++)
		{
			if(count[i] != 0)
				return false;
		}

		return true;
	}
	
	bool consists_only_digits(const char *ptr)
	{
		int len = std::strlen(ptr);
		
		for(int i=0;i<len;i++)
		{
			char digit = *(ptr+i);
			if(digit < '0' ||  digit > '9')
			{
				return false;
			}
		}

		return true;
	}

	void first_nonrepeat_character(std::string line)
	{
		int i,look_up[26] {0};
		
		//ex = abcabbdkjfskjdd

		for(i=0;i<line.length();i++)
		{
			look_up[(int)(line[i]-'a')]++;
		}

		for(i=0;i<line.length();i++)
		{
			if(look_up[(int)(line[i]-'a')] == 1)
			{
				break;
			}	
		}

		if(i != line.length())
		{	
			std::cout<<"\nFirst Non-Repeat Character: "<<line[i]<<std::endl;
	
		}
	}

	void max_adjacent_repeated_char(/*std::string& ref*/)
	{
		std::string ref = "abcaab";
		int i=0,count=0,max_count=0,len = ref.length()-1;
		char max_repeat_char = '-';

		while(i<len)
		{
			if(ref[i] == ref[i+1])
				count = (count == 0)? 2 : (count+1);
			else if(count > max_count)
			{
				max_repeat_char = ref[i];
				max_count = count;
				count = 0;
			}
			
			i++;
		}
		std::cout<<max_repeat_char<<std::endl;
		std::string line = (max_count == 0)? ("No character repeated adajacently.") : ("Max adjacent repeated character is: "+std::string(max_repeat_char));	
		std::cout<<"\n"+line+"\n";
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
	while(*(char_str3 + i))
	{
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
	
	cout<<"\nPermutations of a string:\n"<<endl;
	string permute_string = "ABC";
	sp.string_permutations(permute_string,0,permute_string.length()-1);	
	cout<<endl;
	
	std::cout<<"Anagrams:\n";
	std::string anagram_str1 = "ramkrishna";
	std::string anagram_str2 = "mar";
	std::cout<<"is two strings anagrams?: "<<sp.anagrams_or_not(anagram_str1,anagram_str2)<<endl;
	
	string only_digits = "955003993a0";
	std::cout<<"consists only digits: ";
	std::cout<<sp.consists_only_digits(&only_digits[0])<<std::endl;

	sp.max_adjacent_repeated_char();

	sp.first_nonrepeat_character("abcabbdkjfskjdd");
	return 0;
}
