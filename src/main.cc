#include "app.hh"

int main(int argc, char** argv) {
	App& app = AppInstance();
	app.HandleArguments(argc, argv);

	while (app.run) {
		app.Update();
	}

	return 0;
}