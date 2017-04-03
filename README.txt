Project 2

Character Piggydroid, imaginative character from angrybirds.

Constructed 3d model of piggydroid with help of sphere, cylinders and boxex.
glrotated,glscaled,gltranslated are used to construct and lace the model in the space.

Multiple sliders are used for movements and different action and options for the user to change the position and add more charater.

hierarchical approach has been implemented for hands and legs and root ast the whole model

lookAt(double *eye, double *at, double *up) is implemented inside camera.cpp and defined under camera.cpp
this is similar to glulookat but uses 4x4 matrices to store values and position the screen

animate
the draw function is called 30 times each second so the counter is used and increamented at the end of draw function so it increaments 30 times per second which can be used to translate or rotate
the values increamented is been used to rotate the leg to and fro and also egg rolls from one point to other and rolls backs again. all these animation is done just by increament counters.

Artifacts to show.
Gif1 image name is artifact.gif
bmp image is save.bmp
movie gif artifact_mov.gif
 the artifact shows the animation and multiple addons for the project.

/*Extra Credits Worked on*/
 ~default light source            		: added one more light and changed the background in modeler.cpp
 ~adjustable levels of detail     		: added level of details to hand. so that on slider movement the levels dec and increase.
 ~widgets that control adjustable parameters    : Added one more model of th piggy on slider movement pig 2 can be added and also conveting sphere joints to square joints
 ~"Frame All					: Frame all feature is added in the option-> View -> Frame All.
 ~camera code has a constrained up vector	: Camera twist is implemeted and binded the function to "contol + Mouseclick". Hold the ctrl and mouseclick and drag to twist.
 ~drawing a new type of primitive		: New primitive called drawExcrudedCurves is added to the mode. to see the curve uncomment at line 60 in sample.cpp
 ~controls depending on what mood 		: A slider of angry mood is added to the model which acts by keeping the hands angled to body, eyes moved up and tongue hidden
						  All the other slider changes doesnot affect this angry mood implementation.

	
