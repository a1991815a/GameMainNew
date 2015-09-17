#include <windows.h>
#include "Win32Utils.h"
#include "Director.h"
#include "AppDelegate.h"

// int main() {
// 	
// 	
// 	return 0;
// };

int WINAPI WinMain(
	_In_ HINSTANCE hInstance, 
	_In_opt_ HINSTANCE hPrevInstance, 
	_In_ LPSTR lpCmdLine,
	_In_ int nShowCmd )
{
	AppDelegate app;


	return app.run();
}