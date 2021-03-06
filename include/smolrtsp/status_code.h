/**
 * @file
 *  An RTSP status code.
 */

#ifndef SMOLRTSP_STATUS_CODE_H
#define SMOLRTSP_STATUS_CODE_H

#include <smolrtsp/common.h>
#include <smolrtsp/user_writer.h>

#include <stdint.h>

#include <slice99.h>

/**
 * An RTSP status code.
 */
typedef uint_least16_t SmolRTSP_StatusCode;

/**
 * `Continue`.
 */
#define SMOLRTSP_STATUS_CODE_CONTINUE 100

/**
 * `OK`.
 */
#define SMOLRTSP_STATUS_CODE_OK 200

/**
 * `Created`.
 */
#define SMOLRTSP_STATUS_CODE_CREATED 201

/**
 * `Low on Storage Space`.
 */
#define SMOLRTSP_STATUS_CODE_LOW_ON_STORAGE_SPACE 250

/**
 * `Multiple Choices`.
 */
#define SMOLRTSP_STATUS_CODE_MULTIPLE_CHOICES 300

/**
 * `Moved Permanently`.
 */
#define SMOLRTSP_STATUS_CODE_MOVED_PERMANENTLY 301

/**
 * `Moved Temporarily`.
 */
#define SMOLRTSP_STATUS_CODE_MOVED_TEMPORARILY 302

/**
 * `See Other`.
 */
#define SMOLRTSP_STATUS_CODE_SEE_OTHER 303

/**
 * `Not Modified`.
 */
#define SMOLRTSP_STATUS_CODE_NOT_MODIFIED 304

/**
 * `Use Proxy`.
 */
#define SMOLRTSP_STATUS_CODE_USE_PROXY 305

/**
 * `Use Proxy`.
 */
#define SMOLRTSP_STATUS_CODE_BAD_REQUEST 400

/**
 * `Unauthorized`.
 */
#define SMOLRTSP_STATUS_CODE_UNAUTHORIZED 401

/**
 * `Payment Required`.
 */
#define SMOLRTSP_STATUS_CODE_PAYMENT_REQUIRED 402

/**
 * `Forbidden`.
 */
#define SMOLRTSP_STATUS_CODE_FORBIDDEN 403

/**
 * `Not Found`.
 */
#define SMOLRTSP_STATUS_CODE_NOT_FOUND 404

/**
 * `Method Not Allowed`.
 */
#define SMOLRTSP_STATUS_CODE_METHOD_NOT_ALLOWED 405

/**
 * `Not Acceptable`.
 */
#define SMOLRTSP_STATUS_CODE_NOT_ACCEPTABLE 406

/**
 * `Proxy Authentication Required`.
 */
#define SMOLRTSP_STATUS_CODE_PROXY_AUTHENTICATION_REQUIRED 407

/**
 * `Request Time-out`.
 */
#define SMOLRTSP_STATUS_CODE_REQUEST_TIMEOUT 408

/**
 * `Gone`.
 */
#define SMOLRTSP_STATUS_CODE_GONE 410

/**
 * `Length Required`.
 */
#define SMOLRTSP_STATUS_CODE_PRECONDITION_FAILED 412

/**
 * `Precondition Failed`.
 */
#define SMOLRTSP_STATUS_CODE_PRECONDITION_FAILED 412

/**
 * `Request Entity Too Large`.
 */
#define SMOLRTSP_STATUS_CODE_REQUEST_ENTITY_TOO_LARGE 413

/**
 * `Request-URI Too Large`.
 */
#define SMOLRTSP_STATUS_CODE_REQUEST_URI_TOO_LARGE 414

/**
 * `Unsupported Media Type`.
 */
#define SMOLRTSP_STATUS_CODE_UNSUPPORTED_MEDIA_TYPE 415

/**
 * `Parameter Not Understood`.
 */
#define SMOLRTSP_STATUS_CODE_PARAMETER_NOT_UNDERSTOOD 451

/**
 * `Conference Not Found`.
 */
#define SMOLRTSP_STATUS_CODE_CONFERENCE_NOT_FOUND 452

/**
 * `Not Enough Bandwidth`.
 */
#define SMOLRTSP_STATUS_CODE_NOT_ENOUGH_BANDWIDTH 453

/**
 * `Session Not Found`.
 */
#define SMOLRTSP_STATUS_CODE_SESSION_NOT_FOUND 454

/**
 * `Method Not Valid in This State`.
 */
#define SMOLRTSP_STATUS_CODE_METHOD_NOT_VALID_IN_THIS_STATE 455

/**
 * `Header Field Not Valid for Resource`.
 */
#define SMOLRTSP_STATUS_CODE_HEADER_FIELD_NOT_VALID_FOR_RESOURCE 456

/**
 * `Invalid Range`.
 */
#define SMOLRTSP_STATUS_CODE_INVALID_RANGE 457

/**
 * `Parameter Is Read-Only`.
 */
#define SMOLRTSP_STATUS_CODE_PARAMETER_IS_READ_ONLY 458

/**
 * `Aggregate operation not allowed`.
 */
#define SMOLRTSP_STATUS_CODE_AGGREGATE_OPERATION_NOT_ALLOWED 459

/**
 * `Only aggregate operation allowed`.
 */
#define SMOLRTSP_STATUS_CODE_ONLY_AGGREGATE_OPERATION_ALLOWED 460

/**
 * `Unsupported transport`.
 */
#define SMOLRTSP_STATUS_CODE_UNSUPPORTED_TRANSPORT 461

/**
 * `Destination unreachable`.
 */
#define SMOLRTSP_STATUS_CODE_DESTINATION_UNREACHABLE 462

/**
 * `Internal Server Error`.
 */
#define SMOLRTSP_STATUS_CODE_INTERNAL_SERVER_ERROR 500

/**
 * `Not Implemented`.
 */
#define SMOLRTSP_STATUS_CODE_NOT_IMPLEMENTED 501

/**
 * `Bad Gateway`.
 */
#define SMOLRTSP_STATUS_CODE_BAD_GATEWAY 502

/**
 * `Service Unavailable`.
 */
#define SMOLRTSP_STATUS_CODE_SERVICE_UNAVAILABLE 503

/**
 * `Gateway Time-out`.
 */
#define SMOLRTSP_STATUS_CODE_GATEWAY_TIMEOUT 504

/**
 * `RTSP Version not supported`.
 */
#define SMOLRTSP_STATUS_CODE_RTSP_VERSION_NOT_SUPPORTED 505

/**
 * `Option not supported`.
 */
#define SMOLRTSP_STATUS_CODE_OPTION_NOT_SUPPORTED 551

/**
 * Serializes @p self to @p user_writer.
 *
 * @param[in] self The instance to be serialized.
 * @param[in] user_writer The function to be provided with serialized data (possibly in chunks).
 * @param[in] user_cx Some value provided to @p user_writer on each write.
 *
 * @pre `user_writer != NULL`
 */
void SmolRTSP_StatusCode_serialize(
    SmolRTSP_StatusCode self, SmolRTSP_UserWriter user_writer, void *user_cx);

/**
 * Deserializes @p data to @p self.
 *
 * @pre `self != NULL`
 * @pre `data != NULL`
 */
SmolRTSP_DeserializeResult
SmolRTSP_StatusCode_deserialize(SmolRTSP_StatusCode *restrict self, Slice99 *restrict data);

#endif // SMOLRTSP_STATUS_CODE_H
