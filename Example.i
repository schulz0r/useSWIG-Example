%module Example

%{
#include "example.h"
%}

%include "include/example.h"
%insert(cgo_comment_typedefs) %{
#cgo LDFLAGS: -L${SRCDIR} -l:Example.so
%}
