#include <windows.h> // Standard Windows header

#pragma comment(lib, "user32.lib")
#pragma comment(lib, "kernel32.lib")



int APIENTRY WinMain(HINSTANCE hInstance,
    HINSTANCE hPrevInstance,
    LPTSTR    lpCmdLine,
    int       nCmdShow)
{
    // Initialize input array
    INPUT inputs[2] = {};

    // Simulate "Next Track" key press
    inputs[0].type = INPUT_KEYBOARD;
    inputs[0].ki.wVk = VK_MEDIA_NEXT_TRACK;

    // Simulate "Next Track" key release
    inputs[1].type = INPUT_KEYBOARD;
    inputs[1].ki.wVk = VK_MEDIA_NEXT_TRACK;
    inputs[1].ki.dwFlags = KEYEVENTF_KEYUP;

    // Send the inputs
    UINT uSent = SendInput(ARRAYSIZE(inputs), inputs, sizeof(INPUT));

    // Check for errors
    if (uSent != ARRAYSIZE(inputs)) {
        DWORD error = GetLastError();
        // Handle error (logging or displaying an error message could be useful)
        return 1;
    }

    return 0; // Success
}