// The MIT License (MIT)
//
// Copyright (c) 2013 Dan Ginsburg, Budirijanto Purnomo
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.

//
// Book:      OpenGL(R) ES 3.0 Programming Guide, 2nd Edition
// Authors:   Dan Ginsburg, Budirijanto Purnomo, Dave Shreiner, Aaftab Munshi
// ISBN-10:   0-321-93388-5
// ISBN-13:   978-0-321-93388-1
// Publisher: Addison-Wesley Professional
// URLs:      http://www.opengles-book.com
//            http://my.safaribooksonline.com/book/animation-and-3d/9780133440133
//
//
/// \file engine_context.h
/// \brief A utility library for OpenGL ES.  This library provides a
///        basic common framework for the example applications in the
///        OpenGL ES 3.0 Programming Guide.
//

#ifndef ENGINE_H
#define ENGINE_H

#include <EGL/eglplatform.h>
#include <EGL/egl.h>

#include "WindowSystem/WindowSystem.hpp"
#include "GLEngine/Khr/Khr.hpp"

class Engine
{
    public:
        bool create(const char *title, int posx, int posy, int width, int height);
        void loop();

        //
        /// \brief Register a draw callback function to be used to render each frame
        /// \param context Application context
        /// \param drawFunc Draw callback function that will be used to render the scene
        //
        void registerDrawFunc(void(*drawFunc)(void *ctx));

        //
        /// \brief Register a callback function to be called on shutdown
        /// \param context Application context
        /// \param shutdownFunc Shutdown callback function
        //
        void registerShutdownFunc(void(*shutdownFunc)(void *ctx));

        //
        /// \brief Register an update callback function to be used to update on each time step
        /// \param context Application context
        /// \param updateFunc Update callback function that will be used to render the scene
        //
        void registerUpdateFunc(void(*updateFunc)(void *ctx, float deltatime));

        //
        /// \brief Register a keyboard input processing callback function
        /// \param context Application context
        /// \param keyFunc Key callback function for application processing of keyboard input
        //
        void registerKeyFunc(void(*keyFunc)(void *ctx, unsigned char keyChar, int x, int y));

        void callDrawFunc();
        void callShutdownFunc();
        void callUpdateFunc(float deltatime);
        void callKeyFunc(unsigned char keyChar, int x, int y);

    private:
        WinSystem ws;
        Khr khr;

        struct timeval t1, t2;
        struct timezone tz;
        float deltatime;

        /// Callbacks
        void(*drawFunc)(void *ctx) = NULL;
        void(*shutdownFunc)(void *ctx) = NULL;
        void(*updateFunc)(void *ctx, float deltatime) = NULL;
        void(*keyFunc)(void *ctx, unsigned char keyChar, int x, int y) = NULL;
};

#endif // ENGINE_H
