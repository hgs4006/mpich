/*
 * Copyright (C) by Argonne National Laboratory
 *     See COPYRIGHT in top-level directory
 */

#include "mpiimpl.h"

/*
=== BEGIN_MPI_T_CVAR_INFO_BLOCK ===

cvars:
    - name        : MPIR_CVAR_NEIGHBOR_ALLTOALLV_INTRA_ALGORITHM
      category    : COLLECTIVE
      type        : enum
      default     : auto
      class       : none
      verbosity   : MPI_T_VERBOSITY_USER_BASIC
      scope       : MPI_T_SCOPE_ALL_EQ
      description : |-
        Variable to select neighbor_alltoallv algorithm
        auto - Internal algorithm selection (can be overridden with MPIR_CVAR_COLL_SELECTION_TUNING_JSON_FILE)
        nb   - Force nb algorithm

    - name        : MPIR_CVAR_NEIGHBOR_ALLTOALLV_INTER_ALGORITHM
      category    : COLLECTIVE
      type        : enum
      default     : auto
      class       : none
      verbosity   : MPI_T_VERBOSITY_USER_BASIC
      scope       : MPI_T_SCOPE_ALL_EQ
      description : |-
        Variable to select neighbor_alltoallv algorithm
        auto - Internal algorithm selection (can be overridden with MPIR_CVAR_COLL_SELECTION_TUNING_JSON_FILE)
        nb   - Force nb algorithm

    - name        : MPIR_CVAR_NEIGHBOR_ALLTOALLV_DEVICE_COLLECTIVE
      category    : COLLECTIVE
      type        : boolean
      default     : true
      class       : none
      verbosity   : MPI_T_VERBOSITY_USER_BASIC
      scope       : MPI_T_SCOPE_ALL_EQ
      description : >-
        This CVAR is only used when MPIR_CVAR_DEVICE_COLLECTIVES
        is set to "percoll".  If set to true, MPI_Neighbor_alltoallv will
        allow the device to override the MPIR-level collective
        algorithms.  The device might still call the MPIR-level
        algorithms manually.  If set to false, the device-override
        will be disabled.

=== END_MPI_T_CVAR_INFO_BLOCK ===
*/

/* -- Begin Profiling Symbol Block for routine MPI_Neighbor_alltoallv */
#if defined(HAVE_PRAGMA_WEAK)
#pragma weak MPI_Neighbor_alltoallv = PMPI_Neighbor_alltoallv
#elif defined(HAVE_PRAGMA_HP_SEC_DEF)
#pragma _HP_SECONDARY_DEF PMPI_Neighbor_alltoallv  MPI_Neighbor_alltoallv
#elif defined(HAVE_PRAGMA_CRI_DUP)
#pragma _CRI duplicate MPI_Neighbor_alltoallv as PMPI_Neighbor_alltoallv
#elif defined(HAVE_WEAK_ATTRIBUTE)
int MPI_Neighbor_alltoallv(const void *sendbuf, const int sendcounts[], const int sdispls[],
                           MPI_Datatype sendtype, void *recvbuf, const int recvcounts[],
                           const int rdispls[], MPI_Datatype recvtype, MPI_Comm comm)
    __attribute__ ((weak, alias("PMPI_Neighbor_alltoallv")));
#endif
/* -- End Profiling Symbol Block */

/* Define MPICH_MPI_FROM_PMPI if weak symbols are not supported to build
   the MPI routines */
#ifndef MPICH_MPI_FROM_PMPI
#undef MPI_Neighbor_alltoallv
#define MPI_Neighbor_alltoallv PMPI_Neighbor_alltoallv

/* any non-MPI functions go here, especially non-static ones */


int MPIR_Neighbor_alltoallv_allcomm_auto(const void *sendbuf, const int sendcounts[],
                                         const int sdispls[], MPI_Datatype sendtype, void *recvbuf,
                                         const int recvcounts[], const int rdispls[],
                                         MPI_Datatype recvtype, MPIR_Comm * comm_ptr)
{
    int mpi_errno = MPI_SUCCESS;

    MPIR_Csel_coll_sig_s coll_sig = {
        .coll_type = MPIR_CSEL_COLL_TYPE__NEIGHBOR_ALLTOALLV,
        .comm_ptr = comm_ptr,

        .u.neighbor_alltoallv.sendbuf = sendbuf,
        .u.neighbor_alltoallv.sendcounts = sendcounts,
        .u.neighbor_alltoallv.sdispls = sdispls,
        .u.neighbor_alltoallv.sendtype = sendtype,
        .u.neighbor_alltoallv.recvbuf = recvbuf,
        .u.neighbor_alltoallv.recvcounts = recvcounts,
        .u.neighbor_alltoallv.rdispls = rdispls,
        .u.neighbor_alltoallv.recvtype = recvtype,
    };

    MPII_Csel_container_s *cnt = MPIR_Csel_search(comm_ptr->csel_comm, coll_sig);
    MPIR_Assert(cnt);

    switch (cnt->id) {
        case MPII_CSEL_CONTAINER_TYPE__ALGORITHM__MPIR_Neighbor_alltoallv_allcomm_nb:
            mpi_errno =
                MPIR_Neighbor_alltoallv_allcomm_nb(sendbuf, sendcounts, sdispls, sendtype, recvbuf,
                                                   recvcounts, rdispls, recvtype, comm_ptr);
            break;

        default:
            MPIR_Assert(0);
    }

  fn_exit:
    return mpi_errno;

  fn_fail:
    goto fn_exit;
}

int MPIR_Neighbor_alltoallv_impl(const void *sendbuf, const int sendcounts[],
                                 const int sdispls[], MPI_Datatype sendtype,
                                 void *recvbuf, const int recvcounts[],
                                 const int rdispls[], MPI_Datatype recvtype, MPIR_Comm * comm_ptr)
{
    int mpi_errno = MPI_SUCCESS;

    if (comm_ptr->comm_kind == MPIR_COMM_KIND__INTRACOMM) {
        switch (MPIR_CVAR_NEIGHBOR_ALLTOALLV_INTRA_ALGORITHM) {
            case MPIR_CVAR_NEIGHBOR_ALLTOALLV_INTRA_ALGORITHM_nb:
                mpi_errno =
                    MPIR_Neighbor_alltoallv_allcomm_nb(sendbuf, sendcounts, sdispls, sendtype,
                                                       recvbuf, recvcounts, rdispls, recvtype,
                                                       comm_ptr);
                break;
            case MPIR_CVAR_NEIGHBOR_ALLTOALLV_INTRA_ALGORITHM_auto:
                mpi_errno =
                    MPIR_Neighbor_alltoallv_allcomm_auto(sendbuf, sendcounts, sdispls, sendtype,
                                                         recvbuf, recvcounts, rdispls, recvtype,
                                                         comm_ptr);
                break;
            default:
                MPIR_Assert(0);
        }
    } else {
        switch (MPIR_CVAR_NEIGHBOR_ALLTOALLV_INTER_ALGORITHM) {
            case MPIR_CVAR_NEIGHBOR_ALLTOALLV_INTER_ALGORITHM_nb:
                mpi_errno =
                    MPIR_Neighbor_alltoallv_allcomm_nb(sendbuf, sendcounts, sdispls, sendtype,
                                                       recvbuf, recvcounts, rdispls, recvtype,
                                                       comm_ptr);
                break;
            case MPIR_CVAR_NEIGHBOR_ALLTOALLV_INTER_ALGORITHM_auto:
                mpi_errno =
                    MPIR_Neighbor_alltoallv_allcomm_auto(sendbuf, sendcounts, sdispls, sendtype,
                                                         recvbuf, recvcounts, rdispls, recvtype,
                                                         comm_ptr);
                break;
            default:
                MPIR_Assert(0);
        }
    }
    MPIR_ERR_CHECK(mpi_errno);

  fn_exit:
    return mpi_errno;
  fn_fail:
    goto fn_exit;
}

int MPIR_Neighbor_alltoallv(const void *sendbuf, const int sendcounts[],
                            const int sdispls[], MPI_Datatype sendtype,
                            void *recvbuf, const int recvcounts[],
                            const int rdispls[], MPI_Datatype recvtype, MPIR_Comm * comm_ptr)
{
    int mpi_errno = MPI_SUCCESS;

    if ((MPIR_CVAR_DEVICE_COLLECTIVES == MPIR_CVAR_DEVICE_COLLECTIVES_all) ||
        ((MPIR_CVAR_DEVICE_COLLECTIVES == MPIR_CVAR_DEVICE_COLLECTIVES_percoll) &&
         MPIR_CVAR_BARRIER_DEVICE_COLLECTIVE)) {
        mpi_errno =
            MPID_Neighbor_alltoallv(sendbuf, sendcounts, sdispls, sendtype, recvbuf, recvcounts,
                                    rdispls, recvtype, comm_ptr);
    } else {
        mpi_errno = MPIR_Neighbor_alltoallv_impl(sendbuf, sendcounts, sdispls,
                                                 sendtype, recvbuf, recvcounts,
                                                 rdispls, recvtype, comm_ptr);
    }

    return mpi_errno;
}

#endif /* MPICH_MPI_FROM_PMPI */

/*@
MPI_Neighbor_alltoallv - The vector variant of MPI_Neighbor_alltoall allows
sending/receiving different numbers of elements to and from each neighbor.

Input Parameters:
+ sendbuf - starting address of the send buffer (choice)
. sendcounts - non-negative integer array (of length outdegree) specifying the number of elements to send to each neighbor
. sdispls - integer array (of length outdegree).  Entry j specifies the displacement (relative to sendbuf) from which to send the outgoing data to neighbor j
. sendtype - data type of send buffer elements (handle)
. recvcounts - non-negative integer array (of length indegree) specifying the number of elements that are received from each neighbor
. rdispls - integer array (of length indegree).  Entry i specifies the displacement (relative to recvbuf) at which to place the incoming data from neighbor i.
. recvtype - data type of receive buffer elements (handle)
- comm - communicator with topology structure (handle)

Output Parameters:
. recvbuf - starting address of the receive buffer (choice)

.N ThreadSafe

.N Fortran

.N Errors
@*/
int MPI_Neighbor_alltoallv(const void *sendbuf, const int sendcounts[], const int sdispls[],
                           MPI_Datatype sendtype, void *recvbuf, const int recvcounts[],
                           const int rdispls[], MPI_Datatype recvtype, MPI_Comm comm)
{
    int mpi_errno = MPI_SUCCESS;
    MPIR_Comm *comm_ptr = NULL;
    MPIR_FUNC_TERSE_STATE_DECL(MPID_STATE_MPI_NEIGHBOR_ALLTOALLV);

    MPID_THREAD_CS_ENTER(GLOBAL, MPIR_THREAD_GLOBAL_ALLFUNC_MUTEX);
    MPID_THREAD_CS_ENTER(VCI, MPIR_THREAD_VCI_GLOBAL_MUTEX);
    MPIR_FUNC_TERSE_ENTER(MPID_STATE_MPI_NEIGHBOR_ALLTOALLV);

    /* Validate parameters, especially handles needing to be converted */
#ifdef HAVE_ERROR_CHECKING
    {
        MPID_BEGIN_ERROR_CHECKS;
        {
            MPIR_ERRTEST_DATATYPE(sendtype, "sendtype", mpi_errno);
            MPIR_ERRTEST_DATATYPE(recvtype, "recvtype", mpi_errno);
            MPIR_ERRTEST_COMM(comm, mpi_errno);

            /* TODO more checks may be appropriate */
        }
        MPID_END_ERROR_CHECKS;
    }
#endif /* HAVE_ERROR_CHECKING */

    /* Convert MPI object handles to object pointers */
    MPIR_Comm_get_ptr(comm, comm_ptr);

    /* Validate parameters and objects (post conversion) */
#ifdef HAVE_ERROR_CHECKING
    {
        MPID_BEGIN_ERROR_CHECKS;
        {
            if (!HANDLE_IS_BUILTIN(sendtype)) {
                MPIR_Datatype *sendtype_ptr = NULL;
                MPIR_Datatype_get_ptr(sendtype, sendtype_ptr);
                MPIR_Datatype_valid_ptr(sendtype_ptr, mpi_errno);
                MPIR_Datatype_committed_ptr(sendtype_ptr, mpi_errno);
            }

            if (!HANDLE_IS_BUILTIN(recvtype)) {
                MPIR_Datatype *recvtype_ptr = NULL;
                MPIR_Datatype_get_ptr(recvtype, recvtype_ptr);
                MPIR_Datatype_valid_ptr(recvtype_ptr, mpi_errno);
                MPIR_Datatype_committed_ptr(recvtype_ptr, mpi_errno);
            }

            MPIR_Comm_valid_ptr(comm_ptr, mpi_errno, FALSE);
            /* TODO more checks may be appropriate (counts, in_place, buffer aliasing, etc) */
            if (mpi_errno != MPI_SUCCESS)
                goto fn_fail;
        }
        MPID_END_ERROR_CHECKS;
    }
#endif /* HAVE_ERROR_CHECKING */

    /* ... body of routine ...  */

    mpi_errno = MPIR_Neighbor_alltoallv(sendbuf, sendcounts, sdispls, sendtype,
                                        recvbuf, recvcounts, rdispls, recvtype, comm_ptr);
    MPIR_ERR_CHECK(mpi_errno);

    /* ... end of body of routine ... */

  fn_exit:
    MPIR_FUNC_TERSE_EXIT(MPID_STATE_MPI_NEIGHBOR_ALLTOALLV);
    MPID_THREAD_CS_EXIT(GLOBAL, MPIR_THREAD_GLOBAL_ALLFUNC_MUTEX);
    MPID_THREAD_CS_EXIT(VCI, MPIR_THREAD_VCI_GLOBAL_MUTEX);
    return mpi_errno;

  fn_fail:
    /* --BEGIN ERROR HANDLING-- */
#ifdef HAVE_ERROR_CHECKING
    {
        mpi_errno =
            MPIR_Err_create_code(mpi_errno, MPIR_ERR_RECOVERABLE, __func__, __LINE__, MPI_ERR_OTHER,
                                 "**mpi_neighbor_alltoallv",
                                 "**mpi_neighbor_alltoallv %p %p %p %D %p %p %p %D %C", sendbuf,
                                 sendcounts, sdispls, sendtype, recvbuf, recvcounts, rdispls,
                                 recvtype, comm);
    }
#endif
    mpi_errno = MPIR_Err_return_comm(NULL, __func__, mpi_errno);
    goto fn_exit;
    /* --END ERROR HANDLING-- */
}
