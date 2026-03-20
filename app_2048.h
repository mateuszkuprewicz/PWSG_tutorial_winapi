#pragma once
#include <windows.h>
#include "board.h"
#include <string>
#include <chrono>

class app_2048
{
private:
	POINT m_screen_size;
	board m_board;
	HBRUSH m_field_brush;
	void on_window_move(HWND window, LPWINDOWPOS params);
	void update_transparency();
	bool register_class();
	void on_command(WORD cmdID);
	void on_paint(HWND window);
	static constexpr UINT_PTR s_timer = 1;
	std::chrono::time_point<std::chrono::system_clock>
		m_startTime;
	void on_timer();
	static std::wstring const s_class_name;
	static LRESULT CALLBACK window_proc_static(
		HWND window, UINT message,
		WPARAM wparam, LPARAM lparam);
	LRESULT window_proc(
		HWND window, UINT message,
		WPARAM wparam, LPARAM lparam);
	HWND create_window(DWORD style, HWND parent = nullptr, DWORD ex_style = 0);
	HINSTANCE m_instance;
	HWND m_main, m_popup;
public:
	app_2048(HINSTANCE instance);
	int run(int show_command);
};