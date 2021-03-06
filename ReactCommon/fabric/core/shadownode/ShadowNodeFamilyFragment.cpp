/*
 * Copyright (c) Facebook, Inc. and its affiliates.
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 */

#include "ShadowNodeFamilyFragment.h"

#include <react/core/ShadowNodeFamily.h>

namespace facebook {
namespace react {

ShadowNodeFamilyFragment ShadowNodeFamilyFragment::build(
    ShadowNodeFamily const &family) {
  return {
      family.tag_,
      family.surfaceId_,
      family.eventEmitter_,
  };
}

using Value = ShadowNodeFamilyFragment::Value;

Value::Value(ShadowNodeFamilyFragment const &fragment)
    : tag_(fragment.tag),
      surfaceId_(fragment.surfaceId),
      eventEmitter_(fragment.eventEmitter) {}

Value::operator ShadowNodeFamilyFragment() const {
  return ShadowNodeFamilyFragment{tag_, surfaceId_, eventEmitter_};
}

} // namespace react
} // namespace facebook
