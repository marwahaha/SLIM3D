#include "slim/io/BufferedFile.hpp"
#include "slim/debug/Exception.hpp"

namespace slim
{
namespace io
{

BufferedFile::BufferedFile()
{
}

BufferedFile::~BufferedFile() noexcept(false)
{
    if (fclose(m_stream) != 0)
    {
	throw debug::Exception("Cannot close buffered file.", __FILE__, __func__, __LINE__);
    }
}

}
}
