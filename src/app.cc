#include "app.hh"

App& AppInstance() {
	static App app;

	return app;
}

App::App():
	run(true),
	vm(VMInstance())
{
	vm.LoadProgram({
		0x04, 0x04, 0x05, // mov r1, 0x05
		0x04, 0x05, 0x05, // mov r2, 0x05
		0x06, 0x04, 0x05, // cmp r1, r2
		0x0B, 0x00,       // not ac
		0xFF              // hlt
	});
}

App::~App() {
	vm.DumpRegisters();
}

void App::Update() {
	vm.RunInstruction(run);
}