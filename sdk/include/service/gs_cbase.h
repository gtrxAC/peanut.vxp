
#ifndef _GS_CBASE_H_
#define _GS_CBASE_H_

#include "gs_id.h"
#include "gs_base.h"


#define GS_CBASE_IMPLEMENT \
    public: \
    virtual S32 CALLCC addRef() \
        { \
            return GS_CBase::addRef(); \
    } \
    virtual S32 CALLCC release() \
    { \
            return GS_CBase::release(); \
    }


class GS_CBase : public GS_IBase
{
private:
    S32 refCount;
	U32 m_handle;
public:
    GS_CBase(U32 handle);
    virtual ~GS_CBase();

    int CALLCC addRef();
    int CALLCC release();
    int CALLCC queryInterface(int iid, GS_IBase** pptr);

    static void*    operator new (unsigned int size, void *buf);
    static void*    operator new (unsigned int size);
    static void     operator delete (void* ptr);
};

#endif //_GS_CBASE_H_

