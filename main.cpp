#include "./ExampleApplication.h"

int main(int argc, char* argv[]) {
    auto app = ExampleApplication::create();
    return app->run(argc, argv);
}
