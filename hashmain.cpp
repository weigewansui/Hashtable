/**
 * 	hashmain.s
 */
#include "buildhash.h" // Keep all templated code in one file
#define MYKEY Key
#define MYVALUE Value
// Date function
int getday_blah(int month, int day);
int main()
{
 HASHTABLE<MYKEY, MYVALUE> *ht;
 MYKEY key;
 MYVALUE value;
 cout << "1.\n";

		key.name        = "Key_sad";
		key.country     = "Key_xsdas";
		key.owner       = "Key_oeners";

 //----------------------test build hash table--------------------------
 build_hashtable(&ht); // Build the hashtable with student's function

 cout <<"------------------------test build hashtable-------------------\n";
MYVALUE hhhhhh = get<MYKEY,MYVALUE>(ht,key);

print_value(hhhhhh);

//put works well
//print_key works well
//print_value works well
MYKEY def_key;
MYVALUE def_val;


		def_key.name        = "222";
		def_key.country     = "xasas";
		def_key.owner       = "dasdasd";
		
		def_val.country     = "dsadas";
		def_val.owner       = "2sdasdas";
		def_val.purpose     = "shee lj";
		def_val.orbit_class = "djasdhjaksdjkasd";
		
		def_val.orb.Long    = "dsreje";
		def_val.orb.perigee = "funsdasda";
		def_val.orb.apog    = "dwsdasd";
		def_val.orb.ecce    = "dssss";
		def_val.orb.incl    = "54d2sda";
		def_val.orb.period  = "dadasd";
		put<MYKEY,MYVALUE>(ht,def_key,def_val);

		 print_value(def_val);

//contains works well;
MYKEY def_key1;
MYVALUE def_val1;


		def_key1.name        = "222";
		def_key1.country     = "xasas";
		def_key1.owner       = "dasdasd";
		
		def_val1.country     = "dsadas";
		def_val1.owner       = "2sdasdas";
		def_val1.purpose     = "shee lj";
		def_val1.orbit_class = "djasdhjaksdjkasd";
		
		def_val1.orb.Long    = "dsreje";
		def_val1.orb.perigee = "funsdasda";
		def_val1.orb.apog    = "dwsdasd";
		def_val1.orb.ecce    = "dssss";
		def_val1.orb.incl    = "54d2sda";
		def_val1.orb.period  = "dadasd";
cout <<"---------------------Test contains:-------------\n"<<contains(ht, def_key1)<<endl;


//test isequal  -----------------works good

cout <<"--------------------Test isequal:--------------\n" <<isequal(def_key,def_key1)<<endl;
MYVALUE test_val = get<MYKEY,MYVALUE>(ht,def_key1);

//test get
cout <<"-------------------------Test get()--------------------------\n";
print_value(test_val);


//----------------------Test Reading data----------------------------
		MYKEY test_r;
		test_r.name        = "AAUSat-3";
		test_r.country     = "Denmark";
		test_r.owner       = "Aalborg University";

cout<<"********************Test data retrieval 1:***************************************\n";

MYVALUE hhhhhh2 = get<MYKEY,MYVALUE>(ht,test_r);
print_key(test_r);
print_value(hhhhhh2);


//----------------------Test Reading data----------------------------
		test_r;
		test_r.name        = "Aerocube 4.5A";
		test_r.country     = "USA";
		test_r.owner       = "Aerospace Corporation";

cout<<"********************Test data retrieval 2:***************************************\n";

hhhhhh2 = get<MYKEY,MYVALUE>(ht,test_r);
print_key(test_r);
print_value(hhhhhh2);


//----------------------Test Reading data----------------------------
		test_r;
		test_r.name        = "Apstar 1";
		test_r.country     = "China (PR)";
		test_r.owner       = "APT Satellite Holdings Ltd.";

cout<<"********************Test data retrieval 1:***************************************\n";

hhhhhh2 = get<MYKEY,MYVALUE>(ht,test_r);
print_key(test_r);
print_value(hhhhhh2);




 //cout << "2.\n";
 // Now test get, put, and contains functions for NTSB data.
 //
//  key.month=1;key.date=30;key.year=2012;
//  key.acc_num = "WPR12LA085";
//  value = get<MYKEY, MYVALUE>(ht,key);
//  cout << "First retrieval:\n";
//  print_key(key); print_value(value);
//  key.month=7;key.date=23;key.year=2010;
//  key.acc_num = "CEN10FA465";
//  value = get<MYKEY, MYVALUE>(ht,key);
//  cout << "\nSecond retrieval:\n";
//  print_key(key); print_value(value);
//  // Put entries in hashtable. Test contains first - but purposely
//  // try to put existing entry in hashtable anyhow (!).

//  // Test #1: Try to re-insert current key/value table entry.
//  if (contains<MYKEY, MYVALUE>(ht, key))
//  cout << "First contains test true - correct.\n";
//  else
//  cout << "First contains test false - incorrect.\n";
//  put<MYKEY, MYVALUE>(ht, key, value);
//  // Test #2: Create and insert new entry not already in table
//  key.month=3;key.date=5;key.year=2000;
//  key.acc_num = "BLAH12345";
//  value.year = 1976; value.location = "Wave Field"; value.make = "Sopwith";
//  value.model = "Camel";
// // Other value fields unchanged
//  if (contains<MYKEY, MYVALUE>(ht, key))
//  cout << "Second contains test true - incorrect.\n";
//  else
//  cout << "Second contains test false - correct.\n";
//  put<MYKEY, MYVALUE>(ht, key, value);
//  // Now test ability to retrieve new entry
//  value.location = "BLAHBLAHBLAH";
//  value = get<MYKEY, MYVALUE>(ht, key);
//  cout << "\nFinal get test:\n";
//  print_key(key); print_value(value);

//  return 0;
// }
// int getday_blah(int month, int day)
// {
//  int mydate = 0;
//  int DaysInMonths[] = {31,29,31,30,31,30,31,31,30,31,30,31};
//  if ((month>12)||(month<1)||(day<1)||(day>31))
//  return 0;
//  if (month==1) return (day-1);
//  else {
//  for (int i=0;i<(month-1);i++)
//  mydate += DaysInMonths[i];
//  mydate += day;
//  mydate -= 1;
//  return mydate;
//  }
}
