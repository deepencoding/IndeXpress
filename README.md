# IndeXpress

## Intro
A speedy and reliable word indexing application designed to quickly index each word in large text files, providing instant access to the most frequent words in the directory.

A multi-threaded text file indexing command line application in C++ that works as follows:
The project is a C++ command-line application for indexing text files in a directory tree and finding the top 10 most frequent words.
Users input a directory path through the command line as the starting point for the search.
### Search Thread:

A single thread searches through the specified directory and its sub-directories.
Text files with a '.txt' extension are identified and handed off for processing.
The search thread continues searching while processing is ongoing for efficiency.
### Worker Threads:

A fixed number (N) of worker threads, for instance, N=3, process the text files concurrently.
Worker threads handle the content processing of the text files.
### Text File Processing:

Worker threads open each text file and read its content.
Content is processed word by word, delimited by non-alphanumeric characters.
This approach normalizes words, making comparisons case-insensitive and removing punctuation.
### Master Table:

A shared table in memory is used to track unique words and their occurrence counts.
Words encountered are updated in this master table.
Threads access the same table, preventing data inconsistencies.
### Word Counting and Table Management:

Worker threads update the master table with encountered words and their counts.
The synchronized approach avoids conflicts among threads.
### Top 10 Words:

Once all text files are processed, the application extracts the top 10 most frequent words.
These words, along with their counts, are displayed as the final output.
In essence, this project creates a multi-threaded C++ application that efficiently traverses directories, processes text files, and maintains a shared data structure to count and rank words. The application's end result is a list of the top 10 words and their counts, offering insights into the textual content across the specified directory tree.

## High Level Architectural Design
![Design](https://github.com/deepencoding/IndeXpress/blob/main/architecture.png)

## Development

Developed in Microsoft Visual Studio 2022

### Directory Structure

IndeXpress -> |\
&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&ensp;| -- IndeXpress -> |\
&emsp;&ensp;&emsp;&emsp;&emsp;&emsp;&ensp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&ensp;&emsp;&emsp;| -- IndeXpress.cpp\
&emsp;&ensp;&emsp;&emsp;&emsp;&emsp;&ensp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&ensp;&emsp;&emsp;| -- IndeXpress.vcxproj\
&emsp;&ensp;&emsp;&emsp;&emsp;&emsp;&ensp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&ensp;&emsp;&emsp;| -- IndeXpress.vcxproj.filters\
&emsp;&ensp;&emsp;&emsp;&emsp;&emsp;&ensp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&ensp;&emsp;&emsp;| -- Searcher.cpp\
&emsp;&ensp;&emsp;&emsp;&emsp;&emsp;&ensp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&ensp;&emsp;&emsp;| -- Searcher.hpp\
&emsp;&ensp;&emsp;&emsp;&emsp;&emsp;&ensp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&ensp;&emsp;&emsp;| -- Synchronizer.cpp\
&emsp;&ensp;&emsp;&emsp;&emsp;&emsp;&ensp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&ensp;&emsp;&emsp;| -- Synchronizer.hpp\
&emsp;&ensp;&emsp;&emsp;&emsp;&emsp;&ensp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&ensp;&emsp;&emsp;| -- WorkerThread.cpp\
&emsp;&ensp;&emsp;&emsp;&emsp;&emsp;&ensp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&ensp;&emsp;&emsp;| -- WorkerThread.hpp\
&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&ensp;| -- IndeXpress.sln\
&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&ensp;| -- README.md\

### Output of the Program

![Output](https://github.com/deepencoding/IndeXpress/blob/main/op.png)
