/*
Jaska B
17 April 2013

This ought to utilise the MySQL C++ connection driver to update the database
by replacing the gePrice and alchProfit values (or inserting values into all fields
and creating rows as needed should the table be empty for some reason).

This currently only works on Windows (and hasn't even been tested there too much either).

We'll see how this goes!
*/

#include "stdafx.h"
#include "db.h"

using namespace std;
using namespace sql;

