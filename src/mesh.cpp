#include <GL/gl.h>
#include <vector>
#include <string>
#include <fstream>
#include <boost/algorithm/string.hpp>
#include <stdio.h>
#include "mesh.h"

typedef std::vector<std::string> StringVector;
typedef std::vector<float> FloatVector;
typedef std::vector<int> IndexVector;

void load_mesh (GLuint dest, const char* filename)
{
	std::fstream fin(filename, std::fstream::in);
	std::string line;
	StringVector splitLine;
	
	// Buffer objects
	FloatVector verts;
	IndexVector faces;
	
	// For each line in the file
	while( !fin.eof() ) {
		std::getline(fin, line);
		boost::split(splitLine, line,
					 boost::is_any_of(" \t\n"),
					 boost::token_compress_on);
		
		// If the line has any contents
		if(splitLine.size()>0) {
			for(StringVector::iterator i=splitLine.begin()+1;
				i != splitLine.end(); ++i) {
				
			}
			
			switch(splitLine[0][0]) {
				'v':
					if(splitLine.size()>=4) {
						// Add each vertex point
						for(int v=1; v<4; v++) {
							verts.push_back( atof(splitLine[v].c_str()) );
						}
					}
				break;
				
				'f':
					if(splitLine.size()>=2) {
						faces.push_back( atoi(splitLine[1].c_str()) );
					}
				break;
				
				default:
					;
			}
		}
	}
	
	glBufferData( GL_ARRAY_BUFFER, verts.size()*sizeof(float),
				  &verts[0], GL_STATIC_DRAW);
	glBufferData( GL_ARRAY_BUFFER, faces.size()*sizeof(float),
				  &verts[0], GL_STATIC_DRAW);
}
