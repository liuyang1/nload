/***************************************************************************
                                  graph.h
                             -------------------
    begin                : Sat Sep 29 2001
    copyright            : (C) 2001 - 2012 by Roland Riegel
    email                : feedback@roland-riegel.de
 ***************************************************************************/

/***************************************************************************
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 ***************************************************************************/

#ifndef GRAPH_H
#define GRAPH_H

#include <list>

class Window;

const unsigned long long kilo = 1024;
const unsigned long long mega = 1024 * 1024;
const unsigned long long gibi = 1024 * 1024 *1024;

static unsigned long long ThresArray[]=
{0, 1, 2, 4, 8, 16, 32, 64, 128, 256, 512,
	1*kilo, 2*kilo, 4*kilo, 8*kilo, 16*kilo, 32*kilo, 64*kilo, 128*kilo, 256*kilo, 512*kilo,
	1*mega, 2*mega, 4*mega, 8*mega, 16*mega, 32*mega, 64*mega, 128*mega, 256*mega, 512*mega,
	1*gibi, 2*gibi, 4*gibi, 8*gibi, 16*gibi, 32*gibi, 64*gibi, 128*gibi, 256*gibi, 512*gibi,
	};

static char ThresStr[][10]=
{"NULL", "1b","2b","4b","8b","16b","32b","64b","128b","256b","512b",
	"1Kb","2Kb","4Kb","8Kb","16Kb","32Kb","64Kb","128Kb","256Kb","512Kb",
	"1Mb","2Mb","4Mb","8Mb","16Mb","32Mb","64Kb","128Kb","256Mb","512Mb",
	"1Gb","2Gb","4Gb","8Gb","16Gb","32Gb","64Kb","128Kb","256Gb","512Gb",
	};
	
inline unsigned long long getThresh(unsigned long long val)
{
	unsigned int len = sizeof(ThresArray) / sizeof(unsigned long long);
	for (unsigned int i=0; i < len; i++){
		if (val <= ThresArray[i])
			return ThresArray[i];
	}
	return 0;
}
inline char* getString(unsigned long long val)
{
	unsigned int len = sizeof(ThresArray);
	for (unsigned int i=0; i<len; i++){
		if (val <= ThresArray[i]){
			return ThresStr[i];
		}
	}
	return ThresStr[0];
}

class Graph
{
    public:
        Graph();
        ~Graph();
        
        void setNumOfBars(unsigned int numOfBars);
        void setHeightOfBars(unsigned int heightOfBars);
        void setMaxDeflection(unsigned long long maxDeflection);
		unsigned long long getMaxDeflection()
		{
			return m_maxDeflection;
		}
        
        void update(unsigned long long value);
        void print(Window& window, int x, int y);
        void resetTrafficData();
		void updateMaxDeflection();
		void setDynamicMax() {
			isDynamicMax = true;
		}

    private:
		bool isDynamicMax;
        unsigned int m_heightOfBars;
        unsigned long long m_maxDeflection;
        std::list<unsigned long long> m_values;
};

#endif
