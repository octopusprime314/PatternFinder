/** @file TreeHD.h
 *  @brief Hard Drive processing class that stores the pattern string in a map and it's occurrences in a file
 *
 *  @author Peter J. Morley (pmorley)
 */

#pragma once
#include <map>
#include "TypeDefines.h"

class TreeHD
{
private:
	
public:
	/** @brief Constructor.
     */
	TreeHD(){};

	/** @brief Destructor.
     */
	~TreeHD(){};

	/** @brief Sets the head of the pattern to improve processing speed
	 *
	 *  @param headLeaf contains the entire pattern except the last byte to improve processing speed and memory usage
	 *  @return void
	 */
	inline void setHeadLeaf(string headLeaf)
	{
		this->_headLeaf = headLeaf;
	}

	/** @brief Adds a new pattern to the tree or increments the count in the map
	 *
	 *  @param pIndex index where the pattern is located
	 *  @param uniquestring pattern char information
	 *  @return void
	 */
	inline void addLeaf(PListType pIndex, char uniquestring)
	{
		if (_leaves.find(uniquestring) == _leaves.end())
		{
			_leaves[uniquestring] = vector<PListType>();
			_leaves[uniquestring].push_back(pIndex);
		}
		else
		{
			_leaves[uniquestring].push_back(pIndex);
		}		
	}

	/** map that contains all the pattern information */
	map<char, vector<PListType>> _leaves;

	/** head leaf to save on memory usage */
	string _headLeaf;
};
