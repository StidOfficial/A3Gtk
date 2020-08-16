#ifndef SPLASHSCREEN_H
#define SPLASHSCREEN_H

#include <A3Gtk/splashwindow.hpp>

class SplashScreen : public A3Gtk::SplashWindow
{
public:
	SplashScreen();
	~SplashScreen();
private:
	Glib::RefPtr<Gdk::Pixbuf> m_icon;
	A3Gtk::SplashWindow m_splash_window;
	int m_level;
protected:
	bool on_timeout();
	sigc::connection m_connection_timeout;
};

#endif
