// Author: Yaðýz Bartu Arslan - Junior Computer Engineering Student at Sabanci University
// Written at:  17.12.2923


#include <iostream>
using namespace std;
struct Node {
	int val;
	Node* next;
};



class LinkedListSet {

public:
	LinkedListSet(); // the constructor, head will be nullptr in the initialization.
	LinkedListSet& operator+=(const LinkedListSet& set); // set union operator
	LinkedListSet& operator-(int value); //deletion operator (-)
	LinkedListSet& operator+(int value); //insertion operator (+)
	LinkedListSet& operator-=(const LinkedListSet& otherSet); // set difference
	LinkedListSet& operator&=(const LinkedListSet& otherSet); // set intersection
	void display() const; // displays the set in the given format.
	bool doesContains(int value) const;

private:
	Node* head;
};

LinkedListSet::LinkedListSet() {
	head = nullptr;
}





// functions implementation below here.
// first begin with insertion (easy oldugu icin)
LinkedListSet& LinkedListSet::operator+(int value) {
	// first check the nullptr case then implement the code
	Node* newNode = new Node;
	newNode->val = value;
	newNode->next = nullptr;

	if (!this->doesContains(value)) {
		if (head == nullptr) {
			head = newNode;
		}

		else if (head->val > value) {
			newNode->next = head;
			head = newNode;
		}


		else {
			Node* ptr = head;
			//Node* newNode = new Node;

			while ((ptr->next) && (ptr->next->val < value)) {
				ptr = ptr->next;
			}
			newNode->next = ptr->next;
			ptr->next = newNode;
			//newNode->val = value;
		}
	}
	return *this;
}

LinkedListSet& LinkedListSet::operator-(int value) { // deletion operator (-)
	Node* temp;
	if (head == nullptr) { // empty list case
		return *this;
	}
	else if (head->val == value) { // head is the node to be deleted
		temp = head;
		head = head->next;
		delete temp;
		return *this;
	}
	else { // rest of the all cases
		temp = head; // for traversing the list, we will need this guy.
		while (temp->next) { //check whether nullptr
			if (temp->next->val == value) { //detect the guy that contains the wanted value
				Node* ptr = temp->next; // for the deleted node we re-shape the list with this guy.
				temp->next = temp->next->next; // re-shaping it
				delete ptr;
			}
			else {
				temp = temp->next; // traverse the list with "ptr"
			}
		}
	}
	return *this;
}

LinkedListSet& LinkedListSet::operator+=(const LinkedListSet& otherSet) {
	Node* temp = otherSet.head;  //set temp as the otherSet's head.
	// check whether it is in the set or not.
	while (temp) {
		if (!this->doesContains(temp->val)) {
			// insert the node to the new set.
			this->operator+(temp->val);
		}
		temp = temp->next;
	}
	//return the new set (lhs)
	return *this;
}

bool LinkedListSet::doesContains(int value) const {
	Node* temp = head;
	while (temp) { // begin to traverse
		if (temp->val == value) {
			return true;
		}
		temp = temp->next;
	}

	// else return false;
	return false;
}

//LinkedListSet& LinkedListSet::operator-=(const LinkedListSet& otherSet) {
//	Node* temp = this->head;
//	while (temp) {
//		Node* nextNode = temp->next; // Save the next node
//		if (otherSet.doesContains(temp->val)) { // if the rhs include the element
//			this->operator-(temp->val); // remove it from lhs (this)
//		}
//		temp = nextNode; // Move to the next node
//	}
//	return *this; //return the new set.
//}

LinkedListSet& LinkedListSet::operator-=(const LinkedListSet& otherSet) {
	Node* current = this->head;
	Node* prev = nullptr;
	while (current != nullptr) {
		if (otherSet.doesContains(current->val)) { // if the rhs include the element
			Node* nextNode = current->next; // Save the next node
			if (prev == nullptr) { // Deleting the head node
				this->head = nextNode;
			}
			else { // Deleting a node after the head
				prev->next = nextNode;
			}
			delete current; // Delete the current node
			current = nextNode; // Move to the next node
		}
		else {
			prev = current;
			current = current->next;
		}
	}
	return *this; //return the new set.
}



LinkedListSet& LinkedListSet::operator&=(const LinkedListSet& otherSet) {// set intersection
	int count1 = 0; // define the "count" variable for iterating twice the list. this is for the lhs set
	int count2 = 0; // this count is for rhs set
	Node* ptr = this->head;
	Node* temp = otherSet.head;
	LinkedListSet resultSet;

	Node* temp1 = this->head;
	Node* temp2 = otherSet.head;
	while (ptr) { // count the elements in set lhs
		ptr = ptr->next;
		count1++; // count is now the elements of the set -1
	}
	count1 = count1 + 1; // set -1 +1 = the numbers of element in set.


	while (temp) { // count the elements in set rhs
		temp = temp->next;
		count2++; // count is now the elements of the otherset -1 
	}

	count2 = count2 + 1; // set -1 +1 = the numbers of element in otherset.

	//iterate twice the loop in order to scan every element and the other set's element.
	for (int i = 0; i < count1; i++) {
		// temp2'nin nullptr olup olmadýðýný kontrol edin
		if (temp1 == nullptr) {
			break;
		}
		for (int j = 0; j < count2; j++) {
			//if set2deki eleman set1 de varsa onu lhs'ye yani this->e at
			//yoksa çýkar setten

			// temp2'nin nullptr olup olmadýðýný kontrol edin
			if (temp2 == nullptr) {
				break;
			}

			if (temp1->val == temp2->val) { //if equal (intersects) add to the new Set, which this
				resultSet = resultSet + temp1->val;
			}

			temp2 = temp2->next; // passing to the next node, iterating...
		}
		temp1 = temp1->next; // being ready to the iteration of the next element in the lhs

		//reset the temp2 to otherSet.head so that the iteration for the next element in the temp1 can be happening.
		temp2 = otherSet.head;
	}
	*this = resultSet; // update this to be the resultSet
	return *this; //return the new set.
}


void LinkedListSet::display() const {
	if (head == nullptr) {
		cout << "LinkedListSet is empty";
	}
	else {
		Node* temp = head;
		cout << "LinkedListSet{";
		while (temp) {
			cout << temp->val << ", ";
			temp = temp->next;
		}
		cout << "}";
	}
	cout << endl;
}







int main() {

	// Example usage
	LinkedListSet set1;
	set1 + 1 + 2 + 3 + 17; // Insertion
	set1.display();

	set1 - 2; // Deletion --> {1,3,17}
	set1.display();

	LinkedListSet set2;
	set2 + 3 + 4 + 5;
	set2.display(); // {3,4,5}

	set2 += set1 + 7 + 3 + 19; //Insertion with multiple right-hand values
	set2.display();

	LinkedListSet set3;
	set3 + 3 + 4 + 7 + 17 + 41;
	set3.display();

	LinkedListSet set4;
	set4 + 41 + 37 + 7 + 19 + 41;
	set4.display();

	// Set Union
	set1 += set2;
	set1.display();

	// Set Difference
	set1 -= set3;
	set1.display();

	// Set Intersection
	set1 &= set4;
	set1.display();

	return 0;
}
