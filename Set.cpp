/**
 * 	Set.cpp
 *	Assignment 2
 *	Problem II-1
 *
 * 	Wei Ding
 * 	03597803
 * 	
 */

#include "Set.h"

Set::Set(){
	root = NULL;
}
Set::Set(const Set &obj){
	
	list = obj.list;
	root = obj.root;

}
// Set::~Set(){

//   		delete root; 
//  }



Set Set::operator=(const Set &obj){

//this will make two set have the same address
	list = obj.list;
	root = obj.root;

	return *this;

	// Set c;
	// inlist* tmp = obj.root;
	// while(tmp != NULL){
	// 	c.insert((*tmp).element);
	// 	tmp = (*tmp).next;
	// }

	// return c;

}

bool Set::is_element(int x){

	if (root != NULL)
	{
	// Tmp to store the pointer in linked list
		inlist * tmp = root;
	//search for x in the list
		do
		{
			if (x == (*tmp).element)
				return true;
			tmp = (*tmp).next;
		} while (tmp != NULL);
	}

		return false;

}

void Set::insert(int x){
	//insert into the head;
	if (Set::is_element(x))
	{
		cout <<"It's already in the set!\n";
	} else {
		inlist* tmp =  new inlist();
		(*tmp).next = root;
		(*tmp).element = x;

		root = tmp;
	}
}

void Set::erase(int x){
	// pointer points to the first node
	//if it's in the set
	if (Set::is_element(x))
	{
		inlist *tmp = root;
		//if x is same as the head of the set
		if ((*tmp).element == x)
		{
			//overlap first node with the former set's second node
			root = (*tmp).next;
			//delete the second node
			delete tmp;
			return;
		}
		//move the pointer to the node before x
		while(((*tmp).next)->element!=x){
			tmp = (*tmp).next;
		}

		//copy the "next" in the deleting one to current pointer's "next"
		(*tmp).next = ((*tmp).next)->next;
		//Delete the node that tmp is pointing at
		return;
	} else {
		cout <<x<<"It is not in the set!\n";
		return;
	}
}

Set sunion(Set a, Set b){
	//set ret , initialized same as a;

	Set ret;
	// Set ret(a); would change at the end of this function
	// tmp to point to the nodes in b
	// inlist* tmp1 = b.root;
	// inlist* tmp2 = a.root;
	// while (tmp1 != NULL) {
	// 	while(tmp2 != NULL){
	// 		if ((*tmp))
	// 		{
	// 			/* code */
	// 		}
	// 	}
	// 	tmp1 = (*tmp1).next;
	// }

	//copy a to ret;
	inlist* tmp = a.root;
	while(tmp != NULL){
		ret.insert((*tmp).element);
		tmp = (*tmp).next;
	}

	// return c;

	inlist* tmp2 = b.root;
	while (tmp2 != NULL) {

		// if not in Set, insert
		if (!ret.is_element((*tmp2).element))
		{
			// if not exist, insert
			ret.insert((*tmp2).element);
		}
		// store the next node of b
		tmp2 = (*tmp2).next;
	}

	return ret;

}

Set sintersection(Set a, Set b){
	Set ret;
		inlist* tmp = b.root;
	while(tmp != NULL){
		if (a.is_element((*tmp).element))
		{
			ret.insert((*tmp).element);
		}
		tmp = tmp->next;
	}
	return ret;
}

Set Set::operator +(const Set& obj){
	return sunion(*this,obj);;
}

Set Set::operator -(const Set& obj){
	// get there intersection
	Set ret;
	Set xx = obj;
	//copy *this to ret
	inlist* tmp = (*this).root;
	while(tmp != NULL){
		if (!xx.is_element((*tmp).element))
		{
			ret.insert((*tmp).element);
		}
		tmp = (*tmp).next;
	}
	return ret;

}

int Set::test(){
	cout <<list.element;
}

ostream & operator <<(ostream &os, const Set &obj){

		if (obj.root != NULL)
		{	
			os << "{";
			//tmp point to the head
			inlist const *tmp = obj.root;
			do
			{
				os << (*tmp).element <<", ";
				tmp = (*tmp).next;
			} while (tmp != NULL);

			os << "\b\b";
			os << "}";
		}else{
			os <<"It's empty";
		}

		return os;	
}


