#include "Synchronizer.hpp"
#include "WorkerThread.hpp"
#include "Searcher.hpp"

#include <iostream>
#include <string>
#include <map>
#include <iomanip>
#include <filesystem>
#include <Windows.h>

namespace fs = std::filesystem;

// Number of processor threads
const unsigned int WThreadCount = 3;

// flag indicating if search of .txt file is completed by SearchThread
bool SearchComplete = false;

// Synchronizer queue object
Synchronizer SyncQ;


int main()
{
	std::string dir;

	std::cout << "Please Specify the Absolute Directory Path: ";

	std::cin >> dir;
	const fs::path inputPath = dir;
	
	if (!fs::exists(inputPath))
	{
		std::cout << "\nDirectory doesn't exist. Exiting Code.\n";
		return -1;
	}

	DWORD p_id = GetCurrentProcessId();

	std::cout << "\nPlease wait while process(" << p_id << ")" << " is processing....\n";

	// Creating Worker Threads
	WorkerThread WThread(WThreadCount);
	WThread.m_CreateWorkerThreads();

	// Creating Search thread to add .txt files in Queue
	Searcher SearchThObj;
	SearchThObj.m_StartSearch(dir);


	while (1)
	{
		if (SearchComplete && !(SyncQ.m_GetFileCount()))
			break;
	}

	std::cout << "Search of all txt files completed!\n";

	std::multimap <int, std::string, std::greater<int> > MTable;
	MTable = WThread.m_GetTableEntry();

	std::cout << "\nTotal files Processed " << SyncQ.m_GetProcessedFileCount() << std::endl;
	std::cout << "***********************************************\n";
	std::cout << " " << std::setw(10) << "Words" << std::setw(20) << "No of occurences\n";
	std::cout << "***********************************************\n";

	int i = 0;
	for (auto iter = MTable.begin(); iter != MTable.end(); iter++)
	{
		std::cout << " " << std::setw(10) << iter->second << std::setw(10) << iter->first << "\n";
		i++;

		// To get only Top 10 words
		if (i == 10)
			break;
	}

	std::cout << "***********************************************\n";

	return 0;

}