#!/bin/bash

CAN_INTERFACE="can0"
DELAY=1  # Time delay between messages

# Function to convert float to 32-bit HEX (IEEE 754)
float_to_hex() {
    local float_value=$1
    local hex_value=$(printf "%08X" $(echo "obase=16; ibase=10; $(printf '%d' $(echo "$float_value * 100" | bc)))" | bc))
    echo "$hex_value"
}

# Ensure CAN interface is up
if ! ip link show "$CAN_INTERFACE" | grep -q "UP"; then
    echo "Error: CAN interface $CAN_INTERFACE is not up. Bringing it up..."
    sudo ip link set "$CAN_INTERFACE" up type can bitrate 500000
    sleep 2
fi

while true; do
    PRESSURE="1069.19"  # Example float value

    # Convert float to HEX
    HEX_VALUE=$(float_to_hex "$PRESSURE")
    
    # Format as CAN frame (ID 0x100, 4-byte data)
    CAN_MSG="100#${HEX_VALUE:0:2}${HEX_VALUE:2:2}${HEX_VALUE:4:2}${HEX_VALUE:6:2}"

    echo "Sending: $CAN_MSG"
    cansend $CAN_INTERFACE $CAN_MSG

    sleep $DELAY
done
