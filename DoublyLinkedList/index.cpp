#include <iostream>

using namespace std;

template <class T>
class Node {
  T value;
  Node *next;
	Node *prev;

	public:
	Node(T value, Node* prev, Node* next){
		this->value = value;
		this->next = next;
		this->prev = prev;
	}
	void setkey(T x){
		this->value = x;
	}
	void setNext(Node* nextNode){
		this->next = nextNode;
	}
	void setPrev(Node* prevNode){
		this->prev = prevNode;
	}
	T getValue(){
		return this->value;
	}
	Node* getNext(){
		return this->next;
	}
	Node* getPrev(){
		return this->prev;
	}
	~Node(){
		cout << "this node" << " " << this->getValue() << " " << "was deleted" << "\n";
	}
};

template <class U>
class DoublyLinkedList{
	size_t size;
	Node<U> *front;
	Node<U> *tail;
	public:
	DoublyLinkedList(){
		this->size = 0;

		this->front = nullptr;
		this->tail = nullptr;
	}
	size_t getSize(){
		return this->size;
	}
	Node<U>* getFront(){
		return this->front;
	}
	Node<U>* getTail(){
		return this->tail;
	}
	void pushBack(U value){
		if(isEmpty()){
			this->front = this->tail = new Node<U>(value, nullptr, nullptr);
		}else{
			this->tail->setNext(new Node<U>(value, this->tail, nullptr));
			this->tail = this->tail->getNext();
		}
		this->size++;
	}
	void printNodes(){
		Node<U> *tmp = this->front;
		while (tmp != nullptr){
			cout << "<<" << tmp->getValue() << ">>";
			tmp = tmp->getNext();
		}
		cout << "\n";
	}
	bool isEmpty(){
		return this->size == 0;
	}
	void pushFront(U value){
		if(isEmpty()){
			this->front = this->tail = new Node<U>(value, nullptr, nullptr);
		}else{
			this->front->setPrev(new Node<U>(value, nullptr, this->front));
			this->front  = this->front->getPrev();
		}
	}
};

int main(){
	DoublyLinkedList<int> *list = new DoublyLinkedList<int>();
	list->pushBack(12);
	list->pushFront(21);
	cout <<  (list->getTail()->getNext() == nullptr )<< "\n";

	list->printNodes();
	return 0;
}
