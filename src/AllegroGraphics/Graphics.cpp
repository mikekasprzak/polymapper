// - ------------------------------------------------------------------------------------------ - //
#include "Graphics.h"
// - ------------------------------------------------------------------------------------------ - //
int ScreenWidth;
int ScreenHeight;

int ScreenScalar;

BITMAP* Buffer;

Matrix3x3 Matrix;

std::vector<Matrix3x3>* MatrixStack;

ColorType CurrentColor;
ColorType CurrentNormalColor;
Real CurrentNormalLength;
// - ------------------------------------------------------------------------------------------ - //
//bool
// - ------------------------------------------------------------------------------------------ - //
