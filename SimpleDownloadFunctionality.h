#pragma once
#include <zoe\zoe.h>
#include <string>
#include <iostream>

class SimpleDownloadFunctionality
{
public:
	SimpleDownloadFunctionality();
	~SimpleDownloadFunctionality();

	void Download(std::string downloadLink);
private:
	int DownloaderInit(bool RedirectedURLCheck);
	void progressCallback(int64_t totalBytes, int64_t DownloadedBytes);
	void speedCallback(int64_t bytesPerSecond);

	//INSTANTIATION:
	zoe::Zoe downloader;
};

