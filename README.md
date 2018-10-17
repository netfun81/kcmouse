## kcmouse ##
minimal window manager

Very minimal window manager using Windows Key + Mouse buttons for the following:

Button1 - start dmenu application launcher.

Button2 - make focused window fullscreen and move to right monitor.

Button3 - make focused window fullscreen and move to left monitor.

Button4 (scrollwheel) - cycle down through open programs.

Button5 (scrollwheel) - cycle up through open programs. 


to compile:  gcc -o kcmouse kcmouse.c -lX11


I recommend also using xbindkeys and xdotool for launching, focus, and kill functions.   

#Sample .xbindkeysrc:

	"firefox"
	mod4 + w

	"xdotool selectwindow windowfocus"
	mod4 + z
 
	"xdotool selectwindow windowkill"
	mod4 + q
