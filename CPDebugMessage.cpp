#include "CPDebugMessage.hpp"
#include <iostream>

CPDebugMessage::CPDebugMessage( const string & prefix )
   : mPrefix( prefix )
{

}

void CPDebugMessage::debug( const std::string & message )
{
   std::cout << mPrefix << ":" << message << std::endl;
}
