#include <X11/Xlib.h>

int main(void) {
    Display* display;
    Window root;
    XEvent event;
    int     unusedint; 
    Window  unusedwin;
    Window  focuswin;
    
    display = XOpenDisplay(NULL);
    if(display == NULL)
    {
        return 1;
    }
    
    root = DefaultRootWindow(display);
           
        XGrabButton(display, 1, Mod4Mask, root, True, ButtonPressMask, GrabModeAsync, GrabModeAsync, None, None);
        XGrabButton(display, 2, Mod4Mask, root, True, ButtonPressMask, GrabModeAsync, GrabModeAsync, None, None);
        XGrabButton(display, 3, Mod4Mask, root, True, ButtonPressMask, GrabModeAsync, GrabModeAsync, None, None);
        XGrabButton(display, 4, Mod4Mask, root, True, ButtonPressMask, GrabModeAsync, GrabModeAsync, None, None);
        XGrabButton(display, 5, Mod4Mask, root, True, ButtonPressMask, GrabModeAsync, GrabModeAsync, None, None);      

    for(;;)
    {
	XNextEvent(display, &event);
	XQueryPointer(display, root, &unusedwin, &focuswin, &unusedint, &unusedint, &unusedint, &unusedint, &unusedint);
	if(event.type == ButtonPress)
        {   
        if (event.xbutton.button == Button1) {
            system("dmenu_run");
        } else if (event.xbutton.button == Button3) {		
            XMoveResizeWindow(display, focuswin, 0, 0, 1920, 1080);
        }  else if (event.xbutton.button == Button4) {
            XCirculateSubwindowsDown(display, root);
            XSetInputFocus(display, PointerRoot, RevertToPointerRoot, CurrentTime);
        }  else if (event.xbutton.button == Button5) {
            XCirculateSubwindowsUp(display, root);
            XSetInputFocus(display, PointerRoot, RevertToPointerRoot, CurrentTime);
        }  else if (event.xbutton.button == Button2) {
            XKillClient(display, focuswin);
}
}
}
}
