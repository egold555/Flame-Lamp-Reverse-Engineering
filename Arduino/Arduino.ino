// NEED TO USE VERSION 2.8.0 of IRReciever. Higher versions don't work

#include "IRremote.h"
#include "EG_IR_FlameLantern.h"

const int receiver = 11;

IRrecv irrecv(receiver);
decode_results results;

void printHex(uint32_t number)
{
    Serial.print("0x");
    Serial.print(number < 16 ? "0" : "");
    Serial.print(number, HEX);
    Serial.print(" ");
}

void translateIR()
{

    // decode type = 9 (NEC I think)
    switch (results.value)
    {
    case FLAME_LANTERN_OFF:
        Serial.println("OFF");
        break;
    case FLAME_LANTERN_ON:
        Serial.println("ON");
        break;
    case FLAME_LANTERN_LAMP:
        Serial.println("LAMP");
        break;
    case FLAME_LANTERN_FLAME:
        Serial.println("FLAME");
        break;
    case FLAME_LANTERN_REPEAT:
        Serial.println("REPEAT");
        break;

    default:
        Serial.print("Other Button: ");
        printHex(results.value);
        Serial.println();
    }
}

void setup()
{
    Serial.begin(115200);
    Serial.println("IR Receiver Button Decode");
    irrecv.enableIRIn(); // Start the receiver
}

void loop()
{
    // have we received an IR signal?
    if (irrecv.decode(&results))
    {
        translateIR();
        irrecv.resume();
    }
}