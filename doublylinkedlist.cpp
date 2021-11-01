//list Functions implementation on circular doubly linked list
//Author: Rahimullah Shaheen

#include <iostream>

using namespace std;


//logic for body of node
struct Node{
	int value;
	Node* next;
	Node* previous;
};


//linked list class
class linked{
	private:
		Node *head, *tail,*temp;
	public:linked(){
		head = NULL;
		tail = NULL;
	}
	
	// logic for adding nodes
	void add_node(int n){
		Node *newNode = new Node;
		newNode->value = n;
		newNode->previous = NULL;
		newNode->next = NULL;
		
		if(head == NULL){
			head = newNode;
			tail = newNode;
		}
		else{
			tail->next = newNode;
			temp = tail;
			tail = tail->next;
			
			tail->previous = temp;
		}
		head->previous = tail;
		tail->next = head;

	}
	
	//add at specigic position
	void add_p(int i,int value){
	int count = 0;
	Node* temp;
	Node* newNode = NULL;
	newNode = new Node();
	Node *ptr = get_head();
	while( ptr != get_tail()){
		if(count==i)
		break;
		count ++;
		ptr = ptr->next;
	}
	if(ptr == NULL){
		cout<<"invalid index entry"<<endl;
	}
	else{
	temp = ptr->next;
	ptr->next = newNode;
	newNode->previous = ptr;
	newNode->next = temp;
	temp->next->previous = newNode;
	newNode->value= value;
	}
}
	
		// getter for head
	Node* get_head(){
		return head;
	}
	Node* get_tail(){
		return tail;
	}
	
	
	//add at the head
	void add_head(int n){
		Node *newNode = new Node;
		newNode->value = n;
//		newNode->previous = NULL;
		newNode->next = get_head();
		head->previous = newNode;
		head = newNode; 
		head->previous = tail;
		
	}
	//add at the tail
		void add_tail(int n){
		Node *newNode = new Node;
		newNode->value = n;
		newNode->previous = get_tail();
		newNode->next = head;
		tail->next = newNode; 
		tail = newNode;		
	}

	//logic to remove node
void specific(int i, Node *ptr){
	Node *temp;
	int count = 0;
	temp=ptr;
	while(ptr->next!=get_tail()){
		count++;
		if(count==i-1)
			break;
		ptr=ptr->next;

	}
	if(count==0 || ptr->next==NULL)
	cout<<"invalid index entry"<<endl;

	else{
	temp=ptr->next->next;
	temp->previous=ptr;
	delete ptr->next;
	ptr->next=temp;
	}
}

	//remove at the end
	void remove_tail(){
	Node *temp;
	temp = get_tail();
	tail = temp->previous;
	tail->next = head;
	delete temp;
}
	//remove at the head
	void remove_head(){
	Node *temp;
	temp = get_head();
	head = temp->next;
	head->previous = tail;
	delete temp;
}
	
	//logic to display list
	void display(Node* point){
		while(point->next != get_tail()){
		cout<<point->value<<endl;
		point = point->next;
	}
	cout<<point->value<<endl;
	point = point->next;
	cout<<point->value<<endl;
}
	
	
};


int main(){

	Node *ptr;
	linked l;
	
	for(int i= 1;i<10;i++){
		l.add_node(i);
	}
	ptr = l.get_tail();
	int op= 1;
	int v;
	int p;
	do{
		cout<<"\n\nchoose your option"<<endl<<endl;
		cout<<"Add Node at the begining press: (1)"<<endl;
		cout<<"Add Node at the specific location press (2)"<<endl;
		cout<<"Add NOde at the end press (3)"<<endl;
		cout<<"Delete Node at the bigining press (4)"<<endl;
		cout<<"Delete Node at the end press (5)"<<endl;
		cout<<"Delete Node at the specific location press (6)"<<endl;
		cout<<"To Display list press (7)"<<endl;
		cout<<"To exit press (0)"<<endl;
		cin>>op;

		switch (op){
			case 1:{
				cout<<"Enter value"<<endl;
				cin>>v;
				l.add_head(v);
				break;
				}
				
			case 2:{
				cout<<"Enter position and value"<<endl;
				cin>>p;
				cin>>v;
				l.add_p(p,v);
				break;
			}
			case 3:{
				cout<<"Enter value"<<endl;
				cin>>v;
				l.add_tail(v);
				break;
			}	
			case 4:{
				l.remove_head();
				break;	
				}
				case 5:
				{
					l.remove_tail();
				break;	
				}
				case 6:
				{
					cout<<"Enter position"<<endl;
					cin>>p;
					l.specific(p,l.get_head());
				break;	
				}
				case 7:
				l.display(l.get_head());
				break;
			default:
			cout<<"Invalid Entry";	
		}
	}while(op!=0);

	return 0;
}
