#include "GlobalIncludeAndMacro.h"

#include "main.h"
#include "AppDelegate.h"
#include "CCEGLView.h"

USING_NS_CC;

int APIENTRY _tWinMain(HINSTANCE hInstance,
                       HINSTANCE hPrevInstance,
                       LPTSTR    lpCmdLine,
                       int       nCmdShow)
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

    // create the application instance
    AppDelegate app;
    CCEGLView* eglView = CCEGLView::sharedOpenGLView();
    eglView->setViewName("Bricks");
    //eglView->setFrameSize(480, 320);
	eglView->setFrameSize(540,960);
	eglView->setFrameZoomFactor(0.5f);
    return CCApplication::sharedApplication()->run();
}