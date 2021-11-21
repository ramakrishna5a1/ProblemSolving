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
	int size = 0;

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
		@pos consider this as in zero based index
	*/
    	bool add_node(int pos, int data)
	{
		pos = pos-1;
		bool is_inserted = false;
		if(pos < 0 || pos > (size-1))
		{
			std::cout<<"unable to insert at the given postion as size is: "<<size<<std::endl;
			return false;
		}
        
		if(this->head == nullptr)
        	{
            		head = new Node(data,nullptr);
			size++;
            		is_inserted = true; 
        	}
			
		//insert at the begining
		if(pos == 0)
		{
			Node *new_node = new Node(data,head);
			head = new_node;
			is_inserted = true;	
		}
			
		//insert at the end
		if(pos == (size-1))
		{
			Node *temp = head;
			while(temp->next != nullptr)
				temp = temp->next;
			temp->next = new Node(data,nullptr);	
			is_inserted = true;
		}
			
		//insert in the middle at given position
		/*
		 *0  1  2  3  4 
		 *1->2->3->4->5
		 * 
		 */
		if(!is_inserted)
		{
			Node *temp = head;		
			for(int i=0;i<pos;i++)
			{
				temp = temp->next;
			}
			
			temp->next = new Node(data,temp->next);
			is_inserted = true;
		}

		if(is_inserted)
		{
			size++;
			return true;
		}

		return false;
    	}
          
    	bool add_node(int data)
    	{
        	Node *new_node = new Node(data,nullptr);
        
		if(head == nullptr)
		{
		    head = new_node;
		    size++;
		    return true; 
		}
			
        	Node *temp = head;
		while(temp->next != nullptr)
			temp = temp->next;
		temp->next = new_node;
        
		if(new_node != nullptr)
		{
			size++;
			return true;
		}

       	return false;
    	}
        
    	bool delete_at_position(int pos)
    	{	
		Node *deleting_element = nullptr;
		
		if(this->head == nullptr)
		{
			return false;	
		}
		else if(pos == 1 && this->head->next == nullptr)
		{
			deleting_element = head;
			size--;
			delete deleting_element;
		}
		else if(pos == size && delete_element())
		{
			deleting_element == nullptr;
		}
		else
		{
			Node *temp = head;
			for(int i=0;i<pos;i++)
			{
				temp = temp->next;
			}
			deleting_element = temp->next;
			temp->next = temp->next->next;
			size--;
			delete deleting_element;
		}
		
		return (deleting_element == nullptr);    
    	}
		
    	bool delete_element()
    	{
		Node *deleting_element = nullptr;
		
		if(this->head == nullptr)
		{
			return false;	
		}
		else
		/*
			if head is the only node in the list then 
			remove the head itself
		*/
		if(this->head->next == nullptr)
		{
			deleting_element = head;
			size--;
			delete deleting_element;
		}
		else
		{
			Node *temp = this->head;
			while(temp->next->next != nullptr)
				temp = temp->next;
			
			deleting_element = temp->next;
			temp->next = nullptr;
			size--;
			delete deleting_element;
		}			
        	return (deleting_element == nullptr);    
    	}
        
    	bool reverse_list()
    	{
		if(head == nullptr)
		{
			std::cout<<"no elements in the list";
			return false; 
		}
		
		Node *prev = nullptr,*current = head,*next = nullptr;

		/*
		 *0  1  2  3  4 
		 *1->2->3->4->5
		 *1st iteration: {nullptr}<-{1} {2}->{3}->{4}->{5}
		 *2nd iteration: {nullptr}<-{1}<-{2} {3}->{4}->{5}				
		 */
		
		while(current != nullptr)
		{
			next = current->next;
			current->next = prev;
			prev = current;
			current = next;
		}
		
        	head = prev;
		return (head != nullptr);    
    	}
	
	int get_size()
	{
		return size;
	}

    private:
        //static int size;
        Node *head = nullptr;        
};

int main()
{
	LinkedList *list =new LinkedList();
	
	for(int i=0;i<10;i++)
	{
		if(!list->add_node(i))
		{
			std::cout<<"error occured while inserting"<<std::endl;	
		}
	}

	list->display_list();
	std::cout<<"Size: "<<list->get_size()<<std::endl;
	list->add_node(4,45);
    	list->display_list();
	std::cout<<"Size: "<<list->get_size()<<std::endl;
	
	list->reverse_list();
	list->display_list();

	list->reverse_list();
	list->display_list();
	
	return 0;
}
