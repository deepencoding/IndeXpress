#include "Synchronizer.hpp"

#include <iostream>
#include <string>

// Constructor
Synchronizer::Synchronizer()
{
	m_CountFile = 0;
	std::cout << "Synchronizer Object created." << '\n';
}

// Destructor
Synchronizer::~Synchronizer()
{
}

void Synchronizer::m_AddFileName(std::string filename)
{
	m_QMutexObj.lock();
	m_Queue.push(filename);
	m_CountFile++;
	m_QMutexObj.unlock();
	std::cout << "Added file name." << '\n';

}

std::string Synchronizer::m_GetFrontFile()
{
	std::string filename = "";
	m_QMutexObj.lock();
	if (!m_Queue.empty())
	{
		filename = m_Queue.front();
		m_Queue.pop();
	}
	m_QMutexObj.unlock();
	std::cout << "Get front file." << '\n';
	return filename;

}

size_t Synchronizer::m_GetFileCount()
{
	size_t QSize = 0;
	QSize = m_Queue.size();
	return QSize;

}

int Synchronizer::m_GetProcessedFileCount()
{
	return m_CountFile;
}