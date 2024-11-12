add_definitions(-DAtmospheric_ENABLED)

set(Atmospheric_Impl_Files
  Atmospheric_CCMu_Ar_XSec_1DEnu_nu.cxx
  SignalDef.cxx
)

set(Atmospheric_Header_Files
  Atmospheric_CCMu_Ar_XSec_1DEnu_nu.h
  SignalDef.h
)

add_library(Atmospheric SHARED ${Atmospheric_Impl_Files})
target_link_libraries(Atmospheric FrameworkLibraries CoreIncludes)

install(TARGETS Atmospheric
    EXPORT nuisance-targets
    LIBRARY DESTINATION lib/
    PUBLIC_HEADER DESTINATION include)

add_library(NUIS::Atmospheric ALIAS Atmospheric)