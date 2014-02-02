/*
 * Simple Raspberry Pi OpenGl-ES window tests application 
 * Copyright (C) 2013-2014, Julio Delgado <julio.delgadomangas@gmail.com>
 * 
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef EGLconfig_H__
#define EGLconfig_H__
#include <EGL/egl.h>
#include <EGL/eglext.h>
#include <map>


/// @brief this file is a wrapper for the EGL config, used to set the attributes
/// for out EGL window.
/// The default ctor will make a useable config or the user can create their own
/// by default we will have RGBA 8 Bits with Depth 24 and GLES 2.0

class EGLconfig
{
	public :
		/// @brief ctor will create a default attrib set
		EGLconfig();
		/// @brief dtor (doesn't do anything
		~EGLconfig();
		/// @brief set the attrib / value pair, unfortunatly they are both ints and
		/// not enums so it's quite difficult to check apart from a hard coded range
		/// check based on the headers!
		/// @param[in] _attrib the attribute pair to set
		/// @param[in] _value the value of the attribute
		void setAttribute(EGLint _attrib,EGLint _value);
		/// @brief sets the R,G,B,A bit size
		/// @param[in] _r the red bit depth
		/// @param[in] _g the green bit depth
		/// @param[in] _b the blue bit depth
		/// @param[in] _a the alpha bit depth
		void setRGBA(EGLint _r,EGLint _g, EGLint _b, EGLint _a);
		/// @brief sets the depth buffer size
		/// @param[in] _d the depth
		void setDepth(EGLint _d);
		/// @brief set the surface type
		/// @param[in] the surface type can be | combinations of
		/// EGL_WINDOW_BIT, EGL_PBUFFER_BIT, and EGL_PIXMAP_BIT
		void setSurface(EGLint _s);
		/// @brief set the config for the current values of this class
		/// this must be called for any changes to take place
		/// @param[in] _display the active display created for the config
		void chooseConfig(EGLDisplay _display);
		/// @brief get the config create with choose to the client
		inline EGLConfig getConfig() {return m_config;};
		private :
			std::map<EGLint,EGLint> m_attributes;
			EGLConfig m_config;

};



#endif
