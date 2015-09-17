#ifndef __GWND__
#define __GWND__
#include "GuiObject.h"
#include "GFrame.h"

class GWnd: public GuiObject{
private:
	static LRESULT CALLBACK WndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam);

public:
	GWnd(
		GuiObjId id,
		float width,
		float height,
		const GString& caption,
		GWnd* parent_wnd = nullptr,
		DWORD style = WS_CHILD | WS_POPUP | WS_BORDER | WS_THICKFRAME | WS_CAPTION
		);
	~GWnd();

	void createWindow();
	void destroyWindow();
	void showWindow(int sw = SW_SHOWNORMAL);
	void updateWindow();
	void setParentWindow(GWnd* parent);
	void setFrame(GFrame* frame);
	HWND getWin32Window() const;
	GWnd* getParentWnd();
	const GWnd* getParentWnd() const;



private:
	GWnd* m_hParentWnd;
	HWND m_hWnd;
	GFrame* m_gfFrame;
	DWORD m_dwStyle;

protected:
	gm_msg LRESULT OnEvent(UINT message, WPARAM wParam, LPARAM lParam);
	gm_msg void OnPrepareStyle(WindowStyleExA& style) {};
	gm_msg void OnCreate(HWND hwnd) {};
	gm_msg void OnDestroy(HWND hwnd) {};

	gm_msg void OnChar(char input) {};

	gm_msg void OnKeyDown(char key) {};
	gm_msg void OnKeyUp(char key) {};
	gm_msg void OnLButtonDblClk(const Vec2& point) {};
	gm_msg void OnLButtonDown(const Vec2& point) {};
	gm_msg void OnLButtonUp(const Vec2& point) {};
	gm_msg void OnLMuttonDblClk(const Vec2& point) {};
	gm_msg void OnMButtonDown(const Vec2& point) {};
	gm_msg void OnMButtonUp(const Vec2& point) {};
	gm_msg void OnRButtonDblClk(const Vec2& point) {};
	gm_msg void OnRButtonDown(const Vec2& point) {};
	gm_msg void OnRButtonUp(const Vec2& point) {};

	gm_msg void OnMouseWheel() {};
	gm_msg void OnMouseMove(const Vec2& point) {};
	gm_msg void OnMouseIn(const Vec2& point) {};
	gm_msg void OnLBDownMouseIn(const Vec2& point) {};


	gm_msg void OnClickDestroy() {};
	gm_msg void OnClickMaximun() {};
	gm_msg void OnClickMinimun() {};

};
#endif