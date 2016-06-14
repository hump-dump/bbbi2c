#include "cpdebugmessage.hpp"
#include <iostream>

CPDebugMessage::CPDebugMessage()
{

}

void CPDebugMessage::debug( const std::string & message )
{
   std::cout << message << std::endl;
}
