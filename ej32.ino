///
/// eJ32
///
#include "src/mmu.h"
#include "src/jvm.h"

void setup() {
    Serial.begin(115200);
    delay(100);
    
    int err = jvm_setup("/java/ESP32Test.class");
    if (err) { LOG("jvm_setup failed: "); LOX(err); }
}

void loop() {
    jvm_run();
}
