/*-------------------------------------------------------------------------
 *
 * tuptoaster.h
 *	  POSTGRES definitions for external and compressed storage
 *	  of variable size attributes.
 *
 * Copyright (c) 2000, PostgreSQL Development Team
 *
 * $Id: tuptoaster.h,v 1.5 2000/07/04 06:11:50 tgl Exp $
 *
 *-------------------------------------------------------------------------
 */
#ifndef TUPTOASTER_H
#define TUPTOASTER_H

#ifdef TUPLE_TOASTER_ACTIVE

#include "access/heapam.h"
#include "access/htup.h"
#include "access/tupmacs.h"
#include "utils/rel.h"


#define	TOAST_MAX_CHUNK_SIZE	((MaxTupleSize -							\
				MAXALIGN(												\
					MAXALIGN(offsetof(HeapTupleHeaderData, t_bits)) +	\
					MAXALIGN(sizeof(Oid)) +								\
					MAXALIGN(sizeof(int32)) +							\
					MAXALIGN(VARHDRSZ))) / 4)


extern void heap_tuple_toast_attrs(Relation rel,
				HeapTuple newtup, HeapTuple oldtup);

extern varattrib *heap_tuple_untoast_attr(varattrib * attr);

#endif	 /* TUPLE_TOASTER_ACTIVE */


#endif	 /* TUPTOASTER_H */
