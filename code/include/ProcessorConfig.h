/** @file ProcessorConfig.h
 *  @brief ProcessorConfig class contains all configuration parameters from command line arguments
 *
 *  @author Peter J. Morley (pmorley)
 */
#pragma once
#include "Logger.h"
#include "FileReader.h"

/** @brief Configuration parameters struct
 *  
 *  Includes whether the file will be processed with ram or hd, threads to use,
 *  list of files to process, min and max pattern lengths to search for, etc.
 */
struct ConfigurationParams
{
	PListType minimum, maximum;
	bool usingPureRAM;
	bool usingPureHD;
	unsigned int numThreads;
	int history;
	PatternDiscoveryType nonOverlappingPatternSearch;
	double memoryBandwidthMB;
	bool usingMemoryBandwidth;
	int levelToOutput;
	string patternToSearchFor;
	PListType minOccurrence;
	vector<FileReader*> files;
    FileReader* currentFile;
	int currentFileIndex;
	vector<PListType> fileSizes;
	unsigned char lowRange;
	unsigned char highRange;
	bool suppressStringOutput;
	unsigned int minimumFrequency;
    bool processInts;
    double memoryUsageAtInception;
    double memoryPerThread;
    bool overMemoryCount; //Status to indicate if memory is being over utilized
};
class ProcessorConfig
{
public:
	/** @brief Constructor.
     */
	ProcessorConfig(void);

	/** @brief Destructor.
     */
	~ProcessorConfig(void);

	/** @brief Returns a static processor configuation parameters struct
	 *
	 *  @param argc number of command line arguments
	 *  @param argv contents of each command line argument
	 *  @return ConfigurationParams object based on command line arguments
	 */
	static ConfigurationParams GetConfig(int argc, char **argv);
	
private:
	/** static configuration parameters struct */
	static ConfigurationParams config;

	/** Helper method to recursively search through a directory for files */
	static void FindFiles(string directory);

	/** Displays the help message if a bad command line argument is found */
	static void DisplayHelpMessage();
	
};

