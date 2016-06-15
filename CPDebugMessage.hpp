#ifndef CPDEBUGMESSAGE_HPP
#define CPDEBUGMESSAGE_HPP

#include <string>

using namespace std;

class CPDebugMessage
{
public:
   CPDebugMessage( const string & prefix );
   void debug( const string & message );
private:
   const string mPrefix;
};

#endif // CPDEBUGMESSAGE_HPP
