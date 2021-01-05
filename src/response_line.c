#include "correctness.h"
#include <smolrtsp/response_line.h>

#include <string.h>

void SmolRTSP_ResponseLine_serialize(
    const SmolRTSP_ResponseLine *restrict self, SmolRTSP_UserWriter user_writer, void *user_cx) {
    precondition(self);
    precondition(user_writer);

    SmolRTSP_RTSPVersion_serialize(&self->version, user_writer, user_cx);
    SmolRTSP_StatusCode_serialize(&self->code, user_writer, user_cx);
    user_writer(self->reason.len, self->reason.ptr, user_cx);
    user_writer(strlen("\r\n"), "\r\n", user_cx);
}

bool SmolRTSP_ResponseLine_eq(
    const SmolRTSP_ResponseLine *restrict lhs, const SmolRTSP_ResponseLine *restrict rhs) {
    return SmolRTSP_RTSPVersion_eq(&lhs->version, &rhs->version) && lhs->code == rhs->code &&
           Slice99_primitive_eq(lhs->reason, rhs->reason);
}
