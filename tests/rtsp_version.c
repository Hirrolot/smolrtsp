#include <smolrtsp/rtsp_version.h>

#include "nala.h"

static void assert_pending(Slice99 input) {
    SmolRTSP_RTSPVersion result;
    SmolRTSP_DeserializeResult res = SmolRTSP_RTSPVersion_deserialize(&result, &input);
    ASSERT_EQ(res, SmolRTSP_DeserializeResultPending);
}

static void assert_ok(Slice99 input, SmolRTSP_RTSPVersion expected) {
    SmolRTSP_RTSPVersion result;
    SmolRTSP_DeserializeResult res = SmolRTSP_RTSPVersion_deserialize(&result, &input);
    ASSERT_EQ(res, SmolRTSP_DeserializeResultOk);
    ASSERT(SmolRTSP_RTSPVersion_eq(result, expected));
}

static void assert_err(Slice99 input) {
    SmolRTSP_RTSPVersion result;
    SmolRTSP_DeserializeResult res = SmolRTSP_RTSPVersion_deserialize(&result, &input);
    ASSERT_EQ(res, SmolRTSP_DeserializeResultErr);
}

TEST(deserialize_rtsp_version) {
    const Slice99 input = Slice99_from_str("RTSP/1.1 ");

    for (size_t i = 0; i < input.len - 1; i++) {
        assert_pending(Slice99_update_len(input, i));
    }

    assert_ok(input, (SmolRTSP_RTSPVersion){.major = 1, .minor = 1});

    assert_err(Slice99_from_str("192"));
    assert_err(Slice99_from_str(" ~ RTSP/"));
}