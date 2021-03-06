/*
 * Copyright (C) by Argonne National Laboratory
 *     See COPYRIGHT in top-level directory
 */

#include "mpiimpl.h"
#include "coll_impl.h"
#include "csel_container.h"
#include "mpl.h"

void *MPII_Create_container(struct json_object *obj)
{
    MPII_Csel_container_s *cnt = MPL_malloc(sizeof(MPII_Csel_container_s), MPL_MEM_COLL);

    json_object_object_foreach(obj, key, val) {
        char *ckey = MPL_strdup_no_spaces(key);

        if (!strcmp(ckey, "algorithm=MPIR_Allgather_intra_brucks"))
            cnt->id = MPII_CSEL_CONTAINER_TYPE__ALGORITHM__MPIR_Allgather_intra_brucks;
        else if (!strcmp(ckey, "algorithm=MPIR_Allgather_intra_recursive_doubling"))
            cnt->id = MPII_CSEL_CONTAINER_TYPE__ALGORITHM__MPIR_Allgather_intra_recursive_doubling;
        else if (!strcmp(ckey, "algorithm=MPIR_Allgather_intra_ring"))
            cnt->id = MPII_CSEL_CONTAINER_TYPE__ALGORITHM__MPIR_Allgather_intra_ring;
        else if (!strcmp(ckey, "algorithm=MPIR_Allgather_inter_local_gather_remote_bcast"))
            cnt->id =
                MPII_CSEL_CONTAINER_TYPE__ALGORITHM__MPIR_Allgather_inter_local_gather_remote_bcast;
        else if (!strcmp(ckey, "algorithm=MPIR_Allgather_allcomm_nb"))
            cnt->id = MPII_CSEL_CONTAINER_TYPE__ALGORITHM__MPIR_Allgather_allcomm_nb;
        else if (!strcmp(ckey, "algorithm=MPIR_Allgatherv_intra_brucks"))
            cnt->id = MPII_CSEL_CONTAINER_TYPE__ALGORITHM__MPIR_Allgatherv_intra_brucks;
        else if (!strcmp(ckey, "algorithm=MPIR_Allgatherv_intra_recursive_doubling"))
            cnt->id = MPII_CSEL_CONTAINER_TYPE__ALGORITHM__MPIR_Allgatherv_intra_recursive_doubling;
        else if (!strcmp(ckey, "algorithm=MPIR_Allgatherv_intra_ring"))
            cnt->id = MPII_CSEL_CONTAINER_TYPE__ALGORITHM__MPIR_Allgatherv_intra_ring;
        else if (!strcmp(ckey, "algorithm=MPIR_Allgatherv_inter_remote_gather_local_bcast"))
            cnt->id =
                MPII_CSEL_CONTAINER_TYPE__ALGORITHM__MPIR_Allgatherv_inter_remote_gather_local_bcast;
        else if (!strcmp(ckey, "algorithm=MPIR_Allgatherv_allcomm_nb"))
            cnt->id = MPII_CSEL_CONTAINER_TYPE__ALGORITHM__MPIR_Allgatherv_allcomm_nb;
        else if (!strcmp(ckey, "algorithm=MPIR_Allreduce_intra_recursive_doubling"))
            cnt->id = MPII_CSEL_CONTAINER_TYPE__ALGORITHM__MPIR_Allreduce_intra_recursive_doubling;
        else if (!strcmp(ckey, "algorithm=MPIR_Allreduce_intra_reduce_scatter_allgather"))
            cnt->id =
                MPII_CSEL_CONTAINER_TYPE__ALGORITHM__MPIR_Allreduce_intra_reduce_scatter_allgather;
        else if (!strcmp(ckey, "algorithm=MPIR_Allreduce_intra_smp"))
            cnt->id = MPII_CSEL_CONTAINER_TYPE__ALGORITHM__MPIR_Allreduce_intra_smp;
        else if (!strcmp(ckey, "algorithm=MPIR_Allreduce_inter_reduce_exchange_bcast"))
            cnt->id =
                MPII_CSEL_CONTAINER_TYPE__ALGORITHM__MPIR_Allreduce_inter_reduce_exchange_bcast;
        else if (!strcmp(ckey, "algorithm=MPIR_Allreduce_allcomm_nb"))
            cnt->id = MPII_CSEL_CONTAINER_TYPE__ALGORITHM__MPIR_Allreduce_allcomm_nb;
        else if (!strcmp(ckey, "algorithm=MPIR_Alltoall_intra_brucks"))
            cnt->id = MPII_CSEL_CONTAINER_TYPE__ALGORITHM__MPIR_Alltoall_intra_brucks;
        else if (!strcmp(ckey, "algorithm=MPIR_Alltoall_intra_pairwise"))
            cnt->id = MPII_CSEL_CONTAINER_TYPE__ALGORITHM__MPIR_Alltoall_intra_pairwise;
        else if (!strcmp(ckey, "algorithm=MPIR_Alltoall_intra_pairwise_sendrecv_replace"))
            cnt->id =
                MPII_CSEL_CONTAINER_TYPE__ALGORITHM__MPIR_Alltoall_intra_pairwise_sendrecv_replace;
        else if (!strcmp(ckey, "algorithm=MPIR_Alltoall_intra_scattered"))
            cnt->id = MPII_CSEL_CONTAINER_TYPE__ALGORITHM__MPIR_Alltoall_intra_scattered;
        else if (!strcmp(ckey, "algorithm=MPIR_Alltoall_inter_pairwise_exchange"))
            cnt->id = MPII_CSEL_CONTAINER_TYPE__ALGORITHM__MPIR_Alltoall_inter_pairwise_exchange;
        else if (!strcmp(ckey, "algorithm=MPIR_Alltoall_allcomm_nb"))
            cnt->id = MPII_CSEL_CONTAINER_TYPE__ALGORITHM__MPIR_Alltoall_allcomm_nb;
        else if (!strcmp(ckey, "algorithm=MPIR_Alltoallv_intra_pairwise_sendrecv_replace"))
            cnt->id =
                MPII_CSEL_CONTAINER_TYPE__ALGORITHM__MPIR_Alltoallv_intra_pairwise_sendrecv_replace;
        else if (!strcmp(ckey, "algorithm=MPIR_Alltoallv_intra_scattered"))
            cnt->id = MPII_CSEL_CONTAINER_TYPE__ALGORITHM__MPIR_Alltoallv_intra_scattered;
        else if (!strcmp(ckey, "algorithm=MPIR_Alltoallv_inter_pairwise_exchange"))
            cnt->id = MPII_CSEL_CONTAINER_TYPE__ALGORITHM__MPIR_Alltoallv_inter_pairwise_exchange;
        else if (!strcmp(ckey, "algorithm=MPIR_Alltoallv_allcomm_nb"))
            cnt->id = MPII_CSEL_CONTAINER_TYPE__ALGORITHM__MPIR_Alltoallv_allcomm_nb;
        else if (!strcmp(ckey, "algorithm=MPIR_Alltoallw_intra_pairwise_sendrecv_replace"))
            cnt->id =
                MPII_CSEL_CONTAINER_TYPE__ALGORITHM__MPIR_Alltoallw_intra_pairwise_sendrecv_replace;
        else if (!strcmp(ckey, "algorithm=MPIR_Alltoallw_intra_scattered"))
            cnt->id = MPII_CSEL_CONTAINER_TYPE__ALGORITHM__MPIR_Alltoallw_intra_scattered;
        else if (!strcmp(ckey, "algorithm=MPIR_Alltoallw_inter_pairwise_exchange"))
            cnt->id = MPII_CSEL_CONTAINER_TYPE__ALGORITHM__MPIR_Alltoallw_inter_pairwise_exchange;
        else if (!strcmp(ckey, "algorithm=MPIR_Alltoallw_allcomm_nb"))
            cnt->id = MPII_CSEL_CONTAINER_TYPE__ALGORITHM__MPIR_Alltoallw_allcomm_nb;
        else if (!strcmp(ckey, "algorithm=MPIR_Barrier_intra_dissemination"))
            cnt->id = MPII_CSEL_CONTAINER_TYPE__ALGORITHM__MPIR_Barrier_intra_dissemination;
        else if (!strcmp(ckey, "algorithm=MPIR_Barrier_intra_smp"))
            cnt->id = MPII_CSEL_CONTAINER_TYPE__ALGORITHM__MPIR_Barrier_intra_smp;
        else if (!strcmp(ckey, "algorithm=MPIR_Barrier_inter_bcast"))
            cnt->id = MPII_CSEL_CONTAINER_TYPE__ALGORITHM__MPIR_Barrier_inter_bcast;
        else if (!strcmp(ckey, "algorithm=MPIR_Barrier_allcomm_nb"))
            cnt->id = MPII_CSEL_CONTAINER_TYPE__ALGORITHM__MPIR_Barrier_allcomm_nb;
        else if (!strcmp(ckey, "algorithm=MPIR_Bcast_intra_binomial"))
            cnt->id = MPII_CSEL_CONTAINER_TYPE__ALGORITHM__MPIR_Bcast_intra_binomial;
        else if (!strcmp(ckey, "algorithm=MPIR_Bcast_intra_scatter_recursive_doubling_allgather"))
            cnt->id =
                MPII_CSEL_CONTAINER_TYPE__ALGORITHM__MPIR_Bcast_intra_scatter_recursive_doubling_allgather;
        else if (!strcmp(ckey, "algorithm=MPIR_Bcast_intra_scatter_ring_allgather"))
            cnt->id = MPII_CSEL_CONTAINER_TYPE__ALGORITHM__MPIR_Bcast_intra_scatter_ring_allgather;
        else if (!strcmp(ckey, "algorithm=MPIR_Bcast_intra_smp"))
            cnt->id = MPII_CSEL_CONTAINER_TYPE__ALGORITHM__MPIR_Bcast_intra_smp;
        else if (!strcmp(ckey, "algorithm=MPIR_Bcast_inter_remote_send_local_bcast"))
            cnt->id = MPII_CSEL_CONTAINER_TYPE__ALGORITHM__MPIR_Bcast_inter_remote_send_local_bcast;
        else if (!strcmp(ckey, "algorithm=MPIR_Bcast_allcomm_nb"))
            cnt->id = MPII_CSEL_CONTAINER_TYPE__ALGORITHM__MPIR_Bcast_allcomm_nb;
        else if (!strcmp(ckey, "algorithm=MPIR_Exscan_intra_recursive_doubling"))
            cnt->id = MPII_CSEL_CONTAINER_TYPE__ALGORITHM__MPIR_Exscan_intra_recursive_doubling;
        else if (!strcmp(ckey, "algorithm=MPIR_Exscan_allcomm_nb"))
            cnt->id = MPII_CSEL_CONTAINER_TYPE__ALGORITHM__MPIR_Exscan_allcomm_nb;
        else if (!strcmp(ckey, "algorithm=MPIR_Gather_intra_binomial"))
            cnt->id = MPII_CSEL_CONTAINER_TYPE__ALGORITHM__MPIR_Gather_intra_binomial;
        else if (!strcmp(ckey, "algorithm=MPIR_Gather_inter_linear"))
            cnt->id = MPII_CSEL_CONTAINER_TYPE__ALGORITHM__MPIR_Gather_inter_linear;
        else if (!strcmp(ckey, "algorithm=MPIR_Gather_inter_local_gather_remote_send"))
            cnt->id =
                MPII_CSEL_CONTAINER_TYPE__ALGORITHM__MPIR_Gather_inter_local_gather_remote_send;
        else if (!strcmp(ckey, "algorithm=MPIR_Gather_allcomm_nb"))
            cnt->id = MPII_CSEL_CONTAINER_TYPE__ALGORITHM__MPIR_Gather_allcomm_nb;
        else if (!strcmp(ckey, "algorithm=MPIR_Gatherv_allcomm_linear"))
            cnt->id = MPII_CSEL_CONTAINER_TYPE__ALGORITHM__MPIR_Gatherv_allcomm_linear;
        else if (!strcmp(ckey, "algorithm=MPIR_Gatherv_allcomm_nb"))
            cnt->id = MPII_CSEL_CONTAINER_TYPE__ALGORITHM__MPIR_Gatherv_allcomm_nb;
        else if (!strcmp(ckey, "algorithm=MPIR_Iallgather_intra_gentran_brucks"))
            cnt->id = MPII_CSEL_CONTAINER_TYPE__ALGORITHM__MPIR_Iallgather_intra_gentran_brucks;
        else if (!strcmp(ckey, "algorithm=MPIR_Iallgather_intra_sched_auto"))
            cnt->id = MPII_CSEL_CONTAINER_TYPE__ALGORITHM__MPIR_Iallgather_intra_sched_auto;
        else if (!strcmp(ckey, "algorithm=MPIR_Iallgather_intra_sched_brucks"))
            cnt->id = MPII_CSEL_CONTAINER_TYPE__ALGORITHM__MPIR_Iallgather_intra_sched_brucks;
        else if (!strcmp(ckey, "algorithm=MPIR_Iallgather_intra_sched_recursive_doubling"))
            cnt->id =
                MPII_CSEL_CONTAINER_TYPE__ALGORITHM__MPIR_Iallgather_intra_sched_recursive_doubling;
        else if (!strcmp(ckey, "algorithm=MPIR_Iallgather_intra_sched_ring"))
            cnt->id = MPII_CSEL_CONTAINER_TYPE__ALGORITHM__MPIR_Iallgather_intra_sched_ring;
        else if (!strcmp(ckey, "algorithm=MPIR_Iallgather_intra_gentran_recexch_doubling"))
            cnt->id =
                MPII_CSEL_CONTAINER_TYPE__ALGORITHM__MPIR_Iallgather_intra_gentran_recexch_doubling;
        else if (!strcmp(ckey, "algorithm=MPIR_Iallgather_intra_gentran_recexch_halving"))
            cnt->id =
                MPII_CSEL_CONTAINER_TYPE__ALGORITHM__MPIR_Iallgather_intra_gentran_recexch_halving;
        else if (!strcmp(ckey, "algorithm=MPIR_Iallgather_intra_gentran_ring"))
            cnt->id = MPII_CSEL_CONTAINER_TYPE__ALGORITHM__MPIR_Iallgather_intra_gentran_ring;
        else if (!strcmp(ckey, "algorithm=MPIR_Iallgather_inter_sched_auto"))
            cnt->id = MPII_CSEL_CONTAINER_TYPE__ALGORITHM__MPIR_Iallgather_inter_sched_auto;
        else if (!strcmp(ckey, "algorithm=MPIR_Iallgather_inter_sched_local_gather_remote_bcast"))
            cnt->id =
                MPII_CSEL_CONTAINER_TYPE__ALGORITHM__MPIR_Iallgather_inter_sched_local_gather_remote_bcast;
        else if (!strcmp(ckey, "algorithm=MPIR_Iallgatherv_intra_gentran_brucks"))
            cnt->id = MPII_CSEL_CONTAINER_TYPE__ALGORITHM__MPIR_Iallgatherv_intra_gentran_brucks;
        else if (!strcmp(ckey, "algorithm=MPIR_Iallgatherv_intra_sched_auto"))
            cnt->id = MPII_CSEL_CONTAINER_TYPE__ALGORITHM__MPIR_Iallgatherv_intra_sched_auto;
        else if (!strcmp(ckey, "algorithm=MPIR_Iallgatherv_intra_sched_brucks"))
            cnt->id = MPII_CSEL_CONTAINER_TYPE__ALGORITHM__MPIR_Iallgatherv_intra_sched_brucks;
        else if (!strcmp(ckey, "algorithm=MPIR_Iallgatherv_intra_sched_recursive_doubling"))
            cnt->id =
                MPII_CSEL_CONTAINER_TYPE__ALGORITHM__MPIR_Iallgatherv_intra_sched_recursive_doubling;
        else if (!strcmp(ckey, "algorithm=MPIR_Iallgatherv_intra_sched_ring"))
            cnt->id = MPII_CSEL_CONTAINER_TYPE__ALGORITHM__MPIR_Iallgatherv_intra_sched_ring;
        else if (!strcmp(ckey, "algorithm=MPIR_Iallgatherv_intra_gentran_recexch_doubling"))
            cnt->id =
                MPII_CSEL_CONTAINER_TYPE__ALGORITHM__MPIR_Iallgatherv_intra_gentran_recexch_doubling;
        else if (!strcmp(ckey, "algorithm=MPIR_Iallgatherv_intra_gentran_recexch_halving"))
            cnt->id =
                MPII_CSEL_CONTAINER_TYPE__ALGORITHM__MPIR_Iallgatherv_intra_gentran_recexch_halving;
        else if (!strcmp(ckey, "algorithm=MPIR_Iallgatherv_intra_gentran_ring"))
            cnt->id = MPII_CSEL_CONTAINER_TYPE__ALGORITHM__MPIR_Iallgatherv_intra_gentran_ring;
        else if (!strcmp(ckey, "algorithm=MPIR_Iallgatherv_inter_sched_auto"))
            cnt->id = MPII_CSEL_CONTAINER_TYPE__ALGORITHM__MPIR_Iallgatherv_inter_sched_auto;
        else if (!strcmp(ckey, "algorithm=MPIR_Iallgatherv_inter_sched_remote_gather_local_bcast"))
            cnt->id =
                MPII_CSEL_CONTAINER_TYPE__ALGORITHM__MPIR_Iallgatherv_inter_sched_remote_gather_local_bcast;
        else if (!strcmp(ckey, "algorithm=MPIR_Iallreduce_intra_sched_auto"))
            cnt->id = MPII_CSEL_CONTAINER_TYPE__ALGORITHM__MPIR_Iallreduce_intra_sched_auto;
        else if (!strcmp(ckey, "algorithm=MPIR_Iallreduce_intra_sched_naive"))
            cnt->id = MPII_CSEL_CONTAINER_TYPE__ALGORITHM__MPIR_Iallreduce_intra_sched_naive;
        else if (!strcmp(ckey, "algorithm=MPIR_Iallreduce_intra_sched_recursive_doubling"))
            cnt->id =
                MPII_CSEL_CONTAINER_TYPE__ALGORITHM__MPIR_Iallreduce_intra_sched_recursive_doubling;
        else if (!strcmp(ckey, "algorithm=MPIR_Iallreduce_intra_sched_reduce_scatter_allgather"))
            cnt->id =
                MPII_CSEL_CONTAINER_TYPE__ALGORITHM__MPIR_Iallreduce_intra_sched_reduce_scatter_allgather;
        else if (!strcmp(ckey, "algorithm=MPIR_Iallreduce_intra_gentran_recexch_single_buffer"))
            cnt->id =
                MPII_CSEL_CONTAINER_TYPE__ALGORITHM__MPIR_Iallreduce_intra_gentran_recexch_single_buffer;
        else if (!strcmp(ckey, "algorithm=MPIR_Iallreduce_intra_gentran_recexch_multiple_buffer"))
            cnt->id =
                MPII_CSEL_CONTAINER_TYPE__ALGORITHM__MPIR_Iallreduce_intra_gentran_recexch_multiple_buffer;
        else if (!strcmp(ckey, "algorithm=MPIR_Iallreduce_intra_gentran_tree"))
            cnt->id = MPII_CSEL_CONTAINER_TYPE__ALGORITHM__MPIR_Iallreduce_intra_gentran_tree;
        else if (!strcmp(ckey, "algorithm=MPIR_Iallreduce_intra_gentran_ring"))
            cnt->id = MPII_CSEL_CONTAINER_TYPE__ALGORITHM__MPIR_Iallreduce_intra_gentran_ring;
        else if (!strcmp
                 (ckey,
                  "algorithm=MPIR_Iallreduce_intra_gentran_recexch_reduce_scatter_recexch_allgatherv"))
            cnt->id =
                MPII_CSEL_CONTAINER_TYPE__ALGORITHM__MPIR_Iallreduce_intra_gentran_recexch_reduce_scatter_recexch_allgatherv;
        else if (!strcmp(ckey, "algorithm=MPIR_Iallreduce_intra_sched_smp"))
            cnt->id = MPII_CSEL_CONTAINER_TYPE__ALGORITHM__MPIR_Iallreduce_intra_sched_smp;
        else if (!strcmp(ckey, "algorithm=MPIR_Iallreduce_inter_sched_auto"))
            cnt->id = MPII_CSEL_CONTAINER_TYPE__ALGORITHM__MPIR_Iallreduce_inter_sched_auto;
        else if (!strcmp(ckey, "algorithm=MPIR_Iallreduce_inter_sched_remote_reduce_local_bcast"))
            cnt->id =
                MPII_CSEL_CONTAINER_TYPE__ALGORITHM__MPIR_Iallreduce_inter_sched_remote_reduce_local_bcast;
        else if (!strcmp(ckey, "algorithm=MPIR_Ialltoall_intra_gentran_ring"))
            cnt->id = MPII_CSEL_CONTAINER_TYPE__ALGORITHM__MPIR_Ialltoall_intra_gentran_ring;
        else if (!strcmp(ckey, "algorithm=MPIR_Ialltoall_intra_gentran_brucks"))
            cnt->id = MPII_CSEL_CONTAINER_TYPE__ALGORITHM__MPIR_Ialltoall_intra_gentran_brucks;
        else if (!strcmp(ckey, "algorithm=MPIR_Ialltoall_intra_gentran_scattered"))
            cnt->id = MPII_CSEL_CONTAINER_TYPE__ALGORITHM__MPIR_Ialltoall_intra_gentran_scattered;
        else if (!strcmp(ckey, "algorithm=MPIR_Ialltoall_intra_sched_auto"))
            cnt->id = MPII_CSEL_CONTAINER_TYPE__ALGORITHM__MPIR_Ialltoall_intra_sched_auto;
        else if (!strcmp(ckey, "algorithm=MPIR_Ialltoall_intra_sched_brucks"))
            cnt->id = MPII_CSEL_CONTAINER_TYPE__ALGORITHM__MPIR_Ialltoall_intra_sched_brucks;
        else if (!strcmp(ckey, "algorithm=MPIR_Ialltoall_intra_sched_inplace"))
            cnt->id = MPII_CSEL_CONTAINER_TYPE__ALGORITHM__MPIR_Ialltoall_intra_sched_inplace;
        else if (!strcmp(ckey, "algorithm=MPIR_Ialltoall_intra_sched_pairwise"))
            cnt->id = MPII_CSEL_CONTAINER_TYPE__ALGORITHM__MPIR_Ialltoall_intra_sched_pairwise;
        else if (!strcmp(ckey, "algorithm=MPIR_Ialltoall_intra_sched_permuted_sendrecv"))
            cnt->id =
                MPII_CSEL_CONTAINER_TYPE__ALGORITHM__MPIR_Ialltoall_intra_sched_permuted_sendrecv;
        else if (!strcmp(ckey, "algorithm=MPIR_Ialltoall_inter_sched_auto"))
            cnt->id = MPII_CSEL_CONTAINER_TYPE__ALGORITHM__MPIR_Ialltoall_inter_sched_auto;
        else if (!strcmp(ckey, "algorithm=MPIR_Ialltoall_inter_sched_pairwise_exchange"))
            cnt->id =
                MPII_CSEL_CONTAINER_TYPE__ALGORITHM__MPIR_Ialltoall_inter_sched_pairwise_exchange;
        else if (!strcmp(ckey, "algorithm=MPIR_Ialltoallv_intra_sched_auto"))
            cnt->id = MPII_CSEL_CONTAINER_TYPE__ALGORITHM__MPIR_Ialltoallv_intra_sched_auto;
        else if (!strcmp(ckey, "algorithm=MPIR_Ialltoallv_intra_sched_blocked"))
            cnt->id = MPII_CSEL_CONTAINER_TYPE__ALGORITHM__MPIR_Ialltoallv_intra_sched_blocked;
        else if (!strcmp(ckey, "algorithm=MPIR_Ialltoallv_intra_sched_inplace"))
            cnt->id = MPII_CSEL_CONTAINER_TYPE__ALGORITHM__MPIR_Ialltoallv_intra_sched_inplace;
        else if (!strcmp(ckey, "algorithm=MPIR_Ialltoallv_intra_gentran_scattered"))
            cnt->id = MPII_CSEL_CONTAINER_TYPE__ALGORITHM__MPIR_Ialltoallv_intra_gentran_scattered;
        else if (!strcmp(ckey, "algorithm=MPIR_Ialltoallv_intra_gentran_blocked"))
            cnt->id = MPII_CSEL_CONTAINER_TYPE__ALGORITHM__MPIR_Ialltoallv_intra_gentran_blocked;
        else if (!strcmp(ckey, "algorithm=MPIR_Ialltoallv_intra_gentran_inplace"))
            cnt->id = MPII_CSEL_CONTAINER_TYPE__ALGORITHM__MPIR_Ialltoallv_intra_gentran_inplace;
        else if (!strcmp(ckey, "algorithm=MPIR_Ialltoallv_inter_sched_auto"))
            cnt->id = MPII_CSEL_CONTAINER_TYPE__ALGORITHM__MPIR_Ialltoallv_inter_sched_auto;
        else if (!strcmp(ckey, "algorithm=MPIR_Ialltoallv_inter_sched_pairwise_exchange"))
            cnt->id =
                MPII_CSEL_CONTAINER_TYPE__ALGORITHM__MPIR_Ialltoallv_inter_sched_pairwise_exchange;
        else if (!strcmp(ckey, "algorithm=MPIR_Ialltoallw_intra_gentran_blocked"))
            cnt->id = MPII_CSEL_CONTAINER_TYPE__ALGORITHM__MPIR_Ialltoallw_intra_gentran_blocked;
        else if (!strcmp(ckey, "algorithm=MPIR_Ialltoallw_intra_gentran_inplace"))
            cnt->id = MPII_CSEL_CONTAINER_TYPE__ALGORITHM__MPIR_Ialltoallw_intra_gentran_inplace;
        else if (!strcmp(ckey, "algorithm=MPIR_Ialltoallw_intra_sched_auto"))
            cnt->id = MPII_CSEL_CONTAINER_TYPE__ALGORITHM__MPIR_Ialltoallw_intra_sched_auto;
        else if (!strcmp(ckey, "algorithm=MPIR_Ialltoallw_intra_sched_blocked"))
            cnt->id = MPII_CSEL_CONTAINER_TYPE__ALGORITHM__MPIR_Ialltoallw_intra_sched_blocked;
        else if (!strcmp(ckey, "algorithm=MPIR_Ialltoallw_intra_sched_inplace"))
            cnt->id = MPII_CSEL_CONTAINER_TYPE__ALGORITHM__MPIR_Ialltoallw_intra_sched_inplace;
        else if (!strcmp(ckey, "algorithm=MPIR_Ialltoallw_inter_sched_auto"))
            cnt->id = MPII_CSEL_CONTAINER_TYPE__ALGORITHM__MPIR_Ialltoallw_inter_sched_auto;
        else if (!strcmp(ckey, "algorithm=MPIR_Ialltoallw_inter_sched_pairwise_exchange"))
            cnt->id =
                MPII_CSEL_CONTAINER_TYPE__ALGORITHM__MPIR_Ialltoallw_inter_sched_pairwise_exchange;
        else if (!strcmp(ckey, "algorithm=MPIR_Ibarrier_intra_sched_auto"))
            cnt->id = MPII_CSEL_CONTAINER_TYPE__ALGORITHM__MPIR_Ibarrier_intra_sched_auto;
        else if (!strcmp(ckey, "algorithm=MPIR_Ibarrier_intra_sched_recursive_doubling"))
            cnt->id =
                MPII_CSEL_CONTAINER_TYPE__ALGORITHM__MPIR_Ibarrier_intra_sched_recursive_doubling;
        else if (!strcmp(ckey, "algorithm=MPIR_Ibarrier_intra_gentran_recexch"))
            cnt->id = MPII_CSEL_CONTAINER_TYPE__ALGORITHM__MPIR_Ibarrier_intra_gentran_recexch;
        else if (!strcmp(ckey, "algorithm=MPIR_Ibarrier_inter_sched_auto"))
            cnt->id = MPII_CSEL_CONTAINER_TYPE__ALGORITHM__MPIR_Ibarrier_inter_sched_auto;
        else if (!strcmp(ckey, "algorithm=MPIR_Ibarrier_inter_sched_bcast"))
            cnt->id = MPII_CSEL_CONTAINER_TYPE__ALGORITHM__MPIR_Ibarrier_inter_sched_bcast;
        else if (!strcmp(ckey, "algorithm=MPIR_Ibcast_intra_gentran_tree"))
            cnt->id = MPII_CSEL_CONTAINER_TYPE__ALGORITHM__MPIR_Ibcast_intra_gentran_tree;
        else if (!strcmp(ckey, "algorithm=MPIR_Ibcast_intra_gentran_scatterv_recexch_allgatherv"))
            cnt->id =
                MPII_CSEL_CONTAINER_TYPE__ALGORITHM__MPIR_Ibcast_intra_gentran_scatterv_recexch_allgatherv;
        else if (!strcmp(ckey, "algorithm=MPIR_Ibcast_intra_gentran_ring"))
            cnt->id = MPII_CSEL_CONTAINER_TYPE__ALGORITHM__MPIR_Ibcast_intra_gentran_ring;
        else if (!strcmp(ckey, "algorithm=MPIR_Ibcast_intra_sched_auto"))
            cnt->id = MPII_CSEL_CONTAINER_TYPE__ALGORITHM__MPIR_Ibcast_intra_sched_auto;
        else if (!strcmp(ckey, "algorithm=MPIR_Ibcast_intra_sched_binomial"))
            cnt->id = MPII_CSEL_CONTAINER_TYPE__ALGORITHM__MPIR_Ibcast_intra_sched_binomial;
        else if (!strcmp
                 (ckey, "algorithm=MPIR_Ibcast_intra_sched_scatter_recursive_doubling_allgather"))
            cnt->id =
                MPII_CSEL_CONTAINER_TYPE__ALGORITHM__MPIR_Ibcast_intra_sched_scatter_recursive_doubling_allgather;
        else if (!strcmp(ckey, "algorithm=MPIR_Ibcast_intra_sched_scatter_ring_allgather"))
            cnt->id =
                MPII_CSEL_CONTAINER_TYPE__ALGORITHM__MPIR_Ibcast_intra_sched_scatter_ring_allgather;
        else if (!strcmp(ckey, "algorithm=MPIR_Ibcast_intra_sched_smp"))
            cnt->id = MPII_CSEL_CONTAINER_TYPE__ALGORITHM__MPIR_Ibcast_intra_sched_smp;
        else if (!strcmp(ckey, "algorithm=MPIR_Ibcast_inter_sched_auto"))
            cnt->id = MPII_CSEL_CONTAINER_TYPE__ALGORITHM__MPIR_Ibcast_inter_sched_auto;
        else if (!strcmp(ckey, "algorithm=MPIR_Ibcast_inter_sched_flat"))
            cnt->id = MPII_CSEL_CONTAINER_TYPE__ALGORITHM__MPIR_Ibcast_inter_sched_flat;
        else if (!strcmp(ckey, "algorithm=MPIR_Iexscan_intra_sched_auto"))
            cnt->id = MPII_CSEL_CONTAINER_TYPE__ALGORITHM__MPIR_Iexscan_intra_sched_auto;
        else if (!strcmp(ckey, "algorithm=MPIR_Iexscan_intra_sched_recursive_doubling"))
            cnt->id =
                MPII_CSEL_CONTAINER_TYPE__ALGORITHM__MPIR_Iexscan_intra_sched_recursive_doubling;
        else if (!strcmp(ckey, "algorithm=MPIR_Igather_intra_gentran_tree"))
            cnt->id = MPII_CSEL_CONTAINER_TYPE__ALGORITHM__MPIR_Igather_intra_gentran_tree;
        else if (!strcmp(ckey, "algorithm=MPIR_Igather_intra_sched_auto"))
            cnt->id = MPII_CSEL_CONTAINER_TYPE__ALGORITHM__MPIR_Igather_intra_sched_auto;
        else if (!strcmp(ckey, "algorithm=MPIR_Igather_intra_sched_binomial"))
            cnt->id = MPII_CSEL_CONTAINER_TYPE__ALGORITHM__MPIR_Igather_intra_sched_binomial;
        else if (!strcmp(ckey, "algorithm=MPIR_Igather_inter_sched_auto"))
            cnt->id = MPII_CSEL_CONTAINER_TYPE__ALGORITHM__MPIR_Igather_inter_sched_auto;
        else if (!strcmp(ckey, "algorithm=MPIR_Igather_inter_sched_long"))
            cnt->id = MPII_CSEL_CONTAINER_TYPE__ALGORITHM__MPIR_Igather_inter_sched_long;
        else if (!strcmp(ckey, "algorithm=MPIR_Igather_inter_sched_short"))
            cnt->id = MPII_CSEL_CONTAINER_TYPE__ALGORITHM__MPIR_Igather_inter_sched_short;
        else if (!strcmp(ckey, "algorithm=MPIR_Igatherv_allcomm_gentran_linear"))
            cnt->id = MPII_CSEL_CONTAINER_TYPE__ALGORITHM__MPIR_Igatherv_allcomm_gentran_linear;
        else if (!strcmp(ckey, "algorithm=MPIR_Igatherv_intra_sched_auto"))
            cnt->id = MPII_CSEL_CONTAINER_TYPE__ALGORITHM__MPIR_Igatherv_intra_sched_auto;
        else if (!strcmp(ckey, "algorithm=MPIR_Igatherv_inter_sched_auto"))
            cnt->id = MPII_CSEL_CONTAINER_TYPE__ALGORITHM__MPIR_Igatherv_inter_sched_auto;
        else if (!strcmp(ckey, "algorithm=MPIR_Igatherv_allcomm_sched_linear"))
            cnt->id = MPII_CSEL_CONTAINER_TYPE__ALGORITHM__MPIR_Igatherv_allcomm_sched_linear;
        else if (!strcmp(ckey, "algorithm=MPIR_Ineighbor_allgather_allcomm_gentran_linear"))
            cnt->id =
                MPII_CSEL_CONTAINER_TYPE__ALGORITHM__MPIR_Ineighbor_allgather_allcomm_gentran_linear;
        else if (!strcmp(ckey, "algorithm=MPIR_Ineighbor_allgather_intra_sched_auto"))
            cnt->id =
                MPII_CSEL_CONTAINER_TYPE__ALGORITHM__MPIR_Ineighbor_allgather_intra_sched_auto;
        else if (!strcmp(ckey, "algorithm=MPIR_Ineighbor_allgather_inter_sched_auto"))
            cnt->id =
                MPII_CSEL_CONTAINER_TYPE__ALGORITHM__MPIR_Ineighbor_allgather_inter_sched_auto;
        else if (!strcmp(ckey, "algorithm=MPIR_Ineighbor_allgather_allcomm_sched_linear"))
            cnt->id =
                MPII_CSEL_CONTAINER_TYPE__ALGORITHM__MPIR_Ineighbor_allgather_allcomm_sched_linear;
        else if (!strcmp(ckey, "algorithm=MPIR_Ineighbor_allgatherv_allcomm_gentran_linear"))
            cnt->id =
                MPII_CSEL_CONTAINER_TYPE__ALGORITHM__MPIR_Ineighbor_allgatherv_allcomm_gentran_linear;
        else if (!strcmp(ckey, "algorithm=MPIR_Ineighbor_allgatherv_intra_sched_auto"))
            cnt->id =
                MPII_CSEL_CONTAINER_TYPE__ALGORITHM__MPIR_Ineighbor_allgatherv_intra_sched_auto;
        else if (!strcmp(ckey, "algorithm=MPIR_Ineighbor_allgatherv_inter_sched_auto"))
            cnt->id =
                MPII_CSEL_CONTAINER_TYPE__ALGORITHM__MPIR_Ineighbor_allgatherv_inter_sched_auto;
        else if (!strcmp(ckey, "algorithm=MPIR_Ineighbor_allgatherv_allcomm_sched_linear"))
            cnt->id =
                MPII_CSEL_CONTAINER_TYPE__ALGORITHM__MPIR_Ineighbor_allgatherv_allcomm_sched_linear;
        else if (!strcmp(ckey, "algorithm=MPIR_Ineighbor_alltoall_allcomm_gentran_linear"))
            cnt->id =
                MPII_CSEL_CONTAINER_TYPE__ALGORITHM__MPIR_Ineighbor_alltoall_allcomm_gentran_linear;
        else if (!strcmp(ckey, "algorithm=MPIR_Ineighbor_alltoall_intra_sched_auto"))
            cnt->id = MPII_CSEL_CONTAINER_TYPE__ALGORITHM__MPIR_Ineighbor_alltoall_intra_sched_auto;
        else if (!strcmp(ckey, "algorithm=MPIR_Ineighbor_alltoall_inter_sched_auto"))
            cnt->id = MPII_CSEL_CONTAINER_TYPE__ALGORITHM__MPIR_Ineighbor_alltoall_inter_sched_auto;
        else if (!strcmp(ckey, "algorithm=MPIR_Ineighbor_alltoall_allcomm_sched_linear"))
            cnt->id =
                MPII_CSEL_CONTAINER_TYPE__ALGORITHM__MPIR_Ineighbor_alltoall_allcomm_sched_linear;
        else if (!strcmp(ckey, "algorithm=MPIR_Ineighbor_alltoallv_allcomm_gentran_linear"))
            cnt->id =
                MPII_CSEL_CONTAINER_TYPE__ALGORITHM__MPIR_Ineighbor_alltoallv_allcomm_gentran_linear;
        else if (!strcmp(ckey, "algorithm=MPIR_Ineighbor_alltoallv_intra_sched_auto"))
            cnt->id =
                MPII_CSEL_CONTAINER_TYPE__ALGORITHM__MPIR_Ineighbor_alltoallv_intra_sched_auto;
        else if (!strcmp(ckey, "algorithm=MPIR_Ineighbor_alltoallv_inter_sched_auto"))
            cnt->id =
                MPII_CSEL_CONTAINER_TYPE__ALGORITHM__MPIR_Ineighbor_alltoallv_inter_sched_auto;
        else if (!strcmp(ckey, "algorithm=MPIR_Ineighbor_alltoallv_allcomm_sched_linear"))
            cnt->id =
                MPII_CSEL_CONTAINER_TYPE__ALGORITHM__MPIR_Ineighbor_alltoallv_allcomm_sched_linear;
        else if (!strcmp(ckey, "algorithm=MPIR_Ineighbor_alltoallw_allcomm_gentran_linear"))
            cnt->id =
                MPII_CSEL_CONTAINER_TYPE__ALGORITHM__MPIR_Ineighbor_alltoallw_allcomm_gentran_linear;
        else if (!strcmp(ckey, "algorithm=MPIR_Ineighbor_alltoallw_intra_sched_auto"))
            cnt->id =
                MPII_CSEL_CONTAINER_TYPE__ALGORITHM__MPIR_Ineighbor_alltoallw_intra_sched_auto;
        else if (!strcmp(ckey, "algorithm=MPIR_Ineighbor_alltoallw_inter_sched_auto"))
            cnt->id =
                MPII_CSEL_CONTAINER_TYPE__ALGORITHM__MPIR_Ineighbor_alltoallw_inter_sched_auto;
        else if (!strcmp(ckey, "algorithm=MPIR_Ineighbor_alltoallw_allcomm_sched_linear"))
            cnt->id =
                MPII_CSEL_CONTAINER_TYPE__ALGORITHM__MPIR_Ineighbor_alltoallw_allcomm_sched_linear;
        else if (!strcmp(ckey, "algorithm=MPIR_Ireduce_intra_gentran_tree"))
            cnt->id = MPII_CSEL_CONTAINER_TYPE__ALGORITHM__MPIR_Ireduce_intra_gentran_tree;
        else if (!strcmp(ckey, "algorithm=MPIR_Ireduce_intra_gentran_ring"))
            cnt->id = MPII_CSEL_CONTAINER_TYPE__ALGORITHM__MPIR_Ireduce_intra_gentran_ring;
        else if (!strcmp(ckey, "algorithm=MPIR_Ireduce_intra_sched_auto"))
            cnt->id = MPII_CSEL_CONTAINER_TYPE__ALGORITHM__MPIR_Ireduce_intra_sched_auto;
        else if (!strcmp(ckey, "algorithm=MPIR_Ireduce_intra_sched_binomial"))
            cnt->id = MPII_CSEL_CONTAINER_TYPE__ALGORITHM__MPIR_Ireduce_intra_sched_binomial;
        else if (!strcmp(ckey, "algorithm=MPIR_Ireduce_intra_sched_reduce_scatter_gather"))
            cnt->id =
                MPII_CSEL_CONTAINER_TYPE__ALGORITHM__MPIR_Ireduce_intra_sched_reduce_scatter_gather;
        else if (!strcmp(ckey, "algorithm=MPIR_Ireduce_intra_sched_smp"))
            cnt->id = MPII_CSEL_CONTAINER_TYPE__ALGORITHM__MPIR_Ireduce_intra_sched_smp;
        else if (!strcmp(ckey, "algorithm=MPIR_Ireduce_inter_sched_auto"))
            cnt->id = MPII_CSEL_CONTAINER_TYPE__ALGORITHM__MPIR_Ireduce_inter_sched_auto;
        else if (!strcmp(ckey, "algorithm=MPIR_Ireduce_inter_sched_local_reduce_remote_send"))
            cnt->id =
                MPII_CSEL_CONTAINER_TYPE__ALGORITHM__MPIR_Ireduce_inter_sched_local_reduce_remote_send;
        else if (!strcmp(ckey, "algorithm=MPIR_Ireduce_scatter_intra_sched_auto"))
            cnt->id = MPII_CSEL_CONTAINER_TYPE__ALGORITHM__MPIR_Ireduce_scatter_intra_sched_auto;
        else if (!strcmp(ckey, "algorithm=MPIR_Ireduce_scatter_intra_sched_noncommutative"))
            cnt->id =
                MPII_CSEL_CONTAINER_TYPE__ALGORITHM__MPIR_Ireduce_scatter_intra_sched_noncommutative;
        else if (!strcmp(ckey, "algorithm=MPIR_Ireduce_scatter_intra_sched_pairwise"))
            cnt->id =
                MPII_CSEL_CONTAINER_TYPE__ALGORITHM__MPIR_Ireduce_scatter_intra_sched_pairwise;
        else if (!strcmp(ckey, "algorithm=MPIR_Ireduce_scatter_intra_sched_recursive_doubling"))
            cnt->id =
                MPII_CSEL_CONTAINER_TYPE__ALGORITHM__MPIR_Ireduce_scatter_intra_sched_recursive_doubling;
        else if (!strcmp(ckey, "algorithm=MPIR_Ireduce_scatter_intra_sched_recursive_halving"))
            cnt->id =
                MPII_CSEL_CONTAINER_TYPE__ALGORITHM__MPIR_Ireduce_scatter_intra_sched_recursive_halving;
        else if (!strcmp(ckey, "algorithm=MPIR_Ireduce_scatter_intra_gentran_recexch"))
            cnt->id =
                MPII_CSEL_CONTAINER_TYPE__ALGORITHM__MPIR_Ireduce_scatter_intra_gentran_recexch;
        else if (!strcmp(ckey, "algorithm=MPIR_Ireduce_scatter_inter_sched_auto"))
            cnt->id = MPII_CSEL_CONTAINER_TYPE__ALGORITHM__MPIR_Ireduce_scatter_inter_sched_auto;
        else if (!strcmp
                 (ckey, "algorithm=MPIR_Ireduce_scatter_inter_sched_remote_reduce_local_scatterv"))
            cnt->id =
                MPII_CSEL_CONTAINER_TYPE__ALGORITHM__MPIR_Ireduce_scatter_inter_sched_remote_reduce_local_scatterv;
        else if (!strcmp(ckey, "algorithm=MPIR_Ireduce_scatter_block_intra_gentran_recexch"))
            cnt->id =
                MPII_CSEL_CONTAINER_TYPE__ALGORITHM__MPIR_Ireduce_scatter_block_intra_gentran_recexch;
        else if (!strcmp(ckey, "algorithm=MPIR_Ireduce_scatter_block_intra_sched_auto"))
            cnt->id =
                MPII_CSEL_CONTAINER_TYPE__ALGORITHM__MPIR_Ireduce_scatter_block_intra_sched_auto;
        else if (!strcmp(ckey, "algorithm=MPIR_Ireduce_scatter_block_intra_sched_noncommutative"))
            cnt->id =
                MPII_CSEL_CONTAINER_TYPE__ALGORITHM__MPIR_Ireduce_scatter_block_intra_sched_noncommutative;
        else if (!strcmp(ckey, "algorithm=MPIR_Ireduce_scatter_block_intra_sched_pairwise"))
            cnt->id =
                MPII_CSEL_CONTAINER_TYPE__ALGORITHM__MPIR_Ireduce_scatter_block_intra_sched_pairwise;
        else if (!strcmp
                 (ckey, "algorithm=MPIR_Ireduce_scatter_block_intra_sched_recursive_doubling"))
            cnt->id =
                MPII_CSEL_CONTAINER_TYPE__ALGORITHM__MPIR_Ireduce_scatter_block_intra_sched_recursive_doubling;
        else if (!strcmp
                 (ckey, "algorithm=MPIR_Ireduce_scatter_block_intra_sched_recursive_halving"))
            cnt->id =
                MPII_CSEL_CONTAINER_TYPE__ALGORITHM__MPIR_Ireduce_scatter_block_intra_sched_recursive_halving;
        else if (!strcmp(ckey, "algorithm=MPIR_Ireduce_scatter_block_inter_sched_auto"))
            cnt->id =
                MPII_CSEL_CONTAINER_TYPE__ALGORITHM__MPIR_Ireduce_scatter_block_inter_sched_auto;
        else if (!strcmp
                 (ckey,
                  "algorithm=MPIR_Ireduce_scatter_block_inter_sched_remote_reduce_local_scatterv"))
            cnt->id =
                MPII_CSEL_CONTAINER_TYPE__ALGORITHM__MPIR_Ireduce_scatter_block_inter_sched_remote_reduce_local_scatterv;
        else if (!strcmp(ckey, "algorithm=MPIR_Iscan_intra_sched_auto"))
            cnt->id = MPII_CSEL_CONTAINER_TYPE__ALGORITHM__MPIR_Iscan_intra_sched_auto;
        else if (!strcmp(ckey, "algorithm=MPIR_Iscan_intra_sched_recursive_doubling"))
            cnt->id =
                MPII_CSEL_CONTAINER_TYPE__ALGORITHM__MPIR_Iscan_intra_sched_recursive_doubling;
        else if (!strcmp(ckey, "algorithm=MPIR_Iscan_intra_sched_smp"))
            cnt->id = MPII_CSEL_CONTAINER_TYPE__ALGORITHM__MPIR_Iscan_intra_sched_smp;
        else if (!strcmp(ckey, "algorithm=MPIR_Iscan_intra_gentran_recursive_doubling"))
            cnt->id =
                MPII_CSEL_CONTAINER_TYPE__ALGORITHM__MPIR_Iscan_intra_gentran_recursive_doubling;
        else if (!strcmp(ckey, "algorithm=MPIR_Iscatter_intra_gentran_tree"))
            cnt->id = MPII_CSEL_CONTAINER_TYPE__ALGORITHM__MPIR_Iscatter_intra_gentran_tree;
        else if (!strcmp(ckey, "algorithm=MPIR_Iscatter_intra_sched_auto"))
            cnt->id = MPII_CSEL_CONTAINER_TYPE__ALGORITHM__MPIR_Iscatter_intra_sched_auto;
        else if (!strcmp(ckey, "algorithm=MPIR_Iscatter_intra_sched_binomial"))
            cnt->id = MPII_CSEL_CONTAINER_TYPE__ALGORITHM__MPIR_Iscatter_intra_sched_binomial;
        else if (!strcmp(ckey, "algorithm=MPIR_Iscatter_inter_sched_auto"))
            cnt->id = MPII_CSEL_CONTAINER_TYPE__ALGORITHM__MPIR_Iscatter_inter_sched_auto;
        else if (!strcmp(ckey, "algorithm=MPIR_Iscatter_inter_sched_linear"))
            cnt->id = MPII_CSEL_CONTAINER_TYPE__ALGORITHM__MPIR_Iscatter_inter_sched_linear;
        else if (!strcmp(ckey, "algorithm=MPIR_Iscatter_inter_sched_remote_send_local_scatter"))
            cnt->id =
                MPII_CSEL_CONTAINER_TYPE__ALGORITHM__MPIR_Iscatter_inter_sched_remote_send_local_scatter;
        else if (!strcmp(ckey, "algorithm=MPIR_Iscatterv_allcomm_gentran_linear"))
            cnt->id = MPII_CSEL_CONTAINER_TYPE__ALGORITHM__MPIR_Iscatterv_allcomm_gentran_linear;
        else if (!strcmp(ckey, "algorithm=MPIR_Iscatterv_intra_sched_auto"))
            cnt->id = MPII_CSEL_CONTAINER_TYPE__ALGORITHM__MPIR_Iscatterv_intra_sched_auto;
        else if (!strcmp(ckey, "algorithm=MPIR_Iscatterv_inter_sched_auto"))
            cnt->id = MPII_CSEL_CONTAINER_TYPE__ALGORITHM__MPIR_Iscatterv_inter_sched_auto;
        else if (!strcmp(ckey, "algorithm=MPIR_Iscatterv_allcomm_sched_linear"))
            cnt->id = MPII_CSEL_CONTAINER_TYPE__ALGORITHM__MPIR_Iscatterv_allcomm_sched_linear;
        else if (!strcmp(ckey, "algorithm=MPIR_Neighbor_allgather_allcomm_nb"))
            cnt->id = MPII_CSEL_CONTAINER_TYPE__ALGORITHM__MPIR_Neighbor_allgather_allcomm_nb;
        else if (!strcmp(ckey, "algorithm=MPIR_Neighbor_allgatherv_allcomm_nb"))
            cnt->id = MPII_CSEL_CONTAINER_TYPE__ALGORITHM__MPIR_Neighbor_allgatherv_allcomm_nb;
        else if (!strcmp(ckey, "algorithm=MPIR_Neighbor_alltoall_allcomm_nb"))
            cnt->id = MPII_CSEL_CONTAINER_TYPE__ALGORITHM__MPIR_Neighbor_alltoall_allcomm_nb;
        else if (!strcmp(ckey, "algorithm=MPIR_Neighbor_alltoallv_allcomm_nb"))
            cnt->id = MPII_CSEL_CONTAINER_TYPE__ALGORITHM__MPIR_Neighbor_alltoallv_allcomm_nb;
        else if (!strcmp(ckey, "algorithm=MPIR_Neighbor_alltoallw_allcomm_nb"))
            cnt->id = MPII_CSEL_CONTAINER_TYPE__ALGORITHM__MPIR_Neighbor_alltoallw_allcomm_nb;
        else if (!strcmp(ckey, "algorithm=MPIR_Reduce_intra_binomial"))
            cnt->id = MPII_CSEL_CONTAINER_TYPE__ALGORITHM__MPIR_Reduce_intra_binomial;
        else if (!strcmp(ckey, "algorithm=MPIR_Reduce_intra_reduce_scatter_gather"))
            cnt->id = MPII_CSEL_CONTAINER_TYPE__ALGORITHM__MPIR_Reduce_intra_reduce_scatter_gather;
        else if (!strcmp(ckey, "algorithm=MPIR_Reduce_intra_smp"))
            cnt->id = MPII_CSEL_CONTAINER_TYPE__ALGORITHM__MPIR_Reduce_intra_smp;
        else if (!strcmp(ckey, "algorithm=MPIR_Reduce_inter_local_reduce_remote_send"))
            cnt->id =
                MPII_CSEL_CONTAINER_TYPE__ALGORITHM__MPIR_Reduce_inter_local_reduce_remote_send;
        else if (!strcmp(ckey, "algorithm=MPIR_Reduce_allcomm_nb"))
            cnt->id = MPII_CSEL_CONTAINER_TYPE__ALGORITHM__MPIR_Reduce_allcomm_nb;
        else if (!strcmp(ckey, "algorithm=MPIR_Reduce_scatter_intra_noncommutative"))
            cnt->id = MPII_CSEL_CONTAINER_TYPE__ALGORITHM__MPIR_Reduce_scatter_intra_noncommutative;
        else if (!strcmp(ckey, "algorithm=MPIR_Reduce_scatter_intra_pairwise"))
            cnt->id = MPII_CSEL_CONTAINER_TYPE__ALGORITHM__MPIR_Reduce_scatter_intra_pairwise;
        else if (!strcmp(ckey, "algorithm=MPIR_Reduce_scatter_intra_recursive_doubling"))
            cnt->id =
                MPII_CSEL_CONTAINER_TYPE__ALGORITHM__MPIR_Reduce_scatter_intra_recursive_doubling;
        else if (!strcmp(ckey, "algorithm=MPIR_Reduce_scatter_intra_recursive_halving"))
            cnt->id =
                MPII_CSEL_CONTAINER_TYPE__ALGORITHM__MPIR_Reduce_scatter_intra_recursive_halving;
        else if (!strcmp(ckey, "algorithm=MPIR_Reduce_scatter_inter_remote_reduce_local_scatter"))
            cnt->id =
                MPII_CSEL_CONTAINER_TYPE__ALGORITHM__MPIR_Reduce_scatter_inter_remote_reduce_local_scatter;
        else if (!strcmp(ckey, "algorithm=MPIR_Reduce_scatter_allcomm_nb"))
            cnt->id = MPII_CSEL_CONTAINER_TYPE__ALGORITHM__MPIR_Reduce_scatter_allcomm_nb;
        else if (!strcmp(ckey, "algorithm=MPIR_Reduce_scatter_block_intra_noncommutative"))
            cnt->id =
                MPII_CSEL_CONTAINER_TYPE__ALGORITHM__MPIR_Reduce_scatter_block_intra_noncommutative;
        else if (!strcmp(ckey, "algorithm=MPIR_Reduce_scatter_block_intra_pairwise"))
            cnt->id = MPII_CSEL_CONTAINER_TYPE__ALGORITHM__MPIR_Reduce_scatter_block_intra_pairwise;
        else if (!strcmp(ckey, "algorithm=MPIR_Reduce_scatter_block_intra_recursive_doubling"))
            cnt->id =
                MPII_CSEL_CONTAINER_TYPE__ALGORITHM__MPIR_Reduce_scatter_block_intra_recursive_doubling;
        else if (!strcmp(ckey, "algorithm=MPIR_Reduce_scatter_block_intra_recursive_halving"))
            cnt->id =
                MPII_CSEL_CONTAINER_TYPE__ALGORITHM__MPIR_Reduce_scatter_block_intra_recursive_halving;
        else if (!strcmp
                 (ckey, "algorithm=MPIR_Reduce_scatter_block_inter_remote_reduce_local_scatter"))
            cnt->id =
                MPII_CSEL_CONTAINER_TYPE__ALGORITHM__MPIR_Reduce_scatter_block_inter_remote_reduce_local_scatter;
        else if (!strcmp(ckey, "algorithm=MPIR_Reduce_scatter_block_allcomm_nb"))
            cnt->id = MPII_CSEL_CONTAINER_TYPE__ALGORITHM__MPIR_Reduce_scatter_block_allcomm_nb;
        else if (!strcmp(ckey, "algorithm=MPIR_Scan_intra_recursive_doubling"))
            cnt->id = MPII_CSEL_CONTAINER_TYPE__ALGORITHM__MPIR_Scan_intra_recursive_doubling;
        else if (!strcmp(ckey, "algorithm=MPIR_Scan_intra_smp"))
            cnt->id = MPII_CSEL_CONTAINER_TYPE__ALGORITHM__MPIR_Scan_intra_smp;
        else if (!strcmp(ckey, "algorithm=MPIR_Scan_allcomm_nb"))
            cnt->id = MPII_CSEL_CONTAINER_TYPE__ALGORITHM__MPIR_Scan_allcomm_nb;
        else if (!strcmp(ckey, "algorithm=MPIR_Scatter_intra_binomial"))
            cnt->id = MPII_CSEL_CONTAINER_TYPE__ALGORITHM__MPIR_Scatter_intra_binomial;
        else if (!strcmp(ckey, "algorithm=MPIR_Scatter_inter_linear"))
            cnt->id = MPII_CSEL_CONTAINER_TYPE__ALGORITHM__MPIR_Scatter_inter_linear;
        else if (!strcmp(ckey, "algorithm=MPIR_Scatter_inter_remote_send_local_scatter"))
            cnt->id =
                MPII_CSEL_CONTAINER_TYPE__ALGORITHM__MPIR_Scatter_inter_remote_send_local_scatter;
        else if (!strcmp(ckey, "algorithm=MPIR_Scatter_allcomm_nb"))
            cnt->id = MPII_CSEL_CONTAINER_TYPE__ALGORITHM__MPIR_Scatter_allcomm_nb;
        else if (!strcmp(ckey, "algorithm=MPIR_Scatterv_allcomm_linear"))
            cnt->id = MPII_CSEL_CONTAINER_TYPE__ALGORITHM__MPIR_Scatterv_allcomm_linear;
        else if (!strcmp(ckey, "algorithm=MPIR_Scatterv_allcomm_nb"))
            cnt->id = MPII_CSEL_CONTAINER_TYPE__ALGORITHM__MPIR_Scatterv_allcomm_nb;
        else {
            fprintf(stderr, "unrecognized key %s\n", key);
            MPIR_Assert(0);
        }

        MPL_free(ckey);
    }

    return (void *) cnt;
}
