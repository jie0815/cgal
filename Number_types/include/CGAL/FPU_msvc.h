// Copyright (c) 2010-2011  GeometryFactory Sarl (France)
//
// This file is part of CGAL (www.cgal.org); you can redistribute it and/or
// modify it under the terms of the GNU Lesser General Public License as
// published by the Free Software Foundation; version 2.1 of the License.
// See the file LICENSE.LGPL distributed with CGAL.
//
// Licensees holding a valid commercial license may use this file in
// accordance with the commercial license agreement provided with the software.
//
// This file is provided AS IS with NO WARRANTY OF ANY KIND, INCLUDING THE
// WARRANTY OF DESIGN, MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
//
// $URL$
// $Id$
//
//
// Author(s)     : Laurent Rineau

#include <cfloat>

#ifndef FE_INVALID
#  define FE_INEXACT     _EM_INEXACT
#  define FE_UNDERFLOW   _EM_UNDERFLOW
#  define FE_OVERFLOW    _EM_OVERFLOW
#  define FE_DIVBYZERO   _EM_ZERODIVIDE
#  define FE_INVALID     _EM_INVALID
#endif

namespace CGAL {

// replacement for C99 functions

inline int
feclearexcept(int exceptions) {
  _clearfp();
  return 0;
}

inline int
fetestexcept(int exceptions)
{
#if defined(_M_IX86) && _M_IX86_FP > 0
  // On x86/x64 processors, when SSE is used.
  unsigned int i1;
  unsigned int i2;
  _statusfp2(&i1, &i2);
  return (i1 & exceptions) | (i2 & exceptions);
#else
  // On x86 processors without SSE, or on other processors supported by MSVC
  return _statusfp() & exceptions;
#endif
}

} // end namespace CGAL
