#include <X11/Xlib.h>

int main(void)
      { Display* display;
        Window   root;
        XEvent   event;
        int      unusedint;
        Window   unusedwin;
        Window   focuswin;

void delwin(focuswin)
      { if (focuswin != None)
      { XEvent event;
        event.xclient.type = ClientMessage;
        event.xclient.window = focuswin;
        event.xclient.message_type = XInternAtom(display, "WM_PROTOCOLS", True);
        event.xclient.format = 32;
        event.xclient.data.l[0] = XInternAtom(display, "WM_DELETE_WINDOW", False);
        event.xclient.data.l[1] = CurrentTime;
        XSendEvent(display, focuswin, False, NoEventMask, &event); }}

        display = XOpenDisplay(NULL);
        if(display == NULL)
      { return 1; }

        root = DefaultRootWindow(display);

        XGrabButton(display, 1, Mod4Mask, root, True, ButtonPressMask, GrabModeAsync, GrabModeAsync, None, None);
        XGrabButton(display, 2, Mod4Mask, root, True, ButtonPressMask, GrabModeAsync, GrabModeAsync, None, None);
        XGrabButton(display, 3, Mod4Mask, root, True, ButtonPressMask, GrabModeAsync, GrabModeAsync, None, None);
        XGrabButton(display, 4, Mod4Mask, root, True, ButtonPressMask, GrabModeAsync, GrabModeAsync, None, None);
        XGrabButton(display, 5, Mod4Mask, root, True, ButtonPressMask, GrabModeAsync, GrabModeAsync, None, None);

for(;;)
      { XNextEvent(display, &event);
        XQueryPointer(display, root, &unusedwin, &focuswin, &unusedint, &unusedint, &unusedint, &unusedint, &unusedint);

	if(event.type == ButtonPress)
      { if (event.xbutton.button == Button1)
        system("dmenu_run &");
        else if (event.xbutton.button == Button2)
        delwin(event.xkey.subwindow);
        else if (event.xbutton.button == Button3)
      { if (focuswin != None)
      { XMoveResizeWindow(display, focuswin, 0, 0, 1920, 1080); }}
        else if (event.xbutton.button == Button4)
      { if (focuswin != None)
      { XCirculateSubwindowsDown(display, root);
        XQueryPointer(display, root, &unusedwin, &focuswin, &unusedint, &unusedint, &unusedint, &unusedint, &unusedint);
        XRaiseWindow(display, focuswin); 
        XSetInputFocus(display, focuswin, RevertToParent, CurrentTime); }}
        else if (event.xbutton.button == Button5)
      { if (focuswin != None)
      { XCirculateSubwindowsUp(display, root);
        XQueryPointer(display, root, &unusedwin, &focuswin, &unusedint, &unusedint, &unusedint, &unusedint, &unusedint);
        XRaiseWindow(display, focuswin); 
        XSetInputFocus(display, focuswin, RevertToParent, CurrentTime); }}
}
}
}
