//
// SingletonsManager.hh for SLIM in /home/aracthor/programs/projects/SLIM/core/inc/slim/core//
// 
// Made by aracthor
// 
// Started on  Mon Aug 31 17:31:31 2015 aracthor
// Last Update Wed Sep  9 14:18:19 2015 Aracthor
//

#ifndef SINGLETONS_MANAGER_HH_
# define SINGLETONS_MANAGER_HH_

# include "slim/core/Singleton.hh"

# define SINGLETONS_NUMBER	2

namespace slim
{
namespace core
{

class	SingletonsManager
{
public:
    SingletonsManager();
    ~SingletonsManager();

private:
    void	listSingletons();
    void	initSingletons();
    void	destroySingletons();

private:
    Singleton*	m_singletons[SINGLETONS_NUMBER];
};

}
}

#endif // !SINGLETONS_MANAGER_HH_