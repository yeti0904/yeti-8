#include "app.hh"
#include "fs.hh"

App& AppInstance() {
	static App app;

	return app;
}

App::App():
	run(true),
	vm(VMInstance())
{
	/*
	vm.LoadProgram({
		0x04, 0x04, 0x05, // mov r1, 0x05
		0x04, 0x05, 0x05, // mov r2, 0x05
		0x06, 0x04, 0x05, // cmp r1, r2
		0x0B, 0x00,       // not ac
		0xFF              // hlt
	});*/
}

App::~App() {
	vm.DumpRegisters();
}

void App::HandleArguments(int argc, char** argv) {
	static bool alreadyLoaded = false;
	for (int i = 1; i < argc; ++i) {
		std::string arg = argv[i];
		if (arg[0] == '-') {
			fprintf(stderr, "Unknown option: %s\n", arg.c_str());
			exit(EXIT_FAILURE);
		}
		else {
			if (!FS::File::Exists(arg)) {
				fprintf(stderr, "No such file: %s\n", arg.c_str());
				exit(EXIT_FAILURE);
			}
			if (alreadyLoaded) {
				fputs("Can't load another program, one is already loaded\n", stderr);
				exit(EXIT_FAILURE);
			}
			vm.LoadProgram(FS::File::Binary::Read(arg));
			printf("Loaded %s\n", arg.c_str());
			alreadyLoaded = true;
		}
	}
	if (!alreadyLoaded) {
		run = false;
	}
}

void App::Update() {
	vm.RunInstruction(run);
}