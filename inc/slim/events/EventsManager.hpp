namespace slim
{
namespace events
{

void
EventsManager::addKeyPressListener(IKeyListener* listener, keyboard::EKeyCode keyCode)
{
    m_keyPressListeners[keyCode] = listener;
}

void
EventsManager::addKeyReleaseListener(IKeyListener* listener, keyboard::EKeyCode keyCode)
{
    m_keyReleaseListeners[keyCode] = listener;
}

void
EventsManager::addMouseButtonPressListener(IMouseListener* listener, mouse::EButton button)
{
    m_mouseButtonPressListeners[button] = listener;
}

void
EventsManager::addMouseButtonReleaseListener(IMouseListener* listener, mouse::EButton button)
{
    m_mouseButtonReleaseListeners[button] = listener;
}

void
EventsManager::addMouseMovementListener(IMouseListener* listener)
{
    m_mouseMovementListeners = listener;
}

bool
EventsManager::isKeyPressed(keyboard::EKeyCode key) const
{
    return m_keysCurrentlyPressed[key];
}

bool
EventsManager::isMouseButtonPressed(mouse::EButton button) const
{
    return m_mouseButtonsCurrentlyPressed[button];
}


template <class T>
void
EventsManager::deleteListeners(T** listeners, unsigned int number)
{
    for (unsigned int i = 0; i < number; ++i)
    {
	if (listeners[i])
	{
	    delete listeners[i];
	}
    }
}

}
}