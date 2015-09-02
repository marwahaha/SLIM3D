//
// UnbufferedWritingFile.cpp for SLIM3D in /home/aracthor/programs/projects/SLIM3D/resources
// 
// Made by Aracthor
// 
// Started on  Wed Sep  2 14:50:16 2015 Aracthor
// Last Update Wed Sep  2 17:12:05 2015 Aracthor
//

#include "slim3d/resources/UnbufferedWritingFile.hh"

UnbufferedWritingFile::UnbufferedWritingFile(const char* name) :
    UnbufferedFile(name)
{
    m_fd = open(name, O_RDONLY);
    if (m_fd == -1)
    {
	this->onError("Unbuffered mode, cannot open file");
    }
}

UnbufferedWritingFile::~UnbufferedWritingFile()
{
}


size_t
UnbufferedWritingFile::write(const void* data, size_t size)
{
    size_t	wrote = write(m_fd, data, size, 1, m_stream);

    if (wrote == -1)
    {
	this->onError("Unbuffered mode, error writing in");
    }

    return (wrote);
}
