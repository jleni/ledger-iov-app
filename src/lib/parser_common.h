/*******************************************************************************
*  (c) 2019 ZondaX GmbH
*
*  Licensed under the Apache License, Version 2.0 (the "License");
*  you may not use this file except in compliance with the License.
*  You may obtain a copy of the License at
*
*      http://www.apache.org/licenses/LICENSE-2.0
*
*  Unless required by applicable law or agreed to in writing, software
*  distributed under the License is distributed on an "AS IS" BASIS,
*  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
*  See the License for the specific language governing permissions and
*  limitations under the License.
********************************************************************************/
#pragma once

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>
#include <stddef.h>

#define FAIL_ON_ERROR(CALL) { parser_error_t __local_err = CALL; if (__local_err!=parser_ok) return __local_err; }

typedef enum {
    // Generic errors
    parser_ok = 0,
    parser_no_data,
    parser_init_context_empty,
    parser_display_idx_out_of_range,
    parser_display_page_out_of_range,
    parser_unexepected_error,
    parser_unexpected_buffer_end,
    // Coin specific
    parser_unexpected_wire_type,
    parser_unexpected_version,
    parser_duplicated_field,
    parser_unexpected_chain,
    parser_unexpected_field_length,

    parser_unexpected_type,
    parser_unexpected_method,
    parser_unexpected_value,
    parser_unexpected_number_items,
    parser_unexpected_characters,
    parser_unexpected_field,
    parser_value_out_of_range,
    parser_invalid_address,
    // Context related errors
    parser_context_mismatch,
    parser_context_unexpected_size,
    parser_context_invalid_chars,
    parser_context_unknown_prefix,
    // Required fields
    parser_required_nonce,
    parser_required_method,
} parser_error_t;

typedef struct {
    const uint8_t *buffer;
    uint16_t bufferLen;
    uint16_t offset;
    uint16_t lastConsumed;
} parser_context_t;

#ifdef __cplusplus
}
#endif
