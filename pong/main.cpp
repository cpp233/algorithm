#include <iostream>
#include <ctime>
#include <cstdlib>
#include <conio.h>
#include <windows.h>

// 画面刷新
void gotoxy(short x, short y){
    COORD coord = {x, y};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
// 隐藏光标防止闪烁
void hideCursor(){
    CONSOLE_CURSOR_INFO cursor_info = {1, 0};
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor_info);
}

int main(int argc, char const *argv[])
{
    // 1.初始化
    auto WIDTH{120}, HEIGHT{40};            // 窗口长宽
    auto ball_x{WIDTH/2},                   // 球X轴位置
         ball_y{HEIGHT/2},                  // 球Y轴位置
         ball_vec_x{0},                     // 球X轴速度
         ball_vec_y{0};                     // 球X轴速度
    auto paddle_w{4}, paddle_h{10};         // 挡板长宽
    auto paddle1_x{1},
         paddle1_y{HEIGHT/2-paddle_h/2},    // 挡板1的坐标
         paddle1_vec{3};                    // 挡板1的速度
    auto paddle2_x{WIDTH - paddle_w},
         paddle2_y{HEIGHT/2-paddle_h/2},    // 挡板2的坐标
         paddle2_vec{3};                    // 挡板2的速度
    auto score1{0}, score2{0};              // 得分

    // 2.初始化小球运动
    const int speed = 3;
    srand( (unsigned)time(0));
    ball_vec_x = rand() % speed + 1;
    ball_vec_y = rand() % speed + 1;
    if(rand() % 2 == 1){
        ball_vec_x = -ball_vec_x;
    }
    if(rand() % 2 == 1){
        ball_vec_y = -ball_vec_y;
    }

    // 3. 游戏循环
    while (true)
    {
        // 3.1 处理事件
        char key;
        if(_kbhit()){               // 检测是否有按键信息
            key = getch();          // 得到按键字符
            if( (key == 'w' || key == 'W') && paddle1_y > paddle1_vec){
                paddle1_y -= paddle1_vec;
            }
            else if( (key == 's' || key == 'S') && 
            paddle1_y + paddle1_vec + paddle_h < HEIGHT){
                paddle1_y += paddle1_vec;
            }
            else if( key == 72 && paddle2_y > paddle2_vec){
                paddle2_y -= paddle2_vec;
            }
            else if( (key == 80) && paddle2_y + paddle2_vec + 
            paddle_h < HEIGHT){
                paddle2_y += paddle2_vec;
            }
        }




        // 3.2 更新数据
        ball_x += ball_vec_x;
        ball_y += ball_vec_y;
        if(ball_y < 0 || ball_y >= HEIGHT){
            ball_vec_y = -ball_vec_y;    //上下墙壁碰到改变垂直速度方向
        }
        if(ball_x < paddle_w && ball_y >= paddle1_y &&
           ball_y < paddle1_y + paddle_h){
            ball_vec_x = -ball_vec_x;   // 左边挡板和球撞击判断
        }else if(ball_x > WIDTH - paddle_w && ball_y >= paddle2_y &&
            ball_y < paddle2_y + paddle_h){
            ball_vec_x = -ball_vec_x;   // 左边挡板和球撞击判断
        }
        bool isOut = {false};           // 出边界判定
        if(ball_x < 0){
            score2 += 1;
            isOut = true;
        }else if(ball_x > WIDTH - paddle_w){
            score1 += 1;
            isOut = true;
        }
        if(isOut){
            ball_x = WIDTH / 2;
            ball_y = HEIGHT / 2;
            ball_vec_x = rand() % speed + 1;
            ball_vec_y = rand() % speed + 1;
            if(rand() % 2 == 1){
                ball_vec_x = -ball_vec_x;
            }
            if(rand() % 2 == 1){
                ball_vec_y = -ball_vec_y;
            }
        }

        gotoxy(0, 0);           // 定位到0，0，相当于清空屏幕
        hideCursor();           // 异常光标

        // 3.3 绘制背景
        // 3.3.1 绘制顶部墙
        for(auto x = 0; x <= WIDTH; ++x){
            std::cout << '=';
        }
        std::cout << '\n';
        // 3.3.2 绘制中间的内容
        for(auto y = 0; y < HEIGHT; ++y){
            for(auto x = 0; x <= WIDTH; ++x){
                if(x == ball_x && y == ball_y){
                    std::cout << 'O';
                }else if(y >= paddle1_y && y < paddle1_y + paddle_h&&
                        x >= paddle1_x && x < paddle1_x + paddle_w){
                    std::cout << 'N';
                }else if(y >= paddle2_y && y < paddle2_y + paddle_h &&
                        x >= paddle2_x && x < paddle2_x + paddle_w){
                    std::cout << 'Z';
                }else if(x == 0 || x == WIDTH/2 || x == WIDTH){
                    std::cout << '|';
                }else{
                    std::cout << ' ';
                }
                
            }
            std::cout << '\n';
        }
        // 3.3.3 绘制底部的墙
        for(auto x = 0; x <= WIDTH; ++x){
            std::cout << '=';
        }
        // Sleep(10);
    }
    

     
    return 0;
}
