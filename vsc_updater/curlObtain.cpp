/*
Jaska
31 March 2013

Part one of the data pipeline is to simply obtain the latest data as actual JSON
files and save them to a directory which is created should it not exist.

The data will automatically be overwritten, unless you somehow don't have permission
to write there, in which case the program won't work anyway.
*/

#include "stdafx.h"

using namespace std;

bool itemID::fillFolder()
{
	DIR *jd;
	bool outcome;

	if ((jd = opendir(JSON_DIR)) == NULL) { mkdir(JSON_DIR); }

	for (int i = 0; i<sz; i++)
	{
		outcome = grab(idList[i]);

		if (outcome == true)
		{
			printf("Successfully fetched json data for item number %u.\r\n", idList[i]);
		}
		else
		{
			printf("Failed grabbing json for item number %u!\r\n", idList[i]);
		}
	}
	return true;
}

bool itemID::grab(unsigned long int id)
{
    CURL *curl;
    CURLcode res;

	char* initial = "http://services.runescape.com/m=itemdb_rs/api/graph/";
	char* url = new char[256];
	char* resname = new char[256];

	sprintf(url, "%s%u.json", initial, id);
	sprintf(resname, "%s/%u.json", JSON_DIR, id);

	FILE *out = fopen(resname, "w");
 
    curl = curl_easy_init();

    if(curl)
    {
      curl_easy_setopt(curl, CURLOPT_URL, url);
	  curl_easy_setopt(curl, CURLOPT_WRITEDATA, out);
      curl_easy_setopt(curl, CURLOPT_HEADER, 0);
 
      res = curl_easy_perform(curl);

      if(res != CURLE_OK) 
	  {
        fprintf(stderr, "curl_easy_perform() failed: %s\n",
                curl_easy_strerror(res));
		return false;
	  }
 
	  curl_easy_cleanup(curl);
	  return true;
    }
	else if (!curl) 
	{
		printf("curl initialization failed!\r\n");
		return false;
	}	
}
