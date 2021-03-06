/*
 * Copyright (C) by Argonne National Laboratory
 *     See COPYRIGHT in top-level directory
 */

#ifndef POSIX_EAGER_INLINE
#define POSIX_EAGER_DISABLE_INLINES

#include <mpidimpl.h>
#include <posix_eager.h>
#include "../../posix_types.h"
#include "posix_eager_inline.h"

MPIDI_POSIX_eager_funcs_t MPIDI_POSIX_eager_fbox_funcs = {
    MPIDI_POSIX_fbox_init,
    MPIDI_POSIX_fbox_finalize,

    MPIDI_POSIX_eager_send,

    MPIDI_POSIX_eager_recv_begin,
    MPIDI_POSIX_eager_recv_memcpy,
    MPIDI_POSIX_eager_recv_commit,

    MPIDI_POSIX_eager_recv_posted_hook,
    MPIDI_POSIX_eager_recv_completed_hook
};

#endif /* POSIX_EAGER_INLINE */
