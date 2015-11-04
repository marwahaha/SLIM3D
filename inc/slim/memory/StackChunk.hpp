#ifndef SLIM_MEMORY_STACK_CHUNK_HPP_
# define SLIM_MEMORY_STACK_CHUNK_HPP_

# include "slim/memory/Chunk.hpp"

namespace slim
{
namespace memory
{

class			StackChunk : public Chunk
{
public:
    inline StackChunk(char* data, std::size_t size, const char* name);
    inline ~StackChunk();

public:
    inline void*	alloc(std::size_t size) override;
    inline void 	free(char* ptr) override;
};

}
}

# include "StackChunk.ipp"

#endif // !SLIM_MEMORY_STACK_CHUNK_HPP_
