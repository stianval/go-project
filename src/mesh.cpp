#include <vector>
#include <string>
#include <fstream>
#include <boost/algorithm/string.hpp>
#include <stdio.h>
#include "mesh.h"

typedef std::vector<std::string> StringVector;

void load_mesh (GLuint dest, const char* filename)
{
	std::fstream fin(filename, std::fstream::in);
	std::string line;
	StringVector splitLine;
	
	while( !fin.eof() ) {
		std::getline(fin, line);
		boost::split(splitLine, line,
					 boost::is_any_of(" \t\n"),
					 boost::token_compress_on);
		
		if(splitLine.size()>0) {
			for(StringVector::iterator i=splitLine.begin()+1;
				i != splitLine.end(); ++i) {
				
			}
			
			switch(splitLine[0][0]) {
				'v':
				break;
				
				'f':
				break;
				
				default:
					;
			}
		}
	}
}
