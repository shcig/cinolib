/********************************************************************************
*  This file is part of CinoLib                                                 *
*  Copyright(C) 2016: Marco Livesu                                              *
*                                                                               *
*  The MIT License                                                              *
*                                                                               *
*  Permission is hereby granted, free of charge, to any person obtaining a      *
*  copy of this software and associated documentation files (the "Software"),   *
*  to deal in the Software without restriction, including without limitation    *
*  the rights to use, copy, modify, merge, publish, distribute, sublicense,     *
*  and/or sell copies of the Software, and to permit persons to whom the        *
*  Software is furnished to do so, subject to the following conditions:         *
*                                                                               *
*  The above copyright notice and this permission notice shall be included in   *
*  all copies or substantial portions of the Software.                          *
*                                                                               *
*  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR   *
*  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,     *
*  FITNESS FOR A PARTICULAR PURPOSE AND NON INFRINGEMENT. IN NO EVENT SHALL THE *
*  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER       *
*  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING      *
*  FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS *
*  IN THE SOFTWARE.                                                             *
*                                                                               *
*  Author(s):                                                                   *
*                                                                               *
*     Marco Livesu (marco.livesu@gmail.com)                                     *
*     http://pers.ge.imati.cnr.it/livesu/                                       *
*                                                                               *
*     Italian National Research Council (CNR)                                   *
*     Institute for Applied Mathematics and Information Technologies (IMATI)    *
*     Via de Marini, 6                                                          *
*     16149 Genoa,                                                              *
*     Italy                                                                     *
*********************************************************************************/
#include <cinolib/geometry/segment_utils.h>
#include <cinolib/geometry/point_utils.h>

namespace cinolib
{

// returns true if point p lies inside segment v0-v1
// (segment endpoints count only if strict is set to false)
CINO_INLINE
bool segment_contains_point_exact(const vec2d & v0,
                                  const vec2d & v1,
                                  const vec2d & p,
                                  const bool    strict)
{
    if(!points_are_colinear_exact(v0, v1, p)) return false;

    if(strict)
    {
        if(v0.x() < v1.x() && v0.x() < p.x() && p.x() < v1.x()) return true;
        if(v0.y() < v1.y() && v0.y() < p.y() && p.y() < v1.y()) return true;
        if(v0.x() > v1.x() && v0.x() > p.x() && p.x() > v1.x()) return true;
        if(v0.y() > v1.y() && v0.y() > p.y() && p.y() > v1.y()) return true;
    }
    else
    {
        if(v0.x() <= v1.x() && v0.x() <= p.x() && p.x() <= v1.x()) return true;
        if(v0.y() <= v1.y() && v0.y() <= p.y() && p.y() <= v1.y()) return true;
        if(v0.x() >= v1.x() && v0.x() >= p.x() && p.x() >= v1.x()) return true;
        if(v0.y() >= v1.y() && v0.y() >= p.y() && p.y() >= v1.y()) return true;
    }

    return false;
}

//::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::

// returns true if point p lies inside segment v0-v1
// (segment endpoints count only if strict is set to false)
CINO_INLINE
bool segment_contains_point_exact(const vec3d & v0,
                                  const vec3d & v1,
                                  const vec3d & p,
                                  const bool    strict)
{
    if(!points_are_colinear_exact(v0, v1, p)) return false;

    if(strict)
    {
        if(v0.x() < v1.x() && v0.x() < p.x() && p.x() < v1.x()) return true;
        if(v0.y() < v1.y() && v0.y() < p.y() && p.y() < v1.y()) return true;
        if(v0.z() < v1.z() && v0.z() < p.z() && p.z() < v1.z()) return true;
        if(v0.x() > v1.x() && v0.x() > p.x() && p.x() > v1.x()) return true;
        if(v0.y() > v1.y() && v0.y() > p.y() && p.y() > v1.y()) return true;
        if(v0.z() > v1.z() && v0.z() > p.z() && p.z() > v1.z()) return true;
    }
    else
    {
        if(v0.x() <= v1.x() && v0.x() <= p.x() && p.x() <= v1.x()) return true;
        if(v0.y() <= v1.y() && v0.y() <= p.y() && p.y() <= v1.y()) return true;
        if(v0.z() <= v1.z() && v0.z() <= p.z() && p.z() <= v1.z()) return true;
        if(v0.x() >= v1.x() && v0.x() >= p.x() && p.x() >= v1.x()) return true;
        if(v0.y() >= v1.y() && v0.y() >= p.y() && p.y() >= v1.y()) return true;
        if(v0.z() >= v1.z() && v0.z() >= p.z() && p.z() >= v1.z()) return true;
    }

    return false;
}

}
