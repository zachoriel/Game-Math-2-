#include "sfwdraw.h"
#include "transform.h"
#include "Player.h"
#include "MyGuy.h"
#include "mat3.h"
#include "Rigidbody.h"
#include "shapes.h"
#include "DrawShape.h"

#include <cmath>
#include <string>
#include <cstring>
#include <cassert>


int main()
{
	sfw::initContext();

	Transform transform;
	Rigidbody rigidbody;

	circle circ = { { 0,0 }, 1 };

	transform.position = vec2{ 400, 300 };
	transform.dimension = vec2{ 100,150 };

	bool jumped = false;
	while (sfw::stepContext())
	{
		drawCircle(transform.getGlobalTransform() * circ);
		DrawMatrix(transform.getGlobalTransform(), 1);

		float dt = sfw::getDeltaTime();

		//rigidbody.force += { 0, -25 }; // gravity

		// moving jets
		if (sfw::getKey('W'))rigidbody.force +=
			transform.getGlobalTransform()[1].xy * 1;
		if (sfw::getKey('A'))rigidbody.torque += 360;
		if (sfw::getKey('D'))rigidbody.torque += -360;

		if (sfw::getKey('Q')) rigidbody.impulse +=
			-transform.getGlobalTransform()[1].xy * 10;

		if (sfw::getKey(' ')) //breaking force
		{
			rigidbody.force += -rigidbody.velocity * 20;
			rigidbody.torque += -rigidbody.angularVelocity * 20;
		}

		rigidbody.integrate(transform, dt);

	}
	sfw::termContext();
}









/* Transform myTransform;
myTransform.position = vec2{ 300,400 };
myTransform.dimension = vec2{ 1,1 };
myTransform.angle = 0;

Transform myBaby;
myBaby.position = vec2{ 10,10 };
myBaby.dimension = vec2{ 1,1 };
myBaby.angle = 0;
myBaby.e_parent = &myTransform; */       // old stuff

/* Player me;
me.pos = { 400,300 };  // old old stuff
me.speed = 10; */

/* while (sfw::stepContext())
{
float t = sfw::getTime();

myTransform.angle += sfw::getDeltaTime() * 180;
myTransform.dimension = vec2{ sinf(t) + 2, sinf(t) + 2 };

DrawMatrix(myTransform.getGlobalTransform(), 40);
DrawMatrix(myBaby.getGlobalTransform(), 30); */  // old stuff

/* me.update();
me.draw(); */   // part of the old old stuff