#include <curl/curl.h>
#include <cstdio>
#include <fstream>
#include "array_downloader.hpp"

size_t write_data(void *ptr, size_t size, size_t nmemb, FILE *stream) {
	size_t written = fwrite(ptr, size, nmemb, stream);
	return written;
}

void downloadFile(const std::string &url, const std::string &outfilename) {
	CURL *curl;
	FILE *fp;
	CURLcode res;
	curl = curl_easy_init();
	if(curl) {
		fp = fopen(outfilename.c_str(), "wb");
		curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
		curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_data);
		curl_easy_setopt(curl, CURLOPT_WRITEDATA, fp);
		res = curl_easy_perform(curl);
		curl_easy_cleanup(curl);
		fclose(fp);
	}
}

void fillArray(const std::string &url, std::deque<int> &deq) {
	const std::string outputFileName = "./tmp";
	downloadFile(url, outputFileName);
	std::ifstream file(outputFileName);
	int num;
	while(file >> num)
		deq.push_back(num);
	remove(outputFileName.c_str());
}
