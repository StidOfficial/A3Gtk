#ifndef SPLASHWINDOW_H
#define SPLASHWINDOW_H

#include <gtkmm/window.h>
#include <gdkmm/pixbuf.h>
#include <string>

namespace A3Gtk
{
	class SplashWindow : public Gtk::Window
	{
	public:
		SplashWindow();
		~SplashWindow();
		void set_progress_max(int progress_max);
		int get_progress_max();
		void set_progress(int progress);
		int get_progress();
		void set_text(std::string text);
		std::string get_text();
	private:
		Glib::RefPtr<Gdk::Pixbuf> m_image;
		int m_progress_max;
		int m_progress;
		Cairo::TextExtents m_text_extents;
		std::string m_text;

		void redraw();
	protected:
		virtual bool on_draw(const Cairo::RefPtr< ::Cairo::Context>& cr) override;
		virtual void on_screen_changed(const Glib::RefPtr<Gdk::Screen>& previous_screen) override;
	};
}

#endif
