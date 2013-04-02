/*
Jaska B
1 April 2013

Part two of the data pipeline: Parse each JSON in the JSON_DIR and determine the item's
latest and (presumably) current price. 

This was formerly accomplished in PHP by parsing the JSON as an array object ($obj), which
returns a multi-dimensional array with two entries - "daily[]" and "average[]".

We don't care about the average price at all, so what we need is: end($obj['daily']);

This is possible to obtain in C/C++, of course, since after all PHP is written in C - 
it will just be a bit more tricky manipulating each parsed JSON input!

Jaska B
2 April 2013

Note that as long as the jsoncpp library is the most viable solution, the program simply cannot be pure C!

The JSON::Value type interprets the parsed input file as an objectValue (enum 7) rather than an array.
Thus, it is necessary to store all the keys ("Members") in a std::vector<std::string> - luckily
that is possible because the function Json::Value::getMemberNames() returns such an object.

Vectors are zero-indexed in C++, but for whatever reason the latest price is at position 180.

Think about it - if it's 180 days, but zero-indexed, shouldn't the latest price be at position 179?

Nope, I guess JaGEx does 180 days starting from a "day 0" instead of "day 1" ... :P
*/

#include "stdafx.h"

using namespace std;

/* 
This is just a test function, believe it or not. It doesn't return anything (unless, of course, it fails). 
It does print stuff to the console, if you're interested. 
*/
bool itemID::testRead(unsigned long int id)
{
	char* resname = new char[256];
	sprintf(resname, "%s/%u.json", JSON_DIR, id);

	ifstream t(resname, ifstream::in); 
	if (!t) {return false;}
	string json((istreambuf_iterator<char>(t)), istreambuf_iterator<char>()); 
	t >> json;
	t.close();
	
	Json::Value root;
	Json::Reader reader;
	const char* key = "daily";

	bool success = reader.parse(json, root);
	if (!success)
	{
		printf("Failed to parse JSON for item %u!\r\n", id);
		return false;
	}

/*	vector<string> mem = root.getMemberNames();

	for (int i = 0; i<mem.size(); ++i)
	{
		cout << mem.at(i) << endl;
	} */


	/* extract the object member with key "daily" as we don't care about "average" */
	Json::Value daily = root.removeMember(key);
	/* fill this string vector with what are ultimately representations of daily price over time */
	vector<string> dm = daily.getMemberNames();

	/* 
	DEBUGGING PURPOSES ONLY - these commented-out blocks are only for testing purposes. Basically they tell you
	exactly what is going on behind the scenes, which was really useful while I was writing this...figuring out
	how to use jsoncpp without much help or documentation at all!
	
	This just spits out a bunch of long numbers (seconds since UNIX epoch actually)
	for (int i = 0; i<dm.size(); ++i)
	{
		cout << dm.at(i) << endl;
	} 

	if (daily.isArray())
	{
		// I don't think you should/will ever see this, actually. 
		cout << "It is an array - enum: " << daily.type() << endl;
	}
	else
	{
		// should say "7" which is "objectValue" a.k.a key/value pairs 
		cout << "It is NOT an array - enum: " << daily.type() << endl;
	}

	// This prints out ALL the information you could want to know, finally.
	// "Pos" is position in the vector (NOT array, a vector!)
	// "Date" is the amount of seconds since midnight on 1 Jan 1970 - no, seriously, it is.
	// "Price" is the amount of licks it takes to get to the centre of a Tootsie Pop. 
	for (int i = 0; i<dm.size(); i++)
	{
		cout << "Pos: " << i << " Date: " << dm.at(i) << " Price: " << daily[dm.at(i)] << endl;
	} */
	
	/* The database only contains prices for the last 180 days, meaning that we want the price contained in daily[dm.at(180)] :)*/

	cout << "Latest price for this item: " << daily[dm.at(180)] << endl;
	
	return true;
}