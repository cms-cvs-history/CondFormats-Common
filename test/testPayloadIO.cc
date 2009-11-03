//
// test Payload I/O
//
// requires a few sed....

#include "CondCore/DBCommon/interface/DbScopedTransaction.h"
#include "CondCore/DBCommon/interface/DbConnection.h"
#include "CondCore/DBCommon/interface/DbTransaction.h"
#include "CondCore/DBCommon/interface/Exception.h"
#include "FWCore/PluginManager/interface/PluginManager.h"
#include "FWCore/PluginManager/interface/standard.h"
#include "RelationalAccess/ISchema.h"
#include "RelationalAccess/TableDescription.h"
#include "CoralBase/AttributeSpecification.h"
#include "DataSvc/Ref.h"
#include <iostream>

#include "CondFormats/THEPACKAGE/interface/THEHEADER.h"
typedef THECLASS Payload;

typedef cond::DataWrapper<Payload> SimplePtr;

namespace{
  std::string className("THECLASS");
  std::string DSW_Name("DSW_THECLASS");

  bool withWrapper=false;
}

int main(int argc, char** ) {
try{

  withWrapper = argc>1;
  
  edmplugin::PluginManager::Config config;
  edmplugin::PluginManager::configure(edmplugin::standard::config());

  unsigned int nobjects=10;
  std::vector<std::string> payTok;
  std::vector<std::string> wrapTok;


  //write....
  {
    cond::DbConnection conn;
    conn.configure( cond::CmsDefaults );
    cond::DbSession session = conn.createSession();
    session.open("sqlite_file:test.db");
    
    cond::DbScopedTransaction tr(session);
    tr.start(true);
    
    unsigned int iw;
    for (iw = 0; iw < nobjects; ++iw )   {
      pool::Ref<Payload> ref = session.storeObject(new Payload,className);
      payTok.push_back(ref.toString());
      if (withWrapper) {
	pool::Ref<PayloadWrapper> refW = 
	  session.storeObject(new SimplePtr(new Payload, new cond::GenericSummary(className)));
	wrapTok.push_back(refW.toString());
     }
    }
    
    tr.commit();
    
  }

  //read....
  {
    cond::DbConnection conn;
    conn.configure( cond::CmsDefaults );
    cond::DbSession session = conn.createSession();
    session.open("sqlite_file:test.db");
    
    cond::DbScopedTransaction tr(session);
    tr.start();
    
    unsigned int ir;
    for (ir = 0; ir < payTok.size(); ++ir )   {
      pool::Ref<Payload> ref = session.getTypedObject<Payload>(payTok[ir]);
      Payload & p = *ref;
    }

    for (ir = 0; ir < wrapTok.size(); ++ir )   {
      pool::Ref<SimplePtr> ref = session.getTypedObject<SimplePtr>(wrapTok[ir]);
      Payload & p = ref->data();
    }
    
    
    tr.commit();
    
  }
 


  //read 



 } catch (const std::exception& e){
  std::cout << "ERROR:" << e.what() << std::endl;
    throw;
 }

  return 0;
}
