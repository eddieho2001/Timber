#include "EntryPoint.h"
#include"framework/application.h"

int main() {
	timber::Application* objApp = GetApplication();
	objApp->run();

}