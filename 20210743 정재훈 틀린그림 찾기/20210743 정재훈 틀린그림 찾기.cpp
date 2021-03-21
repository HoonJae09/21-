#include<bangtal.h>
SceneID scene1;

ObjectID pro;
ObjectID up[5];
ObjectID down[5];



int X[5] = { 180,262,250,413,162 };
int upY[5] = { 350,400,340,400,310 };
int downY[5] = { 50,90,30,104,8 };
int radius[7] = { 30,20,20,20,10 };





bool checked[5];


bool checkin(int x, int y, int cx, int cy, int r) {
	return(x > cx - r && x < cx + r && y > cy - r && y < cy + r);
}

void mouseCallback(ObjectID object, int x, int y, MouseAction action) {
	if (object == pro) {

		bool wrong = true;

		for (int i = 0;i < 5; i++) {
			if ((checked[i] == false) && (checkin(x, y, X[i], upY[i], radius[i]) || checkin(x, y, X[i], downY[i], radius[i]))) {
				showObject(up[i]);
				showObject(down[i]);


				checked[i] = true;
				wrong = false;
			}
		}
		if (wrong) {
			endGame();
		}
		else {
			bool completed = true;

			for (int i = 0; i < 5; i++) {
				if (checked[i] == false) {
					completed = false;
				}
			}

			if (completed) {
				endGame();
			}
		}
	}

}

int main() {
	setMouseCallback(mouseCallback);
	
	scene1 = createScene("틀린그림찾기", "pro.png");

	pro = createObject("pro.png");
	locateObject(pro, scene1, 0, 0);
	showObject(pro);

	for (int i = 0; i < 5; i++) {
		up[i] = createObject("check.png");
		locateObject(up[i], scene1, X[i], upY[i] - 10);

		down[i] = createObject("check.png");
		locateObject(down[i], scene1, X[i], downY[i] - 10);
	}
	showMessage("위아래에 틀린 곳을 찾으시오.");



	startGame(scene1);
}