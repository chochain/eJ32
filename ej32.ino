///
/// eJ32
///
#include "src/mmu.h"
#include "src/forth.h"
#include "src/java.h"
///
/// console interface
///
void send_to_console(int, const char* msg) { Serial.print(msg); }
///
/// Arduino core
///
void setup() {
    Serial.begin(115200);
    delay(100);

    forth_setup(send_to_console);
    int err = java_setup("/java/ESP32Test.class", send_to_console);
    if (err) { LOG("java_setup failed: "); LOX(err); }
}

void loop() {
    java_run();
}
