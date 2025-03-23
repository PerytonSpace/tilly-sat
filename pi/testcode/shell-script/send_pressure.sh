#!/bin/bash

CAN_INTERFACE="can0"
DELAY=1  # Time delay between messages

# Function to convert float to IEEE 754 HEX using Python
float_to_hex() {
    local float_value=$1
    python3 -c "import struct; print(struct.pack('>f', float($float_value)).hex().upper())"
}

# Ensure CAN interface is up
if ! ip link show "$CAN_INTERFACE" | grep -q "UP"; then
    echo "Error: CAN interface $CAN_INTERFACE is not up. Bringing it up..."
    sudo ip link set "$CAN_INTERFACE" up type can bitrate 250000
    sleep 2
fi

while true; do
    PRESSURE="1069.19"  # Example float value

    # Convert float to IEEE 754 HEX
    HEX_VALUE=$(float_to_hex "$PRESSURE")

    # Format as CAN frame (ID 0x100, 4-byte data)
    CAN_MSG="100#${HEX_VALUE:0:2}${HEX_VALUE:2:2}${HEX_VALUE:4:2}${HEX_VALUE:6:2}"

    echo "Sending: $CAN_MSG"
    cansend $CAN_INTERFACE $CAN_MSG

    sleep $DELAY
done
