#include "SimpleDownloadFunctionality.h"

SimpleDownloadFunctionality::SimpleDownloadFunctionality()
{
    DownloaderInit(false);
}

SimpleDownloadFunctionality::~SimpleDownloadFunctionality()
{
    zoe::Zoe::GlobalUnInit();
}

void SimpleDownloadFunctionality::Download(std::string downloadLink, std::string targetPath)
{
        // 4) Start download
    auto fut = downloader.start(
        downloadLink,
        targetPath,
        nullptr, progressCallback, speedCallback);

    // 5) Wait & inspect result
    auto res = fut.get();
    std::cout << "Final result: "
    << zoe::Zoe::GetResultString(res)
    << " (" << static_cast<int>(res) << ")\n";
}

void SimpleDownloadFunctionality::progressCallback(int64_t totalBytes, int64_t DownloadedBytes) {
    DownloadedBytes /= (1024 * 1024);
    totalBytes /= (1024 * 1024);
    Status = "Downloading: ";
    std::cout << Status << DownloadedBytes << "/" << totalBytes << " Mb" << std::endl;
}

void SimpleDownloadFunctionality::speedCallback(int64_t bytesPerSecond) {
    bytesPerSecond /= 1024;
    std::cout << bytesPerSecond << " Kb/s" << std::endl;
}

int SimpleDownloadFunctionality::DownloaderInit(bool RedirectedURLCheck)
{
    zoe::Zoe::GlobalInit();
    downloader.setRedirectedUrlCheckEnabled(RedirectedURLCheck);
    return 0;
}
