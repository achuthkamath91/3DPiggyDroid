// The sample model.  You should build a file
// very similar to this for when you make your model.
#include "modelerview.h"
#include "modelerapp.h"
#include "modelerdraw.h"
#include <FL/gl.h>

#include "modelerglobals.h"

// To make a SampleModel, we inherit off of ModelerView
class SampleModel : public ModelerView 
{
public:
    SampleModel(int x, int y, int w, int h, char *label) 
        : ModelerView(x,y,w,h,label) { }
	int kick = 0,act = 0;
	float  sendoff = 0;
	bool back = true;
	bool front = false;
	bool eggRotate = false;
	//bool ballFront = false;
    virtual void draw();

};

// We need to make a creator function, mostly because of
// nasty API stuff that we'd rather stay away from.
ModelerView* createSampleModel(int x, int y, int w, int h, char *label)
{ 
    return new SampleModel(x,y,w,h,label); 
}

// We are going to override (is that the right word?) the draw()
// method of ModelerView to draw out SampleModel
void SampleModel::draw()
{
    // This call takes care of a lot of the nasty projection 
    // matrix stuff.  Unless you want to fudge directly with the 
	// projection matrix, don't bother with this ...
	
	//
	// 3D Model of Piggydroid
	ModelerView::draw();
	
	if (ModelerApplication::Instance()->m_animating == false){
		kick = 0;
		eggRotate = false;
		sendoff = 0;
	}
	// draw the floor
	setAmbientColor(.3f, .9f, .9f);
	setDiffuseColor(COLOR_GREEN);
	//setShininess(3.5);
	glPushMatrix();
	glTranslated(-5, -3.2, -5);
	drawBox(10, 0.02f, 16);
	glPopMatrix();

	// Uncomment to see curves
	/*glPushMatrix();
	setDiffuseColor(COLOR_WHITE);
	glRotated(00, 1.0, 0.0, 0.0);
	glTranslated(-6.3, -3.0, 0.0);
	glScaled(1.0, 1.0, 1.0);
	drawExcrudedCurves();
	glPopMatrix();*/
	

	// whole model
	glPushMatrix();
	setDiffuseColor(COLOR_GREEN);
	glTranslated(VAL(XPOS), VAL(YPOS), -1.9);
	
	glRotated(VAL(ROTATEX), 1.0, 0.0, 0.0); 
	glRotated(VAL(ROTATEY), 0.0, 1.0, 0.0); 

	//draw head  
	setAmbientColor(.1f, .1f, .1f); 
	setDiffuseColor(COLOR_PIGREEN);
		glPushMatrix();
		glTranslated(0.0, 3.0, 0.0);
		glScaled(1.0, 1.0, 0.6);
		drawSphere( 1.5 );
	

			//draw Eyes
			//Left eye
			setDiffuseColor(COLOR_WHITE);
			glPushMatrix();
			if (VAL(ANGRYMOOD) == 0){
				glTranslated(-0.9, 0.25, 1.3);
			}
			else{
				glTranslated(-0.7, 0.35, 1.3);
			}
			
			glScaled(1.0, 1.0, 1.0);
			drawSphere( 0.3 );			
				// Black irish
				glPushMatrix();
				setDiffuseColor(COLOR_BLACK);
				glTranslated(VAL(EYES), 0.0, 0.30);
				glScaled(0.5, 1.0, 0.1);
				drawSphere( 0.15 );
				glPopMatrix();
			glPopMatrix();

			//right eye
			setDiffuseColor(COLOR_WHITE);
			glPushMatrix();
			if (VAL(ANGRYMOOD) == 0){
				glTranslated(0.9, 0.25, 1.3);
			}
			else{
				glTranslated(0.7, 0.35, 1.3);
			}
			
			glScaled(1.0, 1.0, 1.0);
			drawSphere( 0.3 );
			// Black irish
				glPushMatrix();
				setDiffuseColor(COLOR_BLACK);
				glTranslated(VAL(EYES), 0.0, 0.30);
				glScaled(0.5, 1.0, 0.1);
				drawSphere( 0.15 );
				glPopMatrix();
			glPopMatrix();

			//Draw Nose
			glPushMatrix();
			setDiffuseColor(COLOR_NOSEYELL);
			glTranslated(0.0, 0.0, 1.0);
			drawCylinder(0.8, 0.4, 0.6);
			
				setDiffuseColor(COLOR_NOSTRIL);
				glPushMatrix();
				glTranslated(-0.3, 0.0, 0.8);
				glScaled(1.0, 1.2, 0.9);
				drawSphere( 0.20 );
				glPopMatrix();

				glPushMatrix();
				glTranslated(0.3, 0.0, 0.8);
				glScaled(1.0, 1.2, 0.9);
				drawSphere( 0.20 );
				glPopMatrix();

			glPopMatrix();
		
			//tounge
			if (VAL(ANGRYMOOD) == 0){
				setDiffuseColor(COLOR_TONGUE);
				glPushMatrix();
				glTranslated(-0.1, -0.6, 1.4);
				glScaled(1.0, 1.8, -0.9);
				drawSphere(0.20);
				glPopMatrix();
			}
			else{
			}
			// draw left ears
			setDiffuseColor(COLOR_PIGREEN);
			glPushMatrix();
			glTranslated(-0.8, 1.4, 0.0);
			glScaled(1.0, 1.8, -1.0);
			drawSphere( 0.20 );
			glPopMatrix();
		
			// draw right ears
			glPushMatrix();
			glTranslated(0.8, 1.4, 0.0);
			glScaled(1.0, 1.8, -1.0);
			drawSphere( 0.20 );
			glPopMatrix();

		glPopMatrix();
		//end of head
	
		//Body neck
		setDiffuseColor(COLOR_PIGREEN);
		glPushMatrix();
		glTranslated(0.0, 2.5, 0.0);
		glScaled(1.0, 1.0, 1.0);
		glRotated(90, 1.0, 0.0, 0.0);
		drawCylinder(1.1, 0.5, 1.0);
		glPopMatrix();

		//Body
		glPushMatrix();
		glTranslated(0.0, 1.4, 0.0);
		glScaled(1.0, 1.0, 1.0);
		glRotated(90, 1.0, 0.0, 0.0);
		drawCylinder(1.2, 1.0, 1.0);
			
			//Left side Shoulder joint
		if (VAL(LEVELS) >= 1){
			glPushMatrix();
			glRotated(-90, 1.0, 0.0, 0.0);
			if (VAL(BOX) == 1){
				glTranslated(-1.5, -0.5, -0.3);
				glScaled(1.0, 1.0, 1.0);
				drawBox(0.6, 0.6, 0.6);
			}
			else{
				glTranslated(-1.1, -0.2, 0.0);
				glScaled(1.0, 1.0, 1.0);
				drawSphere(0.4);
			}
			glPopMatrix();

			//Left side Hand 
			if (VAL(LEVELS) >= 2){
				glPushMatrix();
				glRotated(0, 1.0, 0.0, 0.0);
				glTranslated(-1.2, 0.0, 0.2);
				glScaled(1.0, 1.0, 1.0);
				glRotated(0 - VAL(HJOINTS), 1.0, 0.0, 0.0);
				if (VAL(ANGRYMOOD) == 1){
					glRotated(-65,0.0,1.0,0.0);
				}
				else{
				}
				drawCylinder(1.2, 0.25, 0.2);

				if (VAL(LEVELS) >= 3){
					//left hand joint
					glPushMatrix();
					glRotated(-270, 0.0, 1.0, 0.0);
					
					if (VAL(BOX) == 1){
						glTranslated(-1.4, -0.25, -0.25);
						glScaled(1.0, 1.0, 1.0);
						drawBox(0.5, 0.5, 0.5);
					}
					else{
						glTranslated(-1.0, 0.0, 0.0);
						glScaled(1.0, 1.0, 1.0);
						drawSphere(0.3);
					}

					glPopMatrix();

					if (VAL(LEVELS) >= 4){
						glPushMatrix();
						glRotated(-270, 0.0, 1.0, 0.0);
						glTranslated(-1.0, 0.0, 0.0);
						glScaled(1.0, 1.0, 1.0);
						glRotated(270, 0.0, 1.0, 0.0);
						if (VAL(ANGRYMOOD) == 1){
							glRotated(115, 0.0, 1.0, 0.0);
						}
						else{
						}
						drawCylinder(1.2, 0.2, 0.15);

						if (VAL(LEVELS) >= 5){
							//Fingers and palm
							glPushMatrix();
							glRotated(270, 0.0, 1.0, 0.0);
							glTranslated(1.2, 0.0, 0.0);
							glScaled(1.2, 0.8, 0.8);
							drawSphere(0.3);
							glPopMatrix();
						}
						glPopMatrix();
					}
				}
				glPopMatrix();
				// End of left side Hand 
			}
		}

		if (VAL(LEVELS) >= 1){
			//Right side Shoulder joint
			glPushMatrix();		
			glRotated(-90, 1.0, 0.0, 0.0);
			if (VAL(BOX) == 1){
				glTranslated(0.9, -0.5, -0.3);
				glScaled(1.0, 1.0, 1.0);
				drawBox(0.6, 0.6, 0.6);
			}
			else{
				glTranslated(1.1, -0.2, 0.0);
				glScaled(1.0, 1.0, 1.0);
				drawSphere(0.4);
			}

			glPopMatrix();

			if (VAL(LEVELS) >= 2){
				//Right side Hand 
				glPushMatrix();
				glRotated(0, 1.0, 0.0, 0.0);
				glTranslated(1.2, 0.0, 0.2);
				glScaled(1.0, 1.0, 1.0);
				glRotated(0 - VAL(HJOINTS), 1.0, 0.0, 0.0);
				if (VAL(ANGRYMOOD) == 1){
					glRotated(65, 0.0, 1.0, 0.0);
				}
				else{
				}
				drawCylinder(1.2, 0.25, 0.2);

				if (VAL(LEVELS) >= 3){
					//Right hand joint
					glPushMatrix();
					glRotated(270, 0.0, 1.0, 0.0);
					
					if (VAL(BOX) == 1){
						glTranslated(0.9, -0.25, -0.25);
						glScaled(1.0, 1.0, 1.0);
						drawBox(0.5, 0.5, 0.5);
					}
					else{
						glTranslated(1.0, 0.0, 0.0);
						glScaled(1.0, 1.0, 1.0);
						drawSphere(0.3);
					}

					glPopMatrix();

					if (VAL(LEVELS) >= 4){
						glPushMatrix();
						glRotated(270, 0.0, 1.0, 0.0);
						glTranslated(1.0, 0.0, 0.0);
						glScaled(1.0, 1.0, 1.0);
						glRotated(-270, 0.0, 1.0, 0.0);
						if (VAL(ANGRYMOOD) == 1){
							glRotated(-115, 0.0, 1.0, 0.0);
						}
						else{
						}
						drawCylinder(1.2, 0.2, 0.15);

						if (VAL(LEVELS) >= 5){
							//Fingers and palm
							glPushMatrix();
							glRotated(270, 0.0, 1.0, 0.0);
							glTranslated(1.2, 0.0, 0.0);
							glScaled(1.2, 0.8, 0.8);
							drawSphere(0.3);
							glPopMatrix();
						}
						glPopMatrix();
					}
				}
				glPopMatrix();
				//End of right side hand 
			}
		}
		glPopMatrix();
		//End of body

		//Body lower
		glPushMatrix();
		glTranslated(0.0, 0.2, 0.0);
		glScaled(1.0, 1.0, 1.0);
		glRotated(90, 1.0, 0.0, 0.0);
		drawCylinder(1.0, 1.0, 0.8);
		glPopMatrix();

		//legs
		//Left side upper Leg
		
		glPushMatrix();
		glTranslated(-0.4, -0.8, 0.0);
		glScaled(0.7, 0.7, 0.7);
		glRotated(90+kick, 1.0, 0.0, 0.0);
		drawCylinder(1.5, 0.5, 0.3);

			//Left Knee
			glPushMatrix();		
			glRotated(-90, 1.0, 0.0, 0.0);
			
			if (VAL(BOX) == 1){
				glTranslated(-0.4, -2.0, -0.35);
				glScaled(1.0, 1.0, 1.0);
				drawBox(0.8, 0.8, 0.8);
				glTranslated(0.4, 0.5, 0.35);
			}
			else{
				glTranslated(0.0, -1.5, 0.0);
				glScaled(1.0, 1.0, 1.0);
				drawSphere(0.5);
			}
			

				//left lower leg
				glPushMatrix();			
				glTranslated(0.0, 0.0, 0.0);
				glRotated(90, 1.0, 0.0, 0.0);
				glScaled(1.0, 1.0, 1.0);
				drawCylinder(1.5, 0.3, 0.25);

					//Feet			
					glPushMatrix();
					glRotated(-90, 1.0, 0.0, 0.0);
					glTranslated(0.0, -1.5, 0.2);
					glScaled(0.6, 0.5, 1.29);
					drawSphere( 0.5 );
					glPopMatrix();

				glPopMatrix();	
				//End of right lower leg
			glPopMatrix();
			// End of left Knee

		glPopMatrix();
		//End of Left upper leg

		// right side upper leg
		glPushMatrix();
		glTranslated(0.4, -0.8, 0.0);
		glScaled(0.7, 0.7, 0.7);
		glRotated(90, 1.0, 0.0, 0.0);
		drawCylinder(1.5, 0.5, 0.3);

			//Right Knee
			glPushMatrix();		
			glRotated(-90, 1.0, 0.0, 0.0);
			
			if (VAL(BOX) == 1){
				glTranslated(-0.4, -2.0, -0.35);
				glScaled(1.0, 1.0, 1.0);
				drawBox(0.8, 0.8, 0.8);
				glTranslated(0.4, 0.5, 0.35);
			}
			else{
				glTranslated(0.0, -1.5, 0.0);
				glScaled(1.0, 1.0, 1.0);
				drawSphere(0.5);
			}

				//Right side lower leg
				glPushMatrix();		
				glTranslated(0.0, 0.0, 0.0);
				glRotated(90, 1.0, 0.0, 0.0);
				glScaled(1.0, 1.0, 1.0);
				drawCylinder(1.5, 0.3, 0.25);
				
					//Feet			
					glPushMatrix();	
					glRotated(-90, 1.0, 0.0, 0.0);
					glTranslated(0.0, -1.5, 0.2);				
					glScaled(0.6, 0.5, 1.2);
					drawSphere( 0.5 );
					glPopMatrix();

				glPopMatrix();
			glPopMatrix();
			//End of right knee		

		glPopMatrix();
		//End of right side upper leg


		//Draw eggs
		setDiffuseColor(COLOR_WHITE);
		glPushMatrix();
		glRotated(0, 1.0, 0.0, 0.0);
		
		glRotated(1, 1.0, 0.0, 0.0);
		glTranslated(-0.4, -2.8, 1.5 + sendoff);
		glScaled(1.0, 0.6, 0.7);
		drawSphere(0.5);
		glPopMatrix();

	glPopMatrix();
	//End of whole model
	
	if (ModelerApplication::Instance()->m_animating == true){
		act = -30;
		if (kick >= 40 && back == true){
			back = false;
			front = true;
		}
		else if (kick < -20 && front == true){
			back = true;
			front = false;
			eggRotate = true;
		}
		if (back == false && front == true){
			kick = kick - 2;
			if (eggRotate == true){
				sendoff = sendoff - 0.2;
			}

		}
		else if (front == false && back == true){
			kick = kick + 1;
			if (eggRotate == true){
				sendoff = sendoff + 0.1;
			}
		}
	}
	else{
		kick = 0;
	}
	


	//model 2
	if (VAL(PIGY2) == 1){
		glPushMatrix();
		glTranslated(VAL(XPOS), VAL(YPOS), 6.5);
		glRotated(180, 0.0, 1.0, 0.0);
		//glRotated(VAL(ROTATEY), 0.0, 1.0, 0.0);

		//draw head  
		setAmbientColor(.1f, .1f, .1f);
		setDiffuseColor(COLOR_PIG2);
		glPushMatrix();
		glTranslated(0.0, 3.0, 0.0);
		glScaled(1.0, 1.0, 0.6);
		drawSphere(1.5);


		//draw Eyes
		//Left eye
		setDiffuseColor(COLOR_WHITE);
		glPushMatrix();
		if (VAL(ANGRYMOOD) == 0){
			glTranslated(-0.9, 0.25, 1.3);
		}
		else{
			glTranslated(-0.7, 0.35, 1.3);
		}
		glScaled(1.0, 1.0, 1.0);
		drawSphere(0.3);
		// Black irish
		glPushMatrix();
		setDiffuseColor(COLOR_BLACK);
		glTranslated(VAL(EYES), 0.0, 0.30);
		glScaled(0.5, 1.0, 0.1);
		drawSphere(0.15);
		glPopMatrix();
		glPopMatrix();

		//right eye
		setDiffuseColor(COLOR_WHITE);
		glPushMatrix();		
		if (VAL(ANGRYMOOD) == 0){
			glTranslated(0.9, 0.25, 1.3);
		}
		else{
			glTranslated(0.7, 0.35, 1.3);
		}
		glScaled(1.0, 1.0, 1.0);
		drawSphere(0.3);
		// Black irish
		glPushMatrix();
		setDiffuseColor(COLOR_BLACK);
		glTranslated(VAL(EYES), 0.0, 0.30);
		glScaled(0.5, 1.0, 0.1);
		drawSphere(0.15);
		glPopMatrix();
		glPopMatrix();

		//Draw Nose
		glPushMatrix();
		setDiffuseColor(COLOR_NOSEYELL);
		glTranslated(0.0, 0.0, 1.0);
		drawCylinder(0.8, 0.4, 0.6);

		setDiffuseColor(COLOR_NOSTRIL);
		glPushMatrix();
		glTranslated(-0.3, 0.0, 0.8);
		glScaled(1.0, 1.2, 0.9);
		drawSphere(0.20);
		glPopMatrix();

		glPushMatrix();
		glTranslated(0.3, 0.0, 0.8);
		glScaled(1.0, 1.2, 0.9);
		drawSphere(0.20);
		glPopMatrix();

		glPopMatrix();

		//tounge
		if (VAL(ANGRYMOOD) == 0){
			setDiffuseColor(COLOR_TONGUE);
			glPushMatrix();
			glTranslated(-0.1, -0.6, 1.4);
			glScaled(1.0, 1.8, -0.9);
			drawSphere(0.20);
			glPopMatrix();
		}
		else{
		}
		// draw left ears
		setDiffuseColor(COLOR_PIG2);
		glPushMatrix();
		glTranslated(-0.8, 1.4, 0.0);
		glScaled(1.0, 1.8, -1.0);
		drawSphere(0.20);
		glPopMatrix();

		// draw right ears
		glPushMatrix();
		glTranslated(0.8, 1.4, 0.0);
		glScaled(1.0, 1.8, -1.0);
		drawSphere(0.20);
		glPopMatrix();

		glPopMatrix();
		//end of head

		//Body neck
		setDiffuseColor(COLOR_PIG2);
		glPushMatrix();
		glTranslated(0.0, 2.5, 0.0);
		glScaled(1.0, 1.0, 1.0);
		glRotated(90, 1.0, 0.0, 0.0);
		drawCylinder(1.1, 0.5, 1.0);
		glPopMatrix();

		//Body
		glPushMatrix();
		glTranslated(0.0, 1.4, 0.0);
		glScaled(1.0, 1.0, 1.0);
		glRotated(90, 1.0, 0.0, 0.0);
		drawCylinder(1.2, 1.0, 1.0);

		//Left side Shoulder joint
		if (VAL(LEVELS) >= 1){
			glPushMatrix();
			glRotated(-90, 1.0, 0.0, 0.0);
			
			if (VAL(BOX) == 1){
				glTranslated(-1.5, -0.5, -0.3);
				glScaled(1.0, 1.0, 1.0);
				drawBox(0.6, 0.6, 0.6);
			}
			else{
				glTranslated(-1.1, -0.2, 0.0);
				glScaled(1.0, 1.0, 1.0);
				drawSphere(0.4);
			}

			glPopMatrix();

			//Left side Hand 
			if (VAL(LEVELS) >= 2){
				glPushMatrix();
				glRotated(0, 1.0, 0.0, 0.0);
				glTranslated(-1.2, 0.0, 0.2);
				glScaled(1.0, 1.0, 1.0);
				glRotated(0 - VAL(HJOINTS), 1.0, 0.0, 0.0);
				if (VAL(ANGRYMOOD) == 1){
					glRotated(-65, 0.0, 1.0, 0.0);
				}
				else{
				}
				drawCylinder(1.2, 0.25, 0.2);

				if (VAL(LEVELS) >= 3){
					//left hand joint
					glPushMatrix();
					glRotated(-270, 0.0, 1.0, 0.0);
					
					if (VAL(BOX) == 1){
						glTranslated(-1.4, -0.25, -0.25);
						glScaled(1.0, 1.0, 1.0);
						drawBox(0.5, 0.5, 0.5);
					}
					else{
						glTranslated(-1.0, 0.0, 0.0);
						glScaled(1.0, 1.0, 1.0);
						drawSphere(0.3);
					}

					glPopMatrix();

					if (VAL(LEVELS) >= 4){
						glPushMatrix();
						glRotated(-270, 0.0, 1.0, 0.0);
						glTranslated(-1.0, 0.0, 0.0);
						glScaled(1.0, 1.0, 1.0);
						glRotated(270, 0.0, 1.0, 0.0);
						if (VAL(ANGRYMOOD) == 1){
							glRotated(115, 0.0, 1.0, 0.0);
						}
						else{
						}
						drawCylinder(1.2, 0.2, 0.15);

						if (VAL(LEVELS) >= 5){
							//Fingers and palm
							glPushMatrix();
							glRotated(270, 0.0, 1.0, 0.0);
							glTranslated(1.2, 0.0, 0.0);
							glScaled(1.2, 0.8, 0.8);
							drawSphere(0.3);
							glPopMatrix();
						}
						glPopMatrix();
					}
				}
				glPopMatrix();
				// End of left side Hand 
			}
		}

		if (VAL(LEVELS) >= 1){
			//Right side Shoulder joint
			glPushMatrix();
			glRotated(-90, 1.0, 0.0, 0.0);
			
			if (VAL(BOX) == 1){
				glTranslated(0.9, -0.5, -0.3);
				glScaled(1.0, 1.0, 1.0);
				drawBox(0.6, 0.6, 0.6);
			}
			else{
				glTranslated(1.1, -0.2, 0.0);
				glScaled(1.0, 1.0, 1.0);
				drawSphere(0.4);
			}

			glPopMatrix();

			if (VAL(LEVELS) >= 2){
				//Right side Hand 
				glPushMatrix();
				glRotated(0, 1.0, 0.0, 0.0);
				glTranslated(1.2, 0.0, 0.2);
				glScaled(1.0, 1.0, 1.0);
				glRotated(0 - VAL(HJOINTS), 1.0, 0.0, 0.0);
				if (VAL(ANGRYMOOD) == 1){
					glRotated(65, 0.0, 1.0, 0.0);
				}
				else{
				}
				drawCylinder(1.2, 0.25, 0.2);

				if (VAL(LEVELS) >= 3){
					//Right hand joint
					glPushMatrix();
					glRotated(270, 0.0, 1.0, 0.0);
					
					if (VAL(BOX) == 1){
						glTranslated(0.9, -0.25, -0.25);
						glScaled(1.0, 1.0, 1.0);
						drawBox(0.5, 0.5, 0.5);
					}
					else{
						glTranslated(1.0, 0.0, 0.0);
						glScaled(1.0, 1.0, 1.0);
						drawSphere(0.3);
					}

					glPopMatrix();

					if (VAL(LEVELS) >= 4){
						glPushMatrix();
						glRotated(270, 0.0, 1.0, 0.0);
						glTranslated(1.0, 0.0, 0.0);
						glScaled(1.0, 1.0, 1.0);
						glRotated(-270, 0.0, 1.0, 0.0);
						if (VAL(ANGRYMOOD) == 1){
							glRotated(-115, 0.0, 1.0, 0.0);
						}
						else{
						}
						drawCylinder(1.2, 0.2, 0.15);

						if (VAL(LEVELS) >= 5){
							//Fingers and palm
							glPushMatrix();
							glRotated(270, 0.0, 1.0, 0.0);
							glTranslated(1.2, 0.0, 0.0);
							glScaled(1.2, 0.8, 0.8);
							drawSphere(0.3);
							glPopMatrix();
						}
						glPopMatrix();
					}
				}
				glPopMatrix();
				//End of right side hand 
			}
		}
		glPopMatrix();
		//End of body

		//Body lower
		glPushMatrix();
		glTranslated(0.0, 0.2, 0.0);
		glScaled(1.0, 1.0, 1.0);
		glRotated(90, 1.0, 0.0, 0.0);
		drawCylinder(1.0, 1.0, 0.8);
		glPopMatrix();

		//legs
		//Left side upper Leg
		glPushMatrix();
		glTranslated(-0.4, -0.8, 0.0);
		glScaled(0.7, 0.7, 0.7);
		glRotated(90, 1.0, 0.0, 0.0);
		drawCylinder(1.5, 0.5, 0.3);

		//Left Knee
		glPushMatrix();
		glRotated(-90, 1.0, 0.0, 0.0);

		if (VAL(BOX) == 1){
			glTranslated(-0.4, -2.0, -0.35);
			glScaled(1.0, 1.0, 1.0);
			drawBox(0.8, 0.8, 0.8);
			glTranslated(0.4, 0.5, 0.35);
		}
		else{
			glTranslated(0.0, -1.5, 0.0);
			glScaled(1.0, 1.0, 1.0);
			drawSphere(0.5);
		}

		//left lower leg
		glPushMatrix();
		glTranslated(0.0, 0.0, 0.0);
		glRotated(90, 1.0, 0.0, 0.0);
		glScaled(1.0, 1.0, 1.0);
		drawCylinder(1.5, 0.3, 0.25);

		//Feet			
		glPushMatrix();
		glRotated(-90, 1.0, 0.0, 0.0);
		glTranslated(0.0, -1.5, 0.2);
		glScaled(0.6, 0.5, 1.29);
		drawSphere(0.5);
		glPopMatrix();

		glPopMatrix();
		//End of right lower leg
		glPopMatrix();
		// End of left Knee

		glPopMatrix();
		//End of Left upper leg

		// right side upper leg
		glPushMatrix();
		glTranslated(0.4, -0.8, 0.0);
		glScaled(0.7, 0.7, 0.7);
		glRotated(90 - kick - act, 1.0, 0.0, 0.0);
		drawCylinder(1.5, 0.5, 0.3);

		//Right Knee
		glPushMatrix();
		glRotated(-90, 1.0, 0.0, 0.0);

		if (VAL(BOX) == 1){
			glTranslated(-0.4, -2.0, -0.35);
			glScaled(1.0, 1.0, 1.0);
			drawBox(0.8, 0.8, 0.8);
			glTranslated(0.4, 0.5, 0.35);
		}
		else{
			glTranslated(0.0, -1.5, 0.0);
			glScaled(1.0, 1.0, 1.0);
			drawSphere(0.5);
		}


		//Right side lower leg
		glPushMatrix();
		glTranslated(0.0, 0.0, 0.0);
		glRotated(90, 1.0, 0.0, 0.0);
		glScaled(1.0, 1.0, 1.0);
		drawCylinder(1.5, 0.3, 0.25);

		//Feet			
		glPushMatrix();
		glRotated(-90, 1.0, 0.0, 0.0);
		glTranslated(0.0, -1.5, 0.2);
		glScaled(0.6, 0.5, 1.2);
		drawSphere(0.5);
		glPopMatrix();

		glPopMatrix();
		glPopMatrix();
		//End of right knee		

		glPopMatrix();
		//End of right side upper leg


		glPopMatrix();
		//End of whole model

	}
	else{
		//do nothing
	}
	
	


}

int main()
{
	// Initialize the controls
	// Constructor is ModelerControl(name, minimumvalue, maximumvalue, 
	// stepsize, defaultvalue)
    ModelerControl controls[NUMCONTROLS];
    controls[XPOS] = ModelerControl("X Position", -2.3, 2.3, 0.1f, 0);
    controls[YPOS] = ModelerControl("Y Position", 0, 5, 0.1f, 0);
	controls[ROTATEX] = ModelerControl("Model Rotate X", -180, 180, 1, 0); 
	controls[ROTATEY] = ModelerControl("Model Rotate Y", -180, 180, 1, 0);
	controls[HJOINTS] = ModelerControl("Hands Forward", 0, 100, 1, 0);
	controls[EYES] = ModelerControl("Eyes Irish", -0.2, 0.2, .01, 0);
	controls[LEVELS] = ModelerControl("Levels ", 0, 5, 1, 5);
	controls[PIGY2] = ModelerControl("Add Pig2 ", 0, 1, 1, 0);
	controls[BOX] = ModelerControl("BOX Joints",0,1,1,0);
	controls[ANGRYMOOD] = ModelerControl("Angry Mood", 0, 1, 1, 0);

    ModelerApplication::Instance()->Init(&createSampleModel, controls, NUMCONTROLS);
	
	
    return ModelerApplication::Instance()->Run();
}
