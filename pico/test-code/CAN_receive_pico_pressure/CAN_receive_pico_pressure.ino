// CAN Receive Example - Decoding Pressure Data
#include <mcp_can.h>
#include <SPI.h>

long unsigned int rxId;
unsigned char len = 0;
unsigned char rxBuf[8];
char msgString[128];  // Array to store serial output

#define CAN0_INT 22  // Set INT to pin 22
MCP_CAN CAN0(17);    // Set CS to pin 17

void setup() {
    Serial.begin(921600);
    delay(2000);
    Serial.println("CAN_receive_pico_pressure");
    delay(2000);

    SPI.begin();

    // Initialize MCP2515
    if (CAN0.begin(MCP_ANY, CAN_250KBPS, MCP_8MHZ) == CAN_OK)
        Serial.println("MCP2515 Initialized Successfully!");
    else
        Serial.println("Error Initializing MCP2515...");

    CAN0.setMode(MCP_NORMAL);  // Set to normal mode (ACK enabled)
    pinMode(CAN0_INT, INPUT);  // Set INT pin as input

    Serial.println("MCP2515 Library Receive Example...");
}

void loop() {
    if (!digitalRead(CAN0_INT)) {  // If interrupt pin is LOW, data is available
        CAN0.readMsgBuf(&rxId, &len, rxBuf);  // Read data

        Serial.print("Received CAN Frame - ID: ");
        Serial.print(rxId, HEX);
        Serial.print("  DLC: ");
        Serial.print(len);
        Serial.print("  Data:");

        for (byte i = 0; i < len; i++) {
            sprintf(msgString, " 0x%.2X", rxBuf[i]);
            Serial.print(msgString);
        }
        Serial.println();

        // Check if the received ID matches the pressure message ID (modify as needed)
        if (rxId == 0x100 && len >= 4) {  // Assuming ID 0x123 for pressure & at least 4 bytes of data
            float pressure;
            memcpy(&pressure, rxBuf, sizeof(float));  // Convert 4 bytes to float
            Serial.print("Decoded Pressure: ");
            Serial.print(pressure, 2);
            Serial.println(" hPa");
        }
    }
}
