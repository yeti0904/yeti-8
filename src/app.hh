#ifndef YETI8_APP_HH
#define YETI8_APP_HH

#include "_components.hh"
#include "vm.hh"

class App;

App& AppInstance();

class App {
	public:
		// variables
		bool run;
		VM&  vm;

		// functions
		App();
		~App();
		void HandleArguments(int argc, char** argv);
		void Update();
};

#endif