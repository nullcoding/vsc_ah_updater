Accurate as of 2 April 2013

**This only applies to Windows!!**

Building the cURL library should be easy enough. The version here is x64 /MT (multi-threaded static release) BUT we use instead the one found at depend/lib/curl64d for debug and at depend/lib/curl64 for release.

The JSON libraries are a royal pain. In order to build jsoncpp, you need to edit the file SConstruct, specifically the lines 108 and 136:

108: env['CXXFLAGS']='-GR -EHsc /nologo /MD'

136: env['LIB_CRUNTIME'] = 'MD'

Of course be sure it kicks out a .lib (it ought to unless you modify the env['LIB_LINK_TYPE'] for some reason).

If jsoncpp is built using libcmt/d it will probably NOT WORK. This is because a) curl is built statically using msvcrt/d and b) the project/solution itself uses msvcrt/d. 

This is only on Windows - it ought not be this complicated on UNIX...let's hope...

Don't play around with the libraries - these two in the folder CURRENTLY are the working ones!!

json_vc110_libMDd.lib (jsoncpp library, static, debug, Visual C++ 11,0 x64)
libcurl_a_debug.lib (cURL library, static, debug, Visual C++ 11,0 x64) N.B be sure to also #define CURL_STATICLIB or DCURL_STATICLIB

Be sure to ignore LIBCMTD.lib - /NODEFAULTLIB:LIBCMTD.lib

Yes it's only debug, sorry - the whole program is still in testing anyway!!