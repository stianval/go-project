#define GL_GLEXT_PROTOTYPES

#include <GL/gl.h>
#include <vector>
#include <string>
#include <fstream>
#include <boost/algorithm/string.hpp>
#include <stdio.h>

#include "mesh.h"

typedef std::vector<std::string> StringVector;
typedef std::vector<GLfloat> FloatVector;
typedef std::vector<GLushort> IndexVector;

void load_mesh (GLuint *vbo, GLuint *ebo, const char* filename)
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
				
			switch(splitLine[0][0]) {
				case 'v':
					if(splitLine.size()>=4) {
						// Add each vertex point
						for(int v=1; v<4; v++) {
							verts.push_back( atof(splitLine[v].c_str())*0.1 );
						}
					}
				break;
				
				case 'f':
					if(splitLine.size()>=4) {
						for(int f=1; f<4; f++) {
							faces.push_back( atoi(splitLine[f].c_str())-1 );
							//printf("%d ", faces.back());
						}
						//printf("\n");
					}
				break;
				
				default:
					break;
			}
		}
	}
	
	glGenBuffers(1, vbo);
	glGenBuffers(1, ebo);
	
	glBindBuffer( GL_ARRAY_BUFFER, *vbo);
	glBufferData( GL_ARRAY_BUFFER, verts.size()*sizeof(GLfloat),
				  &verts[0], GL_STATIC_DRAW);
	
	glBindBuffer( GL_ELEMENT_ARRAY_BUFFER, *ebo);
	glBufferData( GL_ELEMENT_ARRAY_BUFFER, faces.size()*sizeof(GLushort),
				  &faces[0], GL_STATIC_DRAW);
	
	glBindBuffer( GL_ARRAY_BUFFER, 0);
	glBindBuffer( GL_ELEMENT_ARRAY_BUFFER, 0);
	
	printf("%d\n", faces.size()/3);
}

void render_mesh(GLuint vbo, GLuint ebo)
{
	glBindBuffer( GL_ARRAY_BUFFER, vbo);
	glBindBuffer( GL_ELEMENT_ARRAY_BUFFER, ebo);
	
	glEnableClientState(GL_VERTEX_ARRAY);
	
	glColor3f(1.0,0,0);
	glVertexPointer(3, 	GL_FLOAT, 0,0);
	glDrawElements( GL_TRIANGLES, 98, GL_UNSIGNED_SHORT, 0);
	
	glDisableClientState(GL_VERTEX_ARRAY);
	
	glBindBuffer( GL_ARRAY_BUFFER, 0);
	glBindBuffer( GL_ELEMENT_ARRAY_BUFFER, 0);
}
