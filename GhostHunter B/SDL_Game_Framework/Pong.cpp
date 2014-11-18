#include "Pong.h"


Pong::Pong(void){
	rallyLength = 0;
	maxRallyLength = 0;
}


Pong::~Pong(void){
}

void Pong::resetBall(){
	state = 0;
	rallyLength = 0;
	ball.set_world_position(240, 150);
	ball.make_visible();
	ball.set_auto_move(0);
	float dir = -1;
	if(rnd.number() < 0.5f)
		dir = 1;
	ball.set_velocities(-rnd.number(1.6f, 4.0f), dir * rnd.number(1.0f, 3.0f));
}

void Pong::setup(){
	setBackground(0, 0, 0);
	enableKeyRepeat();
	topWall.setImage(300, 20, 255, 255, 255);
	topWall.set_world_position(40, 40);
	bottomWall.setImage(300, 20, 255, 255, 255);
	bottomWall.set_world_position(40, 240);
	leftWall.setImage(20, 220, 255, 255, 255);
	leftWall.set_world_position(40, 40);
	bat.setImage(8, 34, 200, 200, 0);
	bat.set_world_position(307, 150);
	ball.setImage(6, 6, 0, 160, 160);
	ball.set_world_position(240, 150);
	resetBall();

	addSound("sounds/ping1.wav", "PING");
}

void Pong::onKeyReleased(){
	if(state == 0 && keyUp == SDLK_SPACE){
		ball.set_auto_move(20);
		state = 1;
	}
	if(keyUp == SDLK_s){
		playSound("PING");
		cout << "Key released\n";
	}
}

void Pong::onKeyPressed(){
	if(keyDown == SDLK_UP && bat.get_y() - BAT_MOVE >= topWall.get_y() + topWall.get_height()){
		bat.set_world_position_y(bat.get_y() - BAT_MOVE);
	}
	if(keyDown == SDLK_DOWN && bat.get_y() + bat.get_height() + BAT_MOVE <= bottomWall.get_y()){
		bat.set_world_position_y(bat.get_y() + BAT_MOVE);
	}
}

void Pong::logic(){
	bool collision = false;
	if(ball.pp_collision(topWall)){
		ball.set_y_velocity(abs(ball.get_y_velocity()));
		collision = true;
	}
	else if(ball.pp_collision(bottomWall)){
		ball.set_y_velocity(-abs(ball.get_y_velocity()));
		collision = true;
	}
	if(ball.pp_collision(leftWall)){
		ball.set_x_velocity(abs(ball.get_x_velocity()));
		collision = true;
	}
	else if(ball.pp_collision(bat)){
		ball.set_x_velocity(-abs(ball.get_x_velocity()));
		rallyLength++;
		maxRallyLength = max(rallyLength, maxRallyLength);
		collision = true;
	}
	if(ball.is_on_screen() == false)
		resetBall();
	if(collision == true){
		playSound("PING");
		ball.move();
	}
}

void Pong::draw(){
	topWall.update_everything();
	bottomWall.update_everything();
	leftWall.update_everything();
	bat.update_everything();
	ball.update_everything();
	if(state == 0)
		print("Press SPACE to start game", 50, 16, RED);
	else {
		int x = print("Rally length ", 40, 16);
		x = print(rallyLength, x, 16, WHITE);
		x = print("Max rally length ", x + 30, 16, GREEN);
		print(maxRallyLength, x, 16, WHITE);
	}
	print("Press ESCAPE to exit program", 50, 280, RED);

}