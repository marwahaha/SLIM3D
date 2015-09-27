#ifndef SLIM_IO_READING_FILE_HH_
# define SLIM_IO_READING_FILE_HH_

# include "slim/io/File.hh"

namespace slim
{
namespace io
{

class	ReadingFile : public File
{
public:
    ReadingFile(const char* name);
    virtual ~ReadingFile() noexcept(false);

public:
    virtual size_t	read(void* buffer, size_t size) = 0;
};

}
}

#endif // !SLIM_IO_READING_FILE_HH_
