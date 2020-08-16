#include <A3Gtk/splashwindow.hpp>

#include <gdkmm/general.h>

namespace A3Gtk
{
	SplashWindow::SplashWindow() :
		m_progress_max(100),
		m_progress(0)
	{
		m_image = Gdk::Pixbuf::create_from_resource("/resources/images/splash.png");

		if(m_image)
			set_size_request(m_image->get_width(), m_image->get_height());

		set_decorated(false);
		set_resizable(false);
		set_position(Gtk::WIN_POS_CENTER);
		set_app_paintable(true);

		on_screen_changed(get_screen());
	}

	void SplashWindow::set_progress_max(int progress_max)
	{
		if(progress_max <= 0)
			throw std::logic_error("Wrong number");

		m_progress_max = progress_max;

		redraw();
	}

	int SplashWindow::get_progress_max()
	{
		return m_progress_max;
	}

	void SplashWindow::set_progress(int progress)
	{
		if(progress < 0 && progress < get_progress_max())
			throw std::logic_error("Wrong number");

		m_progress = progress;

		redraw();
	}

	int SplashWindow::get_progress()
	{
		return m_progress;
	}

	void SplashWindow::set_text(std::string text)
	{
		m_text = text;

		redraw();
	}

	std::string SplashWindow::get_text()
	{
		return m_text;
	}

	void SplashWindow::redraw()
	{
		auto window = get_window();
		if(window)
		{
			Gdk::Rectangle rect(0, 0, get_allocation().get_width(),
						get_allocation().get_height());

			window->invalidate_rect(rect, false);
		}
	}

	bool SplashWindow::on_draw(const Cairo::RefPtr<Cairo::Context>& cr)
	{
		if(!m_image)
			return false;

		Gtk::Allocation allocation = get_allocation();
		const int width = allocation.get_width();
		const int height = allocation.get_height();

		Gdk::Cairo::set_source_pixbuf(cr, m_image, (width - m_image->get_width()), (height - m_image->get_height()));

		cr->paint();
		
		cr->set_source_rgb(0.7, 0.5, 0);
		cr->rectangle(82, 201, (348 * get_progress()) / get_progress_max(), 5);
		cr->fill();

		cr->set_source_rgb(0.7, 0.7, 0.7);
		cr->select_font_face("Arial", Cairo::FontSlant::FONT_SLANT_NORMAL, Cairo::FontWeight::FONT_WEIGHT_BOLD);
		cr->set_font_size(13);
		cr->get_text_extents(get_text(), m_text_extents);
		cr->move_to(82 + (174 - m_text_extents.width / 2), 225);
		cr->show_text(get_text());

		return Gtk::Window::on_draw(cr);
	}

	void SplashWindow::on_screen_changed(const Glib::RefPtr<Gdk::Screen>& previous_screen)
	{
		auto screen = get_screen();
		auto visual = screen->get_rgba_visual();

		gtk_widget_set_visual(GTK_WIDGET(gobj()), visual->gobj());
	}

	SplashWindow::~SplashWindow()
	{
	}
}
