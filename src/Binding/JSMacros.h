/*
   Copyright 2016 Nidium Inc. All rights reserved.
   Use of this source code is governed by a MIT license
   that can be found in the LICENSE file.
*/
#ifndef binding_jsmacros_h__
#define binding_jsmacros_h__

#define NIDIUM_JSOBJ_SET_PROP_FLAGS(where, name, val, flags)                  \
    JS_DefineProperty(m_Cx, where, reinterpret_cast<const char *>(name), val, \
                      flags)

#define NIDIUM_JSOBJ_SET_PROP(where, name, val)                         \
    NIDIUM_JSOBJ_SET_PROP_FLAGS(where, name, val, JSPROP_PERMANENT      \
                                                      | JSPROP_READONLY \
                                                      | JSPROP_ENUMERATE)

#define NIDIUM_JSOBJ_SET_PROP_CSTR(where, name, val)                           \
    {                                                                          \
        JS::RootedString __n_rootedstring(m_Cx, JS_NewStringCopyZ(m_Cx, val)); \
        NIDIUM_JSOBJ_SET_PROP(where, name, __n_rootedstring);                  \
    }

#define NIDIUM_JSOBJ_SET_PROP_STR(where, name, val) \
    NIDIUM_JSOBJ_SET_PROP(where, name, val)

#define NIDIUM_JSOBJ_SET_PROP_INT(where, name, val) \
    NIDIUM_JSOBJ_SET_PROP(where, name, val)


#endif
