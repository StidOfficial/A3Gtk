#include "examplewindow.hpp"

#include <gtkmm/main.h>
#include <gtkmm/stylecontext.h>
#include <gtkmm/cssprovider.h>

#include <iostream>

int main(int argc, char* argv[])
{
	auto app = Gtk::Application::create(argc, argv, "org.a3gtk.teststyle");

	ExampleWindow window;

	Glib::RefPtr<Gtk::CssProvider> style = Gtk::CssProvider::create();
	try
	{
		style->load_from_path("style.css");
	}
	catch(Gtk::CssProviderError& err)
	{
		std::cerr << err.what() << std::endl;
		return 1;
	}

	Glib::RefPtr<Gdk::Screen> screen = window.get_screen();
	auto context = window.get_style_context();
	context->add_provider_for_screen(screen, style, GTK_STYLE_PROVIDER_PRIORITY_USER);

	return app->run(window);
}
