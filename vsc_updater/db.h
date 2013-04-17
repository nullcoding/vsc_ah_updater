#ifndef DB_H_INCLUDED
#define DB_H_INCLUDED

// referenced from http://dev.mysql.com/tech-resources/articles/mysql-connector-cpp.html

/* MySQL Connector/C++ specific headers */

#include <driver.h>
#include <connection.h>
#include <statement.h>
#include <prepared_statement.h>
#include <resultset.h>
#include <metadata.h>
#include <resultset_metadata.h>
#include <exception.h>
#include <warning.h>

#define DBHOST "tcp://127.0.0.1:3306"
#define USER "alcher"
#define PASSWORD "password"
#define DATABASE "vsc_a"

#endif