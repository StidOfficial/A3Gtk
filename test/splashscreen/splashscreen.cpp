#include "splashscreen.hpp"

#include <gtkmm.h>

SplashScreen::SplashScreen() :
	m_splash_window(),
	m_level(0)
{
	m_icon = Gdk::Pixbuf::create_from_resource("/resources/images/Arma3.png");
	set_icon(m_icon);
	set_wmclass("SplashScreen", "Splash Screen");
	set_title("Arma 3");

	m_connection_timeout = Glib::signal_timeout().connect(sigc::mem_fun(*this, &SplashScreen::on_timeout), 300);
}

bool SplashScreen::on_timeout()
{
	switch(m_level)
	{
		case 0:
		{
			set_progress(0);
			set_text("STARTING UP");
			break;
		}
		case 1:
		{
			set_progress(10);
			set_text("LOADING CORE CONFIGS");
			break;
		}
		case 2:
		{
			set_progress(20);
			set_text("REGISTERING PLUGINS");
			break;
		}
		case 3:
		{
			set_progress(30);
			set_text("PARSING CONFIGS");
			break;
		}
		case 4:
		{
			set_progress(40);
			set_text("PROCESSING COMMAND LINE");
			break;
		}
		case 5:
		{
			set_progress(50);
			set_text("LOADING ADDONS");
			break;
		}
		case 6:
		{
			set_progress(60);
			set_text("INITIALIZING ADDONS");
			break;
		}
		case 7:
		{
			set_progress(70);
			set_text("INITIALIZING INPUT");
			break;
		}
		case 8:
		{
			set_progress(80);
			set_text("LOADING PROFILE OPTIONS");
			break;
		}
		case 9:
		{
			set_progress(90);
			set_text("INITIALIZING MODS");
			break;
		}
		case 10:
		{
			set_progress(100);
			set_text("STARTING THE GAME");
			break;
		}
		default:
		{
			m_level = 0;
			return true;
		}
	}

	m_level++;

	return true;
}

SplashScreen::~SplashScreen()
{
}
