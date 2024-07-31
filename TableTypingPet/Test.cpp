#include "SDL.h"
#include "SDL_image.h"
#include <stdio.h>

int main(int argc, char* argv[])
{

    // 初始化sdl
    if (SDL_Init(SDL_INIT_VIDEO) != 0)
    {
        printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
        return -1;
    }

    // 初始化sdl image
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

    // 计算右下角位置
    int windowI = width - windowWidth - 50;
    int windowJ = height - windowHeight - 100;

    //创建窗口
    SDL_Window* window = SDL_CreateWindow("SDL Image Example", windowI, windowJ, windowWidth, windowHeight, SDL_WINDOW_RESIZABLE | SDL_WINDOW_BORDERLESS);
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

    //加载图像
    SDL_Surface* surface = IMG_Load(R"(C:\\Users\\32331\\Desktop\\ori.png)");
    if (surface == nullptr)
    {
        printf("Unable to load image! SDL_image Error: %s\n", IMG_GetError());
        return -1;
    }

    // 转换为纹理并且渲染
    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_FreeSurface(surface);
    if (texture == nullptr)
    {
        printf("Unable to create texture! SDL Error: %s\n", SDL_GetError());
        return -1;
    }

    // 定义图像位置和大小
    SDL_Rect imageRect = { 100, 100, surface->w, surface->h };

    //加载左手图像
    SDL_Surface* surfaceLeft = IMG_Load(R"(C:\Users\32331\Desktop\Left.png)");
    if (surfaceLeft == nullptr)
    {
        printf("Unable to load left hand image! SDL_image Error: %s\n", IMG_GetError());
        return -1;
    }

    // 转换为纹理并且渲染
    SDL_Texture* textureLeft = SDL_CreateTextureFromSurface(renderer, surfaceLeft);
    SDL_FreeSurface(surfaceLeft);
    if (textureLeft == nullptr)
    {
        printf("Unable to create texture! SDL Error: %s\n", SDL_GetError());
        return -1;
    }

    //加载右手图像
    SDL_Surface* surfaceRight = IMG_Load(R"(C:\Users\32331\Desktop\Right.png)");
    if (surfaceRight == nullptr)
    {
        printf("Unable to load right hand image! SDL_image Error: %s\n", IMG_GetError());
        return -1;
    }

    // 转换为纹理并且渲染
    SDL_Texture* textureRight = SDL_CreateTextureFromSurface(renderer, surfaceRight);
    SDL_FreeSurface(surfaceRight);
    if (textureRight == nullptr)
    {
        printf("Unable to create texture! SDL Error: %s\n", SDL_GetError());
        return -1;
    }

    // 渲染图形
    SDL_RenderClear(renderer);
    SDL_RenderCopy(renderer, texture, NULL, NULL);
    SDL_RenderPresent(renderer);

    // 设置键盘集合
    const Uint8* LKeySates = SDL_GetKeyboardState(NULL);
    const Uint8* RKeySates = SDL_GetKeyboardState(NULL);
    const SDL_Scancode Lkeys[] = { SDL_SCANCODE_Q, SDL_SCANCODE_W, SDL_SCANCODE_E, SDL_SCANCODE_R,
                                   SDL_SCANCODE_A, SDL_SCANCODE_S, SDL_SCANCODE_D, SDL_SCANCODE_F,
                                   SDL_SCANCODE_Z, SDL_SCANCODE_X, SDL_SCANCODE_C, SDL_SCANCODE_V,
                                   SDL_SCANCODE_T, SDL_SCANCODE_G, SDL_SCANCODE_B };
    const SDL_Scancode Rkeys[] = { SDL_SCANCODE_Y, SDL_SCANCODE_U, SDL_SCANCODE_I, SDL_SCANCODE_O,
                                   SDL_SCANCODE_P, SDL_SCANCODE_H, SDL_SCANCODE_J, SDL_SCANCODE_K,
                                   SDL_SCANCODE_L, SDL_SCANCODE_B, SDL_SCANCODE_N, SDL_SCANCODE_M };
    int LKeySetSize = sizeof(Lkeys) / sizeof(Lkeys[0]);
    int RKeySetSize = sizeof(Rkeys) / sizeof(Lkeys[0]);

    // 添加事件监听
    SDL_Event event;
    bool loop = true;
    bool Act = true;
    while (loop)
    {
        while (SDL_PollEvent(&event))
        {
            switch (event.type)
            {

            case SDL_QUIT:
                loop = false;
                break;

            case SDL_KEYDOWN:
                if (Act)
                {
                    for (int i = 0; i < LKeySetSize; i++)
                    {
                        if (event.key.keysym.scancode == Lkeys[i])
                        {
                            SDL_RenderClear(renderer);
                            SDL_RenderCopy(renderer, textureLeft, NULL, NULL);
                            SDL_RenderPresent(renderer);
                        }
                    }
                    for (int j = 0; j < RKeySetSize; j++)
                    {
                        if (event.key.keysym.scancode == Rkeys[j])
                        {
                            SDL_RenderClear(renderer);
                            SDL_RenderCopy(renderer, textureRight, NULL, NULL);
                            SDL_RenderPresent(renderer);
                        }
                    }
                }
                break;

            // 添加焦点判断 
            case SDL_WINDOWEVENT:
                if (event.window.event == SDL_WINDOWEVENT_FOCUS_GAINED)
                {
                    Act = true;
                }
                else if (event.window.event == SDL_WINDOWEVENT_FOCUS_LOST)
                {
                    Act = true;
                }
                break;

            case SDL_KEYUP:
                if (Act)
                {
                    SDL_RenderClear(renderer);
                    SDL_RenderCopy(renderer, texture, NULL, NULL);
                    SDL_RenderPresent(renderer);
                }
            }
        }
    }

    // 释放内存
    SDL_DestroyTexture(texture);
    SDL_DestroyTexture(textureLeft);
    SDL_DestroyTexture(textureRight);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    IMG_Quit();
    SDL_Quit();

    return 0;
}