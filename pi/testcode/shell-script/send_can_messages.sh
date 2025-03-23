#!/bin/bash

CAN_INTERFACE="can0"

Message1="123#DEADBEEF"
Message2="149#CAFEBABE"

DELAY=1

if ! ip link show "$CAN_INTERFACE" | grep -q "UP"; then
	echo "Error:CAN interface $CAN_INTERFACE is not up.Bringing it up..."
	sudo ip link set "$CAN_INTERFACE" up type can bitrate 250000
	sleep 2
fi

while true; do 
	echo "Sending: $Message1"
	cansend $CAN_INTERFACE $Message1
	sleep $DELAY

	echo "Sending: $Message2"
	cansend $CAN_INTERFACE $Message2
	sleep $DELAY
done
