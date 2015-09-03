//
// SingletonsManager.cpp for SLIM3D in /home/aracthor/programs/projects/SLIM3D/core/srcs//
// 
// Made by aracthor
// 
// Started on  Mon Aug 31 17:31:31 2015 aracthor
// Last Update Mon Aug 31 17:55:14 2015 Aracthor
//

#include "slim3d/core/SingletonsManager.hh"

namespace slim
{
namespace core
{

SingletonsManager::SingletonsManager()
{
    this->listSingletons();
    this->initSingletons();
}

SingletonsManager::~SingletonsManager()
{
    this->destroySingletons();
}


void
SingletonsManager::listSingletons()
{
}

void
SingletonsManager::initSingletons()
{
    for (Singleton* singleton : m_singletons)
    {
	singleton->init();
    }
}

void
SingletonsManager::destroySingletons()
{
    for (int i = SINGLETONS_NUMBER - 1; i >= 0; --i)
    {
	m_singletons[i]->destroy();
    }
}

}
}
