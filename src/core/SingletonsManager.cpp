//
// SingletonsManager.cpp for SLIM in /home/aracthor/programs/projects/SLIM/core/srcs//
// 
// Made by aracthor
// 
// Started on  Mon Aug 31 17:31:31 2015 aracthor
// Last Update Sun Sep 13 09:26:07 2015 Aracthor
//

#include "slim/core/SingletonsManager.hh"
#include "slim/debug/LogManager.hh"
#include "slim/maths/Helper.hh"
#include "slim/window/MonitorsManager.hh"

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
    m_singletons[0] = &debug::LogManager::instance;
    m_singletons[1] = &MathsHelper::instance;
    m_singletons[2] = &window::MonitorsManager::instance;
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
