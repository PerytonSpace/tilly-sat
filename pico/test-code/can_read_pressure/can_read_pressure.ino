#include <SPI.h>
#include <mcp2515.h>

struct can_frame canMsg;
MCP2515 mcp2515(10);  // CS pin for MCP2515

void setup() {
    Serial.begin(115200);
    SPI.begin();
    
    mcp2515.reset();
    mcp2515.setBitrate(CAN_500KBPS, MCP_8MHZ);
    mcp2515.setNormalMode();

    Serial.println("CAN Receiver Ready!");
}

void loop() {
    if (mcp2515.readMessage(&canMsg) == MCP2515::ERROR_OK) {
        if (canMsg.can_id == 0x100) {  // Check if it's our pressure data
            float pressure = hexToFloat(canMsg.data);
            Serial.print("Received Pressure: ");
            Serial.println(pressure, 2);  // Print with 2 decimal places
        }
    }
}

// Function to convert 4-byte HEX to float
float hexToFloat(uint8_t *data) {
    uint32_t hexVal = (data[0] << 24) | (data[1] << 16) | (data[2] << 8) | data[3];
    return hexVal / 100.0;  // Convert back to float (since we multiplied by 100)
}
