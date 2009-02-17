#include "CondFormats/Common/interface/UpdateStamp.h"
#include "CondFormats/Common/interface/TimeConversions.h"

namespace {
  std::string sep(". ");
}

namespace cond {

  UpdateStamp::UpdateStamp() : 
    m_revision(-1), m_timestamp(0), m_comment("not stamped"){}
    
    
  UpdateStamp::~UpdateStamp(){}
    
    // stamp and return current revision number;
  int UpdateStamp::stamp(std::string const & icomment, bool append) {
    m_revision++;
    m_timestamp = cond::time::now();
    if (append) m_comment += sep + icomment;
    else m_comment = icomment;
    return m_revision;
  }
    
}
