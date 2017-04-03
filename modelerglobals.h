#ifndef _MODELER_GLOBALS_H
#define _MODELER_GLOBALS_H

#ifndef M_PI
#define M_PI 3.141592653589793238462643383279502
#endif

// This is a list of the controls for the SampleModel
// We'll use these constants to access the values 
// of the controls from the user interface.
enum SampleModelControls
{ 
	XPOS, YPOS, ROTATEX, ROTATEY, HJOINTS, EYES, LEVELS = 6, PIGY2, BOX, ANGRYMOOD, NUMCONTROLS,
};

// Colors
#define COLOR_RED		1.0f, 0.0f, 0.0f
#define COLOR_GREEN		0.0f, 1.0f, 0.0f
#define COLOR_BLUE		0.0f, 0.0f, 1.0f
#define COLOR_GREY      0.5f, 0.5f, 0.5f
#define COLOR_PIGREEN   0.43f, 0.89f, 0.33f
#define COLOR_WHITE     1.0f, 1.0f, 1.0f
#define COLOR_BLACK     0.0f, 0.0f, 0.0f
#define COLOR_NOSEYELL  0.65f, 0.92f, 0.0f
#define COLOR_NOSTRIL   0.05f, 0.2f, 0.02f
#define COLOR_TONGUE    0.67f, 0.26f, 0.20f
#define COLOR_PIG2      0.42f, 0.72f, 0.03f

// We'll be getting the instance of the application a lot; 
// might as well have it as a macro.
#define VAL(x) (ModelerApplication::Instance()->GetControlValue(x))

#endif