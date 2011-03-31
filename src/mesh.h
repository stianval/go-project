#ifndef MESH_H
#define MESH_H

#include <GL/gl.h>

/**
 * Loads mesh data from a .obj file.
 * @param vbo vertex buffer object handle pointer. Should be released manually
 * later.
 * @param ebo element buffer object handle pointer. Should be released manually
 * later.
 * @param filename filename for .obj file.
 */
void load_mesh (GLuint *vbo, GLuint *ebo, const char *filename);

#endif
