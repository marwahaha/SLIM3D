#ifndef SLIM_CORE_ATTRIBUTES_H_
# define SLIM_CORE_ATTRIBUTES_H_

# if defined(__GNUC__)
#  define SLIM_CORE_UNUSED(type, parameter)	__attribute__ ((unused)) type parameter
#  define SLIM_CORE_PACKED(member)		__attribute__ ((packed)) member
#  define SLIM_CORE_NOTETURN			__attribute__ ((noreturn))
# elif defined(_MSC_VER)
#  define SLIM_CORE_UNUSED(type, parameter)	type
#  define SLIM_CORE_PACKED(structure)		structure // TODO
#  define SLIM_CORE_NORETURN			__declspec(noreturn)
# else
#  error "Cannot recognize your compiler."
# endif

#endif /* !SLIM_CORE_ATTRIBUTES_H_ */
