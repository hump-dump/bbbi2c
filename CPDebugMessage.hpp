#ifndef CPDEBUGMESSAGE_HPP
#define CPDEBUGMESSAGE_HPP

#include <string>

using namespace std;

class CPDebugMessage
{
public:
   CPDebugMessage( const string & prefix );
   void debug( const string & message );
   void setParent( CPDebugMessage * parent );
   const std::string & getPrefix() {
      return mPrefix;
   }
private:
   CPDebugMessage();
   string mPrefix;
};

#endif // CPDEBUGMESSAGE_HPP
