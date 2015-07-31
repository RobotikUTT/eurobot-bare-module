#include "CanBus.h"

CanBusLib::CanBusLib() {
}

byte CanBusLib::begin(byte speed, byte sspin, byte bufSize) {
	this->bufSize = bufSize;
	this->mcpCan = MCP_CAN(sspin);
	return this->mcpCan.begin(speed);
}

void CanBusLib::setDeviceID(byte ID) {
	if(ID < 32)
	{
		this->deviceID = ID;
	}
}

void CanBusLib::setCommandID(byte ID)
{
	if(ID < 64)
	{
		this->commandID = ID;
	}
}

void CanBusLib::sendMessage(byte* buffer, unsigned long length)
{
	unsigned long id;

	if(length <= 8) // Only one packet needed
	{
		id = (this->commandID << 5) | this->deviceID;
		this->mcpCan.sendMsgBuf(id, 0, 0, length, buffer);
	}
	else // Composed message and extended frame
	{
		id = ((unsigned long)this->commandID << 23) | ((unsigned long)this->deviceID << 18);
		unsigned long page;
		unsigned long pageCount = length/8;
		if((length & 0x7) != 0)
		{
			++pageCount;
		}
		if(pageCount > PAGE_MAX)
		{
			#if DEBUG_MODE
				Serial.print("Message too long on bus can : 2^17*8 bytes maximum\n");
			#endif

			return;
		}

		// Send all packets
		for (page = 0; page < pageCount; ++page)
		{
			if(page + 1 != pageCount)
			{
				this->mcpCan.sendMsgBuf(id | page, 1, 0, 8, buffer);
			}
			else
			{
				this->mcpCan.sendMsgBuf(id | this->LAST_PACKET_BIT | page, 1, 0, length, buffer);

			}
		}
	}
}

// Preinstantiate Objects
CanBusLib CanBus = CanBusLib();