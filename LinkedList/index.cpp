#include <iostream>

using namespace std;


void console(string message){
  cout << message << "\n";
}
template <typename T>
struct Node {
  T valor;
  Node *next;
};
template <class U>
class SinglyLinkedList{
  public:
    int size;
    Node<U> *tail;
    Node<U> *head;
    SinglyLinkedList(){
			size = 0;
			head = nullptr;
			tail = nullptr;
    }
		int getSize(){
			return this->size;
		}
    void AddAtLast(U x){
			Node<U> *tmp = new Node<U>();
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
			Node<U> *tmp = new Node<U>();
			tmp = this->head;
			while(tmp != nullptr){
				cout << tmp->valor << "-";
				tmp = tmp->next;
			}
				cout << '\n';
    }

    void addAtFront(U value){
      Node<U> *inserted = new Node<U>();
      inserted->valor = value;
      inserted->next = nullptr;
      Node<U> *tmp = new Node<U>();
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

    void addAtIndex(int index, U value){
			if(index < 0  || index > this->size){
				cout << "Out of Range" << "\n";
				return;
			}
			Node<U> *inserted = new Node<U>();
			inserted->valor = value;
			inserted->next = nullptr;
			Node<U> *tmp = new Node<U>();
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
		Node<U>* searchByIndex(int position){
			Node<U>* tmp = new Node<U>();
			tmp = this->head;

			for(int i = 0; i < position; i++){
				tmp = tmp->next;
			}
			return tmp;
		}
		void deleteByIndex(int position){
			Node<U>* tmp = new Node<U>();
			tmp = this->head;

			if(position == 0){
				this->deleteAtFront();
			}else if(position == this->getSize()-1){
				this->deleteAtTail();
			}else{
				for(int i = 0; i < position - 1; i++){
					tmp = tmp->next;
				}
				Node<U> *nextNode = tmp->next->next;
				delete tmp->next;
				tmp->next = nextNode;
				this->size--;
			}
		}
		void deleteAtFront(){
			Node<U>* tmp = new Node<U>();
			tmp = this->head;

			this->head = tmp->next;
			delete tmp;
			this->size--;
		}
		void deleteAtTail(){
			Node<U>* tmp = new Node<U>();
			tmp = this->head;
			for(int i = 0; i < this->getSize() - 2; i++){
				tmp = tmp->next;
			}
			Node<U>* deleteNode = tmp->next;
			tail = tmp;
			delete deleteNode;
			tail->next = nullptr;
			this->size--;
		}
};

bool isPalindrome(string message){
  SinglyLinkedList<char> *list = new SinglyLinkedList<char>();

	for(size_t i{0}; i < message.length(); i++){
		list->AddAtLast(message.at(i));
	}

	for(size_t i{0}; i < list->getSize(); i++){
		if(list->searchByIndex(i)->valor != list->searchByIndex((list->getSize() - 1) - i)->valor){
			return false;
		}
	}

	return true;
}

int main(){
	string message{"aca"};

	bool response = isPalindrome(message);
	cout << (response ? "é um palindromo" : "n é um palindromo") << "\n";
}
