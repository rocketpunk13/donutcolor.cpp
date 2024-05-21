#include <iostream>
#include <string.h>
#include <math.h>
#include <unistd.h>
const char* colors[]={
    "\x1b[30m", // Black
    "\x1b[31m", // Red
    "\x1b[32m", // Green
    "\x1b[33m", // Yellow
    "\x1b[34m", // Blue
    "\x1b[35m", // Magenta
    "\x1b[36m", // Cyan
    "\x1b[37m"  // White
};
int main() {
    float A=0;
    float B=0;
    float i, j;
    int k;
    float z[1760];
    char b[1760];
    printf("\x1b[2J");
    for(;;) {
        memset(b,32,1760);
        memset(z,0,7040);
        for(j=0; j<6.28;j+=0.07) {
            for(i=0;i<6.28;i+=0.02) {
                float c=sin(i);
                float d=cos(j);
                float e=sin(A);
                float f= sin(j);
                float g= cos(A);
                float h= d+2;
                float D= 1/(c*h*e+f*g+5);
                float l= cos(i);
                float m= cos(B);
                float n= sin(B);
                float t= c*h*g-f*e;
                int x= 40+30*D*(l*h*m-t*n);
                int y= 12+15*D*(l*h*n+t*m);
                int o= x+80*y;
                int N= 8*((f*e-c*d*g)*m-c*d*e-f*g-l*d*n);
                if(22>y && y>0 && x>0 && 80>x && D>z[o]) {
                    z[o] = D;
                    b[o] = "...,,,ooo000"[N > 0 ? N : 0];
                }
            }
        }
        printf("\x1b[H");
         for(k=0;k<1761;k++) {
            if (k%80==0) {
                putchar(10);
            } 
            else {
                char ch=b[k];
                if (ch==' ') {
                    printf(" ");
                } 
                else {
                    int color_index = (ch-'.')%8;
                    printf("%s%c\x1b[0m",colors[color_index],ch);
                }
            A += 0.00004;
            B += 0.00002;
        }
        usleep(30000);
    }
    return 0;
}
}
