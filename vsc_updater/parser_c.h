#ifndef PARSER_C_H_INCLUDED
#define PARSER_C_H_INCLUDED

#include "json.h"

void print_json_value(json_object *jobj);

void json_parse_array( json_object *jobj, char *key);

void json_parse(json_object * jobj);

#endif

