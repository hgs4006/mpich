/*
 * Copyright (C) by Argonne National Laboratory
 *     See COPYRIGHT in top-level directory
 */

#ifndef HYDRA_BSTRAP_SGE_H_INCLUDED
#define HYDRA_BSTRAP_SGE_H_INCLUDED

#include "hydra_base.h"
#include "hydra_mem.h"

HYD_status HYDI_bstrap_sge_launch(const char *hostname, const char *launch_exec, char **args,
                                  int *fd_stdin, int *fd_stdout, int *fd_stderr, int *pid,
                                  int debug);
HYD_status HYDI_bstrap_sge_finalize(void);

#endif /* HYDRA_BSTRAP_SGE_H_INCLUDED */
