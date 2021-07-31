#include <iostream>
using namespace std;

class Node
{
	private:
		int data;
		Node *next;
		
		Node(int _data,Node *_next)
		{
			data = _data;
			next = _next;
		}
		
		friend class LinkedList;	
};

class LinkedList
{
    public:
        void display_list()
        {
            if(this->head == nullptr)
            {
				cout<<"No elements found..."<<endl;
				return;
			}
            
			Node *temp = this->head;
			while(temp->next != nullptr)
			{
				cout<<temp->data<<"->";
				temp = temp->next;
			}
			cout<<temp->data<<endl;
        }
        
		/*
			@pos it is zero based index
		*/
        bool add_node(int pos, int data)
        {
            if(this->head == nullptr)
            {
                head = new Node(data,nullptr);
                size++;
                return true; 
            }
			
			//insert at the begining
			if(pos == 0)
			{
				Node *new_node = new Node(data,this->head);
				head = new_node;
				return true;	
			}
			
			//insert at the end
			if(pos == (size-1))
			{
				Node *temp = this->head;
				while(temp->next != nullptr)
					temp = temp->next;
				temp->next = new Node(data,nullptr);	
			}
			
			//insert in the middle
			{
			
			}
        }
        
        bool delete_at_position(LinkedList list, int pos)
        {
            return true;    
        }
		
        bool delete_element()
        {
            return true;    
        }
        
        bool reverse_list()
        {
            return head;    
        }

    private:
        static size = 0;
        Node *head = nullptr;        
};

int main()
{
    return 0;
}
