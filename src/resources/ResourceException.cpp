#include "slim/resources/ResourceException.hh"

#include <cstdio>
#include <cstring>

namespace slim
{
namespace resources
{

ResourceException::ResourceException(const char* resourceName, const char* message,
				     const char* file, const char* function, int line) :
    debug::Exception(message, file, function, line),
    m_resourceName(resourceName)
{
    char	newMessage[SLIM_DEBUG_MESSAGE_BUFFER_SIZE];

    snprintf(newMessage, SLIM_DEBUG_MESSAGE_BUFFER_SIZE, "Resource %s: %s", resourceName, m_whatMessage);
    strcpy(m_whatMessage, newMessage);
}

ResourceException::~ResourceException() throw()
{
}

}
}
