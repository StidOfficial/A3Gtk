#include <gtkmm/main.h>
#include <gtkmm/window.h>
#include <gtkmm/button.h>
#include <gtkmm/stylecontext.h>
#include <gtkmm/cssprovider.h>
#include <gtkmm/messagedialog.h>

#include <iostream>

int main(int argc, char* argv[])
{
	Gtk::Main app(argc, argv);
	Gtk::Window window;

	window.set_title("Text");

	Glib::RefPtr<Gtk::CssProvider> style = Gtk::CssProvider::create();
	if(not style->load_from_path("style.css"))
	{
		std::cerr << "Failed to load style" << std::endl;
		return 1;
	}

	Glib::RefPtr<Gdk::Screen> screen = Gdk::Screen::get_default();
	auto context = window.get_style_context();
	context->add_provider_for_screen(screen, style, GTK_STYLE_PROVIDER_PRIORITY_USER);

	Gtk::MessageDialog dialog(*window, "This is a QUESTION MessageDialog", false, Gtk::MESSAGE_QUESTION, Gtk::BUTTONS_OK_CANCEL);
	dialog.set_secondary_text("And this is the secondary text that explains things.");

	int result = dialog.run();

	app.run(window);

	return 0;
}
