/**
 * 	satdata.h
 *
 * 	AE552 HW2
 * 	Wei Ding
 * 	03597803
 */

#include <iostream>
#include <cmath>
#include <string>

using namespace std;
template <class KEY, class VALUE>

struct HASHTABLE {
 	KEY key;
 	VALUE value;
 	struct HASHTABLE* next;
 };

struct Key {
	string name;
	string country;
	string owner;
};

// struct orb_element{
// 	double Long;
// 	int perigee;
// 	int apog;
// 	double ecce;
// 	double incl;
// 	double period;
// };

struct orb_element{
	string Long;
	string perigee;
	string apog;
	string ecce;
	string incl;
	string period;
};

struct Value {
	string country;
	string owner;
	string purpose;
	string orbit_class;
	//structure of orbital elements;
	orb_element orb;

};


template <class KEY, class VALUE>
VALUE get(HASHTABLE<KEY,VALUE> *ht, KEY k);

template <class KEY,class VALUE>
bool contains(HASHTABLE<KEY,VALUE> *ht, KEY k);

template <class KEY, class VALUE>
void put(HASHTABLE<KEY,VALUE> *ht, KEY k, VALUE v);

template <class KEY,class VALUE>
int hashfunc(HASHTABLE <KEY,VALUE> *ht, KEY k);

template <class KEY>
bool isequal(KEY k1, KEY k2);
