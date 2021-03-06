/**
 *  buildhash.cpp
 *  Wei Ding
 *  03597803
 *
 * Aero 552
 * HW2
 */
#include <fstream>
#include "satdata.h"
#include <vector>

//split strings
vector<string> explode(const string& str, const char& ch) {
    string next;
    vector<string> result;

    // For each character in the string
    for (string::const_iterator it = str.begin(); it != str.end(); it++) {
        // If we've hit the terminal character
        if (*it == ch) {
            // If we have some characters accumulated
            if (!next.empty()) {
                // Add them to the result vector
                result.push_back(next);
                next.clear();
            }
        } else {
            // Accumulate the next character into the sequence
            next += *it;
        }
    }
    if (!next.empty())
         result.push_back(next);
    return result;
}

template <class KEY, class VALUE>
 VALUE get(HASHTABLE<KEY,VALUE> *ht, KEY k){
 	HASHTABLE<KEY,VALUE> *tmp = ht[hashfunc(ht,k)].next;
 	if (contains(ht,k))
 	{
 		while(tmp!=NULL){

 			if (isequal(tmp->key,k))
 				return tmp->value;
 			tmp = tmp->next;

 		}
 	}else{
 		cout <<"Cannot be found!\n";
 		VALUE z_v;
 		return z_v;
 	}
 }

template <class KEY,class VALUE>
 bool contains(HASHTABLE<KEY,VALUE> *ht, KEY k){
 	//tmp point to the  root
 	HASHTABLE<KEY,VALUE> *tmp;

 	for (tmp = ht[hashfunc(ht,k)].next; tmp != NULL; tmp=tmp->next)
 	{
 		if(isequal(k,tmp->key))
 			return true;
 	}
 	return false;
 }

template <class KEY, class VALUE>
 /**
  * insert into head of the list
  * @param ht pointer points to the data structure
  * @param k  [description]
  * @param v  [description]
  */
 
 // ht is a array of address, defined in buildhashtable;
 // *ht points to the first node of HASHTABLE
 // *(ht+index) points to the next one that is pushed in the HASHTABLE;
 // so index linked with the pushed element
 void put(HASHTABLE<KEY,VALUE> *ht, KEY k, VALUE v){
 	if (!contains(ht,k))
 	{
		HASHTABLE<KEY,VALUE> *tmp;
		int index             = hashfunc(ht,k); //need to be defined
		tmp                   = ht[index].next; //the ht store the beginning address of HASHTABLE
												//it will let ht+index store the 
		ht[index].next        = new HASHTABLE<KEY,VALUE>; //directly allocate ht[].next as a new hash table
		ht[index].next->key   = k; //equals to *(ht+index); ht is a array point to different node of HASHTABLE
		ht[index].next->value = v;
		ht[index].next->next  = tmp;
 	}
 }

/*-------------------------------------------------------------------------------*/
template <class KEY, class VALUE>
int hashfunc(HASHTABLE <KEY,VALUE> * ht, KEY k)
{
 	int index=0;
 	int ASCI1=0;
 	int ASCI2=0;
 	int ASCI3=0;

 	for (int i = 0; i < k.name.length(); ++i)
 	{
 		ASCI1 += k.name[i];
 	}
 	 	
 	for (int i = 0; i < k.country.length(); ++i)
 	{
 		ASCI2 += k.country[i];
 	}

 	for (int i = 0; i < k.owner.length(); ++i)
 	{
 		ASCI3 += k.owner[i];
 	}
 	// for (int i = k.name.length()-1; i >= 0; i--)
 	// {
 	index = (779*ASCI1+377*ASCI2+23*ASCI3)%1236;
 	// }


 	// index = (k.name+ 31 * k.country + 137 * k.owner)%1236;

return index;
}

template <class KEY>
bool isequal(KEY k1, KEY k2)
{
 if(k1.name==k2.name && k1.country==k2.country && k1.owner==k2.owner) {
 return 1;
 } else return 0;
}

template<class KEY>
void print_key(KEY &k){
	cout 	<<"satellite name 		: "<<k.name<<endl
			<<"country of operator 	: "<<k.country<<endl
			<<"operator 		: "<<k.owner<<endl;
}

template <class VALUE>
void print_value(VALUE &v){
	cout 	<<"Purpose of use  : "<<v.purpose<<endl
			<<"Class of Orbit  : "<<v.orbit_class<<endl
			<<"Orbit Elements:"<<endl
			<<"	Longitude of GEO: "<<v.orb.Long<<endl
			<<"	Perigee  	   	: "<<v.orb.perigee<<endl
			<<"	Apogee 		   	: "<<v.orb.apog<<endl
			<<"	Eccentricity   		: "<<v.orb.ecce<<endl
			<<"	Inclination 		: "<<v.orb.incl<<endl
			<<" 	Period 			: "<<v.orb.period<<endl;
}


void build_hashtable(HASHTABLE<Key,Value> ** ht)
{
	*ht=new HASHTABLE<Key,Value>[1236];

	Key def_key; 
	Value def_val;

	// 	def_key.name        = "Key_sad";
	// 	def_key.country     = "Key_xsdas";
	// 	def_key.owner       = "Key_oeners";
		
	// 	def_val.country     = "dsadas";
	// 	def_val.owner       = "2sdasdas";
	// 	def_val.purpose     = "shee lj";
	// 	def_val.orbit_class = "djasdhjaksdjkasd";
		
	// 	def_val.orb.Long    = "dsreje";
	// 	def_val.orb.perigee = "funsdasda";
	// 	def_val.orb.apog    = "dwsdasd";
	// 	def_val.orb.ecce    = "dssss";
	// 	def_val.orb.incl    = "54d2sda";
	// 	def_val.orb.period  = "dadasd";
	// 	put<Key,Value>(*ht,def_key,def_val);


	ifstream input;
	input.open("UCS_Satellite_Database_8-1-14.txt");
	string data;
	string buffer;
	    
	// Don't need the first line;
	getline(input, buffer);

	    while(!input.eof()) {

	    	getline(input,def_key.name,'\t');
	    	getline(input,def_key.country,'\t');
	    	getline(input,def_key.owner,'\t');
	    	getline(input,buffer,'\t');
	    	def_val.country = def_key.country;
	    	def_val.owner	= def_key.owner;
	    	getline(input,def_val.purpose,'\t');
	    	getline(input,def_val.orbit_class,'\t');
	    	getline(input,buffer,'\t');
	    	getline(input,def_val.orb.Long,'\t');
	    	getline(input,def_val.orb.perigee,'\t');
	    	getline(input,def_val.orb.apog,'\t');
	    	getline(input,def_val.orb.ecce,'\t');
	    	getline(input,def_val.orb.incl,'\t');
	    	getline(input,def_val.orb.period,'\t');
	    	getline(input,buffer);

	    	//getline(input,data,'\t')
	    	//get every line of the file
	            //split into arrays
	            
	   //          getline(input, data);
	   //          vector<string> result = explode(data, '\t');
				// def_key.name        = result[0];
				// def_key.country     = result[1];
				// def_key.owner       = result[2];
				
				// def_val.country     = def_key.country;
				// def_val.owner       = def_key.owner;
				// def_val.purpose     = result[4];
				// def_val.orbit_class = result[5];
				
				// def_val.orb.Long    = result[7];
				// def_val.orb.perigee = result[8];
				// def_val.orb.apog    = result[9];
				// def_val.orb.ecce    = result[10];
				// def_val.orb.incl    = result[11];
				// def_val.orb.period  = result[12];

				//push into the hush table
				put<Key,Value>(*ht,def_key,def_val);
	    }
	    input.close();

}





