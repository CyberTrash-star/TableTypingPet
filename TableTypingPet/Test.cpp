#include "SDL.h"
#include "SDL_image.h"
#include <stdio.h>
#include <Windows.h>

HHOOK hKeyHook;
bool Act = true;
bool isQKeyPressed = false; // 标记键盘是否被按下
bool isWKeyPressed = false;
bool isEKeyPressed = false;
bool isRKeyPressed = false;
bool isTKeyPressed = false;
bool isAKeyPressed = false;
bool isSKeyPressed = false;
bool isDKeyPressed = false;
bool isFKeyPressed = false;
bool isGKeyPressed = false;
bool isZKeyPressed = false;
bool isXKeyPressed = false;
bool isCKeyPressed = false;
bool isVKeyPressed = false;
bool isYKeyPressed = false;
bool isUKeyPressed = false;
bool isIKeyPressed = false;
bool isOKeyPressed = false;
bool isPKeyPressed = false;
bool isHKeyPressed = false;
bool isJKeyPressed = false;
bool isKKeyPressed = false;
bool isLKeyPressed = false;
bool isBKeyPressed = false;
bool isNKeyPressed = false;
bool isMKeyPressed = false;

LRESULT CALLBACK KeyProc(int nCode, WPARAM wParam, LPARAM lParam)
{
    if (nCode >= 0)
    {
        KBDLLHOOKSTRUCT* pKeyboard = (KBDLLHOOKSTRUCT*)lParam;

        if (wParam == WM_KEYDOWN || wParam == WM_SYSKEYDOWN)
        {
            if (Act)
            {
                switch (pKeyboard->vkCode)
                {
                case 0x57:
                    isWKeyPressed = true;
                    break;
                case 0x51:
                    isQKeyPressed = true;
                    break;
                case 0x45:
                    isEKeyPressed = true;
                    break;
                case 0x52:
                    isRKeyPressed = true;
                    break;
                case 0x54:
                    isTKeyPressed = true;
                    break;
                case 0x41:
                    isAKeyPressed = true;
                    break;
                case 0x53:
                    isSKeyPressed = true;
                    break;
                case 0x44:
                    isDKeyPressed = true;
                    break;
                case 0x46:
                    isFKeyPressed = true;
                    break;
                case 0x47:
                    isGKeyPressed = true;
                    break;
                case 0x5A:
                    isAKeyPressed = true;
                    break;
                case 0x58:
                    isXKeyPressed = true;
                    break;
                case 0x43:
                    isCKeyPressed = true;
                    break;
                case 0x56:
                    isVKeyPressed = true;
                    break;


                case 0x59:
                    isYKeyPressed = true;
                    break;
                case 0x55:
                    isUKeyPressed = true;
                    break;
                case 0x49:
                    isIKeyPressed = true;
                    break;
                case 0x4F:
                    isOKeyPressed = true;
                    break;
                case 0x50:
                    isPKeyPressed = true;
                    break;
                case 0x48:
                    isHKeyPressed = true;
                    break;
                case 0x4A:
                    isJKeyPressed = true;
                    break;
                case 0x4B:
                    isKKeyPressed = true;
                    break;
                case 0x4C:
                    isLKeyPressed = true;
                    break;
                case 0x42:
                    isBKeyPressed = true;
                    break;
                case 0x4E:
                    isNKeyPressed = true;
                    break;
                case 0x4D:
                    isMKeyPressed = true;
                    break;
                }
            }
        }
        else if (wParam == WM_KEYUP || wParam == WM_SYSKEYUP)
        {
            switch (pKeyboard->vkCode)
            {
            case 0x57:
                isWKeyPressed = false;
                break;
            case 0x51:
                isQKeyPressed = false;
                break;
            case 0x45:
                isEKeyPressed = false;
                break;
            case 0x52:
                isRKeyPressed = false;
                break;
            case 0x54:
                isTKeyPressed = false;
                break;
            case 0x41:
                isAKeyPressed = false;
                break;
            case 0x53:
                isSKeyPressed = false;
                break;
            case 0x44:
                isDKeyPressed = false;
                break;
            case 0x46:
                isFKeyPressed = false;
                break;
            case 0x47:
                isGKeyPressed = false;
                break;
            case 0x5A:
                isAKeyPressed = false;
                break;
            case 0x58:
                isXKeyPressed = false;
                break;
            case 0x43:
                isCKeyPressed = false;
                break;
            case 0x56:
                isVKeyPressed = false;
                break;


            case 0x59:
                isYKeyPressed = false;
                break;
            case 0x55:
                isUKeyPressed = false;
                break;
            case 0x49:
                isIKeyPressed = false;
                break;
            case 0x4F:
                isOKeyPressed = false;
                break;
            case 0x50:
                isPKeyPressed = false;
                break;
            case 0x48:
                isHKeyPressed = false;
                break;
            case 0x4A:
                isJKeyPressed = false;
                break;
            case 0x4B:
                isKKeyPressed = false;
                break;
            case 0x4C:
                isLKeyPressed = false;
                break;
            case 0x42:
                isBKeyPressed = false;
                break;
            case 0x4E:
                isNKeyPressed = false;
                break;
            case 0x4D:
                isMKeyPressed = false;
                break;
            }
        }
    }
    return CallNextHookEx(hKeyHook, nCode, wParam, lParam);
}

void InstallHook()
{
    hKeyHook = SetWindowsHookEx(WH_KEYBOARD_LL, KeyProc, GetModuleHandle(NULL), 0);
    if (hKeyHook == NULL)
    {
        printf("Failed to install hook!\n");
    }
}

void RemoveHook() 
{
    if (hKeyHook != NULL) 
    {
        UnhookWindowsHookEx(hKeyHook);
    }
}

int main(int argc, char* argv[]) 
{
    // sdl初始化
    if (SDL_Init(SDL_INIT_VIDEO) != 0) 
    {
        printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
        return -1;
    }

    // sdl image初始化
    if (IMG_Init(IMG_INIT_PNG) == 0) 
    {
        printf("SDL_image could not initialize! IMG_Error: %s\n", IMG_GetError());
        return -1;
    }

    // 获取屏幕尺寸
    SDL_DisplayMode DM;
    if (SDL_GetCurrentDisplayMode(0, &DM) != 0) 
    {
        printf("SDL_GetCurrentDisplayMode failed! SDL_Error: %s\n", SDL_GetError());
        return -1;
    }

    int width = DM.w;
    int height = DM.h;

    // 设置窗口大小
    int windowWidth = 230;
    int windowHeight = 200;

    // 计算屏幕右下角位置
    int windowI = width - windowWidth - 50;
    int windowJ = height - windowHeight - 100;

    // 创建显示窗口
    SDL_Window* window = SDL_CreateWindow("SDL Image Example", windowI, windowJ, windowWidth, windowHeight, SDL_WINDOW_RESIZABLE | SDL_WINDOW_BORDERLESS | SDL_WINDOW_INPUT_FOCUS);
    if (window == nullptr) 
    {
        printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
        return -1;
    }

    // 创建渲染器
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (renderer == nullptr) 
    {
        printf("Renderer could not be created! SDL_Error: %s\n", SDL_GetError());
        return -1;
    }

    // 加载初始图形
    SDL_Surface* surface = IMG_Load(R"(C:\Users\32331\Desktop\ori.png)");
    if (surface == nullptr) 
    {
        printf("Unable to load image! SDL_image Error: %s\n", IMG_GetError());
        return -1;
    }

    // 创建纹理 绘制
    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_FreeSurface(surface);
    if (texture == nullptr) 
    {
        printf("Unable to create texture! SDL Error: %s\n", SDL_GetError());
        return -1;
    }

    // 加载左手图形
    SDL_Surface* surfaceLeft = IMG_Load(R"(C:\Users\32331\Desktop\Left.png)");
    if (surfaceLeft == nullptr) 
    {
        printf("Unable to load left hand image! SDL_image Error: %s\n", IMG_GetError());
        return -1;
    }

    // 创建纹理 绘制
    SDL_Texture* textureLeft = SDL_CreateTextureFromSurface(renderer, surfaceLeft);
    SDL_FreeSurface(surfaceLeft);
    if (textureLeft == nullptr) 
    {
        printf("Unable to create texture! SDL Error: %s\n", SDL_GetError());
        return -1;
    }

    // 加载右手图形
    SDL_Surface* surfaceRight = IMG_Load(R"(C:\Users\32331\Desktop\Right.png)");
    if (surfaceRight == nullptr) 
    {
        printf("Unable to load right hand image! SDL_image Error: %s\n", IMG_GetError());
        return -1;
    }

    // 创建纹理 绘制
    SDL_Texture* textureRight = SDL_CreateTextureFromSurface(renderer, surfaceRight);
    SDL_FreeSurface(surfaceRight);
    if (textureRight == nullptr) 
    {
        printf("Unable to create texture! SDL Error: %s\n", SDL_GetError());
        return -1;
    }

    // 加载键盘钩子
    InstallHook();

    SDL_Event event;
    bool loop = true;

    // 窗口循环
    while (loop) 
    {
        while (SDL_PollEvent(&event)) 
        {
            if (event.type == SDL_QUIT) 
            {
                loop = false;
            }
        }

        // 根据键盘状态更新渲染
        SDL_RenderClear(renderer);
        if (isQKeyPressed || isWKeyPressed || isEKeyPressed || isRKeyPressed || isTKeyPressed || isAKeyPressed || isSKeyPressed || isDKeyPressed || isFKeyPressed || isGKeyPressed || isZKeyPressed || isXKeyPressed || isCKeyPressed || isVKeyPressed)
        {
            SDL_RenderCopy(renderer, textureLeft, NULL, NULL);
        }
        else if (isYKeyPressed || isUKeyPressed || isIKeyPressed || isOKeyPressed || isPKeyPressed || isHKeyPressed || isJKeyPressed || isKKeyPressed || isLKeyPressed || isBKeyPressed || isNKeyPressed || isMKeyPressed)
        {
            SDL_RenderCopy(renderer, textureRight, NULL, NULL);
        }
        else 
        {
            SDL_RenderCopy(renderer, texture, NULL, NULL);
        }
        SDL_RenderPresent(renderer);

        // 处理
        MSG msg;
        while (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE)) {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
    }

    RemoveHook();

    // 释放资源
    SDL_DestroyTexture(texture);
    SDL_DestroyTexture(textureLeft);
    SDL_DestroyTexture(textureRight);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    IMG_Quit();
    SDL_Quit();

    return 0;
}
