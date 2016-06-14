#ifndef CPDEBUGMESSAGE_HPP
#define CPDEBUGMESSAGE_HPP

#include <string>

class CPDebugMessage
{
public:
   CPDebugMessage();
   static void debug( const std::string & message );
};

#endif // CPDEBUGMESSAGE_HPP
