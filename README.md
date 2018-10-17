## kcmouse ##
minimal window manager

Very minimal window manager using Windows Key + Mouse buttons for the following:

Button1 - lower the current focused window exposing what is underneath

Button2 - make window fullscreen and move to right monitor

Button3 - make window fullscreen and move to left monitor


to compile:  gcc -o kcmouse kcmouse.c -lX11


I recommend to use xbindkeys and xdotool for launching, focus, and kill functions.   

#Sample .xbindkeysrc:

	"dmenu_run"
	mod4 + r

	"xdotool selectwindow windowfocus"
	mod4 + x
 
	"xdotool selectwindow windowkill"
	mod4 + q
