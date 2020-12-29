#include <iostream>

using namespace std;


void console(string message){
  cout << message << "\n";
}

struct Node {
  int valor;
  Node *next;
};

class SinglyLinkedList{
  public:
    int size;
    Node *tail;
    Node *head;
    SinglyLinkedList(){
			size = 0;
			head = nullptr;
			tail = nullptr;
    }
		int getSize(){
			return this->size;
		}
    void AddAtLast(int x){
			Node *tmp = new Node;
			tmp->valor = x;
			tmp->next = nullptr;
			if(head == nullptr){
					head = tmp;
					tail = tmp;
					this->size++;
			}else{
					tail->next = tmp;
					tail = tail->next;
					this->size++;
			}
    }

    void showAll(){
			Node *tmp = new Node();
			tmp = this->head;
			while(tmp != nullptr){
					cout << tmp->valor << "-";
					tmp = tmp->next;
			}
			cout << '\n';
    }

    void addAtFront(int value){
      Node *inserted = new Node();
      inserted->valor = value;
      inserted->next = nullptr;
      Node *tmp = new Node();
      tmp = this->head;
      if(head == nullptr){
        head = inserted;
        tail = inserted;
        this->size++;
      }else{
        inserted->next = tmp;
        this->head = inserted;
        this->size++;
      }
    }

    void addAtIndex(int index, int value){
			if(index < 0  || index > this->size){
				cout << "Out of Range" << "\n";
				return;
			}
			Node *inserted = new Node();
			inserted->valor = value;
			inserted->next = nullptr;
			Node *tmp = new Node();
			tmp = this->head;
			if(index == 0){
				this->addAtFront(value);
			}else if(index == size){
				this->AddAtLast(value);
			}else{
				for(int i = 0; i < index -1; i++){
					tmp = tmp->next;
				}
				inserted->next = tmp->next;
				tmp->next = inserted;
				this->size++;
			}
    }
		Node* searchByIndex(int position){
			Node* tmp = new Node();
			tmp = this->head;

			for(int i = 0; i < position; i++){
				tmp = tmp->next;
			}
			return tmp;
		}
		void deleteByIndex(int position){
			Node* tmp = new Node();
			tmp = this->head;

			if(position == 0){
				this->deleteAtFront();
			}else if(position == this->getSize()-1){
				this->deleteAtTail();
			}else{
				for(int i = 0; i < position - 1; i++){
					tmp = tmp->next;
				}
				Node *nextNode = tmp->next->next;
				delete tmp->next;
				tmp->next = nextNode;
				this->size--;
			}
		}
		void deleteAtFront(){
			Node* tmp = new Node();
			tmp = this->head;

			this->head = tmp->next;
			delete tmp;
			this->size--;
		}
		void deleteAtTail(){
			Node* tmp = new Node();
			tmp = this->head;
			for(int i = 0; i < this->getSize() - 2; i++){
				tmp = tmp->next;
			}
			Node* deleteNode = tmp->next;
			tail = tmp;
			delete deleteNode;
			tail->next = nullptr;
			this->size--;
		}
};

int main(){
    SinglyLinkedList *list = new SinglyLinkedList();
		list->AddAtLast(12);
		list->AddAtLast(13);
		list->addAtIndex(1,10);
		list->addAtIndex(3,15);
		list->deleteAtTail();
		list->deleteAtTail();
		list->deleteByIndex(0);
		list->deleteByIndex(0);
		// Node* node = list->searchByIndex();
		// cout << node->valor << "\n";
		list->showAll();
}
