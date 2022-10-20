#include "app.hh"

int main(void) {
	App& app = AppInstance();

	while (app.run) {
		app.Update();
	}

	return 0;
}