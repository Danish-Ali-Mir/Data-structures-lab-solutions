#include <iostream>
using namespace std;

struct Node{
	int marizID;
	Node* next;
	Node* prev;
	Node(int id){
		marizID = id;
		next = nullptr;
		prev = nullptr;
	}	
};

class HospitalSystem {
	private:
		Node* head;
		Node* tail;
		
	public:
		HospitalSystem (){
			head= nullptr;
			tail= nullptr;
		}
		
		void insertAThead (int id){
			Node* newMariz = new Node(id);
			newMariz->next = head;
			newMariz->prev = nullptr;
			
			if (head != nullptr){
				head->prev = newMariz;
			}
			else
				tail = newMariz;
			
			head = newMariz;
		}
		
		void insertATtail(int id){
			Node* newMariz= new Node(id);
			newMariz->next= nullptr;
			newMariz->prev= tail;
			
			if (tail != nullptr){
				tail->next= newMariz;
			}
			else
			{
				head = newMariz;
			}
			
			tail= newMariz;	
		}
		
		void insertatPOS(int id, int pos){
			if (pos <= 1 || head == nullptr){
				insertAThead(id);
				return;
			}
			
			Node* temp = head;
			for (int i= 1; i < pos -1 && temp->next != nullptr ; i++)
				temp = temp->next;
				
				if (temp->next == nullptr){
					insertATtail(id);
					return;
				}
				
			Node* newMariz = new Node(id);
			
			newMariz->next = temp->next;
			newMariz->prev= temp;
			temp->next->prev = newMariz;
			temp->next= newMariz;
		}	
		
		void deleteFROMstart(){
			if (head == nullptr){
				cout<<"The emergency room is empty "<<endl;
				return;
			}
			
			cout<<"removed mariz: "<< head->marizID<<endl;
			Node* temp= head;
			
			if (head == tail){
				head=nullptr;
				tail=nullptr;
			}
			else{
				head= temp->next;
				head->prev= nullptr;
			}
			delete temp; 	
		}
		
		void PrintMarizFROMstart(){
			Node* temp = head;
			cout<<"Start se : ";
			
			while(temp != nullptr){
				cout<<temp->marizID;
				if(temp->next != nullptr){
					cout<<"<->";
				}
				temp= temp->next;
			}
			cout<<"<-Tail\n";
		}
		
		void PrintMarizFROMend(){
			Node* temp = tail;
			cout<<"End se :";
			while(temp != nullptr){
				cout<<temp->marizID;
				if (temp->prev != nullptr){
					cout<<"<->";
				}
				temp= temp->prev;
			}
			cout<<"<-Head\n";
		}
};


int main() {
	
	HospitalSystem sys;
	
	sys.insertATtail(101);
	sys.insertATtail(102);
	sys.insertAThead(200);
	sys.insertatPOS(150,2);
	sys.PrintMarizFROMstart();
	sys.PrintMarizFROMend();
	cout<<endl;
	sys.deleteFROMstart();
	sys.PrintMarizFROMstart();
	
	cout<<endl;
	cout<<endl;
	
	sys.insertATtail(300);
	sys.PrintMarizFROMstart();
	sys.PrintMarizFROMend();
	
	return 0;
}