#ifndef LIB_CAN_BUS_H
#define LIB_CAN_BUS_H

#include <Arduino.h>
#include <SPI.h>
#include "mcp_can.h"

/**
 *
 * maximal data length in bytes : 1048576
 */
class CanBusLib {

	public:
		CanBusLib();

		/**
		 * Init the can controller
		 * @param  speed -	Transmission speed. Values available in `lib/mcp_can/mcp_can_dfs.h`. Default is 1000kb/s
		 * @param  sspin -	Slave selection pin used by spi to select the can controller. Default is pin 10.
		 * @param  bufSize -	Number of message that can be saved in the receive buffer. If you dont filter composed message, this number has to higher than one. 
		 * @return       Return CAN_OK (0) if everything is OK. Else return CAN_FAILINIT (1)
		 */
		byte begin(byte speed = CAN_1000KBPS, byte sspin = 10, byte bufSize = 3);

		/**
		 * Set the device ID.
		 *
		 * Generally this ID doesn't change for every packet send, but sometimes a device can
		 * imitate another. Or change it to require a packet to another device. Remember that an
		 * inferior number has priority over higher. Debug devices should use 0b11111 and the core
		 * module use 0b00000.
		 *
		 * @param ID - The device ID of 5 bit (0 -> 31).
		 */
		void setDeviceID(byte ID);

		/**
		 * Set the command identifier of the packet that you will send.
		 *
		 * This data is contained inside protocol buffer file, so you don't have to use this function
		 * except if you want to create a packet by hand. Remember that an inferior number has priority
		 * over higher.
		 *
		 * @param ID - The command ID of the packet of 6 bit (0 -> 63).
		 */
		void setCommandID(byte ID);

		/**
		 *
		 * Send a message with the given buffer.
		 *
		 * You should use protocol buffer version of send message. You will use this function only if
		 * you want to create a packet by hand. If this buffer is greather than 8 bytes, it will be
		 * splitted and we will send extended frames that contain pagination.
		 *
		 * @param buffer - The buffer to send
		 * @param length - The length of data contained inside the buffer.
		 */
		void sendMessage(byte* buffer, unsigned long length);

	private:
		MCP_CAN mcpCan = 0;

		// Receive vars
		byte available = 0;
		byte missed = 0;
		byte bufSize = 0;

		// Send vars
		byte deviceID = 0;
		byte commandID = 0;

		// Consts
		static const unsigned long PAGE_MAX = 0x20000; // 2^17
		static const unsigned long LAST_PACKET_BIT = 0x20000;
};


extern CanBusLib CanBus;

#endif
