#include "slim/debug/assert.hh"

namespace slim
{
namespace containers
{

template <typename T, unsigned int N>
Buffer<T, N>::Buffer() :
    m_size(0)
{
}

template <typename T, unsigned int N>
Buffer<T, N>::~Buffer()
{
}


template <typename T, unsigned int N>
void
Buffer<T, N>::clear()
{
    m_size = 0;
}


template <typename T, unsigned int N>
unsigned int
Buffer<T, N>::getSize() const
{
    return m_size;
}

template <typename T, unsigned int N>
const T*
Buffer<T, N>::getData() const
{
    return m_data;
}


template <typename T, unsigned int N>
T
Buffer<T, N>::operator[](unsigned int index) const
{
    SLIM_DEBUG_ASSERT(index < m_size);
    return m_data[index];
}

template <typename T, unsigned int N>
T&
Buffer<T, N>::operator[](unsigned int index)
{
    SLIM_DEBUG_ASSERT(index < N);
    return m_data[index];
}


template <typename T, unsigned int N>
Buffer<T, N>&
Buffer<T, N>::operator<<(T c)
{
    SLIM_DEBUG_ASSERT(m_size + 1 < N);
    m_data[m_size] = c;
    m_size++;

    return *this;
}

template <typename T, unsigned int N>
Buffer<T, N>&
Buffer<T, N>::operator<<(const T* str)
{
    while (*str)
    {
	*this << *str;
	str++;
    }

    return *this;
}

template <typename T, unsigned int N>
template <typename U>
Buffer<T, N>&
Buffer<T, N>::operator<<(U n)
{
    if (n < 0)
    {
	*this << static_cast<T>('-');
	n = -n;
    }
    if (n >= 10)
    {
	*this << n / 10;
    }
    else
    {
	*this << (static_cast<T>(n) + '0');
    }

    return *this;
}

}
}