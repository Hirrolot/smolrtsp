/**
 * @file
 * An RTSP header map.
 */

#ifndef SMOLRTSP_HEADER_MAP_H
#define SMOLRTSP_HEADER_MAP_H

#include <smolrtsp/header.h>

#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>

/**
 * An RTSP header map.
 */
typedef struct {
    SmolRTSP_Header *headers;

    /**
     * The count of elements currently in \link #headers \endlink.
     */
    size_t len;

    /**
     * The count of elements \link #SmolRTSP_HeaderMap.headers \endlink is able to contain.
     */
    size_t size;
} SmolRTSP_HeaderMap;

/**
 * Returns a value associated with @p key within @p self.
 */
Slice99 SmolRTSP_HeaderMap_find(SmolRTSP_HeaderMap self, Slice99 key, bool *restrict is_found);

/**
 * Serializes @p self to @p user_writer.
 *
 * @param[in] user_cx Some value provided to @p user_writer on each write.
 *
 * @pre `self != NULL`
 * @pre `user_writer != NULL`
 */
void SmolRTSP_HeaderMap_serialize(
    const SmolRTSP_HeaderMap *restrict self, SmolRTSP_UserWriter user_writer, void *user_cx);

/**
 * Tests @p lhs and @p rhs for equality.
 *
 * @return `true` if @p lhs and @rhs are equal, `false` otherwise.
 *
 * @pre `lhs != NULL`
 * @pre `rhs != NULL`
 */
bool SmolRTSP_HeaderMap_eq(
    const SmolRTSP_HeaderMap *restrict lhs, const SmolRTSP_HeaderMap *restrict rhs);

/**
 * Decides whether @p self is full (no more space left for an additional header) or not.
 *
 * @return `true` if @p self is full, `false` otherwise
 */
bool SmolRTSP_HeaderMap_is_full(const SmolRTSP_HeaderMap self);

/**
 * Pretty-prints @p self to @p stream.
 *
 * @pre `self != NULL`
 * @pre `stream != NULL`
 */
void SmolRTSP_HeaderMap_dbg_to_file(const SmolRTSP_HeaderMap *self, FILE *stream);

/**
 * Pretty-prints @p self to `stdout`.
 *
 * @pre `self != NULL`
 */
void SmolRTSP_HeaderMap_dbg(const SmolRTSP_HeaderMap *self);

#endif // SMOLRTSP_HEADER_MAP_H
