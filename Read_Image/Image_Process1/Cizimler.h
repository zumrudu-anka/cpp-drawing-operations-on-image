#include <windows.h>
#include <math.h>

BYTE* DrawLine(BYTE* Buffer, int width, int height, int xx1, int yy1, int xx2, int yy2);
BYTE* DrawCircle(BYTE* Buffer, int width, int height, int centerx, int centery,float radius);
BYTE* DrawEllipse(BYTE* Buffer, int width, int height, int centerx, int centery, int xrad, int yrad);