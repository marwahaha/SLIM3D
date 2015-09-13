#include "slim/core/attributes.h"
#include "slim/core/templates.hh"
#include "slim/events/EventsManager.hh"

#include <cstring>

namespace slim
{
namespace events
{

EventsManager::EventsManager()
{
    memset(this, 0, sizeof(*this));
}

EventsManager::~EventsManager()
{
    this->deleteListeners(m_keyPressListeners, keyboard::keysNumber);
    this->deleteListeners(m_keyReleaseListeners, keyboard::keysNumber);

    this->deleteListeners(m_mouseButtonPressListeners, mouse::buttonsNumber);
    this->deleteListeners(m_mouseButtonReleaseListeners, mouse::buttonsNumber);
    if (m_mouseMovementListener)
    {
	delete m_mouseMovementListener;
    }

    if (m_closeListener)
    {
	delete m_closeListener;
    }
}


void
EventsManager::onKeyAction(keyboard::EKeyCode keyCode, SLIM_CORE_UNUSED int scancode,
			   keyboard::EAction action, SLIM_CORE_UNUSED int modifiers)
{
    if (action == keyboard::pressed)
    {
	m_keysCurrentlyPressed[keyCode] = true;
	if (m_keyPressListeners[keyCode])
	{
	    m_keyPressListeners[keyCode]->onEvent();
	}
    }
    else if (action == keyboard::released)
    {
	m_keysCurrentlyPressed[keyCode] = false;
	if (m_keyReleaseListeners[keyCode])
	{
	    m_keyReleaseListeners[keyCode]->onEvent();
	}
    }
}

void
EventsManager::onMouseButtonAction(mouse::EButton button, mouse::EAction action, SLIM_CORE_UNUSED int modifiers)
{
    if (action == mouse::pressed)
    {
	m_mouseButtonsCurrentlyPressed[button] = true;
	if (m_mouseButtonPressListeners[button])
	{
	    m_mouseButtonPressListeners[button]->onEvent(m_currentMousePosition);
	}
    }
    else if (action == mouse::released)
    {
	m_mouseButtonsCurrentlyPressed[button] = false;
	if (m_mouseButtonReleaseListeners[button])
	{
	    m_mouseButtonReleaseListeners[button]->onEvent(m_currentMousePosition);
	}
    }
}

void
EventsManager::onMouseMovement(double x, double y)
{
    m_currentMousePosition.x = x;
    m_currentMousePosition.y = y;
    if (m_mouseMovementListener)
    {
	m_mouseMovementListener->onEvent(m_currentMousePosition);
    }
}

void
EventsManager::onClose()
{
    if (m_closeListener)
    {
	m_closeListener->onEvent();
    }
}

}
}
