/*
 *  Copyright (c) 2021 The WebRTC project authors. All Rights Reserved.
 *
 *  Use of this source code is governed by a BSD-style license
 *  that can be found in the LICENSE file in the root of the source
 *  tree. An additional intellectual property rights grant can be found
 *  in the file PATENTS.  All contributing project authors may
 *  be found in the AUTHORS file in the root of the source tree.
 */
#include "net/dcsctp/packet/chunk/init_ack_chunk.h"

#include <stdint.h>

#include <utility>
#include <vector>

#include "api/array_view.h"
#include "net/dcsctp/packet/parameter/forward_tsn_supported_parameter.h"
#include "net/dcsctp/packet/parameter/parameter.h"
#include "net/dcsctp/packet/parameter/state_cookie_parameter.h"
#include "net/dcsctp/packet/parameter/supported_extensions_parameter.h"
#include "net/dcsctp/testing/testing_macros.h"
#include "rtc_base/gunit.h"
#include "test/gmock.h"

namespace dcsctp {
namespace {
using ::testing::ElementsAre;

TEST(InitAckChunkTest, FromCapture) {
  /*
  INIT_ACK chunk (Outbound streams: 1000, inbound streams: 2048)
      Chunk type: INIT_ACK (2)
      Chunk flags: 0x00
      Chunk length: 292
      Initiate tag: 0x579c2f98
      Advertised receiver window credit (a_rwnd): 131072
      Number of outbound streams: 1000
      Number of inbound streams: 2048
      Initial TSN: 1670811335
      Forward TSN supported parameter
          Parameter type: Forward TSN supported (0xc000)
          Parameter length: 4
      Supported Extensions parameter (Supported types: FORWARD_TSN, RE_CONFIG)
          Parameter type: Supported Extensions (0x8008)
          Parameter length: 6
          Supported chunk type: FORWARD_TSN (192)
          Supported chunk type: RE_CONFIG (130)
          Parameter padding: 0000
      State cookie parameter (Cookie length: 256 bytes)
          Parameter type: State cookie (0x0007)
          Parameter length: 260
          State cookie: 4b414d452d42534420312e310000000096b8386000000000…
  */

  uint8_t data[] = {
      0x02, 0x00, 0x01, 0x24, 0x57, 0x9c, 0x2f, 0x98, 0x00, 0x02, 0x00, 0x00,
      0x03, 0xe8, 0x08, 0x00, 0x63, 0x96, 0x8e, 0xc7, 0xc0, 0x00, 0x00, 0x04,
      0x80, 0x08, 0x00, 0x06, 0xc0, 0x82, 0x00, 0x00, 0x00, 0x07, 0x01, 0x04,
      0x4b, 0x41, 0x4d, 0x45, 0x2d, 0x42, 0x53, 0x44, 0x20, 0x31, 0x2e, 0x31,
      0x00, 0x00, 0x00, 0x00, 0x96, 0xb8, 0x38, 0x60, 0x00, 0x00, 0x00, 0x00,
      0x52, 0x5a, 0x0e, 0x00, 0x00, 0x00, 0x00, 0x00, 0x60, 0xea, 0x00, 0x00,
      0xb5, 0xaa, 0x19, 0xea, 0x31, 0xef, 0xa4, 0x2b, 0x90, 0x16, 0x7a, 0xde,
      0x57, 0x9c, 0x2f, 0x98, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
      0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00,
      0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
      0x00, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
      0x13, 0x88, 0x13, 0x88, 0x00, 0x00, 0x01, 0x00, 0x01, 0x01, 0x01, 0x00,
      0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x5a, 0xde, 0x7a, 0x16, 0x90,
      0x00, 0x02, 0x00, 0x00, 0x03, 0xe8, 0x03, 0xe8, 0x25, 0x0d, 0x37, 0xe8,
      0x80, 0x00, 0x00, 0x04, 0xc0, 0x00, 0x00, 0x04, 0x80, 0x08, 0x00, 0x09,
      0xc0, 0x0f, 0xc1, 0x80, 0x82, 0x00, 0x00, 0x00, 0x80, 0x02, 0x00, 0x24,
      0xab, 0x31, 0x44, 0x62, 0x12, 0x1a, 0x15, 0x13, 0xfd, 0x5a, 0x5f, 0x69,
      0xef, 0xaa, 0x06, 0xe9, 0xab, 0xd7, 0x48, 0xcc, 0x3b, 0xd1, 0x4b, 0x60,
      0xed, 0x7f, 0xa6, 0x44, 0xce, 0x4d, 0xd2, 0xad, 0x80, 0x04, 0x00, 0x06,
      0x00, 0x01, 0x00, 0x00, 0x80, 0x03, 0x00, 0x06, 0x80, 0xc1, 0x00, 0x00,
      0x02, 0x00, 0x01, 0x24, 0x57, 0x9c, 0x2f, 0x98, 0x00, 0x02, 0x00, 0x00,
      0x03, 0xe8, 0x08, 0x00, 0x63, 0x96, 0x8e, 0xc7, 0xc0, 0x00, 0x00, 0x04,
      0x80, 0x08, 0x00, 0x06, 0xc0, 0x82, 0x00, 0x00, 0x51, 0x95, 0x01, 0x88,
      0x0d, 0x80, 0x7b, 0x19, 0xe7, 0xf9, 0xc6, 0x18, 0x5c, 0x4a, 0xbf, 0x39,
      0x32, 0xe5, 0x63, 0x8e};

  ASSERT_HAS_VALUE_AND_ASSIGN(InitAckChunk chunk, InitAckChunk::Parse(data));

  EXPECT_EQ(chunk.initiate_tag(), VerificationTag(0x579c2f98u));
  EXPECT_EQ(chunk.a_rwnd(), 131072u);
  EXPECT_EQ(chunk.nbr_outbound_streams(), 1000u);
  EXPECT_EQ(chunk.nbr_inbound_streams(), 2048u);
  EXPECT_EQ(chunk.initial_tsn(), TSN(1670811335u));
  EXPECT_TRUE(
      chunk.parameters().get<ForwardTsnSupportedParameter>().has_value());
  EXPECT_TRUE(
      chunk.parameters().get<SupportedExtensionsParameter>().has_value());
  EXPECT_TRUE(chunk.parameters().get<StateCookieParameter>().has_value());
}

TEST(InitAckChunkTest, SerializeAndDeserialize) {
  uint8_t state_cookie[] = {1, 2, 3, 4, 5};
  Parameters parameters =
      Parameters::Builder().Add(StateCookieParameter(state_cookie)).Build();
  InitAckChunk chunk(VerificationTag(123), /*a_rwnd=*/456,
                     /*nbr_outbound_streams=*/65535,
                     /*nbr_inbound_streams=*/65534, /*initial_tsn=*/TSN(789),
                     /*parameters=*/std::move(parameters));

  std::vector<uint8_t> serialized;
  chunk.SerializeTo(serialized);

  ASSERT_HAS_VALUE_AND_ASSIGN(InitAckChunk deserialized,
                              InitAckChunk::Parse(serialized));

  EXPECT_EQ(chunk.initiate_tag(), VerificationTag(123u));
  EXPECT_EQ(chunk.a_rwnd(), 456u);
  EXPECT_EQ(chunk.nbr_outbound_streams(), 65535u);
  EXPECT_EQ(chunk.nbr_inbound_streams(), 65534u);
  EXPECT_EQ(chunk.initial_tsn(), TSN(789u));

  ASSERT_HAS_VALUE_AND_ASSIGN(
      StateCookieParameter cookie,
      deserialized.parameters().get<StateCookieParameter>());
  EXPECT_THAT(cookie.data(), ElementsAre(1, 2, 3, 4, 5));
  EXPECT_EQ(deserialized.ToString(),
            "INIT_ACK, initiate_tag=0x7b, initial_tsn=789");
}

}  // namespace
}  // namespace dcsctp
