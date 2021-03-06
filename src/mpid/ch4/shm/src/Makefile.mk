##
## Copyright (C) by Argonne National Laboratory
##     See COPYRIGHT in top-level directory
##

AM_CPPFLAGS += -I$(top_srcdir)/src/mpid/ch4/shm/src

noinst_HEADERS += src/mpid/ch4/shm/src/shm_impl.h  \
        src/mpid/ch4/shm/src/shm_am.h      \
        src/mpid/ch4/shm/src/shm_control.h \
        src/mpid/ch4/shm/src/shm_types.h   \
        src/mpid/ch4/shm/src/shm_coll.h    \
        src/mpid/ch4/shm/src/shm_hooks.h   \
        src/mpid/ch4/shm/src/shm_init.h    \
        src/mpid/ch4/shm/src/shm_misc.h    \
        src/mpid/ch4/shm/src/shm_p2p.h     \
        src/mpid/ch4/shm/src/shm_noinline.h\
        src/mpid/ch4/shm/src/shm_rma.h

mpi_core_sources   += src/mpid/ch4/shm/src/func_table.c \
                      src/mpid/ch4/shm/src/shm_init.c \
                      src/mpid/ch4/shm/src/shm_hooks.c \
                      src/mpid/ch4/shm/src/shm_dpm.c \
                      src/mpid/ch4/shm/src/shm_mem.c \
                      src/mpid/ch4/shm/src/shm_misc.c \
                      src/mpid/ch4/shm/src/shm_rma.c \
                      src/mpid/ch4/shm/src/shm_control.c \
                      src/mpid/ch4/shm/src/shm_impl.c

noinst_HEADERS += src/mpid/ch4/shm/src/topotree_util.h \
                  src/mpid/ch4/shm/src/topotree_types.h\
                  src/mpid/ch4/shm/src/topotree.h

mpi_core_sources   += src/mpid/ch4/shm/src/topotree.c \
                      src/mpid/ch4/shm/src/topotree_util.c
