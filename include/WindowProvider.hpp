#ifndef WINDOW_PROVIDER_HPP
#define WINDOW_PROVIDER_HPP

#include <MyGLWindow.h>

class WindowProvider {
	public:
		virtual void createWindow()= 0;
		virtual void swapBuffers() = 0;
};

/*
 * This is an implementation of a WindowProvides, specific for
 * Raspberry pi
 */
class EGLWindowProvider : public WindowProvider {
	private:
		MyGLWindow * window;
	public:
		void createWindow();
		void swapBuffers();
		~EGLWindowProvider();
};
#endif
