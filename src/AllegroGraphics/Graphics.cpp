// - ------------------------------------------------------------------------------------------ - //
#include "Graphics.h"
// - ------------------------------------------------------------------------------------------ - //
int ScreenWidth;
int ScreenHeight;

int ScreenScalar;
// - ------------------------------------------------------------------------------------------ - //
BITMAP* Buffer;

Matrix3x3 Matrix;

std::vector<Matrix3x3>* MatrixStack;

ColorType CurrentColor;
ColorType CurrentNormalColor;
Real CurrentNormalLength;
// - ------------------------------------------------------------------------------------------ - //
Vector2D CameraPos;
Real CameraScale;
// - ------------------------------------------------------------------------------------------ - //
volatile bool CloseButtonPressed;
// - ------------------------------------------------------------------------------------------ - //
void gfxCloseButtonHandler()
{
	CloseButtonPressed = true;
}
END_OF_FUNCTION(gfxCloseButtonHandler)
// - ------------------------------------------------------------------------------------------ - //
