#include <X11/Xlib.h>

int main(void) {
    Display* display;
    Window root;
    XEvent event;
    int unusedint; 
    Window unusedwin;
	Window focuswin;

    display = XOpenDisplay(NULL);
    if(display == NULL)
    {
        return 1;
    }
    
    root = DefaultRootWindow(display);
           
        XGrabButton(display, 1, Mod4Mask, root, True, ButtonPressMask, GrabModeAsync, GrabModeAsync, None, None);
        XGrabButton(display, 2, Mod4Mask, root, True, ButtonPressMask, GrabModeAsync, GrabModeAsync, None, None);
        XGrabButton(display, 3, Mod4Mask, root, True, ButtonPressMask, GrabModeAsync, GrabModeAsync, None, None);     

    for(;;)
    {
	XNextEvent(display, &event);
	XQueryPointer(display, root, &unusedwin, &focuswin, &unusedint, &unusedint, &unusedint, &unusedint, &unusedint);
		if(event.type == ButtonPress)
        { 
		if (event.xbutton.button == Button1) {
            XLowerWindow(display, focuswin);  
        } else if (event.xbutton.button == Button2) {		
            XMoveResizeWindow(display, focuswin, 1920, 0, 1920, 1080);
        } else if (event.xbutton.button == Button3) {		
            XMoveResizeWindow(display, focuswin, 0, 0, 1920, 1080);
}  
}
}
}
