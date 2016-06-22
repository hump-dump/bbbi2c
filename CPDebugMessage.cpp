#include "CPDebugMessage.hpp"
#include <iostream>

CPDebugMessage::CPDebugMessage( const string & prefix )
   : mPrefix( prefix )
{

}

void CPDebugMessage::setParent( CPDebugMessage * parent )
{
   mPrefix = parent->getPrefix() + "`" + mPrefix;
}

void CPDebugMessage::debug( const std::string & message )
{
   std::cout << mPrefix << ":" << message << std::endl;
}
