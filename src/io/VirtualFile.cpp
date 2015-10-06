#include "slim/core/attributes.h"
#include "slim/debug/assert.hh"
#include "slim/io/VirtualFile.hh"
#include "slim/io/BufferedReadingFile.hh"

#include <cstring>

namespace slim
{
namespace io
{

VirtualFile
VirtualFile::fromRealFile(const char* fileName)
{
    BufferedReadingFile	file(fileName);

    return VirtualFile::fromRealFile(file);
}

VirtualFile
VirtualFile::fromRealFile(ReadingFile& file)
{
    unsigned int	size = 0;
    assets::byte*	data = new assets::byte[file.getInfos().getSize()];
    unsigned int	bufferSize;
    assets::byte	buffer[SLIM_IO_FILE_READ_BUFFER_SIZE];

    do
    {
	bufferSize = file.read(buffer, SLIM_IO_FILE_READ_BUFFER_SIZE);
	memcpy(&data[size], buffer, bufferSize);
	size += bufferSize;
    }
    while (bufferSize > 0);

    return VirtualFile(data, size);
}


VirtualFile::VirtualFile(assets::byte* data, unsigned int size) :
    m_data(data),
    m_size(size)
{
}

VirtualFile::VirtualFile(const VirtualFile& reference) :
    m_size(reference.getSize())
{
    m_data = new assets::byte[m_size];
    memcpy(m_data, reference.m_data, m_size);
}

VirtualFile::~VirtualFile()
{
    delete[] m_data;
}


void
VirtualFile::toBuffer(char* buffer, unsigned int size) const
{
    SLIM_CORE_USE(size);
    SLIM_DEBUG_ASSERT(size > m_size);
    memcpy(buffer, m_data, m_size);
    buffer[m_size] = '\0';
}


void
VirtualFile::read(assets::byte* buffer, unsigned int size)
{
    SLIM_DEBUG_ASSERT(m_index + size <= m_size);
    memcpy(buffer, &m_data[m_index], size);
    m_index += size;
}

}
}