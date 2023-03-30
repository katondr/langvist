#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include <curl/curl.h>

static size_t write_data(void *ptr, size_t size, size_t nmemb, void *stream)
{
	size_t written = fwrite(ptr, size, nmemb, (FILE *)stream);
	return written;
}

int main(void)
{
	CURL *curl;
	CURLcode res;
	static const char *pagefilename = "page.out";
	FILE *pagefile;

	curl = curl_easy_init();
	curl_easy_setopt(curl, CURLOPT_URL, "https://www.gutenberg.org/files/1998/1998-0.txt");
	curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_data);

	//res = curl_easy_perform(curl);
	//if(res != CURLE_OK)
	//	fprintf(stderr, "curl_easy_perform() failed: %s\n",
	//			curl_easy_strerror(res));

	pagefile = fopen(pagefilename, "wb");
	if(pagefile) {
		curl_easy_setopt(curl, CURLOPT_WRITEDATA, pagefile);
		curl_easy_perform(curl);
		fclose(pagefile);
	}

	curl_easy_cleanup(curl);

	return 0;
}

