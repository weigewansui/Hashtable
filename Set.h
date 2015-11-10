/**
 *  Set.h
 *  Assignment 2
 *  Problem II-1
 *
 *  Wei Ding
 *  03597803
 */
#ifndef SET_H
#define SET_H
#include <iostream>
using namespace std;
    struct inlist{
        int element;
        inlist *next; 
    };


class Set {
  private:
    //int size;
    // linked list
    inlist list;
    inlist *root;
    // inlist list;
    // int size;
  public:
    Set();
    Set(const Set&); //Copy constructor
    // ~Set();
    int test();

    Set operator =(const Set&);
    Set operator +(const Set&);//set union
    Set operator -(const Set&);//set difference

    bool is_element(int);
    void insert(int);
    void erase(int);

    friend ostream & operator << (ostream&, const Set &);
    friend Set sunion(Set, Set);//set union
    friend Set sintersection(Set a, Set b);// intersection

};

#endif