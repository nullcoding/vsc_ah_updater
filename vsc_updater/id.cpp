/*
Jaska
31 March 2013

Constructor / Initializer data for the main class interface
*/

#include "stdafx.h"

using namespace std;

itemID::itemID() 
{
}

itemID::~itemID()
{
}

const unsigned long int itemID::idList[] = 
{
561,
7936,
1317,
1111,
1271,
1123,
1073,
1091,
1397,
3749,
2497,
25800,
13736,
25796,
8,
11126,
11118,
14497,
1215,
1149,
1305,
1434,
4585,
4587,
1249,
4153,
25794,
4920,
10828,
859,
861,
851,
4103,
4093,
1403,
25798,
6130,
15505,
15507,
1319,
1373,
4131,
1113,
9185,
1213,
1163,
3202,
1359,
1147,
1201,
1303,
1432,
1275,
1127,
1079,
1093,
1333,
1247,
1185,
1289,
1347,
9431,
11113,
13734,
4968,
1395,
847,
855,
};

// define the size of the array as a constant - this may vary by OS
const int itemID::sz = sizeof(idList) / sizeof(idList[0]);