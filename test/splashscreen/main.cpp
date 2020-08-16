#include <gtkmm/main.h>

#include "splashscreen.hpp"

int main(int argc, char* argv[])
{
	auto app = Gtk::Application::create(argc, argv, "org.a3gtk.splash");

	SplashScreen splashScreen;
	return app->run(splashScreen);
}
