#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<windows.h>

#define WIDTH 80
#define HEIGHT 25

int ballX , ballY;
int ballvelocityX , ballvelocityY;

void setup(){
    ballX = WIDTH / 2;
    ballY = HEIGHT /2;
    ballvelocityX = 1;
    ballvelocityY = 1;
}
void draw(){
    system("cls");

    for(int Y = 0; Y<HEIGHT; Y++){
        for(int X = 0;X< WIDTH; X++){
            if ( X == ballX && Y == ballY)
{
    printf("0");   
}  else{
    printf(" ");
}          
        }
        printf("\n");
    }
}
void update(){
    ballX += ballvelocityX;
    ballY += ballvelocityY;

    if (ballX <= 0 || ballX >= WIDTH -1)
    {
        ballvelocityX = -ballvelocityX;
    }

    if (ballY <= 0 || ballY >= HEIGHT - 1 )
    {
        ballvelocityY = -ballvelocityY;
    }
}
int main(){
    setup();

    while (1){
        draw();
        update();
    }
    return 0;
}
