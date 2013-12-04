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
const unsigned long long giga = 1024 * 1024 * 1024;

static unsigned long long ThresArray[]=
{0, 1, 2, 4, 8, 16, 32, 64, 128, 256, 512,
	1*kilo, 2*kilo, 4*kilo, 8*kilo, 16*kilo, 32*kilo, 64*kilo, 128*kilo, 256*kilo, 512*kilo,
	1*mega, 2*mega, 4*mega, 8*mega, 16*mega, 32*mega, 64*mega, 128*mega, 256*mega, 512*mega,
	1*giga, 2*giga, 4*giga, 8*giga, 16*giga, 32*giga, 64*giga, 128*giga, 256*giga, 512*giga,
	};

static char ThresStrBit[][10]=
{"NULL","8Bit/s","16Bit/s","32Bit/s","64Bit/s","128Bit/s","256Bit/s","512Bit/s",
	"1KBit/s","2KBit/s","4KBit/s","8KBit/s","16KBit/s","32KBit/s","64KBit/s","128KBit/s","256KBit/s","512KBit/s",
	"1MBit/s","2MBit/s","4MBit/s","8MBit/s","16MBit/s","32MBit/s","64KBit/s","128KBit/s","256MBit/s","512MBit/s",
	"1GBit/s","2GBit/s","4GBit/s","8GBit/s","16GBit/s","32GBit/s","64KBit/s","128KBit/s","256GBit/s","512GBit/s",
	"1TBit/s","2TBit/s","4TBit/s",
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
			return ThresStrBit[i];
		}
	}
	return ThresStrBit[0];
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
